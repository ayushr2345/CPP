#include "handlers.h"

int main()
{
    utils::PrintWelcomeScreen();
    utils::PrintMenu(utils::MainMenuMap);

    int choice { 0 };
    utils::InputNumberFromUser(choice, 1, static_cast<int>(utils::MainMenu::MAX_COUNT));

    while (choice)
    {
        if (choice > static_cast<int>(utils::MainMenu::MIN_COUNT) &&
            choice < static_cast<int>(utils::MainMenu::MAX_COUNT) + 1)
        {
            utils::PrintSelectedChoice(choice, utils::MainMenuMap);
        }

        switch (choice)
        {
        case 1:
        {
            char previousMenuFlag = 'n';
            utils::PrintMenu(utils::LanguageMenuMap);
            int choice { 0 };
            utils::InputNumberFromUser(choice, 1, static_cast<int>(utils::LanguageMenu::MAX_COUNT));
            while (choice)
            {
                if (choice > static_cast<int>(utils::LanguageMenu::MIN_COUNT) &&
                    choice < static_cast<int>(utils::LanguageMenu::MAX_COUNT) + 1)
                {
                    utils::PrintSelectedChoice(choice, utils::LanguageMenuMap);
                }
                switch (choice)
                {
                case 1:
                {
                    basics::Basics basicObj;
                    handlers::Handle(basicObj);
                    break;
                }
                case 2:
                {
                    int choiceForPointersAndReferences { 0 };
                    std::cout << "Please enter a number to get started with Pointers and References: ";
                    utils::InputNumberFromUser(choiceForPointersAndReferences);
                    pointersAndReferences::PointersAndReferences pointersAndReferencesObj(choiceForPointersAndReferences);
                    handlers::Handle(pointersAndReferencesObj);
                    break;
                }
                case 3:
                {
                    utils::IgnoreStdCinBufferTillEOL();
                    std::cout << "Please enter a name to get started with C Style Strings: ";
                    char str[20];
                    std::cin.getline(str, 20);
                    bool res = utils::CheckAndClearCharactersInStream(str, 20);
                    if (res)
                    {
                        std::cout << "You have entered a name greater than 19 characters. Only 19 characters will be taken input" << std::endl;
                    }
                    cStyleStrings::CStyleStrings cStyleStringsObj(str);
                    handlers::Handle(cStyleStringsObj);
                    break;
                }
                case 4:
                {
                    utils::IgnoreStdCinBufferTillEOL();
                    std::cout << "Please enter a name to get started with CPP Style Strings: ";
                    std::string str;
                    std::getline(std::cin, str);
                    cppStrings::CPPStrings cppStyleStringsObj(str);
                    handlers::Handle(cppStyleStringsObj);
                    break;
                }
                case 5:
                {
                    functions::Functions functionObj;
                    handlers::Handle(functionObj);
                    break;
                }
                case 6:
                {
                    classesAndObjects::ClassesAndObjects classesAndObjectsObj;
                    handlers::Handle(classesAndObjectsObj);
                    break;
                }
                case 7:
                {
                    iostreams::IOStreams iostreamsObj;
                    handlers::Handle(iostreamsObj);
                    break;
                }
                case 8:
                {
                    previousMenuFlag = 'n';
                    break;
                }
                case 9:
                {
                    exit(0);
                }
                default:
                {
                    std::cout << "The selected option is out of bounds!!! "
                              << "Please select appropriate option: " << std::endl;
                    break;
                }
                }

                if (previousMenuFlag = 'y')
                {
                    break;
                }
                else
                {
                    utils::PrintMenu(utils::LanguageMenuMap);
                    std::cin >> choice;
                }
            }
            break;
        }
        case 2:
        {
            char previousMenuFlag = 'n';
            utils::PrintMenu(utils::DSAMenuMap);
            int choice { 0 };
            utils::InputNumberFromUser(choice, 1, static_cast<int>(utils::DSAMenu::MAX_COUNT));
            while (choice)
            {
                if (choice > static_cast<int>(utils::DSAMenu::MIN_COUNT) &&
                    choice < static_cast<int>(utils::DSAMenu::MAX_COUNT) + 1)
                {
                    utils::PrintSelectedChoice(choice, utils::DSAMenuMap);
                }
                switch (choice)
                {
                case 1:
                {
                    recursions::Recursions recursionsObj;
                    handlers::Handle(recursionsObj);
                    break;
                }
                case 2:
                {
                    std::cout << "Enter the length of the array: ";
                    int length = 0;
                    utils::InputNumberFromUser(length, 0, 15);

                    arrayAdt::ArrayADT<int> arrayAdtObj(length);
                    for (int i = 0; i < length; i++)
                    {
                        arrayAdtObj.Insert(arrayAdtObj.GetSize(), i + 1);
                    }
                    handlers::Handle(arrayAdtObj);
                    break;
                }
                case 3:
                {
                    strings::Strings stringObj;
                    handlers::Handle(stringObj);
                    break;
                }
                case 4:
                {
                    matrices::MatricesMain matricesMainObj;
                    handlers::Handle(matricesMainObj);
                    break;
                }
                case 5:
                {
                    linkedList::LinkedListMain linkedListMainObj;
                    handlers::Handle(linkedListMainObj);
                    break;
                }
                case 6:
                {
                    previousMenuFlag = 'y';
                    break;
                }
                case 7:
                {
                    exit(0);
                }
                default:
                {
                    std::cout << "The selected option is out of bounds!!! "
                              << "Please select appropriate option: " << std::endl;
                    break;
                }
                }

                if (previousMenuFlag == 'y')
                {
                    break;
                }
                else
                {
                    utils::PrintMenu(utils::DSAMenuMap);
                    std::cin >> choice;
                }
            }
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            std::cout << "The selected option is out of bounds!!! "
                      << "Please select appropriate option: " << std::endl;
            break;
        }
        }
        utils::PrintMenu(utils::MainMenuMap);
        std::cin >> choice;
    }
    return 0;
}
