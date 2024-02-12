
// selection sorting in c++
#include<iostream>
using namespace std;
class array{
	int a[10];
	int size;
	public:
		array()
		{
			size = 5;
			a[0] = 10;
			a[1] = 23;
			a[2] = 2;
			a[3] = 1;
			a[4] = 9;
		}
		dis()
		{
			for(int i =0; i< size ;i++)
			{
				cout<<endl<<a[i];
			}
		}
	selection_sort()
	{
		for(int i =0; i<size-1 ;i++)
		{
			for(int j = i +1 ;j < size ;j++)
			{
				if(a[i] < a[j])
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				 } 
			}
		}
	}
};

int main()
{
	array obj;
	cout<<endl<<"unsorted array"<<endl ;
	obj.dis();
		cout<<endl<<"_______________________________";
	cout<<endl<<"sorted array"<<endl ;
	obj.selection_sort();

	obj.dis();
		
	return 0;
}
//output:
//	
//
//unsorted array
//
//10
//23
//2
//1
//9
//_______________________________
//sorted array
//
//23
//10
//9
//2
//1
//--------------------------------
//Process exited after 0.2681 seconds with return value 0
//Press any key to continue . . .

