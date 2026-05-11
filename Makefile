INSTALL_DIR=modules

ifneq (${KERNELRELEASE},)
	obj-m := CDD_Dir.o
CDD_Dir-objs := init.o cleanup.o openDevice.o releaseDevice.o trimDevice.o writeDevice.o readDevice.o createScull.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C  $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
	rm -rf modules.order
	rm -rf Module.symvers
	rm -rf CDD_Dir.mod 
endif
