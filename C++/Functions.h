#pragma once

#include <map>
#include <string>

namespace functions
{
    class Functions
    {
    private:
        enum m_functionsMenu
        {
            MIN_COUNT                           = 0,
            SHOWCASE_FUNCTIONS                  = 1,
            SHOWCASE_OVERLOADED_FUNCTIONS       = 2,
            ADD_2_INTS_OVERLOADING              = 3,
            ADD_2_FLOATS_OVERLOADING            = 4,
            ADD_3_INTS_OVERLOADING              = 5,
            SHOWCASE_FUNCTION_TEMPLATES         = 6,
            ADD_2_INTS_TEMPLATE                 = 7,
            ADD_2_FLOATS_TEMPLATE               = 8,
            ADD_2_STRINGS_TEMPLATE              = 9,
            SHOWCASE_DEFAULT_ARGUMENTS          = 10,
            ADD_2_INTS_DEFAULT_ARGS             = 11,
            ADD_3_INTS_DEFAULT_ARGS             = 12,
            ADD_4_INTS_DEFAULT_ARGS             = 13,
            SHOWCASE_PASSING_ARGS_TO_FUNCTIONS  = 14,
            SWAP_PASS_BY_VALUE                  = 15,
            SWAP_PASS_BY_ADDRESS                = 16,
            SWAP_PASS_BY_REFERENCE              = 17,
            RETURN_BY_ADDRESS_CREATE_ARRAY      = 18,
            RETURN_BY_REFERENCE                 = 19,
            SHOWCASE_GLOBAL_VS_STATIC_VARIABLES = 20,
            SHOWCASE_RECURSIVE_FUNCTIONS        = 21,
            SHOWCASE_FUNCTION_POINTERS          = 22,
            SHOWCASE_WORKING_FUNCTION_POINTERS  = 23,
            FACTORIAL                           = 24,
            BACK_TO_PREVIOUS_MENU               = 25,
            EXIT_FROM_PROGRAM                   = 26,
            MAX_COUNT                           = EXIT_FROM_PROGRAM
        };
        int                        m_choice{ 0 };
        std::map<int, std::string> m_functionsMenuMap{};

    public:
        Functions();
        const int  GetMinCase();
        const int  GetMaxCase();
        const int& GetChoice();
        void       GetChoiceInputFromUser();
        void       PrintMenu();
        void       PrintSelectedChoice();
        void       ShowcaseFunctions();
        void       ShowcaseOverloadedFunctions();
        int        Add2IntsOverloading(int, int);
        float      Add2FloatsOverloading(float, float);
        int        Add3IntsOverloading(int, int, int);
        void       ShowcaseFunctionTemplates();

        // templates should not have definition in a separate source file 
        // as it would give compilation and linking errors
        template <typename T>
        T             AddTemplate(T a, T b) { return a + b; }
        void          ShowcaseDefaultArguments();
        int           Add2Or3Or4IntsDefaultArgument(int, int b = 0, int c = 0, int d = 0);
        void          ShowcasePassingArgsToFunction();
        void          SwapByValue(int, int);
        void          SwapByAddress(int*, int*);
        void          SwapByReference(int&, int&);
        int*          ReturnByAddressCreateArray(int);
        int&          ReturnByReference(int&);
        void          ShowcaseGlobalVsStaticVariables();
        void          ShowcaseRecursiveFunctions();
        void          ShowcaseFunctionPointers();
        int           Max2Int(int, int);
        int           Min2Int(int, int);
        long long int Factorial(int);
    };
} // namespace functions
