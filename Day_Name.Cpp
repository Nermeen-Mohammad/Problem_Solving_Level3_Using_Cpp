#include<iostream>
#include<iomanip>
using namespace std;

short DayOfWeekOrder(int Year, int Month, int Day)
{
	short a, m, y;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	//Gregorian ... sun=0 mon=1
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayName[7] = { "Sun", "Mon", "Tue","Wed", "Thu", "Fri", "Sat" };
	return arrDayName[DayOfWeekOrder];
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

short ReadDay()
{
	cout << "Enter a day to check: ";
	int Month;
	cin >> Month;
	return Month;

}

void PrintScreen(int Year, int Month, int Day)
{
	cout << endl;
	cout << "Date      :" <<Year <<'\\' <<Month <<'\\' << Day <<endl;
	cout << "Day Order :" << DayOfWeekOrder(Year,Month,Day)<<endl;
	cout << "Day Name  :" << DayShortName(DayOfWeekOrder(Year, Month, Day))<<endl;

}

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	PrintScreen(Year, Month,Day);
	system("pause>0");
	return 0;
}