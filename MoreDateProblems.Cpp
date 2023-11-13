
#pragma warning(disable : 4996)

#include <iostream>
using namespace std;



struct stDate {
	short Year;
	short Month;
	short Day;
};

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}


short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];

}

stDate GetSystemDate() {
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string  DayShortName(short DayWeekOrder)
{
	string ArrDayNames[] = { "Sun","Mon","Tue", "Wed","Thu","Fri","Sat" };
	return ArrDayNames[DayWeekOrder];

}

short IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
	//return (DayWeekOfOrder(Date) == 6 || (DayWeekOfOrder(Date) == 5));
}

bool IsBusinessDay(stDate Date)
{
	return (!IsWeekEnd(Date));
}


short DaysUntilTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);

}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate increaseDateByOneDay(stDate Date)
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
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = increaseDateByOneDay(Date1);

	}
	return IncludeEndDay ? ++Days : Days;
}

short DaysUntilTheEndOfMonth(stDate Date)
{
	stDate EndOfMontDate;

	EndOfMontDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
	EndOfMontDate.Month = Date.Month;
	EndOfMontDate.Year = Date.Year;

	return  GetDifferenceInDays(Date, EndOfMontDate, true);

}

short DaysUntilTheEndOfYear(stDate Date1)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date1.Year;

	return GetDifferenceInDays(Date1, EndOfYearDate, true);
}

int main()
{
	stDate Date1 = GetSystemDate();
	cout << "\nToday is  " << DayShortName(DayOfWeekOrder(Date1)) << " , "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	cout << "\nIs it End of Week?\n";
	if (IsEndOfWeek(Date1))
		cout << "Yes it is Saturday, it's of Week.";
	else
		cout << "No it's Not end of week.";

	/*************************************/

	cout << "\n\nIs it Weekend?\n";
	if (IsWeekEnd(Date1))
		cout << "Yes it is a week end.";
	else
		cout << "No today is " << DayShortName(DayOfWeekOrder(Date1)) << ", Not a weekend.";

	/*************************************/

	cout << "\n\nIs it Business Day?\n";
	if (IsBusinessDay(Date1))
		cout << "Yes it is a business day.";
	else
		cout << "No it is NOT a business day.";

	/*************************************/

	cout << "\n\nDays until end of week : ";
	cout << DaysUntilTheEndOfWeek(Date1) << " Day(s).";

	/*************************************/

	cout << "\nDays until end of month : "
		<< DaysUntilTheEndOfMonth(Date1) << " Day(s).";

	/*************************************/

	cout << "\nDays until end of year : "
		<< DaysUntilTheEndOfYear(Date1) << " Day(s).";

	return 0;
}
