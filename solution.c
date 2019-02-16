#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_LICENSE( "GPL" );
MODULE_AUTHOR( "Toshchev Konstantin <konst.toshchev@gmail.com>" );

inline int proc ( void ) {
    int    count = 0;
    struct task_struct *task;

    for_each_process(task) {
        count++;
    }
    return count;
}

int init_module ( void ) {
    printk( KERN_INFO "Module Solution start!\n" );
    printk( KERN_INFO "Process count: %d \n", proc() );
    return 0;
}

void cleanup_module ( void ) {
    printk( KERN_INFO "Module Solution stop!\n" );
    return;
}

