#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <climits>


using namespace std;

enum class FavSubject {
    INFORMATICS,
    CIVILLAW,
    MATHEMATIC,
    ENGLISH,
    PE,
    PHILOSOPHY,
    UNDEFIENED
};

//перечисление специальностей
enum class Specialty {
    CYBERSECURITY,
    APPLIERCOMPUTERSIENCE,
    JURISPRUDENCE,
    MANAGMENT,
    INFORMATIONTEHNOLOGY,
    UNDEFIENED
};


//основная структура
struct SU {
    string FullName;
    int year;
    Specialty specialty;
    int numOfGroup;
    float gpa;
    FavSubject favSubject;
};

pair<SU*, bool> findAllYear(int target, const SU* arr,
    int n) {
    int count = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i].year == target)
            count++;
    }

    SU* found = new SU[count];
    int j = 0;
    for (int i = 0; i < n && j < count; i++) {
        if (arr[i].year == target)
            found[j++] = arr[i];
    }

    return { found, !found == NULL};//выводим список и количество удовлетворяющих условию строк
};

pair<SU*, bool> findAllGpaB(float target, const SU* arr,
    int n) {
    int count2 = 0;
    //больше введенного значения
    for (int i = 0; i < n; i++) {
        if (arr[i].gpa == target)
            count2++;
    }

    SU* foundGpa = new SU[count2];
    int j = 0;
    for (int i = 0; i < n && j < count2; i++) {
        if (arr[i].gpa == target)
            foundGpa[j++] = arr[i];
    }
    return { foundGpa, !foundGpa == NULL };
}

pair<SU*, bool> findAllGpaM(float target, const SU* arr,
    int n) {
    int count2 = 0;
    //больше введенного значения
    for (int i = 0; i < n; i++) {
        if (arr[i].gpa < target)
            count2++;
    }

    SU* foundGpa = new SU[count2];
    int j = 0;
    for (int i = 0; i < n && j < count2; i++) {
        if (arr[i].gpa < target)
            foundGpa[j++] = arr[i];
    }
    return { foundGpa, !foundGpa == NULL };
}


Specialty string_to_Spec(string storage) {
    Specialty spec;
    if (storage == "CYBERSECURITY")
        spec = Specialty::CYBERSECURITY;
    else if (storage == "APPLIERCOMPUTERSIENCE")
        spec = Specialty::APPLIERCOMPUTERSIENCE;
    else if (storage == "JURISPRUDENCE")
        spec = Specialty::JURISPRUDENCE;
    else if (storage == "MANAGMENT")
        spec = Specialty::MANAGMENT;
    else if (storage == "INFORMATIONTEHNOLOGY")
        spec = Specialty::INFORMATIONTEHNOLOGY;
    else {
        cout << "Incorrect specialty" << endl;
        return Specialty::UNDEFIENED;
    }
    return spec;
}

FavSubject string_to_FavS(string storage) {
    FavSubject FavS;
    if (storage == "INFORMATICS")
        FavS = FavSubject::INFORMATICS;
    else if (storage == "CIVILLAW")
        FavS = FavSubject::CIVILLAW;
    else if (storage == "MATHEMATIC")
        FavS = FavSubject::MATHEMATIC;
    else if (storage == "ENGLISH")
        FavS = FavSubject::ENGLISH;
    else if (storage == "PE")
        FavS = FavSubject::PE;
    else if (storage == "PHILOSOPHY")
        FavS = FavSubject::PHILOSOPHY;
    else {
        cout << "Incorrect subject" << endl;
        FavS = FavSubject::UNDEFIENED;
    }
    return FavS;
}

string Spec_to_string(Specialty specialty) {
    string res;
    switch (specialty) {
    case Specialty::CYBERSECURITY:
        res = "CYBERSECURITY";
        break;
    case Specialty::APPLIERCOMPUTERSIENCE:
        res = "APPLIERCOMPUTERSIENCE";
        break;
    case Specialty::JURISPRUDENCE:
        res = "JURISPRUDENCE";
        break;
    case Specialty::MANAGMENT:
        res = "MANAGMENT";
        break;
    case Specialty::INFORMATIONTEHNOLOGY:
        res = "INFORMATIONTEHNOLOGY";
        break;
    case Specialty::UNDEFIENED:
        res = "UNDEFIENED";
        break;
    }
    return res;
}


