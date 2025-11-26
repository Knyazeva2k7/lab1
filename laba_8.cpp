#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;
int getInterval(int a, int b) {
    return rand() % (b - a + 1) + a;
}

void echo(int**& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int**& matrix(int n, int a, int b) {
    int*** matrix_ptr = new int**;//указатель на число инт для строк матрицы
    *matrix_ptr = new int* [n]; //выделение памяти под эту строку
    for (int i = 0; i < n; i++) {
        (*matrix_ptr)[i] = new int[n];//выделение памяти под каждый элемент строки
        for (int j = 0; j < n; j++) {
            (*matrix_ptr)[i][j] = getInterval(a, b);
        }
    }
    return *matrix_ptr;//возвращает саму матрицу
}

void clear(int**& matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

void swap(int a, int b) {
    int c = a;
    a = b;
    b = c;
}

int green(int**& matrix, int n) {
    int maxMatG, minMatG;
    int min = matrix[0][0], max = matrix[0][0];
    int minG = matrix[0][0], maxG = matrix[0][0];
    for (int i = 0; i < n; i++) {
        if (i < n / 2 + 1) {
            for (int j = 0; j < n - i; j++) {

                if ((j < n / 2 + 1) && (j >= i)) {
                    if (matrix[i][j] > max && matrix[i][j] < 0)
                        max = matrix[i][j];

                    if (matrix[i][j] < min && matrix[i][j]> 0)
                        min = matrix[i][j];

                }

                for (int i = 0; i < n / 2 + 1; i++) {
                    for (int j = n / 2 + 1; j < n - i; j++) {
                        if (matrix[i][j] > maxG)
                            maxG = matrix[i][j];
                        if (matrix[i][j] < minG)
                            minG = matrix[i][j];
                    }
                }
            }
        }
    }
    if (minG > min) {
        int minMatG = min;
        return minMatG;
    }
    else {
        int minMatG = minG;
        return minMatG;
    }


    if (maxG < max) {
        int maxMatG = max;
        return maxMatG;
    }
    else {
        int maxMatG = maxG;
        return maxMatG;
    }
    return maxMatG;
}

void red(int**& matrix, int n) {
    int maxMatR = matrix[0][0], minMatR = matrix[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j >= n - 1) {
                if (matrix[i][j] > maxMatR) {
                    maxMatR = matrix[i][j];

                }
                if (matrix[i][j] < minMatR) {
                    minMatR = matrix[i][j];

                }
            }
        }
    }
    cout << minMatR << endl;
    cout << maxMatR << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    //1 zadanie
    srand(time(nullptr));

    int n, a, b;
    cout << "Enter array size" << endl;
    cin >> n;
    cout << "Enter interval for values generation" << endl;
    cin >> a >> b;

    int**& mat = matrix(n, a, b);

    green(mat, n);
    red(mat, n);
    echo(mat, n);

    clear(mat, n);

    //2 zadanie
    ofstream file("file.txt");

    file.open("file.txt");
    for (int i = 1; i <= 50; i++) {
        file << i << endl;
    }
    file.close();
    ifstream file2("file.txt");
    int** matrica = new int* [n];
    for (int i = 0; i < n; i++) {
        matrica[i] = new int[n];
        for (int j = 0; j < n; j++) {
            int num;
            for (int a = 1; a <= n; a++) {
                file2 >> num;
                matrica[i][j] = num;

            }

        }
    }


    return 0;
}
