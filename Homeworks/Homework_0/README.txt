prime_number.c
Eric Li

Summary: This program determines if an entered number is prime or not. We prompt the user for a value, for when they enter a number
and press enter, the program will print the appropriate result/response to the terminal.

How to use this program: (Assuming that you are in the directory where prime_number.c is in)

1. We first have to compile the code, so assuming you have the gcc compiler set up on your computer,
type "gcc -Wall prime_number.c -o out.exe" in the terminal which will compile the code and make an executable file called out.exe.


2. To run the program, type "./out.exe" in the terminal; right under where you just typed, and you should see a prompt in the terminal
asking you to enter an number. So enter a number and click enter, and you will see a message telling you whether the number you entered is prime or not.

Sources: Got the idea of using a return 0 in my loop to end the program from a stack overflow thread
https://stackoverflow.com/questions/26362549/does-return-0-exit-a-program-or-exit-a-loop. 