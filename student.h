//header file for student data management
#ifndef STUDENT_H
#define STUDENT_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct student{
	int rollno;
	char name[50];
	float percentage;
	struct student *next;


}stu;

//main functions
void read_records(stu **ptr);
void add_record(stu **ptr);
void delete_record(stu **ptr);
void save_records(stu *ptr);
void show_list(stu *ptr);
void sort_records(stu *ptr);
void modify_data(stu **ptr);
void delete_all(stu **ptr);
void reverse_links(stu **);
void exit_all(stu *ptr);

//other functions
void free_all(stu *ptr);
void delete_name(stu **ptr);
void delete_rollno(stu **ptr);
void modify_rollno(stu **ptr);
void modify_name(stu **ptr);
void modify_percentage(stu **ptr);
void sort_name(stu *ptr);
void sort_rollno(stu *ptr);
void sort_percentage(stu *ptr);
int count_node(stu *ptr);


#endif
