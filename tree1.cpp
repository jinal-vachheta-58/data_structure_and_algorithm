

#include <iostream>
using namespace std;

// define structure of tree node
struct treenode
{
    treenode *left;
    int data;
    treenode *right;
    treenode(int val)
    {
        left = NULL;
        data = val;
        right = NULL;
    }
};

class binary_search_tree;
class stack;
// define stack class
class stack
{
    treenode **arr;
    int size;
    int top;

public:
    stack(int s)
    {
        size = s;
        top = -1;
        arr = new treenode *[size];
        // arr = new int(data);
    }

    ~stack()
    {
        delete[] arr;
    }

    bool isempty()
    {
        return top == -1;
    }

    bool isfull()
    {
        return top == size - 1;
    }

    void push(treenode *val)
    {
        if (isfull())
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    treenode *pop()
    {
        if (isempty())
        {
            cout << "stack underflow" << endl;
            return NULL;
        }
        return arr[top--];
    }

    treenode *peek()
    {
        if (isempty())
        {
            cout << "stack is empty" << endl;
            return NULL;
        }
        return arr[top];
    }
};

// define binary search tree data structure class
class binary_search_tree
{
    treenode *root;

public:
    binary_search_tree()
    {
        root = NULL;
    }

    void insert(int val)
    {
        treenode *newnode = new treenode(val);

        if (root == NULL)
        {
            root = newnode;
            return;
        }
        else
        {
            treenode *current = root;

            while (true)
            {
                if (val < current->data)
                {
                    if (current->left == NULL)
                    {
                        current->left = newnode;
                        return;
                    }
        	            current = current->left;
                }
                else if (val > current->data)
                {
                    if (current->right == NULL)
                    {
                        current->right = newnode;
                        return;
                    }
                    current = current->right;
                }
                else
                {
                    cout << "same value can not be inserted\n";
                    delete newnode;
                    return;
                }
            }
        }
    }

    bool search(int val)
    {
        treenode *current = root;
        while (current != NULL)
        {
            if (current->data == val)
            {
                return true;
            }
            else if (val < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return false;
    }
    
    
treenode * minvalue(treenode * node)
{
	treenode * cur = node;
	while(cur != NULL && cur->left != NULL)
	{
		cur = cur->left;
	}
	return cur;
}



void remove(int val)
{
	root = removenode(root , val);
}
treenode * removenode(treenode * node , int val)
{
	if(node == NULL)
	{
		cout<<" tree is empty";
		return node;
	}
	else
	{
//		tree is not empty
		if(val < node->data)
		{
			node->left = removenode(node->left,val);
		}
		else if(val > node->data)
		{
			node->right = removenode(node->right,val);
		}
		else
		{
			if(node->left == NULL && node->right == NULL)
			{
				delete node;
				return NULL;
			}
			else if(node->left == NULL && node->right != NULL)
			{
				struct treenode *temp = node->right;
				delete node;
				return temp;
			}
			else if(node->left != NULL && node->right == NULL)
			{
				treenode *temp = node->left;
				delete node;
				return temp;
			}
			else
			{
				treenode * temp = minvalue(node->right);
				node->data = temp->data;
				node->right = removenode(node->right,temp->data);
			}
		}
		return node; 
	}
}

     void inorder()
     {
     cout<<"inorder travasal : ";
    
     stack st(100);
     treenode *node = root;
    
     while(current != NULL || !st.isempty())
     {
     while(current != NULL)
     {
     st.push(current);
     current = current->left;
     }
    
     if(!st.isempty())
     {
     treenode* temp = st.pop();
     cout<<endl<<temp->data;
     current = current->right;
     }
     }
     cout<<endl;
     return;
     }



    void preorder()
    {
        cout << "Preorder traversal: ";

        if (root == NULL)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        stack st(100);
        st.push(root);

        while (!st.isempty())
        {
            treenode *current = st.pop();
            cout << current->data << " ";

            // Push right child first so that it is processed after the left child
            if (current->right != NULL)
            {
                st.push(current->right);
            }

            // Push left child (if exists)
            if (current->left != NULL)
            {
                st.push(current->left);
            }
        }

        cout << endl;
    }

    void postorder()
    {
        cout << "Postorder traversal: ";

        if (root == NULL)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        stack st1(100);
        stack st2(100);
        st1.push(root);

        while (!st1.isempty())
        {
            treenode *current = st1.pop();
            st2.push(current);

            // Push left child first, if exists
            if (current->left != NULL)
            {
                st1.push(current->left);
            }

            // Push right child, if exists
            if (current->right != NULL)
            {
                st1.push(current->right);
            }
        }

        // Print nodes in reverse order from the second stack
        while (!st2.isempty())
        {
            treenode *current = st2.pop();
            cout << current->data << " ";
        }

        cout << endl;
    }

};

int main()
{
    binary_search_tree bst;
    int t_data, op;

    do
    {
        cout << "\n_________________________________\n";
        cout << "\n1. insert";
        cout << "\n2. delete";
        cout << "\n3. search";
        cout << "\n4. inorder travarsal";
        cout << "\n5. postorder travarsal";
        cout << "\n6. preorder travarsal";

        cout << "\nenter option : ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "\nenter data to insert : ";
            cin >> t_data;
            bst.insert(t_data);
            break;
        case 2:
             cout<<"\nenter data to delete : ";
             cin>>t_data;
             bst.remove(t_data);
            break;
        case 3:
            cout << "\nenter data to search : ";
            cin >> t_data;
            if (bst.search(t_data))
            {
                cout << "\ntrue\n";
            }
            else
            {
                cout << "\nfalse\n";
            }
            break;
        case 4:
            bst.inorder();
            break;
        case 5:
            bst.postorder();
            break;
        case 6:
            bst.preorder();
            break;
        }

    } while (op != 99);
    return 0;
}

