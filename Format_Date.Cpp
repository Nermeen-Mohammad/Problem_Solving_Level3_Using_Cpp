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

string ReplaceWordInString(string s1, string StringToReplace, string sRepalceTo)
{
	short pos = s1.find(StringToReplace) ;
	while (pos != std::string::npos)
	{
		s1 = s1.replace(pos, StringToReplace.length(), sRepalceTo);
		pos = s1.find(StringToReplace);

	}
	return s1;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{

	string FormattedDateString = "";
	FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

	return FormattedDateString;
}

int main()
{
	string DateString = ReadDateAsString();

	stDate Date = StringToDate(DateString);
	cout << "\n" << FormateDate(Date) << "\n"; 
	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << endl;
	cout << "\n" << FormateDate(Date, "mm.dd.yyyy") << "\n"; 
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";  
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";  
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
	
	system("pause>0");
	return 0;

}

