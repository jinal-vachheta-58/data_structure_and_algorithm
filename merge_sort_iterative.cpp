#include<iostream>
using namespace std;
// merge sort
void merge(int *a,int s,int mid,int e)
{
//	int mid = (s+e)/2;		
	
	//len of both
	int l1 = mid-s+1;
	int l2 = e-mid;
	
	// make array
	int *first = new int[l1];
	int *second = new int[l2];
	
	// copy elements in first
	int k=s;
	for(int i = 0;i<l1; i++)
	{
		first[i] = a[k++];
	}
	
	// copy elements in second
	k=mid+1;
	for(int i = 0;i<l1; i++)
	{
		second[i] = a[k++];
	}
	
	// sort and merge them
	int i1 = 0;
	int i2 = 0;
	k = s;
	
	while(i1 < l1 && i2 < l2)
	{
		if(first[i1] < second[i2])
		{
			a[k++] = first[i1++];
		}
		else
		{
			a[k++] = second[i2++];
		}
	}
	
	// break wwhile(condition)
	while(i1 < l1)
	{
		a[k++] = first[i1++];
	}
	
	while(i2 < l2)
	{
		a[k++] = second[i2++];
	}
	
	
	
	
}
int min(int x,int y)
{
	if(x<y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
void mergesort(int *a,int n)
{
	for(int i = 1;i<n;i = 2*i)
	{
		for(int j = 0;j<n-1;j = j+2*i)
		{
			int mid = min(j+i-1,n-1);
			int k = min(j+2*i-1,n-1);
			merge(a,j,mid,k);	
		}	
	}
	
	
	
//	for(int i = 1; i < n; i=i*2)
//	{
//		for(int j =0;j<n-1 ; j= j+2*i)
//		{
//			int mid = min(j+i-1 , n-1);
//			int k = min(j+2*i-1,n-1);
//			merge(a,j,k);
//		}
//	}
}


int main()
{
	int n;
	cout<<"Enter n : ";
	cin>>n;
	int a[100];
	
	for(int i=0;i<n;i++)
	{
		cin>> a[i];
	}
	cout<<endl;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<< a[i]<<endl;
	}
	
	
	mergesort(a,n);
	
	cout<<endl;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<< a[i]<<endl;
	}
	return 0;
}
