#pragma once

#include <iostream>
#include <fstream>
#include "Student.h"

namespace student
{
    std::ofstream& operator<<(std::ofstream& ofs, Student& s)
    {
        ofs << s.name << std::endl;
        ofs << s.roll << std::endl;
        ofs << s.branch << std::endl;
        return ofs;
    }

    std::ifstream& operator>>(std::ifstream& ifs, Student& s)
    {
        std::getline(ifs, s.name);
        std::string str;
        std::getline(ifs, str);
        s.roll = stoi(str);
        std::getline(ifs, s.branch);
        return ifs;
    }

} // namespace student
