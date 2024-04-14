// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
#include <math.h>
#include <Windows.h>
using namespace std;

// Ваші файли загловки 
//
#include "Lab3Example.h"
class Data{
    unsigned int day;
    unsigned int month;
    int year;
public:
    //конструктор за замовчуванням
    Data() : day(1), month(1), year(2024) {}

    // Конструктор з одним параметром (день)
    Data(unsigned int d) : day(d), month(1), year(2024) {}

    // Конструктор з двома параметрами (день, місяць)
    Data(unsigned int d, unsigned int m) : day(d), month(m), year(2024) {}

    // Конструктор з трьома параметрами (день, місяць, рік)
    Data(unsigned int d, unsigned int m, int y) {
        if (d > 0 && d <= 31 && m > 0 && m <= 12) { day = d; month = m; year = y; }
    }

    //функції - члени встановлення дня, місяця та року
    double getDay() const { return day; }
    void setDay(unsigned int d) { if (d <= 0 || d > 31) { cout << " \nError set day \n\n"; return; } this->day = d; }
    double getMonth() const { return month; }
    void setMonth(unsigned int m) { if (m <= 0 || m > 12) { cout << " \nError set month \n\n"; return; } this->month = m; }
    double getYear() const { return year; }
    void setYear(int y) {this->year = y; }

    void InputData(){
        unsigned int in_day, in_month;
        int in_year;
    cout << " \nInput day, month and year: ";
    cin >> in_day >> in_month >> in_year;

    Data obj1(in_day), obj2(in_month),
        obj3(in_day, in_month, in_year);
    obj1.printInfo1();
    obj1.printInfo2();
    obj2.printInfo1();
    obj2.printInfo2();
    obj3.printInfo1();
    obj3.printInfo2();
    }
    //дві функції-члени друку за шаблоном: “5 січня 2019 року” і “05.01.2019”
    //1-а функція
    void printInfo1()
    {
        cout  << day;
        
        switch (month) {
        case 1: cout << " січня "; break;
        case 2: cout << " лютого "; break;
        case 3: cout << " березня "; break;
        case 4: cout << " квітня "; break;
        case 5: cout << " травня "; break;
        case 6: cout << " червня "; break;
        case 7: cout << " липня "; break;
        case 8: cout << " серпня "; break;
        case 9: cout << " вересня "; break;
        case 10: cout << " жовтня "; break;
        case 11: cout << " листопада "; break;
        case 12: cout << " грудня "; break;
        default: cout << "Error month!"; break;
        }
       
        cout << " Year= " << year << endl;
    }

    //2-а функція
    void printInfo2()
    {
        cout << day << "." << month << "." << year << "\n";
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << " Lab #3  !\n";
//  Код виконання завдань
//  Головне меню завдань
//  Функції та класи можуть знаходитись в інших файлах проекту
    Data obj;
    obj.printInfo1();
    obj.printInfo2();
    
    obj.InputData();
    
    
    obj.setDay(-1);
    obj.printInfo1();
    obj.printInfo2();
    obj.setDay(12);
    obj.printInfo1();
    obj.printInfo2();
    obj.setDay(33);
    obj.printInfo1();
    obj.printInfo2();
    obj.setMonth(-2);
    obj.printInfo1();
    obj.printInfo2();
    obj.setMonth(5);
    obj.printInfo1();
    obj.printInfo2();
    obj.setMonth(13);
    obj.printInfo1();
    obj.printInfo2();
    cout << " \nEnd testing \n";
    return 0;
}

