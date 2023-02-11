#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    public:
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
            }
};
node * insertintotree( node* &root , int d)
{
   //base case
   
   if(root ==NULL)
   {
    root=new node(d);
    return root;
   }
   if(d<root->data)
   {
    root->left=insertintotree(root->left ,d);
   }
   
   if(d >root->data)
   {
    root->right=insertintotree(root->right ,d);
   }
   return root;
   

}
node* minvalue( node* &root)
{
     node*temp=root;
    while(temp->left!=NULL)
    {
       temp=temp->left;

    }
     return temp;
}
node* deletefromtree( node* root , int t)
{
    
    //base case
    if(root==NULL)
    
        return root;

    
    if(root->data==t)
{
    //0 child 
    if(root->left ==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    //1 child
    //left child
    if(root->left!=NULL && root->right==NULL)
    {
        node*temp= root->left;
        delete root;
        return temp;

    }
    //right child
    if(root->right!=NULL && root->left ==NULL)
    {
          node*temp= root->right;
        delete root;
        return temp;
    }
    //2 child
    if(root->left!=NULL && root->right!=NULL)
    {
        int mini = minvalue(root->right)->data;
        root->data=mini;
        deletefromtree(root->right ,mini);
        return root;

    }
}
    // if t is greater then root
     else if(t>root->data)
    {
       root->right= deletefromtree(root->right , t);
        return root;
    }
    //if t is less then root
    else
    {
        root->left= deletefromtree(root->left , t);
        return root;
    }


}
void takeinput(node * &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        insertintotree(root ,data);
        cin>>data;
    }
}
void levelordertraversal(node*root)
{
     queue <node*> q ;
     q.push(root);
     q.push(NULL);
     
     
    while(!q.empty())
     {
        node*temp=q.front();
     q.pop();
        //precv level completef
        if(temp==NULL)
        {
          cout<<endl;
          //now checking child nodes
          if(!q.empty())
          {
            q.push(NULL);
          }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left)
            {
                 q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }

        }
        }

     }


 void inorder(node*root)
 {
    if(root==NULL)
    {
        return;

    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);


 }
 void searchinbst( node*root , int x)
 {
    //base case
      if(root==NULL){
        cout<<"data not found"<<endl;
        return;
    }
   
    if(x>root->data &&root!=NULL)
    {    
        searchinbst(root->right,x);
    }
     if(x <root->data &&root!=NULL)
    { 
        searchinbst(root->left ,x);
    }
       if(x==root->data &&root!=NULL)
      {
        cout<<"data found"<<endl;
        cout<<root->data<<endl;
        
        
      
    }
   
 }

int main()
{
    node*root=NULL;

    cout<<"enter data"<<endl;
    takeinput(root);



    // cout<<"levelorder traversal"<<endl;
    // levelordertraversel(root);
  cout<<"inorder traversal"<<endl;
  inorder(root);
  int x;
  cout<<"value to search"<<endl;
  cin>>x;
  cout<<"searching....."<<endl;

  searchinbst(root,x);
  cout<<"min value"<<endl;
   cout<< minvalue(root)->data<<endl;
   cout<<"enter value to delete"<<endl;
   int t;
   cin>>t;
   deletefromtree(root ,t);
    cout<<"inorder traversal after deleting"<<endl;
  inorder(root);
  cout<<"level prder traversal"<<endl;
  levelordertraversal(root);




}