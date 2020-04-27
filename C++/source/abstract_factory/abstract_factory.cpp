#include <iostream>
#include <string>
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

class Checkbox
{
    public:
        virtual ~Checkbox();
        virtual void draw() = 0;
};

Checkbox::~Checkbox() {}

class WinCheckbox : public Checkbox
{
    public:
        void draw() { std::cout << "I'm win checkbox!" << std::endl; }
};

class MacCheckbox : public Checkbox
{
    public:
        void draw() { std::cout << "I'm mac checkbox!" << std::endl; }
};

class GuiFactory
{
    public:
        virtual ~GuiFactory();
        virtual std::shared_ptr<Button>		createButton() = 0;
        virtual std::shared_ptr<Checkbox>	createCheckbox() = 0;
};

GuiFactory::~GuiFactory() {}

class WinGuiFactory : public GuiFactory
{
    public:
        std::shared_ptr<Button> createButton()
        {
            return std::make_shared<WinButton>();
        }

        std::shared_ptr<Checkbox> createCheckbox()
        {
            return std::make_shared<WinCheckbox>();
        }
};

class MacGuiFactory : public GuiFactory
{
    public:
        std::shared_ptr<Button> createButton()
        {
            return std::make_shared<MacButton>();
        }

        std::shared_ptr<Checkbox> createCheckbox()
        {
            return std::make_shared<MacCheckbox>();
        }
};

class App
{
    public:
        App(std::shared_ptr<GuiFactory> guiFactory)
        {
            m_guiFactory = guiFactory;
        }
        
        void initUI()
        {
            m_button = m_guiFactory->createButton();
            m_checkbox = m_guiFactory->createCheckbox();
        }
        
        void drawUI()
        {
            m_button->draw();
            m_checkbox->draw();
        }

    private:
    
        std::shared_ptr<GuiFactory>	m_guiFactory;
        std::shared_ptr<Button>		m_button;
        std::shared_ptr<Checkbox>	m_checkbox;
};

int main()
{
    std::cout << "==== Win app ====" << std::endl;
    App winApp(std::make_shared<WinGuiFactory>());
    winApp.initUI();
    winApp.drawUI();
    std::cout << std::endl;
    
    std::cout << "==== Mac app ====" << std::endl;
    App macApp(std::make_shared<MacGuiFactory>());
    macApp.initUI();
    macApp.drawUI();
    std::cout << std::endl;
}
