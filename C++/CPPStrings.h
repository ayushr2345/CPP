#pragma once

#include <map>
#include <string>

namespace cppStrings
{
    class CPPStrings
    {
    private:
        enum m_CPPStyleStringsMenu
        {
            MIN_COUNT                               = 0,
            SHOW_CASE_CPP_STYLE_STRINGS             = 1,
            GET_STRING                              = 2,
            GET_STRING_LENGTH                       = 3,
            GET_STRING_CAPACITY                     = 4,
            SET_STRING_TO_POINTER                   = 5,
            GET_STRING_POINTER                      = 6,
            GET_STRING_POINTER_LENGTH               = 7,
            IS_STRING_POINTER_EMPTY                 = 8,
            COMPARE_STRING_TO_STRING_POINTER        = 9,
            CONCATENATE_STRING_AND_STRING_POINTER   = 10,
            N_CONCATENATE_STRING_AND_STRING_POINTER = 11,
            SHOW_CASE_STRING_TO_INT                 = 12,
            SHOW_CASE_STRING_TO_LONG                = 13,
            SHOW_CASE_STRING_TO_FLOAT               = 14,
            BACK_TO_PREVIOUS_MENU                   = 15,
            EXIT_FROM_PROGRAM                       = 16,
            MAX_COUNT                               = EXIT_FROM_PROGRAM
        };
        int                        m_choice { 0 };
        std::string                m_string { "" };
        std::string*               m_stringPtr { nullptr };
        std::map<int, std::string> m_CPPStyleStringsMap{};

    public:
        CPPStrings(const std::string&);
        ~CPPStrings();
        const int&         GetMinCase();
        const int&         GetMaxCase();
        const int&         GetChoice();
        void               GetChoiceInputFromUser();
        void               PrintMenu();
        void               PrintSelectedChoice();
        void               ShowcaseCPPStyleStrings();
        const std::string& GetString();
        const size_t       GetStringLength();
        const size_t       GetStringCapacity();
        void               SetStringPointer();
        const std::string  GetStringPointer();
        const size_t       GetStringPointerLength();
        const bool         IsStringPointerEmpty();
        const int&         CompareStringWithStringPointer();
        void               ConcatenateStringAndStringPointer(std::string&);
        void               NConcatenateStringAndStringPointer(std::string&, const int&);
        void               ShowcaseStringToInt();
        void               ShowcaseStringToLong();
        void               ShowcaseStringToFloat();
    };
} // namespace cppStrings
