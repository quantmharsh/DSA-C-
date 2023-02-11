#include<iostream>
using namespace std;
class node
{
 public:
 int data;
 node*next=NULL;
  node(int d)
  {
    this->data=d;
    this->next=NULL;
  }

};
void insertnode( node* &tail , int element , int d)
{
node *temp=new node(d);
 //if  cll is empty
  if(tail==NULL)
  {
    tail=temp;
    tail->next=tail;
  }
  //when not empty
  else{
     
     node*current=tail;
     while(current->data!=element)
     {
        current=current->next;
     }
     temp->next=current->next;
        current->next=temp;
  }
}
void deletenode(node* &tail , int element)

{
  if(tail==NULL)
  {
    cout<<"cll empty"<<endl;
  }
  else{
     node*current=tail->next;
     node*prev=tail;
     while(current->data!=element)
     {
         prev=current;
        current=current->next;
      
     }
     prev->next=current->next;
    
     if(current==tail)
     {
        tail=prev;
     }
      current->next=NULL;

  }
}

void print( node* & tail)
{
    node*temp=tail;
    do{
        cout<<tail->data<<" "<<endl;
         tail=tail->next;

    }while(tail!=temp);
}


int main()
{
 node*tail=NULL;
 insertnode( tail,5,3);
 print(tail);
  insertnode( tail,3,7);
  print(tail);
  deletenode(tail,7);
  print(tail);
  
}