// singly linked list in c++

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
class singly_linked_list{
	struct node *head;
	public:
		singly_linked_list()
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
				while(current!= NULL)
				{
					cout<<current->data << " -> ";
					current = current->next;
				}
				cout<<endl;	
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
				head = newnode;
			}
		}
		
		// INSERT AT MIDDLE FUNCTION 
		void insert_at_middle(int t_data,int pos)
		{
			
			struct node *newnode = new node(t_data);
			
			if(head == NULL)
			{
				cout<<"\nlist is empty...\n";
			}
			else 
			{
				struct node *current = head;
				int count = 1;
				while(current->next != NULL && count < pos-1)
				{
					current = current->next;
					count++;
				}
				newnode->next = current->next;				
				current->next = newnode;
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
			}
		}
		// DELETE AT START FUNCTION
		void delete_at_start()
		{
		    if (head == NULL)
		    {
		        cout << "\nlist is empty...\n";
		    }
		    else
		    {
		        struct node *temp = head;
		        head = head->next;
		        delete temp;
		    }
		}
		
		// DELETE AT END FUNCTION
		void delete_at_end()
		{
		    if (head == NULL)
		    {
		        cout << "\nlist is empty...\n";
		    }
		    else if (head->next == NULL)
		    {
		        delete head;
		        head = NULL;
		    }
		    else
		    {
		        struct node *current = head;
		        while (current->next->next != NULL)
		        {
		            current = current->next;
		        }
		        delete current->next;
		        current->next = NULL;
		    }
		}
		
		// DELETE AT MIDDLE FUNCTION
		void delete_at_middle(int pos)
		{
		    if (head == NULL)
		    {
		        cout << "\nlist is empty...\n";
		    }
		    else
		    {
		        struct node *current = head;
		        struct node *prev = NULL;
		        int count = 1;
		        while (current != NULL && count < pos)
		        {
		            prev = current;
		            current = current->next;
		            count++;
		        }
		        if (current == NULL)
		        {
		            cout << "\nPosition out of range...\n";
		        }
		        else
		        {
		            prev->next = current->next;
		            delete current;
		        }
		    }
		}
		
		// UPDATE AT START FUNCTION
		
		// UPDATE AT END FUNCTION
		
		// UPDATE AT MIDDLE FUNCTION
		
		
};

int main()
{
	singly_linked_list ll;
	int op,pos,t_data;
	
	do{
		cout<<"______________________________\n";
		cout<<"0. display linked list\n";
		cout<<"1. insert at start\n";
		cout<<"2. insert at middle\n";
		cout<<"3. insert at end\n";
		cout<<"4. delete at start\n";
		cout<<"5. delete at middle\n";
		cout<<"6. delete at end\n";
		cout<<"7. update at start\n";
		cout<<"8. update at middle\n";
		cout<<"9. update at end\n";
		cout<<"10. sort list\n";
		cout<<"11. reverse list\n";
		cout<<"12. search an element\n";
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
				ll.delete_at_start();
				break;
			case 5:
				cout<<"Enter pos : ";
				cin >> pos;
				ll.delete_at_middle(pos);
				break;
			case 6:
				ll.delete_at_end();
				break;
//			case 7:
//				ll.update_at_start();
//				break;
//			case 8:
//				ll.update_at_middle();
//				break;
//			case 9:
//				ll.update_at_end();
//				break;
//			case 10:
//				ll.sort();
//				break;
//			case 11:
//				ll.reverse();
//				break;
//			case 12:
//				ll.search_an_element();
//				break;
			case 99:
				cout<<"\n....EXIT....\n";
				break;
		}
		
		cout<<"______________________________";
	}while(op != 99);
	
	return 0;
}

