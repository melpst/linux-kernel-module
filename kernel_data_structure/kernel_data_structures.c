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

	return 0;
}

void birthday_list_exit(void){
	printk(KERN_INFO "Removing Module.\n");
}


