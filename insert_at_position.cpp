#include<iostream>
using namespace std;
class node
{
public :
int data;
node*next;
 
 node(int data)     //creating first node
 {
    this->data=data;
    this->next=NULL;
 }
};

void insertatfirst(node* &head, int d)
{
    node*temp=new node(d);
    temp->next=head;
    head=temp;



}
void insertatlast(node* &tail,int d)
{
   node*temp=new node(d);
   tail->next=temp;
   tail=temp;

}
void insertatposition(node* &tail,node*&head, int pos,int data)
{      
   
     //inserting at first position
     if(pos==1)
     {
        insertatfirst(head,data);
     }
     
   
    //going to position where we have to insert the node
    node*temp=head;
    int c=1;
    while(c<=pos-1)
    {
        temp=temp->next;
        c++;
    }
    
     //creating node to be inserted
      node*insertatposition=new node(data);
       insertatposition->next=temp->next;
       temp->next=insertatposition;
       

       //inserting at last
       if(temp->next==NULL)
       {
        insertatlast(tail,data);
        return;
       }
}

void print( node* &head)
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
 node*node1=new node(1);
 node*head=node1;
 node*tail=node1;
  insertatlast(tail,8);
    print(head);
    insertatlast(tail,6);
    print(head);
    insertatposition(tail,head,3,43);
    print(head);
      insertatposition(tail,head,4,50);
    print(head);
    insertatfirst(head,4);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;

}