#include<iostream>
#include<cmath>
#include<string>
using namespace std;

const int table_size = 10;
const float a = (sqrt(5) - 1) / 2;
struct node {
	int key;
	node *next;
	node(int k)
	{
		key = k;
		next = NULL;
	}
};
class hashtable{
	node *table[table_size];
	
	public:
		hashtable()
		{
			for(int i = 0; i<table_size ; i++)
			{
				table[i] = NULL;
			}
		}
		
		int hashfunction(int key)
		{
//			return k % 10;
//			return k % table_size;
//			return table_size * ((key * a) - int(key * a));
			
			
//			step 1: sq(key);
			int sq  = key * key;
			string strsq = to_string(sq);
			int mid =  strsq.length() / 2;
			string midval = strsq.substr(-3,2);
			return stoi(midval) % table_size;
		}
		
		void insert(int key)
		{
			int index = hashfunction(key);
			node* newnode = new node(key);
			
			newnode->next = table[index];
			table[index] = newnode;
		}
		
		void display()
		{
			for(int i = 0; i<table_size ; i++)
			{
				cout<< "\nbucket "<< i<<" : ";
				node *cur = table[i];
				while(cur != NULL)
				{
					cout<<cur->key <<" -> ";
					cur = cur->next;
				}
				cout<<" NULL ";
			}
		}
		
		bool search(int key)
		{
			int index = hashfunction(key);
			node * cur = table[index];
			
			while(cur != NULL)
			{
				if(cur->key == key)
				{
					return true;
					
				}
				cur = cur->next;
			}
			return false;
		}
		
//		void remove(int key)
//		{
//			int index = hashfunction(key);
//			node *cur = table[index],*prev;
//			
//			if(cur != NULL && cur->key == key)
//			{
//				cout<<"hello";
////				struct node *d = table[index];
//				table[index] = cur->next;
////				cur->next = cur->next->next;
//				delete cur;
//				return;
//			}
//			while(cur != NULL || cur->key != key)
//			{
//				prev = cur;
//				cur = cur->next;
//			}
//			if(cur == NULL)
//			{
//				return;
//			}
//			if(cur->next->key == key)
//			{
////				struct node *d = cur->next;
//				prev->next = cur->next;
//				delete cur;
//			}
//		}
		void remove(int key)
		{
			int index = hashfunction(key);
			struct node *curr=table[index];
			if(curr==NULL)
			{
				cout<<"element is not in hash";
				return;
			}
			if(curr->key == key)
			{
				table[index] = curr->next;
				delete curr;
				cout<<key <<" is deleteedd from hash";	
				return; 
			}
			while(curr->next!=NULL)
			{		
				if(curr->next->key == key)
				{
					struct node *temp =curr->next;
					curr->next =curr->next->next;
					delete temp;
						cout<<key <<" is deleteedd from hash";
						return;	
				}
				curr= curr->next;
			}	
					cout<<"element is not in hash";	
//					return;/
		}
		
		
};

int main()
{
	hashtable ll;
	int op,pos,t_data;
	
	do{
		cout<<"______________________________\n";
		cout<<"0. display hash table\n";
		cout<<"1. insert \n";
		cout<<"2. delete\n";
		cout<<"3. search\n";
		
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
				ll.insert(t_data);
				break;
			case 2:
				cout<<"Enter data : ";
				cin >> t_data;
//				int re = ;
				if(ll.search(t_data))
				{
					cout<<"found : ";
				
				}
				else
				{
					cout<<"not ";
				}
				break;
			case 3:
				cout<<"Enter data : ";
				cin >> t_data;
				ll.remove(t_data);
				break;
			case 4:
				cout<<"\nexit";
				break;
			
		}
		
		cout<<"______________________________";
	}while(op != 4);
	
	return 0;
}

