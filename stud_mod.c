//File to write the modifying functions

#include"student.h"

void modify_data(stu **ptr){
	printf("\033[33m----------------------------------------\n");
	char ch;
	if(*ptr==0){
		printf("No Records Found\n");
		printf("----------------------------------------\033[0m\n");
		return ;
	}
	printf("Enter which record to search for modification\n");
	printf("R/r:Search by roll number\n");
	printf("N/n:Search by name\n");
	printf("P/p:Search by percentage\n");
	scanf(" %c",&ch);
	switch(ch){
		case 'R':case 'r':modify_rollno(ptr);break;
		case 'N':case 'n':modify_name(ptr);break;
		case 'P':case 'p':modify_percentage(ptr);break;
		default:printf("\033[31mInvalid option\033[0m\n");
		return;
	}

	printf("----------------------------------------\033[0m\n");
}
void modify_rollno(stu **ptr){
	int rollno;
	printf("enter the roll number to search\n");
	scanf("%d",&rollno);
	stu *pos=*ptr;
	while(pos){
		if(pos->rollno==rollno){
			printf("%d %s %f\n",pos->rollno,pos->name,pos->percentage);
			printf("Enter name and percentage to modify\n");
			scanf("%s%f",pos->name,&pos->percentage);
			return;
		}
		pos=pos->next;
	}
	printf("Roll number not found\n");
	
}
void modify_name(stu **ptr){
	char name[20];
	printf("enter the name to modify\n");
	scanf("%s",name);
	stu *pos=*ptr;
	int c=0;
	while(pos){
		if(strcmp(pos->name,name)==0){
			printf("%d %s\n",pos->rollno,pos->name);
			c++;
		}
		pos=pos->next;
	}
	pos=*ptr;
	if(c==1){
		while(pos){
			if(strcmp(pos->name,name)==0){
				printf("%d %s %f\n",pos->rollno,pos->name,pos->percentage);
				printf("Enter name and percentage to modify\n");
				scanf("%s%f",pos->name,&pos->percentage);
			}
			pos=pos->next;
		}
		return;
	}else if(c>1){
		printf("there are multiple records which rollno to delete\n");
		modify_rollno(ptr);
		return;
	}
	printf("Name not found\n");
}
void modify_percentage(stu **ptr){
	float percentage;
	printf("enter the percentage to modify to delete\n");
	scanf("%f",&percentage);
	stu *pos=*ptr;
	int c=0;
	while(pos){
		if(percentage==pos->percentage){
			printf("%d %s %f\n",pos->rollno,pos->name,pos->percentage);
			c++;
		}
		pos=pos->next;
	}
	pos=*ptr;
	if(c==1){
		while(pos){
			if(percentage==pos->percentage){
				printf("%d %s %f\n",pos->rollno,pos->name,pos->percentage);
				printf("Enter name and percentage to modify\n");
				scanf("%s%f",pos->name,&pos->percentage);
			}
			pos=pos->next;
		}
		return;
	}else if(c>1){
		printf("there are multiple records which rollno to delete\n");
		modify_rollno(ptr);
		return;
	}
	printf("Name not found\n");

}
