#include<iostream>
#include<iomanip>
using namespace std;


bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1) {
		return 0;
	}
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short DayOfWeekOrder(int Year, int Month, int Day)
{
	short a, m, y;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	//Gregorian ... sun=0 mon=1
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short ReadYear()
{
	cout << "Enter a year to check: ";
	int Year;
	cin >> Year;
	return Year;

}

short ReadMonth()
{
	cout << "Enter a month to check: ";
	int Month;
	cin >> Month;
	return Month;

}

short ReadDay()
{
	cout << "Enter a day to check: ";
	int Day;
	cin >> Day;
	return Day;
}

int NumberOfDaysFromTheBeginingOfTheYear(short Year,short Month, short Day)
{
	int TotalNumber = 0;
	for (short i = 1; i <= Month; i++)
	{
		 TotalNumber += NumberOfDaysInMonth(Year,i);
	}
	return (TotalNumber -(NumberOfDaysInMonth(Year, Month)- Day));
	  
    // int TotalNumber = 0;
	// for (short i = 1; i <= Month-1; i++)
	// {
	// 	TotalNumber += NumberOfDaysInMonth(Year, i);
	// }
	// return TotalNumber+ Day ;
}

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout <<"Total Days : " << NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);

	system("pause>0");
	return 0;
}