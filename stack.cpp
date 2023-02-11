#include<iostream>
#include<stack>
using namespace std;

class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop() {
        if(top >=0 ) {
            top--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

    void traverse(){
        for(int i=size; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }
    
    //  void solve(int count)
    // {
    //     // base case

    //     if (count == size / 2)
    //     {
    //         pop();
    //         return;
    //     }

    //     int num = top();
    //     pop();

    //     // RECURSIVE CALL
    //     solve(count + 1);

    //     push(num);
    // }


};


int main() {
     int size;
     cout<<"enter size of stack"<<endl;
     cin>>size;
     int a;

    Stack st = Stack(size);
    for(int i=0;i<size;i++)
    {
        
      cout<<"push data"<<endl;
      cin>>a;
      st.push(a);

    }
    // st.push(22);
    // st.push(43);
    // st.push(44);
    // st.push(22);
    // st.push(43);

    st.traverse();

    return 0;
}