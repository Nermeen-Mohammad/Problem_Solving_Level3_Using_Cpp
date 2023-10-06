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
	Date.Year = ReadYear();
	Date.Month = ReadMonth();
	Date.Day = ReadDay();

	return Date;
}

short NumbersOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
		return 0;

	short ArrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Month == 2)
	{
		if (IsLeapYear(Year))
			return 29;
		else
			return 28;
	}
	else
	{
		return ArrDays[Month - 1];
	}
}

bool IsLastDayInMonth(sDate Date)
{
	return (Date.Day == NumbersOfDaysInMonth(Date.Year, Date.Month));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

sDate DateAfterSubtractingOneDay(sDate& Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
			Date.Day = 31;
		}
		else
		{
			Date.Month--;
			Date.Day = NumbersOfDaysInMonth(Date.Year, Date.Month);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

sDate DateAfterSubtractingXDays(sDate& Date, short DaysToAdd)
{
	for (int i = 1; i <= DaysToAdd; i++) 
	{
		Date = DateAfterSubtractingOneDay(Date);
	}
	return Date;
}

sDate DateAfterSubtractingOneWeek(sDate& Date)
{
	for (int i = 1; i <= 7; i++) 
	{
		Date = DateAfterSubtractingOneDay(Date);
	}
	return Date;
}

sDate DateAfterSubtractingXWeeks(sDate& Date, short WeeksToAdd)
{
	for (int i = 1; i <= WeeksToAdd; i++) 
	{
		Date = DateAfterSubtractingOneWeek(Date);
	}
	return Date;
}

sDate DateAfterSubtractingOneMonth(sDate& Date)
{
	
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDays = NumbersOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > NumberOfDays)
	{
		Date.Day = NumberOfDays;
	}

	return Date;
}

sDate DateAfterSubtractingXMonths(sDate& Date, short MonthsToAdd)
{
	for (int i = 1; i <= MonthsToAdd; i++) 
	{
		Date = DateAfterSubtractingOneMonth(Date);
	}
	return Date;
}

sDate DateAfterSubtractingOneYear(sDate& Date)
{
	 Date.Year--;
	 return Date;
}

sDate DateAfterSubtractingXYears(sDate Date, short YearsToAdd)
{

	for (int i = 1; i <= YearsToAdd; i++)
	{
		Date = DateAfterSubtractingOneYear(Date);
	}
	return Date;
}

sDate DateAfterSubtractingXYearsFaster(sDate Date, short YearsToAdd)
{
	Date.Year -= YearsToAdd;
	return Date;
}

sDate DateAfterSubtractingOneDecade(sDate Date)
{
	Date.Year -= 10;
	return Date;
}

sDate DateAfterSubtractingXDecades(sDate& Date, short DecadesToAdd)
{
	for (int i = 1; i <= DecadesToAdd*10; i++)
	{
		Date = DateAfterSubtractingOneYear(Date);
	}
	return Date;
}

sDate DateAfterSubtractingXDecadesFaster(sDate& Date, short DecadesToAdd)
{
	Date.Year -= DecadesToAdd * 10;
	return Date;
}

sDate DateAfterSubtractingOneCentury(sDate& Date)
{
	Date.Year -=  100;
	return Date;
}

sDate DateAfterSubtractingOneMillennium(sDate& Date)
{
	Date.Year -= 1000;
	return Date;
}

void PrintScreen()
{
	sDate  Date1 = ReadFullDate();
	

	cout << "\n++ Date After ++\n\n";

	Date1 = DateAfterSubtractingOneDay(Date1);
	cout << "Subtracting One Day Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

	Date1 = DateAfterSubtractingXDays(Date1,10);
	cout << "Subtracting 10 Days Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

	Date1 = DateAfterSubtractingOneWeek(Date1);
	cout << "Subtracting One Week Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingXWeeks(Date1,10);
	cout << "Subtracting 10 Weeks Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingOneMonth(Date1);
	cout << "Subtracting One Month Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingXMonths(Date1, 5);
	cout << "Subtracting 5 Months Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingOneYear(Date1);
	cout << "Subtracting One Year Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingXYears(Date1,10);
	cout << "Subtracting 10 Years Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingXYearsFaster(Date1, 10);
	cout << "Subtracting 10 Years(Faster) Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingOneDecade(Date1);
	cout << "Subtracting One Decade Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingXDecades(Date1,10);
	cout << "Subtracting 10 Decades Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingXDecadesFaster(Date1, 10);
	cout << "Subtracting 10 Decades(Faster) Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingOneCentury(Date1);
	cout << "Subtracting One Century Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterSubtractingOneMillennium(Date1);
	cout << "Subtracting One Millennium Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
}

int main()
{

	
	
	
	PrintScreen();





	system("pause>0");
	return 0;
}