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


 void levelordertraversel(node* root)
 {

    queue<node*> q;
    q.push(root);
    q.push(NULL);  //chagnging level after root node

    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        //for changing level
        if(temp==NULL)
        {    //purana level complete ho chuka h
            cout<<endl;
            //jo next level h usk liye    if q has more child nodes
            if(!q.empty())
            {
              q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";  //printing this here because here it is sure that temp is not null in if case it is null
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
int diameter(node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    int op1=diameter(root->left);
    int op2= diameter(root->right);
    int op3 =height(root->left)+1+height(root->right);
    int ans= max(op1,max(op2,op3));
    return ans;
}
int main()
{
    int i;
      node*root=NULL;
       root=buildtree(root);
       cout<<"level order traversal"<<endl;
       levelordertraversel(root);
       cout<<"inorder"<<endl;
       inorder(root);
       cout<<"preorder"<<endl;
       preorder(root);
       cout<<"postorder"<<endl;
       postorder(root);
       cin>>i;
       cout<<"height is"<<height(root);
       cout<<"diameter is"<<diameter(root);
       
       
       return 0;
       
     
}
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 