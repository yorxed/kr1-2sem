#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include "Abiturient.h"

int IntPointEnter() {
	int num;
	while (true) {
		cout << ":";
		cin >> num;
		if (!cin) {
			cout << "������, ������� ���������� ��������!\n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			continue;
		}
		else if (num >= 0 && num <= 300) {
			break;
		}
		else {
			cout << "������� ������������������ ���������� ������, �� 0 �� 300" << endl;
			continue;
		}
	}
	return num;
}

int IntEnter() {
	int num;
	while (true) {

		cin >> num;
		if (!cin) {
			cout << "������, ������� ���������� ��������!\n";
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			continue;
		}
		else if (num >= 0) {
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			break;
		}
		else {
			continue;
		}
	}
	return num;
}

void Info() {
	cout << "****************************\n*                          *\n* ����������� ������ �1    *\n* ��������� ����� �������� *\n* ������ �4305             *\n* ������� �2               *\n*                          *\n****************************\n";
	cout << "\n����������: �������, ���, ��������, �����, �����. ������� ������ ��������. " << endl;
	cout << "����������� ����������� ��������� :" << endl;
	cout << "  � ���������������� ������ ���� ������������," << endl;
	cout << "  � ������ ������������, ����� ������ � ������� �� ������ ��������," << endl;
	cout << "  � ������ N ������������, ������� ����� ������� ����� ������\n" << endl;
}

void InputInFileFromConsole(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector) {
	enum {
		yes = 1,
		EXIT
	};

	string Path_name, Path_secondname, Path_midlename, Path_adress, Path_adressnum;
	int answer, Path_point;
	do {
		cout << "������� ��� �����������\n";
		cin >> Path_name;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "������� ������� �����������\n";
		cin >> Path_secondname;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "������� �������� �����������\n";
		cin >> Path_midlename;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "������� ����� �� ������� ����� ����������\n";
		cin >> Path_adress;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "������� ����� ���� � ������� ��������� ����������\n";
		cin >> Path_adressnum;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "������� ����� ������ �����������\n";
		Path_point = IntPointEnter();
		Abiturient* a1 = new Abiturient();
		a1->SetInfo(Path_name, Path_secondname, Path_midlename, Path_adress, Path_adressnum, Path_point);
		Abiturients.push_back(a1);
		SavingVector.push_back(a1);
		cout << "\n�� ������ ��������� ���� ������?\n\n������� 1 ����� ����������\n������� 2 ����� ���������\n";
		do {
			answer = IntEnter();
			if (answer == yes) {
				continue;
			}
			else if (answer == EXIT) {
				break;
			}
			else {
				cout << "������� ��������� ������" << endl;
			}
		} while (!(answer == yes || answer == EXIT));
	} while (answer != EXIT);
}

int ReadFromFile(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector, string path) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "������ ��� �������� �����!\n";
		return 1;
	}
	else {
		while (!fin.eof()) {
			string InfoFromFile = "";
			getline(fin, InfoFromFile);
			istringstream iss(InfoFromFile);
			string name; string secondname; string midlename; string adress; string adressnum; int points;
			if (iss >> name >> secondname >> midlename >> adress >> adressnum >> points) {
				if (points >= 0 && points <= 300) {
					Abiturient* abiturient = new Abiturient(points, name, secondname, midlename, adress, adressnum);
					Abiturients.push_back(abiturient);
					SavingVector.push_back(abiturient);
				}
				else {
					cout << "������ ����� ����������, ������ �� ����� ���������!" << endl;
				}
			}
			else {
				cerr << "������ ��� ������ ������!" << endl;
				Abiturients.clear();
				SavingVector.clear();
				return 1;
				break;
			}
		}
	}
	cout << "������ ������� ������ �������� � ������:" << endl;
	for (int i = 0; i < size(Abiturients); i++) {
		int point = Abiturients[i]->GetPoint();
		string name = Abiturients[i]->GetName();
		string secondname = Abiturients[i]->GetSecondname();
		string midlename = Abiturients[i]->GetMidlename();
		string adress = Abiturients[i]->GetAdress();
		string adressnum = Abiturients[i]->GetAdressNum();
		cout << "���: " << secondname << ", " << name << ", " << midlename << " �����: " << adress << " " << adressnum << " ���� " << point << endl;
	}
	fin.close();
	return 0;
}

