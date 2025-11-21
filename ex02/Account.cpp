/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:31:33 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/21 11:56:47 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) { // creator
    
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";created" << std::endl;
} 

Account::~Account() {  // destructor
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";closed" << std::endl;
}

int Account::getNbAccounts(){
    return (_nbAccounts);
}

int Account::getTotalAmount(){
    return (_totalAmount);
}

int Account::getNbDeposits(){
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(){
    return (_totalNbWithdrawals);
}

int Account::checkAmount() const{
    return (_amount);
}

void Account::displayStatus() const{

    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << checkAmount();
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void Account::_displayTimestamp(){
    
    time_t ts = time(0);
    
    char buf[20];

    strftime(buf, 20, "%Y%m%d_%H%M%S", localtime(&ts));
    std::cout << '[';
    std::cout << buf;
    std::cout << "] ";
}

void    Account::displayAccountsInfos(){

    _displayTimestamp();
    
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ){
    
    _displayTimestamp();
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << checkAmount();
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << ";amount:" << checkAmount();;
    std::cout << ";nb_deposits:" << _nbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    
    _displayTimestamp();
    if (checkAmount() > withdrawal){
        
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount:" << checkAmount();;
        std::cout << ";withdrawal:" << withdrawal;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << ";amount:" << checkAmount();;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals;
        std::cout << std::endl;
        return (true);
    }
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << checkAmount();;
    std::cout << ";withdrawal:refused" << std::endl;
    return (false);
}
