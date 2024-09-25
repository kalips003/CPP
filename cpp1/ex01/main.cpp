#include "Zombie.hpp"
#include <iostream>
// #include <iomanip>

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(5, "Frank");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}