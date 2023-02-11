#include <iostream>

using namespace std;

class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int s)
    {
        size = s;
        arr = new int[s];
        top = -1;
    }

    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        return 0;
    }

    int isEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }

    void push(int num)
    {
        if (!isFull())
        {
            top++;
            arr[top] = num;
            return;
        }
        cout << "Stack overflow" << endl;
    }

    int pop()
    {
        if (!isEmpty())
        {
            int data = arr[top];
            top--;
            return data;
        }
        return -1;
    }

    void traverse()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
        return;
    }

    void solve(int count)
    {
        // base case

        if (count == size / 2)
        {
            pop();
            return;
        }

        int num = top;
        cout<<"num is"<<num<<endl;
        pop();

        // RECURSIVE CALL
        solve(count + 1);

        push(num);
    }
};

int main()
{
    Stack st = Stack(5);
    st.push(99);
    st.push(88);
    st.push(77);
    st.push(66);
    st.push(55);

    st.traverse();
    cout<<"---------------------"<<endl;
    st.solve(0);
    st.traverse();

    return 0;
}