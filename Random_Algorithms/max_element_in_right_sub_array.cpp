#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 11
int result_arr [SIZE];

using namespace std;

void swap (int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void  GetMaxInRightSubArrayForEachElem (int arr[] , int left_idx, int right_idx)
{
	int max_elem = -1;
	for (int i= right_idx; i >= left_idx; i--)
	{
		if (arr[i] >= max_elem)
		{
			max_elem = arr[i];
			result_arr[i] = -1;
			continue;
		}
		else
		{
			result_arr[i] = max_elem;
			continue;
		}
	}	

}

int main ()
{

	int arr[SIZE];
	srand (time (NULL));

	for (int i=0; i < SIZE; i++)
	{
		arr[i] = rand () % 20 + 1;
		cout << arr[i] << " , " ;
	}
	cout << endl;

	GetMaxInRightSubArrayForEachElem (arr, 0, (SIZE-1) );
	
	for (int i=0; i < SIZE; i++)
	{
		cout << result_arr[i] << " , " ;
	}


	return 0;
}
