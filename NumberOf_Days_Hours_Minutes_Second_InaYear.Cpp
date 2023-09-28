#include<iostream>
#include<iomanip>
using namespace std;

int ReadNumber()
{
	cout << "Enter year to check: ";
	int Year;
	cin >> Year;
	return Year;

}

bool IsLeapYear(int Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

int Days(int Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

int Hours(int Year)
{

	return Days(Year) * 24;

}

int Minutes(int Year)
{
	return Hours(Year) * 60;

}

int Second(int Year)
{
	return Minutes(Year) * 60;

}

void PrintScreen(int Year)
{
	cout << setw(30) << "Number of days in year [" << Year << "] are " << Days(Year)<<endl;
	cout << setw(30) << "Number of Hours in year [" << Year << "] are " << Hours(Year)<<endl;
	cout << setw(30) << "Number of Minutes in year [" << Year << "] are " << Minutes(Year)<<endl;
	cout << setw(30) << "Number of Seconds in year [" << Year << "] are " << Second(Year)<<endl;
}

int main()
{


	int Year = ReadNumber();
	PrintScreen(Year);


	system("pause>0");
	return 0;
}