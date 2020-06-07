#include<iostream>
using namespace std;

void move_even(int ar[],int i,int size)
 
{
       if(i==size)
       {
         return ;
       }
       else if(ar[i]%2==0 && i!=0)
       {
           int temp=ar[i];
           int s=i-1;
           while(s>=0)
           {
          ar[s+1]=ar[s];
          s--;
           }
        ar[0]=temp;
        move_even(ar,i+1,size);
           }
        else
        {
          move_even(ar,i+1,size);
            }
     
}
int main()
{
    int n;
    cout<<"enter the size of an array";
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
    {   
        cout<<"enter an element"<<endl;
        cin>>a[i];
    }
    cout<<"your array is:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    move_even(a,0,n);
    cout<<endl;
    cout<<"modified array:";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
