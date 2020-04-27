#include <iostream>
#include <string>
#include <memory>

class UiComponent
{
    public:
        virtual ~UiComponent();
        virtual void draw() = 0;
};

UiComponent::~UiComponent() {}

class Text : public UiComponent
{
    public:
        void draw() { std::cout << "Text\n"; }
};

class Button : public UiComponent
{
    public:
        void draw() { std::cout << "Button\n"; }
};

class Checkbox : public UiComponent
{
    public:
        void draw() { std::cout << "Checkbox\n"; }
};

class BorderDecorator : public UiComponent
{
    public:
        BorderDecorator(std::shared_ptr<UiComponent> uiComponent)
            : _uiComponent(uiComponent) {}
            
        void draw();
        
    private:
        std::shared_ptr<UiComponent> _uiComponent;
};

void BorderDecorator::draw()
{
    std::cout << "+---------------------------------------+\n";
    std::cout << "| "; _uiComponent->draw();
    std::cout << "+---------------------------------------+\n";
}

int main()
{
    auto button = std::make_shared<Button>();
    auto text = std::make_shared<Text>();
    auto checkbox = std::make_shared<Checkbox>();
    
    button->draw();
    text->draw();
    checkbox->draw();
    
    std::cout << "\n";
    
    std::make_shared<BorderDecorator>(button)->draw();
    std::make_shared<BorderDecorator>(text)->draw();
    std::make_shared<BorderDecorator>(checkbox)->draw();
}
