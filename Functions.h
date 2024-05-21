#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>


int IntPointEnter();

int IntEnter();

void Info();

void InputInFileFromConsole(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector);

int ReadFromFile(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector, string);

void InputInFileFromFile(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector);

void SortWithoutInput(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector);

void Sort(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector);

void ArrOutputPoints(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector);

void OutputTopAbiturients(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector);

void InputSaveFile(vector <Abiturient*>& SavingVector, string);

void SaveInFile(vector <Abiturient*>& SavingVector);

void MenuInput(vector <Abiturient*>& Abiturients, vector <Abiturient*>& SavingVector);

