#include<iostream>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node*next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertatbeg(node* &head , node * &tail ,int d)
{
    node*temp=new node(d);
    if(head==NULL)
    {
       head=temp;
       tail=temp;
    }
     temp->next=head;
     head=temp;
}
void insertatail(node *&head , node *&tail , int d)
{
  node*insert=new node(d);
   node *temp=head;
   while(temp-> next!=NULL)
   {
    temp=temp->next;
   }
    tail->next=insert;
    tail=insert;


}
void print( node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
       cout<<temp->data<<endl;
       temp=temp->next;
    }
    return ;
}
  //from this function we can do both the things together can find the cycle and also  starting node of cycle
bool detectCycle(node* &head )
{
    //using map for mapping each node with each bool value either true or false
    //after visitig node we will change it to visited true
    map<node* ,bool> visited;
    //for traversing ll
    node*temp=head;
    while(temp!=NULL)
    {
        if(visited[temp]=true)
        {
            cout<<"present at "<<temp->next->data;
           return true;
        }
        visited[temp]=true;
    }
    

    return false;
    
}

//cycle detection usinf floyeds cycle detection
  node*  floyedcd(node * &head)
{
    node* slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
            
        }
          slow=slow->next;
      
    
    if(slow==fast)
    {
      
        cout<<"FCD"<<slow->data<<endl;
          return slow;
    }
    
        
    
    }
    
       
}

  //getting starting node of loop
   node*  getStartingNode( node* &head)
  {
     node* intersection=floyedcd(head);
     node*slow=head;
    while(slow!=intersection)
    {
        intersection=intersection->next;
        slow=slow->next;
    }
    cout<<"cycle at"<<slow->data<<endl;

  }

int main()
{ 
    node* node1=new node(100);
    node* head=node1;
    node*tail=node1;
    
    insertatbeg(head,tail,10);
    insertatbeg(head,tail,20);
    insertatbeg(head,tail,30);
    insertatbeg(head,tail,40);

    insertatail(head,tail,101);
    
    print(head);
    cout<<tail->data<<endl;
    tail->next=head->next;
    cout<<"head->next"<<head->next->data<<endl;
   
     if(detectCycle(head))
        {
            cout<<"there is cycle "<<endl;
        }
        else
        cout<<"no cycle"<<endl;
        if(floyedcd(head)!=NULL)
        {
            cout<<"fcd present"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
       
       getStartingNode(head);
        
       
}