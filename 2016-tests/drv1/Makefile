#https://github.com/korisk/fpw/blob/master/Makefile

obj-m += hello.o

#module files get special treatment to extract properties and exports

#####################################################
# Makefile
#obj-m += mydrv.o
#mydrv-objs := interface.o cppmod.o kernel_api.o
#list-multi := mydrv.o
#all: cppmod.o module
#module:
#	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
#clean:
#	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
#cppmod.o : cppmod.cpp new.h kernel_api.h cppmod.h
#$(CC) -c -o $@ -mcmodel=kernel -fpermissive -fno-builtin -fno-exceptions -fno-rtti -nostdinc $<


hello-objs := hello-1.o hello_f1.o  main.o

#build_dir = /lib/modules/$(shell uname -r)/build

build_dir = /usr/src/linux-headers-4.4.0-57-generic
#include and arch/x68/include mapped to my_env


#main.o : main.cpp
#	gcc 

all: module_files

module_files:
	make -C $(build_dir) M=$(PWD) modules
#	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C $(build_dir) M=$(PWD) clean

#main.o: main.cpp prepare scripts FORCE
#	$(Q)$(MAKE) $(build)=$(build-dir) $(target-dir)$(notdir $@)

hello_f1.o: hello_f1.c
	@echo About to compile hello_f1.o
	g++ -fpermissive \
	-Wp,-MD,/home/baruch/w/drv1/.hello_f1.o.d  -nostdinc \
	-isystem /usr/lib/gcc/x86_64-linux-gnu/5/include  \
	-I$(build_dir)/arch/x86/include -I$(build_dir)/arch/x86/include/generated/uapi \
	-I$(build_dir)/arch/x86/include/generated  -I$(build_dir)/include -I$(build_dir)/arch/x86/include/uapi \
	-I$(build_dir)/arch/x86/include/generated/uapi -I$(build_dir)/include/uapi -I$(build_dir)/include/generated/uapi \
	-include $(build_dir)/include/linux/kconfig.h -I$(build_dir)/ubuntu/include  \
	-D__KERNEL__ -fno-pie -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common \
	-Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-pie -no-pie -mno-sse \
	-mno-mmx -mno-sse2 -mno-3dnow -mno-avx -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 \
	-mpreferred-stack-boundary=3 -mskip-rax-setup -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time \
	-maccumulate-outgoing-args -DCONFIG_X86_X32_ABI -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 \
	-DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_SSSE3=1 -DCONFIG_AS_CRC32=1 -DCONFIG_AS_AVX=1 \
	-DCONFIG_AS_AVX2=1 -DCONFIG_AS_SHA1_NI=1 -DCONFIG_AS_SHA256_NI=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables \
	-fno-delete-null-pointer-checks -Wno-maybe-uninitialized -O2 --param=allow-store-data-races=0 -Wframe-larger-than=1024 \
	-fstack-protector-strong -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls \
	-fno-var-tracking-assignments -pg -mfentry -DCC_USING_FENTRY -Wdeclaration-after-statement -Wno-pointer-sign \
	-fno-strict-overflow \
	-fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -DCC_HAVE_ASM_GOTO  \
	-DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(hello_f1)"  -D"KBUILD_MODNAME=KBUILD_STR(hello)" \
	-c -o /home/baruch/w/drv1/hello_f1.o \
	/home/baruch/w/drv1/hello_f1.c

