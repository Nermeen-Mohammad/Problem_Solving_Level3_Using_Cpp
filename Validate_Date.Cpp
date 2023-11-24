

#include <iostream>
using namespace std;


struct stDate {
	short Year;
	short Month;
	short Day;
};


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

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

bool IsValidateDate(stDate Date)
{
	if (Date.Year <= 0 || Date.Month <= 0 || Date.Day <= 0)
		return false;
	if (Date.Day != Days(Date.Year, Date.Month))
		return false;
	if (Date.Month < 1 || Date.Month > 12)
		return false;

	else
		return true;
}




int main()
{
	if (IsValidateDate(ReadFullDate()) == true)
		cout << "\nYes,is a valid date\n";
	else
		cout << "\nNo,is Not a valid date\n";
}

