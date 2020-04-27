#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class INewsSubscriber
{
    public:
        virtual ~INewsSubscriber();
        virtual void printNews(const std::string& news) = 0;
};

INewsSubscriber::~INewsSubscriber() {}

class NewsPublisher
{
    public:
        void subscribe(std::shared_ptr<INewsSubscriber> subscriber)
        {
            m_subscribers.push_back(subscriber);
        }
        
        void unsubscribe(std::shared_ptr<INewsSubscriber> subscriber)
        {
            const auto& it = std::find(m_subscribers.begin(), m_subscribers.end(), subscriber);
            m_subscribers.erase(it);
        }
        
        void setNews(const std::string& news)
        {
            std::cout << "Publisher sends news\n";
            for (ulong i = 0; i < m_subscribers.size(); ++i)
            m_subscribers[i]->printNews(news);
        }

    private:
        std::vector<std::shared_ptr<INewsSubscriber>> m_subscribers;
};

class NewsSubscriber1 : public INewsSubscriber
{
    public:
        void printNews(const std::string& news)
        {
            std::cout << "Subscriber1 receives news: " << news << "\n";
        }
};
    
class NewsSubscriber2 : public INewsSubscriber
{
    public:
        void printNews(const std::string& news)
        {
            std::cout << "Subscriber2 receives news: " << news << "\n";
        }
};

int main()
{
    auto publisher = std::make_shared<NewsPublisher>();
    auto subscriber1 = std::make_shared<NewsSubscriber1>();
    auto subscriber2 = std::make_shared<NewsSubscriber2>();
    
    std::cout << "======================\n";
    publisher->subscribe(subscriber1);
    publisher->setNews(std::string("News list 10.04.2019 09:00"));
    std::cout << "======================\n";
    publisher->subscribe(subscriber2);
    publisher->setNews(std::string("News list 10.04.2019 10:00"));
    std::cout << "======================\n";
    publisher->unsubscribe(subscriber1);
    publisher->setNews(std::string("News list 10.04.2019 11:00"));
    std::cout << "======================\n\n";
}
