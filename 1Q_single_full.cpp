#include<iostream>
using namespace std;

template<typename T>
class node
{   
  private:
    T data;
    node<T> *next;
    template <typename U>friend class single_ll;
};
template<typename T>
class single_ll
{
    public:
     single_ll();
     ~single_ll(); 
     bool empty() const; 
     const T& front() const; 
     void del_beg();
     void del_gn(T n);
     void del_pos(T pos);
     void remove_end();
     void insert_beg(T d);
     void insert_end(T d);
     void Insert_pos(T d,T pos);
     void rev();
     void swap(T n);
     void display();
     private:
     node<T> *head;
     
     
};
     template<typename T>
     single_ll<T>::single_ll()
     : head(NULL) { } 
     
    template<typename T>
    single_ll<T>::~single_ll()
    {
        node<T> *temp=head;
        head=head->next;
        delete temp;
    }
     template<typename T>
     bool single_ll<T>::empty() const
     { 
       return head== NULL; 
   }
    template<typename T>
    const T& single_ll<T>::front() const 
      { 
        return head->data;
         } 
    template<typename T>
    void single_ll<T>::insert_end(T d)
    {
       node<T> *new_node= new node<T>;
        new_node->data=d;
        
        
         if(head==NULL)
         {
             head=new_node;
             new_node->next=NULL;
             
         }
        else
           {
                node<T> *t =head;
                while(t->next!=NULL)
                {
                    t=t->next;
                }
            new_node->next=NULL;
            t->next=new_node;
           }
    }
    template<typename T>
    void single_ll<T>::insert_beg(T d)
    {
       node<T> *new_node= new node<T>;
        new_node->data=d;
        
        
         if(head==NULL)
         {
             head=new_node;
             new_node->next=NULL;
             
         }
        else
           {
                new_node->next=head;
                head=new_node;
           }
    }
     template<class T>
     void single_ll<T>::Insert_pos(T d,T pos)
     {
         node<T> *new_node=new node<T>;
         new_node->data=d;
        new_node->next=NULL;
         node<T> *t=head;
         int count=1;
         while(count!=(pos-1)&& t!=NULL)
         {
             t=t->next;
             count++;
         }
         if(t==NULL)
         {
           cout<<"this position doesnot exist";
         }
         else
         {
         new_node->next=t->next;
         t->next=new_node;
         }
     }
    template<typename T>
     void single_ll<T>:: rev()
     {
         node<T> *p=head;
         node<T> *temp=head;
         node<T>*prev=NULL;
         
         while(temp!=NULL)
         {
             temp=temp->next;
             p->next=prev;
             prev=p;
             p=temp;
             
         }
         head=prev;
     }
    
     template<typename T>
     void single_ll<T>::del_gn(T no)
     {  
         if(head==NULL)
         {
             cout<<"empty";
             
         }
        else if(head->data==no)
        {
            head=NULL;
        }
        else
           {
                node<T> *p=head;
                node<T> *temp=p->next;
                while( temp!=NULL && temp->data!=no)
                {  p=p->next;
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                  cout<<"no element exist";
                }
                else
                {
                 p->next=p->next->next;
                 delete temp;
                }
                
           }
     }
    template<typename T>
    void single_ll<T>::del_beg()
    {
       if(head==NULL)
         {
             cout<<"empty";
             
         }
        else
           {
                node<T> *temp=head;
                head=head->next;
                delete temp;
           }
    }
    
      template<class T>
     void single_ll<T>:: swap(T n)
     {
         node<T> *t=head;
         while(t->next->data!=n)
         {
             t=t->next;
         }
        int temp=t->next->data;
        t->next->data=t->data;
        t->data=temp;
     }
    template<typename T>
    void single_ll<T>::remove_end()
    
    {
       node<T> *t=head;
       while(t->next->next!=NULL)
       {
       	  t=t->next;
	   }
	   t->next=NULL;
	   
    }
    template<typename T>
     void single_ll<T>::del_pos(T pos)
     {  
                 node<T> *p=head;
                node<T> *temp=p->next;
                int count=1;
                if(pos==0)
                {
                   head=head->next;
                   delete p;
                }
              else
              {
                while( temp!=NULL && count!=(pos-1))
                {  
                   p=p->next;
                   temp=temp->next;
                   count++;
                }
                if(temp==NULL)
                {
                  cout<<"position doesnot exists";
                }
                else
                {
                p->next=p->next->next;
                delete temp;
                }
              }
              
                
            
     }
    template<typename T>
     void single_ll<T>:: display()
     {
         
		 node<T> *t=head;
         while(t!=NULL)
         {
             cout<<t->data<<"->";
             t=t->next;
             
         }
        
     }

  int main()
  {   
      single_ll <int> c;
      string m;
      do
      {
	  cout<<"Menu:";
      cout<<endl;
      cout<<"1.Insertion at beginning"<<endl;
      cout<<"2.Insertion at end"<<endl;
      cout<<"3.Insertion at random position"<<endl;
      cout<<"4.Deletion at beginning"<<endl;
      cout<<"5.Deletion of given node"<<endl;
      cout<<"6.Deletion at a position"<<endl;
      cout<<"7.Deletion at end"<<endl;
	  cout<<"8.reverse a list"<<endl;
	  cout<<"9.swap a given node with the prev node"<<endl;      
      cout<<"enter a no:"<<endl;
      int n;
      cin>>n;
      int s;
      switch(n)
      { 
      	case 1: 
      	       cout<<"enter the no of nodes u want:"<<endl;
      	       int m;
      	       cin>>m;
      	       while(m>0)
      	       {
      	       	cout<<endl;
		       	cout<<"enter an element:"<<endl;
		       	cin>>s;
		       	c.insert_beg(s);
		       	c.display();
		       	m--;
		       }
		       	break;
		       	
		
		case 2:       	             	       
		       cout<<"enter the no of nodes u want:"<<endl;
      	       int k;
      	       cin>>k;
      	       while(k>0)
      	       {
      	       	cout<<endl;
		       	cout<<"enter an element:"<<endl;
		       	cin>>s;
		       	c.insert_end(s);
		       	c.display();
		       	k--;
		       }
		       	break;
		case 3:
			   int num,pos;
		       cout<<"enter an element:"<<endl;
		       cin>>num;
		       cout<<"enter the position"<<endl;
		       cin>>pos;
		       c.Insert_pos(num,pos);
		       c.display();
		       break;
		case 4: 
      	       
      	       if(!c.empty())
      	       {
		       	c.del_beg();
		       	c.display();
		       }
		       	break;
		case 5:
			    int n;
			    cout<<"enter the node"<<endl;
			    cin>>n;
			    c.del_gn(n);
			    c.display();
			    break;
		case 6:
			   int g;
			   cout<<"enter the position to be delted"<<endl;
			   cin>>g;
			   c.del_pos(g);
			   c.display();
			   break;
		case 7: 
      	       if(!c.empty())
      	       {
      	        c.remove_end();
		       	c.display();
		   }
		        break;
		case 8:
			   c.rev();
			   c.display();
			   break;
		case 9:
			   int h;
		      cout<<"enter the node "<<endl;
		      cin>>h;
		      c.swap(h);
		      c.display();
			  break;	  
		default:cout<<"wrong no entered";
	}
	cout<<endl;
	cout<<"do you want to continue? n or y:"<<endl;
    cin>>m;
}while(m!="n");
}
      
      
      
    
    
