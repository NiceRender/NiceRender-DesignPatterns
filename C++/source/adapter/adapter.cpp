#include <iostream>
#include <memory>

// Adaptee
namespace fking_lib
{
    class Rect
    {
        public:
            void setRect(float x1, float y1, float x2, float y2)
            {
                _x1 = x1; _y1 = y1;
                _x2 = x2; _y2 = y2;
            }
            float getX1() { return _x1; }
            float getY1() { return _y1; }
            float getX2() { return _x2; }
            float getY2() { return _y2; }
        
        private:
            float _x1, _y1, _x2, _y2;
    };
}

// Target
class IRect
{
    public:
        virtual ~IRect();
        virtual void setRect(float x, float y, float w, float h) = 0;
        virtual float getX() = 0;
        virtual float getY() = 0;
        virtual float getW() = 0;
        virtual float getH() = 0;
};

IRect::~IRect() {}

// Adapter
class FkingLibRectAdapter : public IRect, private fking_lib::Rect
{
    public:
        void setRect(float x, float y, float w, float h)
        {
            fking_lib::Rect::setRect(x, y, x + w, y + h);
        }
        float getX() { return fking_lib::Rect::getX1(); }
        float getY() { return fking_lib::Rect::getY1(); }
        float getW() { return fking_lib::Rect::getX2() - fking_lib::Rect::getX1(); }
        float getH() { return fking_lib::Rect::getY2() - fking_lib::Rect::getY1(); }
};

// Client
int main()
{
    std::shared_ptr<IRect> rect2 = std::make_shared<FkingLibRectAdapter>();
    rect2->setRect(50, 50, 200, 100);
    std::cout <<
        "X = " << rect2->getX() <<
        "; Y = " << rect2->getY() <<
        "; W = " << rect2->getW() <<
        "; H = " << rect2->getH() << "\n";
}
