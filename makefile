invert.out : main.o create_database.o display_db.o save_database.o search_word.o update_database.o validation.o
	gcc -o invert.out main.o create_database.o display_db.o save_database.o search_word.o update_database.o validation.o
main.o : main.c header.h
	gcc -c main.c -o main.o
create_database.o : create_database.c header.h
	gcc -c create_database.c -o create_database.o
display_db.o : display_db.c header.h
	gcc -c display_db.c -o display_db.o
save_database.o : save_database.c header.h
	gcc -c save_database.c -o save_database.o
search_word.o : search_word.c header.h
	gcc -c search_word.c -o search_word.o
update_database.o : update_database.c header.h
	gcc -c update_database.c -o update_database.o
validation.o : validation.c header.h
	gcc -c validation.c -o validation.o
clean:
	rm *.o *.out