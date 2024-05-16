#include <iostream>
#include <fstream>
#include "IOStreams.h"
#include "utils.h"
#include "Student.h"

namespace iostreams
{
    IOStreams::IOStreams() :
        m_choice           (0),
        m_iostreamsMenuMap ( {} )
    {
        m_iostreamsMenuMap.insert({ m_iostreamsMenu(SHOWCASE_STREAMS),
                                    std::string("Showcase Streams") });
        m_iostreamsMenuMap.insert({ m_iostreamsMenu(SHOWCASE_WRITING_TO_A_FILE),
                                    std::string("Showcase writing to a file") });
        m_iostreamsMenuMap.insert({ m_iostreamsMenu(SHOWCASE_READING_FROM_A_FILE),
                                    std::string("Showcase reading from a file") });
        m_iostreamsMenuMap.insert({ m_iostreamsMenu(SHOWCASE_SERIALIZATION),
                                    std::string("Showcase serialization") });
        m_iostreamsMenuMap.insert({ m_iostreamsMenu(SHOWCASE_BINARY_FILES_OPERATIONS),
                                    std::string("Showcase binary files operations") });
        m_iostreamsMenuMap.insert({ m_iostreamsMenu(BACK_TO_PREVIOUS_MENU),
                                    std::string("Back to previous menu") });
        m_iostreamsMenuMap.insert({ m_iostreamsMenu(EXIT_FROM_PROGRAM),
                                    std::string("Exit from program") });
    }

    const int IOStreams::GetMinCase()
    {
        return m_iostreamsMenu::MIN_COUNT;
    }

    const int IOStreams::GetMaxCase()
    {
        return m_iostreamsMenu::MAX_COUNT;
    }

    const int& IOStreams::GetChoice()
    {
        return m_choice;
    }

