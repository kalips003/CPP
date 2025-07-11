#include "Zombie.hpp"
#include <iostream>
// #include <iomanip>

int main() {    
    int N = 5;
    Zombie* horde = zombieHorde(5, "Frank");
    Zombie* horde2 = zombieHorde_v2(5, "Frankette");


    for (int i = 0; i < N; i++) {       
        horde[i].announce();
        horde2[i].announce();
    }

    for (int i = 0; i < N; i++)
        horde[i].~Zombie();
    operator delete[](horde);

    delete[] horde2;
    return 0;
}