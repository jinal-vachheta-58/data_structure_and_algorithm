//priority queue using array
#include<iostream>
using namespace std;
class p_q{
	int size;
	int front;
	int rear;
	int *data , *priority;
	public:
		p_q(int s)
		{
			size = s;
			front = rear = -1;
			data = new int[size];
			priority = new int[size];
		}
		enqueue(int t_data,int p)
		{
			if(rear == size - 1)
			{
				cout<<"\nfull\n";
			}
			else if(front == -1 && rear == -1)
			{
				front = rear = 0;
				data[rear] = t_data;
				priority[rear] = p;
			}
			else
			{
				int i;
				for(i = rear ; i>=front ; i--)
				{
					if(p > priority[i])
					{
						data[i+1] = data[i];
						priority[i+1] = priority[i];
					}
					else
					{
						break;
					}
					
				}
				data[i+1] = t_data;
				priority[i+1] = p;
				rear++;
			}
		}
		void dequeue()
		{
			if(front == -1 && rear == -1)
			{
				cout<<"\nempty\n";
			}
			else if(front == rear )
			{
				cout << "Dequeued element: " << data[front] << "\n";
				front = rear = -1;
			}
			else
			{
				cout << "Dequeued element: " << data[front] << "\n";
				front++;
			}
		}
		void display()
		{
			cout<< "\n";
			for(int i = front ; i<= rear ; i++)
			{
				cout << data[i] <<" : "<<priority[i] << "\n";
			}
		}
};

int main()
{
	p_q q(10);
	int ch,x,pr;
			do{
				cout<<"\n\n\n1. enqueue\n2.dequeue.\n3.display.";
				
		cout<<"\n\nenter the choise";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"enter the element";
				cin>>x;
					cout<<"enter the element priority";
				cin>>pr;
				q.enqueue(x,pr);
				break;

			case 2:
				q.dequeue();
			break;
			case 3:
				q.display();
				break;
			default :
				cout<<"wrong choise :";
				break;
		}
			
	}
	while(ch != 99);
	return 0;
}
		

