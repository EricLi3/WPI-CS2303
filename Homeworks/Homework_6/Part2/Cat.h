#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.h"
using std::string;
using std::cout;
using std::endl;

// derived class
class Cat : public Animal {

    public:
        Cat(string tp, string c); //Constructor that sets the specifed type to be the type.

        Cat();                      // default type to "unk"

        /**
        * Sets type to specified type
        * @param string tp
        * @returns void
        * side effect: changes type to specifed type
        */
        void setType(string tp);

        /**
        * Prints out the information about the animal
        * @param string c -color
        * @returns void
        * side effect: prints to the console
        */
        void displayInfo(string c);
    
        /**
        * Prints out cat talking sounds to the console
        * @returns void
        * side effect: prints to the console
        */
        void meow();    //print "I can speak! Meow meow!!"
};
#endif

