Eric Li
Program : matrix_calc.c

This program reads in two matrices and a character representing the operation you want to do on these matrices. 
We have two operations avaliable for the matrices, addition and subtraction. After entering the data files 
which contain the number of elements in the matrix and the elements of the matrix, and adding eiher 'a' for addition or 's' for subtraction, 
hit enter and you will see the resulting matrix printed out on the console after doing the operation you specified. 

How to use:
Assuming you are in the right directory and have your data files downloaded, Type "make" or "mingw32-make" into the terminal and hit enter 
determing if you are using a windows machine or not.This will generate the output and execuable files. Then type "./matrixCalc.exe" to the terminal,
enter the two data files and your choice of singular choice of operation and hit enter. You should then see a new matrix on your console, which is the matrix after doing the specifed computation of the matricies entered. 
you can also type gcc -Wall matrix_calc.c matrix_math.c -matrixCalc.exe and get the same result.


Sources:
https://stackoverflow.com/questions/27525617/how-to-properly-compare-command-line-arguments . 
Used this site to learn how to compare command line argunments to execute either the add function or the subract function on the matrices. 