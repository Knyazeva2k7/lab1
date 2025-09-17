#include <iostream>
#include <string>  
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "задание 1" << endl;
    int x1, x2;
    cin >> x1 >> x2;
    const double e = 2.7182;
    double y = (pow(e, -x1) + pow(e, -x2)) / 2;
    cout << "Функция у =";
    cout << y << endl;



    cout << "задание 2" << endl;
    int a, b, c;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    int p = (a + b + c) / 2;
    cout << "Площадь треугольника по формуле Герона S = ";
    cout << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;

    cout << "задание 3" << endl;
    const double kPi = 3.1415;
    int R, r, l, h;
    cout << "R = ";
    cin >> R;
    cout << "r = ";
    cin >> r;
    cout << "l = ";
    cin >> l;
    cout << "h = ";
    cin >> h;
    int s = kPi * (R * r) * l + kPi * pow(R, 2) + kPi * pow(r, 2);
    int v = (float)1 / 3 * (pow(R, 2) + pow(r, 2) + (R * r)) * h * kPi;
    cout << "Площадь поверхности усеченного конуса S = ";
    cout << s << endl;
    cout << "Объем усеченного конуса V = ";
    cout << v << endl;

    cout << "задание 4" << endl;
    cout << "Введите число, содержащее не менее трех разрядов ";
    int number;
    cin >> number;
    cout << "Третий справа разряд числа равен ";
    cout << number % 1000 / 100 << endl;

    cout << "задание 5" << endl;
    cout << "Введите дробное число ";
    float n;
    cin >> n;
    cout << "Первый разряд после десятичной точки числа равен ";
    int n10 = n * 10;
    cout << n10 % 10 << endl;

    cout << "задание 6" << endl;
    int age;
    cout << "Введите ваш возраст в месяцах ";
    cin >> age;
    cout << "Ваш возраст в годах ";
    cout << age / 12 << endl;

    cout << "задание 7" << endl;
    cout << "Введите температуру в градусах Цельсия ";
    int tempC;
    cin >> tempC;
    int tempF = 1.8 * tempC + 32;
    cout << tempC << " градусов Цельсия равны " << tempF << " градусам Фаренгейта" << endl;

    cout << "задание 8" << endl;
    long long worldPopulation, rusPopulation;
    cout << "Введите население всего мира: ";
    cin >> worldPopulation;
    cout << "Введите население России: ";
    cin >> rusPopulation;
    cout << "Население России составляет " << (float)rusPopulation * 100 / worldPopulation << "% населения мира" << endl;

    cout << "задание 9" << endl;
    cout << "Введите пятизначное число: ";
    int five;
    cin >> five;
    cout << "1 цифра равна " << five / 10000 << endl;
    cout << "2 цифра равна " << five / 1000 % 10 << endl;
    cout << "3 цифра равна " << five / 100 % 10 << endl;
    cout << "4 цифра равна " << five % 100 / 10 << endl;
    cout << "5 цифра равна " << five % 10 << endl;

    cout << "задание 10" << endl;
    string firstName;
    string lastName;
    int ages;
    cout << "Как вас зовут? ";
    getline(cin, firstName);
    cout << "Как ваша фамилия? ";
    getline(cin, lastName);
    cout << "Сколько вам лет?";
    cin >> ages;
    cout << "Имя: " << lastName << ", " << firstName << endl;
    cout << "Возраст: " << ages << endl;


    return 0;

}
