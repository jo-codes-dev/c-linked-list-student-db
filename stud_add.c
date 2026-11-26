//file that contain add exit_all and revers functions to the data
#include"student.h"


void add_record(stu **ptr){
	printf("\033[33m----------------------------------------\n");
	stu *new=malloc(sizeof(stu));
retake:	printf("Enter name and percentage\n");
	if(scanf("%19s%f",new->name,&new->percentage)!=2){
		//%19s make sure that only 19 char are entered
		while(getchar()!='\n');
		//Clears invalid input from buffer
		printf("Invalid input. Enter valid name and percentage\n");
		goto retake;
	}
	for(int i = 0; new->name[i] != '\0'; i++){
		if(!((new->name[i] >= 'A' && new->name[i] <= 'Z') ||
		     (new->name[i] >= 'a' && new->name[i] <= 'z'))){
			printf("Invalid name. Use alphabets only.\n");
			goto retake;
		}
	}
	if(new->percentage<0 || new->percentage >100){
		printf("Enter the valid percentage\n");
		goto retake;
	}
	int roll = 1;
	while(1){
		stu *temp = *ptr;
		int found = 0;
		while(temp != 0){
			if(temp->rollno == roll){
				found = 1;
				break;
			}
			temp = temp->next;
		}
		if(!found) break;
		roll++;
	}
	new->rollno = roll;
	if(*ptr == 0 || (*ptr)->rollno > new->rollno){
		new->next = *ptr;
		*ptr = new;
	}else{
		stu *prev = *ptr;
		while(prev->next != 0 && prev->next->rollno < new->rollno){
			prev = prev->next;
		}
		new->next = prev->next;
		prev->next = new;
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
	free(a);
	printf("\033[33m----------------------------------------\n");
}

