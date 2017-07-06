/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2017 University of California Los Angeles
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
 */

#ifndef UAN_ADDRESS_TRANSLATOR_H
#define UAN_ADDRESS_TRANSLATOR_H

#include "ns3/address.h"
#include "uan-address.h"
#include "ns3/mac48-address.h"
#include <unordered_map>

namespace ns3 {
  class AddressTranslator{
    public:
      AddressTranslator();
      ~AddressTranslator();

      /**
       * Translates a Mac48Address to an UanAddress 
       * Input: a Mac48Address
       * Output: the corresponding UanAddress
       */
      UanAddress translate(const Mac48Address addr);

      /**
       * Translates an UanAddress to its corresponding Mac48Address
       * If no such address exists, return NULL
       * Input: an UanAddress
       * Output: the corresponding Mac48Address
       */
      Mac48Address getM48(const UanAddress addr);

      /**
       * Removes a Mac48Address from the map
       * If no such address exists, do nothing
       * Input: a Mac48Address 
       * Output: void
       */
      void remove(Mac48Address addr);


    private:
      static std::unordered_map<std::string,UanAddress> storeMap;
      static std::unordered_map<uint8_t,Mac48Address> getMap;
  }; //class AddressTranslator

} // namespace ns3

#endif /* UAN_ADDRESS_TRANSLATOR_H */

