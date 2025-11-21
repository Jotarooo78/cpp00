/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:32:06 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/19 16:32:08 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() : _index(0), _total(0){ return ;}

PhoneBook::~PhoneBook(){ return ;}

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
    if (_index > 7)
        _index = 0;
    if (_total < 8)
        _total = _total + 1;
    std::cout << "New contact added" << std::endl;
    return ;
}

void PhoneBook::display(){

    size_t new_index = 0;
    
    while (new_index < _total)
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
    std::string input;
    int tmp_index;

    if (_total == 0){
        std::cout << "No contact in the Phonebook yet" << std::endl;
        return ;
    }
    PhoneBook::display();
    std::cout << "Please enter an index between 0 to 7 : ";
    std::cin >> input;
    if (input.size() != 1 || (input[0] < '0' || input[0] > '7')){
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    tmp_index = input[0] - '0';
    std::cout << "First name: " << _contacts[tmp_index].getFirstName() << std::endl;
    std::cout << "Last name: " << _contacts[tmp_index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[tmp_index].getNickName() << std::endl;
    std::cout << "Phone: " << _contacts[tmp_index].getPhoneNumber() << std::endl;
    std::cout << "Secret: " << _contacts[tmp_index].getDarkestSecret() << std::endl;
    return ;
}