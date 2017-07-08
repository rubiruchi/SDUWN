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
    root_module = Module('ns.lte', cpp_namespace='::ns3')
    return root_module

def register_types(module):
    root_module = module.get_root()
    
    ## log.h (module 'core'): ns3::LogLevel [enumeration]
    module.add_enum('LogLevel', ['LOG_NONE', 'LOG_ERROR', 'LOG_LEVEL_ERROR', 'LOG_WARN', 'LOG_LEVEL_WARN', 'LOG_DEBUG', 'LOG_LEVEL_DEBUG', 'LOG_INFO', 'LOG_LEVEL_INFO', 'LOG_FUNCTION', 'LOG_LEVEL_FUNCTION', 'LOG_LOGIC', 'LOG_LEVEL_LOGIC', 'LOG_ALL', 'LOG_LEVEL_ALL', 'LOG_PREFIX_FUNC', 'LOG_PREFIX_TIME', 'LOG_PREFIX_NODE', 'LOG_PREFIX_LEVEL', 'LOG_PREFIX_ALL'], import_from_module='ns.core')
    ## ff-mac-common.h (module 'lte'): ns3::SetupRelease_e [enumeration]
    module.add_enum('SetupRelease_e', ['setup', 'release'])
    ## ff-mac-common.h (module 'lte'): ns3::Result_e [enumeration]
    module.add_enum('Result_e', ['SUCCESS', 'FAILURE'])
    ## ff-mac-common.h (module 'lte'): ns3::CeBitmap_e [enumeration]
    module.add_enum('CeBitmap_e', ['TA', 'DRX', 'CR'])
    ## ff-mac-common.h (module 'lte'): ns3::NormalExtended_e [enumeration]
    module.add_enum('NormalExtended_e', ['normal', 'extended'])
    ## address.h (module 'network'): ns3::Address [class]
    module.add_class('Address', import_from_module='ns.network')
    ## address.h (module 'network'): ns3::Address::MaxSize_e [enumeration]
    module.add_enum('MaxSize_e', ['MAX_SIZE'], outer_class=root_module['ns3::Address'], import_from_module='ns.network')
    ## eps-bearer.h (module 'lte'): ns3::AllocationRetentionPriority [struct]
    module.add_class('AllocationRetentionPriority')
    ## attribute-construction-list.h (module 'core'): ns3::AttributeConstructionList [class]
    module.add_class('AttributeConstructionList', import_from_module='ns.core')
    ## attribute-construction-list.h (module 'core'): ns3::AttributeConstructionList::Item [struct]
    module.add_class('Item', import_from_module='ns.core', outer_class=root_module['ns3::AttributeConstructionList'])
    ## spectrum-model.h (module 'spectrum'): ns3::BandInfo [struct]
    module.add_class('BandInfo', import_from_module='ns.spectrum')
    ## buffer.h (module 'network'): ns3::Buffer [class]
    module.add_class('Buffer', import_from_module='ns.network')
    ## buffer.h (module 'network'): ns3::Buffer::Iterator [class]
    module.add_class('Iterator', import_from_module='ns.network', outer_class=root_module['ns3::Buffer'])
    ## lte-common.h (module 'lte'): ns3::BufferSizeLevelBsr [class]
    module.add_class('BufferSizeLevelBsr')
    ## ff-mac-common.h (module 'lte'): ns3::BuildBroadcastListElement_s [struct]
    module.add_class('BuildBroadcastListElement_s')
    ## ff-mac-common.h (module 'lte'): ns3::BuildBroadcastListElement_s::Type_e [enumeration]
    module.add_enum('Type_e', ['BCCH', 'PCCH'], outer_class=root_module['ns3::BuildBroadcastListElement_s'])
    ## ff-mac-common.h (module 'lte'): ns3::BuildDataListElement_s [struct]
    module.add_class('BuildDataListElement_s')
    ## ff-mac-common.h (module 'lte'): ns3::BuildRarListElement_s [struct]
    module.add_class('BuildRarListElement_s')
    ## ff-mac-common.h (module 'lte'): ns3::BwPart_s [struct]
    module.add_class('BwPart_s')
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
