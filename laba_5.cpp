#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string Caesar(const string text, int shift) {
    string res = text;
    for (int i = 0; i < res.length(); ++i) {
        if (isalpha(res[i])) {
            char base = islower(res[i]) ? 'a' : 'A';

            res[i] = base + (res[i] - base + shift) % 26;
        }

    }
    return res;
}

string deCaesar(const string text, int shift) {
    return Caesar(text, -shift);
}
bool checkPass(std::string pass) {
    if (pass.length() < 8 || pass.length() > 14)
        return false;

    bool upper = false;
    bool lower = false;
    bool digit = false;
    bool other = false;

    for (unsigned char c : pass) {
        if (c < 33 || c > 126)
            return false;

        if (isupper(c))
            upper = true;
        else if (islower(c))
            lower = true;
        else if (isdigit(c))
            digit = true;
        else
            other = true;
    }

    return upper + lower + digit + other >= 3;
}

bool revStr(string input) {
    string sanit = "", rev = "";

    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i]))
            sanit += tolower(input[i]);
    }

    for (int i = sanit.length() - 1; i >= 0; i--) {
        rev += sanit[i];
    }
    return rev == sanit;
}

unsigned int strLen(const char* input) {
    unsigned int count = 0;
    while (input[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "rus");

    //1 zadanie
    string input;
    cout << "Введите палиндром" << endl;
    cin >> input;

    if (revStr(input)) {
        cout << "palindrom" << endl;
    }
    else {
        cout << "ne palindrom" << endl;
    }

    //2 zadanie
    string password;
    cout << "Введите пароль" << endl;
    cin >> password;
    if (checkPass(password)) {
        cout << "correct password" << endl;
    }
    else {
        cout << "incorrect password" << endl;
    }



    //3 zadanie

    cout << "len " << strLen(input.c_str()) << endl;

    //4 zadanie
    string shifr;
    int shift;

    cout << "Введите слово для шифровки " << endl;
    cin >> shifr;
    cout << "Введите сдвиг " << endl;
    cin >> shift;
    string encrypted = Caesar(shifr, shift);
    cout << encrypted << endl;

    //5 zadanie
    int first = 0, last = 5, num;
    vector<string> names = { "Елена", "Павел","Яна",
        "Владимир", "Стас" };
    vector<string> surnames = { "Борецкий", "Прилучный", "Малышева",
        "Путин", "Банько" };
    cout << "Введите количество людей" << endl;

    cin >> num;
    srand(time(nullptr));
    for (int i = 0; i < num; i++) {
        int randNum1 =  rand() % (last - 1) + first;
        int randNum2 = rand() % (last - 1) + first;
        cout << names[randNum1] << " " << surnames[randNum2] << endl;
    }
    //6 zadanie
    string str, poisk;
    int numOfstr;

    cout << "Введите количество строк с данными " << endl;
    cin >> numOfstr;

    vector<string> strInf(numOfstr);

    cout << "Ведите строки с данными " << endl;
    for (auto str : strInf) {
        cin.ignore();
        cin >> str;
    }

    cout << "Введите поисковую строку " << endl;
    cin >> poisk;

    for (const auto str : strInf) {
        if (str.find(poisk) != string::npos) {
            cout << str << endl;
        }
        else {
            cout << "not found" << endl;
        }
    }

    return 0;
}





