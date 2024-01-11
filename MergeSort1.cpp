#include<iostream>
using namespace std;

void merge(int Array[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* LeftArray = new int[n1];
	int* RightArray = new int[n2];

	for (int i = 0; i < n1; i++)
	{
		LeftArray[i] = Array[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		RightArray[j] = Array[mid + 1 + j];
	}


	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (LeftArray[i] <= RightArray[j])
		{
			Array[k] = LeftArray[i];
			i++;
		}
		else
		{
			Array[k] = RightArray[j];
			j++;
		}
		k++;

	}

	while (i < n1)
	{
		Array[k] = LeftArray[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		Array[k] = RightArray[j];
		j++;
		k++;
	}
	delete[] LeftArray;
	delete[] RightArray;
}


void MergeSort(int Array[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;


		MergeSort(Array, left, mid);
		MergeSort(Array, mid + 1, right);

		merge(Array, left, mid, right);
	}
}

void printArray(int Array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
}


int main()
{
	int Array[] = { 12,11,13,5,6,7 };
	int sizeOfArray = sizeof(Array) / sizeof(Array[0]);
//	cout << sizeOfArray; 

	cout << "Original Array: ";
	printArray(Array, sizeOfArray);

	MergeSort(Array, 0, sizeOfArray - 1);

	cout <<endl<< "Sorted Array: ";
	printArray(Array, sizeOfArray);

}







