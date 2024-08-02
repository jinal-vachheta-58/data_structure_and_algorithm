#include<iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* front;
public:
    PriorityQueue() {
        front = NULL;
    }
    void enter_queue(int data, int priority) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->priority = priority;
        newNode->next = NULL;

        if (front == NULL || priority < front->priority) {
            newNode->next 	= front;
            front = newNode;
        }
        else {
            Node* temp = front;
            while (temp->next != NULL && temp->next->priority < priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void delete_queue() {
        if (front == NULL) {
            cout << "Underflow - Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        cout << "Deleted element: " << temp->data << endl;
        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements (data, priority): ";
        Node* temp = front;
        while (temp != NULL) {
            cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    PriorityQueue pq;

    char choice;
    int data, priority;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Enter element into queue" << endl;
        cout << "2. Delete element from queue" << endl;
        cout << "3. Peek front element" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                cout << "Enter data and priority to enqueue (data priority): ";
                cin >> data >> priority;
                pq.enter_queue(data, priority);
                break;
            case '2':
                pq.delete_queue();
                break;
            case '3':
                cout << "Front element: " << pq.peek() << endl;
                break;
            case '4':
                pq.display();
                break;
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while(choice != '5');

    return 0;
}

