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
 //creating destructor to free up memory 
 ~node()
 {
    int value=this->data;
    if(this->next!=NULL)
    {
        delete next;
        this->next=NULL;
    }
    cout<<"memory is free for data with data"<<value<<endl;

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
    while(c<pos-1)
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

//------deleting node-------------

void DeleteNode(int position, node*head)
{
    //deleting first node
    if(position==1)
    {
        node*temp=head;
        head=head->next;
         temp->next=NULL;
         delete temp;
    }

    //deleting at any other position and end as well
    else{
        int cnt=1;
        node*current=head;
        node*temp=NULL;
        while(cnt<position)
        {
            temp=current;
            current=current->next;
            cnt++;
        }
        temp->next=current->next;
        current->next=NULL;
        delete current;
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
    cout<<"------------------"<<endl;
    print(head);
    cout<<"--------------------"<<endl;
    cout<<head->data<<endl;
    cout<<tail->data<<endl;


    DeleteNode(2,head);
    print(head);

}