//file to write the save function exit_all function

#include"student.h"

void save_records(stu *ptr){
	printf("\033[33m----------------------------------------\n");
	FILE *fp=fopen("student.dat","w");
	if(fp==0){
		printf("Error in opening file\n");
		return;
	
	}	
	if(ptr==0){
		printf("No Records Found\n");
		fclose(fp);
		printf("----------------------------------------\033[0m\n");
		return ;
	}

	
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
//exit all function
void exit_all(stu *ptr){
	char op;
	printf("s/S: Save and exit\n");
	printf("e/E: exit without saving\n");
	scanf(" %c",&op);
	switch(op){
		case 's': case 'S':save_records(ptr);
				free_all(ptr);
				printf("\033[33m**********     end     **********\n\033[0m");
				exit(0);
		case 'e':case 'E':free_all(ptr);
					printf("\033[33m**********     end     **********\n\033[0m");
				exit(0);
		default:printf("\033[31minvalid option to save or not\033[0m\n");
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
		if((fscanf(fp,"%d%s%f",&new->rollno,new->name,&new->percentage))==EOF){
			free(new);
			break;
		}
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
	fclose(fp);
	sort_rollno(*ptr);
	
	printf("The records are copied\n");
}
