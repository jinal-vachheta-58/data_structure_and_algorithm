#include<iostream>
using namespace std;

int pivot(int *a,int s,int e)
{
	int p_ele = a[s];
	int c=0;
	for(int i = s;i <=e ;i++)
	{
		if(a[i] < p_ele)
		{
		c++;
	}
	}
	
	int p_index = s+c;
	
	int temp = a[s];
	a[s] = a[p_index];
	a[p_index] = temp;
	
	// sort
	int i = s,j = e;
	while(i < p_index && j > p_index)
	{
		while(a[i] <= p_ele)
		{
			i++;
		}
		while(a[j] >= p_ele)
		{
			j--;
		}
		if(i < p_index && j > p_index)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] =  temp;
			i++;
			j++;
		}
	}
	return p_index;
}
void quick(int *a,int s,int e)
{
	if(s >= e)
	{
		return;
	}
	int p = pivot(a,s,e);
	quick(a,s,p-1);
	quick(a,p+1,e);
}
int main()
{
	int a[] = {4,2,1,3,0};
	int size = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<size;i++)
		{
			
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	quick(a,0,size-1);
	for(int i=0;i<size;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<"\n";
}
