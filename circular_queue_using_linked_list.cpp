//circular queue using linked list in c++
#include<iostream>
using namespace std;
struct node{
	int data;
	node * next;
//	node * prev;
	node(int t_data)
	{
		data = t_data;
		next = NULL;
	}
};
class circular_queue_using_linked_list{
	struct node *front , * rear;
	public:
		circular_queue_using_linked_list()
		{
			front = NULL;
			rear = NULL;
		}
		int peek()
		{
			if(front == NULL)
			{
				cout<<"stack is empty";
				return -1;
			}
			else
			{
				return front->data;
			}
		}
		void push(int t_data)
		{
			node * newnode = new node(t_data);
			if(front == NULL)
			{
				front = rear = newnode;
				rear->next = front;
			}
			else
			{
				rear->next = newnode;
				rear = newnode;
				rear->next = front;
			}
		}
		int pop()
		{
			if(front == NULL)
			{
				cout<<"stack is empty";
				return -1;
			}
			else
			{
				node * temp = front;
				front = front->next;
				int t_data = temp->data;
				delete temp;
				return t_data;
			}
		}
		void display()
		{
			node * temp = front;
			cout<<temp->data<<"  ->  ";
				temp = temp->next;
			while(temp != front)
			{
				cout<<temp->data<<"  ->  ";
				temp = temp->next;
			}
		}
};
int main()
{
	circular_queue_using_linked_list st;
	int ch,t_data;
	do{
		cout<<"\n1.push\n2.pop\n3.peek\n4.display\n";
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
