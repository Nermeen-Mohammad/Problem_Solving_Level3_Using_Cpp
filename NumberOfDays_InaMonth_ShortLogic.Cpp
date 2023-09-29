#include<iostream>
#include<iomanip>
using namespace std;

int ReadYear()
{
	cout << "Enter year to check: ";
	int Year;
	cin >> Year;
	return Year;

}

int ReadMonth()
{
	cout << "Enter month to check: ";
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

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return ((Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1]);


}


void PrintScreen(int Year, int Month)
{
	cout << setw(15) << "Number of days in month [" << Month << "] are " << Days(Year, Month);

}

int main()
{

	int Year = ReadYear();
	int Month = ReadMonth();

	PrintScreen(Year, Month);
	system("pause>0");
	return 0;
}