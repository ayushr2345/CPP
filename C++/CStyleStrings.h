#pragma once

#include <map>
#include <string>
#include <cstring>

namespace cStyleStrings
{
    class CStyleStrings
    {
    private:
        enum m_CStyleStringsMenu
        {
            MIN_COUNT                               = 0,
            SHOW_CASE_C_STYLE_STRINGS               = 1,
            GET_STRING                              = 2,
            GET_STRING_LENGTH                       = 3,
            SET_STRING_TO_POINTER                   = 4,
            GET_STRING_POINTER                      = 5,
            GET_STRING_POINTER_LENGTH               = 6,
            IS_STRING_POINTER_EMPTY                 = 7,
            COMPARE_STRING_TO_STRING_POINTER        = 8,
            CONCATENATE_STRING_AND_STRING_POINTER   = 9,
            N_CONCATENATE_STRING_AND_STRING_POINTER = 10,
            SHOW_CASE_STRING_TO_LONG                = 11,
            SHOW_CASE_STRING_TO_FLOAT               = 12,
            SHOW_CASE_STRING_TO_TOKEN               = 13,
            BACK_TO_PREVIOUS_MENU                   = 14,
            EXIT_FROM_PROGRAM                       = 15,
            MAX_COUNT                               = EXIT_FROM_PROGRAM
        };
        int                        m_choice { 0 };
        char                       m_string[20] { "" };
        char*                      m_stringPtr { nullptr };
        std::map<int, std::string> m_CStyleStringsMap{};

    public:
        CStyleStrings(const char[]);
        ~CStyleStrings();
        const int&   GetMinCase();
        const int&   GetMaxCase();
        const int&   GetChoice();
        void         GetChoiceInputFromUser();
        void         PrintMenu();
        void         PrintSelectedChoice();
        void         ShowcaseCStyleStrings();
        const char*  GetString();
        const size_t GetStringLength();
        void         SetStringPointer(const int&);
        const char*  GetStringPointer();
        const size_t GetStringPointerLength();
        const bool   IsStringPointerEmpty();
        const int&   CompareStringWithStringPointer();
        void         ConcatenateStringAndStringPointer(char[], const int&);
        void         NConcatenateStringAndStringPointer(char[], const int&, const int&);
        void         ShowcaseStringToLong();
        void         ShowcaseStringToFloat();
        void         ShowcaseStringToToken();
    };
} // namespace cstylestrings
