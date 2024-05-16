#pragma once

#include <map>
#include <string>

namespace iostreams
{
    class IOStreams
    {
    private:
        enum m_iostreamsMenu
        {
            MIN_COUNT                        = 0,
            SHOWCASE_STREAMS                 = 1,
            SHOWCASE_WRITING_TO_A_FILE       = 2,
            SHOWCASE_READING_FROM_A_FILE     = 3,
            SHOWCASE_SERIALIZATION           = 4,
            SHOWCASE_BINARY_FILES_OPERATIONS = 5,
            BACK_TO_PREVIOUS_MENU            = 6,
            EXIT_FROM_PROGRAM                = 7,
            MAX_COUNT                        = EXIT_FROM_PROGRAM
        };
        int                        m_choice{ 0 };
        std::map<int, std::string> m_iostreamsMenuMap{};

    public:
        IOStreams();
        const int  GetMinCase();
        const int  GetMaxCase();
        const int& GetChoice();
        void       GetChoiceInputFromUser();
        void       PrintMenu();
        void       PrintSelectedChoice();
        void       ShowCaseStreams();
        void       ShowCaseWritingToAFile();
        void       ShowCaseReadingFromAFile();
        void       ShowCaseSerialization();
        void       ShowCaseBinaryFilesOperations();
    };
} // namespace iostreams
