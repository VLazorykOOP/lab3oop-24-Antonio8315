// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
#include <math.h>
#include <Windows.h>
#define _RE 0
#define _IM 1
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
        else{ day = 1; month = 1; year = 1; }
    }

    //функції - члени встановлення дня, місяця та року
    double getDay() const { return day; }
    void setDay(unsigned int d) { if (d <= 0 || d > 31) { cout << " \nError set day \n\n"; return; } this->day = d; }
    double getMonth() const { return month; }
    void setMonth(unsigned int m) { if (m <= 0 || m > 12) { cout << " \nError set month \n\n"; return; } this->month = m; }
    double getYear() const { return year; }
    void setYear(int y) {this->year = y; }

    //функція - член одержання дня, місяця та року;
    void InputData(){
        unsigned int in_day, in_month;
        int in_year;
    cout << " \nInput day, month and year: ";
    cin >> in_day >> in_month >> in_year;

    Data obj1(in_day), obj2(in_day, in_month),
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

class VectorInt {
    //вказівник на int
    int* v;

    //число елементів
    int num;

    //змінна стану
    int state;
public:

    //конструктор без параметрів
    VectorInt() : v(NULL), num(0), state(0) {}

    //конструктор з одним параметром
    VectorInt(int n);

    //конструктор з двома параметрами
    VectorInt(int n, int&);
    VectorInt(int n, int*);

    //конструктор копій та операція присвоєння
    VectorInt(const VectorInt& s);
    VectorInt& operator=(const VectorInt& s);

    //деструктор
    ~VectorInt() {
        cout << " del vec\n";
        if (v) delete[] v;
    }

    //оголошення (визначення) всіх функцій у класі
    void Input();
    void Output();
    VectorInt Add(VectorInt& b);
    VectorInt Minus(VectorInt& b);
    VectorInt Mnoj(VectorInt& b);
    VectorInt Bilshe(VectorInt& b);
    VectorInt Menshe(VectorInt& b);
    VectorInt Rivno(VectorInt& b);
};

//конструктор з одним параметром
VectorInt::VectorInt(int n) {
    if (n <= 0) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
    num = n;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        v[i] = 0.0;
        //v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0; 
    }
}

//конструктор із двома параметрами
VectorInt::VectorInt(int n, int& b) {
    if (n <= 0) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
    num = n;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        v[i] = b;
        //v[i]._Val[_RE]=0.0; v[i]._Val[_IM]=0.0; 
    }
}

//конструктор копій
VectorInt::VectorInt(const VectorInt& s) {
    num = s.num;
    v = new int[num];
    state = 0;
    for (int i = 0; i < num; i++) v[i] = s.v[i];
}

//операція присвоєння
VectorInt& VectorInt::operator=(const VectorInt& s) {
    if (num != s.num)
    {
        if (v) delete[] v;
        num = s.num;
        v = new int[num];
        state = 0;
    }
    for (int i = 0; i < num; i++) v[i] = s.v[i];
    return *this;
}

//функція введення данних користувачем (присвоює елементу масиву деяке значення)
void VectorInt::Input() {
    if (num == 0) {
        if (v) delete[] v;
        do {
            cout << "Input size Vec\n";
            cin >> num;
        } while (num <= 0);
        v = new int[num];
    }
    for (int i = 0; i < num; i++) {
        cout << " v [ " << i << " ] real img "; cin >> v[i];
    };
}

//функція, що виводить (одержує) елементи масиву
void VectorInt::Output() {
    if (num != 0) {
        for (int i = 0; i < num; i++) {
            cout << " v [ " << i << " ] " << v[i] << '\t';
            cout << endl;
        }
    }
}

 //функція додавання
VectorInt VectorInt::Add(VectorInt& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0) {
        VectorInt tmp(tnum);
        for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
        return tmp;
    }
    return VectorInt(0);
};

//функція віднімання
VectorInt VectorInt::Minus(VectorInt& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0) {
        VectorInt tmp(tnum);
        for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] - b.v[i];
        return tmp;
    }
    return VectorInt(0);
};

//функція множення елементів вектора на число
VectorInt VectorInt::Mnoj(VectorInt& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0) {
        VectorInt tmp(tnum);
        for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] * b.v[i];
        return tmp;
    }
    return VectorInt(0);
};

//функція більше
VectorInt VectorInt::Bilshe(VectorInt& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0) {
        VectorInt tmp(tnum);
        for (int i = 0; i < tnum; i++) {
            if (v[i] > b.v[i])  cout << "true\n";
            if (v[i] <= b.v[i]) cout << "false\n";
        }
        return tmp;
    }
    return VectorInt(0);
};

//функція менше
VectorInt VectorInt::Menshe(VectorInt& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0) {
        VectorInt tmp(tnum);
        for (int i = 0; i < tnum; i++) {
            if (v[i] < b.v[i])  cout << "true\n";
            if (v[i] >= b.v[i]) cout << "false\n";
        }
        return tmp;
    }
    return VectorInt(0);
};

//функція рівно
VectorInt VectorInt::Rivno(VectorInt& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0) {
        VectorInt tmp(tnum);
        for (int i = 0; i < tnum; i++) {
            if (v[i] == b.v[i])  cout << "true\n";
            if (v[i] != b.v[i]) cout << "false\n";
        }
        return tmp;
    }
    return VectorInt(0);
};

int main()
{   //підключення української мови (для виводу назви місяця у вікно консолі)
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout << " Lab #3  !\n";

    int taskN;

    //вибір завдання
    cout << "Input # of task: ";
    cin >> taskN;
    switch (taskN) {
    case 1: {
        // програма тестування всіх можливостей класу InputData
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
        obj.setYear(2025);
        obj.printInfo1();
        obj.printInfo2();
        cout << " \nEnd testing \n";
        break;
    }
    case 2: {
        // програма тестування всіх можливостей класу VectorInt:

        //оголошення змінних
        int a(5), b, c;
        cout << " Test " << endl;
        VectorInt VecObj, VecObj1(10);

        //виведення конструктора без параметрів (нічого)
        cout << "VecObj \n";
        VecObj.Output();

        //виведення конструктора з одним параметром (кість елементів)
        cout << "VecObj1 \n";
        VecObj1.Output();

        //виведення конструктора з двома параметрами (кість елементів та значення ініціалізації)
        cout << " Input a  - заповнення вектора" << endl;
        cin >> a;
        VectorInt VecObj2(10, a);
        VecObj2.Output();

        //додавання
        cout << " Dodavanna " << endl;
        VecObj.Input();
        cout << endl;
        VecObj.Output();
        VecObj1 = VecObj.Add(VecObj2);
        VecObj1.Output();

        //віднімання
        cout << " Vidnimanna " << endl;
        VecObj.Input();
        VecObj2 = VecObj1.Minus(VecObj);
        VecObj2.Output();
        
        //множення
        cout << " Mnojenna " << endl;
        VecObj1.Input();
        VecObj = VecObj2.Mnoj(VecObj1);
        VecObj.Output();

        //менше
        cout << " Menshe " << endl;
        VecObj1.Input();
        VecObj2 = VecObj.Menshe(VecObj1);

        //більше
        cout << " Bilshe " << endl;
        VecObj2.Input();
        VecObj = VecObj1.Bilshe(VecObj2);

        //рівно
        cout << " Rivno " << endl;
        VecObj.Input();
        VecObj1 = VecObj2.Rivno(VecObj);

        break;
    }
    default: cout << "No Number"; break;
    }
    
    return 0;
}