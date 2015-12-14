#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched.h>

void dfs(struct task_struct *task){
	struct task_struct *next_task;
	struct list_head *list;

	list_for_each(list, &task->children){
		next_task = list_entry(list, struct task_struct, sibling);
		printk(KERN_INFO "id: %d | task: %s | state: %ld\n", next_task->pid, next_task->comm, next_task->state);
	}
}

int dfs_tree_init(void){
	printk(KERN_INFO "Loading module.\n");
	dfs(&init_task);
	return 0;
}

void dfs_tree_exit(void){
	printk(KERN_INFO "Removing module.\n");
}

module_init(dfs_tree_init);
module_exit(dfs_tree_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jitlada Supreeyaporn");
MODULE_DESCRIPTION("DFS tree task");
