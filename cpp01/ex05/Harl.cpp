#include <Harl.hpp>
#include <iostream>
#include <string>
#include <cstddef>
#include <utility>

Harl::Harl() {
}

Harl::Harl(const Harl & src) {
    (void) src;
}

Harl & Harl::operator = (const Harl & src) {
    if (this == &src) {
        return *this;
    }
    return *this;
}

Harl::~Harl() {
}

void Harl::debug() const {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;
}

void Harl::info() const {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning() const {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
              << std::endl;
}

void Harl::error() const {
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level) const {
    const std::size_t COMPLAINTS_SIZE = 4;
    std::pair<const std::string, void (Harl::*)() const> complaints[COMPLAINTS_SIZE] = {
        std::make_pair("DEBUG", &Harl::debug),
        std::make_pair("INFO", &Harl::info),
        std::make_pair("WARNING", &Harl::warning),
        std::make_pair("ERROR", &Harl::error)
    };

    for (std::size_t i = 0; i < COMPLAINTS_SIZE; i++) {
        if (level.compare(complaints[i].first) == 0) {
            (this->*complaints[i].second)();
            break;
        }
    }
}
