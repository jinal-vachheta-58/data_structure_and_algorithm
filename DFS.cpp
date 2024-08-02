#include<iostream>
using namespace std;

class stack{
    int *arr;
    int size;
    int top;

public:
    stack(int s)
    {
        size = s;
        top = -1;
        arr = new int[size];
    }

    ~stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack overflow" <<endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }
};

int main()
{
    stack s(5); // Creating a stack with size 5
    int i = 0; // Starting vertex
    int visited[5] = {0}; // Array to track visited vertices
    int arr[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}
    }; // Adjacency matrix representing the graph

    cout << i << " ";
    visited[i] = 1; // Mark the starting vertex as visited
    s.push(i); // Push the starting vertex into the stack

    // DFS traversal
    while(!s.isEmpty())
    {
        int u = s.pop();
        for(int j = 0; j < 5; j++)
        {
            if(arr[u][j] == 1 && visited[j] == 0)
            {
                cout << j << " "; // Print the visited vertex
                visited[j] = 1; // Mark vertex j as visited
                s.push(j); // Push vertex j into the stack
                break; // Break to continue DFS from vertex j
            }
        }
    }

    return 0;
}

