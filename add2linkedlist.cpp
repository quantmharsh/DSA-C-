#include<iostream>
using namespace std;
 struct  node
 {
   public:
   int data;
   struct  node*next;
   node(int d)
   {
    data=d;
    next=NULL;
   }
 };
 void insertintolast( struct node* &head ,struct node* &tail , int data)
 {
     node*temp=new node(data);
    
    tail->next=temp;
     tail=temp;
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

    node* reverse(struct node *p)
{
    if (p != NULL)
    {
        reverse(p->next);
        cout << "\n --> " << p->data << endl;
        return;
    }
    return;
}
struct node* add(  node* node1, node*node2  )
{
    int carry=0;
    node* anshead=NULL;
    node* anstail=NULL;

    while( node1!=NULL || node2 !=NULL || carry!= 0 )
 {
      int val1=0;
      
    if( node1!=NULL)
    {
    val1=node1->data;
    }
    
    int val2=0;
    if( node2!=0)
    {val2=node2->data;
    } 
    int sum= val1+val2+carry;
      int digit=sum%10;
      int carry=sum/10;
      insertintolast( anshead ,anstail,digit);
       if(node1!=NULL)
       {
        node1=node1->next;
       }
       if(node2!=NULL)
       {
        node2=node2->next;
       }

 }
 return anshead;

}
struct node* addtwolist( struct node* node1, struct node* node2)
{
    //step 1 reverse node
    node1=reverse(node1);
    node2=reverse(node2);
    //step 2 add 2 ll
    node* ans=add(node1 , node2);
    //step 3 reverse ans
     ans=reverse(ans);
     return ans;
}


 
int main()
{
  node* node1=new node(1);
 node*head=node1;
 node*tail=node1;
 insertintolast(head,tail,2);
 insertintolast(head,tail,3);
 
 print(head);


reverse(head);

//2nd node
node*node2=new node(6);
node*headtwo=node2;
node*tailtwo=node2;
insertintolast(headtwo,tailtwo,7);
insertintolast(headtwo,tailtwo,8);
insertintolast(headtwo,tailtwo,9);
cout<<"2nd linked list"<<endl;
print(headtwo);
cout<<"2nd linked list after reverse"<<endl;
reverse(headtwo);

addtwolist(node1 , node2);



}