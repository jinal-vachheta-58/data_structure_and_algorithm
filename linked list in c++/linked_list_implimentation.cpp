#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
	node(int t_data)
	{
		data = t_data;
		next = NULL;
	}
};

class linked_list{
	struct node * head;
	
	public:
		linked_list()
		{
			head = NULL;
		}
	
	// display function 
	void display(void)
	{
		struct node *current = head;
		cout<<"_________________________________________________"<<endl;
		while(current != NULL)
		{
			cout<<"\n  "<<current->data;
			current = current->next;
		}
		cout<<"\n_________________________________________________"<<endl;
	}
	
	//
		
		//insert_at_start function 
	void insert_at_start(int t_data)
	{
		struct node *newnode = new node(t_data);
		if(head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}	
	//insert_at_middle function
	int insert_at_middle()
	{
		struct node *current = head;
			int total_count = 1;
			cout<<"\nyou can enter only following position.........\n";
			while(current != NULL)
			{
				cout<<total_count<<endl;
				current = current->next;
				total_count++;
			}
		int t_data,pos;
			cout<<"\nEnter data : ";
			cin>>t_data;
			cout<<"\nEnter position : ";
			cin>>pos;
		struct node *newnode = new node(t_data);
		if(head == NULL)
		{
			if(pos != 1)
			{
				cout<<"\nlist is empty................\nyou can enter only FIRST position.........\n";
			}
			else
			{
				head = newnode;
			}
		}
		else
		{
			
			
				if(pos-1 > total_count)
				{
				cout<<"\nYour position is invalid ................"<<endl;
				return 1;
				}
				else
				{
					int count = 1;
					
			current = head;
					while(current != NULL && count < pos-1)
					{
						current = current->next;
						count++;
						
					}
					newnode->next = current->next;
					current->next = newnode;
				}
//			struct node *current = head;
			
			
			
		}
	}
	
	//insert_at_end function
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
//			cout<<"_________________________________________________"<<endl;
			while(current->next != NULL)
			{
				current = current->next;
			}
			current->next = newnode;
		}
	}
};
int main()
{
	linked_list ll;
	int op,t_data,pos;

do{
	cout<<endl<<"=================================================================================";
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
	
	
	cout<<endl<<"Enter option : ";
	cin>>op;
	
	switch(op)
	{
		case 0:
			ll.display();
			break;
		case 1:
			cout<<"\nEnter data : ";
			cin>>t_data;
			ll.insert_at_start(t_data);
			break;
		case 2:
			
			ll.insert_at_middle();
			break;
		case 3:
			cout<<"\nEnter data : ";
			cin>>t_data;
			ll.insert_at_end(t_data);
			break;
		case 4:
			// ll.delete_at_start();
			break;
		case 5:
			
			break;
		case 6:
//			ll.delete_at_end();
			break;
		case 7:
		
			break;
		case 99:
			cout<<"\n exit..........."<<endl;
			break;
		default:
			cout<<"\n INVALID OPTION..........."<<endl;
			break;
	}
	cout<<endl<<"=================================================================================";
	}while(op != 99);

	return 0;
}



