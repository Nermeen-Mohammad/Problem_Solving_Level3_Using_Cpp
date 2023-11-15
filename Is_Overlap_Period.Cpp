
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


bool IsOverlapPeriods(stPeriod period1, stPeriod period2)
{
	if
		(
			CompareDateFunction(period2.EndDate, period1.StartDate) == CompareDate::Before
			||
			CompareDateFunction(period2.StartDate, period1.EndDate) == CompareDate::After
			)
	{
		return false;
	}
	else
	{
		return true;
	}
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


int main()
{

	cout << "\n\nEnter period 1 \n";
	stPeriod period1 = ReadPeriod();

	cout << "\n\nEnter period 2 \n";
	stPeriod period2 = ReadPeriod();

	
	if (IsOverlapPeriods(period1, period2)) 
		cout << "\nYes, Periods Overlap\n";
	else       
		cout << "\nNo, Periods do not Overlap\n";

	


	system("pause > 0");
	return 0;
}
