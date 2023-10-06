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

sDate DateAfterAddingOneDay(sDate& Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
			Date.Day = 1;

		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

sDate DateAfterAddingXDays(sDate& Date, short DaysToAdd)
{
	for (int i = 1; i <= DaysToAdd; i++) 
	{
		Date = DateAfterAddingOneDay(Date);
	}
	return Date;
}

sDate DateAfterAddingOneWeek(sDate& Date)
{
	for (int i = 1; i <= 7; i++) 
	{
		Date = DateAfterAddingOneDay(Date);
	}
	return Date;
}

sDate DateAfterAddingXWeeks(sDate& Date, short WeeksToAdd)
{
	for (int i = 1; i <= WeeksToAdd; i++) 
	{
		Date = DateAfterAddingOneWeek(Date);
	}
	return Date;
}

sDate DateAfterAddingOneMonth(sDate& Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short NumbersOfDaysInCurrentMonth = NumbersOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > NumbersOfDaysInCurrentMonth)
	{
		Date.Day = NumbersOfDaysInCurrentMonth;
	}

	return Date;
}

sDate DateAfterAddingXMonths(sDate& Date, short MonthsToAdd)
{
	for (int i = 1; i <= MonthsToAdd; i++) 
	{
		Date = DateAfterAddingOneMonth(Date);
	}
	return Date;
}

sDate DateAfterAddingOneYear(sDate& Date)
{
	 Date.Year++;
	 return Date;
}

sDate DateAfterAddingXYears(sDate Date, short YearsToAdd)
{

	for (int i = 1; i <= YearsToAdd; i++)
	{
		Date = DateAfterAddingOneYear(Date);
	}
	return Date;
}

sDate DateAfterAddingXYearsFaster(sDate Date, short YearsToAdd)
{
	Date.Year += YearsToAdd;
	return Date;
}

sDate DateAfterAddingOneDecade(sDate Date)
{
	Date.Year += 10;
	return Date;
}

sDate DateAfterAddingXDecades(sDate& Date, short DecadesToAdd)
{
	for (int i = 1; i <= DecadesToAdd*10; i++)
	{
		Date = DateAfterAddingOneYear(Date);
	}
	return Date;
}

sDate DateAfterAddingXDecadesFaster(sDate& Date, short DecadesToAdd)
{
	Date.Year += DecadesToAdd * 10;
	return Date;
}

sDate DateAfterAddingOneCentury(sDate& Date)
{
	Date.Year +=  100;
	return Date;
}

sDate DateAfterAddingOneMillennium(sDate& Date)
{
	Date.Year += 1000;
	return Date;
}

void PrintScreen()
{
	sDate  Date1 = ReadFullDate();
	

	cout << "\n++ Date After ++\n\n";

	Date1 = DateAfterAddingOneDay(Date1);
	cout << "Adding One Day Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

	Date1 = DateAfterAddingXDays(Date1,10);
	cout << "Adding 10 Days Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year<<endl;

	Date1 = DateAfterAddingOneWeek(Date1);
	cout << "Adding One Week Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingXWeeks(Date1,10);
	cout << "Adding 10 Weeks Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingOneMonth(Date1);
	cout << "Adding One Month Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingXMonths(Date1, 10);
	cout << "Adding 10 Months Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingOneYear(Date1);
	cout << "Adding One Year Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingXYears(Date1,10);
	cout << "Adding 10 Years Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;


	Date1 = DateAfterAddingXYearsFaster(Date1, 10);
	cout << "Adding 10 Years(Faster) Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingOneDecade(Date1);
	cout << "Adding One Decade Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingXDecades(Date1,10);
	cout << "Adding 10 Decades Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingXDecadesFaster(Date1, 10);
	cout << "Adding 10 Decades(Faster) Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingOneCentury(Date1);
	cout << "Adding One Century Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DateAfterAddingOneMillennium(Date1);
	cout << "Adding One Millennium Is : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;
}

int main()
{

	
	
	
	PrintScreen();





	system("pause>0");
	return 0;
}