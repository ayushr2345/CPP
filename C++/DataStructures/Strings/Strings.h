#pragma once

#include <map>
#include <string>

namespace strings
{
    class Strings
    {
    private:
        enum m_StringsMenu
        {
            MIN_COUNT                            = 0,
            PRINT_ALL_ASCII_CHARACTERS           = 1,
            SHOWCASE_CHAR_ARRAY_VS_STRING        = 2,
            DISPLAY                              = 3,
            TAKE_INPUT                           = 4,
            FIND_LENGTH_OF_STRING                = 5,
            CHANGE_CASE_TO_UPPER                 = 6,
            CHANGE_CASE_TO_LOWER                 = 7,
            TOGGLE_CASE                          = 8,
            COUNT_WORDS_IN_SENTENCE              = 9,
            COUNT_LETTERS_IN_SENTENCE            = 10,
            COUNT_VOWELS_AND_CONSONANTS          = 11,
            VALIDATE_STRING_FOR_ONLY_ALPHABETS   = 12,
            VALIDATE_STRING_FOR_ONLY_NUMERIC     = 13,
            VALIDATE_STRING_FOR_ALPHANUMERIC     = 14,
            VALIDATE_STRING_FOR_ONLY_CHARACTERS  = 15,
            REVERSE_THE_STRING                   = 16,
            COMPARE_TWO_STRINGS_MATCH_CASE       = 17,
            COMPARE_TWO_STRINGS_IGNORE_CASE      = 18,
            CHECK_IF_STRING_IS_PALINDROME        = 19,
            FIND_DUPLICATES_IN_STRING_N2         = 20,
            FIND_DUPLICATES_IN_STRING_HASH_TABLE = 21,
            FIND_DUPLICATES_IN_STRING_BITWISE    = 22,
            CHECK_FOR_ANAGRAM                    = 23,
            PERMUTATIONS_OF_STRING_BRUTE_FORCE   = 24,
            BACK_TO_PREVIOUS_MENU                = 25,
            EXIT_FROM_PROGRAM                    = 26,
            MAX_COUNT                            = EXIT_FROM_PROGRAM
        };
        int                        m_choice         { 0 };
        std::map<int, std::string> m_stringsMenuMap {   };
        int                        m_size_A         { 0 };
        int                        m_size_B         { 0 };
        char                       m_string_A[10]   { 0 };
        char                       m_string_B[10]   { 0 };

    public:
        Strings();
        const int  GetMinCase();
        const int  GetMaxCase();
        const int& GetChoice();
        void       GetChoiceInputFromUser();
        void	   PrintMenu();
        void       PrintSelectedChoice();
        void       PrintAllASCIICharacters();
        void       ShowcaseCharArrayVsStrings();
        void       Display();
        void       TakeInput();
        void       FindLenghOfString();
        void       ChangeCaseToUpper();
        void       ChangeCaseToLower();
        void       ToggleCase();
        void       CountWordsInASentence();
        void       CountLettersInASentence();
        void       CountVowelsAndConsonantsInTheSentence();
        void       ValidateStringForOnlyAlphabets();
        void       ValidateStringForOnlyNumeric();
        void       ValidateStringForAlphanumeric();
        void       ValidateStringForOnlyCharacters();
        void       ReverseTheString();
        void       CompareTheStringsMatchCase();
        void       CompareTheStringsIgnoreCase();
        void       CheckIfStringIsPalindrome();
        void       FindDuplicatesInStringN2();
        void       FindDuplicatesInStringHashTable();
        void       FindDuplicatesInStringBitwise();
        void       CheckForAnagram();
        void       PermutationsOfStringBruteForce();
    };
} // namespace strings
