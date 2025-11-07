#include <iostream>
#include <windows.h>
#include <limits>
using namespace std;

// Базовый класс для хранения названия и цены
class Publication {
public:
    string book_name;
    float book_price;

    // Ввод названия и цены
    virtual void getData() {
        cout << "Введите название книги: ";
        getline(cin, book_name);
        cout << "Введите цену книги: ";
        cin >> book_price;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }

    // Вывод названия и цены
    virtual void putData() {
        cout << "Название книги: " << book_name << endl;
        cout << "Цена книги: " << book_price << endl;
    }
};

// Класс для хранения информации о продажах за три месяца
class Sales {
public:
    float mass[3];

    virtual void getData() {
        for (int i = 0; i < 3; i++) {
            cout << "Введите стоимость проданных книг за месяц " << i + 1 << ": ";
            cin >> mass[i];
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
        }
    }

    virtual void putData() {
        cout << "Продажи книг за последние три месяца: ";
        for (int i = 0; i < 3; i++) {
            cout << mass[i] << " ";
        }
        cout << endl;
    }
};

// Класс книги, наследуется от Publication и Sales
class Book : public Publication, public Sales {
public:
    int pages;

    void getData() override {
        cout << "=== Ввод данных о книге ===\n";
        Publication::getData();
        Sales::getData();
        cout << "Введите количество страниц: ";
        cin >> pages;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }

    void putData() override {
        cout << "=== Данные о книге ===\n";
        Publication::putData();
        Sales::putData();
        cout << "Количество страниц: " << pages << endl;
    }
};

// Класс аудиокниги, наследуется от Publication и Sales
class Type : public Publication, public Sales {
public:
    int time;

    void getData() override {
        cout << "=== Ввод данных об аудиозаписи ===\n";
        Publication::getData();
        Sales::getData();
        cout << "Введите время записи (в минутах): ";
        cin >> time;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }

    void putData() override {
        cout << "=== Данные об аудиозаписи ===\n";
        Publication::putData();
        Sales::putData();
        cout << "Время записи (в минутах): " << time << endl;
    }
};

int main() {
    // поддержка русского языка в консоли
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8); // вывод в UTF-8
    SetConsoleCP(CP_UTF8);       // ввод в UTF-8

    Book book; // объект книги
    Type type; // объект аудиокниги

    // Ввод данных книги и аудиокниги
    book.getData();
    type.getData();

    // Вывод данных книги и аудиокниги
    book.putData();
    type.putData();

    return 0;
}
