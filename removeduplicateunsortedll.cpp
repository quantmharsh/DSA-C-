#include<iostream>
using namespace std;
class node{
    public:
    
    int data;
    node*next;
    //node constructor
    node( int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void insertatend( node* &tail,int d)
{
    node*temp=new node(d);
    tail->next=temp;  
    tail=temp;
}
node*  sortll(node* &head)
{
  node*curr=head;
  int temp;
  while(curr!=NULL)
  {
    node*index=curr->next;
    while(index!=NULL)
    {
        if(curr->data>index->data)
        {
            temp=curr->data;
            curr->data=index->data;
            index->data=temp;
        }
        index=index->next;
    }
    curr=curr->next;
  }
  return head;
}
node* removeduplicate(node*head)
{
    node*curr=head;
    if(head==NULL)
    {
        return NULL;
    }
    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            curr->next=curr->next->next;
        }
        else{
             curr=curr->next;
        }
    }
    return head;
}
void print( node* &head)
{
    node*temp=head ;//creating a pointer that will point to head node
    while(temp!=NULL)//Till when temp does not become nnull we have to print  the current node data
    {
        cout<<temp->data<<endl;
        temp=temp->next;//shifting temp from 1st node to next one it will continue 

    }

}
int main()
{
    node*node1=new node(1);
    
    node*head=node1;
    node*tail=node1;
    insertatend(tail,3);
    insertatend(tail,2);
    insertatend(tail,3);
    print(head);
    cout<<"removing duplicate"<<endl;
    sortll(head);
    removeduplicate(head);
    print(head);

   
}