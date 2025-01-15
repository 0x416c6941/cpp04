#include <cstddef>
#include <string>
#include <Harl.hpp>
#include <iostream>

#define INVALID_ARGS    1

int main(int argc, char * argv[]) {
    const int MIN_ARGS = 2;
    const std::string INSUFFICIENT_ARGS = "main():: Missing filter argument.";
    Harl yapper;
    const std::size_t LOGLEVEL_ARG = 1;

    if (argc < MIN_ARGS) {
        std::cout << INSUFFICIENT_ARGS << std::endl;
        return INVALID_ARGS;
    }
    yapper.set_loglevel(std::string(argv[LOGLEVEL_ARG]));
    yapper.yap();
    return 0;
}
