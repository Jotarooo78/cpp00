/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:32:14 by armosnie          #+#    #+#             */
/*   Updated: 2025/11/19 16:32:22 by armosnie         ###   ########.fr       */
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
        if (cmd == "")
            return (0);
        else if (cmd == "ADD")
            pb.add();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            break ;
    }
    return (0);
}