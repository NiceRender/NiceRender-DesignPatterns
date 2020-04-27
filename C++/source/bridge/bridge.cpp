#include <iostream>

// Implementor
class UiElementImp
{
    public:
        virtual ~UiElementImp();
        virtual void displayImp() = 0;
};

UiElementImp::~UiElementImp() {}

// ConcreteImplementorA
class UiElementWinImp : public UiElementImp
{
    public:
        virtual ~UiElementWinImp();
        void displayImp() { std::cout << "(Windows implementation)"; }
};

UiElementWinImp::~UiElementWinImp() {}

// ConcreteImplementorB
class UiElementMacImp : public UiElementImp
{
    public:
        virtual ~UiElementMacImp();
        void displayImp() { std::cout << "(Mac implementation)"; }
};

UiElementMacImp::~UiElementMacImp() {}

// ConcreteImplementorC
class UiElementLinuxImp : public UiElementImp
{
    public:
        virtual ~UiElementLinuxImp();
        void displayImp() { std::cout << "(Linux implementation)"; }
};

UiElementLinuxImp::~UiElementLinuxImp() {}

// Abstraction
class UiElement
{
    public:
        UiElement(UiElementImp* imp) : m_imp(imp) {}
        virtual ~UiElement();
        virtual void display() = 0;

    protected:
        UiElementImp* m_imp = nullptr;
};

UiElement::~UiElement() {}

// RefinedAbstraction
class Button : public UiElement
{
    public:
        Button(UiElementImp* imp) : UiElement(imp) {}
        virtual ~Button() override;
        void display() override
        {
            std::cout << "I'm button ";
            m_imp->displayImp();
            std::cout << "\n";
        }
};

Button::~Button() {}

int main()
{
    UiElementWinImp impWin;
    UiElementMacImp impMac;
    UiElementLinuxImp impLinux;

    Button winButton(dynamic_cast<UiElementImp*>(&impWin));
    winButton.display();
    Button macButton(dynamic_cast<UiElementImp*>(&impMac));
    macButton.display();
    Button linuxButton(dynamic_cast<UiElementImp*>(&impLinux));
    linuxButton.display();
}
