//file for the sort function 
#include"student.h"

void sort_records(stu *ptr){
	printf("\033[33m----------------------------------------\n");
	if(ptr==0){
		printf("No records found\n");
		return;
	}
	char ch,c=0;
	while(1){
	printf("choose how to sort\n");
	printf("N/n:Sort with Names\n");
	printf("P/p:Sort with percentage\n");
	printf("T/T:To display\n");
	scanf(" %c",&ch);
	switch(ch){
		case 'N':case 'n':sort_name(ptr);c++;break;
		case 'P':case 'p':sort_percentage(ptr);c++;break;
		case 'T':case 't':show_list(ptr);break;	
		default:printf("Invalid sorting option\n");
	}
	if(c==1)break;
	}
	printf("----------------------------------------\033[0m\n");
}

void sort_name(stu *ptr){
	int i,j,c=count_node(ptr);
	stu *p1=ptr,*p2,t;
	for(i=0 ; i<c-1; i++){
		p2=p1->next;
		for(j=0; j<c-1-i; j++){
			if(strcmp(p1->name,p2->name)>0){
				t.rollno = p1->rollno;
				t.percentage=p1->percentage;
				strcpy(t.name,p1->name);
				
				p1->rollno = p2->rollno;
				p1->percentage=p2->percentage;
				strcpy(p1->name,p2->name);
				
				p2->rollno = t.rollno;
				p2->percentage=t.percentage;
				strcpy(p2->name,t.name);	
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	printf("Sorted according to names\n");
}
void sort_rollno(stu *ptr){
	int i,j,c=count_node(ptr);
	stu *p1=ptr,*p2,t;
	for(i=0 ; i<c-1; i++){
		p2=p1->next;
		for(j=0; j<c-1-i; j++){
			if(p1->rollno > p2->rollno){
				t.rollno = p1->rollno;
				t.percentage=p1->percentage;
				strcpy(t.name,p1->name);
				
				p1->rollno = p2->rollno;
				p1->percentage=p2->percentage;
				strcpy(p1->name,p2->name);
				
				p2->rollno = t.rollno;
				p2->percentage=t.percentage;
				strcpy(p2->name,t.name);	
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	printf("Sorted according to roll numbers\n");
}
void sort_percentage(stu *ptr){
int i,j,c=count_node(ptr);
	stu *p1=ptr,*p2,t;
	for(i=0 ; i<c-1; i++){
		p2=p1->next;
		for(j=0; j<c-1-i; j++){
			if(p1->percentage > p2->percentage){
				t.rollno = p1->rollno;
				t.percentage=p1->percentage;
				strcpy(t.name,p1->name);
				
				p1->rollno = p2->rollno;
				p1->percentage=p2->percentage;
				strcpy(p1->name,p2->name);
				
				p2->rollno = t.rollno;
				p2->percentage=t.percentage;
				strcpy(p2->name,t.name);	
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	printf("Sorted according to percentages\n");
}
