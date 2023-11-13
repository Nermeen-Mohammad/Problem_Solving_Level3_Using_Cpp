
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}
bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AftereDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return  0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
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

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun", "Mon", "Tue","Wed", "Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}

bool IsWeekEnd(stDate Date)
{
	//Weekends are Fri and Sat 
	short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	return  (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);
}

stDate ReadFullDate()
{
	stDate Date;

	cout << "Please enter a Day? ";
	cin >> Date.Day;
	cout << "\nPlease enter a Month? ";
	cin >> Date.Month;
	cout << "\nPlease enter a Year? ";
	cin >> Date.Year;

	return Date;
}


enum CompareDate { Equal = 0, After=1, Before=-1};

CompareDate CompareDateFunction(stDate Date1, stDate Date2)
{
	if (IsDate1AftereDate2(Date1, Date2))
		return CompareDate::After;

	if (IsDate1BeforeDate2(Date1, Date2))
		return CompareDate::Before;

	return CompareDate::Equal;
}


int main()
{
	cout << "\nEnter Date1:\n";
	stDate Date1 = ReadFullDate();

	cout << "\nEnter Date2:\n";
	stDate Date2 = ReadFullDate();

	cout << "\n\nCompare Result  : " << CompareDateFunction(Date1, Date2);


	


	system("pause > 0");
	return 0;
}
