//file that contain add and revers functions to the data
#include"student.h"


void add_record(stu **ptr){
	printf("\033[33m----------------------------------------\n");
	stu *new=malloc(sizeof(stu));
retake:	printf("Enter name and percentage\n");
	scanf("%s%f",new->name,&new->percentage);
	if(new->percentage<0 || new->percentage >100){
		printf("Enter the valid percentage\n");
		goto retake;
	}
	if(strlen(new->name)<=0){
		printf("Name cannot be empty.\n");
		goto retake;
	}
	if(*ptr==0 || (*ptr)->rollno != 1){
		new->rollno=1;
		new->next=*ptr;
		*ptr=new;
	}else{
		stu *last=(*ptr)->next;
		stu *prev=*ptr;
					
		while(last!=0 && last->rollno == ((prev->rollno)+1)){
			prev=last;
			last=last->next;
		}
		new->rollno = (prev->rollno+1);
		new->next = prev->next;
		prev->next=new;
	}
	printf("\033[33m----------------------------------------\n");
}
//revers links function
void reverse_links(stu **ptr){
	printf("\033[33m----------------------------------------\n");
	if(*ptr==0){
		printf("No Records Found\n");
		printf("\033[33m----------------------------------------\n");
		return;
	}
	int i,c=count_node(*ptr);
	stu **a=malloc(sizeof(stu*)*c);
	if(c>1){
	//store the addresses in array
	stu *t=*ptr;
	for(i=0; i<c ; i++){
		a[i]=t;
		t=t->next;
	}
	for( i=c-1;i>0;i--)
		a[i]->next=a[i-1];
	a[0]->next=0;
	*ptr=a[c-1];
	
	}
	printf("\033[33m----------------------------------------\n");
}

