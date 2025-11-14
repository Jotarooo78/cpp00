#include "phonebook.hpp"

PhoneBook::PhoneBook() : _index(0), _total(0){}

PhoneBook::~PhoneBook(){}

std::string formatField(std::string field){
    if (field.length() > 10){
        field = field.substr(0, 9);
        field += '.';
    }
    return field;
}

void PhoneBook::add()
{
    std::string cmd;

    std::cout << "Name :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setFirstName(cmd);

    std::cout << "Lastname :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setLastName(cmd);

    std::cout << "Nickname :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setNickName(cmd);

    std::cout << "Phone number :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setPhoneNumber(cmd);

    std::cout << "Darkest secret :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setDarkestSecret(cmd);
    
    _index = _index + 1;
    if (_index > 8)
        _index = 0;
    if (_total < 9)
        _total = _total + 1;
    std::cout << "New contact added" << std::endl;
    return ;
}

void PhoneBook::display(){

    size_t new_index = 1;
    
    while (new_index <= _total)
    {
        std::cout << std::setw(10) << new_index << "|";
        std::cout << std::setw(10) << formatField(_contacts[new_index].getFirstName()) << "|";
        std::cout << std::setw(10) << formatField(_contacts[new_index].getLastName()) << "|";
        std::cout << std::setw(10) << formatField(_contacts[new_index].getNickName()) << std::endl;
        new_index = new_index + 1;
    }   
}

void PhoneBook::search()
{
    int cmd;

    if (_total == 0){
        std::cout << "No contact in the Phonebook yet" << std::endl;
        return ;
    }
    std::cout << "Please enter a number between 1 to 8" << std::endl;
    PhoneBook::display();
    std::cin >> cmd;
    if ((cmd < 1 || cmd > 8)){
        std::cout << "Invalid number" << std::endl;
        return ;
    }
}