#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
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
	{ 0x41086e, "module_layout" },
	{ 0xbef9fe65, "cdev_del" },
	{ 0xf28b622f, "cdev_init" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x8fde5204, "slab_buffer_size" },
	{ 0xc288f8ce, "malloc_sizes" },
	{ 0x9c22db12, "pci_disable_device" },
	{ 0x105e2727, "__tracepoint_kmalloc" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0x9629486a, "per_cpu__cpu_number" },
	{ 0xfc39e32f, "ioport_unmap" },
	{ 0xfc822e6e, "kmem_cache_alloc_notrace" },
	{ 0xb72397d5, "printk" },
	{ 0xacdeb154, "__tracepoint_module_get" },
	{ 0x2da418b5, "copy_to_user" },
	{ 0x40c497a1, "cdev_add" },
	{ 0x2036d7d2, "module_put" },
	{ 0x42c8de35, "ioremap_nocache" },
	{ 0x594bf15b, "ioport_map" },
	{ 0xec88c4a4, "pci_unregister_driver" },
	{ 0x280f9f14, "__per_cpu_offset" },
	{ 0x37a0cba, "kfree" },
	{ 0xedc03953, "iounmap" },
	{ 0x7997cb91, "__pci_register_driver" },
	{ 0x436c2179, "iowrite32" },
	{ 0xf3cc0b6c, "pci_enable_device" },
	{ 0xf2a644fb, "copy_from_user" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xe484e35f, "ioread32" },
	{ 0xf20dabd8, "free_irq" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v00006432d00005125sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "BCD541ABBE646DB74780756");
