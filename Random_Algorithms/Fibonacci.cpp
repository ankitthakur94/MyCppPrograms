#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
static int count =0;
std::vector <int> fib_nums;


int FibSubOptimal (int i)
{
	count ++;
	cout << count << " :   Called for i = " << i << std::endl;
	if (i < 1)
	{
		return -1;
	}
	
	
	if (i==1 || i==2)
	{
		return i-1;
	}

	return ( FibSubOptimal(i-1) + FibSubOptimal(i-2) );
}
	
int FibOptimal (int i)
{
	
	count ++;	
	if (i < 0)
	{
		return -1;
	}
	
	fib_nums.push_back(0);
	fib_nums.push_back(1);
	
 	cout << fib_nums[0] << " , "  << fib_nums[1] << " , " ;
	for (int j=2; j<=i ; j++)
	{
		int result = fib_nums[j-1] + fib_nums[j-2];
		fib_nums.push_back(result);
		cout << result << " , " ;
	}
	cout << endl;

	return fib_nums[i];
	
}

int first_num, second_num;

int FibOptimal2 (int i)
{
	
	count ++;	
	if (i < 0)
	{
		return -1;
	}
	
	first_num =0;
	second_num  =1;
	//fib_nums.push_back(0);
	//fib_nums.push_back(1);
	
 	cout << first_num << " , "  << second_num << " , " ;
	for (int j=2; j<=i ; j++)
	{
		int result = (first_num + second_num);
		first_num = second_num;
		second_num = result;
		//int result = fib_nums[j-1] + fib_nums[j-2];
		//fib_nums.push_back(result);
		cout << result << " , " ;
	}
	cout << endl;

	return second_num;
	
}

int main ()
{
	cout << " Enter a number ?" << endl;
	int i;
	cin >> i;
	
	cout << endl;
	
	std::clock_t start;
	std::clock_t end_1;
	std::clock_t end_2;
	
	
	//start = std::clock();
	//cout << " Fib number is : " << FibSubOptimal(i) << endl;
	//end_1 =  (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
	
	
	start = std::clock();
	cout << " Fib number is : " << FibOptimal2(i) << endl;
	end_2 = (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
	
	cout << " Runtime : (Suboptimal , Optimal) "  << end_1 << " , " << end_2 << endl;  
	

	return 0;
}


