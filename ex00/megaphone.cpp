#include <iostream>

int main(int ac, char **av)
{
    if (ac < 1)
      return (0);
    if (ac == 1)
      return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *", 0);
    if (ac > 1)
    {
      for (int i = 1; av[i]; i++)
      {
        std::string string = av[i];
        for (int j = 0; string[j]; j++)
          std::cout << static_cast<char>(std::toupper(string[j]));
      }
    }
    return (0);
}