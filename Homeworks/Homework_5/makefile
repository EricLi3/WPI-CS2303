matrixCalc: matrix_calc.o matrix_math.o
	gcc -g -Wall matrix_calc.o matrix_math.o -lm -o matrixCalc // don't need the .exe flag

matrix_calc.o: matrix_calc.c matrix_math.h
	gcc -g -Wall -c matrix_calc.c

matrix_math.o: matrix_math.c matrix_math.h
	gcc -g -Wall -c matrix_math.c

clean:
	del -f matrix_calc.o matrix_math.o matrixCalc

all: matrixCalc