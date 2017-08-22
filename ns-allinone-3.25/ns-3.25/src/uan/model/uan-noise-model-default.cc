/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 University of Washington
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Leonard Tracy <lentracy@gmail.com>
 */

#include "uan-noise-model-default.h"
#include "ns3/double.h"
#include "ns3/core-module.h"
// #include "ns3/log.h"

#include <cmath>

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (UanNoiseModelDefault);
// NS_LOG_COMPONENT_DEFINE ("UanRandomNoise");

UanNoiseModelDefault::UanNoiseModelDefault ()
{
  m_Rand = CreateObject<UniformRandomVariable>();
  m_k = 0;
  m_b = 0;
}

UanNoiseModelDefault::UanNoiseModelDefault(double k, double b) {
  m_Rand = CreateObject<UniformRandomVariable>();
  //m_k = k;
  //m_b = b; 
  //m_wind = 0;
  //m_shipping = 0;
}

UanNoiseModelDefault::~UanNoiseModelDefault ()
{
}

TypeId
UanNoiseModelDefault::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::UanNoiseModelDefault")
    .SetParent<Object> ()
    .AddConstructor<UanNoiseModelDefault> ()
    .AddAttribute ("Wind", "Wind speed in m/s.",
                   DoubleValue (5), // 1
                   MakeDoubleAccessor (&UanNoiseModelDefault::m_wind),
                   MakeDoubleChecker<double> (0)) // 0
    .AddAttribute ("Shipping", "Shipping contribution to noise between 0 and 1.",
                   DoubleValue (0.5), // 0
                   MakeDoubleAccessor (&UanNoiseModelDefault::m_shipping),
                   MakeDoubleChecker<double> (0,1))
    .AddAttribute ("k", "Multiple of the Random Noise Variable.",
                   DoubleValue (1000), // 0
                   MakeDoubleAccessor (&UanNoiseModelDefault::m_k),
                   MakeDoubleChecker<double> (-2000))
    .AddAttribute ("b", "Offset the Random Noise Variable.",
                   DoubleValue (20), // 0
                   MakeDoubleAccessor (&UanNoiseModelDefault::m_b),
                   MakeDoubleChecker<double> (-2000))
  ;
  return tid;
}

// Common acoustic noise formulas.  These can be found
// in "Priniciples of Underwater Sound" by Robert J. Urick
double
UanNoiseModelDefault::GetNoiseDbHz (double fKhz) const
{
  double turb, wind, ship, thermal;
  double turbDb, windDb, shipDb, thermalDb, noiseDb;

  // random model
  double randomFactor = m_Rand->GetValue();
  randomFactor = m_Rand->GetValue();
  //double addError = 1000 * ( randomFactor - 0.8 );
  double addError = (m_k * randomFactor) + m_b;

  turbDb = 17.0 - 30.0 * std::log10 (fKhz);
  turb = std::pow (10.0, turbDb * 0.1);

  shipDb = 40.0 + 20.0 * (m_shipping - 0.5) + 26.0 * std::log10 (fKhz) - 60.0 * std::log10 (fKhz + 0.03);
  ship = std::pow (10.0, (shipDb * 0.1));

  windDb = 50.0 + 7.5 * std::pow (m_wind, 0.5) + 20.0 * std::log10 (fKhz) - 40.0 * std::log10 (fKhz + 0.4);
  wind = std::pow (10.0, windDb * 0.1);

  thermalDb = -15 + 20 * std::log10 (fKhz);
  thermal = std::pow (10, thermalDb * 0.1);

  noiseDb = 0;

  return noiseDb;
}

} // namespace ns3
