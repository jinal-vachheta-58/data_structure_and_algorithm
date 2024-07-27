// array implimentation in c++

#include<iostream>
using namespace std;
class array{
	int a[100];
	int size;
	public:
		array()
		{
			size = 3;
			a[0] = 1;
			a[1] = 2;
			a[2] = 3;
		}
		
	// display function
	void display(void)
	{
			cout<<"\n___________________________\n";
		for(int i = 0;i < size ;i++)
		{
			cout<<endl<<"a["<<i<<"] : "<<a[i];
		}
			cout<<"\n___________________________\n";
	}
	
	//insert_at_start function
	void insert_at_start(void)
	{
		int data;
		cout<<"Enter data : ";
		cin>>data;
		
		for(int i= size; i >= 0; i-- )
		{
			if(i==0)
			{
				a[i] = data;
				size++;
			}
			else
			{
				a[i] = a[i-1];
			}
		}
	}
	
	//insert_at_middle function
	void insert_at_middle(void)
	{
		int data,pos;
		cout<<"\nEnter data : ";
		cin>>data;
		cout<<"\nEnter pos : ";
		cin>>pos;
		
		for(int i= size; i >= pos; i-- )
		{
			if(i==pos)
			{
				a[i] = data;
				size++;
			}
			else
			{
				a[i] = a[i-1];
			}
		}
	}
	
	// insert_at_end function
	void insert_at_end(void)
	{
		int data;
		cout<<"Enter data : ";
		cin>>data;
		
		a[size] = data;
		size++;
	}
	
	//delete_at_start function
	void delete_at_start(void)
	{
		if(size == 0)
		{
			cout<<"\narray is empty.....\n";
		}
		else
		{
			for(int i= 0; i <= size; i++)
			{
				if(i == size)
				{
					size--;
				}
				else
				{
					a[i] = a[i+1];
				}
			}	
		}
		
	}
	
	// delete_at_middle function
	void delete_at_middle(void)
	{
		if(size == 0)
		{
			cout<<"\narray is empty.....\n";
		}
		else
		{
			int pos;
			cout<<"\nEnter pos : ";
			cin>>pos;
			for(int i= pos; i <= size; i++ )
		{
			if(i == size)
			{
				a[i] = 0;
				size--;
			}
			else
			{
				a[i] = a[i+1];
			}
		}
		}
		
	}
	
	// delete_at_end function
	void delete_at_end(void)
	{
		
		if(size == 0)
		{
			cout<<"\narray is empty.....\n";
		}
		
		else
		{
			a[size-1] = 0;
			size--;
		}
		
	}
	
	// update_at_start function
	void update_at_start(void)
	{
		if(size == 0)
		{
			cout<<"\narray is empty.....\n";
		}
		
		else
		{
		int data;
		cout<<"Enter data to update : ";
		cin>>data;
		
		a[0] = data;
		}
	}
	
	// update_at_middle function
	void update_at_middle(void)
	{
		if(size == 0)
		{
			cout<<"\narray is empty.....\n";
		}
		
		else
		{
		int data;
		cout<<"Enter data to update : ";
		cin>>data;
		int pos;
		cout<<"\nEnter pos : ";
		cin>>pos;
		
		a[pos] = data;
		}
	}
	
	// update_at_end function
	void update_at_end(void)
	{
		if(size == 0)
		{
			cout<<"\narray is empty.....\n";
		}
		
		else
		{
		int data;
		cout<<"Enter data to update : ";
		cin>>data;
		
		a[size-1] = data;
		}
	}
	

};

int main()
{
	
	array obj;
	int op;
	
	
	do{
		cout<"\n===========================+++++++++++++++===============================\n";
		cout<<endl<<"0. display....";
		cout<<endl<<"1. insert at start....";
		cout<<endl<<"2. insert at middle....";
		cout<<endl<<"3. insert at end....";
		cout<<endl<<"4. delete at start....";
		cout<<endl<<"5. delete at middle....";
		cout<<endl<<"6. delete at end....";
		cout<<endl<<"7. update at start....";
		cout<<endl<<"8. update at middle....";
		cout<<endl<<"9. update at end....";
		
		cout<<"\nEnter your option : ";
		cin>>op;
		
		switch(op)
		{
		case 0:
			obj.display();
			break;
		case 1:
			obj.insert_at_start();
			break;		
		case 2:
			obj.insert_at_middle();
			break;
		case 3:
			obj.insert_at_end();
			break;
		case 4:
			obj.delete_at_start();
			break;
		case 5:
			obj.delete_at_middle();
			break;
		case 6:
			obj.delete_at_end();
			break;
		case 7:
			obj.update_at_start();
			break;
		case 8:
			obj.update_at_middle();
			break;	
		case 9:
			obj.update_at_end();
			break;
			//
		case 9:
			obj.update_at_end();
			break;
cout<"\n===========================+++++++++++++++===============================\n";		
		}
		
		
	}while(op != 99);
	return 0;
}
