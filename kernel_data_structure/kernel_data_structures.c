#include<linux/list.h>
#include<linux/types.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<slab.h>

struct birthday{
	int day;
	int month;
	int year;
	struct list_head list;
};

static LIST_HEAD(birthday_list);

int birthday_list_init(void){
	printk(KERN_INFO "Loading Module.\n");

	struct birthday *person;
	int i;
	for(i = 0; i<5; i++){
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->day = 2;
		person->month = 8;
		person->year = 1995;
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &birthday_list);
	}

	printk(KERN_INFO "Created Birthday Link.\n");

	struct birthday *ptr;

	list_for_each_entry(ptr, &birthday_list, list){
		printk(KERN_INFO "D/M/Y : %d/%d/%d\n", person->day, person->month, person->year);
	}

	return 0;
}

void birthday_list_exit(void){
	struct birthday *ptr, *next;
	
	list_for_each_entry_safe(ptr, next, &birthday_list, list){
		printk(KERN_INFO "Freeing node.\n");

		list_del(&ptr->list);
		kfree(ptr);
	}

	printk(KERN_INFO "Removing Module.\n");
}

module_init(birthday_list_init);
module_exit(birthday_list_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Data Structure");
MODULE_AUTHOR("Jitlada Supreeyaporn");
