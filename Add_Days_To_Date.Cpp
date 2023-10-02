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

int ReadDaysToAdd()
{
	cout << "How many days to add ?  ";
	int AddDay;
	cin >> AddDay;
	return AddDay;
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

sDate ReadFullDate()
{
	sDate Date;
	Date.Year  = ReadYear();
	Date.Month = ReadMonth();
	Date.Day   = ReadDay();

	return Date;
}

sDate DateAddDays(sDate Date, int Days)
{
	int RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Year, Date.Month, Date.Day);

	short MonthDays = 0;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}

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

		sDate  Date = ReadFullDate();
	    int AddDays = ReadDaysToAdd();
		
		Date = DateAddDays(Date, AddDays);
		cout << "\nDate After Adding [" << AddDays << "] days is : ";
		cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

		system("pause>0");
		return 0;
	}