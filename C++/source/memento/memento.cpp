#include <iostream>
#include <string>

class Rect;

// Memento
class RectMemento
{
    public:
        RectMemento(float x, float y, float w, float h)
        {
            m_x = x; m_y = y;
            m_w = w; m_h = h;
        }
    
    private:
        friend class Rect;
        float m_x, m_y, m_w, m_h;
};

// Originator
class Rect
{
    private:
        float m_x, m_y, m_w, m_h;

    public:
        Rect(float x, float y, float w, float h)
        {
            m_x = x; m_y = y;
            m_w = w; m_h = h;
        }
        
        void setX(float value) { m_x = value; } 
        void setY(float value) { m_y = value; } 
        void setW(float value) { m_w = value; } 
        void setH(float value) { m_h = value; } 
        
        RectMemento* createMemento() { return (new RectMemento(m_x, m_y, m_w, m_h)); }
        
        void setMemento(RectMemento* memento)
        { 
            m_x = memento->m_x;
            m_y = memento->m_y;
            m_w = memento->m_w;
            m_h = memento->m_h;
        }
        
        void printInfo()
        {
            std::cout << "x = " << m_x << "; y = " << m_y
                    << "; w = " << m_w << "; h = " << m_h << "\n";
        }
};
 
// Caretaker
class RectCaretaker
{
    public:
        RectMemento* getMemento() { return m_memento; }
        void setMemento(RectMemento* memento) { m_memento = memento; }
    
    private:
        RectMemento* m_memento;
};

int main()
{
    auto rect = new Rect(10, 10, 100, 50);
    rect->printInfo();
    
    auto caretaker = new RectCaretaker();
    caretaker->setMemento(rect->createMemento());
    
    rect->setX(50);
    rect->setY(60);
    rect->setW(20);
    rect->setH(30);
    rect->printInfo();
    
    rect->setMemento(caretaker->getMemento());
    rect->printInfo();
}
