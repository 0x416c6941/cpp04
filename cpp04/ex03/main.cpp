#include <IMateriaSource.hpp>
#include <MateriaSource.hpp>
#include <Ice.hpp>
#include <Cure.hpp>
#include <World.hpp>
#include <ICharacter.hpp>
#include <Character.hpp>
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    World world;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(0);
    delete me;
    std::cout << std::endl;
    me = new Character("me", world);
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    me->unequip(0);
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0);
    delete src;
    delete bob;
    delete me;
    return 0;
}
