#include <map>
#include <iostream>
#include <memory>
#include <string>

// Flyweight
class TetrisShape
{
    public:
        void display() const { std::cout << m_asciiImage; }
    
    protected:
        std::string m_asciiImage;
};

// ConcreteFlyweight 1
class ShapeT : public TetrisShape
{
    public:
        ShapeT()
        {
            m_asciiImage =  "    \n"
                            "### \n"
                            " #  \n"
                            "    \n";
        }
};

// ConcreteFlyweight 2
class ShapeL : public TetrisShape
{
    public:
        ShapeL()
        {
            m_asciiImage =  "    \n"
                            " #  \n"
                            " #  \n"
                            " ## \n";
        }
};

// ConcreteFlyweight 3
class ShapeO : public TetrisShape
{
    public:
        ShapeO()
        {
            m_asciiImage =  "    \n"
                            " ## \n"
                            " ## \n"
                            "    \n";
        }
};

// FlyweightFactory
class TetrisShapesFactory
{
    public:
        const TetrisShape& getShape(char key)
        {
            auto it = m_shapes.find(key);
            if (m_shapes.end() == it)
            {
                if (key == 'T') m_shapes[key] = std::make_unique<const ShapeT>();
                else if (key == 'L') m_shapes[key] = std::make_unique<const ShapeL>();
                else if (key == 'O') m_shapes[key] = std::make_unique<const ShapeO>();
                return *m_shapes[key];
            }
            else return *it->second;
        }
    
    private:
        std::map<char, std::unique_ptr<const TetrisShape>> m_shapes;
};

int main()
{
    std::string shapeKeys = "TTTOLOLO";
    TetrisShapesFactory factory;

    for (auto it : shapeKeys)
    {
        auto shape = factory.getShape(it);
        shape.display();
    }
}
