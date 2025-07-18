#include "Zombie.hpp"
#include <iostream>
// #include <iomanip>

int main() {    
    int N = 15;
    
    Zombie* horde = zombieHorde(N, "Frank");
    Zombie* horde2 = zombieHorde_v2(N, "Frankette");


    for (int i = 0; i < N; i++) {
        std::cout << "\e[38;5;" << (i + 43) % 256 << "m";    
        horde[i].announce();
        std::cout << "\e[38;5;" << (i + 152) % 256 << "m";    
        horde2[i].announce();
    }
    std::cout << std::endl;

    for (int i = 0; i < N; i++)
        horde[i].~Zombie();
    operator delete[](horde);

    delete[] horde2;

    return 0;
}