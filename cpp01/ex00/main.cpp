#include <Zombie.hpp>
#include <string>
#include <iostream>

// We don't have any other files available,
// so I'll just declare those functions here...
Zombie * newZombie(std::string name);
void randomChump(std::string name);

int main() {
    Zombie * heap_zombie = newZombie("Pepe");

    std::cout << "Heap zombie:" << std::endl;
    heap_zombie->announce();
    std::cout << std::endl;
    std::cout << "Stack zombie:" << std::endl;
    randomChump("Gigachad");
    std::cout << std::endl;
    delete heap_zombie;
    return 0;
}
