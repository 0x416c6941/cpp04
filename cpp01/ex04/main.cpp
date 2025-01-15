#include <string>
#include <iostream>
#include <defs.hpp>
#include <fstream>
#include <stdexcept>
#include <cstddef>

/**
 * Reads entire file to a string and then returns it.
 * @param   in  Input file stream.
 * @throws  std::ios_base::failure  IO error occured.
 * @return  Read file as a string.
 */
std::string read_file(std::ifstream & in) {
    std::string ret;
    char buf;

    for (;;) {
        in >> std::noskipws >> buf;
        if (!in.good() && !in.eof()) {
            throw std::ios_base::failure("read_file():: IO error.");
        }
        else if (in.eof()) {
            break;
        }
        ret.push_back(buf);
    }
    return ret;
}

/**
 * Replaces all occurences of \p s1 in \p to_replace with \p s2.
 * @param   to_replace  String to replace \p s1 with \p s2 in.
 * @param   s1          String to replace.
 * @param   s2          String to replace \p s1 with.
 */
void replacement_magic(std::string & to_replace,
                       const std::string & s1, const std::string & s2) {
    std::size_t pos = 0;

    // Keep replacing s1 with s2 until no more occurences are found.
    while ((pos = to_replace.find(s1, pos)) != std::string::npos) {
        to_replace.erase(pos, s1.length());
        to_replace.insert(pos, s2);
    }
}

int main(int argc, char * argv[]) {
    const int REQUIRED_ARGS = 4;
    const std::string MISSING_ARGS = "Usage: ./program filename s1 s2.";
    std::ifstream in;
    std::ofstream out;
    std::string file;

    if (argc != REQUIRED_ARGS) {
        std::cerr << MISSING_ARGS << std::endl;
        return INVALID_ARGS;
    }
    in.open(argv[IN_FILENAME]);
    if (!in.is_open()) {
        std::cerr << "Error opening file: " << argv[IN_FILENAME] << std::endl;
        return IO_ERROR;
    }
    try {
        file = read_file(in);
    }
    catch (std::ios_base::failure & e) {
        std::cerr << e.what() << std::endl;
        return IO_ERROR;
    }
    out.open(std::string(argv[IN_FILENAME]).append(".replace").c_str(),
             std::ios::trunc);
    if (!out.is_open()) {
        std::cerr << "Error opening file: "
                  << argv[IN_FILENAME] << ".replace" << std::endl;
        return IO_ERROR;
    }
    replacement_magic(file, std::string(argv[S1]), std::string(argv[S2]));
    out << file;
    if (!out.good()) {
        std::cerr << "Error writing to file: "
                  << argv[IN_FILENAME] << ".replace" << std::endl;
        return IO_ERROR;
    }
    return 0;
}
