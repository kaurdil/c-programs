#include<bits/stdc++.h> 
using namespace std;  
int postIndex = 0; 
int search(int in[], int data,int n) 
{ 
    int i = 0; 
    for (i = 0; i < n; i++) 
        if (in[i] == data) 
            return i; 
    return i; 
} 
void Pre(int in[], int post[], int begin, 
            int end, stack<int> &s,int n) 
{ 
    if (begin > end) 
        return; 
    int val = post[postIndex]; 
    int inIndex = search(in, val, n); 
    postIndex--; 
    Pre(in, post, inIndex + 1, end, s, n); 
    Pre(in, post, begin, inIndex - 1, s, n); 
    s.push(val); 
} 
void Print_Pre(int in[], int post[],int n) 
{ 
    int len = n; 
    postIndex = len - 1; 
    stack<int> s ; 
    Pre(in, post, 0, len - 1, s, n); 
    while (s.size() > 0) 
    { 
        cout << s.top() << " "; 
        s.pop(); 
    } 
} 
int main() 
{ 
    int size;
    cout<<"Enter the number of nodes in binary tree: ";
	cin>>size;
	int inorder[size]; 
    int postorder[size];
	cout<<"Inorder traversal :\n";
	for (int i = 0; i < size; i++)
	{   cout<<"Enter element: ";
		cin>>inorder[i];
	}
	cout<<"\nPostorder traversal :\n";
	for (int i = 0; i < size; i++)
	{   
	    cout<<"Enter element: ";
		cin>>postorder[i]; 
	}
	cout<<"your inorder :";
	for (int i = 0; i < size; i++)
	{
		cout<<inorder[i]<<" ";
	}
	cout<<"\nyour postorder:";
	for (int i = 0; i < size; i++)
	{   
		cout<<postorder[i]<<" ";
	}
    cout << "\nPreorder traversal :\n"; 
    Print_Pre(inorder, postorder,size); 
} 
