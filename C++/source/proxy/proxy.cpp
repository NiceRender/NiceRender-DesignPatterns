#include <iostream>
#include <string>
#include <memory>

class IPhone
{
    public:
        virtual ~IPhone();
        virtual void unlock() = 0;
        virtual void lock() = 0;
        virtual void call() = 0;

    protected:
        bool m_isLocked = true;
};

IPhone::~IPhone() {}

class Phone : public IPhone
{
    public:
        void unlock();
        void lock();
        void call();
};

void Phone::unlock()
{
    m_isLocked = false;
    std::cout << "Phone is unlocked.\n";
}

void Phone::lock()
{
    m_isLocked = true;
    std::cout << "Phone is locked.\n";
}

void Phone::call()
{
    if (m_isLocked) std::cout << "Access denied!\n";
    else std::cout << "Hello!\n";
}

class PhoneWithPassword : public IPhone
{
    public:
        PhoneWithPassword(Phone* phone): m_phone(phone) {}
        void unlock();
        void lock();
        void call();
        bool checkPassword(const std::string& password)
        {
            if (password == "qwerty") return true;
            else return false;
        }
    
    private:
        Phone* m_phone;
};

void PhoneWithPassword::lock()
{
    m_phone->lock();
}

void PhoneWithPassword::unlock()
{
    std::string pass;
    std::cout << "Enter the password: ";
    std::cin >> pass;
    if (checkPassword(pass)) m_phone->unlock();
    else std::cout << "The password is wrong!\n";
}

void PhoneWithPassword::call()
{
    m_phone->call();
}

int main()
{
    Phone phone;
    PhoneWithPassword phone2(&phone);

    std::cout << "==== Simple Phone ====\n";
    std::cout << "Call: ";      phone.call();
    std::cout << "Unlock: ";    phone.unlock();
    std::cout << "Call: ";      phone.call();
    std::cout << "Lock: ";      phone.lock();

    std::cout << "\n==== Phone with pass ====\n";
    std::cout << "Call: ";      phone2.call();
    std::cout << "Unlock. ";    phone2.unlock();
    std::cout << "Call: ";      phone2.call();
}
