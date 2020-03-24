#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int val;
  struct node* left;
  struct node* right;
}node;
//names of fucntion:

node* insert(node* root,int ele);
void postorder(node * root); 
int height(node* root);
void no_siblings(node* root);
int leftLeafSum(node* root);
void cousin_nodes(node* root,int a,int b);
void spiralorder_traversal(node* root);

//defination of function: 
void postorder(node * root)
{
  if(!root)
    return ;
  else
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d,",root->val);
  }
}
int height(node* root)
{
  if(!root)
  {
    return 0;
  }
  else
  {
    int lh = height(root->left);
    int rh = height(root->right);
    if(rh < lh)
      return lh+1;
    else
      return rh+1;
  }
}
node* insert(node* root,int ele)
{
  if(!root)
  {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->val = ele;
    tmp->right =  tmp->left = NULL; 
    return tmp;
  }
  else if(ele < root->val)
  {
    root->left =  insert(root->left,ele);
  }
  else 
  {
    root->right =  insert(root->right,ele);
  }
  return root;
}
void no_siblings(node* root)
{
  if(!root)
  {
    return ;
  }
  else
  {
    if(root->left)
    {
      no_siblings(root->left);      
    }
    if(root->right)
    {
      no_siblings(root->right);
    }
    if(root->left && !root->right)
    {
      printf("%d,",root->left->val);
    }
    if(!root->left && root->right)
    {
      printf("%d,",root->right->val);
    }
  }
}
int isLeaf(node* root)
{
  if(!root)
  {
    return 0;
  }
  if(!root->left && !root->right)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int leftLeafSum(node* root)
{
  int sum = 0;
  if(!root)
  {
    return 0;
  }
  if(root->left)
  {
    if(isLeaf(root->left->left))
    {
      sum+=root->left->left->val;
    }
    sum += leftLeafSum(root->left);
  }
  if(root->right)
  {
    if(isLeaf(root->right->left))
    {
      sum+=root->right->left->val;
    }
     sum += leftLeafSum(root->right);
  }
  return sum;
}
void cousin_nodes(node* root,int a,int b)
{
  //assuming that a and b are present, and tree is not empty
  node* crt = root; 
  //I would like to count the number of steps to reach it
  int step_a=0,step_b=0;
  if(crt->val == a || crt->val == b)
  {
      printf("No root\n");
      return ;
  }
  while(crt->val != a)
  {
    step_a++;
    if(crt->val < a)
    {
      crt = crt->right;
    }
    else
    {
      crt = crt->left;
    }
  }

  crt = root;
  while(crt->val != b)
  {
    step_b++;
    if(crt->val < b)
    {
      crt = crt->right;
    }
    else
    {
      crt = crt->left;
    }
  }
  if(step_b == step_a)
  {
    int lr = 0;
    //to check if they aren't siblings
    crt = root;
    printf("%d\n",root->val);
    while(crt)
    {
      if(crt->left)
      {
        if(crt->left->val == a)
          break;
      }
      if(crt->right)
      {
        if(crt->right->val == a)
          break;
      }
      if(crt->val < a)
        crt = crt->right;
      else 
        crt = crt->left;
    }//breaking just a node previous to it
    if(crt->left) //they are siblings
    {
      if(crt->left->val == b)
      {
        printf("NO\n");
        return ;
      }
    }
    if(crt->right)
    {
      if(crt->right->val == b)
      {
        printf("No\n");
        return;
      }
    }
    printf("Yes\n");
  }
  else
  {
    printf("NO\n");
  }
}
void printLevel(node* root,int lvl,int flag)
{
  if(!root)
    return;
  if(lvl == 1)
    printf("%d,",root->val);
  else 
  {
    if(flag)
    {
      printLevel(root->left,lvl-1,flag);
      printLevel(root->right,lvl-1,flag);
    }
    else
    {
      printLevel(root->right,lvl-1,flag);
      printLevel(root->left,lvl-1,flag);
    }
  }
}
void spiralorder_traversal(node* root)
{
  if(!root)
  {
    return ;
  }
  int h = height(root);
  int flag = 0;
  for(int i = 1;i<=h;i++)
  {
    printLevel(root,i,flag);
    flag = !flag;
  }
}
