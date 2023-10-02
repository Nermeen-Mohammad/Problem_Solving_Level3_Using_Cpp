#include<iostream>
#include<iomanip>
using namespace std;

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short ReadYear()
{
	cout << "Enter a year: ";
	int Year;
	cin >> Year;
	return Year;

}

short ReadMonth()
{
	cout << "Enter a month: ";
	int Month;
	cin >> Month;
	return Month;

}

short ReadDay()
{
	cout << "Enter a day: ";
	int Day;
	cin >> Day;
	return Day;
}

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate ReadFullDate()
{
	sDate Date;
	Date.Year  = ReadYear();
	Date.Month = ReadMonth();
	Date.Day   = ReadDay();

	return Date;
}

short NumbersOfDaysInMonth(sDate Date)
{
	if (Date.Month > 12 || Date.Month < 1)
		return 0;

	short ArrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
	if (Date.Month == 2)
	{
		if (IsLeapYear(Date.Year))
			return 29;
		else
			return 28;
	}
	else
	{
		return ArrDays[Date.Month - 1];
	}
}

bool IsLastMonth(sDate Date)
{
return	Date.Month == 12;
}

bool IsLastDay(sDate Date)
{
	return (Date.Day==NumbersOfDaysInMonth(Date));
	
}

	int main()
	{

		sDate  Date1 = ReadFullDate();
		cout << endl;
		
		if (IsLastMonth(Date1))
			cout << "\n Yes,Month is last month in year.";
		else 
			cout << "\n No,Month is NOT last month in year.";


		if (IsLastDay(Date1))
			cout << "\n Yes,Day is last Day in Month.";
		else
			cout << "\n No,Day is NOT last Day in Month.";
		
		system("pause>0");
		return 0;
	}