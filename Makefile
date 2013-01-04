obj-m += snd-usb-usbpal.o
snd-usb-usbpal-objs += chip.o 6fire.o comm.o midi.o firmware.o pcm.o

FW_PATH=/lib/firmware
FW_MYTEK_PATH=$(FW_PATH)/mytek

VERSION=$(shell uname -r|cut -d. -f1)
PATCHLEVEL=$(shell uname -r|cut -d. -f2)

KERNEL_VERSION=$(shell echo $(VERSION)*65536+$(PATCHLEVEL)*256|bc)

all:
	@echo "#define LINUX_VERSION_CODE $(KERNEL_VERSION)" > version.h
	make CONFIG_DEBUG_SECTION_MISMATCH=y -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	rm -f /lib/modules/$(shell uname -r)/extras/snd-usb-snd-usbpal.ko
	rm -f /lib/modules/$(shell uname -r)/extra/snd-usb-usbpal.ko
	mkdir -p /lib/modules/$(shell uname -r)/extra
	cp snd-usb-usbpal.ko /lib/modules/$(shell uname -r)/extra
	depmod -a

uninstall:
	rm -f /lib/modules/$(shell uname -r)/extra/snd-usb-usbpal.ko

kremove:
	for x in $(shell find /lib/modules/$(shell uname -r) -iname snd-usb-usbpal\*); do \
	rm -f $$x; \
	done

