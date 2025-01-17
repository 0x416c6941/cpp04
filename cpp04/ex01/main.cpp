#include <cstddef>
#include <Animal.hpp>
#include <sstream>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>
#include <iostream>

int main() {
    const std::size_t ANIMAL_SIZE = 10, IDEAS_TO_ADD = 200;
    Animal *animals[ANIMAL_SIZE];
    std::stringstream ss;

    for (std::size_t i = 0; i < ANIMAL_SIZE / 2; i++) {
        animals[i] = new Dog();
        animals[i]->makeSound();
        for (std::size_t j = 0; j < IDEAS_TO_ADD; j++) {
            ss.str(""); // Clearing the stream.
            ss << "Idea " << j + 1;
            animals[i]->get_brain().add_idea(ss.str());
        }
        // Weird, but let's just let this check be
        // (I'm being a bit too paranoid).
        if (animals[i]->get_brain().get_ideas_cnt() != 0) {
            std::cout << "Last idea that was added to the animals brain: "
                      << animals[i]->get_brain().get_idea(0) << std::endl;
        }
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
