//file to write the delete function 

#include"student.h"
void delete_rollno(stu **);
void delete_name(stu **);
//delete options
void delete_record(stu **ptr){
	printf("\033[31m----------------------------------------\n");
	if(*ptr==0){
		printf("No Records Found\n");
		printf("----------------------------------------\033[0m\n");
		return;
	}
	char ch;
	while(1){
		printf("enter the choice to delete\n");
		printf("R/r.delete using rollno.\n");
		printf("N/n.delete using name\n");
		printf("B/b.go back\n");
		scanf(" %c",&ch);
		switch(ch){
			case'R':case'r':delete_rollno(ptr);break;
			case'N':case'n':delete_name(ptr);break;
			case'B':case'b':
			printf("----------------------------------------\033[0m\n");
			return;
			default:printf("\033[31mInvalid option\033[0m\n");
		}
	}
	printf("----------------------------------------\033[0m\n");
}	
//delete all
void delete_all(stu **ptr){
	printf("\033[31m----------------------------------------\n");
	if(*ptr==0){
		printf("No Records Found\n");
		printf("----------------------------------------\033[0m\n");
		return;
	}
	stu *pos=*ptr;
	while(pos){
		*ptr=pos->next;
		free(pos);
		pos=*ptr;
	}
	printf("All nodes are deleted\n");
	printf("----------------------------------------\033[0m\n");

}	
//delete using name
void delete_name(stu **ptr){
	char name[20];
	printf("enter the name to delete\n");
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
	if(c==1){
	pos=*ptr;
	stu *prev;
		while(pos){
			if(strcmp(pos->name,name)==0){
				if(*ptr==pos){
					*ptr=pos->next;
				}else{
					prev->next=pos->next;
				}
				free(pos);
				return;
			}	
			prev=pos;
			pos=pos->next;
		}
		printf("deleted the node\n");
	}else if(c>1){
		printf("there are multiple records which rollno to delete\n");
		delete_rollno(ptr);
		return;
	}
	printf("name not found\n");
}
//delete using rollno
void delete_rollno(stu **ptr){
	int rollno;
	printf("enter the rollno to delete\n");
	scanf("%d",&rollno);
	stu *pos=*ptr , *prev;
	while(pos){
		if(pos->rollno == rollno){
			if(pos==*ptr)
				*ptr=pos->next;
			else
				prev->next = pos->next;
			free(pos);
			return;
		}
		prev=pos;
		pos=pos->next;
	}
	printf("rollno not found\n");
}
