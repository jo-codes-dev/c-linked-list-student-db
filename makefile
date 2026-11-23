compiler = cc
exe: stud_main.o stud_add.o stud_show.o stud_del.o stud_save.o stud_mod.o stud_sort.o
	$(compiler) $^ -o $@
	
stud_main.o:stud_main.c
	$(compiler) -c $^
stud_add.o:stud_add.c
	$(compiler) -c $^
stud_show.o:stud_show.c
	$(compiler) -c $^
stud_del.o:stud_del.c
	$(compiler) -c $^
stud_save.o:stud_save.c
	$(compiler) -c $^	
stud_mod.o:stud_mod.c
	$(compiler) -c $^
stud_sort.o:stud_sort.c
	$(compiler) -c $^
clear:
	@echo "cleaning up..."
	@rm -vr *.o
