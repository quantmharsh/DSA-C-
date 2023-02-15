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





bool Isduplicate(node*root , node*root2)
{
//base case
if(root==NULL &&root2==NULL)
{
   return true;
}
else if(root!=NULL && root2==NULL)
{
  return false;
}
else if(root==NULL && root2!=NULL)
{
  return false;
}
bool leftside=Isduplicate(root->left ,root2->left);
bool rightside=Isduplicate(root->right,root2->right);

bool value= root->data==root2->data;
if(leftside && rightside && value)
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
      node*root2=NULL;
       root=buildtree(root);
       root2=buildtree(root2);
       cout<<"level order traversal"<<endl;
       
       cout<<"inorder"<<endl;
       inorder(root);
       inorder(root2);
       cout<<"DUPLICATE ?"<<endl;
       cout<<Isduplicate(root,root2)<<endl;
       
       
       
       return 0;
       
     
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 