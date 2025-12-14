#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//основная структура
struct pen {
		string brand;
		float weight;
		string color;
		int quantity;
		float price;
};

void printMenu() {
	cout << "Меню:" << endl;
	cout << "1. Вывести текущий список на экран" << endl;
	cout << "2. Добавить в список новый элемент" << endl;
	cout << "3. Удалить из списка существующий элемент" << endl;
	cout << "4. Очистить список" << endl;
	cout << "5. Сохранить список в файл" << endl;
	cout << "6. Загрузить список из файла" << endl;
	cout << "0. Выход" << endl;
}

//1. вывод списка на экран
void display(pen* arr, int n) {
	if (n == 0 || arr == nullptr) {
		cout << "Список пуст" << endl;
		return;
	}

	cout << "Список ручек " << endl;
	for (int i = 0; i < n; ++i) {
		cout << "№" << (i + 1) << ".";
		cout << "Бренд: " << arr[i].brand << endl;
		cout << "Вес: " << arr[i].weight << endl; 
		cout << "Цвет: " << arr[i].color << endl;
		cout << "Количество: " << arr[i].quantity << endl;
		cout << "Цена: " << arr[i].price << endl;
	}
}

//2. добавить элемент
//везде передаем указатель по ссылке (Pen*&), 
// чтобы функция могла изменить сам массив,
// и size по ссылке (int&), чтобы менять размер.
void inputPen(pen*& arr, int& size) {
	pen newPen;
	cout << "Добавление новой ручки" << endl;
	cout << "Введите бренд: "; cin >> newPen.brand;
	cout << "Введите вес: "; cin >> newPen.weight;
	cout << "Введите цвет: "; cin >> newPen.color;
	cout << "Введите количество: "; cin >> newPen.quantity;
	cout << "Введите цену: "; cin >> newPen.price;
	//создание массива размером на 1 больше
	pen* temp = new pen[size + 1];

	//копирование старых данных в новый массив
	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];
	}
	//добавление нового элемента в конец
	temp[size] = newPen;
	//удаление старого массива из памяти
	if (size > 0) {
		delete[] arr;
	}
	//перенаправаление указателя на новый массив и уведличение счетчика
	arr = temp;
	size++;

	cout << "Ручка добавлена" << endl;
}

//3. удалить элемент

void deletePen(pen*& arr, int& size) {
	display(arr, size);
	if (size == 0)//если ничего не нет
		return;

	int index;
	cout << "Введите номер ручки, которую хотите удалить" << endl;
	cin >> index;
	if (index < 1 || index > size) {
		cout << "ERROR. Неверное число" << endl;
		return;
	}

	//если 1 элемент то очищаем весь список
	if (size == 1) {
		delete[] arr;//очищение памяти 
		arr = nullptr;//зануляем указател
		size = 0;//обнуляем размер 
		cout << "" << endl;
		return;
	}

	pen* temp = new pen[size - 1];//создание нового массива на единичку меньше
	int j = 0;//индекс для нового масиива
	for (int i = 1; i < size; i++) {
		if (i == (index - 1)) {
			continue;
		}
		temp[j] = arr[i];
		j++;
	}
	delete[] arr;
	arr = temp;
	size--; 

	cout << "Ручка удалена" << endl;
}

//4. очистить список

void cleanPen(pen*& arr, int& size) {
	if (size == 0) {
		cout << "Список ручек пуст" << endl;
		return;
	}

	delete[]arr;
	arr = nullptr;
	size = 0;
	cout << "Список очищен" << endl;
}

//5. сохранение в файл
void saveToFile(pen*& arr, int size, const string& fileName) {
	ofstream file(fileName);
	if (!file.is_open()) {
		cout << "Ошибка в открытии файла" << endl;
		return;
	}

	file << size << endl; //пишем количество
	for (int i = 0; i < size; i++) {
		file << arr[i].brand << " "
			<< arr[i].weight << " "
			<< arr[i].color << " "
			<< arr[i].quantity << " "
			<< arr[i].price << endl;
	}
	file.close();
	cout << "" << fileName << endl;
}
//6. добавление из файла
void addFromFile(pen*& arr, int& size, const string& fileName) {
	ifstream file(fileName);
	if (file.fail()) {
		cout << "Файл не найден" << endl;
		return;
	}

	if (arr != nullptr) {
		delete[]arr;
		arr = nullptr;
		size = 0;
	}

	int newSize;
	file >> newSize;//читаем размер из файла

	if (newSize > 0) {
		arr = new pen[newSize];
		
		for (int i = 1; i < newSize; i++) {
			file >> arr[i].brand
				>> arr[i].weight
				>> arr[i].color
				>> arr[i].quantity
				>> arr[i].price;
		}
		cout << "Добавлено " << newSize << " новых ручек" << endl;
	}
	else {
		cout << "Список был пуст" << endl;
	}
	file.close();
}

int main()
{
	setlocale(LC_ALL, "rus");

	pen* pens = nullptr; //указатель на начало динамического массива
	int choice; //текущее количество элементов
	int count = 0;

	string fileName = "pens.txt";
	
	do {
		//cmotri
		printMenu();
		cout << "Ваш выбор: " << endl;
		cin >> choice;
		if (choice > 6 || choice < 0) {
			cout << "Неверный выбор " << endl;
		}
		
		
		switch (choice) {
		case 1: {
			cout << "Текущий список выглядит так:" << endl;
			display(pens, count);
			break;
		}
		case 2: {
			inputPen(pens, count);
			break;
		}
		case 3: {
			deletePen(pens, count);
			break;
		}
		case 4: {
			cleanPen(pens, count);
			break;
		}
		case 5: {
			saveToFile(pens, count, fileName);
			break;
		}
		case 6: {
			addFromFile(pens, count, fileName);
			break;
		}
		case 0: {
			cout << "Выход..." << endl;
			break;
		}
		default:
			cout << "Неверный ввод, попробуйте снова" << endl;
		}
	} while (choice != 0);
	return 0;
}

