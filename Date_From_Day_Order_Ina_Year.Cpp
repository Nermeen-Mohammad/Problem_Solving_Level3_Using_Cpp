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

int NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
{
	int TotalNumber = 0;
	for (short i = 1; i <= Month-1; i++)
	{
		TotalNumber += NumberOfDaysInMonth(Year, i);
	}
	return TotalNumber+Day;

}

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate GetDateFromDayOrderInYear(short Year, int TotalDays)
{
	sDate Date;
	Date.Year = Year;
	Date.Month = 1;

	short RemainingDays = TotalDays;
	short MonthDays = 0;

	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Year, Date.Month);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}

	}
	return Date;
}

	int main()
	{

		short Year = ReadYear();
		short Month = ReadMonth();
		short Day = ReadDay();
		int TotalDays = NumberOfDaysFromTheBeginingOfTheYear(Year, Month, Day);

		cout << "Number of days from the begining of the year is : " << TotalDays;
		
		sDate Date;
		Date = GetDateFromDayOrderInYear(Year, TotalDays);
		cout << "Date for [" << TotalDays << "] is : \n";
		cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


		system("pause>0");
		return 0;
	}