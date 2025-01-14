#include <Zombie.hpp>
#include <string>
#include <iostream>

// We don't have any other files available,
// so I'll just declare those functions here...
Zombie * newZombie(std::string name);
void randomChump(std::string name);
Zombie * zombieHorde(int N, std::string name);

int main() {
    Zombie * zombie = newZombie("Pepe");
    const int horde_size = 10;
    const std::string horde_zombie_name = "BRAIN";

    std::cout << "Heap zombie:" << std::endl;
    zombie->announce();
    std::cout << std::endl;
    std::cout << "Stack zombie:" << std::endl;
    randomChump("Gigachad");
    std::cout << std::endl;
    delete zombie;
    std::cout << std::endl;
    zombie = zombieHorde(horde_size, horde_zombie_name);
    for (int i = 0; i < horde_size; i++) {
        zombie[i].announce();
    }
    delete[] zombie;
    return 0;
}
