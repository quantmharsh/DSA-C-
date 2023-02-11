#include<iostream>
using namespace std;
 class node
 {
   public:
   int data;
   node*next;
   node(int d)
   {
    data=d;
    next=NULL;
   }
 };
 

 void reverse(struct node *p)
{
    if (p != NULL)
    {
        reverse(p->next);
        cout << "\n --> " << p->data << endl;
        return;
    }
    return;
}

 void insertintolast(node* &head ,node* &tail , int data)
 {
     node*temp=new node(data);
    
    tail->next=temp;
     tail=temp;
 }
  node* reverselist(node* head )
 {
    if(  head->next=NULL)
    {
        return head;
    }
    else{

    
     node*curr=head;
     cout<<"value of current"<<curr->data<<endl;
     node*prev=NULL;
     node*forward=NULL;
     while(curr!=NULL)
     {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        cout<<"value of curr in loop"<<curr->data<<endl;
        cout<<"value of prev"<<prev->data<<endl;
        curr=forward;
     }
      
         cout<<"prev->data"<<prev->data<<endl;
         cout<<"head->data"<<head->data<<endl;
            return  prev;
         
        
         
        
    }
 }
 void print(node* head)
 {
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
 }
int main()
{
 node* node1=new node(1);
 node*head=node1;
 node*tail=node1;
 insertintolast(head,tail,2);
 insertintolast(head,tail,3);
 
 print(head);
 cout<<tail->data<<endl;
//  reverselist(head);
//  node*newhead=reverselist(head);
reverse(head);
//  print(newhead);

}