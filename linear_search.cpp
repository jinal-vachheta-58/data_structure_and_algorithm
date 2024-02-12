
// linear search in c++
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
	linear_search()
	{
		int data;
		cout<<"Enter data to be searched : ";
		cin >> data;
		int index = -1;
		for (int i = 0; i < size; i++) 
		{
			if (a[i] == data) 
        	{
        		index = i;
			}
		}
		
        if(index == -1)
        {
        	cout<<endl<<"Element not found....";
		}
		else 
		{
			cout<<endl<<"Element found on index : "<<index; ;
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
	obj.linear_search();

//	obj.dis();
		
	return 0;
}
//output:
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
//Enter data to be searched : 23
//
//Element found on index : 1
//--------------------------------
//Process exited after 2.665 seconds with return value 0
//Press any key to continue . . .
