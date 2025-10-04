// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main() {
	setlocale(0, "Russian");
	// ========= ПЯТОЕ
	cout << "Выбор типа числа: \n";
	cout << "1. int\n" << "2. float\n" << "3. double\n";
	int cursor;
	cin >> cursor;

	// INT
	if (cursor == 1) {
		cout << "Введите число: ";
		int numberInt;
		cin >> numberInt;

		int doubleDigitsArray1[sizeof(int) * 8];
		int orderInt = sizeof(int) * 8;
		unsigned int maskInt = 1 << (orderInt - 1);

		for (int i = 0; i < orderInt; i++) {
			if (numberInt & (maskInt >> i)) {
				doubleDigitsArray1[i] = 1;
			}
			else {
				doubleDigitsArray1[i] = 0;
			}

		}
		cout << "\n";

		cout << "Двоичное представление числа: ";
		for (int k = 0; k < orderInt; k++) {
			cout << doubleDigitsArray1[k];
		}
		cout << "\n";
		// СМЕНА БИТА
		cout << "Поменять бит? (1. да / 2. нет) ";
		int cursorInner1;
		cin >> cursorInner1;
		if (cursorInner1 == 1) {
			cout << "Введите индекс бита и значение: ";
			int changingIndex1, changingValue1;
			cin >> changingIndex1 >> changingValue1;
			doubleDigitsArray1[31 - changingIndex1] = changingValue1;
		}
		else if (cursorInner1 == 2) {
			cout << "Двоичное представление числа: ";
			for (int k = 0; k < orderInt; k++) {
				cout << doubleDigitsArray1[k];
			}
		}
		cout << "Двоичное представление числа: ";
		for (int k = 0; k < orderInt; k++) {
			cout << doubleDigitsArray1[k];
		}
	}
	// FLOAT
	else if (cursor == 2) {
		cout << "Введите число: ";
		float numberFloat;
		cin >> numberFloat;

		union {
			float floatUnion;
			unsigned int intUnion;
		} convertionFloat;

		convertionFloat.floatUnion = numberFloat;

		int doubleDigitsArray2[sizeof(float) * 8];
		int orderFloat = sizeof(float) * 8;
		unsigned int maskFloat = 1 << (orderFloat - 1);

		for (int i = 0; i < orderFloat; i++) {
			if (convertionFloat.intUnion & (maskFloat >> i)) {
				doubleDigitsArray2[i] = 1;
			}
			else {
				doubleDigitsArray2[i] = 0;
			}

		}
		cout << "\n";

		cout << "Двоичное представление числа: ";
		for (int k = 0; k < orderFloat; k++) {
			cout << doubleDigitsArray2[k];
		}
		cout << "\n";

		// СМЕНА БИТА
		cout << "Поменять бит? (1. да / 2. нет) ";
		int cursorInner2;
		cin >> cursorInner2;
		if (cursorInner2 == 1) {

			cout << "Введите индекс бита и значение: ";
			int changingIndex2, changingValue2;
			cin >> changingIndex2 >> changingValue2;
			doubleDigitsArray2[orderFloat - 1 - changingIndex2] = changingValue2;

			cout << "Двоичное представление числа: ";
			for (int k = 0; k < orderFloat; k++) {

				cout << doubleDigitsArray2[k];
			}

		}
		else if (cursorInner2 == 2) {


			cout << "Двоичное представление числа: ";
			for (int k = 0; k < orderFloat; k++) {

				cout << doubleDigitsArray2[k];
			}

		}


	}
	// DOUBLE
	else if (cursor == 3) {
		cout << "Введите число: ";
		double numberDouble;
		cin >> numberDouble;

		union {
			double doubleUnion;
			int intUnion[2];
		} convertionDouble;

		convertionDouble.doubleUnion = numberDouble;

		const int orderDouble = sizeof(double) * 8;
		int doubleDigitsArray3[orderDouble];

		unsigned int mask;
		for (int i = 0; i < 32; i++) {
			mask = 1u << (31 - i);
			doubleDigitsArray3[i] = (convertionDouble.intUnion[1] & mask) ? 1 : 0;
		}
		for (int i = 0; i < 32; i++) {
			mask = 1u << (31 - i);
			doubleDigitsArray3[32 + i] = (convertionDouble.intUnion[0] & mask) ? 1 : 0;
		}

		cout << "Двоичное представление числа: \n";
		for (int k = 0; k < orderDouble; k++) {
			cout << doubleDigitsArray3[k];
		}
		cout << "\n";

		cout << "Поменять бит? (1. да / 2. нет) ";
		int cursorInner3;
		cin >> cursorInner3;

		if (cursorInner3 == 1) {
			cout << "Введите индекс бита и значение: ";
			int changingIndex, changingValue;
			cin >> changingIndex >> changingValue;

			doubleDigitsArray3[orderDouble - 1 - changingIndex] = changingValue;

			cout << "Двоичное представление числа: \n";
			for (int k = 0; k < orderDouble; k++) {
				cout << doubleDigitsArray3[k];
			}
			cout << "\n";
		}
		else if (cursorInner3 == 2) {
			cout << "Двоичное представление числа: ";
			for (int k = 0; k < orderDouble; k++) {
				cout << doubleDigitsArray3[k];
			}
			cout << "\n";
		}
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

