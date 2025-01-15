#ifndef HARL_HPP
#define HARL_HPP

#include <string>


class Harl {
    private:
        enum e_log_level {
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            NO_LOG
        };

        enum e_log_level m_log_level;

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

        void set_loglevel(std::string level);
        void yap() const;
};

#endif  // HARL_HPP
