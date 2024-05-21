#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Abiturient.h"
#include "Functions.h"

using namespace std;

int TestReadFile() {
    string pathToFile = "test.txt";
    vector <Abiturient*> Abiturients;
    ifstream inputFile(pathToFile);
    if (!inputFile.is_open()) {
        cerr << "Тестирование прошло неудачно! Не удалось открыть тестовый файл!" << endl;
        return 0;
    }
    else {
        int cntAbiturients = 3;
        int cntAbiturientFile = 0;
        string line;
        while (getline(inputFile, line)) {
            cntAbiturientFile++;
        }
        if (cntAbiturientFile == 0) {
            cout << "Тестирование прошло неудачно! Тестовый файл пуст!" << endl;
            return 0;
        }
        if (cntAbiturientFile < cntAbiturients) {
            cout << "Тестирование прошло неудачно! Тестовых данных в файле меньше, чем должно быть!" << endl;
            return 0;
        }
        inputFile.close();
        ifstream fin(pathToFile);
        for (int i = 0; i < cntAbiturients; i++) {
            string InfoFromFile = "";
            inputFile.clear();
            getline(fin, InfoFromFile);
            istringstream iss(InfoFromFile);
            string name; string secondname; string middlename; string address; string addressnum; int points;
            if (iss >> name >> secondname >> middlename >> address >> addressnum >> points) {
                if (points >= 0 && points <= 300) {
                    Abiturient* abiturient = new Abiturient(points, name, secondname, middlename, address, addressnum);
                    Abiturients.push_back(abiturient);
                }
                else {
                    cout << "Тестирование прошло неудачно! Данные в файле некорректны!" << endl;
                    cntAbiturients = 0;
                    return 0;
                }
            }
            else {
                cerr << "Тестирование прошло неудачно! Ошибка при чтении данных!" << endl;
                cntAbiturients = 0;
                return 0;
            }
        }
        string names[3] = { "Abc", "gfd", "lkd" };
        string secondnames[3] = { "wer", "zXc", "olt" };
        string middlenames[3] = { "GTr", "kEr", "wer" };
        string addresses[3] = { "kO", "yr", "hf" };
        string addressnums[3] = { "y", "s", "i" };
        int points[3] = { 123, 222, 85 };
        for (int i = 0; i < cntAbiturients; i++) {
            int point = Abiturients[i]->GetPoint();
            string name = Abiturients[i]->GetName();
            string secondname = Abiturients[i]->GetSecondname();
            string middlename = Abiturients[i]->GetMidlename();
            string address = Abiturients[i]->GetAdress();
            string addressnum = Abiturients[i]->GetAdressNum();
            if (name != names[i] || secondname != secondnames[i] || middlename != middlenames[i] || address != addresses[i] || addressnum != addressnums[i] || point != points[i]) {
                cout << "Тестирование прошло неудачно! Данные в файле некорректны либо были считаны неравильно!" << endl;
                return 0;
            }
        }
    }
    return 1;
}

int TestSort() {
    int cntAbiturients = 3;
    string names[3] = { "gfd", "Abc", "lkd" };
    string secondnames[3] = { "zXc", "wer", "olt" };
    string middlenames[3] = { "kEr", "GTr", "wer" };
    string addresses[3] = { "yr", "kO", "hf" };
    string addressnums[3] = { "s", "y", "i" };
    int points[3] = { 222, 123, 85 };
    string pathToFile = "test.txt";
    vector <Abiturient*> Abiturients;
    ifstream inputFile(pathToFile);
    if (!inputFile.is_open()) {
        cerr << "Тестирование прошло неудачно! Не удалось открыть тестовый файл!" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < cntAbiturients; i++) {
            string InfoFromFile = "";
            inputFile.clear();
            getline(inputFile, InfoFromFile);
            istringstream iss(InfoFromFile);
            string name; string secondname; string middlename; string address; string addressnum; int points1;
            if (iss >> name >> secondname >> middlename >> address >> addressnum >> points1) {
                if (points1 >= 0 && points1 <= 300) {
                    Abiturient* abiturient = new Abiturient(points1, name, secondname, middlename, address, addressnum);
                    Abiturients.push_back(abiturient);
                }
            }
        }
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
        for (int i = 0; i < cntAbiturients; i++) {
            int point = Abiturients[i]->GetPoint();
            string name = Abiturients[i]->GetName();
            string secondname = Abiturients[i]->GetSecondname();
            string middlename = Abiturients[i]->GetMidlename();
            string address = Abiturients[i]->GetAdress();
            string addressnum = Abiturients[i]->GetAdressNum();
            if (name != names[i] || secondname != secondnames[i] || middlename != middlenames[i] || address != addresses[i] || addressnum != addressnums[i] || point != points[i]) {
                cout << "Тестирование прошло неудачно! Данные в файле некорректны либо были считаны неравильно!" << endl;
                return 0;
            }
        }
    }
    return 1;
}