void InputInFileFromFile(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector) {
	string path;
	cout << "������� �������� ����� ������ � �����������" << endl;
	int RecivingData;
	do {
		cin >> path;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		RecivingData = ReadFromFile(Abiturients, SavingVector, path);
		if (RecivingData == 0) {
			break;
		}
		else {
			cout << "������� �������� ������������� �����" << endl;
			continue;
		}
	} while (!(RecivingData == 0));
}

void SortWithoutInput(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector) {
	for (int i = 0; i < size(Abiturients); i++) {
		for (int j = 0; j < (size(Abiturients) - 1); j++) {
			int points1 = Abiturients[j]->GetPoint();
			int points2 = Abiturients[j + 1]->GetPoint();
			if (points1 < points2) {
				Abiturient* a = Abiturients[j];
				Abiturients[j] = Abiturients[j + 1];
				Abiturients[j + 1] = a;
			}
		}
	}
	SavingVector = Abiturients;
}

void Sort(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector) {
	for (int i = 0; i < size(Abiturients); i++) {
		for (int j = 0; j < (size(Abiturients) - 1); j++) {
			int points1 = Abiturients[j]->GetPoint();
			int points2 = Abiturients[j + 1]->GetPoint();
			if (points1 < points2) {
				Abiturient* a = Abiturients[j];
				Abiturients[j] = Abiturients[j + 1];
				Abiturients[j + 1] = a;
			}
		}
	}
	cout << "��������������� ������ ������������:" << endl;

	for (int i = 0; i < size(Abiturients); i++) {
		int point = Abiturients[i]->GetPoint();
		string name = Abiturients[i]->GetName();
		string secondname = Abiturients[i]->GetSecondname();
		string midlename = Abiturients[i]->GetMidlename();
		string adress = Abiturients[i]->GetAdress();
		string adressnum = Abiturients[i]->GetAdressNum();
		cout << "���: " << secondname << ", " << name << ", " << midlename << " �����: " << adress << " " << adressnum << " ���� " << point << endl;
		SavingVector.push_back(Abiturients[i]);
	}
}

void ArrOutputPoints(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector) {
	int PointMore;
	cout << "������� ���� ��� ������ ������������ � ����� �� ������ � ����" << endl;
	do {
		cin >> PointMore;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		if (PointMore >= 0 && PointMore <= 300) {
			for (int i = 0; i < size(Abiturients); i++) {
				int point = Abiturients[i]->GetPoint();
				if (point >= PointMore) {
					string name = Abiturients[i]->GetName();
					string secondname = Abiturients[i]->GetSecondname();
					string midlename = Abiturients[i]->GetMidlename();
					string adress = Abiturients[i]->GetAdress();
					string adressnum = Abiturients[i]->GetAdressNum();
					cout << "���: " << secondname << ", " << name << ", " << midlename << " �����: " << adress << " " << adressnum << " ���� " << point << endl;
					SavingVector.push_back(Abiturients[i]);
				}
			}
		}
		else {
			cout << "���� �� ����� ��������� 300 ��� ���� ������ ����" << endl;
		}
	} while (!(PointMore >= 0 && PointMore <= 300));
}

void OutputTopAbiturients(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector) {
	int NumberAbiturients;
	cout << "������� ������������ ������� ����� ������� ����� ������ �� ������ �������?" << endl;
	do {
		cin >> NumberAbiturients;
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		if (NumberAbiturients <= size(Abiturients) && NumberAbiturients > 0) {
			for (int i = 0; i < NumberAbiturients; i++) {
				int point = Abiturients[i]->GetPoint();
				string name = Abiturients[i]->GetName();
				string secondname = Abiturients[i]->GetSecondname();
				string midlename = Abiturients[i]->GetMidlename();
				string adress = Abiturients[i]->GetAdress();
				string adressnum = Abiturients[i]->GetAdressNum();
				cout << "���: " << secondname << ", " << name << ", " << midlename << " �����: " << adress << " " << adressnum << " ���� " << point << endl;
				SavingVector.push_back(Abiturients[i]);
			}
		}
		else {
			cout << "������� ���������� ��������, ������ 0 � �� ������ " << size(Abiturients) << endl;
		}
	} while (!(NumberAbiturients <= size(Abiturients) && NumberAbiturients > 0));
}

enum {
	yes = 1,
	no,
	End
};

void InputSaveFile(vector <Abiturient*>& SavingVector, string PathToSave) {
	ofstream fout;
	fout.open(PathToSave);
	for (int i = 0; i < size(SavingVector); i++) {
		if (i == size(SavingVector) - 1) {
			SavingVector[i]->SetInFile(fout);
		}
		else {
			SavingVector[i]->SetInFile(fout);
			fout << "\n";
		}
	}
	fout.close();
}

