#include<iostream>
using namespace std;
struct node {
	int c;
	int p;
	struct node *next;
	node(int cc,int pp)
	{
		c = cc;
		p = pp;
		next = NULL;
	}
};
class polynomial{
	struct node *head;
	public:
		polynomial()
		{
			head = NULL;
		}
		void add_term(int cof ,int pow)
		{
			
			struct node *newnode = new node(cof,pow);
			if(head == NULL || head->p < pow)
			{
				newnode->next = head;
				head = newnode;
			}
			else
			{
				struct node *temp = head;
				node *prev = NULL;

            // Traverse the list to find the correct position for the new term
            while (temp != NULL && temp->p > pow) {
                prev = temp;
                temp = temp->next;
            }

            if (temp != NULL && temp->p == pow) { // If the power matches, update the coefficient
                temp->c += cof;
                delete newnode; // Avoid memory leak
            } else {
                // Insert the new term into the list
                if (prev == NULL) { // Shouldn't happen due to previous conditions
                    head = newnode;
                } else {
                    newnode->next = prev->next;
                    prev->next = newnode;
                }
            }
        }
    }

		void display_poly()
		{
			struct node *temp = head;
//			cout<<endl<<"___________________________________\n";
			while(temp!= NULL)
			{
				cout<< temp->c <<"x^"<<temp->p;
				temp =temp->next;
				
				if(temp != NULL)
				{
					cout<<" + ";
				}
				else
				{
					cout<<endl;
				}
			}
			
			cout<<endl<<"___________________________________\n";
		}
	
	
 polynomial add_poly(polynomial poly2)
{
	struct node *p1 = head;
	struct node *p2 = poly2.head;
	struct polynomial result;
	while(p1 != NULL || p2 != NULL)
	{
		if(p1->p == p2->p)
		{
		result.add_term(p1->c + p2->c,p1->p);
		p1 = p1->next;
		p2 = p2->next;
			
		}
		else if(p1->p > p2->p)
		{
			result.add_term(p1->c,p1->p);
			p1 = p1->next;
		}
		else if(p1->p < p2->p)
		{
			result.add_term(p2->c,p2->p);
			p2 = p2->next;
		}
	}
	while(p1 != NULL)
	{
		result.add_term(p1->c , p1->p);
		p1 = p1->next;
	}
	while(p2 != NULL)
	{
		result.add_term(p2->c , p2->p);
		p2 = p2->next;
	}
	
	return result;
}
};



int main()
{
	int op;
	int cof,pow;
	polynomial p1,p2;
	do{
		cout<<"Enter the choice  : ";
			cin>> op;
	switch(op)
	{
		case 1:
			
			cout<<"add term in 1 poly : ";
			cout<<"Enter the cof : ";
			cin>> cof;
			cout<<"Enter the pow : ";
			cin>> pow;
			p1.add_term(cof,pow);
			p1.display_poly();
			break;
		case 2:
			
			cout<<"add term in 2 poly : ";
			cout<<"Enter the cof : ";
			cin>> cof;
			cout<<"Enter the pow : ";
			cin>> pow;
			p2.add_term(cof,pow);
//			char x="p2"; 
			p2.display_poly();
			break;
		case 3:
			cout<< "first poly : \n";
			p1.display_poly();
			break;
		case 4:
			cout<< "second poly : \n";
			p2.display_poly();
			break;
		case 5:
			cout<< "add poly : \n";
			struct polynomial result = p1.add_poly(p2);
			cout<<"hii";
			result.display_poly();
			break;
		
	}	
		
		
	}while(op != 99);
	
	return 0;
}
