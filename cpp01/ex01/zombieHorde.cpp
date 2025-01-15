#include <Zombie.hpp>
#include <string>

Zombie * zombieHorde(int N, std::string name) {
    Zombie * ret = new Zombie[N];

    for (int i = 0; i < N; i++) {
        ret[i].set_name(name);
    }
    return ret;
}
