#include<iostream>
using namespace std;
class node{
    public:
     int data;
    node*prev=NULL;
    node*next=NULL;
    public:
    node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertatbeg(node* &head,node*&tail , int d)
{  
     node*temp=new node(d);
    if(head==NULL)
{
   
     head=temp;
     tail=temp;
}
else{
    temp->next=head;
    head->prev=temp;
    head=temp;
}
}
void insertatlast(node* &head ,node* &tail, int d)
{
     node*temp=new node(d);
    if(head==NULL)
{
   
     head=temp;
     tail=temp;
}
  else{
    tail->next=temp;
     temp->prev=tail;
     tail=temp;

  }
}
  void insertatpos(node* &head, node*&tail, int d,int pos)
  {
    if(pos==1)
    {
        insertatbeg(head,tail,d);
        return;
    }
    
    int cnt=0;
    node*temp=new node( d);
    node*current=head;
    if(current->next==NULL)
    {
        insertatlast(head,tail,d);
        return;
    }
    while(cnt<pos-1)
    {
       current=current->next;
       cnt++;
    }
     temp->next=current->next;
     current->next->prev=temp;
     current->next=temp;
     temp->prev=current;
  }

  void deletenode(node *&head ,int pos)
  {
    if(pos==1)
    {
    node*temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    }
    else{
        node*temp=NULL;
        node*curr=head;
        int cnt=1;
        while(cnt!=pos)
        {
            temp=curr;
            curr=curr->next;
            cnt++;
        }
        temp->next=curr->next;
        curr->next->prev=temp;
        curr->next=NULL;
        curr->prev=NULL;



    }



  }
  void print(node* &head)
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
 node*head=NULL;
 node*tail=NULL;
 insertatbeg(head,tail,1);
 insertatbeg(head,tail,2);
 insertatbeg(head,tail,3);
 insertatbeg(head,tail,4);
 insertatbeg(head,tail,5);
 insertatbeg(head,tail,6);
 insertatlast(head,tail,7);
 print(head);
 cout<<"after deleting"<<endl;
 deletenode(head,2);
 
 print(head);
 
}