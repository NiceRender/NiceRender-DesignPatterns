#include <iostream>
#include <string>

struct Person
{
    std::string name;
    long age;
};

// Handler
class Hotel
{
    public:
        virtual ~Hotel();
        virtual void settlePerson(const Person* person) = 0;
        
        Hotel(int numRooms) : m_numRooms(numRooms) {}
        
        void requestSettlePerson(const Person* person)
        {
            if (m_numRooms != m_numBusyRooms)
            {
                settlePerson(person);
                m_numBusyRooms++;
            }
            else if (m_next) m_next->requestSettlePerson(person);
            else std::cout << "All hotels are full\n";
        }
        
        Hotel* setNext(Hotel* hotel)
        {
            m_next = hotel;
            return m_next;
        }
    
    protected:
        int m_numRooms;
        int m_numBusyRooms = 0;
        Hotel* m_next;
};

Hotel::~Hotel() { if (m_next) delete m_next; }

// Concrete Handler 1
class AtlantisThePalmHotel: public Hotel
{
    public: AtlantisThePalmHotel(int numRooms): Hotel(numRooms) {}
    protected: void settlePerson(const Person* person);
};

void AtlantisThePalmHotel::settlePerson(const Person* person)
{
    std::cout << "Welcome to \"Atlantis The Palm Hotel\", dear " << person->name << "!" << std::endl;
}

// Concrete Handler 2
class BurjAlArabHotel: public Hotel
{
    public: BurjAlArabHotel(int numRooms): Hotel(numRooms) {}
    protected: void settlePerson(const Person* person);
};

void BurjAlArabHotel::settlePerson(const Person* person)
{
    std::cout << "Welcome to \"Burj Al Arab Hotel\", dear " << person->name << "!" << std::endl;
}

// Concrete Handler 3
class MandarinOrientalJumeiraHotel: public Hotel
{
    public: MandarinOrientalJumeiraHotel(int numRooms): Hotel(numRooms) {}
    protected: void settlePerson(const Person* person);
};

void MandarinOrientalJumeiraHotel::settlePerson(const Person* person)
{
    std::cout << "Welcome to \"Mandarin Oriental Jumeira Hotel\", dear " << person->name << "!" << std::endl;
}

// Client
int main()
{
    auto hotel = new AtlantisThePalmHotel(2);
    hotel->setNext(new BurjAlArabHotel(2))
         ->setNext(new MandarinOrientalJumeiraHotel(2));

    hotel->requestSettlePerson(new Person({"Mason", 20}));
    hotel->requestSettlePerson(new Person({"Emma", 25}));
    hotel->requestSettlePerson(new Person({"Jacob", 30}));
    hotel->requestSettlePerson(new Person({"Olivia", 25}));
    hotel->requestSettlePerson(new Person({"William", 20}));
    hotel->requestSettlePerson(new Person({"Sophia", 25}));
    hotel->requestSettlePerson(new Person({"Michael", 30}));
}
