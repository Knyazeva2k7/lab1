#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cin >> n;
    vector<double> vec;

    for (int i = 0; i < n; i++) {
        double number;
        cin >> number;
        vec.push_back(number);
    }

    int min = vec[0];
    int max = vec[0];
    for (int e : vec) {
        if (e < min)
            min = e;
        if (e > max)
            max = e;
    }

    cout << "минимальный элемент: "
        << min << " максимальный элемент: " <<
        max << endl;

    int indexMIN = 0;
    int indexMAX = 0;
    for (int i = 0; i < n; i++) {//поиск индексов чисел
        if (vec[i] == min)
            indexMIN = i;
        if (vec[i] == max)
            indexMAX = i;
    }
    swap(vec[indexMAX], vec[indexMIN]);//поменяли местами мин и макс

    for (int j = 0; j < n; j++) {
        cout << vec[j] << " ";
    }//массив, с переставленными максимальным и минимальным значениями
    for (int i = 0; i <= n - 1; i++) {
        int count1 = count(vec.begin(), vec.end(), vec[i]);
        //считает сколько раз повторяется число
        cout << "\nчисло " << vec[i] << " повторяется " << count1 << " раз" << endl;
    }

    //2 zadanie переделай через динамический массив
    //1
    int n2;
    cin >> n2;
    int* vec2 = new int [n2];
    for (int i = 0; i < n2; i++) {
        double number;
        cin >> number;
        vec2[i] = number;
    }
    int minModule = abs(vec2[0]);
    for (int i = 0; i < n2; i++) {
        if (abs(vec2[i]) < minModule)
            minModule = abs(vec2[i]);
    }

    auto indMin = find(vec2, vec2+n2, minModule);
    //auto определяет тип переменной на основе ее инициализации
    if (indMin != vec2+n2) {
        int index = distance(vec2, indMin) + 1;
        //distance определяет "расстояние" от начала вектора
        // до нужного числа
        cout << "Номер минимального по модулю элемента массива "
            << index << endl;
    }
    //2
    for (int i = 0; i < n2; i++) {
        double sum = 0;
        if (vec2[i] < 0) {
            for (int j = 1; j < n2 - i; j++) {
                sum += abs(vec2[i + j]);
            }
            cout << "Сумма модулей элементов массива после отрицательного числа равна "
                << sum << endl;
            break;
        }
    }
    //3
    for (int i = 0; i < n2; i++) {
        int nol = 0;
        if (abs(vec2[i]) <= 2) {
            vec2[i] = nol;
        }
        else
            vec2[i] = abs(vec2[i]);
    }
    sort(vec2, vec2 + n2, greater<double>());
    for (int i = 0; i < n2; i++) {
        cout << vec2[i] << " ";
    }


    return 0;
}
