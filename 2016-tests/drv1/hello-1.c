/*  
 *  hello-1.c - The simplest kernel module.
 */
 
#ifdef __cplusplus
extern "C" {
#endif

#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

extern char * f1(void);

int init_module(void)
{
//	printk(KERN_INFO "Hello 1.c\n" );
	printk(KERN_INFO "Hello: %s.\n", f1() );

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}


#ifdef __cplusplus
}
#endif
