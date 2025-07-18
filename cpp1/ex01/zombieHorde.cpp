#include "Zombie.hpp"

Zombie  *zombieHorde( int N, std::string name ) {
    
    if (N <= 0) {
        std::cout << RED "bad N argument" RESET << std::endl;
        return NULL;
    }
    
    Zombie* horde = static_cast<Zombie*>(operator new[](sizeof(Zombie) * N));
    for (int i = 0; i < N; i++)
        new (&horde[i]) Zombie(name);
    
    return horde;
}

Zombie  *zombieHorde_v2( int N, std::string name ) {
    
    if (N <= 0) {
        std::cout << RED "bad N argument" RESET << std::endl;
        return NULL;
    }

    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    
    return horde;
}