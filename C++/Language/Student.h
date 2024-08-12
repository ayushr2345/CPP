#pragma once

#include<string>

namespace student
{
    class Student
    {
    public:
        ~Student() { name = ""; roll = 0; branch = ""; }
        std::string name {""};
        int         roll {0};
        std::string branch {""};
        friend std::ofstream& operator<<(std::ofstream&, Student&);
        friend std::ifstream& operator>>(std::ifstream&, Student&);
    };
} // namespace student