    void IOStreams::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, (int)m_iostreamsMenu::MAX_COUNT);
    }

    void IOStreams::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_iostreamsMenuMap.begin();
            it != m_iostreamsMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void IOStreams::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
            << "You have chosen choice "
            << m_iostreamsMenuMap.at(m_choice)
            << std::endl;
    }

    void IOStreams::ShowCaseStreams()
    {
        std::cout << "Stream is data or flow of characters. They are used for accessing and transferring the data from and to outside world" << std::endl
                  << "Input from keyboard, output to a monitor, talking to a network, etc all use streams" << std::endl;
    }

    void IOStreams::ShowCaseWritingToAFile()
    {
        std::cout << "In C++, fstream class is present to help with reading and writing in a file and reading from a file." << std::endl
                  << "To write to a file, we should open the file for writing using the ofstream object of the fstream class" << std::endl
                  << "ofstream <name-of-object>(\"<file-name.txt\">, <mode>);" << std::endl
                  << "There are various modes present for opening a file such as ios::trunc (remove all contents present in file and then write) or ios::app (continue writing at end of the file)" << std::endl    
                  << "If there is no file with the name present, it will create a new file" << std::endl
                  << "Should close the file at the end of the program using file.close()" << std::endl
                  << "We should perform operations in file after confirming that if the file is open using is_open() method" << std::endl;

        std::ofstream ofs("DemoFile.txt", std::ios::trunc);
        if (!ofs.is_open())
        {
            std::cout << "Failed to open the file" << std::endl;
        }
        else
        {
            std::cout << "File is opened. Writing contents to the file" << std::endl;
            ofs << "Name: Ayush Ranjan" << std::endl;
            ofs << "Age: 23" << std::endl;
            ofs << "Company: Nokia" << std::endl;
        }
        ofs.close();
    }
    
    void IOStreams::ShowCaseReadingFromAFile()
    {
        std::cout << "To read from a file in C++, we can use the ifstream object from fstream class" << std::endl
                  << "ifstream <name-of-object>(\"<file-name.txt\">, <mode>);" << std::endl;

        std::cout << "We will open the file we created during the Writing in a file method" << std::endl;

        std::ifstream ifs("DemoFile.txt");

        if (!ifs.is_open())
        {
            std::cout << "Failed to open the file" << std::endl;
        }
        else
        {
            std::cout << "File is opened. Reading contents from the file" << std::endl;
            std::string s1, s2, s3;
            
            std::getline(ifs, s1);
            std::getline(ifs, s2);
            std::getline(ifs, s3);

            std::cout << "Contents of the file: " << s1 << " " << s2 << " " << s3 << std::endl;
        }
        ifs.close();
    }

    void IOStreams::ShowCaseSerialization()
    {
        std::cout << "If instead of in-built data types, we want to write an object of a class to a file then, we need to overload the << operator of the class" << std::endl
                  << "ofstream& operator<<(ofstream& ofs, <class-name>& c) {<write-contents-to-file-and-return--ofs>}" << std::endl;

        std::cout << "We have a class called Student which has name, roll number and branch members" << std::endl;

        student::Student s1;
        s1.name = "Ayush Ranjan";
        s1.roll = 16;
        s1.branch = "ECE";

        std::ofstream ofs("MyFile.txt", std::ios::trunc);

        if (!ofs.is_open())
        {
            std::cout << "Failed to open the file" << std::endl;
        }
        else
        {
            std::cout << "File is opened. Writing the object to the file" << std::endl;

            ofs << s1 << std::endl;
        }
        ofs.close();

        std::cout << "We have stored the object to the file through the object. Similarly we can retreive the object from a file by overloading the >> operator" << std::endl;
        
        student::Student s2;
        std::ifstream ifs("MyFile.txt");

        ifs >> s2;

        std::cout << "We have read the object through serialization" << std::endl;
        
        std::cout << "The read object:" << std::endl
                  << "....Name: " << s2.name << std::endl
                  << "....Roll: " << s2.roll << std::endl
                  << "....Branch: " << s2.branch << std::endl;
    }

    void IOStreams::ShowCaseBinaryFilesOperations()
    {
        std::cout << "There are two types of files here: txt files and binary files" << std::endl
                  << "There is a difference in how the data is stored in each of them" << std::endl
                  << "If we want to store the number 23 in a txt and a binary file then" << std::endl
                  << "23 in binary is 10111. And int is normally 4 bytes so, 23 in binary would be stored as: 0000'0000'0000'0000'0000'0000'0001'0111 in a binary file" << std::endl
                  << "while for in a txt file: " << std::endl
                  << "ASCII values are 8 bits. ASCII of '2' is 50 - 00110010 and that of '3' is 51 - 00110011 and it is stored as: 0011'0010'0011'0011 in the txt file" << std::endl
                  << "Notepad reads the first 8 bits, does the conversion and displays the characters but if it does the same with a binary file, it will display junk characters" << std::endl;

        std::cout << "The differences between text and binary file is:" << std::endl
                  << "1. Binary files are faster to read and write as compared to text files because of all the conversions" << std::endl
                  << "2. Binary files are smaller in size as compared to the text files as each character takes up 8 bits in ASCII" << std::endl
                  << "3. Binary files are non-human readable while on that other hand, text files are human-readable" << std::endl;

        std::ofstream ofs("DemoFileBin", std::ios::binary | std::ios::trunc);
        if (!ofs.is_open())
        {
            std::cout << "Failed to open the file" << std::endl;
        }
        else
        {
            std::string str = "Ayush Ranjan";
            size_t size = str.size();

            std::cout << "File is opened. Writing contents to the file" << std::endl;
            ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
            ofs.write(str.c_str(), str.size());
        }
        ofs.close();

        std::ifstream ifs("DemoFileBin", std::ios::binary);

        if (!ifs.is_open())
        {
            std::cout << "Failed to open the file" << std::endl;
        }
        else
        {
            std::cout << "File is opened. Reading contents from the file" << std::endl;

            std::string readStr;
            size_t size;
            ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
            readStr.resize(size);
            ifs.read(const_cast<char*>(readStr.c_str()), size);
            ifs.close();

            std::cout << "We have read the object from the binary file" << std::endl;

            std::cout << "The content in file is: " << readStr << std::endl;
        }
    }
} // namespace iostreams
