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

void maxMin(int*& arr, int*& max) {
    for (int i = 0; i < *(&arr + 1) - arr; i++) {
        if (arr[i] > *max)
            max = &arr[i];
    }

    cout << &max << endl;
}
void maxMin2(int*& arr, int*& min) {
    int* min = &arr[0];
    for (int i = 0; i < *(&arr + 1) - arr; i++) {
        if (arr[i] < arr[i + 1])
            min = &arr[i];
    }
    cout << &min << endl;
}
void swap(int*& arr) {
    int*& temp = maxMin(int*& arr, int*& max);
    maxMin(int*& arr, int*& max) = maxMin2(int*& arr, int*& min);
    maxMin2(int*& arr) = int*& temp;
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
    int n;
    cin >> n;
    int* arr = new int[n];
    cout << "array " << endl;
    for (int i = 0; i < n; i++) {
        int num = rand();
        arr[i] = num;
        cout << num << " ";
    }
    cout << endl;
    maxMin(arr, arr[0]);

    return 0;
}