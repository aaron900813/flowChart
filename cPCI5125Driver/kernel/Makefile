################################################################################
#   Makefile for the HRcPCI5125 device driver (Linux)
################################################################################

PROJNAME:=cPCI5125
DEVFILE:=/dev/cPCI5125

ifneq ($(KERNELRELEASE),)

obj-m	   += cPCI5125.o
cPCI5125-objs := cpci5125driverlnx.o
EXTRA_CFLAGS += $(FIXUPFLAGS)

else

PATCHLEVEL:=$(shell uname -r | cut -d. -f2)
FIXUPFLAGS:=$(shell $(shell pwd)/fixupflags.sh)
cPCI5125_BOOT:=/etc/rc.d/init.d
cPCI5125_BOOT3:=/etc/rc.d/rc3.d/S50cPCI5125
cPCI5125_BOOT5:=/etc/rc.d/rc5.d/S50cPCI5125

EXTRA_CFLAGS += $(FIXUPFLAGS)
KDIR	:= /lib/modules/$(shell uname -r)/build
PWD	:= $(shell pwd)

ifeq ($(PATCHLEVEL), 4)
INSTRULES:=
UNINSTRULES:=
else
INSTRULES:=all
UNINSTRULES:=clean
endif

export FIXUPFLAGS

# Install paths
moduledir:= /lib/modules/$(shell uname -r)/

all:
        ifeq ($(PATCHLEVEL), 4)
		$(MAKE) -f Makefile2.4 $@
        else
		$(MAKE) -C $(KDIR) M=$(PWD) modules
        endif

clean:
        ifeq ($(PATCHLEVEL), 4)
		$(MAKE) -f Makefile2.4 $@
        else
		$(MAKE) -C $(KDIR) M=$(PWD) $@
        endif

install: $(INSTRULES)
        ifeq ($(PATCHLEVEL), 4)
		$(MAKE) -f Makefile2.4 $@
        else
#		al
		#1.将生成的ko文件安装到默认文件夹 ／lib／modules／`uname -r`／extral
		$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules_install
		#2.拷贝init load unload脚本到init.d文件夹下
		install -m0755 -p cpci5125_init ${cPCI5125_BOOT}/cpci5125_init
		install -m0755 -p cpci5125_load ${cPCI5125_BOOT}/cpci5125_load
		install -m0755 -p cpci5125_unload ${cPCI5125_BOOT}/cpci5125_unload
		#3.在rcN.d中建立与init.d文件夹中的初始化的软连接
		ln -f -s ../init.d/cpci5125_init ${cPCI5125_BOOT3}
		ln -f -s ../init.d/cpci5125_init ${cPCI5125_BOOT5}
		#4.手动执行一次驱动加载
		sh ./cpci5125_load

		#总结：生成驱动到系统默认外部内核文件夹中，在rcN.d中创建链接 init.d中有脚本 开机自动执行cpci5125_init脚本
        endif

uninstall: $(UNINSTRULES)
        ifeq ($(PATCHLEVEL), 4)
		$(MAKE) -f Makefile2.4 $@
        else
#		clean
		sh cpci5125_unload
		rm -f $(moduledir)/extra/$(PROJNAME).*
		rm -f ${cPCI5125_BOOT}/cpci5125_init
		rm -f ${cPCI5125_BOOT}/cpci5125_load
		rm -f ${cPCI5125_BOOT}/cpci5125_unload
		rm -f ${cPCI5125_BOOT3}
		rm -f ${cPCI5125_BOOT5}
        endif
		
default:
        ifeq ($(PATCHLEVEL), 4)
		$(MAKE) -f Makefile2.4 $@
        else
		$(MAKE) -C $(KDIR) M=$(PWD) modules
        endif
	

endif
