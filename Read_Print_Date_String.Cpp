#include <iostream>
#include <string>
#include<vector>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

vector <string> SplitString(string S, string Delim)
{

	vector <string> vString;

	short pos = 0;
	string sWord;
	while ((pos = S.find(Delim)) != std::string::npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S.erase(0, pos + Delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}

	return vString;


}


string ReadDateAsString()
{
	cout << "Please enter a date dd/mm/yyyy ? ";
	string date;
	getline(cin >> ws, date);
	return date;
}

stDate StringToDate(string DateString)
{
	stDate Date;
	vector <string> vDate;
	vDate = SplitString(DateString, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string DateToString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
	string DateString = ReadDateAsString();

	stDate Date = StringToDate(DateString);

	cout << "\nDay : " << Date.Day << endl;
	cout << "\nMonth : " << Date.Month << endl;
	cout << "\nYear : " << Date.Year << endl;

	cout << "\nYou Entered : " << DateToString(Date);

}

