#include "phonebook.hpp"

void PhoneBook::add()
{
    std::string tmp;
    Contact contact;

    std::cout << "Name :" << std::endl;
    std::getline(std::cin, tmp);
    if (tmp.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    contact.setFirstName(tmp);

    std::cout << "Lastname :" << std::endl;
    std::getline(std::cin, tmp);
    if (tmp.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    contact.setLastName(tmp);

    std::cout << "Nickname :" << std::endl;
    std::getline(std::cin, tmp);
    if (tmp.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    contact.setNickName(tmp);

    std::cout << "Phone number :" << std::endl;
    std::getline(std::cin, tmp);
    if (tmp.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    contact.setPhoneNumber(tmp);

    std::cout << "Darkest secret :" << std::endl;
    std::getline(std::cin, tmp);
    if (tmp.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    contact.setDarkestSecret(tmp);
    
    
}