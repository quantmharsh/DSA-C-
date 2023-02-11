#include<iostream>

using  namespace std;
 class node
 {
    public:
     int data;
     node*next;
     public:
     node(int d)
     {
        this->data=d;
        this->next=NULL;
     }
 };
 class queue{
   public:
   node*front;
   node*back;
   public:
   queue()
   {
    front=NULL;
    back=NULL;
   }
   void push(int d)
   {
      node*temp=new node(d);

     if(front==NULL)
     {
        front=temp;
        back=temp;
        return;
        
     }
     back->next=temp;
     back=temp;

   }
   void pop()
   {
    if(front==NULL)
    {
        cout<<"underflow"<<endl;
    }
    node*todelete=front;

     cout<<"deleted element is"<<front->data<<endl;
     front=front->next;
     delete todelete;
   }
    
     int peek()
     {
        if(front==NULL)
        {
            cout<<"empty"<<endl;
            return -1; 
        }
        cout<<front->data<<endl;
     }
     bool empty()
     {
        if(front==NULL)
        {
        return true;
        }
        else{
            return false;
        }
     }
     void traverse()
     {
         node*temp=front;
         while(temp!=NULL)
         {
            cout<<temp->data<<endl;
            temp=temp->next;
         }
     }
 }; 
 int main()
 { 
    queue q;
    q.push(10);
    q.push(20);
  q.push(30);

 q.push(40);
 q.push(50);
 q.push(60);
 q.push(70);
 q.peek();
 q.pop();
 q.peek();
 q.traverse();



 }