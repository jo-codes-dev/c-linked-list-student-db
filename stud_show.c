//file to handel display the list 

#include"student.h"
void show_list(stu *ptr){
	printf("\033[33m----------------------------------------\n");
	if(ptr==0){
		printf("No Records Found\n");
		printf("----------------------------------------\033[0m\n");
		return ;
	}
	printf("Roll no.\tName\tPercentage\n");
	printf("----------------------------------------\n");
	while(ptr!=0){
		printf("%d\t%s\t%f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
	printf("----------------------------------------\033[0m\n");
}
int count_node(stu *ptr){
	int c=0;
	while(ptr!=0){
		c++;
		ptr=ptr->next;
	}
	return c;
}

