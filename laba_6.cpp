#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    //1 zadanie
    ofstream fileout;
    int n, m;
    cout << "введите кол-во чисел,которые хотите записать в файл" << endl;
    cin >> n;
    n = abs(n);
    cout << "введите кол-во чисел,которые хотите вывести на экран" << endl;
    cin >> m;
    if (m > n) {
        return -1;
    }
    m = abs(m);
    fileout.open("file.txt");
    for (int i = 1; i <= n; i++) {
        fileout << i << endl;
    }
    fileout.close();

    ifstream ifs("file.txt");
    int num;
    for (int i = 1; i <= m; i++) {
        ifs >> num;
        cout << num << endl;
    }

    //2 zadanie
    ifs.seekg(0, ios::beg);

    int number;
    int sum = 0;
    while (ifs >> number) {
        if (number % 2 == 0)
            sum += number;
    }
    cout << "сумма четных чисел: " << sum << endl;
    ifs.close();
    //3 zadanie
    ifstream fmin("file.txt");


    int min = 1000;
    int number1;

    while (fmin >> number1) {
        if (number1 > 0 && number1 < min) {
            min = number1;
        }
    }
    if (min != 1000) {
        cout << "минимальное положительное число равно: " << min << endl;
    }
    else {
        cout << "нет положительных чисел." << endl;
    }
    fmin.close();
    //4 zadanie
    fstream file_f("file.txt", ios::in | ios::out | ios::binary);
    for (int i = 1; i <= n; i++) {
        file_f.write((char*)&i, sizeof(i));
    }
    file_f.seekg(0, ios::beg);
    int sum1 = 0;
    while (file_f.read((char*)&number, sizeof(number))) {
        if (number % 2 == 0) {
            sum1 += number;
        }
    }
    cout << "сумма четных чисел (бин-версия): " << sum1 << endl;
    //5 zadanie
    file_f.seekg(0, ios::beg);

    while (file_f.read((char*)&number, sizeof(number))) {
        if (number > 0 && number < min)
            min = number;
    }
    if (min != 1000) {
        cout << "минимальное положительное число равно(бин-версия): " << min << endl;
    }
    else {
        cout << "нет положительных чисел." << endl;
    }
    return 0;
}