//stack using ll
#include<iostream>
using namespace std;
struct node{
	int data;
	node * next;
	node(int t_data)
	{
		data = t_data;
		next = NULL;
	}
};
class stack{
	struct node *top;
	public:
		stack()
		{
			top = NULL;
		}
		int peek()
		{
			if(top == NULL)
			{
				cout<<"stack is empty";
				return -1;
			}
			else
			{
				return top->data;
			}
		}
		void push(int t_data)
		{
			node * newnode = new node(t_data);
			if(top == NULL)
			{
				top = newnode;
			}
			else
			{
				newnode->next = top;
				top = newnode;
			}
		}
		int pop()
		{
			if(top == NULL)
			{
				cout<<"stack is empty";
				return -1;
			}
			else
			{
				node * temp = top;
				top = top->next;
				int t_data = temp->data;
				delete temp;
				return t_data;
			}
		}
		void display()
		{
			node * temp = top;
			while(temp != NULL)
			{
				cout<<temp->data<<"  ->  ";
				temp = temp->next;
			}
		}
};
int main()
{
	stack st;
	int ch,t_data;
	do{
		cout<<"\n1.push\n2.pop\n3.peek\n";
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
					st.display();
					break;
		}		
	}while(ch != 9);	
	return 0;
}
