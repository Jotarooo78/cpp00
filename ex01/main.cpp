#include "phonebook.hpp"

int main()
{
    PhoneBook pb;
    std::string cmd;

    while (1)
    {
        std::cout << "wait for commande [ADD], [SEARCH] or [EXIT]" << '\n';
        std::cin >> cmd;
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