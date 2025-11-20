#include "handlers.h"
#include <iostream>
#include <string>

namespace
{
    enum class SubmenuResult
    {
        BACK,
        CONTINUE,
        EXIT
    };

    SubmenuResult RunLanguageMenu()
    {
        constexpr std::size_t kCStyleMax = 20;

        utils::PrintMenu(utils::LanguageMenuMap);
        int langChoice{ 0 };
        utils::InputNumberFromUser(langChoice, 1, static_cast<int>(utils::LanguageMenu::MAX_COUNT));

        while (langChoice)
        {
            if (langChoice > static_cast<int>(utils::LanguageMenu::MIN_COUNT) &&
                langChoice < static_cast<int>(utils::LanguageMenu::MAX_COUNT) + 1)
            {
                utils::PrintSelectedChoice(langChoice, utils::LanguageMenuMap);
            }

            switch (langChoice)
            {
            case 1:
            {
                basics::Basics basicObj;
                handlers::Handle(basicObj);
                break;
            }
            case 2:
            {
                int num{ 0 };
                std::cout << "Please enter a number to get started with Pointers and References: ";
                utils::InputNumberFromUser(num);
                pointersAndReferences::PointersAndReferences obj(num);
                handlers::Handle(obj);
                break;
            }
            case 3:
            {
                utils::IgnoreStdCinBufferTillEOL();
                std::cout << "Please enter a name to get started with C Style Strings: ";
                char str[kCStyleMax];
                std::cin.getline(str, kCStyleMax);
                bool truncated = utils::CheckAndClearCharactersInStream(str, static_cast<int>(kCStyleMax));
                if (truncated)
                {
                    std::cout << "You have entered a name greater than " << (kCStyleMax - 1)
                        << " characters. Only " << (kCStyleMax - 1) << " characters were taken." << std::endl;
                }
                cStyleStrings::CStyleStrings obj(str);
                handlers::Handle(obj);
                break;
            }
            case 4:
            {
                utils::IgnoreStdCinBufferTillEOL();
                std::cout << "Please enter a name to get started with CPP Style Strings: ";
                std::string s;
                std::getline(std::cin, s);
                cppStrings::CPPStrings obj(s);
                handlers::Handle(obj);
                break;
            }
            case 5:
            {
                functions::Functions obj;
                handlers::Handle(obj);
                break;
            }
            case 6:
            {
                classesAndObjects::ClassesAndObjects obj;
                handlers::Handle(obj);
                break;
            }
            case 7:
            {
                iostreams::IOStreams obj;
                handlers::Handle(obj);
                break;
            }
            case 8:
            {
                return SubmenuResult::BACK;
            }
            case 9:
            {
                return SubmenuResult::EXIT;
            }
            default:
            {
                std::cout << "The selected option is out of bounds. Please select an appropriate option." << std::endl;
                break;
            }
            }

            utils::PrintMenu(utils::LanguageMenuMap);
            utils::InputNumberFromUser(langChoice, 1, static_cast<int>(utils::LanguageMenu::MAX_COUNT));
        }

        return SubmenuResult::CONTINUE;
    }

