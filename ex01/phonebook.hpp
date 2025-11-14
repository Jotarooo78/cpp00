#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <iostream>
#include "contact.hpp"

class PhoneBook 
{
    private:
        Contact contacts[8];
        size_t  index;
        size_t  total;


    public:
        PhoneBook(); // createur
        ~PhoneBook(); // destructeur
        void add(); // fonction membre
        void search();
        void display();
        
};

#endif