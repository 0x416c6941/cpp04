#include <Zombie.hpp>
#include <string>

Zombie * newZombie(std::string name) {
    Zombie * ret = new Zombie(name);
    return ret;
}
