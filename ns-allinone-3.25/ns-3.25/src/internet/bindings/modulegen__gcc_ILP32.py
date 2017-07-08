from pybindgen import Module, FileCodeSink, param, retval, cppclass, typehandlers


import pybindgen.settings
import warnings

class ErrorHandler(pybindgen.settings.ErrorHandler):
    def handle_error(self, wrapper, exception, traceback_):
        warnings.warn("exception %r in wrapper %s" % (exception, wrapper))
        return True
pybindgen.settings.error_handler = ErrorHandler()


import sys

def module_init():
    root_module = Module('ns.internet', cpp_namespace='::ns3')
    return root_module

def register_types(module):
    root_module = module.get_root()
    
    ## address.h (module 'network'): ns3::Address [class]
    module.add_class('Address', import_from_module='ns.network')
    ## address.h (module 'network'): ns3::Address::MaxSize_e [enumeration]
    module.add_enum('MaxSize_e', ['MAX_SIZE'], outer_class=root_module['ns3::Address'], import_from_module='ns.network')
    ## trace-helper.h (module 'network'): ns3::AsciiTraceHelper [class]
    module.add_class('AsciiTraceHelper', import_from_module='ns.network')
    ## trace-helper.h (module 'network'): ns3::AsciiTraceHelperForDevice [class]
    module.add_class('AsciiTraceHelperForDevice', allow_subclassing=True, import_from_module='ns.network')
    ## internet-trace-helper.h (module 'internet'): ns3::AsciiTraceHelperForIpv4 [class]
    module.add_class('AsciiTraceHelperForIpv4', allow_subclassing=True)
    ## internet-trace-helper.h (module 'internet'): ns3::AsciiTraceHelperForIpv6 [class]
    module.add_class('AsciiTraceHelperForIpv6', allow_subclassing=True)
    ## attribute-construction-list.h (module 'core'): ns3::AttributeConstructionList [class]
    module.add_class('AttributeConstructionList', import_from_module='ns.core')
    ## attribute-construction-list.h (module 'core'): ns3::AttributeConstructionList::Item [struct]
    module.add_class('Item', import_from_module='ns.core', outer_class=root_module['ns3::AttributeConstructionList'])
    ## buffer.h (module 'network'): ns3::Buffer [class]
    module.add_class('Buffer', import_from_module='ns.network')
    ## buffer.h (module 'network'): ns3::Buffer::Iterator [class]
    module.add_class('Iterator', import_from_module='ns.network', outer_class=root_module['ns3::Buffer'])
    ## packet.h (module 'network'): ns3::ByteTagIterator [class]
    module.add_class('ByteTagIterator', import_from_module='ns.network')
    ## packet.h (module 'network'): ns3::ByteTagIterator::Item [class]
    module.add_class('Item', import_from_module='ns.network', outer_class=root_module['ns3::ByteTagIterator'])
    ## byte-tag-list.h (module 'network'): ns3::ByteTagList [class]
    module.add_class('ByteTagList', import_from_module='ns.network')
    ## byte-tag-list.h (module 'network'): ns3::ByteTagList::Iterator [class]
    module.add_class('Iterator', import_from_module='ns.network', outer_class=root_module['ns3::ByteTagList'])
    ## byte-tag-list.h (module 'network'): ns3::ByteTagList::Iterator::Item [struct]
    module.add_class('Item', import_from_module='ns.network', outer_class=root_module['ns3::ByteTagList::Iterator'])
    ## callback.h (module 'core'): ns3::CallbackBase [class]
    module.add_class('CallbackBase', import_from_module='ns.core')
    ## candidate-queue.h (module 'internet'): ns3::CandidateQueue [class]
    module.add_class('CandidateQueue')
    ## event-id.h (module 'core'): ns3::EventId [class]
    module.add_class('EventId', import_from_module='ns.core')
    ## global-route-manager.h (module 'internet'): ns3::GlobalRouteManager [class]
    module.add_class('GlobalRouteManager')
    ## global-route-manager-impl.h (module 'internet'): ns3::GlobalRouteManagerImpl [class]
    module.add_class('GlobalRouteManagerImpl', allow_subclassing=True)
    ## global-route-manager-impl.h (module 'internet'): ns3::GlobalRouteManagerLSDB [class]
    module.add_class('GlobalRouteManagerLSDB')
    ## global-router-interface.h (module 'internet'): ns3::GlobalRoutingLSA [class]
    module.add_class('GlobalRoutingLSA')
    ## global-router-interface.h (module 'internet'): ns3::GlobalRoutingLSA::LSType [enumeration]
    module.add_enum('LSType', ['Unknown', 'RouterLSA', 'NetworkLSA', 'SummaryLSA', 'SummaryLSA_ASBR', 'ASExternalLSAs'], outer_class=root_module['ns3::GlobalRoutingLSA'])
    ## global-router-interface.h (module 'internet'): ns3::GlobalRoutingLSA::SPFStatus [enumeration]
    module.add_enum('SPFStatus', ['LSA_SPF_NOT_EXPLORED', 'LSA_SPF_CANDIDATE', 'LSA_SPF_IN_SPFTREE'], outer_class=root_module['ns3::GlobalRoutingLSA'])
    ## global-router-interface.h (module 'internet'): ns3::GlobalRoutingLinkRecord [class]
    module.add_class('GlobalRoutingLinkRecord')
    ## global-router-interface.h (module 'internet'): ns3::GlobalRoutingLinkRecord::LinkType [enumeration]
    module.add_enum('LinkType', ['Unknown', 'PointToPoint', 'TransitNetwork', 'StubNetwork', 'VirtualLink'], outer_class=root_module['ns3::GlobalRoutingLinkRecord'])
    ## hash.h (module 'core'): ns3::Hasher [class]
    module.add_class('Hasher', import_from_module='ns.core')
    ## inet6-socket-address.h (module 'network'): ns3::Inet6SocketAddress [class]
    module.add_class('Inet6SocketAddress', import_from_module='ns.network')
    ## inet6-socket-address.h (module 'network'): ns3::Inet6SocketAddress [class]
    root_module['ns3::Inet6SocketAddress'].implicitly_converts_to(root_module['ns3::Address'])
    ## inet-socket-address.h (module 'network'): ns3::InetSocketAddress [class]
    module.add_class('InetSocketAddress', import_from_module='ns.network')
    ## inet-socket-address.h (module 'network'): ns3::InetSocketAddress [class]
    root_module['ns3::InetSocketAddress'].implicitly_converts_to(root_module['ns3::Address'])
    ## int-to-type.h (module 'core'): ns3::IntToType<0> [struct]
    module.add_class('IntToType', import_from_module='ns.core', template_parameters=['0'])
    ## int-to-type.h (module 'core'): ns3::IntToType<0>::v_e [enumeration]
    module.add_enum('v_e', ['value'], outer_class=root_module['ns3::IntToType< 0 >'], import_from_module='ns.core')
    ## int-to-type.h (module 'core'): ns3::IntToType<1> [struct]
    module.add_class('IntToType', import_from_module='ns.core', template_parameters=['1'])
    ## int-to-type.h (module 'core'): ns3::IntToType<1>::v_e [enumeration]
    module.add_enum('v_e', ['value'], outer_class=root_module['ns3::IntToType< 1 >'], import_from_module='ns.core')
    ## int-to-type.h (module 'core'): ns3::IntToType<2> [struct]
    module.add_class('IntToType', import_from_module='ns.core', template_parameters=['2'])
    ## int-to-type.h (module 'core'): ns3::IntToType<2>::v_e [enumeration]
    module.add_enum('v_e', ['value'], outer_class=root_module['ns3::IntToType< 2 >'], import_from_module='ns.core')
    ## int-to-type.h (module 'core'): ns3::IntToType<3> [struct]
    module.add_class('IntToType', import_from_module='ns.core', template_parameters=['3'])
    ## int-to-type.h (module 'core'): ns3::IntToType<3>::v_e [enumeration]
    module.add_enum('v_e', ['value'], outer_class=root_module['ns3::IntToType< 3 >'], import_from_module='ns.core')
    ## int-to-type.h (module 'core'): ns3::IntToType<4> [struct]
    module.add_class('IntToType', import_from_module='ns.core', template_parameters=['4'])
    ## int-to-type.h (module 'core'): ns3::IntToType<4>::v_e [enumeration]
    module.add_enum('v_e', ['value'], outer_class=root_module['ns3::IntToType< 4 >'], import_from_module='ns.core')
    ## int-to-type.h (module 'core'): ns3::IntToType<5> [struct]
    module.add_class('IntToType', import_from_module='ns.core', template_parameters=['5'])
    ## int-to-type.h (module 'core'): ns3::IntToType<5>::v_e [enumeration]
    module.add_enum('v_e', ['value'], outer_class=root_module['ns3::IntToType< 5 >'], import_from_module='ns.core')
    ## int-to-type.h (module 'core'): ns3::IntToType<6> [struct]
    module.add_class('IntToType', import_from_module='ns.core', template_parameters=['6'])
    ## int-to-type.h (module 'core'): ns3::IntToType<6>::v_e [enumeration]
    module.add_enum('v_e', ['value'], outer_class=root_module['ns3::IntToType< 6 >'], import_from_module='ns.core')
    ## ipv4-address.h (module 'network'): ns3::Ipv4Address [class]
    module.add_class('Ipv4Address', import_from_module='ns.network')
    ## ipv4-address.h (module 'network'): ns3::Ipv4Address [class]
    root_module['ns3::Ipv4Address'].implicitly_converts_to(root_module['ns3::Address'])
    ## ipv4-address-generator.h (module 'internet'): ns3::Ipv4AddressGenerator [class]
    module.add_class('Ipv4AddressGenerator')
    ## ipv4-address-helper.h (module 'internet'): ns3::Ipv4AddressHelper [class]
    module.add_class('Ipv4AddressHelper')
    ## ipv4-interface-address.h (module 'internet'): ns3::Ipv4InterfaceAddress [class]
    module.add_class('Ipv4InterfaceAddress')
    ## ipv4-interface-address.h (module 'internet'): ns3::Ipv4InterfaceAddress::InterfaceAddressScope_e [enumeration]
    module.add_enum('InterfaceAddressScope_e', ['HOST', 'LINK', 'GLOBAL'], outer_class=root_module['ns3::Ipv4InterfaceAddress'])
    ## ipv4-interface-container.h (module 'internet'): ns3::Ipv4InterfaceContainer [class]
    module.add_class('Ipv4InterfaceContainer')
    ## ipv4-address.h (module 'network'): ns3::Ipv4Mask [class]
    module.add_class('Ipv4Mask', import_from_module='ns.network')
    ## ipv4-routing-table-entry.h (module 'internet'): ns3::Ipv4MulticastRoutingTableEntry [class]
    module.add_class('Ipv4MulticastRoutingTableEntry')
    ## ipv4-routing-helper.h (module 'internet'): ns3::Ipv4RoutingHelper [class]
    module.add_class('Ipv4RoutingHelper', allow_subclassing=True)
    ## ipv4-routing-table-entry.h (module 'internet'): ns3::Ipv4RoutingTableEntry [class]
    module.add_class('Ipv4RoutingTableEntry')
    ## ipv4-static-routing-helper.h (module 'internet'): ns3::Ipv4StaticRoutingHelper [class]
    module.add_class('Ipv4StaticRoutingHelper', parent=root_module['ns3::Ipv4RoutingHelper'])
    ## ipv6-address.h (module 'network'): ns3::Ipv6Address [class]
    module.add_class('Ipv6Address', import_from_module='ns.network')
    ## ipv6-address.h (module 'network'): ns3::Ipv6Address [class]
    root_module['ns3::Ipv6Address'].implicitly_converts_to(root_module['ns3::Address'])
    ## ipv6-address-generator.h (module 'internet'): ns3::Ipv6AddressGenerator [class]
    module.add_class('Ipv6AddressGenerator')
    ## ipv6-address-helper.h (module 'internet'): ns3::Ipv6AddressHelper [class]
    module.add_class('Ipv6AddressHelper')
    ## ipv6-interface-address.h (module 'internet'): ns3::Ipv6InterfaceAddress [class]
    module.add_class('Ipv6InterfaceAddress')
    ## ipv6-interface-address.h (module 'internet'): ns3::Ipv6InterfaceAddress::State_e [enumeration]
    module.add_enum('State_e', ['TENTATIVE', 'DEPRECATED', 'PREFERRED', 'PERMANENT', 'HOMEADDRESS', 'TENTATIVE_OPTIMISTIC', 'INVALID'], outer_class=root_module['ns3::Ipv6InterfaceAddress'])
    ## ipv6-interface-address.h (module 'internet'): ns3::Ipv6InterfaceAddress::Scope_e [enumeration]
    module.add_enum('Scope_e', ['HOST', 'LINKLOCAL', 'GLOBAL'], outer_class=root_module['ns3::Ipv6InterfaceAddress'])
    ## ipv6-interface-container.h (module 'internet'): ns3::Ipv6InterfaceContainer [class]
    module.add_class('Ipv6InterfaceContainer')
    ## ipv6-routing-table-entry.h (module 'internet'): ns3::Ipv6MulticastRoutingTableEntry [class]
    module.add_class('Ipv6MulticastRoutingTableEntry')
    ## ipv6-address.h (module 'network'): ns3::Ipv6Prefix [class]
    module.add_class('Ipv6Prefix', import_from_module='ns.network')
    ## ipv6-routing-helper.h (module 'internet'): ns3::Ipv6RoutingHelper [class]
    module.add_class('Ipv6RoutingHelper', allow_subclassing=True)
    ## ipv6-routing-table-entry.h (module 'internet'): ns3::Ipv6RoutingTableEntry [class]
    module.add_class('Ipv6RoutingTableEntry')
    ## ipv6-static-routing-helper.h (module 'internet'): ns3::Ipv6StaticRoutingHelper [class]
    module.add_class('Ipv6StaticRoutingHelper', parent=root_module['ns3::Ipv6RoutingHelper'])
    ## mac48-address.h (module 'network'): ns3::Mac48Address [class]
    module.add_class('Mac48Address', import_from_module='ns.network')
    ## mac48-address.h (module 'network'): ns3::Mac48Address [class]
    root_module['ns3::Mac48Address'].implicitly_converts_to(root_module['ns3::Address'])
    ## net-device-container.h (module 'network'): ns3::NetDeviceContainer [class]
    module.add_class('NetDeviceContainer', import_from_module='ns.network')
    ## node-container.h (module 'network'): ns3::NodeContainer [class]
    module.add_class('NodeContainer', import_from_module='ns.network')
    ## object-base.h (module 'core'): ns3::ObjectBase [class]
    module.add_class('ObjectBase', allow_subclassing=True, import_from_module='ns.core')
    ## object.h (module 'core'): ns3::ObjectDeleter [struct]
    module.add_class('ObjectDeleter', import_from_module='ns.core')
    ## object-factory.h (module 'core'): ns3::ObjectFactory [class]
    module.add_class('ObjectFactory', import_from_module='ns.core')
    ## ipv6-extension-header.h (module 'internet'): ns3::OptionField [class]
    module.add_class('OptionField')
    ## packet-metadata.h (module 'network'): ns3::PacketMetadata [class]
    module.add_class('PacketMetadata', import_from_module='ns.network')
    ## packet-metadata.h (module 'network'): ns3::PacketMetadata::Item [struct]
    module.add_class('Item', import_from_module='ns.network', outer_class=root_module['ns3::PacketMetadata'])
    ## packet-metadata.h (module 'network'): ns3::PacketMetadata::Item [enumeration]
    module.add_enum('', ['PAYLOAD', 'HEADER', 'TRAILER'], outer_class=root_module['ns3::PacketMetadata::Item'], import_from_module='ns.network')
    ## packet-metadata.h (module 'network'): ns3::PacketMetadata::ItemIterator [class]
    module.add_class('ItemIterator', import_from_module='ns.network', outer_class=root_module['ns3::PacketMetadata'])
    ## packet.h (module 'network'): ns3::PacketTagIterator [class]
    module.add_class('PacketTagIterator', import_from_module='ns.network')
    ## packet.h (module 'network'): ns3::PacketTagIterator::Item [class]
    module.add_class('Item', import_from_module='ns.network', outer_class=root_module['ns3::PacketTagIterator'])
    ## packet-tag-list.h (module 'network'): ns3::PacketTagList [class]
    module.add_class('PacketTagList', import_from_module='ns.network')
    ## packet-tag-list.h (module 'network'): ns3::PacketTagList::TagData [struct]
    module.add_class('TagData', import_from_module='ns.network', outer_class=root_module['ns3::PacketTagList'])
    ## packet-tag-list.h (module 'network'): ns3::PacketTagList::TagData::TagData_e [enumeration]
    module.add_enum('TagData_e', ['MAX_SIZE'], outer_class=root_module['ns3::PacketTagList::TagData'], import_from_module='ns.network')
    ## pcap-file.h (module 'network'): ns3::PcapFile [class]
    module.add_class('PcapFile', import_from_module='ns.network')
    ## trace-helper.h (module 'network'): ns3::PcapHelper [class]
    module.add_class('PcapHelper', import_from_module='ns.network')
    ## trace-helper.h (module 'network'): ns3::PcapHelper [enumeration]
    module.add_enum('', ['DLT_NULL', 'DLT_EN10MB', 'DLT_PPP', 'DLT_RAW', 'DLT_IEEE802_11', 'DLT_LINUX_SLL', 'DLT_PRISM_HEADER', 'DLT_IEEE802_11_RADIO', 'DLT_IEEE802_15_4', 'DLT_NETLINK'], outer_class=root_module['ns3::PcapHelper'], import_from_module='ns.network')
    ## trace-helper.h (module 'network'): ns3::PcapHelperForDevice [class]
    module.add_class('PcapHelperForDevice', allow_subclassing=True, import_from_module='ns.network')
    ## internet-trace-helper.h (module 'internet'): ns3::PcapHelperForIpv4 [class]
    module.add_class('PcapHelperForIpv4', allow_subclassing=True)
    ## internet-trace-helper.h (module 'internet'): ns3::PcapHelperForIpv6 [class]
    module.add_class('PcapHelperForIpv6', allow_subclassing=True)
    ## rip-helper.h (module 'internet'): ns3::RipHelper [class]
    module.add_class('RipHelper', parent=root_module['ns3::Ipv4RoutingHelper'])
    ## ripng-helper.h (module 'internet'): ns3::RipNgHelper [class]
    module.add_class('RipNgHelper', parent=root_module['ns3::Ipv6RoutingHelper'])
    ## ripng.h (module 'internet'): ns3::RipNgRoutingTableEntry [class]
    module.add_class('RipNgRoutingTableEntry', parent=root_module['ns3::Ipv6RoutingTableEntry'])
    ## ripng.h (module 'internet'): ns3::RipNgRoutingTableEntry::Status_e [enumeration]
    module.add_enum('Status_e', ['RIPNG_VALID', 'RIPNG_INVALID'], outer_class=root_module['ns3::RipNgRoutingTableEntry'])
    ## rip.h (module 'internet'): ns3::RipRoutingTableEntry [class]
    module.add_class('RipRoutingTableEntry', parent=root_module['ns3::Ipv4RoutingTableEntry'])
    ## rip.h (module 'internet'): ns3::RipRoutingTableEntry::Status_e [enumeration]
    module.add_enum('Status_e', ['RIP_VALID', 'RIP_INVALID'], outer_class=root_module['ns3::RipRoutingTableEntry'])
    ## tcp-socket-base.h (module 'internet'): ns3::RttHistory [class]
    module.add_class('RttHistory')
    ## global-route-manager-impl.h (module 'internet'): ns3::SPFVertex [class]
    module.add_class('SPFVertex')
    ## global-route-manager-impl.h (module 'internet'): ns3::SPFVertex::VertexType [enumeration]
    module.add_enum('VertexType', ['VertexUnknown', 'VertexRouter', 'VertexNetwork'], outer_class=root_module['ns3::SPFVertex'])
    ## sequence-number.h (module 'network'): ns3::SequenceNumber<unsigned int, int> [class]
    module.add_class('SequenceNumber32', import_from_module='ns.network')
