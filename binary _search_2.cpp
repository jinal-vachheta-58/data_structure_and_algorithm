#include<iostream>
using namespace std;
class array{
	int a[5],size;
	public:
		array()
		{
			size = sizeof(array)/sizeof(a[0]);
			for(int i=0; i<size; i++)
			{
				a[i] = i;
			}
		}
	dis()
	{
//		cout<<size<<endl;
		for(int i=0; i<size; i++)
			{
				cout<<a[i]<<endl;
			}
	}
	int binary_search()
	{
		int start = 0,end = size-1,mid;
		int target;
		cout<<endl<<"Enter data to be searched : ";
		cin>>target;
		while(start <= end)
		{
			mid = (start + end)/2;
			if(a[mid] == target)
			{
				return mid;
			}
			
			if( target > a[mid])
			{
				start = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
		return 10;
	}
};
int main()
{
	array obj1;
	obj1.dis();
	int result = obj1.binary_search();
	if(result == 10)
	{
		cout<<"target does not found";
	}
	else
	{
		cout<<endl<<"target found" <<result;
	}	
	return 0;
}
