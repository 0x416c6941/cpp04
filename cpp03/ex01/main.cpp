#include <ClapTrap.hpp>
#include <ScavTrap.hpp>
#include <climits>

#define DEFAULT_CLAPTRAP_EP 10
#define DEFAULT_SCAVTRAP_EP 50

int main() {
    ClapTrap robin("Robin");
    ScavTrap vershinin("Vershinin");

    for (int i = 0; i <= DEFAULT_CLAPTRAP_EP; i++) {
        robin.attack("lion king");
    }
    robin = ClapTrap("Robin");
    robin.takeDamage(UINT_MAX);
    robin = ClapTrap("Robin");
    for (int i = 0; i <= DEFAULT_CLAPTRAP_EP; i++) {
        robin.beRepaired(UINT_MAX);
    }
    for (int i = 0; i <= DEFAULT_SCAVTRAP_EP; i++) {
        vershinin.attack("some guy");
    }
    vershinin = ScavTrap("Vershinin");
    vershinin.takeDamage(UINT_MAX);
    vershinin = ScavTrap("Vershinin");
    vershinin.guardGate();
    vershinin.attack("some guy");
    return 0;
}
