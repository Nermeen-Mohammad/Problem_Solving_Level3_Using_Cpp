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
	return (Year % 100 != 0 && Year & 4 == 0) || (Year % 400 == 0)  ;


}
 
int main()
{


	short Year = ReadNumber();
	if (IsLeapYear(Year))
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