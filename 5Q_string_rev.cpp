#include<iostream>
using namespace std;

void reverse(string &str,int size,int i=0)  
{  
   if(i>=size)
    {
     return;
    }
    else
    {
      char temp=str[size];
      str[size]=str[i];
      str[i]=temp;
      return reverse(str, size-1, i+1);
}  }
  
int main()  
{  
    string a;
    cout<<"enter a string";
	cin>>a; 
    int n=a.length();
    reverse(a,n-1,0); 
    cout<<a;
    return 0;  
}  


