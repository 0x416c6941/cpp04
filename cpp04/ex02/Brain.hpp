#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstddef>
#include <string>

class Brain {
    private:
        static const std::size_t m_IDEAS_SIZE = 100;
        std::string m_ideas[m_IDEAS_SIZE];
        std::size_t m_ideas_cnt;

    public:
        Brain();
        Brain(const Brain & src);
        Brain & operator = (const Brain & src);
        virtual ~Brain();

        std::size_t get_max_ideas_cnt() const;
        std::size_t get_ideas_cnt() const;
        /**
         * @throws  domain_error    If tried to access idea
         *                          with index \p idx,
         *                          which isn't present in Brain.
         */
        const std::string & get_idea(size_t idx) const;
        void add_idea(const std::string & idea);
};

#endif  // BRAIN_HPP
