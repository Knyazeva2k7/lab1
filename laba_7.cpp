#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;
double trArea(const double* a, const double* b) {
    return *a * *b / 2;
}

double& maxi(double& n1, double& n2, double& n3) {
    if (n1 >= n2 && n1 >= n3)
        return n1;
    else if (n2 >= n1 && n2 >= n3) {
        return n2;
    }
    else
        return n3;
}
void maxiAverage(double& n1, double& n2, double& n3) {
    double average = (n1 + n2 + n3) / 3;
    maxi(n1, n2, n3) = average;
}

double* maxi2(double& n1, double& n2, double& n3) {
    if (n1 >= n2 && n1 >= n3)
        return &n1;
    else if (n2 >= n1 && n2 >= n3) {
        return &n2;
    }
    else
        return &n3;
}
int& mini2(int(&arr)[5]) {
    int min = arr[0];
    for (int i = 0; i < 5; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int maxi2(int(&arr)[5]) {
    int max = arr[0];
    for (int i = 0; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }return max;
}

void swap2(int (&arr)[5]) {
    mini(arr) = maxi(arr);
}


int main() {
    setlocale(LC_ALL, "rus");
    //1 zadanie
    double number;
    double* ptr = &number;
    *ptr = 100;
    double* ptr2 = ptr;
    *ptr2 = 200;
    cout << "адрес переменной ptr: " << ptr << "\nзначение переменной " << *ptr << endl;
    cout << "адрес переменной ptr2: " << ptr2 << "\nзначение переменной " << *ptr2 << endl;


    //2 zadanie
    double a, b;
    cout << "введите 2 стороны треугольника " << endl;
    cin >> a >> b;
    double* a_link = &a, * b_link = &b;
    cout << "площадь треугольника равна " << trArea(a_link, b_link) << endl;


    //3 zadanie
    double n1, n2, n3;
    cout << "введите 3 числа " << endl;
    cin >> n1 >> n2 >> n3;
    maxiAverage(n1, n2, n3);//замена максимального элемента ср. ариф.
    cout << "после изменения " << n1 << " " << n2 << " "
        << n3 << " " << endl;


    //4 zadanie
    double num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    double* maxPtr = maxi2(num1, num2, num3);//указатель на максимальное число
    double average2 = (num1 + num2 + num3) / 3;
    *maxPtr = average2; //присваиваем значение ср. ариф. вместо максимума 

    cout << "после изменения(2 версия) " << num1
        << " " << num2 << " "
        << num3 << endl;


    //5 zadanie
    cout << "введите длину массива " << endl;
    int arr[5] = {5, 4, 1, 7, 8};

    cout << mini(arr) << endl;
    cout << maxi(arr) << endl;
    swap(arr);
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }
    cout << endl;

    return 0;

}
