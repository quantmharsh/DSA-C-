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
    return;
}
  else{
    tail->next=temp;
     temp->prev=tail;
     tail=temp;
     



  }
  return;
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

  void sum(node*tail , node* tail2)
  {
      node*temp1=tail;
      node*temp2=tail2;
      int ans=0;
      while(temp1 !=tail && temp2!=tail2)
      {
          ans=ans + temp1->data+temp2->data;
          temp1=temp1->prev ;
          temp2=temp2->prev;
      }
      while(temp1!=NULL)
      {
          ans=ans+temp1->data;
          temp1=temp1->prev;
          
      }
      while(temp2!=NULL)
      {
          ans=ans+temp2->data;
          temp2=temp2->prev;
          
      }
      cout<<"sum is"<<ans<<endl;
  }
 
   node* reverse(node* p)
   {
    if(p!=NULL)
    {
        reverse(p->next);
        cout<<p->data<<endl;
        return 0;
    }
    return p;
   }
 
 
  node * add( node* &first ,node *&second)
  {
   
     node *anshead=NULL;
     node * anstail=NULL;
     int carry=0;
    
     while(first!=NULL && second!=NULL)
     {
           int sum=carry+first->data+second->data;
          int digit =sum%10;
         insertatlast(anshead ,anstail ,digit);
          carry=sum/10;
     }

     
     while(first!=NULL )
     {
           int sum=carry+first->data;
          int digit =sum%10;
          insertatlast(anshead ,anstail ,digit);
          carry=sum/10;
     }
     
     while(second!=NULL)
     {
           int sum=carry+second->data;
          int digit =sum%10;
          insertatlast(anshead ,anstail ,digit);
          carry=sum/10;
     }
     
     while(carry!=0)
     {
           int sum=carry+first->data+second->data;
          int digit =sum%10;
          insertatlast(anshead ,anstail ,digit);
          carry=sum/10;
     }
     return anshead;
  }
  node * carrysum(node * &first , node* &second)
  {
      first=reverse(first);
      second=reverse(second);
      node* ans=add(first,second);
       ans=reverse(ans);
   return ans;
  }
int main()
{ 
    node* first=new node(1);
 node*head=first;
 node*tail=first;
  node*second=new node(4);
  node*head2=second;
 node*tail2=second;
 insertatbeg(head,tail,2);
 insertatbeg(head,tail,3);
 
 print(head);
 cout<<endl;


 insertatbeg(head2,tail2,5);
 insertatbeg(head2,tail2,6);


 
 print(head2);
 sum(tail,tail2);
 cout<<"first reverese list"<<endl;
reverse(head);


 cout<<"second reversed list"<<endl;
 reverse(head2);

 
carrysum(first,second);


 


 
}