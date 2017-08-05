#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xd2901226, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xe826dde, __VMLINUX_SYMBOL_STR(ovs_stt_fill_metadata_dst) },
	{ 0xe70abe76, __VMLINUX_SYMBOL_STR(ovs_stt_xmit) },
	{ 0x1b2cccd, __VMLINUX_SYMBOL_STR(ovs_netdev_tunnel_destroy) },
	{ 0xf0b3fd47, __VMLINUX_SYMBOL_STR(ovs_vport_ops_unregister) },
	{ 0x65a2df78, __VMLINUX_SYMBOL_STR(__ovs_vport_ops_register) },
	{ 0xaaaae74a, __VMLINUX_SYMBOL_STR(ovs_vport_free) },
	{ 0x5c4d44ed, __VMLINUX_SYMBOL_STR(rpl_rtnl_delete_link) },
	{ 0x2a7ee5d, __VMLINUX_SYMBOL_STR(ovs_netdev_link) },
	{ 0x6e720ff2, __VMLINUX_SYMBOL_STR(rtnl_unlock) },
	{ 0x4e54947f, __VMLINUX_SYMBOL_STR(dev_change_flags) },
	{ 0x4e5e58b, __VMLINUX_SYMBOL_STR(ovs_stt_dev_create_fb) },
	{ 0xc7a4fbed, __VMLINUX_SYMBOL_STR(rtnl_lock) },
	{ 0xb59116c5, __VMLINUX_SYMBOL_STR(ovs_vport_alloc) },
	{ 0xcd279169, __VMLINUX_SYMBOL_STR(nla_find) },
	{ 0x8afaebe7, __VMLINUX_SYMBOL_STR(nla_put) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=openvswitch";


MODULE_INFO(srcversion, "7A8EE429FDA4C472FA87D48");
