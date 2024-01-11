#include<iostream>
using namespace std;



    void merge(int ArrayB[], int ArrayC[], int ArrayA[], int SizeofB, int SizeofC) {  // i index of B , j index of C , k index of A
        int i = 0, j = 0, k = 0; 
        while (i < SizeofB && j < SizeofC)
        { 
            if (ArrayB[i] <= ArrayC[j]) { 
                ArrayA[k] = ArrayB[i]; // Copy it to A
                i++; // Increment the index of B
            }
            else { 
                ArrayA[k] = ArrayC[j]; // Copy the current element of C to A
                j++; // Increment the index of C
            }
            k++; // Increment the index of A
        }
        // At this point, either B or C is exhausted
        if (i == SizeofB) { 
           copy(ArrayC + j, ArrayC + SizeofC, ArrayA + k); // Copy the remaining elements of C to A
        }
        else { 
            copy(ArrayB + i, ArrayB + SizeofB, ArrayA + k); // Copy the remaining elements of B to A
        }
    }

    void printArray(int Array[], int size) {
        for (int i = 0; i < size; i++)
            cout << Array[i] << " ";
        cout << endl;
    }

    int main()
    {

        int ArrayA[6] ;
        int ArrayB[3] = { 3,9,17 }, ArrayC[3] = { 2,6,10 };

        merge(ArrayB, ArrayC, ArrayA, 3, 3);

        cout << "Merged array: ";
        printArray(ArrayA, 6);

        return 0;
    }