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
//	int peek()
//	{
//		if(empty())
//		{
////			cout<<"stack is full";
//			return -1;
//		}
//		else
//		{
//			int x = a[top];
////			top--;
//			return x;
//		}
//	}
};
//int isnum(char ch)
//{
//	return (ch >= '0' && ch <= '9');
//}
char isop(char ch)
{
	return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^');
}
char postfix_evaluation(char *postfix)
{
	int op1,op2,result,i=0,j=0;
	char ch;
	stack s(50);
	while(postfix[i] != '\0')
//for(i = 0;postfix[i] != '\0' ; i++)
	{
		if(postfix[i] >= '0' && postfix[i] <= '9')
		{
			int num = postfix[i] - '0';
			s.push(num);
		}
		else if(isop(postfix[i]))
		{
				op2 = s.pop();
				op1 = s.pop();
			switch(postfix[i])
			{
				case '+':
					result = op1 + op2;
					break;
				case '-':
					result = op1 - op2;
					break;
				case '/':
					result = op1 / op2;
					break;
				case '*':
					result = op1 * op2;
					break;
				case '^':
					result = op1 ^ op2;
					break;
					
			}
			s.push(result);
		}
		i++;
	}
	result = s.pop();
	return result;
}

int main()
{
	char postfix[] = "12*34*2/*6+7-";
	int r = postfix_evaluation(postfix);
	cout<<r;
	return 0;
}
