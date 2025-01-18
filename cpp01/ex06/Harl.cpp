#include <Harl.hpp>
#include <iostream>
#include <string>
#include <cstddef>
#include <utility>

Harl::Harl() : m_log_level(NO_LOG) {
}

Harl::Harl(const Harl & src) : m_log_level(src.m_log_level) {
}

Harl & Harl::operator = (const Harl & src) {
    if (this == &src) {
        return *this;
    }
    m_log_level = src.m_log_level;
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

void Harl::set_loglevel(std::string level) {
    if (level.compare("DEBUG") == 0) {
        m_log_level = DEBUG;
    }
    else if (level.compare("INFO") == 0) {
        m_log_level = INFO;
    }
    else if (level.compare("WARNING") == 0) {
        m_log_level = WARNING;
    }
    else if (level.compare("ERROR") == 0) {
        m_log_level = ERROR;
    }
}

void Harl::yap() const {
    // This is stupid, but when using g++ we can't just fallthrough the cases,
    // since otherwise -Werror would cry out loud...
    // clang++ is fine though.
    switch (m_log_level) {
        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
            std::cout << std::endl;
            std::cout << "[ INFO ]" << std::endl;
            info();
            std::cout << std::endl;
            std::cout << "[ WARNING ]" << std::endl;
            warning();
            std::cout << std::endl;
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            info();
            std::cout << std::endl;
            std::cout << "[ WARNING ]" << std::endl;
            warning();
            std::cout << std::endl;
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            warning();
            std::cout << std::endl;
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            std::cout << std::endl;
            break;
        case NO_LOG:
            std::cout << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
    }
}
