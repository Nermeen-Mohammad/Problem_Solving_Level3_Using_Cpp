#include<iostream>
#include<iomanip>
using namespace std;


bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month > 12 || Month < 1)
		return 0;

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

string ShortDayName(short DayOfWeekOrder)
{
	string arrMonthName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	return arrMonthName[DayOfWeekOrder];
}

string ShortMonthName(int Month)
{
	string arrMonthName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return arrMonthName[Month - 1];
}

short ReadYear()
{
	cout << "Enter a year to check: ";
	int Year;
	cin >> Year;
	return Year;

}

short ReadMonth()
{
	cout << "Enter a month to check: ";
	int Month;
	cin >> Month;
	return Month;

}

void PrintCalendarScreen(int Year,int Month)
{

	int Current = DayOfWeekOrder(Year, Month, 1);
	int NumberOfDays = NumberOfDaysInMonth(Year, Month);
	
	cout << endl;
	printf("________________%s________________\n\n",
	ShortMonthName(Month).c_str());
	printf("Sun   Mon   Tue  Wed  Thu  Fri  Sat\n");

		int i;
	for (i = 0; i < Current; i++)
	{
		printf("     ");
	}
	
	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
	

	cout << "\n____________________________________\n";
}                            

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();
	PrintCalendarScreen(Year, Month);


	system("pause>0");
	return 0;
}