//#define D_HAS_STD_BYTE = 0
#include <string>

using namespace std;

class Abiturient {
private:
	int points = 0;
	string name, secondname, midlename, adress, adressnum;

public:
	Abiturient() {}

	Abiturient(int b, const string& n, const string& sn, const string& mn, const string& a, const string& an)
		: points(b), name(n), secondname(sn), midlename(mn), adress(a), adressnum(an) {}

	void SetInfo(string, string, string, string, string, int);
	
	void SetInFile(ofstream&) const;

	const int GetPoint() const;

	const string& GetName() const;

	const string& GetSecondname() const;

	const string& GetMidlename() const;

	const string& GetAdress() const;

	const string& GetAdressNum() const;
};