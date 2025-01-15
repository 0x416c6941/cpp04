#include <string>
#include <iostream>

int main() {
    const std::string brain = "HI THIS IS BRAIN",
                      * stringPTR = &brain, & stringREF = brain;

    std::cout << "brain's addr: " << &brain
              << ", stringPTR's stored addr: " << stringPTR
              << ", stringREF's referenced variable addr: " << &stringREF << std::endl;
    std::cout << "brain: " << brain
              << ", stringPTR: " << *stringPTR
              << ", stringREF: " << stringREF << std::endl;
    return 0;
}
