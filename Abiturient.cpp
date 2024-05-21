#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include "Abiturient.h"


using namespace std;

void Abiturient::SetInfo(string Data_Name, string Data_SecondName, string Data_Midlename, string Data_Adress, string Data_Adressnum, int Data_Point) {
	name = Data_Name;
	secondname = Data_SecondName;
	midlename = Data_Midlename;
	adress = Data_Adress;
	adressnum = Data_Adressnum;
	points = Data_Point;
}

void Abiturient::SetInFile(ofstream& fout) const {
	
	fout << name << " ";
	fout << secondname << " ";
	fout << midlename << " ";
	fout << adress << " ";
	fout << adressnum << " ";
	fout << points;
}

const int Abiturient::GetPoint() const {
	return points;
}
const string& Abiturient::GetName() const {
	return name;
}
const string& Abiturient::GetSecondname() const {
	return secondname;
}
const string& Abiturient::GetMidlename() const {
	return midlename;
}
const string& Abiturient::GetAdress() const {
	return adress;
}
const string& Abiturient::GetAdressNum() const {
	return adressnum;
}

