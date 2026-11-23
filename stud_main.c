//main function for student database management  
#include"student.h"

int main(){
	printf("\033[32m**********STUDENT DATA MANAGEMENT**********\033[0m\n");
	stu *headptr=0;		//head pointer initializing to zero
	char op;			//declaration of op to store the option selection
	
	read_records(&headptr);		//read if the file already exist
	
	while(1){		//infinite loop to run continuously until stopped manually
		printf("\033[34m--------menu--------\n");
		printf("Enter the choice\n");
		printf("a/A:Add new record\n");
		printf("d/D:Delete according to name\n");
		printf("s/S:Show the list\n");
		printf("m/M:Modify the data\n");
		printf("v/V:Save and exit \n");
		printf("e/E:Exit without saving\n");
		printf("t/T:Sort the list\n");
		printf("l/L:Delete all the records\n");
		printf("r/R:Reverse the List\n");
		printf("\033[0m");
		scanf(" %c",&op);
		switch(op){
			case 'a':case 'A':add_record(&headptr);break;
			case 's':case 'S':show_list(headptr);break;
			case 'd':case 'D':delete_record(&headptr);break;
			case 'm':case 'M':modify_data(&headptr);break;
			case 't':case 'T':sort_records(headptr);break;
			case 'l':case 'L':delete_all(&headptr);break;
			case 'r':case 'R':reverse_links(&headptr);break;
			case 'e':case 'E':free_all(headptr);
			exit(0);
			case 'v':case 'V':save_records(headptr);
			free_all(headptr);
			printf("\033[33m**********     end     **********\n\033[0m");
				exit(0);
			default:printf("\033[31mInvalid option\033[0m\n");
		}
	}
	return 0;
}