int TestOutputTopAbiturients() {
    int cntAbiturients = 3;
    string names[1] = { "gfd" };
    string secondnames[1] = { "zXc" };
    string middlenames[1] = { "kEr" };
    string addresses[1] = { "yr" };
    string addressnums[1] = { "s" };
    int points[1] = { 222};
    string pathToFile = "test.txt";
    vector <Abiturient*> Abiturients;
    ifstream inputFile(pathToFile);
    if (!inputFile.is_open()) {
        cerr << "Тестирование прошло неудачно! Не удалось открыть тестовый файл!" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < cntAbiturients; i++) {
            string InfoFromFile = "";
            inputFile.clear();
            getline(inputFile, InfoFromFile);
            istringstream iss(InfoFromFile);
            string name; string secondname; string middlename; string address; string addressnum; int points1;
            if (iss >> name >> secondname >> middlename >> address >> addressnum >> points1) {
                if (points1 >= 0 && points1 <= 300) {
                    Abiturient* abiturient = new Abiturient(points1, name, secondname, middlename, address, addressnum);
                    Abiturients.push_back(abiturient);
                }
            }
        }
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
        int NumberAbiturients = 1;
        if (NumberAbiturients <= size(Abiturients) && NumberAbiturients > 0) {
            for (int i = 0; i < NumberAbiturients; i++) {
                int point = Abiturients[i]->GetPoint();
                string name = Abiturients[i]->GetName();
                string secondname = Abiturients[i]->GetSecondname();
                string middlename = Abiturients[i]->GetMidlename();
                string address = Abiturients[i]->GetAdress();
                string addressnum = Abiturients[i]->GetAdressNum();
                if (name != names[i] || secondname != secondnames[i] || middlename != middlenames[i] || address != addresses[i] || addressnum != addressnums[i] || point != points[i]) {
                    cout << "Тестирование прошло неудачно! Данные в файле некорректны либо были считаны неравильно!" << endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}

int TestArrOutputPoints() {
    int cntAbiturients = 3;
    string names[2] = { "Abc", "gfd"};
    string secondnames[2] = { "wer", "zXc"};
    string middlenames[2] = { "GTr", "kEr"};
    string addresses[2] = { "kO", "yr"};
    string addressnums[2] = { "y", "s"};
    int points[2] = { 123, 222};
    string pathToFile = "test.txt";
    vector <Abiturient*> Abiturients;
    ifstream inputFile(pathToFile);
    if (!inputFile.is_open()) {
        cerr << "Тестирование прошло неудачно! Не удалось открыть тестовый файл!" << endl;
        return 0;
    }
    else {
        for (int i = 0; i < cntAbiturients; i++) {
            string InfoFromFile = "";
            inputFile.clear();
            getline(inputFile, InfoFromFile);
            istringstream iss(InfoFromFile);
            string name; string secondname; string middlename; string address; string addressnum; int points1;
            if (iss >> name >> secondname >> middlename >> address >> addressnum >> points1) {
                if (points1 >= 0 && points1 <= 300) {
                    Abiturient* abiturient = new Abiturient(points1, name, secondname, middlename, address, addressnum);
                    Abiturients.push_back(abiturient);
                }
            }
        }
        int PointMore = 100;
        if (PointMore >= 0 && PointMore <= 300) {
            for (int i = 0; i < size(Abiturients); i++) {
                int point = Abiturients[i]->GetPoint();
                if (point >= PointMore) {
                    string name = Abiturients[i]->GetName();
                    string secondname = Abiturients[i]->GetSecondname();
                    string middlename = Abiturients[i]->GetMidlename();
                    string address = Abiturients[i]->GetAdress();
                    string addressnum = Abiturients[i]->GetAdressNum();
                    if (name != names[i] || secondname != secondnames[i] || middlename != middlenames[i] || address != addresses[i] || addressnum != addressnums[i] || point != points[i]) {
                        cout << "Тестирование прошло неудачно! Данные в файле некорректны либо были считаны неравильно!" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int TestInputInClass() {
    string testname = "Denis";
    string testsecondname = "Brus";
    string testmiddlename = "Oleg";
    string testaddress = "Zapad";
    string testaddressnum = "50a";
    int testpoint = 15;
    vector <Abiturient*> Abiturients;
    string name = "Denis"; string secondname = "Brus"; string middlename = "Oleg"; string address = "Zapad"; string addressnum = "50a"; int points = 15;
    Abiturient* abiturient = new Abiturient(points, name, secondname, middlename, address, addressnum);
    Abiturients.push_back(abiturient);
    int point2 = Abiturients[0]->GetPoint();
    string name2 = Abiturients[0]->GetName();
    string secondname2 = Abiturients[0]->GetSecondname();
    string middlename2 = Abiturients[0]->GetMidlename();
    string address2 = Abiturients[0]->GetAdress();
    string addressnum2 = Abiturients[0]->GetAdressNum();
    if (name2 != testname || secondname2 != testsecondname || middlename2 != testmiddlename || address2 != testaddress || addressnum2 != testaddressnum || point2 != testpoint) {
        cout << "Тестирование прошло неудачно! Данные в файле некорректны либо были считаны неравильно!" << endl;
        return 0;
    }
    return 1;
}

void Test() {
    if (TestReadFile() == 1) {
        if (TestSort() == 1) {
            if (TestOutputTopAbiturients() == 1) {
                if (TestArrOutputPoints() == 1) {
                    if (TestInputInClass() == 1) {
                       cout << "Тестирование прошло успешно!" << endl;
                    }
                }
            }
        }
    }
}