#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
     int data;
    node*left;
    node*right;
    
      node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
      }
};
node* buildtree(node*root)
{
 cout<<"enter the  data"<<endl;
 int data;
 cin>>data;
 root=new node(data);

 if(data ==-1)
 {
    return NULL; 

 } 

 cout<<"enter left of the root"<<data<<endl;
 root->left=buildtree(root->left);

 cout<<"enter right of the root"<<data<<endl;
 root->right=buildtree(root->right);
 return root;
}


 
 // -------inorder--------
  void inorder(node*root)
  {
    if(root== NULL)
   {
     return;
   }
   inorder(root->left);
   cout<<root->data<<" "<<endl;
   inorder(root->right);
  }

//-------preorder---------
void preorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" "<<endl;
    preorder(root->left);
    preorder(root->right);
}

//--------postorder------
void postorder(node*root)
{
    if(root==NULL)
    {
        return;

    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" "<<endl;
}

 int height(node*root)
{

  if(root==NULL)
  {
    return 0;

  }
  int leftheight =height(root->left);
  int rightheight=height(root->right);
   int ans= max(leftheight,rightheight)+1;


 return ans;
  
   
}
pair<bool,int> isbalancefast(node * root)
{
  if(root==NULL)
  {
    pair<bool,int> p=make_pair(true,0);
    return p;
  }
  pair<int ,int> leftside=isbalancefast(root->left);
  pair<int, int> rightside=isbalancefast(root->right);
  bool leftans=leftside.first;
  bool rightans=rightside.first;
  bool diff=abs(leftside.second-rightside.second)<=1;
  pair<bool,int> ans;
  ans.second=max(leftans,rightans)+1;
  if(leftans && rightans && diff)
  {
    ans.first=true;
  }
  else{
    ans.first=false;
  }
  return ans;

}
bool checkbalancefast(node*root)
{
  return isbalancefast(root).first;
}

bool isbalance(node* root)
{
  if(root==NULL)
  {
    return true;
  }
  bool leftside=isbalance(root->left);
  bool rightside=isbalance(root->right);
  bool diffrence=abs(height(root->left)-height(root->right)) <=1;
  if( leftside && rightside && diffrence)
  {
    return true;
  }
  else{
    return false;
  }
}


int main()
{
    int i;
      node*root=NULL;
       root=buildtree(root);
       cout<<"level order traversal"<<endl;
       
       cout<<"inorder"<<endl;
       inorder(root);
       cout<<"preorder"<<endl;
       preorder(root);
       cout<<"postorder"<<endl;
       postorder(root);
       cin>>i;
       cout<<"height is?"<<height(root);
       cout<<"balanced ?"<<checkbalancefast(root);  
       cout<<"balanced slow"<<isbalance(root);
       
       
       return 0;
       
     
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 