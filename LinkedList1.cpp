#include<iostream>
using  namespace std;
 class node
 {
    public:
    int data;
    node*next=NULL;
    node*prev=NULL;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node()
    {
       int value=this->data;
       if(this->next!=NULL)
       {
          
          delete next;
          this->next=NULL;

       }
       cout<<"deleted value is"<<value<<endl;
    }

 };

 void insertatfirst( node * &head,int data)
 {
    node*temp=new node(data);
     
     temp->next=head;
     head->prev=temp;
     head=temp;

 }


 void insertatlast( node* &head ,node*&tail,int data)
 {
    node*temp=new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;


 }

 void insertatposition(node* &head,node* &tail ,int pos, int data)
 {
    if(pos==1)
    {
       insertatfirst( head, data);
    }
       node*temp=head;
    int cnt=1;
    while(cnt<pos)
    {
        temp=temp->next;
        cnt++;
    }
      
      node* nodeatpos=new node(data);
         nodeatpos->next=temp->next;
         temp->next->prev=nodeatpos;
         nodeatpos->prev=temp;
         temp->next =nodeatpos;


    if(temp==NULL)
    {
        insertatlast(head,tail,data);
    }

 }
    
 void deletenode(  node*head,node*tail,int pos)
 
 {
    if(pos==1)
    {
        node*temp=head;
        temp=head->next;
        head->next=NULL;
        head=temp;
     }

     int cnt=1;
     node*current=head;
     node*temp=NULL;
     while(cnt<pos)
     {
       temp=current;
       current=current->next;
       cnt++;
     }
     temp->next=current->next;
    current->next=NULL;
    delete current;

 }
 void print( node* &head,node* &tail)
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
 insertatfirst(head,4);
 insertatlast(head,tail,8);
 insertatlast(head,tail,12);
 insertatlast(head,tail,16);
 insertatlast(head,tail,20);
 insertatlast(head,tail,24);
 print(head,tail);
 insertatposition(head,tail,2,3);
 print(head,tail);
 deletenode(head,tail,2);
 print(head,tail);
  insertatposition(head,tail,2,3);
   insertatposition(head,tail,3,98);
   insertatposition(head,tail,4,99);
   print(head,tail);


}
