#include <iostream>
#include <memory>

class Button
{
    public:
        virtual ~Button();
        virtual void draw() = 0;
};

Button::~Button() {}

class WinButton : public Button
{
    public:
        void draw() { std::cout << "I'm win button!" << std::endl; }
};

class MacButton : public Button
{
    public:
        void draw() { std::cout << "I'm mac button!" << std::endl; }
};

class LinuxButton : public Button
{
    public:
        void draw() { std::cout << "I'm linux button!" << std::endl; }
};

class ButtonsFactory
{
    public:
    
        enum Os { WIN, MAC, LINUX };
        
        std::shared_ptr<Button> create(Os os)
        {
            switch (os)
            {
                case WIN:   { return std::make_shared<WinButton>(); }
                case MAC:   { return std::make_shared<MacButton>(); }
                case LINUX: { return std::make_shared<LinuxButton>(); }
            };
            return nullptr;
        }
};

int main()
{
    ButtonsFactory buttonsFactory;
    buttonsFactory.create(ButtonsFactory::Os::WIN)->draw();
    buttonsFactory.create(ButtonsFactory::Os::MAC)->draw();
    buttonsFactory.create(ButtonsFactory::Os::LINUX)->draw();
    return 0;
}
