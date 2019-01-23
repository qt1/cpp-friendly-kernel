/*
 *  hello-1.c - The simplest kernel module.
 */
 #define CPP_ASMLINKAGE extern "C
 

extern "C" {

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-fpermissive"

#define new n_e_w
#define private private_member
#define PATCH_THIS_LATER 1
 

#include <linux/module.h> /* Needed by all modules */
#include <linux/kernel.h> /* Needed for KERN_INFO */

#pragma GCC diagnostic pop
#undef new 
#undef private 

#pragma GCC diagnostic error "-pedantic"
#pragma GCC diagnostic error "-fpermissive"


int init_module(void)
{
    printk(KERN_INFO "Hello world 1.\n");

    /*
     * A non 0 return means init_module failed; module can't be loaded.
     */
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Goodbye world 1.\n");
}
}
