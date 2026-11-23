//file to write the save function

#include"student.h"

void save_records(stu *ptr){
	printf("\033[33m----------------------------------------\n");
	if(ptr==0){
		printf("No Records Found\n");
		printf("----------------------------------------\033[0m\n");
		return ;
	}
	FILE *fp=fopen("student.dat","w");
	
	while(ptr!=0){
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->percentage);
		ptr=ptr->next;
	}
	fclose(fp);
	printf("Saved...\n");
	printf("----------------------------------------\033[0m\n");
}
void free_all(stu *ptr){		//Using recursion to free the memory
	if(ptr){
		free_all((ptr)->next);
		free(ptr);
		
	}
}
void read_records(stu **ptr){
	FILE *fp=fopen("student.dat","r");
	if(fp==0){			//if the student.dat file doest exist
		return;			//proceed normally
	}
	//if student.dat file found copy them
	stu *new;
	while(1){
		new=malloc(sizeof(stu));
		if((fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->percentage))==EOF)break;
		new->next=0;
		if(*ptr==0 ){
			*ptr=new;
		}else{
			stu *last=*ptr;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
	
	printf("The records are copied\n");
}
