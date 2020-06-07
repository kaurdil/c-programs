#include<iostream>
using namespace std;

template<typename T>
class node
{   
  private:
    T data;
    node<T> *next;
    template <typename U>friend class Circular_ll;
};
template<typename T>
class Circular_ll
{
    public:
     Circular_ll();
     ~Circular_ll(); 
     bool empty() const; 
     const T& front() const; 
     const T& back() const; 
     void advance(); 
     void add_end(const T& d);
	 void add_beg(const T& d); 
	 void Insert_pos(T d,T pos);
     void remove_beg();
	 void remove_end();
	 void del_pos(T pos); 
     void display();
     private:
     node<T> *cursor;
     
     
};
     template<typename T>
     Circular_ll<T>::Circular_ll()
     : cursor(NULL) { } 
     
    template<typename T>
    Circular_ll<T>::~Circular_ll()
    {
        while (!empty()) 
        {
            remove_end();
        }
    }
     template<typename T>
     bool Circular_ll<T>::empty() const
     { 
       return cursor == NULL; 
       }
     template<typename T>
     const T& Circular_ll<T>::back() const 
     { 
       return cursor->data;
        }
    template<typename T>
    const T& Circular_ll<T>::front() const 
      { 
        return cursor->next->data;
         } 
    template<typename T>
    void Circular_ll<T>::advance() 
       { 
        cursor = cursor->next; 
        }
    template<typename T>
    void Circular_ll<T>::add_end(const T& d)
    {
        node<T> *new_node=new node<T>;
        new_node->data=d;
        if(cursor==NULL)
        {
            new_node->next=new_node;
            cursor=new_node;
        }
        else
        {
            new_node->next=cursor->next;
            cursor->next=new_node;
            cursor=new_node;
        }
    }
    template<typename T>
    void Circular_ll<T>::add_beg(const T& d)
    {
        node<T> *new_node=new node<T>;
        new_node->data=d;
        if(cursor==NULL)
        {
            new_node->next=new_node;
            cursor=new_node;
        }
        else
        {
            
            new_node->next=cursor->next;
            cursor->next=new_node;
        }
    }
    template<typename T>
    void Circular_ll<T>::remove_beg()
    {
       node<T> *t=cursor->next;
       if(t==cursor)
       {
         cursor=NULL;
       }
       else
       {
         cursor->next=t->next;
         delete t;
       }
    }
    template<typename T>
    void Circular_ll<T>::remove_end()
    {
       node<T> *t=cursor->next;
       if(t==cursor)
       {
         cursor=NULL;
       }
       else
       {
         while(t->next!=cursor)
         {
            t=t->next;
		 }
		 t->next=cursor->next;
		 cursor=t;
		 
       }
    }
    template<typename T>
     void Circular_ll<T>:: display()
     {
         node<T> *t=cursor->next;
         do
         {
             cout<<t->data<<"->";
             t=t->next;
             
         }while(t!=cursor->next);
        
     }
    template<class T>
     void Circular_ll<T>::Insert_pos(T d,T pos)
     {
         node<T> *new_node=new node<T>;
         new_node->data=d;
        new_node->next=NULL;
         node<T> *t=cursor->next;
         int count=1;
         while(count!=(pos-1)&& t!=cursor)
         {
             t=t->next;
             count++;
         }
         if(t==cursor)
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
     void Circular_ll<T>::del_pos(T pos)
     {  
                 node<T> *p=cursor->next;
                node<T> *temp=p->next;
                int count=1;
                if(pos==1)
                {
                   remove_beg();
                }
              else
              {
                while( temp!=cursor && count!=(pos-1))
                {  
                   p=p->next;
                   temp=temp->next;
                   count++;
                }
                if(temp==cursor)
                { 
                  remove_end();
                }
                else
                {
                p->next=p->next->next;
                delete temp;
                }
              }
              
                
            
     }
  int main()
  {   
      Circular_ll <int> c;
      string m;
      do
      {
	  cout<<"Menu:";
      cout<<endl;
      cout<<"1.Insertion at beginning"<<endl;
      cout<<"2.Insertion at end"<<endl;
      cout<<"3.Insertion at random position"<<endl;
      cout<<"4.Deletion at beginning"<<endl;
      cout<<"5.Deletion at end"<<endl;
      cout<<"6.Deletion at a position"<<endl;
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
		       	c.add_beg(s);
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
		       	c.add_end(s);
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
		       	c.remove_beg();
		       	c.display();
		       }
		       	break;
		case 5: 
      	       if(!c.empty())
      	       {
      	        c.remove_end();
		       	c.display();
		   }
		        break;
		case 6:
			   int g;
			   cout<<"enter the position to be deleted"<<endl;
			   cin>>g;
			   c.del_pos(g);
			   c.display();
			   break;
		        
		default:cout<<"wrong no entered";
	}
	cout<<endl;
	cout<<"do you want to continue? n or y:"<<endl;
    cin>>m;
}while(m!="n");
}
      
      
    
    
