#include <iostream>
#include <string>

class AppSettings
{
    public:
        static AppSettings* getInstance()
        {
            if (!_instance) _instance = new AppSettings();
            return _instance;
        }
        
        void setLang(std::string lang) { _lang = lang; }
        std::string getLang() { return _lang; }

    protected:
        AppSettings() {}

    private:
        static AppSettings* _instance;
        std::string _lang = "en";
};
  
AppSettings* AppSettings::_instance = nullptr;

int main()
{
    AppSettings::getInstance()->setLang("en");
    std::string lang = AppSettings::getInstance()->getLang();
    if (lang == "en") { std::cout << "Hello!\n"; }
    else if (lang == "ru") { std::cout << "Privet!\n"; }
}
