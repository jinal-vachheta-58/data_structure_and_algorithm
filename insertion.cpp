#include<iostream>
using namespace std;
int main()
{
	int a[5];
	int n= 5;
	
	for(int i= 0;i<n;i++)
	{
		cin>>a[i] ;
	}
	cout<<"\nstart\n";
	
	for(int i= 0;i<n;i++)
	{
		cout <<a[i] << endl;
	}
	
	
	int  i,key,j;
	for(i =1;i<n;i++)
	{
		key = a[i];
		j=i-1;
		
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
	}
	
	cout<< endl;
	
	for(i= 0;i<n;i++)
	{
		cout<<a[i] << endl;
	}
	return 0;
}
