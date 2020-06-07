#include <iostream> 
using namespace std; 
int search(int arr[], int x, int n) 
{ 
	for (int i = 0; i < n; i++) 
		if (arr[i] == x) 
			return i; 
	return -1; 
}  
void printPostOrder(int in[], int pre[], int n) 
{ 
	int root = search(in, pre[0], n); 
	
	if (root != 0) 
		printPostOrder(in, pre + 1, root); 

	if (root != n - 1) 
		printPostOrder(in + root + 1, pre + root + 1, n - root - 1);  
	cout << pre[0] << " "; 
}  
int main() 
{ 
    int size;
	cout<<"Enter the no of nodes: ";
	cin>>size;
	int inor[size];
	int preor[size];
	cout<<"Inorder traversal :\n ";
	for (int i = 0; i < size; i++)
	{
		cout<<"Enter your element: ";
		cin>>inor[i];
		}
	cout<<"\nPreorder traversal :\n";
	for (int i = 0; i < size; i++)
	{   cout<<"Enter your element: ";
		cin>>preor[i];
	}
	cout<<"\nyour inorder is:\n";
	for (int i=0;i<size;i++)
	{
		cout<<inor[i]<<" ";
	}
	cout<<"\nyour preorder is:\n";
	for (int i=0;i<size;i++)
	{
		cout<<preor[i]<<" ";
		
	}
	cout << "\nPostorder traversal :\n"; 
	printPostOrder(inor, preor, size); 
	return 0; 
} 

