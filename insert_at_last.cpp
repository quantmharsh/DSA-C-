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
    node*node1=new node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    node*head=node1;
    node*tail=node1;
    insertatend(tail,8);
    print(head);
    insertatend(tail,6);
    print(head);
    cout<<tail->data<<endl;

}