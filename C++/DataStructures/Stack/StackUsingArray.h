#pragma once

#include <map>
#include <string>
#include <optional>
#include <iostream>

namespace stack
{
    template <class T>
    class StackUsingArray
    {
    private:
        enum m_StackUsingArrayMenu
        {
            MIN_COUNT             = 0,
            IS_EMPTY              = 1,
            IS_FULL               = 2,
            DISPLAY               = 3,
            PUSH                  = 4,
            POP                   = 5,
            PEEK                  = 6,
            GET_TOP               = 7,
            BACK_TO_PREVIOUS_MENU = 8,
            EXIT_FROM_PROGRAM     = 9,
            MAX_COUNT             = EXIT_FROM_PROGRAM
        };
        int                        m_choice                 { 0 };
        std::map<int, std::string> m_stackUsingArrayMenuMap {};
        int                        m_top                    { -1 };
        int                        m_size                   { 0 };
        T*                         m_data                   { nullptr };

    public:
        StackUsingArray(int);
        ~StackUsingArray();
        const int        GetMinCase();
        const int        GetMaxCase();
        const int&       GetChoice();
        void             GetChoiceInputFromUser();
        void	         PrintMenu();
        void             PrintSelectedChoice();
        bool             IsEmpty();
        bool             IsFull();
        std::optional<T> GetTop();
        bool             Push(T);
        std::optional<T> Pop();
        std::optional<T> Peek(int);
        void             Display();
    };
} // namespace stack

# include "StackUsingArray.tpp"
