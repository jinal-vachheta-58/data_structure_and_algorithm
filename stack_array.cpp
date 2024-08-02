//stack using array
#include<iostream>
using namespace std;
class stack{
	int *a;
	int top;
	int size;
	public:
		stack(int s)
		{
			size = s;
			top = -1;
			a = new int[size];
		}
		bool isfull()
		{
			return top == size-1;
		}
		bool isempty()
		{
			return top == -1;
		}
		int peek()
		{
			if(isempty())
			{
				cout<<"stack is empty";
				return -1;
			}
			else
			{
				return a[top];
			}
		}
		void push(int t_data)
		{
			if(isfull())
			{
				cout<<"stack is full";
			}
			else
			{
				top++;
				a[top] = t_data;
			}
		}
		int pop()
		{
			if(isempty())
			{
				cout<<"stack is empty";
				return -1;
			}
			else
			{
				return a[top--];
			}
		}
};
int main()
{
	stack st(10);
	int ch,t_data;
	do{
		cout<<"\n1.push\n2.pop\n3.peek\n4.isfull\n5.isempty\n";
		cout<<"Enter your choice : ";
		cin >>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter data : ";
				cin >>t_data;
				st.push(t_data);
				break;
			case 2:
				t_data = st.pop();
				cout<<t_data<<" is deleted from stack";
				break;
			case 3:
				t_data = st.peek();
				cout<<" top most element : "<<t_data;
				break;
			case 4:
				if(st.isfull())
				{
					cout<<"stack is full";
				}
				break;
			case 5:
				if(st.isempty())
				{
					cout<<"stack is empty";
				}
				break;
		}		
	}while(ch != 9);	
	return 0;
}
