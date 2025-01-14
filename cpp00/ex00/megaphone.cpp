#include <string>
#include <iostream>
#include <cstddef>
#include <cctype>

int main(int argc, char * argv[]) {
    const std::string NO_ARGS = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

    if (argc <= 1) {
        std::cout << NO_ARGS << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        for (std::size_t j = 0; argv[i][j] != '\0'; j++) {
            std::cout << (char) std::toupper(argv[i][j]);
        }
    }
    std::cout << std::endl;
    return 0;
}
