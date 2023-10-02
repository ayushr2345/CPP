#pragma once

#include <map>
#include <string>

namespace pointersAndReferences
{
    class PointersAndReferences
    {
    private:
        enum m_PointersAndReferencesMenu
        {
            MIN_COUNT                                                                 = 0,
            PRINT_DATA_IN_MEMBER_DATA_VARIABLE                                        = 1,
            PRINT_ADDRESS_OF_MEMBER_DATA_VARIABLE                                     = 2,
            SET_DATA_IN_MEMBER_POINTER_VARIABLE                                       = 3,
            DEREFERENCE_MEMBER_POINTER_VARIABLE                                       = 4,
            PRINT_ADDRESS_STORED_IN_MEMBER_POINTER_VARIABLE                           = 5,
            PRINT_ADDRESS_OF_MEMBER_POINTER_VARIABLE                                  = 6,
            PRINT_DATA_IN_MEMBER_REFERENCE_VARIABLE                                   = 7,
            PRINT_ADDRESS_OF_MEMBER_REFERENCE_VARIABLE                                = 8,
            INCREMENT_OR_DECREMENT_MEMBER_DATA_VARIABLE_VIA_REGULAR                   = 9,
            INCREMENT_OR_DECREMENT_MEMBER_DATA_VARIABLE_VIA_MEMBER_REFERENCE_VARIABLE = 10,
            INCREMENT_OR_DECREMENT_MEMBER_DATA_VARIABLE_VIA_MEMBER_POINTER_VARIABLE   = 11,
            COMPARE_ADDRESS_OF_REFERENCE_DATA_POINTER_MEMBER_VARIABLES                = 12,
            COMPARE_DATA_OF_REFERENCE_DATA_POINTER_MEMBER_VARIABLES                   = 13,
            INITIALIZE_THE_ARRAY                                                      = 14,
            PRINT_SIZE_OF_ARRAY                                                       = 15,
            SHOWCASE_ARRAYS_WITH_POINTERS                                             = 16,
            DISPLAY_THE_ARRAY                                                         = 17,
            PROBLEMS_WITH_POINTERS                                                    = 18,
            BACK_TO_PREVIOUS_MENU                                                     = 19,
            EXIT_FROM_PROGRAM                                                         = 20,
            MAX_COUNT                                                                 = EXIT_FROM_PROGRAM
        };
        int                        m_choice { 0 };
        int*                       m_ptr { nullptr };
        int                        m_data { 0 };
        int&                       m_dataRef { m_data };
        int*                       m_array { nullptr };
        int                        m_arraySize;
        std::map<int, std::string> m_PointersAndReferencesMap{};

    public:
        PointersAndReferences(const int& data);
        ~PointersAndReferences();
        const int&  GetMinCase();
        const int&  GetMaxCase();
        const int&  GetChoice();
        void        GetChoiceInputFromUser();
        void        PrintMenu();
        void        PrintSelectedChoice();
        const int&  GetData();
        const int*  GetDataAddress();
        void        SetDataInPtr();
        const int&  DereferenceMemberPointer();
        const int*  GetDataInPointer();
        const int** GetPointerAddress();
        const int&  GetDataInReference();
        const int*  GetAddressOfReference();
        void        IncrementOrDecrementDataViaRegular(const int&);
        void        IncrementOrDecrementDataViaReference(const int&);
        void        IncrementOrDecrementDataViaPointer(const int&);
        void        CompareAddressesOfThree();
        void        CompareDataOfThree();
        void        InitializeArray(const int&);
        void        FillTheArray();
        void        ShowCaseArraysWithPointers();
        void        DisplayArray();
        void        ShowCaseProblemsWithArrays();
        const int&  GetArraySize();
        const bool  IsArrayNull();
    };
} // namespace pointersAndReferences
