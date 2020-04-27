#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Vertex
{
    public:
        Vertex() {}
        Vertex(float x, float y) : m_x(x), m_y(y) {}
        void print() { std::cout << "(" << x() << "; " << y() << ") "; }
        float x() { return m_x; }
        float y() { return m_y; }

    private:
        float m_x = 0.0f;
        float m_y = 0.0f;
};

// Prototype
class Shape
{
    public:
        virtual ~Shape();
        virtual std::shared_ptr<Shape> clone() const { return doClone(); }
        virtual void printInfo() {}
        
    private:
        virtual std::shared_ptr<Shape> doClone() const
        {
            return std::make_shared<Shape>(*this);
        }
};

Shape::~Shape() {}

// Concrete Prototype
class Triangle : public Shape
{
    public:
        Triangle() {}
        Triangle(const Vertex v1, const Vertex v2, const Vertex v3)
        {
            m_v1 = v1;
            m_v2 = v2;
            m_v3 = v3;
        }

        void printInfo() override;
        
    private:
        virtual std::shared_ptr<Shape> doClone() const override
        {
            return std::make_shared<Triangle>(*this);
        }
    
        Vertex m_v1, m_v2, m_v3;
};

void Triangle::printInfo()
{
    m_v1.print();
    m_v2.print();
    m_v3.print();
    std::cout << "\n";
}

// Concrete Prototype
class Quad : public Shape
{
    public:
        Quad() {}
    
        Quad(const Vertex v1, const Vertex v2, const Vertex v3, const Vertex v4)
        {
            m_v1 = v1;
            m_v2 = v2;
            m_v3 = v3;
            m_v4 = v4;
        }

        void printInfo() override;
        
    private:
        virtual std::shared_ptr<Shape> doClone() const override
        {
            return std::make_shared<Quad>(*this);
        }
    
        Vertex m_v1, m_v2, m_v3, m_v4;
};

void Quad::printInfo()
{
    m_v1.print();
    m_v2.print();
    m_v3.print();
    m_v4.print();
    std::cout << "\n";
}

// Client
int main()
{
    auto trianglePrototype = std::make_shared<Triangle>(
        Vertex(0, 0), Vertex(2, 0),
        Vertex(2, 3));

    auto quadPrototype = std::make_shared<Quad>(
        Vertex(0, 0), Vertex(2, 0),
        Vertex(2, 3), Vertex(0, 3));  
    
    std::vector<std::shared_ptr<Shape>> shapes;
    
    for (int i = 0; i < 5; ++i)
        shapes.push_back(trianglePrototype->clone());
    for (int i = 0; i < 5; ++i)
        shapes.push_back(quadPrototype->clone());
    
    for (ulong i = 0; i < shapes.size(); ++i)
    {
        std::cout << "Shape " << i << ". ";
        shapes[i]->printInfo();
    }
}
