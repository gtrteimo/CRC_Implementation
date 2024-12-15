all: cyclicRedundicCheck.exe out
cyclicRedundicCheck.exe: src\main.c bin\intermediates\cyclicRedundicCheck.o bin\intermediates\in-output.o bin\intermediates\errorDevil.o 
	gcc -Wall -o bin\cyclicRedundicCheck.exe src\main.c bin\intermediates\cyclicRedundicCheck.o bin\intermediates\in-output.o bin\intermediates\errorDevil.o

bin\intermediates\cyclicRedundicCheck.o: src\cyclicRedundicCheck.c
	gcc -Wall -c -o bin\intermediates\cyclicRedundicCheck.o src\cyclicRedundicCheck.c

bin\intermediates\in-output.o: src\in-output.c
	gcc -Wall -c -o bin\intermediates\in-output.o src\in-output.c

bin\intermediates\errorDevil.o: src\errorDevil.c
	gcc -Wall -c -o bin\intermediates\errorDevil.o src\errorDevil.c


cdebug: cyclicRedundicCheck.exe
	gdb .\bin\cyclicRedundicCheck.exe
debug: 
	gdb .\bin\cyclicRedundicCheck.exe
out:
	.\bin\cyclicRedundicCheck.exe
clean: 
	del /s /q bin\*.exe bin\intermediates\*.o