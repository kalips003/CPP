#include <iostream>

// ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }   

    for (int i = 1; i < ac; i++)
        for (int j = 0; av[i][j]; j++)
            std::cout << static_cast<char>(std::toupper(av[i][j]));
    std::cout << std::endl;

    return 0;
}