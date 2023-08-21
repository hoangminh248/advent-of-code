DAY = day1
INC = D:/ADVENT-OF-CODE/mylib/

output: $(DAY).o $(INC)myCPlib.o
	gcc $(DAY).o $(INC)myCPlib.o -o $(DAY).exe

$(DAY).o : $(DAY).c
	gcc -c $(DAY).c -I $(INC)
$(INC)myCPlib.o: $(INC)myCPlib.c $(INC)myCPlib.h
	gcc -c $(INC)myCPlib.c -o $(INC)myCPlib.o
clean: 
	del *.o *.exe
run:
	./$(DAY)