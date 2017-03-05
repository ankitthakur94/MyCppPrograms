#include <iostream>

using namespace std;

int BinarySearchRecrr (int arr[], int left_idx, int right_idx, int num_to_find)
{
	// Important (why not left_idx >= right_idx)
	if (left_idx > right_idx)
		return -1;

	int mid_idx = (left_idx + right_idx)/2;
	int mid_elem = arr[mid_idx];

	cout << " Left Idx, Right Idx =  " << left_idx << " , " << right_idx << ". Mid Idx = " << mid_idx << std::endl;
	if (num_to_find == mid_elem)
		return mid_idx;


	// Why right = mid-1, why not right = mid.  Similarly for left_idx
	if (num_to_find < mid_elem)
	{
		right_idx = mid_idx -1;
	}
	else
	{
		left_idx = mid_idx +1;
	}

	return (BinarySearchRecrr (arr, left_idx, right_idx, num_to_find) );

}

int FirstOccuranceOfANumberUsingBinarySearch (int arr[], int left_idx, int right_idx, int num_to_find)
{
	if (left_idx > right_idx)
		return -1;

	int mid_idx = (left_idx + right_idx)/2;
	int mid_elem = arr[mid_idx];

	cout << " Left Idx, Right Idx =  " << left_idx << " , " << right_idx << ". Mid Idx = " << mid_idx << std::endl;

	if (num_to_find == mid_elem  && arr[mid_idx-1] < num_to_find)
	{
		return mid_idx;
	}

	
	// Why right = mid-1, why not right = mid.  Similarly for left_idx
	if (num_to_find <= mid_elem)
	{
		// Go Left.
		right_idx = mid_idx -1;
	}
	else
	{
		// Go Right.
		left_idx = mid_idx +1;
	}

	return (FirstOccuranceOfANumberUsingBinarySearch(arr, left_idx, right_idx, num_to_find) );


}
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// 7, 8, 9, 0, 1, 2, 3, 4, 5, 6 
int FindNumberOfRotationsOfSortedArray (int arr[], int left_idx, int right_idx)
{
	// Terminating condition
	if (left_idx > right_idx)
		return -1;

	
	int mid_idx = (left_idx + right_idx)/2;
	int mid_elem = arr[mid_idx];
	cout << " Left Idx, Right Idx =  " << left_idx << " , " << right_idx << ". Mid Idx = " << mid_idx << std::endl;

	// Terminating condition
	if (arr[mid_idx-1] > arr[mid_idx] && arr[mid_idx+1] > arr[mid_idx] )
	{
		return mid_idx;
	}

	if (arr[mid_idx] < arr[left_idx])
	{
		// Go Left 
		cout << " Left part is unsorted " << endl;
		right_idx = mid_idx -1;
	}
	else if (arr[mid_idx] > arr[right_idx] ) 
	{
		// Go Right
		cout << " Right part is unsorted " << endl;
		left_idx = mid_idx +1;
	}
	else
	{
		// The array is sorted. Go Left.
		cout << " Arr is sorted " << endl;
		right_idx = mid_idx -1;
	}


	return (FindNumberOfRotationsOfSortedArray (arr, left_idx, right_idx) );
}

int main ()
{

	size_t arr_size = 11;
	int arr[arr_size] = {1,2,2,2,3,4,5,6,7,8,9};
	for (int i=0; i<arr_size; i++)
	{
		cout <<  i << " : " << arr[i] << "  ,  " ;
	} 
	cout << endl;

	int to_find;
	cout << " Enter number to find ? " << std::endl;
	cin >> to_find;

	cout << " Searching recursively -> " << endl;
	int idx_found_recrr = BinarySearchRecrr(arr, 0, (arr_size-1), to_find);
	cout << "Result : Recurr Binary Search : " << idx_found_recrr << std::endl;
	
	
	cout << " Finding first occurence : " << endl;
	int idx_first_occr = FirstOccuranceOfANumberUsingBinarySearch(arr, 0, (arr_size-1), to_find);
	cout << " First occurence of : " << to_find << " is at idx : " << idx_first_occr << std::endl;

	int arr2[arr_size]  = {7, 8, 9, 10, 0, 1, 2, 3, 4, 5, 6};
	cout << " Finding Number of rotations : " << endl;
	int num_rot = FindNumberOfRotationsOfSortedArray(arr2, 0, (arr_size-1));
	cout << " Number of Rot. : " << num_rot << std::endl;
	return 0;
}
