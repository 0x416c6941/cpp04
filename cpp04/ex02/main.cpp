#include <cstddef>
#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>
#include <iostream>

int main() {
    const std::size_t ANIMAL_SIZE = 10;
    Animal *animals[ANIMAL_SIZE];

    for (std::size_t i = 0; i < ANIMAL_SIZE / 2; i++) {
        animals[i] = new Dog();
        animals[i]->makeSound();
    }
    for (std::size_t i = ANIMAL_SIZE / 2; i < ANIMAL_SIZE; i++) {
        animals[i] = new Cat();
        animals[i]->makeSound();
    }
    for (std::size_t i = 0; i < ANIMAL_SIZE; i++) {
        delete animals[i];
    }
    return 0;
}
