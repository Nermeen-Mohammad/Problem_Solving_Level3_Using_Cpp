#include<iostream>
#include<iomanip>
using namespace std;

int ReadYear()
{
	cout << "Enter year : ";
	int Year;
	cin >> Year;
	return Year;

}

int ReadMonth()
{
	cout << "Enter a month to check: ";
	int Month;
	cin >> Month;
	return Month;

}

bool IsLeapYear(int Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

int Days(int Year, int Month)
{
	if (Month > 12 || Month < 1)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short Array31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 0; i < 7; i++)
	{
		if (Month == Array31Days[i])
			return 31;
	}

	return 30;


}

int Hours(int Year,int Month)
{

	return Days(Year,Month) * 24;

}

int Minutes(int Year, int Month)
{
	return Hours(Year, Month) * 60;

}

int Second(int Year, int Month)
{
	return Minutes(Year,Month) * 60;

}

void PrintScreen(int Year,int Month)
{
	cout << setw(30) << "Number of days in month [" << Month << "] are " << Days(Year, Month)<<endl;
	cout << setw(30) << "Number of Hours in month [" << Month << "] are " << Hours(Year, Month)<<endl;
	cout << setw(30) << "Number of Minutes in month [" << Month << "] are " << Minutes(Year, Month)<<endl;
	cout << setw(30) << "Number of Seconds in month [" << Month << "] are " << Second(Year, Month)<<endl;
}

int main()
{


	int Year = ReadYear();
	int Month = ReadMonth();

	

	PrintScreen(Year,Month);


	system("pause>0");
	return 0;
}