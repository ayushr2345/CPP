#include <iostream>
#include "ClassesAndObjects.h"
#include "Rectangle.h"
#include "Complex.h"
#include "Cuboid.h"
#include "Car.h"
#include "../../utils.h"

namespace classesAndObjects
{
    ClassesAndObjects::ClassesAndObjects() :
        m_choice(0),
        m_classesAndObjectsMenuMap({})
    {
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_PRINCIPLES_OF_OOPS),
                                            std::string("Showcase Principles of OOPs") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CLASS_VS_OBJECT),
                                            std::string("Showcase Classes vs Objects") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_ACCESSORS_AND_MUTATORS),
                                            std::string("Showcase Accessors and Mutators") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CONSTRUCTORS),
                                            std::string("Showcase Constructors") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_DEFAULT_CONSTRUCTORS),
                                            std::string("Showcase Default Constructors") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_NON_PARAMETERIZED_CONSTRUCTORS),
                                            std::string("Showcase Non-parameterized Constructors") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_PARAMETERIZED_CONSTRUCTORS),
                                            std::string("Showcase Parameterized Constructors") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_COPY_CONSTRUCTORS),
                                            std::string("Showcase Copy Constructors") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_DEEP_COPY_CONSTRUCTORS),
                                            std::string("Showcase Deep Copy Constructors") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_TYPES_OF_FUNCTIONS_IN_A_CLASS),
                                            std::string("Showcase Types of Functions in a Class") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_THIS_POINTER),
                                            std::string("Showcase this pointer") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_STRUCT_VS_CLASS),
                                            std::string("Showcase Struct vs Class") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_OPERATOR_OVERLOADING),
                                            std::string("Showcase Operator Overloading") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_OPERATOR_OVERLOADING_WITH_FRIEND_FUNCTION),
                                            std::string("Showcase Operator Overloading with Friend Function") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_OVERLOADING_INSERTION_AND_EXTRACTION_OPERATOR),
                                            std::string("Showcase Overloading Insertion and Extraction Operator") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_INHERITANCE),
                                            std::string("Showcase Inheritance") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CONSTRUCTORS_IN_INHERITANCE),
                                            std::string("Showcase Constructors in Inheritance") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_ACCESS_SPECIFIERS),
                                            std::string("Showcase Access Specifiers") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_TYPES_OF_INHERITANCE),
                                            std::string("Showcase Types of Inheritance") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_WAYS_OF_INHERITANCE),
                                            std::string("Showcase Ways of Inheritance") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_GENERALIZATION_VS_SPECIALIZATION),
                                            std::string("Showcase Generalization vs Specialization") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_BASE_CLASS_POINTER_DERIVED_CLASS_OBJECT),
                                            std::string("Showcase Base Class Pointer Derived Class Object") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_POLYMORPHISM),
                                            std::string("Showcase Polymorphism") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_VIRTUAL_FUNCTIONS),
                                            std::string("Showcase Virtual Functions") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_RUNTIME_POLYMORPHISM),
                                            std::string("Showcase Runtime Polymorphism") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_PURE_VIRTUAL_FUNCTIONS),
                                            std::string("Showcase Pure Virtual Functions") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_ABSTRACT_CLASSES),
                                            std::string("Showcase Abstract Classes") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_FRIEND_FUNCTIONS_AND_CLASSES),
                                            std::string("Showcase Friend Functions and Classes") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_STATIC_MEMBERS),
                                            std::string("Showcase Static Members") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_NESTED_CLASS),
                                            std::string("Showcase Nested Class") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_EXCEPTION_HANDLING),
                                            std::string("Showcase Exception Handling") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_EXCEPTION_HANDLING_MULTICATCH_AND_EPSILON),
                                           std::string("Showcase Exception Handling Multicatch and Epsilon") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_EXCEPTION_HANDLING_INHERITANCE),
                                           std::string("Showcase Exception Handling in Inheritance") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_TEMPLATE_FUNCTIONS_AND_CLASSES),
                                            std::string("Showcase Template Functions and Classes") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CONSTANTS),
                                            std::string("Showcase Constants") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_POINTER_TO_A_CONSTANT),
                                            std::string("Showcase Pointer to a Constant") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CONSTANT_POINTER),
                                            std::string("Showcase Constant Pointer") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CONSTANT_POINTER_TO_A_CONSTANT),
                                            std::string("Showcase Constant Pointer to a Constant") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CONSTANT_IDENTIFIER_FOR_FUNCTIONS),
                                            std::string("Showcase Constant Identifier for Functions") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_CONSTANT_IDENTIFIER_FOR_MEMBER_FUNCTION),
                                            std::string("Showcase Constant Identifier for Member Function") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_MACROS),
                                            std::string("Showcase Macros") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_NAMESPACES),
                                            std::string("Showcase Namespaces") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_DESTRUCTOR),
                                            std::string("Showcase Destructor") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_DESTRUCTOR_HEAP_OBJECT),
                                            std::string("Showcase Destructor Heap Object") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(SHOWCASE_BASE_CLASS_POINTER_DERIVED_CLASS_OBJECT_DESTRUCTOR_PROBLEM),
                                            std::string("Showcase Base Class Pointer Derived Class Object Destructor Problem") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(BACK_TO_PREVIOUS_MENU),
                                            std::string("Back to previous menu") });
        m_classesAndObjectsMenuMap.insert({ m_classesAndObjectsMenu(EXIT_FROM_PROGRAM),
                                            std::string("Exit from program") });
    }

    const int ClassesAndObjects::GetMinCase()
    {
        return m_classesAndObjectsMenu::MIN_COUNT;
    }

    const int ClassesAndObjects::GetMaxCase()
    {
        return m_classesAndObjectsMenu::MAX_COUNT;
    }

    const int& ClassesAndObjects::GetChoice()
    {
        return m_choice;
    }

    void ClassesAndObjects::GetChoiceInputFromUser()
    {
        utils::InputNumberFromUser(m_choice, 1, (int)m_classesAndObjectsMenu::MAX_COUNT);
    }

    void ClassesAndObjects::PrintMenu()
    {
        std::cout << std::endl;
        for (std::map<int, std::string>::iterator it = m_classesAndObjectsMenuMap.begin();
            it != m_classesAndObjectsMenuMap.end();
            it++)
        {
            std::cout << it->first << ". " << it->second << std::endl;
        }
        std::cout << "Please enter your choice: ";
    }

    void ClassesAndObjects::PrintSelectedChoice()
    {
        std::cout << std::endl << std::endl
            << "You have chosen choice "
            << m_classesAndObjectsMenuMap.at(m_choice)
            << std::endl;
    }

    void ClassesAndObjects::ShowCasePrinciplesOfOops()
    {
        std::cout << "OOP is a style of programming where we try to mimic the data in real world terms" << std::endl
                  << "The basic priinciples of OOPs are:" << std::endl
                  << "1. Abstraction - Hiding the working of something and making available only the functions to the user. eg: We know how to drive a car, but not the working. OR We use cout, etc but its not necessary to know the working" << std::endl
                  << "2. Encapsulation - Grouping of data and functions related to data in single entity. eg: classes or structs in CPP" << std::endl
                  << "3. Inheritance - Deriving properties of one class to another. eg: Car is a class, ToyotaCars derive from Cars class, basic functionalities, data are same, but there can be more data and functionalities." << std::endl
                  << "4. Polymorphism - Same thing in different forms can exist. eg: Car can exist in form of Toyota, Safari, etc. Browser - Chrome, Safari, etc, A man can be a father, husband, brother, son at same time" << std::endl;
    }

    void ClassesAndObjects::ShowCaseClassesVsObjects()
    {
        std::cout << "Objects: The entities having properties and belonging to a class." << std::endl
                  << "Class:   The entites that have similar proterties can be classified into a class" << std::endl
                  << "A class can have multiple objects but an object have only one class" << std::endl;

        std::cout << "To declare a class:" << std::endl
                  << "class <class-name>" << std::endl
                  << "{" << std::endl
                  << "....<members of the class>" << std::endl
                  << "};" << std::endl;

        std::cout << "Rectangle is a class with data and fuunctions related to a rectangle. We create an object of rectangle by" << std::endl
                  << "Rectangle <object-name> OR " << std::endl
                  << "Rectangle* <pointer-variable-name> = new Rectangle" << std::endl;
    }

    void ClassesAndObjects::ShowCaseAccessorsAndMutators()
    {
        rectangle::Rectangle rectangleObject {};
        rectangleObject.SetLength(10U);
        rectangleObject.SetBreadth(5U);
        std::cout << "We set the Length and Breadth of Rectangle Object on the stack through Mutator Functions, SetLength (unsigned int) and SetBreadth (unsigned int)" << std::endl
                  << "We access the Length and Breadth through the Accessor functions, GetLength() and GetBreadth()." << std::endl
                  << "The class has other functions such as GetArea() which will calculate and return the area of the rectangle object and, similarly for perimeter, we have GetPerimeter()" << std::endl;
        
        std::cout << "The length of the rectangle object on stack is: " << rectangleObject.GetLength() << std::endl
                  << "The breadth of the rectangle object on stack is: " << rectangleObject.GetBreadth() << std::endl
                  << "The area of the rectangle object on stack is: " << rectangleObject.GetArea() << std::endl
                  << "The perimeter of the rectangle object on stack is: " << rectangleObject.GetPerimeter() << std::endl;

        std::cout << "Now we create the rectangle object on heap" << std::endl;
        rectangle::Rectangle* rectangleObjectPointer = new rectangle::Rectangle;
        rectangleObjectPointer->SetLength(8U);
        rectangleObjectPointer->SetBreadth(4U);
        std::cout << "The length of the rectangle object on heap is: " << rectangleObjectPointer->GetLength() << std::endl
                  << "The breadth of the rectangle object on heap is: " << rectangleObjectPointer->GetBreadth() << std::endl
                  << "The area of the rectangle object on heap is: " << rectangleObjectPointer->GetArea() << std::endl
                  << "The perimeter of the rectangle object on heap is: " << rectangleObjectPointer->GetPerimeter() << std::endl;
        
        std::cout << "We should delete the rectangleObjectPointerObject we created on heap" << std::endl;
        delete rectangleObjectPointer;
        rectangleObjectPointer = nullptr;
    }

    void ClassesAndObjects::ShowCaseConstructors()
    {
        std::cout << "Constructors for classes are called when the class object is created. "
                     "Philosophically, if you buy a car, it has a properties like shape, color, length and etc. So an object should have properties at the time of its creation too" << std::endl
                  << "To define a constructor:" << std::endl
                  << "class ExampleClass" << std::endl
                  << "{" << std::endl
                  << "public:" << std::endl
                  << "....ExampleClass(<optional-arguments>) {<body-of-constructor>}" << std::endl
                  << "};" << std::endl
                  << "There are four types of constructors:" << std::endl
                  << "1. Default Constructors - Provided by the compiler" << std::endl
                  << "2. Parameterized Constructors - The constructors which expects an argument" << std::endl
                  << "3. Non-parameterized Constructors - The constructors which does not expects an argument" << std::endl
                  << "4. Copy Constructors - These are used to make a copy of an object" << std::endl;
    }

    void ClassesAndObjects::ShowCaseDefaultConstructors()
    {
        std::cout << "Default Constructors are provided by the compiler by default. If your class has no constructor, compiler will provide a default constructor that will not do anything." << std::endl;
    }

    void ClassesAndObjects::ShowCaseNonParameterizedConstructors()
    {
        std::cout << "Non-parameterized constructors are the ones which does not expect any argument." << std::endl
                  << "Here, we make rectangle object using a non-parameterized constructor" << std::endl;
        rectangle::Rectangle rectangleObj;
    }

    void ClassesAndObjects::ShowCaseParameterizedConstructors(int length, int breadth)
    {
        std::cout << "Parameterized constructors are the ones which expects an argument. We can always combine parameterized and non-parameterized constructors by" << std::endl
                  << "having default arguments in the Parameterized Constructors" << std::endl
                  << "Here, we make rectangle object using a parameterized constructor" << std::endl;
        rectangle::Rectangle rectangleObj (length, breadth);
    }

    void ClassesAndObjects::ShowCaseCopyConstructors(int length, int breadth)
    {
        std::cout << "If we want to copy an object to another object, we cannot do so by using the assignment (=) operator unless its overloaded" << std::endl
                  << "Hence copy constructor is useful" << std::endl
                  << "To write a copy constructor:" << std::endl
                  << "ClassName(ClassName& obj) {<copy-contents-of-obj-to-the-target-class-object>}" << std::endl;

        rectangle::Rectangle sourceRectangleObj;
        sourceRectangleObj.SetLength(length);
        sourceRectangleObj.SetBreadth(breadth);
        std::cout << "The area and perimeter of the source Rectangle Object is: " << sourceRectangleObj.GetArea() << " & " << sourceRectangleObj.GetPerimeter() << std::endl;

        std::cout << "Now we make a target Rectangle Object using the copy constructor and make a copy of source Rectangle" << std::endl;

        rectangle::Rectangle targetRectangleObj(sourceRectangleObj);
        std::cout << "The area and perimeter of the target Rectangle Object is: " << targetRectangleObj.GetArea() << " & " << targetRectangleObj.GetPerimeter() << std::endl;
    }

    void ClassesAndObjects::ShowCaseDeepCopyConstructors()
    {
        std::cout << "Copy constructors work fine if the class does not have a member pointer. But if the class is having a member pointer, normal copy constructor won't work." << std::endl
                  << "eg:" << std::endl
                  << "If a class A is having a member pointer and in the copy constructor, we simply do, this.ptr = sourceObj.ptr, both the pointers are pointing to one memory location which is wrong" << std::endl
                  << "To solve issues like these, we have deep copy constructors where we reserve a new memory location, copy the contents and point the appropriate pointer to it" << std::endl;

        class DeepCopyConstructor
        {
        private:
            int  m_data { 0 };
            int* m_ptr = nullptr;
        public:
            DeepCopyConstructor() = default;

            DeepCopyConstructor(DeepCopyConstructor& sourceObj)
            {
                m_data = sourceObj.m_data;
                m_ptr = new int[5];
                std::cout << "Copying the member pointer data to the target object" << std::endl;
                for (int i = 0; i < 5; i++)
                {
                    m_ptr[i] = sourceObj.m_ptr[i];
                }
            }

            void InitializeAndFillArrayUpto5()
            {
                std::cout << "Initializing array" << std::endl;
                m_ptr = new int[5];
                for (int i = 0; i < 5; i++)
                {
                    m_ptr[i] = i + 1;
                }

                std::cout << "Displaying the array to which member pointer points to: ";
                for (int i = 0; i < 5; i++)
                {
                    std::cout << i << " ";
                    if (i == 5 - 1)
                    {
                        std::cout << std::endl;
                    }
                }
            }

            void SetData(int data)
            {
                std::cout << "Setting data" << std::endl;
                m_data = data;
            }

            void Display() const
            {
                std::cout << "The data is: " << m_data << std::endl;
                std::cout << "The array is: ";
                for (int i = 0; i < 5; i++)
                {
                    std::cout << i << " ";
                    if (i == 5 - 1)
                    {
                        std::cout << std::endl;
                    }
                }
            }
        };

        DeepCopyConstructor source;
        source.SetData(10);
        source.InitializeAndFillArrayUpto5();
        source.Display();
        
        std::cout << "Source Object is made and data and array is set and displayed" << std::endl;

        std::cout << "Creating target object and calling the copy constructor on that one!" << std::endl;

        DeepCopyConstructor target(source);
        std::cout << "Displaying target data and array without actually setting the data and array for target object" << std::endl;
        target.Display();
    }

    void ClassesAndObjects::ShowCaseTypesOfFunctionsInAClass()
    {
        std::cout << "There can be various types of functions present in a class namely:" << std::endl
                  << "1. Constructors: We have already seen this one" << std::endl
                  << "2. Mutators: We have already seen this one" << std::endl
                  << "3. Accessors: We have already seen this one" << std::endl
                  << "4. Facilitators: These are the functions that returns some sort of calculations / analysis on the class data. eg: area(), perimeter()" << std::endl
                  << "5. Introspecting / Enquiring: These are the functions which give boolean output, whether a value / field is true or false. eg: isEmpty(), isFull()" << std::endl
                  << "6. Destructors: This is called when an object is destroyed. We will see this later" << std::endl;
    }

    void ClassesAndObjects::ShowCaseThisPointer()
    {
        std::cout << "'this' is a pointer to the particular object for which the member function is being called" << std::endl
                  << "eg:" << std::endl
                  << "Rectangle (int length, int breadth) // given that length and breadth are the member varialbes of the Rectangle class" << std::endl
                  << "{"
                  << "....length = length // is ambiguous and won't work" << std::endl
                  << "....this.length  = length;" << std::endl
                  << "....this.breadth = breadth;" << std::endl
                  << "}" << std::endl;
    }

    void ClassesAndObjects::ShowCaseStructVsClass()
    {
        std::cout << "There are only 2 difference between a struct and a class:" << std::endl
                  << "1. In C, structs can only have member variables while in C++, structs can have both member variables and member functions" << std::endl
                  << "2. The default access specifier in class is private while in struct is public" << std::endl;
    }

    void ClassesAndObjects::ShowCaseOperatorOverloading()
    {
        std::cout << "If we wish to add two objects of a class, we cannot simply add them. We need to overload the '+' operator or write a function to add two objects" << std::endl
                  << "eg. If we have a class for complex numbers and we wish to add two complex numbers, we cannot simply add using the '+' operator" << std::endl;

        complex::Complex comp1(10, 5);
        complex::Complex comp2(2, 3);

        std::cout << "Complex number 1 is: ";
        comp1.Display();
        std::cout << "Complex number 2 is: ";
        comp2.Display();

        std::cout << "To add these two complex numbers, we have 2 methods inside of Complex class:" << std::endl
                  << "1. Add(Complex&) method that adds the complex number in argument to the complex number through which it has been called and returns the result complex number" << std::endl
                  << "2. Overloaded '+' operator that does the same in two ways:" << std::endl
                  << "....a. comp3 = comp1.operator+(comp2);" << std::endl
                  << "....b. comp3 = comp1 + comp4;" << std::endl;

        std::cout << "To overload the + operator for a complex class:" << std::endl
                  << "Complex Complex::operator+(Complex &comp)" << std::endl
                  << "{" << std::endl
                  << "....Complex temp(0, 0);" << std::endl
                  << "....temp.m_real = this->m_real + comp.GetReal();" << std::endl
                  << "....temp.m_img  = this->m_img  + comp.GetImg();" << std::endl
                  << "....return temp;" << std::endl
                  << "}" << std::endl;

        std::cout << "The sum of two complex numbers is using comp1.Add(comp2): ";
        (comp1.Add(comp2)).Display();
        std::cout << std::endl;

        std::cout << "The sum of two complex numbers is (using comp1.operator+(comp2)): ";
        (comp1.operator+(comp2)).Display();
        std::cout << std::endl;

        std::cout << "The sum of two complex numbers is (using (comp1 + comp2 which is same as comp1.operator+(comp2))): ";
        (comp1 + comp2).Display();
        std::cout << std::endl;
    }

    void ClassesAndObjects::ShowCaseOperatorOverloadingWithFriendFunction()
    {
        std::cout << "We can also define operator overloading using the friend function" << std::endl
                  << "The advantage is that one object is not performing operation on the other one. It is another function performing operation on two different objects of the complex class" << std::endl
                  << "friend functions can access the private members of the class and they cannot be inline" << std::endl;

        complex::Complex comp1(10, 5);
        complex::Complex comp2(2, 3);

        std::cout << "Complex number 1 is: ";
        comp1.Display();
        std::cout << "Complex number 2 is: ";
        comp2.Display();

        std::cout << "To overload the - operator for a complex class using friend function (friend function cannot be inline, should be declared friend at the time of declaration):" << std::endl
                  << "Complex operator-(Complex &comp1, Complex &comp2)" << std::endl
                  << "{" << std::endl
                  << "....Complex temp(0, 0);" << std::endl
                  << "....temp.m_real = comp1.m_real - comp2.GetReal();" << std::endl
                  << "....temp.m_img  = comp1.m_img  - comp2.GetImg();" << std::endl
                  << "....return temp;" << std::endl
                  << "}" << std::endl;

        std::cout << "The subtraction operator has been overloaded using friend function" << std::endl;

        std::cout << "The subtraction of the two complex numbers is (using comp1 - comp2):";
        (comp1 - comp2).Display();
        std::cout << std::endl;

        std::cout << "We cannot use comp1.operator-(comp2) here because it is a friend function and any object cannot call friend function" << std::endl;
    }

    void ClassesAndObjects::ShowCaseOverloadingInsertionAndExtractionOperator()
    {
        std::cout << "We can also overload Insertion and Extraction operators in C++ to input or print the members of a class" << std::endl
                  << "To print the output on the screen, we need ostream object as well as the object for class for which we want to overload the insertion operator" << std::endl
                  << "Hence, we cannot make this overloaded insertion or extraction operator as the member of the class, we have to make it friend of class" << std::endl
                  << "eg:" << std::endl
                  << "ostream& operator<<(ostream &o, Complex &c)" << std::endl
                  << "{" << std::endl
                  << "....o << c.real << '+' << c.img << 'i' << std::endl;" << std::endl
                  << "....return 0;"
                  << "}" << std::endl
                  << "The insertion operator have been overloaded for the Complex class" << std::endl;

        complex::Complex C(10, 10);
        std::cout << "This is being printed through the overloaded insertion operator of Complex Class: " << C << std::endl;
    }

    void ClassesAndObjects::ShowCaseInheritance()
    {
        std::cout << "If we want to borrow the properties of one class to another, we can make use of Inheritance" << std::endl
                  << "If there is a Rectangle class having properties such as length, breadth, GetArea(), GetPerimeter(), a cuboid is a rectangle" << std::endl
                  << "a cuboid also have the property surface area, length, breadth and added height and GetVolume()" << std::endl;

        std::cout << "Cuboid class" << std::endl
                  << "class Cuboid : public Rectangle" << std::endl
                  << "{" << std::endl
                  << "private:" << std::endl
                  << "....unsigned int m_height { 0 };" << std::endl
                  << "public:" << std::endl
                  << "....Cuboid (unsigned int length, unsigned int breadth, unsigned int height) : m_height (height) { std::cout << 'Parameterized constructor of Cuboid' << std::endl; }" << std::endl
                  << "....void SetHeight(unsigned int height) { m_height = height; }" << std::endl
                  << "....unsigned int GetHeight() { return m_height; }" << std::endl
                  << "....unsigned int GetVolume() { return m_height * GetArea(); }" << std::endl
                  << "};" << std::endl;

        rectangle::Cuboid cuboidObj(5, 10, 8);
        std::cout << "The cuboid does not have length and breadth but as it is deriving from rectangle, it will have length as well as breadth and also its methods" << std::endl;

        std::cout << "The length, breadth and height of the Cuboid are: " << cuboidObj.GetLength() << " " << cuboidObj.GetBreadth() << " " << cuboidObj.GetHeight() << std::endl
                  << "The volume of the cuboid is: " << cuboidObj.GetVolume() << std::endl;
    }

    void ClassesAndObjects::ShowCaseConstructorsInInheritance()
    {
        std::cout << "If a class is inheriting from another class, the base class constructor is called before calling the derived class constructor" << std::endl;

        rectangle::Cuboid cuboidObj(10, 50, 20);

        std::cout << "As it is visible, the base class constructor is called before the derived class constructor" << std::endl
                  << "But this will call the non-parameterized constructor of the Base class that is the Rectangle class" << std::endl
                  << "To call the parameterized constructor of the Rectangle class, the constructor of the cuboid class needs to be changed in this way" << std::endl
                  << "Cuboid (unsigned int length, unsigned int breadth, unsigned int length) : Rectangle (length, breadth) {}" << std::endl;
    }

    void ClassesAndObjects::ShowCaseAccessSpecifiers()
    {
        std::cout << "There are 3 access specifiers present in C++ class:" << std::endl   
                  << "1. private (default)" << std::endl
                  << "2. protected" << std::endl
                  << "3. public" << std::endl;

        std::cout << "All members are accessible in the class itself be it public, private, protected" << std::endl;

        std::cout << "An object of a class can only access the public members of the class" << std::endl;

        std::cout << "Only public and protected members of the base class are accessible from the derived class" << std::endl;
    }

    void ClassesAndObjects::ShowCaseTypesOfInteritance()
    {
        std::cout << "There are 5 types of inheritance in C++:" << std::endl
                  << "1. Single Inheritance: One class deriving from a base class. eg: Rectangle <- Cuboid" << std::endl
                  << "2. Heirarchial Inheritance: Multiple classes deriving from a single base class. eg: Shape <- Rectangle, Square, Circle" << std::endl
                  << "3. Multi Level Inheritance: One class deriving from base class and another class is derived from the already derived class. eg: Point <- Circle <- Cylinder" << std::endl
                  << "4. Multiple Inheritance: A class inherited from two or more base classes. eg: Phone, Camera <- Smartphone" << std::endl
                  << "5. Hybrid Inheritance: Mix and match. eg: Phone, Camera <- Smartphone" << std::endl;

        std::cout << "A special type of hybrid inheritance causes the diamond problem. eg: A <- B, C <- D" << std::endl
                  << "Now, D will have properties of A from B and from C both so there'll be ambiguity. so B and C should inherited from A using virtual." << std::endl;
    }

    void ClassesAndObjects::ShowCaseWaysOfInheritance()
    {
        std::cout << "A class can inherit in 3 ways:" << std::endl
                  << "1. private (default)" << std::endl
                  << "2. protected" << std::endl
                  << "3. public" << std::endl
                  << "These access specifiers (ways of inheriting) won't affect the child class in any way but it will affect the grandchild class" << std::endl;

        std::cout << "Rules:" << std::endl
                  << "1. If (Child: private Parent), public and protected members of the Parent are inherited into the private members of Child. GrandChild class cannot access these members directly with any inheritance type from Child" << std::endl
                  << "2. If(Child: protected Parent), public and protected members of the Parent are inherited into the protected members of Child. GrandChild class can access these members" << std::endl
                  << "3. If(Child: public Parent), public and protected members of the Parent are inherited into the public and protected members of Child respectively. GrandChild class can access these members" << std::endl;
    }

    void ClassesAndObjects::ShowCaseGeneralizationVsSpecialization()
    {
        std::cout << "Generalization is a term used for top-down approach" << std::endl 
                  << "There is a Creta, Innova, Swift class and there is a Car class, all Creta, Innova, Swift class are derived from the Car class" << std::endl
                  << "eg: Fortuner is a spc Innova" << std::endl;

        std::cout << "Specialization is a term used for bottom-up approach" << std::endl 
                  << "There is a Rectangle class and a Cuboid class which derives from the Rectangle class so Cuboid is a specialized Rectangle" << std::endl
                  << "eg: We have classes Rectangle, Circle, etc we generalized them into Shape class" << std::endl;
    }

    void ClassesAndObjects::ShowCaseBaseClassPointerDerivedClassObject()
    {
        std::cout << "A base class pointer can point to a derived class object but not the vice versa" << std::endl
                  << "class BasicCar" << std::endl
                  << "{" << std::endl
                  << "public:" << std::endl
                  << "....Start();" << std::endl
                  << "};" << std::endl
                  << "class AdvancedCar: public BasicCar" << std::endl
                  << "{" << std::endl
                  << "public:" << std::endl
                  << "....PlayMusic();" << std::endl
                  << "};" << std::endl;

        std::cout << "In the above example, if we create objects like this:" << std::endl
                  << "....BasicCar *bptr = new AdvancedCar();" << std::endl
                  << "we can use bptr to only calll methods of the BasicCar as the pointer is aware of only those methods" << std::endl
                  << "AdvancedCar is a specialized BasicCar so all the methods of BasicCar will work for AdvancedCar but not vice versa" << std::endl;
    }

    void ClassesAndObjects::ShowCasePolymorphism()
    {
        std::cout << "The Rectangle class and the Cuboid class both have Display() methods in them which prints which class is it being called from" << std::endl
                  << "We have overrided the Display function in the derived class here so that would be called from the derived object" << std::endl
                  << "if was not overrided, would have called the Display of the base class" << std::endl
                  << "To call the display of the base method, we need to do, derivedClassObj.Parent::Display();" << std::endl;
       
        rectangle::Rectangle rectobj(10, 20);
        rectangle::Cuboid    cuboidObj(10, 20, 30);

        std::cout << "Calling the Display() for both the Rectangle and Cuboid Objects" << std::endl;
        rectobj.Display();
        cuboidObj.Display();
    }

    void ClassesAndObjects::ShowCaseVirtualFunctions()
    {
        std::cout << "If we have a Rectangle pointer pointing to Cuboid Object and we call Display of it, it will call Rectangle's display" << std::endl
                  << "but psychologically, the object is still a Cuboid and Display should work that way only, so we can do that by making the Rectangle Display as virtual" << std::endl;

        rectangle::Rectangle* bptr = new rectangle::Cuboid(10, 20, 30);

        std::cout << "Calling the Display() for Rectangle pointer pointing towards a Cuboid object" << std::endl;
        bptr->Display();
    }

    void ClassesAndObjects::ShowCaseRuntimePolymorphism()
    {
        std::cout << "If there is a generalized class with some functions and we used it to derive classes from it, we are not going to use the base class definitions" << std::endl
                  << "Every derived class will have a specialized method for itself which would be called" << std::endl
                  << "So, a base class ptr can point to different derived objects at runtime and call their particular methods. This is run time polymorphism" << std::endl;
    }

    void ClassesAndObjects::ShowCasePureVirtualFunctions()
    {
        std::cout << "If we are overriding every member function of the base class in the derived class, we won't be using the base class functions so no need for body of them and we may as well make them virtual" << std::endl
                  << "But if some derived class does not implement their functions, it will fail, so we should make it mandatory by making the virtual functions -> pure virtual functions" << std::endl
                  << "To do so, ....virtual void Display() = 0;" << std::endl;

        car::ICar* bptr = 0;
        car::Innova innovaObj;
        car::Swift  swiftObj;
        
        std::cout << "Using base class pointer to call Start() and Stop() for Innova Car" << std::endl;
        bptr = &innovaObj;
        bptr->Start();
        bptr->Stop();

        std::cout << "Now pointing the same Car pointer to a Swift Car and using that pointer to call Start() and Stop() for Swift Car" << std::endl;
        bptr = &swiftObj;
        bptr->Start();
        bptr->Stop();
    }

    void ClassesAndObjects::ShowCaseAbstractClasses()
    {
        std::cout << "There are three types of classes in C++ based on whether it has concrete functions or virtual functions" << std::endl
                  << "1. Only have concrete functions - suitable for reusability and not polymorphism" << std::endl
                  << "2. Have concrete functions as well as virtual functions - suitable for reusability and polymorphism" << std::endl
                  << "3. Only have virtual functions - not suitable for reusability but suitable for polymorphism" << std::endl
                  << "2 & 3 are called abstract classes and 3 is also called an Interface. An object cannot be created for an Interface" << std::endl;
    }

    void ClassesAndObjects::ShowCaseFriendFunctionAndClasses()
    {
        std::cout << "If there needs to be a functions that can access all the members of a class be it private, protected or public, we can use a friend function" << std::endl
                  << "Friend functions are mostly used for operator overloading" << std::endl;

        std::cout << "If we want to access all members of a class inside other class we can inherit or otherwise make the class as friend class" << std::endl
                  << "class Your; // forward declaration" << std::endl
                  << "class My" << std::endl
                  << "{" << std::endl
                  << "....int a;" << std::endl
                  << "....friend Your;" << std::endl
                  << "};" << std::endl
                  << "class Your" << std::endl
                  << "{" << std::endl
                  << "public:" << std::endl
                  << "....My my;" << std::endl
                  << "....void func() { std::cout << my.a << std::endl; }" << std::endl
                  << "};" << std::endl;
    }

    void ClassesAndObjects::ShowCaseStaticMembers()
    {
        std::cout << "Static members belong to a class and all of its objects. It is shared among all the objects of that class and the static members reside in the code section of memory" << std::endl
                  << "class Test" << std::endl
                  << "{" << std::endl
                  << "private:" << std::endl
                  << "....int a;" << std::endl
                  << "....int b;" << std::endl
                  << "public:" << std::endl
                  << "....static int count;" << std::endl
                  << "....Test()" << std::endl
                  << "....{" << std::endl
                  << "........a = 10;" << std::endl
                  << "........b = 20;" << std::endl
                  << "........count++;" << std::endl
                  << "....}" << std::endl
                  << "....static int getCount()" << std::endl
                  << "....{" << std::endl
                  << "........return count; // static member functions can only access static members" << std::endl
                  << "....}" << std::endl
                  << "};" << std::endl
                  << "int Test::count = 0; // Important, declaring count as global but only accessible to Test class" << std::endl;

        std::cout << "If we create objects of Test class, we can access the count as:" << std::endl
                  << "Test t1, t2;" << std::endl
                  << "t1.count;" << std::endl
                  << "t2.count;" << std::endl
                  << "T.count;" << std::endl
                  << "t1.getCount();" << std::endl
                  << "t2.getCount();" << std::endl
                  << "T.getCount();" << std::endl;

        std::cout << "Other example can be setting the price of Innova as static" << std::endl
                  << "Innova innovaObj; // innova bought and we can check the price by innovaObj.price;" << std::endl
                  << "but there should be a way to check innova price before buying it also" << std::endl
                  << "so we can also do, Innova.price()" << std::endl
                  << "static members are used as counters or shared memory across objects such as admission, scholar number and stuff" << std::endl;
    }

    void ClassesAndObjects::ShowCaseNestedClass()
    {
        std::cout << "Nested classes are classes declared inside other classes. It is done when there's no need for the inner class to be present outside the outer class" << std::endl
                  << "class Outer" << std::endl
                  << "{" << std::endl
                  << "public:" << std::endl
                  << "....int a;" << std::endl
                  << "....static int b;" << std::endl
                  << "....class Inner" << std::endl
                  << "....{" << std::endl
                  << "....public:" << std::endl
                  << "........int x;" << std::endl
                  << "........void show()" << std::endl
                  << "........{" << std::endl
                  << "............cout << x or b; //only static members accessible here" << std::endl
                  << "........}" << std::endl
                  << "....};" << std::endl
                  << "....Inner i;" << std::endl
                  << "....i.x;" << std::endl
                  << "....i.show();" << std::endl
                  << "};" << std::endl
                  << "Another place where this might be needed is a LinkedList" << std::endl;
    }

    void ClassesAndObjects::ShowCaseExceptionHandling()
    {
        std::cout << "There are 3 types of errors:" << std::endl
                  << "1. Syntax Errors: Compiler helps in resolving these" << std::endl
                  << "2. Logical Errors: Debugger helps in resolving these" << std::endl
                  << "3. Runtime Errors: User causes these but it is our responsibility to solve these. It can be due to unavailability of resources or bad input and cause program to crash" << std::endl
                  << "We throw an exception in the 3rd case to help the user solve the program and not crash the program" << std::endl;

        std::cout << "try and catch block is used for this" << std::endl
                  << "int a, b;" << std::endl
                  << "cin >> a >> b;" << std::endl
                  << "try :" << std::endl
                  << "{" << std::endl
                  << "....if (b == 0) throw 1;" << std::endl
                  << "....cout << a / b;" << std::endl
                  << "}" << std::endl
                  << "catch (int ex)" << std::endl
                  << "{" << std::endl
                  << "....if (ex == 1) cout << 'Div by zero'; << endl" << std::endl
                  << "}" << std::endl
                  << "Error codes can also be thrown which means different types of errors" << std::endl;
    }

    void ClassesAndObjects::ShowCaseExceptionHandlingMultiCatchAndEpsilon()
    {
        std::cout << "Even a function can throw an exception:" << std::endl 
                  << "int division(int a, int b)" << std::endl
                  << "{" << std::endl
                  << "....if (b == 0) throw 1;" << std::endl
                  << "....return a / b;" << std::endl
                  << "}" << std::endl
                  << "to use it: " << std::endl 
                  << "try :" << std::endl
                  << "{" << std::endl
                  << "....int c = division(a, b);" << std::endl
                  << "....cout << c;" << std::endl
                  << "}" << std::endl
                  << "catch (int ex)" << std::endl
                  << "{" << std::endl
                  << "....if (ex == 1) cout << 'Div by zero'; << endl" << std::endl
                  << "}" << std::endl;

        std::cout << "A function can throw any data type even classes" << std::endl
                  << "int division(int a, int b) throw(int) {}" << std::endl
                  << "int division(int a, int b) throw(float) {}" << std::endl
                  << "int division(int a, int b) throw(class) {}" << std::endl
                  << "int division(int a, int b) throw() // should throw nothing {}" << std::endl;

        std::cout << "There can be multiple throw and catch blocks present:" << std::endl
                  << "try:" << std::endl
                  << "{" << std::endl
                  << "....throw <int>;" << std::endl
                  << "....throw <float>;" << std::endl
                  << "....throw <class>;" << std::endl
                  << "....and many more;" << std::endl
                  << "}" << std::endl
                  << "catch(int e) {}" << std::endl
                  << "catch(float e) {}" << std::endl
                  << "catch(class e) {}" << std::endl
                  << "catch(...) {} // epsilon, will catch all exception types" << std::endl;

        std::cout << "Scenarios for epsilon:" << std::endl
                  << "1. int thrown and catch(int) present before catch(...) - handle by catch(int)" << std::endl
                  << "2. int thrown and catch(int) not present but catch(...) present - handle by catch(...)" << std::endl
                  << "3. int thrown and catch(int) present but catch(...) not present- handle by catch(int)" << std::endl
                  << "4. int thrown and catch(...) present before catch(int) - handle by catch(...)" << std::endl
                  << "catch(...) should be the last block" << std::endl;
        
        std::cout << "To throw a class as an exception, we can write our own Exception class or derive from in-built exception class and override the what method of the exception class" << std::endl;
    }

    void ClassesAndObjects::ShowCaseExceptionHandlingInheritance()
    {
        std::cout << "If an exception class derives from another exception class, we should place the catch blocks in order of their derivation" << std::endl
                  << "class MyException1 {};" << std::endl
                  << "class MyException2: public MyException1 {};" << std::endl
                  << "try: {}" << std::endl
                  << "catch(MyException1) // will handle all exceptions of all the derived classes as well so this is wrong" << std::endl
                  << "catch(MyException2) {} catch(MyException1) {}  // base class exception should be last one" << std::endl;
    }

    void ClassesAndObjects::ShowCaseTemplateFunctionsAndClasses()
    {
        std::cout << "Template functions and classes are used for generalization" << std::endl
                  << "for templates: " << std::endl
                  << "template <typename T or class T>" << std::endl
                  << "T maximum(T a, T b) { return a > b ? a : b; }"
                  << "This template will work for any data type as long as it has a valid '>' operator" << std::endl;

        std::cout << "We can also define template classes. eg: A stack class which can be used for any data type" << std::endl
                  << "template <class T>"
                  << "class Stack" << std::endl
                  << "{" << std::endl
                  << "private:" << std::endl
                  << "....T S[10];" << std::endl
                  << "....int top;" << std::endl
                  << "public:" << std::endl
                  << "....void push(T);" << std::endl
                  << "....T pop()" << std::endl
                  << "};" << std::endl
                  << "template <class T>" << std::endl
                  << "void Stack<T>::push(T a) {}" << std::endl;
    }

    void ClassesAndObjects::ShowCaseConstants()
    {
        std::cout << "const identifier is used when we do not want the value of a variable to change" << std::endl
                  << "const int a = 10;" << std::endl  
                  << "a++, a--, a = 20;  is not allowed now, compiler will throw error that it is a const" << std::endl;
    }

    void ClassesAndObjects::ShowCasePointerToAConstant()
    {
        std::cout << "Pointer to a constant means that the pointer cannot modify the value where it points to but can point to a different address. It is declared as:" << std::endl
                  << "const int *p = &a; OR int const *p = &a;" << std::endl
                  << "++(*p); // not allowed" << std::endl
                  << "p = &y; // allowed" << std::endl
                  << "++(*p); // still not allowed" << std::endl;
    }

    void ClassesAndObjects::ShowCaseConstantPointer()
    {
        std::cout << "Constant pointer means that the pointer cannot point to some other memory address but it can modify the value where it points to. It is declared as:" << std::endl
                  << "int *const p = &a;" << std::endl
                  << "++(*p); // allowed" << std::endl
                  << "p = &y; // not allowed" << std::endl;
    }

    void ClassesAndObjects::ShowCaseConstantPointerToAConstant()
    {
        std::cout << "Constant pointer to a constant means that the pointer cannot modify the value where it points to and also cannot point to any other address. It is declared as:" << std::endl
                  << "const int *const ptr = &a;" << std::endl
                  << "++(*ptr); // not allowed" << std::endl
                  << "ptr = &y; // not allowed" << std::endl;
    }

    void ClassesAndObjects::ShowCaseConstantIdentifierForFunctions()
    {
        std::cout << "If we do not want a function to modify its arguments, we can use this:" << std::endl
                  << "int add (const int& a, const int& b)" << std::endl
                  << "{" << std::endl
                  << "....a++; b++; // not allowed to modify the values" << std::endl
                  << "....return a + b;" << std::endl
                  << "}" << std::endl;
    }

    void ClassesAndObjects::ShowCaseConstantIdentifierForMemberFunction()
    {
        std::cout << "If we don't want a member function to modify the data members of a class, we can make the method const:" << std::endl
                  << "class Test" << std::endl
                  << "{" << std::endl
                  << "private:" << std::endl
                  << "....int x = 10;" << std::endl
                  << "public:" << std::endl
                  << "....void Display() const" << std::endl
                  << "....{" << std::endl
                  << "........x++; // not allowed" << std::endl
                  << "........cout << x << endl;" << std::endl
                  << "....}" << std::endl
                  << "};" << std::endl;
    }

    void ClassesAndObjects::ShowCaseMacros()
    {
        std::cout << "These are symbolic constants given to the compiler and the compiler replaces them with the meaning before compilation" << std::endl
                  << "# define PI 3.14 // replace PI with 3.14 anywhere in program" << std::endl
                  << "# define SQR(x) x*x // replace SQ(R(x) with x*x anywhere in program" << std::endl
                  << "# define MSG(x) #x // replace MSG(x) with \"x\" anywhere in program" << std::endl
                  << "#ifndef // if not defined" << std::endl
                  << "....# define PI 3.14 // if not defined" << std::endl
                  << "#endif" << std::endl;
    }

    void ClassesAndObjects::ShowCaseNamespaces()
    {
        std::cout << "If we want to use the same name for functions in different context, then we can make use of namespaces" << std::endl
                  << "namespace first" << std::endl
                  << "{" << std::endl
                  << "....void fun() {}" << std::endl
                  << "}" << std::endl
                  << "namespace second" << std::endl
                  << "{" << std::endl
                  << "....void fun() {}" << std::endl
                  << "}" << std::endl;

        std::cout << "To use them:" << std::endl
                  << "first::fun(); // will call fun() from first namespace" << std::endl
                  << "second::fun(); // will call fun() from second namespace" << std::endl
                  << "if we want to use one namespace throughout the program:" << std::endl
                  << "using namespace first;" << std::endl
                  << "now if we call fun() it will call fun() for first namespace" << std::endl
                  << "to call fun() from second namespace, second::fun()" << std::endl;
    }

    void ClassesAndObjects::ShowCaseDestructors()
    {
        std::cout << "As constructors are called when an object is created, destructors are called when an object is destroyed which is usually at the end of the program" << std::endl
                  << "A destructor cannot be overloaded and does not take any arguments" << std::endl
                  << "~<class-name>() {} // this is how a destructor is declared" << std::endl;
    }

    void ClassesAndObjects::ShowCaseDestructorsHeapObject()
    {
        std::cout << "If an object is made using the new operator, we should call the delete for that object also and that is when the object gets destroyed and the destructor gets called" << std::endl;

        class Test
        {
        public:
            Test()  { std::cout << "Test class Constructor called" << std::endl; }
            ~Test() { std::cout << "Test class Destructor called" << std::endl; }
        };

        Test *testObj = new Test();
        delete testObj;
    }

    void ClassesAndObjects::ShowCaseBaseClassPointerDerivedClassObjectDestructorProblem()
    {
        std::cout << "When there is destructor present in inheritance, the destructors are called in the opposite manner as the constructors are called" << std::endl
                  << "class Base" << std::endl
                  << "{" << std::endl
                  << "public:" << std::endl
                  << "....Base()  { std::cout << \"Base Constructor Called\" << std::endl }" << std::endl
                  << "....~Base() { std::cout << \"Base Destructor Called\" << std::endl }" << std::endl
                  << "};" << std::endl
                  << "class Derived: public Base" << std::endl
                  << "{" << std::endl
                  << "public:" << std::endl
                  << "....Derived()  { std::cout << \"Derived Constructor Called\" << std::endl }" << std::endl
                  << "....~Derived() { std::cout << \"Derived Destructor Called\" << std::endl }" << std::endl
                  << "};" << std::endl
                  << "Derived d; // base constructor -> derived constructor -> derived destructor -> base destructor" << std::endl;

        class Base
        {
        public:
            Base() { std::cout << "Base Constructor called" << std::endl; }
            virtual ~Base() { std::cout << "Base Destructor called" << std::endl; }
        };

        class Derived: public Base
        {
        public:
            Derived() { std::cout << "Derived Constructor called" << std::endl; }
            ~Derived() { std::cout << "Derived Destructor called" << std::endl; }
        };

        std::cout << "Creating and destroying derived class object" << std::endl;

        Derived *derivedObj = new Derived;
        delete derivedObj;

        std::cout << "But if there is a situation where the base class pointer points to the derived class object, when the derived class object is deleted: " << std::endl
                  << "base constructor -> derived constructor -> base destructor" << std::endl
                  << "the base class pointer cannot call derived class destructor hence derived object is not deleted" << std::endl
                  << "to solve this issue, we have to make the base class destructor as virtual" << std::endl;

        Base* bptr = new Derived;
        delete bptr;
    }        
} // namespace classesAndObjects
