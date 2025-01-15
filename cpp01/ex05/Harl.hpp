#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
    private:
        void debug() const;
        void info() const;
        void warning() const;
        void error() const;

    public:
        Harl();
        Harl(const Harl & src);
        Harl & operator = (const Harl & src);
        virtual ~Harl();

        void complain(std::string level) const;
};

#endif  // HARL_HPP
