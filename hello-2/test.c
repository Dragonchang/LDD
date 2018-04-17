#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
//#include <linux/list.h>
//#include <linux/mm.h>
//#include "hello.h"


MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Gatieme");
MODULE_DESCRIPTION("test hello");
extern void print_module(void);
int test_init(void)
{
    print_module( );

    printk(KERN_ALERT "run in cpu %d\n", get_cpu());

    printk(KERN_ALERT "PAGE_OFFSET : 0x%lx, TASK_SIZE : 0x%lx", PAGE_OFFSET, TASK_SIZE);


    return 0;
}



void test_exit(void)
{
    printk(KERN_ERR"exit");
}

module_init(test_init);
module_exit(test_exit);

