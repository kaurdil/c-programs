#include<iostream> 
using namespace std; 
class Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
	friend class AVL;
}; 

class AVL{
	
public:
int height(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 
 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 
Node* newNode(int key) 
{ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; 
	return(node); 
} 
 
Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	x->right = y; 
	y->left = T2; 
	
	y->height = max(height(y->left),height(y->right)) + 1; 
	x->height = max(height(x->left),height(x->right)) + 1; 
	
	return x; 
} 


Node *leftRotate(Node *x) 
{ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	y->left = x; 
	x->right = T2; 

	x->height = max(height(x->left),height(x->right)) + 1; 
	y->height = max(height(y->left),height(y->right)) + 1; 
	
	return y; 
} 


int getBalance(Node *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

Node* insert(Node* node, int key) 
{ 
	
	if (node == NULL) 
		return(newNode(key)); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else 
		return node; 
	
	node->height = 1 + max(height(node->left),height(node->right)); 
	
	int balance = getBalance(node); 

	// case 1:Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 
	// case 2: Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 
	// cases 3: Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
	//case 4: Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
} 
//finding inorder successor
Node * minValueNode(Node* node) 
{ 
	Node* current = node; 
	while (current->left != NULL) 
		current = current->left; 
	return current; 
} 

Node* deleteNode(Node* root, int key) 
{ 
	if (root == NULL) 
		return root; 
	if ( key < root->key ) 
		root->left = deleteNode(root->left, key); 
	else if( key > root->key ) 
		root->right = deleteNode(root->right, key); 
	else
	{ 
		// node with only one child or no child 
		if( (root->left == NULL) ||(root->right == NULL) ) 
		{ 
			Node *temp = root->left ? root->left :root->right; 
			// No child case 
			if (temp == NULL) 
			{ 
				temp = root; 
				root = NULL; 
			} 
			else // One child case 
			*root = *temp;
			delete temp; 
		} 
		else
		{ 
			// node with two children
			Node* temp = minValueNode(root->right); 
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key); 
		} 
	} 
	if (root == NULL) 
	return root; 
	//Updating height of the current node 
	root->height = 1 + max(height(root->left),height(root->right)); 

	// check if the node become unbalanced or not 
	int balance = getBalance(root); 
	// If this node becomes unbalanced, 
	// case 1: Left Left Case 
	if (balance > 1 && getBalance(root->left) >= 0) 
		return rightRotate(root); 
	// case 2:Left Right Case 
	if (balance > 1 && getBalance(root->left) < 0) 
	{ 
		root->left = leftRotate(root->left); 
		return rightRotate(root); 
	} 
	//case 3: Right Right Case 
	if (balance < -1 && getBalance(root->right) <= 0) 
		return leftRotate(root); 
	// case 4: Right Left Case 
	if (balance < -1 && getBalance(root->right) > 0) 
	{ 
		root->right = rightRotate(root->right); 
		return leftRotate(root); 
	} 
	return root; 
} 
void preOrder(Node *root) 
{ 
	if(root != NULL) 
	{ 
		cout << root->key << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 

};
int main() 
{   
    AVL a;
    int data,size,ch,count=0; 
    Node *root = NULL; 
	cout<<"enter no of nodes required: ";
	cin>>size; 
	do{
	cout<<"\n1. Insertion in AVL Tree\n";
    cout<<"2. Deletion in AVL Tree\n";
    cout<<"3. exit\n";
    cout<<"Enter your choice:";
    cin>>ch;
    switch (ch) {
        case 1:
                while (count!=size) {
	            cout<<"Enter your data:";
                cin>>data;
                count+=1;
	            root = a.insert(root, data);
                   }
                cout<<"preorder Traversal:";
	            a.preOrder(root);
                break;
        case 2:
		    cout<<"Enter your data:";
            cin>>data;
	        root=a.deleteNode(root, data);
	        cout<<"preorder Traversal After deletion:";
	        a.preOrder(root);
	         break;
	    case3:
		   exit(0);
		   break;
            }
}while(ch!=3);
    
	return 0; 
} 


