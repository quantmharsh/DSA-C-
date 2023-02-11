#include<iostream>
#include<stack>

using namespace std;
struct node
{
    
    int data;
    node*next;
    
     
};
node *top= NULL;
bool isempty()
{
 if(top == NULL)
 return true;
 else
 return false;
}
void push(int value)
{
    node*temp= new node();
    temp->data=value;
    temp->next=top;
    top=temp;
}
void pop()
{
    node*temp=top;
    top=top->next;
    delete(temp);
}
void  showtop()
{
    if(isempty())
    {
        cout<<"stack underflow"<<endl;

    }
    else{
        cout<<top->data;
    }

    }

    void displayStack()
{
 if ( isempty() )
  cout<<"Stack is Empty";
 else
 {
  node *temp=top;
  while(temp!=NULL)
  {   cout<<temp->data<<" ";
   temp=temp->next;
  }
  cout<<"\n";
 }
 }
    int main()
    {
        push(1);
        push(2);
        push(3);
        showtop();
       displayStack();

    }

