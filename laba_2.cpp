#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");



    cout << "задание 1" << endl;
    cout << "введите 2 любых целых числа ";
    int num1, num2;
    cin >> num1 >> num2;
    if (num1 > 0 and num2 % 2 == 0) {
        cout << "да" << endl;
    }

    else {
        cout << "нет" << endl;
    }




    cout << "задание 2" << endl;
    int n;
    cout << "введите натуральное число n " << endl;
    cin >> n;
    cout << n << endl;
    int source = n;

    if (n >= 10000) {
        cout << "слишком большое число" << endl;

        return -1;
    }

    int mirrowed = 0;

    while (n > 0) {
        int d = n % 10;
        mirrowed = mirrowed * 10 + d;
        n /= 10;
    }

    cout << mirrowed << endl;

    if (mirrowed == source)
        cout << "палиндром" << endl;
    else
        cout << "не палиндром" << endl;





    cout << "задание 3" << endl;
    cout << "введите величины сторон треугольника " << endl;
    int a, b, c;
    cin >> a >> b >> c;

    if (a > 30000 or b > 30000 or c > 30000) {
        cout << "число слишком большое" << endl;

        return -1;
    }

    if (a + b > c or b + c > a or c + a > b) {
        if (a * a + b * b == c * c or
            b * b + c * c == a * a or
            c * c + a * a == b * b) {
            cout << "да" << endl;
        }
        else {
            cout << "нет" << endl;
        }

    }
    if (a + b < c or b + c < a or c + a < b) {
        cout << "UNDEFINED" << endl;
    }




    cout << "задание 4" << endl;
    int i = 1;
    do {
        if ((i % 5 == 0) and (i % 7 == 0)) {
            cout << "fuzzbuzz" << endl;
        }
        else if (i % 5 == 0) {
            cout << "fuzz" << endl;
        }
        else if (i % 7 == 0) {
            cout << "buzz" << endl;
        }
        else {
            cout << i << endl;
        }
        i++;
    } while (i <= 500);
    /*решение с помощью while
    while (i <= 500) {
       if ((i % 5 == 0) and (i % 7 == 0)) {
            cout << "fuzzbuzz" << endl;
        }
        else if (i % 5 == 0) {
            cout << "fuzz" << endl;
        }
        else if (i % 7 == 0) {
            cout << "buzz" << endl;
        }
        else {
            cout << i << endl;
        }
        i++;
    }*/
    /*for (i = 1; i <= 500; i++) {
        if ((i % 5 == 0) and (i % 7 == 0)) {
            cout << "fuzzbuzz" << endl;
        }
        else if (i % 5 == 0) {
            cout << "fuzz" << endl;
        }
        else if (i % 7 == 0) {
            cout << "buzz" << endl;
        }
        else {
            cout << i << endl;
        }*/


    cout << "задание 5" << endl;
    double x;
    cout << "x \t| y" << endl;
    for (x = -2; x <= 2; x += 0.5) {
        double y = -2.4 * (x * x) + 5 * x - 3;
        cout << x  << " \t| " << y << endl;
    }





    cout << "задание 6" << endl;
    int a2, b2, h;
    cout << "введите диапазон и шаг" << endl;
    cin >> a2 >> b2 >> h;
    for (double x = 0.1; x <= 1; x += 0.1) {
        double s = 0;

        for (int i = 0; ; i++) {
            int fc = 1;
            for (int j = 2; j <= 1; j++) {
                fc *= j;
            }
            double si = ((2 * i + 1) * pow(x, 2 * i)) / fc;

            s += si;

            if (si < 0.0001)
                break;
        }
        double y = (1 + 2 * x * x) * exp(x * x);
        cout << s << "" << y << endl;
    }






    cout << "задание 7" << endl;
    int a3 = 1;
    for (a3 = 1; a3 <= 19; a3 += 3) {
        int x = (3 + a3) / (a3 - 4) * (a3 - 4);
        cout << "при а = " << a3 << " выражение равно " << x << endl;

    }
    /*решение с помощью while
    while (a3 <= 19) {
    if (a3 != 4) {
         double res = (3 + a3) / (a3 - 4) * (a3 - 4);
         cout << "при а = " << a3 << " выражение равно " << res << endl;  
     }
     a3 += 3;
    }*/
    /*решение с помощью do while
    do {
    if (a3 != 4) {
        double res = (3 + a3) / (a3 - 4) * (a3 - 4);
        cout << "при а = " << a3 << " выражение равно " << res << endl;

    }
    a3 += 3;
} while (a3 <= 19);
    */



    cout << "задание 8" << endl;

    int a_1 = 1;
    int b_1 = 1;
    int n = 15;
    int i;
    cout << a_1 << " " << b_1 << endl;
    for (int i = 2; i < n; i++) {
        int a = (3 * b_1 + 2 * a_1);
        int b = (2 * a_1 + b_1);

        cout << a << " " << b << endl;

        a_1 = a;
        b_1 = b;
    }







    cout << "задание 9" << endl;
    int x1, y1;
    cout << "введите координаты точки ";
    cin >> x1 >> y1;
    if (y1 < 0.5 * x1 + 1 and y1 > -0.5 * x1 - 1 and x1 < sqrt(1 * 1 + y1 * y1)) {
        cout << "принадлежит" << endl;
    }
    else {
        cout << "не принадлежит" << endl;

    }


    cout << "задание 10" << endl;
    double x2;
    cin >> x2;
    for (int c = 0; c <= 4; c++) {
        double ln1 = 0;
        for (int n = 0; ; n++) {
            double si = pow(x2 - 1, 2 * n + 1) / ((2 * n + 1) * pow(x2 + 1, 2 * n + 1));
            ln1 += si;

            if (si < 1e-7)
                break;
        }
        ln1 *= 2;

        double ln2 = 0;
        for (int n = 0;; n++) {
            double si = pow(x2 - 1, n + 1) / (n + 1);

            if (n % 2 != 0)
                ln2 -= si;
            else
                ln2 += si;

            if (si < 1e-7)
                break;
        }

        double ln3 = 0;
        for (int n = 0;; n++) {
            double si = pow(x2 - 1, n + 1) / (n + 1) / pow(x2 + 1, n + 1);
            if (n % 2 != 0)
                ln3 -= si;
            else
                ln3 += si;
            if (si < 1e-3)
                break;
        }

        cout << "ln(" << x2 << ") = "
            << ln1 << "; "
            << ln2 << "; "
            << ln3 << endl;

        cin >> x2;
    }
    return 0;

}