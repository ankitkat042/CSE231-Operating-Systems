#include<linux/kernel.h>
#include<linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include<linux/stat.h>
#include<linux/moduleparam.h>
#include <asm/uaccess.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/pid.h>
#include<linux/sched.h>
#include <linux/cred.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ankit Kumar 2021015");
// reference https://stackoverflow.com/questions/8547332/efficient-way-to-find-task-struct-by-pid
static int procID = 0;
module_param(procID, int, 0);
struct task_struct *mytask;
struct pid *pid_struct;

static int __init get_info_taskStruct(void)
{
    pid_struct = find_get_pid(procID);
    if (pid_struct == NULL){ 
        printk(KERN_ERR "PID not valid: dmesg: enter correct pid\n");
        return -EINVAL;
    }

    
    mytask = get_pid_task(pid_struct, PIDTYPE_PID);;
    if (mytask == NULL) {
        printk(KERN_ERR "Failed to get task_struct from pid value\n");
        return -EINVAL;
    }
    
    

    printk(KERN_INFO "PID: %d\n", mytask->pid);
    printk(KERN_INFO "UID: %d\n", mytask->cred->uid);
    printk(KERN_INFO "PGID: %d\n", mytask->group_leader->pid);
    printk(KERN_INFO "process location: %s\n", mytask->comm);

    return 0;
}

static void __exit unload_taskStruct(void)
{
    printk(KERN_INFO "module unloaded\n");
}

module_init(get_info_taskStruct);
module_exit(unload_taskStruct);


