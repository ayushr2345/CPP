#pragma once

#include <map>
#include <string>

namespace classesAndObjects
{
    class ClassesAndObjects
    {
    private:
        enum m_classesAndObjectsMenu
        {
            MIN_COUNT                                                           = 0,
            SHOWCASE_PRINCIPLES_OF_OOPS                                         = 1,
            SHOWCASE_CLASS_VS_OBJECT                                            = 2,
            SHOWCASE_ACCESSORS_AND_MUTATORS                                     = 3,
            SHOWCASE_CONSTRUCTORS                                               = 4,
            SHOWCASE_DEFAULT_CONSTRUCTORS                                       = 5,
            SHOWCASE_NON_PARAMETERIZED_CONSTRUCTORS                             = 6,
            SHOWCASE_PARAMETERIZED_CONSTRUCTORS                                 = 7,
            SHOWCASE_COPY_CONSTRUCTORS                                          = 8,
            SHOWCASE_DEEP_COPY_CONSTRUCTORS                                     = 9,
            SHOWCASE_TYPES_OF_FUNCTIONS_IN_A_CLASS                              = 10,
            SHOWCASE_THIS_POINTER                                               = 11,
            SHOWCASE_STRUCT_VS_CLASS                                            = 12,
            SHOWCASE_OPERATOR_OVERLOADING                                       = 13,
            SHOWCASE_OPERATOR_OVERLOADING_WITH_FRIEND_FUNCTION                  = 14,
            SHOWCASE_OVERLOADING_INSERTION_AND_EXTRACTION_OPERATOR              = 15,
            SHOWCASE_INHERITANCE                                                = 16,
            SHOWCASE_CONSTRUCTORS_IN_INHERITANCE                                = 17,
            SHOWCASE_ACCESS_SPECIFIERS                                          = 18,
            SHOWCASE_TYPES_OF_INHERITANCE                                       = 19,
            SHOWCASE_WAYS_OF_INHERITANCE                                        = 20,
            SHOWCASE_GENERALIZATION_VS_SPECIALIZATION                           = 21,
            SHOWCASE_BASE_CLASS_POINTER_DERIVED_CLASS_OBJECT                    = 22,
            SHOWCASE_POLYMORPHISM                                               = 23,
            SHOWCASE_VIRTUAL_FUNCTIONS                                          = 24,
            SHOWCASE_RUNTIME_POLYMORPHISM                                       = 25,
            SHOWCASE_PURE_VIRTUAL_FUNCTIONS                                     = 26,
            SHOWCASE_ABSTRACT_CLASSES                                           = 27,
            SHOWCASE_FRIEND_FUNCTIONS_AND_CLASSES                               = 28,
            SHOWCASE_STATIC_MEMBERS                                             = 29,
            SHOWCASE_NESTED_CLASS                                               = 30,
            SHOWCASE_EXCEPTION_HANDLING                                         = 31,
            SHOWCASE_EXCEPTION_HANDLING_MULTICATCH_AND_EPSILON                  = 32,
            SHOWCASE_EXCEPTION_HANDLING_INHERITANCE                             = 33,
            SHOWCASE_TEMPLATE_FUNCTIONS_AND_CLASSES                             = 34,
            SHOWCASE_CONSTANTS                                                  = 35,
            SHOWCASE_POINTER_TO_A_CONSTANT                                      = 36,
            SHOWCASE_CONSTANT_POINTER                                           = 37,
            SHOWCASE_CONSTANT_POINTER_TO_A_CONSTANT                             = 38,
            SHOWCASE_CONSTANT_IDENTIFIER_FOR_FUNCTIONS                          = 39,
            SHOWCASE_CONSTANT_IDENTIFIER_FOR_MEMBER_FUNCTION                    = 40,
            SHOWCASE_MACROS                                                     = 41,
            SHOWCASE_NAMESPACES                                                 = 42,
            SHOWCASE_DESTRUCTOR                                                 = 43,
            SHOWCASE_DESTRUCTOR_HEAP_OBJECT                                     = 44,
            SHOWCASE_BASE_CLASS_POINTER_DERIVED_CLASS_OBJECT_DESTRUCTOR_PROBLEM = 45,
            BACK_TO_PREVIOUS_MENU                                               = 46,
            EXIT_FROM_PROGRAM                                                   = 47,
            MAX_COUNT                                                           = EXIT_FROM_PROGRAM
        };
        int                                                                     m_choice { 0 };
        std::map<int, std::string>                                              m_classesAndObjectsMenuMap {};

    public:
        ClassesAndObjects();
        const int& GetMinCase();
        const int& GetMaxCase();
        const int& GetChoice();
        void       GetChoiceInputFromUser();
        void       PrintMenu();
        void       PrintSelectedChoice();
        void       ShowCasePrinciplesOfOops();
        void       ShowCaseClassesVsObjects();
        void       ShowCaseAccessorsAndMutators();
        void       ShowCaseConstructors();
        void       ShowCaseDefaultConstructors();
        void       ShowCaseNonParameterizedConstructors();
        void       ShowCaseParameterizedConstructors(int length, int breadth);
        void       ShowCaseCopyConstructors(int length, int breadth);
        void       ShowCaseDeepCopyConstructors();
        void       ShowCaseTypesOfFunctionsInAClass();
        void       ShowCaseThisPointer();
        void       ShowCaseStructVsClass();
        void       ShowCaseOperatorOverloading();
        void       ShowCaseOperatorOverloadingWithFriendFunction();
        void       ShowCaseOverloadingInsertionAndExtractionOperator();
        void       ShowCaseInheritance();
        void       ShowCaseConstructorsInInheritance();
        void       ShowCaseAccessSpecifiers();
        void       ShowCaseTypesOfInteritance();
        void       ShowCaseWaysOfInheritance();
        void       ShowCaseGeneralizationVsSpecialization();
        void       ShowCaseBaseClassPointerDerivedClassObject();
        void       ShowCasePolymorphism();
        void       ShowCaseVirtualFunctions();
        void       ShowCaseRuntimePolymorphism();
        void       ShowCasePureVirtualFunctions();
        void       ShowCaseAbstractClasses();
        void       ShowCaseFriendFunctionAndClasses();
        void       ShowCaseStaticMembers();
        void       ShowCaseNestedClass();
        void       ShowCaseExceptionHandling();
        void       ShowCaseExceptionHandlingMultiCatchAndEpsilon();
        void       ShowCaseExceptionHandlingInheritance();
        void       ShowCaseTemplateFunctionsAndClasses();
        void       ShowCaseConstants();
        void       ShowCasePointerToAConstant();
        void       ShowCaseConstantPointer();
        void       ShowCaseConstantPointerToAConstant();
        void       ShowCaseConstantIdentifierForFunctions();
        void       ShowCaseConstantIdentifierForMemberFunction();
        void       ShowCaseMacros();
        void       ShowCaseNamespaces();
        void       ShowCaseDestructors();
        void       ShowCaseDestructorsHeapObject();
        void       ShowCaseBaseClassPointerDerivedClassObjectDestructorProblem();
    };
} // namespace classesAndObjects
