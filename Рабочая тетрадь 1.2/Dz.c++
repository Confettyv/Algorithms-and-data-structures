#include <iostream>
#include <cmath>
using namespace std;

// Функция, корень которой мы ищем
double f(double x) {
    return cos(2/x) - 2*sin(1/x) + 1/x;
}

int main() {
    double a = 1;     
    double b = 2;      
    double eps = 0.0001; 
    double x;           
    
    // Проверка условия смены знака на концах интервала
    if (f(a) * f(b) >= 0) {
        cout << "На концах интервала функция имеет одинаковый знак!" << endl;
        cout << "f(a) = " << f(a) << ", f(b) = " << f(b) << endl;
        return 1;
    }
    
    int iterations = 0; 
    double x_prev;     
    
    double fixed_point = b;
    double fixed_value = f(b);
    
    x = a;
    
    cout << "Метод хорд:" << endl;
    
    do {
        iterations++;
        x_prev = x;
        
        x = x - f(x) * (fixed_point - x) / (fixed_value - f(x));
        
        cout << iterations << " : x = " << x << ", f(x) = " << f(x) << endl;
        
    } while (fabs(x - x_prev) > eps && fabs(f(x)) > eps);
    
    cout << "Результат: " << x << endl;
    cout << "Количество итераций: " << iterations << endl;
    cout << "Значение функции: f(" << x << ") = " << f(x) << endl;
    
    return 0;
}