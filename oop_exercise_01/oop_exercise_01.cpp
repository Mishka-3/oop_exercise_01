// oop_exercise_01.cpp
//
// Гаврилин Михаил Юрьевич 80-201
// 
// Создать класс fraction для работы с дробями.
// Рациональная (несократимая) дробь представляется парой целых чисел (a, b), где a — числитель, b — знаменатель. Создать класс Rational для работы с рациональными дробями. Обязательно должны быть реализованы операции:
// -сложения add, (a, b) + (c, d) = (ad + bc, bd);
// -вычитания sub, (a, b) –(c, d) = (ad – bc, bd);
// -умножения mul, (a, b) ´(c, d) = (ac, bd);
// -деления div, (a, b) / (c, d) = (ad, bc);
// -операции сравнения.
// Должна быть реализована функция сокращения дроби reduce(), которая обязательно вызывается при выполнении арифметических операций


#include "oop_exercise_01.h"
using namespace std;

class fraction { // класс дробей
private:
    int rnum, rdenom;
public:
    int num;
    int denom;
    fraction(int a, int b){ // конструктор 
        num = a;
        denom = b;
    };
    int NOD(int a, int b){ // НОД
        a = abs(a);
        b = abs(b);
        while (a > 0 && b > 0)
            if (a > b) a %= b;
            else    b %= a;
        return a + b;
    }
    fraction reduce(fraction a){ // метод сокращения
        int b, q, t;
        fraction f(0, 0);
        b = NOD(a.num, a.denom);
        q = a.num / b;
        t = a.denom / b;
        f.num = q;
        f.denom = t;
        if (f.denom < 0){
            f.denom *= -1;
            f.num *= -1;
        }
        return f;
    }

    void printfrac() { // вывод дроби
        cout << num << "/" << denom << "\n";
    }

    void sum_frac(fraction c, fraction d) { // метод суммы
        rnum = c.num * d.denom + d.num * c.denom;
        rdenom = c.denom * d.denom;
    }
    void subt_frac(fraction c, fraction d) { // метод вычитания
        rnum = c.num * d.denom - d.num * c.denom;
        rdenom = c.denom * d.denom;
    }
    void mult_frac(fraction c, fraction d) { // метод умножения
        rnum = c.num * d.num;
        rdenom = c.denom * d.denom;
    }
    void div_frac(fraction c, fraction d) { // метод деления
        rnum = c.num * d.denom;
        rdenom = c.denom * d.num;
    }
    fraction get_sum() { // метод возвращения суммы
        fraction f(0, 0), d(0, 0);
        fraction result(rnum, rdenom);
        f = d.reduce(result);
        return f;
    }
    fraction get_subt() { // метод возвращения разности
        fraction f(0, 0), d(0, 0);
        fraction result(rnum, rdenom);
        f = d.reduce(result);
        return f;
    }
    fraction get_div() { // метод возвращения частного
        fraction f(0, 0), d(0, 0);
        fraction result(rnum, rdenom);
        f = d.reduce(result);
        return f;
    }
    fraction get_mult() { // метод возвращения произведения
        fraction f(0, 0), d(0, 0);
        fraction result(rnum, rdenom);
        f = d.reduce(result);
        return f;
    }

    int compare(fraction a, fraction b){ // метод сравнения
        int c, d, q, t;
        if (a.denom == b.denom){
            if (a.num > b.num){
                t = 1;
                return t;
            }
            else if (a.num < b.num){
                t = 0;
                return t;
            }
            else{
                t = -1;
                return t;
            }
        }
        else{
            c = a.num * b.denom;
            d = a.denom * b.num;
            q = a.denom * b.denom;
            if (c > d)
            {
                t = 1;
                return t;
            }
            else if (c < d)
            {
                t = 0;
                return t;
            }
            else
            {
                t = -1;
                return t;
            }
        }
    }
};


int main(){
    int k = 0;
    fraction first(0, 0);
    fraction f(0, 0), d(0, 0);
    while (1){
        cout << "1. Input drob" << "\t" << "2. Print drob" << "\t" << "3. Sum" << "\t" << "4.  Substract" << "\t" << "5. Multiply " << "\t" << "6. Divide" << "\t" << "7. Compare" << "\t" << "8. Reduce" << "\t" << "9. Exit" << "\n";
        scanf_s("%d", &k);
        if (k == 1){
            int a, b;
            cout << "Enter numerator and denominator" << '\n';
            cin >> a >> b;
            fraction p(a, b);
            first = p;
        }
        if (k == 2){
            first.printfrac();
        }
        if (k == 3){
            cout << "Enter numerator and denominator of second frac" << "\n";
            int c, d;
            cin >> c >> d;
            fraction second(c, d);
            first.sum_frac(first, second);
            cout << "first+second = ";
            (first.get_sum()).printfrac();
        }
        if (k == 4){
            cout << "Enter numerator and denominator of second frac" << "\n";
            int c, d;
            cin >> c >> d;
            fraction second(c, d);
            first.subt_frac(first, second);
            cout << "first-second = ";
            (first.get_subt()).printfrac();
        }
        if (k == 5){
            cout << "Enter numerator and denominator of second frac" << "\n";
            int c, d;
            cin >> c >> d;
            fraction second(c, d);
            first.mult_frac(first, second);
            cout << "first*second = ";
            (first.get_mult()).printfrac();
        }
        if (k == 6){
            cout << "Enter numerator and denominator of second frac" << "\n";
            int c, d;
            cin >> c >> d;
            fraction second(c, d);
            first.div_frac(first, second);
            cout << "first/fecond = ";
            (first.get_div()).printfrac();
        }
        if (k == 7){
            cout << "Enter numerator and denominator of second frac" << "\n";
            int c, d, t;
            cin >> c >> d;
            fraction second(c, d);
            t = first.compare(first, second);
            if (t == 1) { cout << "first frac is larger\n"; }
            if (t == 0) { cout << "second frac is larger\n"; }
            if (t == -1) { cout << "they are equal\n"; }
        }
        if (k == 8){
            d = f.reduce(first);
            d.printfrac();
        }
        if (k == 9){
            break;
        }
    }
    return 0;
}
