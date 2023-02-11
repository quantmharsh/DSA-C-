#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=100;
//creating array of type bool to store visited vertices
  bool vis[N];
  //and creatind adjency list  for storing edges
  vector<int> adj[N];

  int main()
  {
   //marking all visited as 0{}
   for(int i=0;i<N;i++)
   {
      vis[i]=0;
   }
   //taking no of nodes and edges as input
   int n,m;
   cout<<"enter no of nodes"<<endl;
   cin>>n;
   cout<<"enter no of edges"<<endl;
   cin>>m;

   //now takking edges as input between two  nodes
   int x,y;
   for(int i=0;i<m;i++)
   {
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);

   }
   //creating a queue ds
   queue<int> q;
   //pushing the first element from where we have to start
   q.push(1);
   //marking first node as visited
   vis[1]=1;
   while(!q.empty())
   {
      //storing the queue front element and then popping it out 
      int node=q.front();
      q.pop();
      cout<<node<<endl;
      //now we will go to edges of the node and check whether its edjes 
      //are visited or not 
      //if not visited then we will mark it as visited
      vector<int> :: iterator i;
      for(i=adj[node].begin();i!=adj[node].end();i++)
      {
         if(!vis[*i])
         {
           vis[*i]=1;
           q.push(*i); 
         }
      }

   }

  }


  