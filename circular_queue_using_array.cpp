//circular queue using array
#include<iostream>
using namespace std;
class circular_queue{
	int *a;
	int front,rear,size;
	public:
		circular_queue(int s)
		{
			size = s;
			front = rear = -1;
			a = new int[size];
		}
		bool isfull()
		{ 
//		(front 0 and rear -1 hoy) or ( rear is at just before front )
			return (front == 0 && rear == size-1) || (((rear +1)%size) == front);
		}
		bool isempty()
		{ 
//		(front 0 and rear -1 hoy) or ( rear is at just before front )
			return (front == -1 && rear == -1);
		}
		
		void enqueue(int t_data)
		{
			if(isfull())
			{
				cout<<"overflow";
			}
			else if(front == -1)
			{
				front = rear = 0;
				a[rear] = t_data; 
			}
			else if(rear == size-1 && front != 0)
			{
				rear = (rear +1)% size;
				a[rear] = t_data;
			}
			else 
			{
				rear = (rear+1)%size;
				a[rear] = t_data;
			}
		}
		
		int dequeue()
		{
			if(isempty())
			{
				cout<<"underflow";	
				return -10;
			}
			else if(front == rear)
			{
				int x = a[front]; 
				front = rear = -1;
				return x;
			}
			else
			{
				return a[front++];
			}
		}
//		void display()
//		{
//			int i = a[front];
//			cout<< a[front]<<" -> ";
//			while(true)
//			{
//				
//				cout<< a[i]<<" -> ";
//				i = (i+1)% size;
//				if(i-1 == rear )
//				{
//					break;
//				}
//			}
//		}
};
int main()
{
	circular_queue st(10);
	int ch,t_data;
	do{
		cout<<"\n1.enqueue\n2.dequeue\n3.display\n";
		cout<<"Enter your choice : ";
		cin >>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter data : ";
				cin >>t_data;
				st.enqueue(t_data);
				break;
			case 2:
				t_data = st.dequeue();
				cout<<t_data<<" is deleted from queue";
				break;
			case 3:
//				st.display();
				break;
		}		
	}while(ch != 9);	
	return 0;
}
