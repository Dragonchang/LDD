#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
//#include <linux/list.h>
//#include <linux/mm.h>
//#include "hello.h"


MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Gatieme");
MODULE_DESCRIPTION("hello world");

/*
 * print the module information
 */
void print_module(void)
{
    struct module *mod;

    printk(KERN_ALERT "this module: %p==%p\n", &__this_module, THIS_MODULE);
    printk(KERN_ALERT "module state: %d\n", THIS_MODULE->state);
    printk(KERN_ALERT "module name: %s\n", THIS_MODULE->name);

    list_for_each_entry(mod, *(&THIS_MODULE->list.prev), list);
    printk(KERN_ALERT "module name: %s\n", mod->name);
    printk(KERN_ALERT "module state: %d\n", THIS_MODULE->state);
    printk(KERN_EMERG "***********zfl-print_module --begin pid: %d, comm: %.20s\n",current->pid, current->comm);
}
EXPORT_SYMBOL(print_module);

int hello_init(void)
{
    print_module( );

    printk(KERN_ALERT "run in cpu %d\n", get_cpu());

    printk(KERN_ALERT "PAGE_OFFSET : 0x%lx, TASK_SIZE : 0x%lx", PAGE_OFFSET, TASK_SIZE);


    return 0;
}



void hello_exit(void)
{
    printk(KERN_ERR"exit");
}


module_init(hello_init);
module_exit(hello_exit);


