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
 
 node* merge( node*left , node*right)
 { 
    cout<<"inside merge"<<endl;
    node*ans =new node(-1);
    node*temp =ans;
    // if left list is empty
    if(left==NULL)
    {
        return right;
    }
    // if right is empty
    if(right==NULL)
    {
        return left;
    }
    while(left!=NULL && right!=NULL)
    {
          if(left->data <right->data)
          {
            temp->next=left;
            temp=left;
            left=left->next;
          }
          if(right->data <left->data)
          {
            temp->next=right;
            temp=right;
            right=right->next;

          }
    }
          //if only left list is remaining
          while(left!=NULL)
          {
            temp->next=left;
            temp=left;
            left=left->next;
          }
          //if only right list is remaining
          while(right!=NULL)
          {
             temp->next=right;
             temp=right;
             right=right->next;
          }
      ans=ans->next;
      cout<<"Returning ans"<<ans<<endl;
      return ans;
    

 }

node* findmid( node*head)
{  
    cout<<"inside mid"<<endl;
    node*slow=head;
    node*fast=head->next;
    if(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast =fast->next->next;
    }
    cout<<"returning mid"<<slow<<" mid data-> "<<slow->data<<endl;
    return slow;
}
   node* mergesort( node* &head)
{
    cout<<"inside mergesort"<<endl;
    // base case
    if(head==NULL ||head->next==NULL)
    {
        return head;
    }
  
    // finding mid
    node* mid=findmid(head);
    // doing partition and calling mergesort recursivly
      node*left= head;
    node*right = mid->next;
      mid->next=NULL;
    left=mergesort(left);
    right=mergesort(right);

      // merging two linked list
     node* result=  merge(left , right);
     cout<<"returning result"<<result<<" ans data"<<result->data<<endl;
      return result;
      

    

}
int main()
{
 node*node1=new node(1);
 node*head=node1;
 node*tail=node1;
  insertatlast(tail,8);
    // print(head);
    insertatlast(tail,6);
    // print(head);
    insertatposition(tail,head,3,43);
    // print(head);
      insertatposition(tail,head,4,50);
    // print(head);
    insertatfirst(head,4);
    print(head);
    // cout<<head->data<<endl;
    // cout<<tail->data<<endl;
    
    
cout<<"after sorting"<<endl;
     head = mergesort(head);
    
    print(head);

}