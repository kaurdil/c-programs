#include<iostream>
using namespace std;
class node
{
	int data;
	node *lchild;
	node *rchild;
	friend class Binary_Search;
};
class Binary_Search
{
	node *root;
	public:
		Binary_Search()
		{
			root=NULL;
		}
	node *createnode(int n);
	node *insert_key(node *k,int n);
	void inorder(node *m);
	node *delete_key(node *k,int n);
	node *FindMin(node *n);
};
node *Binary_Search::createnode(int n)
{
	node *new_node;
	new_node=new node;
    new_node->data=n;
	new_node->lchild=NULL;
	new_node->rchild=NULL;
	return new_node;
	
}
node *Binary_Search::FindMin(node* root)
{
	while(root->lchild != NULL) root = root->lchild;
	return root;
}
void Binary_Search::inorder(node* root)
{
	if (root == NULL)
		return;
 
	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);
}
node *Binary_Search::insert_key(node *root,int n)
{
	if(root==NULL)
	{
		root=createnode(n);
	}
	else if(n<root->data)
		{
		  root->lchild=insert_key(root->lchild,n);
		}
	else
	  {
	  	root->rchild=insert_key(root->rchild,n);
	  }
	return root;

}
node *Binary_Search::delete_key(node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->lchild = delete_key(root->lchild,data);
	else if (data > root->data) root->rchild = delete_key(root->rchild,data);	
	else {
		// Case 1:  No child
		if(root->lchild == NULL && root->rchild == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->lchild == NULL) {
		    node *temp = root;
			root = root->rchild;
			delete temp;
		}
		else if(root->rchild == NULL) {
			node *temp = root;
			root = root->lchild;
			delete temp;
		}
		// case 3: two children
		else { 
			node *temp = FindMin(root->rchild);
			root->data = temp->data;
			root->rchild = delete_key(root->rchild,temp->data);
		}
	}
	return root;
}

int main()
{
	Binary_Search s;
	node *root=NULL;
	int data,size,ch,count=0; 
    cout<<"Enter size";
    cin>>size;
  do{

    cout<<"\n1. Insertion in Binary Search Tree\n";
    cout<<"2. Deletion in Binary Search Tree\n";
    cout<<"3. exit\n";
    
    cout<<"Enter your choice:";
    cin>>ch;
    switch (ch) {
        case 1:
                while (count!=size) {
	            cout<<"Enter your data:";
                cin>>data;
                count+=1;
	            root=s.insert_key(root, data);
                   }
                cout<<"Inorder Traversal:";
	            s.inorder(root);
                break;
    
	    case 2:
		    cout<<"Enter your data:";
            cin>>data;
	        root=s.delete_key(root, data);
	        cout<<"Inorder Traversal After deletion:";
	        s.inorder(root);
	         break;
	    case3:
		   exit(0);
		   break;
  }
}while(ch!=3);
}

