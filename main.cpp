#include <Windows.h>
#include "Abiturient.h"
#include "Functions.h"
#include "Test.h"

using namespace std;

enum {
	Task1 = 1,
	Task2,
	Task3,
	Task4,
	Task5,
	EXIT
};

int main() {
	vector <Abiturient*> SavingVector;
	vector <Abiturient*> Abiturients;

	int answer;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	Info();
	cout << "Как вы хотите ввести исходные данные?\n1)Ручной ввод\n2)Ввод с файла" << endl;
	do {
		answer = IntEnter();
		if (answer == Task1) {
			InputInFileFromConsole(Abiturients, SavingVector);
			SaveInFile(SavingVector);
		}
		else if (answer == Task2) {
			InputInFileFromFile(Abiturients, SavingVector);
			SaveInFile(SavingVector);
		}
		else {
			cout << "Введите коректное значение" << endl;
		}
	} while (!(answer == Task1 || answer == Task2));

	do {
		cout << "\nКакое задание вы хотите выбрать?\n1)Ввести данные\n2)Вывести отсортированный список всех абитуриентов\n3)Вывести список абитуриентов, сумма баллов у которых не меньше заданной\n4)Вывести список N абитуриентов, имеющих самую высокую сумму баллов\n5)Тест\n6)Выход" << endl;
		answer = IntEnter();
		if (answer == Task1) {
			MenuInput(Abiturients, SavingVector);
		}
		else if (answer == Task2) {
			Sort(Abiturients, SavingVector);
			SaveInFile(SavingVector);
		}
		else if (answer == Task3) {
			ArrOutputPoints(Abiturients, SavingVector);
			SaveInFile(SavingVector);
		}
		else if (answer == Task4) {
			OutputTopAbiturients(Abiturients, SavingVector);
			SaveInFile(SavingVector);
		}
		else if (answer == Task5){
			Test();
		}
		else if (answer == EXIT) {
			continue;
		}
		else {
			cout << "Введите коректное значение" << endl;
		}
	} while (answer != EXIT);
	return 0;
} 