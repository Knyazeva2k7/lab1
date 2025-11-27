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


int** matrix(int n, int a, int b) {
    int** matrix_ptr = new int*[n];//указатель на число инт для строк матриц
    for (int i = 0; i < n; i++) {
        matrix_ptr[i] = new int[n];//выделение памяти под каждый элемент строки
        for (int j = 0; j < n; j++) {
            matrix_ptr[i][j] = getInterval(a, b);
        }
    }
    return matrix_ptr;
}

void clear(int**& matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}


int* green(int**& matrix, int n, int a) {
    int* maxPtr{};
    
    int max = a;
    for (int j = 0; j < n; j++) {        
        for (int i = 0; i < (j < n/2. ? j: n-j-1); i++) {            
            if (matrix[i][j] > max && matrix[i][j] < 0) {
                max = matrix[i][j];
                maxPtr = matrix[i] + j;
             }   
        }
    }
    if (maxPtr == nullptr)
        cout << "нет чисел, подходящих под условие" << endl;
    return maxPtr;
}

int* red(int**& matrix, int n,  int b) {
    int min = b;
    int* minPtr{};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j >= n - 1) {
                if (matrix[i][j] < min && matrix[i][j] > 0) {
                    minPtr = matrix[i] + j;
                    min = matrix[i][j];
                }
            }
        }
    }
    if (minPtr == nullptr)
        cout << "нет чисел, подходящих под условие"<< endl;
    
    return minPtr;
}

int main() {
    setlocale(LC_ALL, "rus");
    //1 zadanie
    srand(time(nullptr));

    int n, a, b;
    cout << "Введите размер матрицы" << endl;
    cin >> n;
    cout << "Введите интервал для чисел" << endl;
    cin >> a >> b;

    int** mat = matrix(n, a, b);

    echo(mat, n);
    int* maxNegativePtr = red(mat, n, b);
    int* minPositivePtr = green(mat, n, a);
    cout << "Числа которые поменчялись местаами: " << *maxNegativePtr <<
        " и " << *minPositivePtr << endl;
    int temp = *maxNegativePtr;
    *maxNegativePtr = *minPositivePtr;
    *minPositivePtr = temp;

    echo(mat, n);
    clear(mat, n);

    

    return 0;
}
