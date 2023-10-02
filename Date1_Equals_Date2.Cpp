#include<iostream>
#include<iomanip>
using namespace std;

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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{ 
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	
}
	int main()
	{

		sDate  Date1 = ReadFullDate();
		cout << endl;
		sDate  Date2 = ReadFullDate();
	    
		if (IsDate1BeforeDate2(Date1, Date2))
		
			cout << "\nYes, Date1 is equal Date2.";
		else
			cout << "\nNo, Date1 is NOT equal Date2.";
		
		system("pause>0");
		return 0;
	}