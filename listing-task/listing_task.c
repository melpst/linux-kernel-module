#include<linux/sched.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

int listing_task_init(void){
	struct task_struct *task;
	
	for_each_process(task){
		printk(KERN_INFO "id: %d | command: %s | state: %ld\n", task->pid, task->comm, task->state);
	}
	return 0;
}

void listing_task_exit(void){
	printk(KERN_INFO "Removing module.\n");
}

module_init(listing_task_init);
module_exit(listing_task_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jitlada Supreeyaporn");
MODULE_DESCRIPTION("Listing Task Command");
