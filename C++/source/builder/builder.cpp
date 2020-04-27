#include <iostream>
#include <string>
#include <memory>

class Computer
{
    public:
        void setCpu(const std::string& cpu)         { m_cpu = cpu; }
        void setGpu(const std::string& gpu)         { m_gpu = gpu; }
        void setRam(const std::string& ram)         { m_ram = ram; }
        void setRom(const std::string& rom)         { m_rom = rom; }
        void setScreen(const std::string& screen)   { m_screen = screen; }

        void displayInfo()
        {
            std::cout <<
                "\n- CPU: " << m_cpu << "\n- GPU: "     << m_gpu    << "\n- RAM: " << m_ram <<
                "\n- ROM: " << m_rom << "\n- Screen: "  << m_screen;
        }

    private:
        std::string m_cpu, m_gpu, m_ram, m_rom, m_screen;
};

class ComputerBuilder
{
    public:
        virtual ~ComputerBuilder();
        virtual void setCpu()       = 0;
        virtual void setGpu()       = 0;
        virtual void setRam()       = 0;
        virtual void setRom()       = 0;
        virtual void setScreen()    = 0;
        void createComputer() { m_computer = std::make_shared<Computer>(); }
        std::shared_ptr<Computer> getComputer() { return m_computer; }

    protected:
        std::shared_ptr<Computer> m_computer;
};

ComputerBuilder::~ComputerBuilder() {}

class GamingComputerBuilder : public ComputerBuilder
{
    public:
        virtual ~GamingComputerBuilder();
        void setCpu()       { m_computer->setCpu("Intel Core i7 8700K");    }
        void setGpu()       { m_computer->setGpu("GTX 1080");               }
        void setRam()       { m_computer->setRam("16 GB");                  }
        void setRom()       { m_computer->setRom("500 GB SSD + 2 TB HDD");  }
        void setScreen()    { m_computer->setScreen("4K");                  }
};

GamingComputerBuilder::~GamingComputerBuilder() {}

class CryptoMiningFarmBuilder : public ComputerBuilder
{
    public:
        virtual ~CryptoMiningFarmBuilder();
        void setCpu()       { m_computer->setCpu("Intel Celeron J3060");    }
        void setGpu()       { m_computer->setGpu("RX 580 x6");              }
        void setRam()       { m_computer->setRam("8 GB");                   }
        void setRom()       { m_computer->setRom("200 GB HDD");             }
        void setScreen()    { m_computer->setScreen("1024x768");            }
};

CryptoMiningFarmBuilder::~CryptoMiningFarmBuilder() {}

class TypewriterBuilder : public ComputerBuilder
{
    public:
        virtual ~TypewriterBuilder();
        void setCpu()       { m_computer->setCpu("Intel Celeron J3060");    }
        void setGpu()       { m_computer->setGpu("Intel HD");               }
        void setRam()       { m_computer->setRam("4 GB");                   }
        void setRom()       { m_computer->setRom("200 GB HDD");             }
        void setScreen()    { m_computer->setScreen("1024x768");            }
};

TypewriterBuilder::~TypewriterBuilder() {}

class DirectorOfComputerBuilder
{
    public:
        void makeComputer(ComputerBuilder& computerBuilder)
        {
            computerBuilder.createComputer();
            computerBuilder.setCpu();
            computerBuilder.setGpu();
            computerBuilder.setRam();
            computerBuilder.setRom();
            computerBuilder.setScreen();
        }
};

int main()
{
    DirectorOfComputerBuilder	director;
    GamingComputerBuilder       gamingComputerBuilder;
    CryptoMiningFarmBuilder     cryptoMiningFarmBuilder;
    TypewriterBuilder           typewriterBuilder;

    std::cout << "\n";
    std::cout << "==== Gaming computer ====";
    director.makeComputer(gamingComputerBuilder);
    gamingComputerBuilder.getComputer()->displayInfo();
    std::cout << "\n\n";
    std::cout << "==== Crypto mining farm ====";
    director.makeComputer(cryptoMiningFarmBuilder);
    cryptoMiningFarmBuilder.getComputer()->displayInfo();
    std::cout << "\n\n";
    std::cout << "==== Typewriter ====";
    director.makeComputer(typewriterBuilder);
    typewriterBuilder.getComputer()->displayInfo();
    std::cout << "\n\n";
}
