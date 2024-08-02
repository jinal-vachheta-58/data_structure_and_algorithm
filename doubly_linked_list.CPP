// doubly linked list

#include<iostream>
using namespace std;

struct node{
	struct node *prev;
	int data;
	struct node *next;
	
	node(int t_data)
	{
		prev = NULL;
		data = t_data;
		next = NULL;
	}
};
class lili{
	struct node *head;
	public:
		lili()
		{
			head = NULL;
		}
		//DISPLAY FUNCTION 
		void display(void)
		{
			if(head == NULL)
			{
				cout<<"\nlist is empty...\n";
			}
			else
			{
				struct node *current = head;
				while(current != NULL)
				{
					cout<<current->data << " -> ";
					current = current->next;
				}
				cout<<endl;	
			}
		}
		
		// COUNT LENGTH OF LINKED LIST
		int length(node *current)
		{
			int len = 0;
			 if(head == NULL)
			{
				cout<<"\nlist is empty...\n";
				return len;
			}
			else
			{
				struct node *current = head;
				while(current != NULL)
				{
					len++;
					current = current->next;
				}
				cout<<endl;	
				return len;
			}
		}
		
		//INSERT AT START FUNCTION 
		void insert_at_start(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				head = newnode;
			}
			else 
			{
				newnode->next = head ;
				head->prev = newnode;
				head = newnode;
			}
		}
		
		//insert_at_middle
		void insert_at_middle(int t_data,int pos)
		{
			
			struct node *newnode = new node(t_data);
			
			if(head == NULL )
			{
				cout<<"\nlist is empty...\n";
			}
			else 
			{
				struct node *current = head;
				int count = 1;
				while(current->next != NULL && count < pos-1)
				{
					count++;
					current = current->next;
				}
				
//				if(current->next != NULL && count < pos-1)
//				{
					newnode->next = current->next;
					newnode->prev = current;			
					current->next->prev = newnode;
					current->next = newnode;
//				}
//				else
//				{
//					cout<<"\nout of range...\n";
//				}
			}
		}
		
		//INSERT AT END FUNCTION
		void insert_at_end(int t_data)
		{
			struct node *newnode = new node(t_data);
			if(head == NULL)
			{
				head = newnode;
			}
			else 
			{
				struct node *current = head;
				while(current->next != NULL)
				{
					current = current->next;
				}
				current->next = newnode;
				newnode->prev = current;
			}
		}
		
		void sort(void)
		{
			if (head == NULL) {
        cout << "\nList is empty\n";
        return;
	}
			struct node *ptr1= head,*ptr2 = head;
			while(ptr1->next != NULL)
			{
				ptr2 = ptr1->next;
				while(ptr2 != NULL)
				{
					if(ptr1->data > ptr2->data)
					{
						int temp = ptr1->data;
						ptr1->data= ptr2->data;
						ptr2->data = temp;
					}
					ptr2 = ptr2->next;
				}
				ptr1 = ptr1->next;
			}
		}
		
		// DELETE AT START 
		void d_s(void)
		{
			if(head == NULL)
			{
				cout<<"\nlist is empty...\n";
			}
			else
			{
				struct node *temp = head;
				head = head->next;
				delete temp;
			}
		}
		
		void d_m(int pos)
		{
			
//			struct node *newnode = new node(t_data);
			
			if(head == NULL )
			{
				cout<<"\nlist is empty...\n";
			}
			else 
			{
				struct node *current = head;
				int count = 1;
				while(current->next != NULL && count < pos-1)
				{
//					cout<<current->data<<"    ->    "<<count;
					count++;
					current = current->next;
					
				}
//				cout<<"\n"<<current->data<<"    ->    "<<count;

				struct node *d_n;
//				current = current->prev;	
//				d_n = current->next;			
//				current->next = current->next->next;
//				current = current->next->next->prev;
//				d_n->next = NULL;
//				d_n->prev = NULL;
//				delete d_n;


				d_n = current->next;
				current->next = current->next->next;
				current->next->prev = current;
				delete d_n;
			}
		}
		
		// DELETE LAST ELEMENT
		void d_e(void)
		{
			if(head == NULL)
			{
				cout<<"\nlist is empty...\n";
			}
			else
			{
				struct node *temp = head;
				struct node *d_n;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
//				head = head->next;
				d_n = temp;
				temp = temp->prev;
				temp->next = NULL;
				
				delete d_n;
			}
		}
};


int main()
{
	lili ll;
	int op,pos,t_data;
	
	do{
		cout<<"______________________________";
		cout<<"\nEnter option : ";
		cin>> op;
		switch(op)
		{
			case 0:
				ll.display();
				break;
			case 1:
				cout<<"Enter data : ";
				cin >> t_data;
				ll.insert_at_start(t_data);
				break;
			case 2:
				cout<<"Enter data : ";
				cin >> t_data;
				cout<<"Enter pos : ";
				cin >> pos;
				ll.insert_at_middle(t_data,pos);
				break;
			case 3:
				cout<<"Enter data : ";
				cin >> t_data;
				ll.insert_at_end(t_data);
				break;
			case 4:
				ll.sort();
				break;
			case 5:
				ll.d_s();
				break;	
			case 6:
				cout<<"Enter pos : ";
				cin >> pos;
				ll.d_m(pos);
				break;
			case 7:
				ll.d_e();
				break;
			case 99:
				cout<<"\n....EXIT....\n";
				break;
		}
		
		cout<<"______________________________";
	}while(op != 99);
	
	return 0;
}

