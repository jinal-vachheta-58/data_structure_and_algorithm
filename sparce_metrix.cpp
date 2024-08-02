#include<iostream>
using namespace std;

int main()
{
	int m1[5][5],m2[10][3];
	int j,i,k=1,m,n;
	int l=0;
	
	cout<<"enter the size of matrix A :"<<endl;
	cin>>m>>n;
	
	cout<<"enter the elements of the matrix:"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>m1[i][j];
		}
	}
	
	for(i=0;i<m;i++)
	{
	    for(j=0;j<n;j++)
		{
			if(m1[i][j]!=0)
			{
				m2[k][0]=i;
				m2[k][1]=j;
				m2[k][2]=m1[i][j];
				k=k+1;
				l=l+1;//counting number of nonzero element
			}
			
		}	
	}
	m2[0][0]=m;//total row 
	m2[0][1]=n;//total column
	m2[0][2]=l;//total nonzero element 
	
	cout<<"sparse matrix representation :"<<endl;
	
	for(i=0;i<k;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<m2[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	  int m3[10][10] = {0}; // Initialize simple matrix with zeros

    cout << "Simple matrix representation:\n";
    for (int i = 1; i <= l; i++) {
        m3[m2[i][0]][m2[i][1]] = m2[i][2];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << m3[i][j] << "\t";
        }
        cout << endl;
    }
	return 0;
}

/*

enter the size of matrix A :
3       3
enter the elements of the matrix:
1       0       0
0       0       6
0       4       8
sparse matrix representation :
3       3       4
0       0       1
1       2       6
2       1       4
2       2       8


enter the size of matrix A :
4
4
enter the elements of the matrix:
1       0       0       5
0       0       0       4
0       3       0       0
0       0       0       7
sparse matrix representation :
4       4       5
0       0       1
0       3       5
1       3       4
2       1       3
3       3       7

*/