string FavS_to_string(FavSubject favSubject) {
    string res;

    switch (favSubject) {
    case FavSubject::INFORMATICS:
        res = "INFORMATICS";
        break;
    case FavSubject::CIVILLAW:
        res = "CIVILLAW";
        break;
    case FavSubject::MATHEMATIC:
        res = "MATHEMATIC";
        break;
    case FavSubject::ENGLISH:
        res = "ENGLISH";
        break;
    case FavSubject::PE:
        res = "PE";
        break;
    case FavSubject::UNDEFIENED:
        res = "UNDEFIENED";
        break;
    }
    return res;
}

void display(SU* su, int n) {
    for (int i = 0; i < n; i++) {
        cout << su[i].FullName << ' '
            << su[i].year << ' '
            << Spec_to_string(su[i].specialty) << ' '
            << su[i].numOfGroup << ' '
            << su[i].gpa << ' '
            << FavS_to_string(su[i].favSubject) << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");


    fstream file("file2.txt", ios::in);

    if (file.fail()) {
        cout << "Ошибка открытия файла" << endl;
        return -1;
    }

    int countStr = 0;
    string str;
    while (getline(file, str))
        countStr++;

    SU* vus;
    vus = new SU[countStr];//новый массив с количеством подходящих учеников
    file.clear();
    file.seekg(0, ios::beg);
    for (int i = 0; getline(file, str) && i < countStr; i++) {
        stringstream ss(str);

        string token;
        char del = ';';
        vector<string> storage;
        while (getline(ss, token, del))
            storage.push_back(token);

        if (storage.size() != 6)
            continue;


        SU unik{
            storage[0],
            stoi(storage[1]),
            string_to_Spec(storage[2]),
            stoi(storage[3]),
            stof(storage[4]),
            string_to_FavS(storage[5])
        };
        vus[i] = unik;
    }
    

    
    int choice;
    

    
    do {
        cout << "Меню:" << endl;
        cout << "1. Поиск студентов по году поступления" << endl;
        cout << "2. Поиск студентов с низким средним баллом (< указанного)" << endl;
        cout << "3. Поиск студентов с высоким средним баллом (>= указанного)" << endl;
        cout << "4. Показать всех студентов" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        if (choice < 0 && choice > 4)
            cout << "некорректное число" << endl;




        switch (choice) {

        case 1: {
            int yearAdmission;
            cout << "введите год поступления" << endl;
            cin >> yearAdmission;
            int n = 6;
            pair<SU*, bool > res = findAllYear(yearAdmission, vus, n);
            if (res.second) {
                cout << "Студенты, поступившие в " << yearAdmission << " год" << endl;
                display(res.first, 6);
            }
            else
                cout << "Нет студентов, поступивших в этот год" << endl;

            break;
        }


        case 2: {
            float gpa;
            cout << "Введите средний балл " << endl;
            cin >> gpa;
            int n = 6;

            pair<SU*, bool> res = findAllGpaM(gpa, vus, n);
            if (res.second) {
                cout << "Студенты со средним баллом ниже " << gpa << endl;
                display(res.first, 6);
            }
            else
                cout << "Нет студентов с таким уровнем среднего балла" << endl;
            break;
        }
        case 3: {
            float gpa;
            cout << "Введите средний балл " << endl;
            cin >> gpa;
            int n = 6;

            pair<SU*, bool> res = findAllGpaB(gpa, vus, n);
            if (res.second) {
                cout << "Студенты со средним баллом выше " << gpa << endl;
                display(res.first, 6);
            }
            else
                cout << "Нет студентов с таким уровнем среднего балла" << endl;
            break;
        }
        case 4: {
            cout << "Все студенты" << endl;
            display(vus, 6);
            break;
        }
        case 0: {
            cout << "Выход из программы" << endl;
            break;
        }
        }
        

        } while (choice != 0);
    
    return 0;
}

