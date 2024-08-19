#include <iostream>
#include <functional>
#include "Strings.h"
#include "../../utils.h"

namespace strings
{
    Strings::Strings():
        m_choice         ( 0 ),
        m_stringsMenuMap ( {   } ),
        m_size_A         ( 0 ),
        m_size_B         ( 0 ),
        m_string_A       ( { 0 } ),
        m_string_B       ( { 0 } )
    {
        m_stringsMenuMap.insert({ m_StringsMenu(PRINT_ALL_ASCII_CHARACTERS),
                                  std::string("Print all the ASCII characters") });
        m_stringsMenuMap.insert({ m_StringsMenu(SHOWCASE_CHAR_ARRAY_VS_STRING),
                                  std::string("Showcase Character Array vs Strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(DISPLAY),
                                  std::string("Display the strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(TAKE_INPUT),
                                  std::string("Take input to the strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(FIND_LENGTH_OF_STRING),
                                  std::string("Find length of the strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(CHANGE_CASE_TO_UPPER),
                                  std::string("Change case to upper for the strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(CHANGE_CASE_TO_LOWER),
                                  std::string("Change case to lower for the strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(TOGGLE_CASE),
                                  std::string("Toggle case of the strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(COUNT_WORDS_IN_SENTENCE),
                                  std::string("Count the words in the sentence") });
        m_stringsMenuMap.insert({ m_StringsMenu(COUNT_LETTERS_IN_SENTENCE),
                                  std::string("Count letters in the sentence") });
        m_stringsMenuMap.insert({ m_StringsMenu(COUNT_VOWELS_AND_CONSONANTS),
                                  std::string("Count vowels and consonants in the sentence") });
        m_stringsMenuMap.insert({ m_StringsMenu(VALIDATE_STRING_FOR_ONLY_ALPHABETS),
                                  std::string("Validate the strings for only alphabets") });
        m_stringsMenuMap.insert({ m_StringsMenu(VALIDATE_STRING_FOR_ONLY_NUMERIC),
                                  std::string("Validate the strings for only numeric") });
        m_stringsMenuMap.insert({ m_StringsMenu(VALIDATE_STRING_FOR_ALPHANUMERIC),
                                  std::string("Validate the strings for alphanumeric") });
        m_stringsMenuMap.insert({ m_StringsMenu(VALIDATE_STRING_FOR_ONLY_CHARACTERS),
                                  std::string("Validate the strings for special characters") });
        m_stringsMenuMap.insert({ m_StringsMenu(REVERSE_THE_STRING),
                                  std::string("Reverse the strings") });
        m_stringsMenuMap.insert({ m_StringsMenu(COMPARE_TWO_STRINGS_MATCH_CASE),
                                  std::string("Compare the strings (match case)") });
        m_stringsMenuMap.insert({ m_StringsMenu(COMPARE_TWO_STRINGS_IGNORE_CASE),
                                  std::string("Compare the strings (ignore case)") });
        m_stringsMenuMap.insert({ m_StringsMenu(CHECK_IF_STRING_IS_PALINDROME),
                                  std::string("Check if the string is palindrome") });
        m_stringsMenuMap.insert({ m_StringsMenu(FIND_DUPLICATES_IN_STRING_N2),
                                  std::string("Find duplicates in the string using N2 way") });
        m_stringsMenuMap.insert({ m_StringsMenu(FIND_DUPLICATES_IN_STRING_HASH_TABLE),
                                  std::string("Find duplicates in the string using hash table") });
        m_stringsMenuMap.insert({ m_StringsMenu(FIND_DUPLICATES_IN_STRING_BITWISE),
                                  std::string("Find duplicates in the string using bitwise") });
        m_stringsMenuMap.insert({ m_StringsMenu(CHECK_FOR_ANAGRAM),
                                  std::string("Check if the strings are anagrams") });
        m_stringsMenuMap.insert({ m_StringsMenu(PERMUTATIONS_OF_STRING_BRUTE_FORCE),
                                  std::string("Permutations of the string using brute force") });
        m_stringsMenuMap.insert({ m_StringsMenu(BACK_TO_PREVIOUS_MENU),
                                  std::string("Back to Previous Menu") });
        m_stringsMenuMap.insert({ m_StringsMenu(EXIT_FROM_PROGRAM),
                                  std::string("Exit from program") });
    }

    const int Strings::GetMinCase()
    {
        return m_StringsMenu::MIN_COUNT;
    }

    const int Strings::GetMaxCase()
    {
        return m_StringsMenu::MAX_COUNT;
    }

    const int& Strings::GetChoice()
    {
        return m_choice;
    }

    void Strings::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, static_cast<int>(m_StringsMenu::MAX_COUNT));
    }

    void Strings::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_stringsMenuMap.begin();
            it != m_stringsMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void Strings::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_stringsMenuMap.at(m_choice)
                  << std::endl;
    }

    void Strings::PrintAllASCIICharacters()
    {
        std::cout << "American Standard Code for Information Interchange (ASCII) characters are supported by every OS"
                  << ". This has 128 characters ranging from 0 to 128"
                  << std::endl;
        
        for (int i = 0; i < 128; i++)
        {
            std::cout << i << " --> " << static_cast<char>(i) << std::endl;
        }
    }

    void Strings::ShowcaseCharArrayVsStrings()
    {
        std::cout << "There's a difference between a character array and a string. A string is stores in a character array and is terminated"
                  << " by a string delimeter ('\\0')" << std::endl
                  << "char arr[5] = [1, 2, 3, 4, 5]; is a character array" << std::endl
                  << "char arr[] = {'a', 'y', 'u', 's', 'h', '\\0'}; is a string" << std::endl
                  << "We can print a string with cout and printf directly but not print a character array with cout or printf directly"
                  << std::endl;
    }

    void Strings::Display()
    {
        std::cout << "String A: " << m_string_A << std::endl;
        std::cout << "String B: " << m_string_B << std::endl;
    }

    void Strings::TakeInput()
    {
        std::cout << "Do you want to input a word or a sentence: " << std::endl;
        std::cout << "    1. Word" << std::endl
                  << "    2. Sentence" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            utils::IgnoreStdCinBufferTillEOL();
            std::cout << "Please enter the word to input in string A: ";
            // std::cin.getline(m_string_A, 20);
            std::cin >> m_string_A;
            bool resA = utils::CheckAndClearCharactersInStream(m_string_A, 20);
            if (resA)
            {
                std::cout << "You have entered a word greater than 19 characters. Only 19 characters will be taken input" << std::endl;
            }

            utils::IgnoreStdCinBufferTillEOL();
            std::cout << "Please enter the sentence to input in string B: ";
            // std::cin.getline(m_string_B, 20);
            std::cin >>m_string_B;
            bool resB = utils::CheckAndClearCharactersInStream(m_string_B, 20);
            if (resB)
            {
                std::cout << "You have entered a word greater than 19 characters. Only 19 characters will be taken input" << std::endl;
            }
            FindLenghOfString();
        }
        else if (choice == 2)
        {
            utils::IgnoreStdCinBufferTillEOL();
            std::cout << "Please enter the sentence to input in string A: ";
            std::cin.getline(m_string_A, 20);
            bool resA = utils::CheckAndClearCharactersInStream(m_string_A, 20);
            if (resA)
            {
                std::cout << "You have entered a sentence greater than 19 characters. Only 19 characters will be taken input" << std::endl;
            }

            utils::IgnoreStdCinBufferTillEOL();
            std::cout << "Please enter the sentence to input in string B: ";
            std::cin.getline(m_string_B, 20);
            bool resB = utils::CheckAndClearCharactersInStream(m_string_B, 20);
            if (resB)
            {
                std::cout << "You have entered a sentence greater than 19 characters. Only 19 characters will be taken input" << std::endl;
            }
            FindLenghOfString();
        }
        else
        {
            std::cout << "Wrong choice entered, exiting" << std::endl;
            return;
        }
    }

    void Strings::FindLenghOfString()
    {
        int i = 0;
        for (i; m_string_A[i] != '\0'; i++)
        {}
        std::cout << "The length of string A is: " << i << std::endl;
        m_size_A = i;

        int j = 0;
        for (j; m_string_B[j] != '\0'; j++)
        {}
        m_size_B = j;
        std::cout << "The length of string B is: " << j << std::endl;
    }

    void Strings::ChangeCaseToUpper()
    {
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (m_string_A[i] >= 97 and m_string_A[i] <= 122)
            {
                m_string_A[i] -= 32;
            }
        }

        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (m_string_B[i] >= 97 and m_string_B[i] <= 122)
            {
                m_string_B[i] -= 32;
            }
        }
        Display();
    }

    void Strings::ChangeCaseToLower()
    {
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (m_string_A[i] >= 65 and m_string_A[i] <= 90)
            {
                m_string_A[i] += 32;
            }
        }

        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (m_string_B[i] >= 65 and m_string_B[i] <= 90)
            {
                m_string_B[i] += 32;
            }
        }
        Display();
    }

    void Strings::ToggleCase()
    {
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (m_string_A[i] >= 65 and m_string_A[i] <= 90)
            {
                m_string_A[i] += 32;
            }

            if (m_string_A[i] >= 97 and m_string_A[i] <= 122)
            {
                m_string_A[i] -= 32;
            }
        }

        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (m_string_B[i] >= 65 and m_string_B[i] <= 90)
            {
                m_string_B[i] += 32;
            }

            if (m_string_B[i] >= 97 and m_string_B[i] <= 122)
            {
                m_string_B[i] -= 32;
            }
        }

        Display();
    }

    void Strings::CountWordsInASentence()
    {
        int spacesA = 0;
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (m_string_A[i] == ' ' and m_string_A[i] != ' ')
            {
                spacesA++;
            }
        }

        int spacesB = 0;
        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (m_string_B[i] == ' ' and m_string_B[i - 1] != ' ')
            {
                spacesB++;
            }
        }
        Display();
        std::cout << "The number of words in string A is: " << spacesA + 1 << std::endl;
        std::cout << "The number of words in string B is: " << spacesB + 1 << std::endl;
    }

    void Strings::CountLettersInASentence()
    {
        int lettersA = 0;
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (m_string_A[i] != ' ')
            {
                lettersA++;
            }
        }

        int lettersB = 0;
        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (m_string_B[i] != ' ')
            {
                lettersB++;
            }
        }
        Display();
        std::cout << "The number of letters in string A is: " << lettersA << std::endl;
        std::cout << "The number of letters in string B is: " << lettersB << std::endl;
    }

    void Strings::CountVowelsAndConsonantsInTheSentence()
    {
        int vowelsA = 0;
        int consonantsA = 0;
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (m_string_A[i] == 'a' or
                m_string_A[i] == 'e' or
                m_string_A[i] == 'i' or
                m_string_A[i] == 'o' or
                m_string_A[i] == 'u' or
                m_string_A[i] == 'A' or
                m_string_A[i] == 'E' or
                m_string_A[i] == 'I' or
                m_string_A[i] == 'O' or
                m_string_A[i] == 'U')
            {
                vowelsA++;
            }
            else
            {
                consonantsA++;
            }
        }

        int vowelsB = 0;
        int consonantsB = 0;
        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (m_string_B[i] == 'a' or
                m_string_B[i] == 'e' or
                m_string_B[i] == 'i' or
                m_string_B[i] == 'o' or
                m_string_B[i] == 'u' or
                m_string_B[i] == 'A' or
                m_string_B[i] == 'E' or
                m_string_B[i] == 'I' or
                m_string_B[i] == 'O' or
                m_string_B[i] == 'U')
            {
                vowelsB++;
            }
            else
            {
                consonantsB++;
            }
        }
        Display();
        std::cout << "The number vowels and consonants in string A are: " << vowelsA << " " << consonantsA << " respectively." << std::endl; 
        std::cout << "The number vowels and consonants in string B are: " << vowelsB << " " << consonantsB << " respectively." << std::endl; 
    }

    void Strings::ValidateStringForOnlyAlphabets()
    {
        int flagA = 0;
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (not ((m_string_A[i] >= 65 and m_string_A[i] <= 90) or (m_string_A[i] >= 97 and m_string_A[i] <= 122)))
            {
                flagA = 1;
                break;
            }
        }

        int flagB = 0;
        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (not ((m_string_A[i] >= 65 and m_string_A[i] <= 90) or (m_string_A[i] >= 97 and m_string_A[i] <= 122)))
            {
                flagB = 1;
                break;
            }
        }

        if (not flagA)
        {
            std::cout << "String A only has alphabets" << std::endl;
        }
        else
        {
            std::cout << "String A doesn't only have alphabets" << std::endl;
        }
        
        if (not flagB)
        {
            std::cout << "String B only has alphabets" << std::endl;
        }
        else
        {
            std::cout << "String B doesn't only have alphabets" << std::endl;
        }
        Display();
    }

    void Strings::ValidateStringForOnlyNumeric()
    {
        int flagA = 0;
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (not (m_string_A[i] >= 48 and m_string_A[i] <= 57))
            {
                flagA = 1;
                break;
            }
        }

        int flagB = 0;
        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (not (m_string_B[i] >= 48 and m_string_B[i] <= 57))
            {
                flagB = 1;
                break;
            }
        }

        if (not flagA)
        {
            std::cout << "String A only has numbers" << std::endl;
        }
        else
        {
            std::cout << "String A doesn't only have numbers" << std::endl;
        }
        
        if (not flagB)
        {
            std::cout << "String B only has numbers" << std::endl;
        }
        else
        {
            std::cout << "String B doesn't only have numbers" << std::endl;
        }
    }

    void Strings::ValidateStringForAlphanumeric()
    {
        int flagA = 0;
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (not ((m_string_A[i] >= 48 and 
                      m_string_A[i] <= 57 ) or
                     (m_string_A[i] >= 65 and
                      m_string_A[i] <= 90 ) or
                     (m_string_A[i] >= 97 and
                      m_string_A[i] <= 122)))
            {
                flagA = 1;
                break;
            }
        }

        int flagB = 0;
        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (not ((m_string_A[i] >= 48 and 
                      m_string_A[i] <= 57 ) or
                     (m_string_A[i] >= 65 and
                      m_string_A[i] <= 90 ) or
                     (m_string_A[i] >= 97 and
                      m_string_A[i] <= 122)))
            {
                flagB = 1;
                break;
            }
        }

        if (not flagA)
        {
            std::cout << "String A only has alphanumeric" << std::endl;
        }
        else
        {
            std::cout << "String A doesn't only have alphanumeric" << std::endl;
        }
        
        if (not flagB)
        {
            std::cout << "String B only has alphanumeric" << std::endl;
        }
        else
        {
            std::cout << "String B doesn't only have alphanumeric" << std::endl;
        }
    }

    void Strings::ValidateStringForOnlyCharacters()
    {
        int flagA = 0;
        for (int i = 0; m_string_A[i] != '\0'; i++)
        {
            if (m_string_A[i] >= 48 and 
                m_string_A[i] <= 57  and
                m_string_A[i] >= 65 and
                m_string_A[i] <= 90 and
                m_string_A[i] >= 97 and
                m_string_A[i] <= 122)
            {
                flagA = 1;
                break;
            }
        }

        int flagB = 0;
        for (int i = 0; m_string_B[i] != '\0'; i++)
        {
            if (m_string_B[i] >= 48 and 
                m_string_B[i] <= 57  and
                m_string_B[i] >= 65 and
                m_string_B[i] <= 90 and
                m_string_B[i] >= 97 and
                m_string_B[i] <= 122)
            {
                flagB = 1;
                break;
            }
        }

        if (not flagA)
        {
            std::cout << "String A does not have any character" << std::endl;
        }
        else
        {
            std::cout << "String A has a few characters" << std::endl;
        }
        
        if (not flagB)
        {
            std::cout << "String B does not have any character" << std::endl;
        }
        else
        {
            std::cout << "String B has a few characters" << std::endl;
        }
    }

    void Strings::ReverseTheString()
    {
        for (int i = 0, j = m_size_A - 1; i <= j; i++, j--)
        {
            char temp = m_string_A[i];
            m_string_A[i] = m_string_A[j];
            m_string_A[j] = temp;
        }

        for (int i = 0, j = m_size_B - 1; i <= j; i++, j--)
        {
            char temp = m_string_B[i];
            m_string_B[i] = m_string_B[j];
            m_string_B[j] = temp;
        }

        Display();
    }

    void Strings::CompareTheStringsMatchCase()
    {
        if (m_size_A == m_size_B)
        {
            for (int i = 0; i < m_size_A; i++)
            {
                if (not (m_string_A[i] == m_string_B[i]))
                {
                    std::cout << "The strings are not the same (match case)" << std::endl;
                    return;
                }
            }
            std::cout << "The two strings are the same (match case)" << std::endl;
        }
        else
        {
            std::cout << "The two strings are not the same (match case)" << std::endl;
        }
    }

    void Strings::CompareTheStringsIgnoreCase()
    {
        if (m_size_A == m_size_B)
        {
            for (int i = 0; i < m_size_A; i++)
            {
                if (not ((m_string_A[i] == m_string_B[i]) or
                         (m_string_A[i] - 32 == m_string_B[i]) or
                         (m_string_A[i] + 32 == m_string_B[i])))
                {
                    std::cout << "The strings are not the same (ignore case)" << std::endl;
                    return;
                }
            }
            std::cout << "The two strings are the same (ignore case)" << std::endl;
        }
        else
        {
            std::cout << "The two strings are not the same (ignore case)" << std::endl;
        }
    }

    void Strings::CheckIfStringIsPalindrome()
    {
        int flagA = 0;
        for (int i = 0, j = m_size_A - 1; i <= j; i++, j--)
        {
            if (not (m_string_A[i] == m_string_A[j]))
            {
                flagA = 1;
                break;
            }
        }

        int flagB = 0;
        for (int i = 0, j = m_size_B - 1; i <= j; i++, j--)
        {
            if (not (m_string_B[i] == m_string_B[j]))
            {
                flagB = 1;
                break;
            }
        }

        if (not flagA)
        {
            std::cout << "String A is a palindrome" << std::endl;
        }
        else
        {
            std::cout << "String A is not a palindrome" << std::endl;
        }

        if (not flagB)
        {
            std::cout << "String B is a palindrome" << std::endl;
        }
        else
        {
            std::cout << "String B is not a palindrome" << std::endl;
        }
    }

    void Strings::FindDuplicatesInStringN2()
    {
        int duplicateNumber = 0;
        for (int i = 0; i < m_size_A; i++)
        {
            duplicateNumber = 0;
            for (int j = i; j < m_size_A; j++)
            {
                if (m_string_A[i] == m_string_A[j])
                {
                    duplicateNumber++;
                }
            }
            std::cout << "In string A, character: " << m_string_A[i] << " has " << duplicateNumber << " duplicates" << std::endl;
        }

        for (int i = 0; i < m_size_B; i++)
        {
            duplicateNumber = 0;
            for (int j = i; j < m_size_B; j++)
            {
                if (m_string_B[i] == m_string_B[j])
                {
                    duplicateNumber++;
                }
            }
            std::cout << "In string B, character: " << m_string_A[i] << " has " << duplicateNumber << " duplicates" << std::endl;
        }
    }

    void Strings::FindDuplicatesInStringHashTable()
    {
        int hashTable[128] = { 0 };
        for (int i = 0; i < m_size_A; i++)
        {
            hashTable[m_string_A[i]]++;
        }

        for (int i = 0; i < 128; i++)
        {
            if (hashTable[i] != 0)
            {
                std::cout << "For string A, the number of duplicates for the character "
                          << static_cast<char>(i) << " are " << hashTable[i] << std::endl;
                hashTable[i] = 0;
            }
        }

        for (int i = 0; i < m_size_B; i++)
        {
            hashTable[m_string_B[i]]++;
        }

        for (int i = 0; i < 128; i++)
        {
            if (hashTable[i] != 0)
            {
                std::cout << "For string B, the number of duplicates for the character "
                          << static_cast<char>(i) << " are " << hashTable[i] << std::endl;
                hashTable[i] = 0;
            }
        }
    }

    void Strings::FindDuplicatesInStringBitwise()
    {
        std::cout << "This doesn't care about cases of the alphabets" << std::endl;

        int flagA = 0;
        int H = 0;
        int x = 0;
        for (int i = 0; i < m_size_A; i++)
        {
            x = 1;
            if (m_string_A[i] >= 65 and m_string_A[i] <= 90)
            {
                x = x << (static_cast<int>(m_string_A[i]) - 65);
            }
            else if (m_string_A[i] >= 90 and m_string_A[i] <= 122)
            {
                x = x << (m_string_A[i] - 97);
            }

            if ((x & H) > 0)
            {
                flagA = 1;
                std::cout << "In string A duplicate found for charcter " << m_string_A[i] << std::endl;
            }
            else
            {
                H = x | H;
            }
        }

        int flagB = 0;
        H = 0;
        x = 0;
        for (int i = 0; i < m_size_B; i++)
        {
            x = 1;
            if (m_string_B[i] >= 65 and m_string_B[i] <= 90)
            {
                x = x << (static_cast<int>(m_string_B[i]) - 65);
            }
            else if (m_string_B[i] >= 90 and m_string_B[i] <= 122)
            {
                x = x << (m_string_B[i] - 97);
            }

            if ((x & H) > 0)
            {
                flagB = 1;
                std::cout << "In string B duplicate found for charcter " << m_string_B[i] << std::endl;
            }
            else
            {
                H = x | H;
            }
        }

        if (not flagA)
        {
            std::cout << "There is no duplicate found in string A" << std::endl;
        }

        if (not flagB)
        {
            std::cout << "There is no duplicate found in string B" << std::endl;
        }
    }

    void Strings::CheckForAnagram()
    {
        if (not (m_size_A == m_size_B))
        {
            std::cout << "The strings are not anagrams as they are not of same length" << std::endl;
        }
        else
        {
            int H[26] = { 0 };
            for (int i = 0; i < m_size_A; i++)
            {
                if (m_string_A[i] >= 65 and m_string_A[i] <= 90)
                {
                    H[m_string_A[i] -  65]++;
                }
                else if (m_string_A[i] >= 97 and m_string_A[i] <= 122)
                {
                    H[m_string_A[i] -  97]++;
                }
            }

            for (int i = 0; i < m_size_B; i++)
            {
                if (m_string_B[i] >= 65 and m_string_B[i] <= 90)
                {
                    H[m_string_B[i] -  65]--;
                }
                else if (m_string_B[i] >= 97 and m_string_B[i] <= 122)
                {
                    H[m_string_B[i] -  97]--;
                }
            }

            for (int i = 0; i < 26; i++)
            {
                if (not H[i] == 0)
                {
                    std::cout << "The strings are not anagrams" << std::endl;
                    return;
                }
            }

            std::cout << "The strings are anagramns" << std::endl;
        }
    }

    void Strings::PermutationsOfStringBruteForce()
    {
        std::function<void(char[], int)> permutation = [&permutation](char S[], int k) {
        static int A[4] = {0};  // You may want to use a dynamically sized array if S has a different size
        static char Res[4];     // Same here

        if (S[k] == '\0') {  // Base case: when we've filled the result array
            Res[k] = '\0';   // Null-terminate the result string
            std::cout << Res << std::endl;
        } else {
            for (int i = 0; S[i] != '\0'; i++) {  // Loop through all characters of the input string
                if (A[i] == 0) {  // Check if the character is already used
                    Res[k] = S[i];  // Place character in the result array
                    A[i] = 1;       // Mark character as used
                    permutation(S, k + 1);  // Recurse with next position
                    A[i] = 0;       // Backtrack: Unmark character as used
                }
            }
        }
    };

    char arr[4] = "abc";
    permutation(arr, 0);  // Start with the first character (index 0)
    }
} // namespace strings
