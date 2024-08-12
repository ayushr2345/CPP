#include <iostream>
#include "Functions.h"
#include "../utils.h"

namespace functions
{
    Functions::Functions() :
        m_choice           (0),
        m_functionsMenuMap ({})
    {
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_FUNCTIONS),
                                    std::string("Showcase Functions") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_OVERLOADED_FUNCTIONS),
                                    std::string("Showcase overloaded functions") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_2_INTS_OVERLOADING),
                                    std::string("Add 2 integers using overloaded functions") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_2_FLOATS_OVERLOADING),
                                    std::string("Add 2 floats using overloaded functions") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_3_INTS_OVERLOADING),
                                    std::string("Add 3 integers using overloaded functions") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_FUNCTION_TEMPLATES),
                                    std::string("Showcase function templates") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_2_INTS_TEMPLATE),
                                    std::string("Add 2 integers using template function") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_2_FLOATS_TEMPLATE),
                                    std::string("Add 2 floats using template function") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_2_STRINGS_TEMPLATE),
                                    std::string("Add 2 strings using template function") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_DEFAULT_ARGUMENTS),
                                    std::string("Showcase default arguments") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_2_INTS_DEFAULT_ARGS),
                                    std::string("Add 2 integers using default arguments function") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_3_INTS_DEFAULT_ARGS),
                                    std::string("Add 3 integers using default arguments function") });
        m_functionsMenuMap.insert({ m_functionsMenu(ADD_4_INTS_DEFAULT_ARGS),
                                    std::string("Add 4 integers using default arguments function") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_PASSING_ARGS_TO_FUNCTIONS),
                                    std::string("Showcase passing arguments to a function") });
        m_functionsMenuMap.insert({ m_functionsMenu(SWAP_PASS_BY_VALUE),
                                    std::string("Swap integers using pass by value") });
        m_functionsMenuMap.insert({ m_functionsMenu(SWAP_PASS_BY_ADDRESS),
                                    std::string("Swap integers using pass by address") });
        m_functionsMenuMap.insert({ m_functionsMenu(SWAP_PASS_BY_REFERENCE),
                                    std::string("Swap integers using pass by reference") });
        m_functionsMenuMap.insert({ m_functionsMenu(RETURN_BY_ADDRESS_CREATE_ARRAY),
                                    std::string("Create array using return by address") });
        m_functionsMenuMap.insert({ m_functionsMenu(RETURN_BY_REFERENCE),
                                    std::string("Return by reference") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_GLOBAL_VS_STATIC_VARIABLES),
                                    std::string("Showcase global vs static variables") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_RECURSIVE_FUNCTIONS),
                                    std::string("Showcase recursive functions") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_FUNCTION_POINTERS),
                                    std::string("Showcase function pointers") });
        m_functionsMenuMap.insert({ m_functionsMenu(SHOWCASE_WORKING_FUNCTION_POINTERS),
                                    std::string("Showcase working function pointers ") });
        m_functionsMenuMap.insert({ m_functionsMenu(FACTORIAL),
                                    std::string("Factorial using recursion") });
        m_functionsMenuMap.insert({ m_functionsMenu(BACK_TO_PREVIOUS_MENU),
                                    std::string("Back to previous menu") });
        m_functionsMenuMap.insert({ m_functionsMenu(EXIT_FROM_PROGRAM),
                                    std::string("Exit from program") });
    }

    const int Functions::GetMinCase()
    {
        return m_functionsMenu::MIN_COUNT;
    }

    const int Functions::GetMaxCase()
    {
        return m_functionsMenu::MAX_COUNT;
    }

    const int& Functions::GetChoice()
    {
        return m_choice;
    }

    void Functions::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, (int)m_functionsMenu::MAX_COUNT);
    }

    void Functions::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_functionsMenuMap.begin();
            it != m_functionsMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void Functions::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
                  << "You have chosen choice "
                  << m_functionsMenuMap.at(m_choice)
                  << std::endl;
    }

    void Functions::ShowcaseFunctions()
    {
        std::cout << "Functions are pieces of code that can be used many times, can be shared with other programs as well as other programmers" << std::endl
                  << "To declare functions:" << std::endl
                  << "....<RETURN-TYPE> <FUNCTION-NAME> (<ARGUMENTS-LIST>)" << std::endl
                  << "....{" << std::endl
                  << "........<FUNCTION-BLOCK>" << std::endl
                  << "........return <AT-MOST-ONE-VARIABLE-CAN-BE-RETUENED>;    // not necessary to return if return type void" << std::endl
                  << "....}" << std::endl
                  << "Functions can also be declared first and defined afterwards using:" << std::endl
                  << "....<RETURN-TYPE> <FUNCTION-NAME> (<ARGUMENTS-LIST>);" << std::endl
                  << "and later, we can define the function afterwards as mentioned before." << std::endl
                  << "To call the function, we have to do:" << std::endl
                  << "<FUNCTION-NAME (<ARGUMENT-LIST>);>" << std::endl;
    }

    void Functions::ShowcaseOverloadedFunctions()
    {
        std::cout << "Function overvloading can be done in C++ which means that there can exist many functions with same name if:" << std::endl
                  << "1. The number of arguments are different in each of them if the data type is same" << std::endl
                  << "2. The data type of the args is different" << std::endl
                  << "....int add(int, int);" << std::endl
                  << "....int add(int, int, int);" << std::endl
                  << "....float add(float, float);" << std::endl
                  << "are all valid overloaded functions" << std::endl; 
    }

    int Functions::Add2IntsOverloading(int a, int b) { return a + b; }

    float Functions::Add2FloatsOverloading(float a, float b) { return a + b; }

    int Functions::Add3IntsOverloading(int a, int b, int c) { return a + b + c; }

    void Functions::ShowcaseFunctionTemplates()
    {
        std::cout << "If the body of two or more functions is same, we can write a generic function instead of overloading many functions" << std::endl
                  << "....template <<typename OR class> T>" << std::endl
                  << "....T add (T a, T b)" << std::endl
                  << "....{" << std::endl
                  << "........return a + b;" << std::endl
                  << "....}" << std::endl;
        std::cout << "Then the function will be called for int using:" << std::endl
                  << "....add<int> (10, 20);" << std::endl
                  << "if the data type is not mentioned in <>, then compiler will deduce the data type of variables and if it finds a template for that, will instantiate the function" << std::endl;
        std::cout << "This way, using function templates, functions which add two numbers (int, long, float, double, etc) can be combined into one generic template function." << std::endl
                  << "The function for any data member will not be instantiated. They will be instantiated for a data type only when they are called on that particular data type" << std::endl;
    }

    void Functions::ShowcaseDefaultArguments()
    {
        std::cout << "Functions can have default arguments supplied to them at the time of declaration. If no value is given for a particular argument, then the default value is taken" << std::endl
                  << "Default arguments can only be present at then end of the formal parameters of the function" << std::endl
                  << "....int add (int a, int b = 0, int c = 0, int d = 0) { return a + b + c + d; }" << std::endl
                  << "This function can add as 4 different overloaded functions:" << std::endl
                  << "1. ........int add (int a);" << std::endl
                  << "2. ........int add (int a, int b);" << std::endl
                  << "3. ........int add (int a, int b, int c);" << std::endl
                  << "4. ........int add (int a, int b, int c, int d);" << std::endl;
    }

    int Functions::Add2Or3Or4IntsDefaultArgument(int a, int b, int c, int d) { return a + b + c + d; }

    void Functions::ShowcasePassingArgsToFunction()
    {
        std::cout << "There are 3 ways in which we can pass the parameters to a function in C++:" << std::endl
                  << "1. Pass by value" << std::endl
                  << "2. Pass by address" << std::endl
                  << "3. Pass by reference" << std::endl;

        std::cout << "1. Pass by value" << std::endl
                  << "....void swap(int a, int b) { // Code to swap a and b }" << std::endl
                  << "it will be called as swap (x, y) where x and y are integers" << std::endl
                  << "As this is pass by value, the value of x and y will be copied in a and b respectively and those will be swapped instead of x and y" << std::endl
                  << "Hence pass by value is not good enough if the user wants to change the value of the actual parameters" << std::endl;
        std::cout << std::endl;
        std::cout << "2. Pass by address" << std::endl
                  << "....void swap(int *a, int *b) { // Code to swap *a and *b }" << std::endl
                  << "it will be called as swap (&x, &y) where x and y are integers" << std::endl
                  << "As this is pass by address, the address of x and y will be copied in a and b respectively and swapping can be done by dereferencing a and b " << std::endl
                  << "Hence pass by address is nice way if the user wants to change the value of the actual parameters" << std::endl;
        std::cout << std::endl;
        std::cout << "3. Pass by reference" << std::endl
                  << "....void swap(int &a, int &b) { // Code to swap a and b }" << std::endl
                  << "it will be called as swap (x, y) where x and y are integers" << std::endl
                  << "As this is pass by reference, the address of a and b would be created references of x and y respectively and swapping can be done " << std::endl
                  << "Hence pass by reference is better way if the user wants to change the value of the actual parameters" << std::endl
                  << "Pass by reference only exists in C++ and is internally implemented in the form of pointers" << std::endl;
    }

    void Functions::SwapByValue(int a, int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void Functions::SwapByAddress(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void Functions::SwapByReference(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int* Functions::ReturnByAddressCreateArray(int length)
    {
        int* p = new int[length];
        return p;
    }

    int& Functions::ReturnByReference(int& a)
    {
        std::cout << "Value passed: " << a << std::endl;
        return a;
    }

    void Functions::ShowcaseGlobalVsStaticVariables()
    {
        std::cout << "Global variables can be declared in C++ outside of any functions and their memory exists throughout the program and are accessible everywhere insidie the program" << std::endl
                  << "Static variables can be declared in C++ outside or inside a function: " << std::endl
                  << "1. If declared inside a function, their memory exists through out the program but are only accessible within that function. If control comes inside this function a second time, memory for static"
                  << " variable won't be reserved second time as it already exists" << std::endl
                  << "2. If declared outside the functions, it basically acts as global variable" << std::endl;
    }

    void Functions::ShowcaseRecursiveFunctions()
    {
        std::cout << "A function that calls itself is called a Recursive function and the process is called recursion" << std::endl
                  << "....void fun (int n)" << std::endl
                  << "....{" << std::endl
                  << "........if (n > 0)        // necessary to terminate the recursion as otherwise it will run infinite times" << std::endl
                  << "........{" << std::endl
                  << "............std::cout << n << std::endl;" << std::endl
                  << "............fun (n - 1);" << std::endl
                  << "........}" << std::endl
                  << "....}" << std::endl
                  << "The above recursive function will print numbers from n till 1" << std::endl;
    }

    void Functions::ShowcaseFunctionPointers()
    {
        std::cout << "In C++, a pointer to a function is possible:" << std::endl
                  << "....void display() { std::cout << \"Hello World\" << std::endl; }" << std::endl
                  << "<RETURN-TYPE> (*<FUNCTION-POINTER-NAME>) (<FORMAL-PARAMETERS>)" << std::endl
                  << "....void (*fp) ();" << std::endl
                  << "....fp = display;" << std::endl
                  << "....(*fp)();      // will call display" << std::endl;
        std::cout << "The same function pointer can point to many functions if the function signature is same. Function overriding is implemented using function pointers internally" << std::endl;
    }

    int Functions::Max2Int(int x, int y) { return x > y ? x : y; }

    int Functions::Min2Int(int x, int y) { return x < y ? x : y; }

    long long int Functions::Factorial(int n)
    {
        if (n > 1) return (n * Factorial(n - 1));
        else return 1;
    }
} // namespace functions
