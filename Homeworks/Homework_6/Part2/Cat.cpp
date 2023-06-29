
#include "Cat.h"
//Constructor that sets the specifed type to be the type.
Cat::Cat(string tp, string c):Animal(c){

    type = tp;
}
//default constructor that sets the type to "unk". 
Cat::Cat():Animal("black"){
    type = "unk";
}

/**
 * Sets type to specified type
 * @param string tp
 * @returns void
 * side effect: changes type to specifed type
*/
void Cat::setType(string tp) {
    type = tp;
}
/**
 * Prints out the information about the animal
 * @param string c -color
 * @returns void
 * side effect: prints to the console
*/
void Cat::displayInfo(string c) {
    cout << "I am a " << type << endl;
    cout << "My color is " << c << endl;
}
/**
 * Prints out cat talking sounds to the console
 * @returns void
 * side effect: prints to the console
*/
void Cat::meow() {
    cout << "I can meow! Meow meow!!" << endl;
}
