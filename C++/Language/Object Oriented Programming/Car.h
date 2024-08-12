#pragma once

#include <map>
#include <string>

namespace car
{
    class ICar
    {
    public:
        virtual void Start() = 0;
        virtual void Stop()  = 0;
    };

    class Innova : public ICar
    {
    public:
        void Start() { std::cout << "Innova started" << std::endl; }
        void Stop()  { std::cout << "Innova stopped" << std::endl; }
    };

    class Swift : public ICar
    {
    public:
        void Start() { std::cout << "Swift started" << std::endl; }
        void Stop()  { std::cout << "Swift stopped" << std::endl; }
    };
} // namespace car
