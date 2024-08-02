#include<iostream>
using namespace std;

class queue{
	int *a;
	int n;
	int front,rare;
	public:	
	queue()
	{
		cout<<"entr thw size of the queue";
		cin>>n;
		a = new int[n];
		front =-1;
		rare=-1;
	}
	void push(int x)
	{
		if(rare >= n-1)
		{
			cout<<"queue is full";
		}
		else
		{
		if(front == -1)
		{
			front = 0;
		}
			
			rare++;
			a[rare]=x;
//			cout<<"element id pushed : \n"<<x;
		}
	}
	
	int pop()
	{
		if(front ==-1 || front > rare)
		{
			cout<<"\nqueue is underflow or empty.\n";
			return -1;
		}
		else
		{
			
//			cout<<a[front]<<" elemrnt is poped out: ";
			front++;
			return a[front-1];
		}
	}
	
bool isEmpty() {
        return (front > rare || front == -1);
    }
};
int main()
{
	queue q;
	 int i =0;
	int visited[5]= {0,0,0,0,0};
	 int  arr[5][5]={
	 {1,0,0,0,1},
	 {1,0,0,1,0},
	 {1,0,0,1,0},
	 {0,1,1,0,1},
	 {1,0,0,1,0}
	 };
	 cout<<i<<" ";
	 visited[i] = 1;
	 q.push(i);
	while(!q.isEmpty())
	{
	 	int u = q.pop();
	 	for(int j=0;j<5 ;j++)
	 	{
	 		if (arr[u][j] ==1 && visited[j]==0){
	 			cout<<j<<" ";
	 	         visited[j] = 1;
	 			q.push(j);
			}

		}
	
	}
	return 0;
}
