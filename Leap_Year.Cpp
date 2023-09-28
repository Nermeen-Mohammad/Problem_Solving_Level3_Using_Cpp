#include<iostream>
using namespace std;

int ReadNumber()
{
	cout << "Enter year to check: ";
	short Year;
	cin >> Year;
	return Year;

}


bool IsLeapYear(int Year)
{
	if (Year % 400 == 0)
	{
		return true;
	}

	else if (Year % 100 == 0)
	{
		return false;
	}

	else if (Year & 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 
int main()
{


	short Year = ReadNumber();
	if (IsLeapYear(Year)== true)
	{
		cout << "\nYes, Year [" << Year << "] is a leap year.\n";
	}
	else
	{
		cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";
	}

	system("pause>0");
	return 0;
}