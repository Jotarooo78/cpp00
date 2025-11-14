#include "phonebook.hpp"

PhoneBook::PhoneBook() : _index(0){}

void PhoneBook::add()
{
    std::string cmd;

    std::cout << "Name :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.length() > 10){
        cmd = cmd.substr(0, 10);
    }
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setFirstName(cmd);

    std::cout << "Lastname :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.length() > 10){
        cmd = cmd.substr(0, 10);
    }
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setLastName(cmd);

    std::cout << "Nickname :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.length() > 10){
        cmd = cmd.substr(0, 10);
    }
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setNickName(cmd);

    std::cout << "Phone number :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.length() > 10){
        cmd = cmd.substr(0, 10);
    }
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setPhoneNumber(cmd);

    std::cout << "Darkest secret :" << std::endl;
    std::getline(std::cin, cmd);
    if (cmd.length() > 10){
        cmd = cmd.substr(0, 10);
    }
    if (cmd.empty()){
        std::cout << "It can't be empty" << std::endl;
        return ;
    }
    _contacts[_index].setDarkestSecret(cmd);
    
    _index = _index + 1;
    if (_index > 8)
        _index = 0;
    std::cout << "New contact added" << std::endl;
    return ;
}

void PhoneBook::display(){

    int new_index = 0;
    
    while (new_index <= _index)
    {
        std::cout << _contacts[new_index].

    }
}

void PhoneBook::search()
{
    int cmd;

    std::cout << "Please enter a number between 1 to 8" << std::endl;
    //display
    std::cin >> cmd;
    if (cmd < 1 && cmd > 8){
        std::cout << "Invalid number" << std::endl;
        return ;
    }

}