#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <iostream>
#include "contact.hpp"

class PhoneBook 
{
    private:
        Contact _contacts[8];
        size_t  _index;

    public:
        PhoneBook(); // createur
        ~PhoneBook(); // destructeur
        void add(); // fonction membre
        void search();
        void display();
        
};

#endif