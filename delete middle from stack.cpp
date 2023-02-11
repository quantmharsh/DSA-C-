#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    int size;
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (temp == NULL)
        {
            cout << "Stack overflow" << endl;
            return;
        }

        if (top == NULL)
        {
            top = temp;
            size++;
            return;
        }

        temp->next = top;
        top = temp;
        size++;
        return;
    }

    int pop()
    {
        Node *temp = top;
        if (temp == NULL)
        {
            return -1;
        }

        int data = temp->data;
        top = temp->next;
        delete temp;
        size--;
        return data;
    }

    

   
    void traverse()
    {
        Node *temp = top;
        if (temp == NULL)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << endl;
            cout << "-----------" << endl;
            temp = temp->next;
        }
        return;
    }
};

int main()
{
    Stack st = Stack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.solve(0);

    return 0;
}