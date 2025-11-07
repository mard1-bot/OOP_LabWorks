#include <iostream>
#include <windows.h>
#include <limits>
using namespace std;

// Базовый класс для публикации (книга или аудиокнига)
class Publication {
public:
    string book_name; // название книги
    float book_price; // цена книги

    virtual void getData() { // ввод данных
        cout << "Введите название книги: ";
        getline(cin, book_name);
        cout << "Введите цену книги: ";
        cin >> book_price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }

    virtual void putData() { // вывод данных
        cout << "Название книги: " << book_name << endl;
        cout << "Цена книги: " << book_price << endl;
    }
};

// Класс книги, наследует Publication
class Book : public Publication {
public:
    int pages; // количество страниц

    void getData() override {
        Publication::getData(); // ввод названия и цены
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }

    void putData() override {
        Publication::putData(); // вывод названия и цены
        cout << "Количество страниц: " << pages << endl;
    }
};

// Класс аудиокниги, наследует Publication
class Type : public Publication {
public:
    int time; // длительность записи в минутах

    void getData() override {
        Publication::getData(); // ввод названия и цены
        cout << "Введите время записи (в минутах): ";
        cin >> time;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }

    void putData() override {
        Publication::putData(); // вывод названия и цены
        cout << "Время записи (в минутах): " << time << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8); // вывод в UTF-8
    SetConsoleCP(CP_UTF8);       // ввод в UTF-8

    Book book; // объект книги
    Type type; // объект аудиокниги

    book.getData(); // ввод данных книги
    type.getData(); // ввод данных аудиокниги
    book.putData(); // вывод данных книги
    type.putData(); // вывод данных аудиокниги

    return 0;
}