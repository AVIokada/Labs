#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <Windows.h>

    class Settings {
    private:
        static std::map<std::string, std::string> settingsMap;

    public:
        static void Add(const std::string& key, const std::string& value) {
            settingsMap[key] = value;
        }

        static std::string Get(const std::string& key) {
            if (settingsMap.find(key) != settingsMap.end()) {
                return settingsMap[key];
            }
            return "Key not found";
        }

        static void Print() {
            for (const auto& pair : settingsMap) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
        }
    };

    std::map<std::string, std::string> Settings::settingsMap;

    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, "ru");

        std::vector<float> numbers = { 1.5, 2.0, 3.0, 4.5 , 5 };

        std::cout << "Исходные значения вектора:" << std::endl;
        for (const auto& num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        numbers.insert(numbers.begin() + 2, 3.75);
        std::cout << "После вставки 3.75 на третью позицию:" << std::endl;
        for (const auto& num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        numbers.pop_back();
        std::cout << "После удаления последнего элемента:" << std::endl;
        for (const auto& num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        Settings::Add("разрешение", "1920x1080");
        Settings::Add("полный экран", "да");
        Settings::Print();

        std::cout << "Полный экран: " << Settings::Get("полный экран") << std::endl;

        Settings::Add("громкость", "75");
        Settings::Print();

        return 0;
    }