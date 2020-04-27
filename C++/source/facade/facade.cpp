#include <iostream>

class Cpu
{
    public:
        void getInfo() { std::cout << "Intel Core i7 8700K\n"; }
};

class Gpu
{
    public:
        void getInfo() { std::cout << "GTX 1080\n"; }
};

class Ram
{
    public:
        void getInfo() { std::cout << "Kingston HyperX FURY 16GB\n"; }
};

// Facade
class GamingComputer
{
    public:
        void getInfo()
        {
            _cpu.getInfo();
            _gpu.getInfo();
            _ram.getInfo();
        }
        
    private:
        Cpu _cpu;
        Gpu _gpu;
        Ram _ram;
};

int main()
{
    GamingComputer comp;
    comp.getInfo();
}
