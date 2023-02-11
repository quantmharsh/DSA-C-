#include<iostream>
using namespace std;
class node{
    public:
  int data;
  node*next;
  
};
node* mergetwolist( node* &head1 ,node* &head2)
{
     node*result= new node();
        if(head1==NULL)
        {
            return(head2);
        }
        else if(head2==NULL)
        {
            return(head1);
        }
        if( head1->data <head2->data)
        {
            result=head1;
            result->next=mergetwolist( head1->next , head2);

        }
        if( head2->data <head1->data)
        {
            result =head2;
            result->next=mergetwolist(head1 ,head2->next);
        }
        return result;
}
void insertinlist(node**head_ref ,int data)
{
    node*temp=new node();
    temp->data=data;
    temp->next=(*head_ref);
    (*head_ref)=temp;


}
 void print( node* node)
 {
    while(node!=NULL)
    {
        cout<<node->data<<endl;
        node=node->next;
    }
 }
int main()
{
    node*result=NULL;
    node*head1=NULL;
    node*head2=NULL;
    insertinlist( &head1 , 8);
     insertinlist( &head1 , 6);
      insertinlist( &head1 , 4);
       insertinlist( &head2 , 9);
       insertinlist( &head2 , 7);
       insertinlist( &head2 , 5);
       result= mergetwolist(head1 ,head2);
       print(result);

}