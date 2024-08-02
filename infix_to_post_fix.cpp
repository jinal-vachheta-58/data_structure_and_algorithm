#include<iostream>
using namespace std;
class stack
{
	int *a,top,size;
	public:
	stack(int s)
	{
		size = s;
		top = -1;
		a = new int[size];
	}
	bool full()
	{
		return top == size -1;
	}
	bool empty()
	{
		return top == -1;
		}	
	void push(int t_data)
	{
		if(full())
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
		if(empty())
		{
//			cout<<"stack is empty";
			return -1;
		}
		else
		{
			int x = a[top];
			top--;
			return x;
		}
	}
	int peek()
	{
		if(empty())
		{
//			cout<<"stack is full";
			return -1;
		}
		else
		{
			int x = a[top];
//			top--;
			return x;
		}
	}
};
	int isoperand( char ch)
	{
		return ((ch >= 'a' && ch <= 'z' ) || (ch >= 'A' && ch <= 'z'));
	}
	int precedence(char ch)
	{
		if(ch == '+' || ch == '-')
		{
			return 1;mm
		}
		else if(ch == '/' || ch == '*')
		{
			return 2;
		}
		else if(ch == '^')
		{
			return 3;
		}
		else
		{
			return -1;
		}
	}
	void infix_to_postfix(char *infix)
	{
		char postfix[50];
		int i=0,j=0;
		stack st(50);
		while(infix[i] != '\0')
		{
			if(isoperand(infix[i]))
			{
				postfix[j] = infix[i];
				j++;
			}
			else if(infix[i] == '(')
			{
				st.push(infix[i]);
			}
			else if(infix[i] == ')')
			{
				// while 
				while(!st.empty() && st.peek() != '(')
				{
					postfix[j] = st.pop();
					j++;
				}
				if(!st.empty() && st.peek() != '(')
				{
					cout<<"mismatch : ";
					return;
				}
				else
				{
					st.pop(); // discard the bracket
				}
			}
			else 
			{
				while(!st.empty() && precedence(infix[i]) <= precedence(st.peek()))
				{
					postfix[j] = st.pop();
					j++;
				}
				st.push(infix[i]);
			}
			i++;
		}
		
		while(!st.empty())
		{
			postfix[j] = st.pop();
			j++;
		}
		postfix[j] = '\0';
		cout<<postfix;
	}


int main()
{
	
	char infix[] = "((x+(y*z))-w)";
	infix_to_postfix(infix);
	
	return 0;
}
