sales: coffee_shop.o calculations.o
	gcc -g -Wall coffee_shop.o calculations.o -lm -o sales.exe

coffee_shop.o: coffee_shop.c calculations.h
	gcc -g -Wall -c coffee_shop.c

calculations.o: calculations.c calculations.h
	gcc -g -Wall -c calculations.c

clean:
	del -f coffee_shop.o calculations.o sales.exe

all: sales