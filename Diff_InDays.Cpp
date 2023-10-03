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

short NumbersOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
		return 0;

	short ArrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

}

sDate DateAfterAddingOneDay(sDate Date)
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

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay=false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = DateAfterAddingOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

	int main()
	{

		sDate  Date1 = ReadFullDate();
		cout << endl;
		sDate Date2 = ReadFullDate();

	
		cout << "\nDiffrence is: " << GetDifferenceInDays (Date1, Date2) << " Day(s)."; 
		cout << "\nDiffrence (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s).";


		
		system("pause>0");
		return 0;
	}