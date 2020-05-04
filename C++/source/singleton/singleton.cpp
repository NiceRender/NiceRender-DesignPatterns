#include <iostream>
#include <string>

class AppSettings
{
    public:
        static AppSettings* getInstance()
        {
            if (!m_instance) m_instance = new AppSettings();
            return m_instance;
        }

        void setLang(std::string lang) { m_lang = lang; }
        std::string getLang() { return m_lang; }

    protected:
        AppSettings() {}

    private:
        static AppSettings* m_instance;
        std::string m_lang = "en";
};

AppSettings* AppSettings::m_instance = nullptr;

int main()
{
    AppSettings::getInstance()->setLang("en");

    // ...

    std::string lang = AppSettings::getInstance()->getLang();
    if (lang == "en") { std::cout << "Hello!\n"; }
    else if (lang == "ru") { std::cout << "Privet!\n"; }
}
