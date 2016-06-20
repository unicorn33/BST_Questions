#include <iostream>
#include <climits>

using namespace std;

typedef struct BSTNODE
{
	struct BSTNODE *pleft;
	struct BSTNODE *pright;
	int val;
}node;

node* insertNode(node *root, int val);
node* createNode(int val);
void inOrderTraverse(node *root);
int findMin(node *root);
int findMax(node *root);

int main()
{
  int arr[] = {4, 5, 8, 10, 15, 3, 6, 20};
  int nelem = sizeof(arr)/sizeof(int);

  node *root = NULL;
  int count = 0;
  while(count < nelem)
  {
      root = insertNode(root, arr[count]);
	  count++;
  }

  inOrderTraverse(root);
  cout << "\n";
  cout << " Min value is " << findMin(root) << "\n";
  cout << " Max value is " << findMax(root) << "\n";

  root = insertNode(root, 12);
  root = insertNode(root, 1);

  inOrderTraverse(root);
  cout << "\n";
  cout << " Min value is " << findMin(root) << "\n";
  cout << " Max value is " << findMax(root) << "\n";

  return 0;
}

node* createNode(int val)
{
    node* pelement = new node;
    if (!pelement)
    {
    	cout << " memory allocation failed \n ";
    }

    pelement->pleft = NULL;
    pelement->pright = NULL;
    pelement->val = val;

    return pelement;
}


node* insertNode(node *root, int val)
{
    if (root == NULL)
    {
    	root = createNode(val);
    	return root;
    }

    if(root->val >= val)
    {
    	root->pleft = insertNode(root->pleft, val);
    }
    else
    {
    	root->pright = insertNode(root->pright, val);
    }

    return root;
}

void inOrderTraverse(node *root)
{
    if (root == NULL)
    {
    	return;
    }

    inOrderTraverse(root->pleft);
    cout << " " << root->val << "";
    inOrderTraverse(root->pright);
}

int findMin(node *root)
{
    if (root == NULL)
    {
    	return INT_MIN;
    }

    while(root->pleft != NULL)
    {
    	root = root->pleft;
    }

    return root->val;
}

int findMax(node *root)
{
    if (root == NULL)
    {
    	return INT_MIN;
    }

    while(root->pright != NULL)
    {
    	root = root->pright;
    }

    return root->val;
}
