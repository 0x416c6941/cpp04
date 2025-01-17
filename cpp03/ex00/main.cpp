#include <ClapTrap.hpp>
#include <climits>

#define DEFAULT_CLAPTRAP_EP 10

int main() {
    ClapTrap robin("Robin");

    for (int i = 0; i <= DEFAULT_CLAPTRAP_EP; i++) {
        robin.attack("lion king");
    }
    robin = ClapTrap("Robin");
    robin.takeDamage(UINT_MAX);
    robin = ClapTrap("Robin");
    for (int i = 0; i <= DEFAULT_CLAPTRAP_EP; i++) {
        robin.beRepaired(UINT_MAX);
    }
    return 0;
}
