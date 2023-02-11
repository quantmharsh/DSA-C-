
#include<iostream>
#include<stack>
using namespace std;


stack <int> solve(stack<int>&inputStack, int count, int size) {
    //base case
    if(count == size/2) {
        inputStack.pop();
        
    }
else{


    int num = inputStack.top(); 
    inputStack.pop();
    
	//RECURSIVE CALL
       inputStack= solve(inputStack, count+1, size);
    
    inputStack.push(num);
}
return inputStack;
    
}

void deleteMiddle(stack<int> inputStack, int N){
	
  	int count = 0;
     inputStack =solve(inputStack, count, N);
    while(!inputStack.empty())
    {
        int st=inputStack.top();
        cout<<inputStack.top()<<endl;
        inputStack.pop();
    }
   
}
void traverse(  stack<int> & inputStack)
{ 
       
      for (int i =  3; i >= 0; i--)
        {
            cout <<inputStack.top()<< endl;
           
        }
        return;
}
int main()
{
    stack<int> inputStack ;
    // inputStack.push(10);
    // inputStack.push(20);
    // inputStack.push(30);
    // inputStack.push(40);
    // int N=inputStack.size();
    cout<<" no of elements to push in stack"<<endl;
    int m=0;
    int d;
    cin>>m;
    for(int i=0;i<m;i++)
    {     
        cout<<"ENTER ELEMENT"<<endl;
        cin>>d;
         inputStack.push(d);
    }
    int N= inputStack.size();
    cout<<"size of stack is"<<N<<endl;
    deleteMiddle(inputStack ,N);
}
