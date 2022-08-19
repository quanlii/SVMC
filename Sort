#include <iostream>

using namespace std;

bool increase(int l, int r)		//tang
{
	return l < r;
}
bool decrease(int l, int r)		//giam
{
	return l > r;
}
bool doNothing(int l, int r)	//nothing
{
	return 0;
}


void selectionSort(int *arr, int len, bool(*compare)(int, int))
{
	for(int i = 0; i < len; i++)
	{
		int maxIndex = i;
		for(int j = i; j < len; j++)
		{
			if(compare(arr[j],arr[maxIndex]))
			{
				maxIndex = j;
			}
			swap(arr[j], arr[maxIndex]);
		}
	}
}


 int main()
 {
	 int arr[10] = {1,4,2,5,3,6,8,7,9,0};
	 selectionSort(arr, 10, doNothing);
	 return 0;
 }
