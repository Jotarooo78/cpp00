/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:31:33 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/20 16:53:42 by armosnie         ###   ########.fr       */
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
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
} 

Account::~Account() {  // destructor
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed";
    if (!(getNbAccounts() == _accountIndex + 1))
        std::cout << std::endl;
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
    std::cout << ";amount:" << _amount;
    std::cout << ";deposit:" << _nbDeposits;
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
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals();
    std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ){
    
    _displayTimestamp();
    _nbDeposits += 1;
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amout:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << getNbDeposits();
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    
    _displayTimestamp();
    if (checkAmount() > withdrawal){
        
        _nbWithdrawals += 1;
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amout:" << _amount;
        std::cout << ";withdrawals:" << withdrawal;
        _amount -= withdrawal;
        std::cout << ";amount:" << _amount;
        std::cout << ";nb_withdrawal:" << getNbWithdrawals();
        std::cout << std::endl;
        return (true);
    }
    std::cout << "index:" << getNbAccounts();
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawals:refused" << std::endl;
    return (false);
}
