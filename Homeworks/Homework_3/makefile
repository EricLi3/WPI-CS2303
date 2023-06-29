analysis: coffee_shop_sales.o calculations.o
	gcc -g -Wall coffee_shop_sales.o calculations.o -lm -o analysis.exe

coffee_shop_sales.o: coffee_shop_sales.c calculations.h
	gcc -g -Wall -c coffee_shop_sales.c

calculations.o: calculations.c calculations.h
	gcc -g -Wall -c calculations.c

clean:
	del -f coffee_shop_sales.o calculations.o analysis.exe

all: analysis