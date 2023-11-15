
#include <iostream>
using namespace std;



struct stDate {
	short Year;
	short Month;
	short Day;
};

struct stPeriod {

	stDate StartDate;
	stDate EndDate;

};

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

enum CompareDate { Before = -1, Equal = 0, After = 1  };

CompareDate CompareDateFunction(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2)) return CompareDate::Before;
	if (IsDate1EqualDate2(Date1, Date2)) return CompareDate::Equal;

	/* if (IsDate1AfterDate2(Date1,Date2))    
	return enDateCompare::After;*/

	//this is faster
	return CompareDate::After; 
}

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

stPeriod ReadPeriod()
{
	stPeriod period;
	cout << "\nEnter Start Date\n";
	period.StartDate = ReadFullDate();

	cout << "\nEnter End Date \n";
	period.EndDate = ReadFullDate();


	return period;
}

int PeriodLengthInDays(stPeriod period, bool EncludeEndDate = false)
{
	return (GetDifferenceInDays(period.StartDate, period.EndDate, EncludeEndDate));
}

int main()
{

	cout << "\n\nEnter period 1 \n";
	stPeriod period1 = ReadPeriod();

	cout << "\nPeriod Length is: " << PeriodLengthInDays(period1);   
	cout << "\nPeriod Length (Including End Date) is: " << PeriodLengthInDays(period1, true);
	


	


	system("pause > 0");
	return 0;
}
