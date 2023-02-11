#include<iostream>
#define  n 20
using namespace std;
class queue
{
    public:
     int*arr;
     int front;
     int back;
      
     public:
     queue()
     {
         arr= new int[n];
        front=-1;
        back=-1; 
     }
     void push(int x)
     {
        if(back==n-1)
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1)
        {
            front++;
        }

     }
     void pop()
     {
        if(front==-1 || front> back)
        {
            cout<<"no element"<<endl;
            return;
        }
        front++;
     } 
     void traverse()
     {
        for(int i=front;i<=back;i++)
        {
          cout<<arr[i]<<endl;
        }
        return;
     }
     int peek()
     {
        if(front==-1 || front>back)
        {
            cout<<"no element"<<endl;
            return -1;

        }
        else
        return arr[front];
     }
     bool empty()
     {
        if(front==-1 || front>back)
        {
            return true;
        }
        else{
            return false;
        }
     }

};
int main()
{
    queue q;
    int num;
    int size=5;
    // cout<<"enter value in printer"<<endl;
    // for(int i=0;i<size;i++)

    //  {
    // cout<<"enter no"<<endl;
    //   cin>>num;
    //   q.push(num);
    //  }
    int op;
   
   
    cout<<"1.push"<<endl;
    cout<<"2.pop"<<endl;
    cout<<"3.traverse"<<endl;
    

     do{
         cin>>op;
    switch(op)
    {
      case 1:
      cout<<"enter no"<<endl;
      cin>>num;
      q.push(num);
      break;

      case 2:
      q.pop();
      break;
      case 3:
      q.traverse();
      break;


    }
     }while(op>0 &&op<4);
 
    cout<<"peek is"<<q.peek()<<endl;
    q.pop();
    q.traverse();
    q.empty();
}


