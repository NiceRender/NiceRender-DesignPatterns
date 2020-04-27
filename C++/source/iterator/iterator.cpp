#include <iostream>

// Iterator
class Iterator
{
    public:
        virtual ~Iterator();
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() = 0;
        virtual int* getItem() = 0;
};

Iterator::~Iterator() {}

// Aggregate
class Aggregate
{
    public:
        virtual ~Aggregate();
};

Aggregate::~Aggregate() {}

// Concrete Aggregate
class List : public Aggregate
{
    public:
        List(const unsigned int size)
        {
            m_list = new int[size]();
            m_count = size;
        }
        
        ~List();
        long size() const { return m_count; }
        int* at(long index) { return &m_list[index]; }
        
        void printList(Iterator* it)
        {
            it->first();
            for (; !it->isDone(); it->next())
                std::cout << *it->getItem() << " ";
            std::cout << "\n";
        }
    
    private:
        int *m_list;
        long m_count;
};

List::~List() { delete[] m_list; }

// Concrete Iterator
class ListIterator : public Iterator
{
    public:
        ListIterator(List *list) : m_list(list), m_index(0) {}
        void first() { m_index = 0; }
        void next() { m_index++; }
        bool isDone() { return m_index > m_list->size() - 1; }
        int* getItem();
    
    private:
        List* m_list;
        long m_index;
};

int* ListIterator::getItem()
{
    if (isDone()) return nullptr;
    return m_list->at(m_index);
}

// Concrete Iterator
class ListIteratorReverse : public Iterator
{
    public:
        ListIteratorReverse(List *list) : m_list(list) { first(); }
        void first() { m_index = m_list->size() - 1; }
        void next() { m_index--; }
        bool isDone() { return m_index < 0; }
        int* getItem();
    
    private:
        List* m_list;
        long m_index;
};

int* ListIteratorReverse::getItem()
{
    if (isDone()) return nullptr;
    return m_list->at(m_index);
}

// Client
int main()
{
    auto list = new List(10);
    auto it = new ListIterator(list);
    auto itReverse = new ListIteratorReverse(list);
    
    for (; !it->isDone(); it->next())
        *it->getItem() = rand() % 100;
    
    list->printList(it);
    list->printList(itReverse);
    
    delete it;
    delete itReverse;
}
