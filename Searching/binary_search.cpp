#include <iostream>

using namespace std;

int BinarySearch (int arr[], int left_idx, int right_idx, int to_find )
{
	int mid_idx = (left_idx+right_idx)/2;
	
	while (left_idx <= right_idx)
	{
		mid_idx = (left_idx+right_idx)/2;
		cout << " Left Idx, Right Idx =  " << left_idx << " , " << right_idx << ". Mid Idx = " << mid_idx << std::endl;
		
		if (arr[mid_idx] == to_find)
		{
			return mid_idx;
		}
		if (to_find < arr[mid_idx] )
		{
			right_idx = mid_idx -1;
		}
		else
		{
			left_idx = mid_idx + 1;
		}
	}
	return -1;
}

int BinarySearchRecrr (int arr[], int left_idx, int right_idx, int to_find )
{
	if (left_idx > right_idx)
	{
		return -1;
	}
	
	int mid_idx = (left_idx+right_idx)/2;
	cout << " Left Idx, Right Idx =  " << left_idx << " , " << right_idx << ". Mid Idx = " << mid_idx << std::endl;
	
	if (arr[mid_idx] == to_find)
	{
		return mid_idx;
	}
	
			
	if (to_find < arr[mid_idx] )
	{
		right_idx = mid_idx -1;
	}
	else
	{
		left_idx = mid_idx + 1;
	}
		
	mid_idx = BinarySearchRecrr(arr, left_idx, right_idx, to_find);
	return mid_idx;
}

int BiarySearchFirstOccurOfANum (int arr[], int left_idx, int right_idx, int to_find )
{
	// Terminating condition.
	if ( left_idx > right_idx )
	{
		return -1;
	}
	
	int mid_idx = (left_idx + right_idx )/2;
	cout << " Left Idx, Right Idx =  " << left_idx << " , " << right_idx << ". Mid Idx = " << mid_idx << std::endl;


	if (arr[mid_idx] == to_find && arr[mid_idx-1] < to_find )
	{
		return mid_idx;
	}
	
	if ( to_find <= arr[mid_idx])
	{
		right_idx = mid_idx -1;
	}
	else
	{
		left_idx = mid_idx +1;
	}
	
	// Recursive call to binary search algo.
	mid_idx = BiarySearchFirstOccurOfANum (arr, left_idx, right_idx, to_find);
	return mid_idx;
}


int BiarySearchLastOccurOfANum (int arr[], int left_idx, int right_idx, int to_find )
{
	// Terminating condition.
	if ( left_idx > right_idx )
	{
		return -1;
	}
	
	int mid_idx = (left_idx + right_idx )/2;
	cout << " Left Idx, Right Idx =  " << left_idx << " , " << right_idx << ". Mid Idx = " << mid_idx << std::endl;


	if (arr[mid_idx] == to_find && arr[mid_idx+1] > to_find )
	{
		return mid_idx;
	}
	
	if ( to_find < arr[mid_idx])
	{
		right_idx = mid_idx -1;
	}
	else
	{
		left_idx = mid_idx +1;
	}
	
	// Recursive call to binary search algo.
	mid_idx = BiarySearchLastOccurOfANum (arr, left_idx, right_idx, to_find);
	return mid_idx;
}


int main ()
{
	
	size_t arr_size = 11;
	int arr[arr_size] = {1,2,2,2,3,4,5,6,7,8,9};
	//for (int i=0; i<arr_size; i++)
	//{
	//	arr[i] = i;
	 //} 
	 
	 int to_find;
	 cout << " Enter number to find ? " << std::endl;
	 cin >> to_find;
	 
	 cout << " Searching recursively -> " << endl;
	 int idx_found_recrr = BinarySearchRecrr(arr, 0, (arr_size-1), to_find);
	 	cout << "Result : Recurr Binary Search : " << idx_found_recrr << std::endl;

	 cout << " Searching Loopally -> " << endl;
	 int idx_found = BinarySearch(arr, 0, (arr_size-1), to_find);
	
	cout << "Result : Loop Binary  Search : " << idx_found << std::endl;
	
	cout << " Finding first occurence : " << endl;
	int idx_first_occr = BiarySearchFirstOccurOfANum (arr, 0, (arr_size-1), to_find);
	cout << " First occurence of : " << to_find << " is at idx : " << idx_first_occr << std::endl;
	
	cout << " Finding last  occurence : " << endl;
	int idx_last_occr = BiarySearchLastOccurOfANum (arr, 0, (arr_size-1), to_find);
	cout << " Last occurence of : " << to_find << " is at idx : " << idx_last_occr << std::endl;



	return 0;
}
