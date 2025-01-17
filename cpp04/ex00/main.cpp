#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongCat.hpp>
#include <iostream>

int main() {
    const Animal * meta = new Animal();
    const Animal * j = new Dog();
    const Animal * i = new Cat();
    const WrongAnimal * wa = new WrongAnimal();
    const WrongAnimal * wc = new WrongCat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    std::cout << wc->getType() << std::endl;
    wa->makeSound();
    wc->makeSound();
    delete wa;
    delete wc;
    return 0;
}