bool CheckCorrectNameFile(string PathToSave) {
	if (!std::filesystem::is_regular_file(PathToSave)) {
		return 1;
	}
	return 0;
}

void SaveInFile(vector <Abiturient*>& SavingVector) {
	int answer, answer2;
	ofstream fout;
	ifstream fin;
	string PathToSave;
	cout << "\n�� ������ ��������� ��������� ������?\n1)��\n2)���" << endl;
	do {
		answer = IntEnter();
		if (answer == yes) {
			cout << "������� ��� ����� � ����������� �� ������� �� ������ ��������� ����������" << endl;
			cin >> PathToSave;
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			if (ifstream(PathToSave)) {
				cout << "���� ���� ��� ����������" << endl;
				if (filesystem::is_regular_file(PathToSave)) {
					do{
						cout << "�� ������ ������������ ����, ��� ������� �����?\n1)������������\n2)������� �����" << endl;
						answer2 = IntEnter();
						if (answer2 == yes) {
							ofstream outputFile(PathToSave);
							if (!outputFile.is_open()) {
								cout << "�� ������� ������������ ����!" << endl;
							}	
							else {
								fout.open(PathToSave);
								InputSaveFile(SavingVector, PathToSave);
								cout << "���� �����������!" << endl;
								answer2 = End;
							}
						}
						else if (answer2 == no) {
							cout << "������� �� ������� ��� �����" << endl;
							cin >> PathToSave;
							cin.ignore((numeric_limits<streamsize>::max)(), '\n');
							if (filesystem::is_regular_file(PathToSave)) {
								if (ifstream(PathToSave)) {
									cout << "���� ���� ��� ����������" << endl;
								}
								else {
									fout.open(PathToSave);
									InputSaveFile(SavingVector, PathToSave);
									answer2 = End;
								}
							}
							else {
								cout << "������� ��������� ��� �����!" << endl;
							}
						}
					} while (!(answer2 == End));
				}
				else {
					cout << "������� ��������� ��� �����!" << endl;
				}
				fout.close();
				break;
			}
			else {
				if (!std::filesystem::is_regular_file(PathToSave)) {
					fout.open(PathToSave);
					InputSaveFile(SavingVector, PathToSave);
					cout << "������ ������� ��������� �� ����!" << endl;
				}
			}
		}
		else if (answer == no) {
			break;
		}
		else {
			cout << "������� ���������� ��������!" << endl;
		}
	} while (!(answer == yes || answer == no));
	SavingVector.clear();
}

enum {
	Task1 = 1,
	Task2,
	Task3,
	Task4,
	EXIT
};

void MenuInput(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector) {
	int answer;
	do {
		cout << "�� ������ ������������ ������ ��� �������� � ������������?\n1)�������� � ������������\n2)������������ �������� ������\n3)�����" << endl;
		answer = IntEnter();
		if (answer == Task1) {
			cout << "��� �� ������ ������ �������� ������?\n1)������ ����\n2)���� � �����" << endl;
			do {
				answer = IntEnter();
				if (answer == Task1) {
					InputInFileFromConsole(Abiturients , SavingVector);
					SortWithoutInput(Abiturients, SavingVector);
					SaveInFile(SavingVector);
				}
				else if (answer == Task2) {
					InputInFileFromFile(Abiturients, SavingVector);
					SortWithoutInput(Abiturients, SavingVector);
					SaveInFile(SavingVector);
				}
				else {
					cout << "������� ���������� ��������" << endl;
				}
			} while (!(answer == Task1 || answer == Task2));
		}
		else if (answer == Task2) {
			Abiturients.clear();
			cout << "��� �� ������ ������ �������� ������?\n1)������ ����\n2)���� � �����" << endl;
			do {
				answer = IntEnter();
				if (answer == Task1) {
					InputInFileFromConsole(Abiturients, SavingVector);
					SortWithoutInput(Abiturients, SavingVector);
					SaveInFile(SavingVector);
				}
				else if (answer == Task2) {
					InputInFileFromFile(Abiturients, SavingVector);
					SortWithoutInput(Abiturients, SavingVector);
					SaveInFile(SavingVector);
				}
				else {
					cout << "������� ���������� ��������" << endl;
				}
			} while (!(answer == Task1 || answer == Task2));
		}
		else if (answer == Task3) {
			break;
		}
		else {
			cout << "������� ���������� ��������" << endl;
		}
	} while (!(answer == Task1 || answer == Task2));
}