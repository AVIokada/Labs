#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <ctime>
#include <Windows.h>

class BirthYearException : public std::exception {
public:
    enum class ErrorCode {
        TOO_OLD,
        NOT_BORN_YET,
        NEGATIVE
    };

    BirthYearException(ErrorCode code) : code(code) {}

    const char* what() const noexcept override {
        switch (code) {
        case ErrorCode::TOO_OLD: return "Что-то не верится...";
        case ErrorCode::NOT_BORN_YET: return "Вы ещё не родились";
        case ErrorCode::NEGATIVE: return "Вы ввели отрицательное число!";
        default: return "Неизвестная ошибка";
        }
    }

    ErrorCode getCode() const { return code; }

private:
    ErrorCode code;
};


void processNumberInput() {
    int num;
    std::cout << "Введите число 1, 2 или 3: ";
    std::cin >> num;

    switch (num) {
    case 1: std::cout << "Один" << std::endl; break;
    case 2: std::cout << "Два" << std::endl; break;
    case 3: std::cout << "Три" << std::endl; break;
    default:
        throw std::runtime_error("Некорректное значение");
    }
}

void processBirthYearInput() {
    int year;
    std::cout << "Введите год своего рождения: ";
    std::cin >> year;

    if (year < 0) {
        throw BirthYearException(BirthYearException::ErrorCode::NEGATIVE);
    }
    else if (year < 1850) {
        throw BirthYearException(BirthYearException::ErrorCode::TOO_OLD);
    }
    else if (year > 2025) {
        throw BirthYearException(BirthYearException::ErrorCode::NOT_BORN_YET);
    }

    std::cout << "Спасибо!" << std::endl;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");

    try {
        processNumberInput();

        processBirthYearInput();
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const BirthYearException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Неизвестная ошибка" << std::endl;
    }

    return 0;
}