    SubmenuResult RunDataStructuresMenu()
    {
        utils::PrintMenu(utils::DataStructuresMenuMap);
        int dsChoice{ 0 };
        utils::InputNumberFromUser(dsChoice, 1, static_cast<int>(utils::DataStructuresMenu::MAX_COUNT));

        while (dsChoice)
        {
            if (dsChoice > static_cast<int>(utils::DataStructuresMenu::MIN_COUNT) &&
                dsChoice < static_cast<int>(utils::DataStructuresMenu::MAX_COUNT) + 1)
            {
                utils::PrintSelectedChoice(dsChoice, utils::DataStructuresMenuMap);
            }

            switch (dsChoice)
            {
            case 1:
            {
                recursions::Recursions obj;
                handlers::Handle(obj);
                break;
            }
            case 2:
            {
                std::cout << "Enter the length of the array: ";
                int length = 0;
                utils::InputNumberFromUser(length, 0, 15);

                arrayAdt::ArrayADT<int> arrayAdtObj(length);
                for (int i = 0; i < length; ++i)
                {
                    arrayAdtObj.Insert(arrayAdtObj.GetSize(), i + 1);
                }
                handlers::Handle(arrayAdtObj);
                break;
            }
            case 3:
            {
                strings::Strings obj;
                handlers::Handle(obj);
                break;
            }
            case 4:
            {
                matrices::MatricesMain obj;
                handlers::Handle(obj);
                break;
            }
            case 5:
            {
                linkedList::LinkedListMain obj;
                handlers::Handle(obj);
                break;
            }
            case 6:
            {
                stack::StackMain obj;
                handlers::Handle(obj);
                break;
            }
            case 7:
            {
                queue::QueueMain obj;
                handlers::Handle(obj);
                break;
            }
            case 8:
            {
                tree::TreeMain obj;
                handlers::Handle(obj);
                break;
            }
            case 9:
            {
                heap::HeapMain obj;
                handlers::Handle(obj);
                break;
            }
            case 10:
            {
                return SubmenuResult::BACK;
            }
            case 11:
            {
                return SubmenuResult::EXIT;
            }
            default:
            {
                std::cout << "The selected option is out of bounds. Please select an appropriate option." << std::endl;
                break;
            }
            }

            utils::PrintMenu(utils::DataStructuresMenuMap);
            utils::InputNumberFromUser(dsChoice, 1, static_cast<int>(utils::DataStructuresMenu::MAX_COUNT));
        }

        return SubmenuResult::CONTINUE;
    }

    SubmenuResult RunAlgorithmsMenu()
    {
        utils::PrintMenu(utils::AlgorithmsMenuMap);
        int algChoice{ 0 };
        utils::InputNumberFromUser(algChoice, 1, static_cast<int>(utils::AlgorithmsMenu::MAX_COUNT));

        while (algChoice)
        {
            if (algChoice > static_cast<int>(utils::AlgorithmsMenu::MIN_COUNT) &&
                algChoice < static_cast<int>(utils::AlgorithmsMenu::MAX_COUNT) + 1)
            {
                utils::PrintSelectedChoice(algChoice, utils::AlgorithmsMenuMap);
            }

            switch (algChoice)
            {
            case 1:
            {
                sorting_algorithms::SortingAlgorithmsMain obj;
                handlers::Handle(obj);
                break;
            }
            case 2:
            {
                return SubmenuResult::BACK;
            }
            case 3:
            {
                return SubmenuResult::EXIT;
            }
            default:
            {
                std::cout << "The selected option is out of bounds. Please select an appropriate option." << std::endl;
                break;
            }
            }

            utils::PrintMenu(utils::AlgorithmsMenuMap);
            utils::InputNumberFromUser(algChoice, 1, static_cast<int>(utils::AlgorithmsMenu::MAX_COUNT));
        }

        return SubmenuResult::CONTINUE;
    }
} // namespace

int main()
{
    utils::PrintWelcomeScreen();

    while (true)
    {
        utils::PrintMenu(utils::MainMenuMap);
        int choice{ 0 };
        utils::InputNumberFromUser(choice, 1, static_cast<int>(utils::MainMenu::MAX_COUNT));

        if (choice == 0)
        {
            // Exit requested from top-level prompt
            return 0;
        }

        if (choice > static_cast<int>(utils::MainMenu::MIN_COUNT) &&
            choice < static_cast<int>(utils::MainMenu::MAX_COUNT) + 1)
        {
            utils::PrintSelectedChoice(choice, utils::MainMenuMap);
        }

        switch (choice)
        {
        case 1:
        {
            auto result = RunLanguageMenu();
            if (result == SubmenuResult::EXIT)
                return 0;
            break;
        }
        case 2:
        {
            auto result = RunDataStructuresMenu();
            if (result == SubmenuResult::EXIT)
                return 0;
            break;
        }
        case 3:
        {
            auto result = RunAlgorithmsMenu();
            if (result == SubmenuResult::EXIT)
                return 0;
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            std::cout << "The selected option is out of bounds. Please select an appropriate option." << std::endl;
            break;
        }
        }
    }

    return 0;
}