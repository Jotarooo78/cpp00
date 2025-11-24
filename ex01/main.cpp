/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:32:14 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/24 14:17:14 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (1)
    {
        std::cout << "waiting for commande [ADD], [SEARCH] or [EXIT]" << '\n';
        std::cin >> cmd;
        std::cin.ignore();
        if (std::cin.eof()){
            std::cout << "\nEOF detected, exiting..." << std::endl;
            std::cin.clear();
            break ;
        }
        if (cmd == "")
            continue ;
        else if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            break ;
    }
    return (0);
}