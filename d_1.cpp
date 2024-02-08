// array implimentation

#include<iostream>
using namespace std;
class array{
	int a[100];
	int size;
	public:
		display()
		{
//			cout<<size;
			for(int i=0; i< size ;i++)
			{
				cout<< "\ndata : "<<a[i];
			}
		}
		
		int ias()
		{
			int data;
			cout<<"Enter data :";
			cin>> data;
			if(size == 0)
			{
				a[size] = data;
				size++;
				return 0;
			}
			else
			{
				for(int i= size;i>=0 ;i--)
				{
					if(i==0)
					{
						a[i] = data;
					}
					else
					{
						a[i] = a[i-1];
					}
				}
				size++;
			}
			return 0;
		}
	
};

int main()
{
	array o;
	int op;
	
	do{
		cout<<"\n___________________________\nEnter option : ";
		cin>> op;
		
		switch(op)
		{
			case 1:
				o.display();
				break;
			case 2:
				o.ias();
				break;
				
			case 3:
				
				break;
				
			case 4:
				
				break;
				
			case 5:
				
				break;
			default:
				cout<<"invalid option"<<endl;
				
		}
		
	}while(op != 99);
	return 0;
}
