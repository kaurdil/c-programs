#include<iostream>
using namespace std;

template<typename T>
class node
{   
  private:
    T data;
    node<T> *prev;
    node<T> *next;
    template <typename U>friend class double_ll;
};
template<typename T>
class double_ll
{
    public:
     double_ll();
     ~double_ll(); 
     bool empty() const; 
     const T& front() const;
     const T& back() const;
     void addFront(const T& e);  
     void addBack(const T& e); 
     void addpos(T d,T pos);
     void removeFront();  
     void removeBack();
     void removepos(T pos);
     void listReverse(double_ll <T>& L) ;
     void display();  
     
     private:
     node<T> *head;
     node<T> *tail;
     protected: 
     void add(node<T>* v, const T& e);  
     void remove(node<T>* v); 
     
     
};
template<typename T>
     double_ll<T>::double_ll()
     {
         head = new node<T>;  
        tail = new node<T>; 
        head->next = tail;  
        tail->prev = head;

     }
     
    template<typename T>
    double_ll<T>::~double_ll()
    {
        while (!empty()) removeFront(); 
         delete head;  
         delete tail;

    }
     template<typename T>
     bool double_ll<T>::empty() const
     { 
       return (head->next == tail); 
   }
    template<typename T>
    const T& double_ll<T>::front() const 
      { 
         return head->next->data; 
         } 
    template<typename T>
    const T& double_ll<T>::back() const 
      { 
        return tail->prev->data;  
         }
    template<typename T>
    void double_ll<T>::add(node<T>* v, const T& e) 
    { 
      node<T>* u = new node<T>; 
      u->data= e; 
      u->next = v; 
      u->prev = v->prev; 
      v->prev->next = v->prev = u; 
      }  
    template<typename T>
    void double_ll<T>::addFront(const T& e) 
     { add(head->next, e); }
     template<typename T>
     void double_ll<T>::addBack(const T& e) 
      { add(tail, e); } 
      template<typename T>
      void double_ll<T> ::remove(node<T>* v) 
      { 
      node<T> *u = v->prev;  
      node<T> *w = v->next; 
      u->next = w; 
      w->prev = u;
      delete v; 
      }
      template<typename T>
      void  double_ll<T> ::removeFront() 
      { remove(head->next); } 
      template<typename T> 
      void double_ll<T>::removeBack() 
       { remove(tail->prev); } 
       
       template<typename T> 
       void double_ll<T>::display()
     {
         node<T> *t=head->next;
         while(t!=tail)
         {
             cout<<t->data<<"->";
             t=t->next;
             
         }
     }
     template<typename T>
     void double_ll<T>::removepos(T pos)
     {  
                 node<T> *p=head->next;
                node<T> *temp=p->next;
                int count=1;
                if(pos==0)
                {
                   head->next=head->next->next;
                   delete p;
                }
              else
              {
                while( temp!=tail && count!=(pos-1))
                {  
                   p=p->next;
                   temp=temp->next;
                   count++;
                }
                if(temp==tail)
                {
                  cout<<"no";
                }
                else
                {
                p->next=p->next->next;
                delete temp;
                }
              }
              
                
            
     }
     template<typename T> 
       void double_ll<T>::addpos(T d, T pos)
     {
         node<T> *new_node=new node<T>;
         new_node->data=d;
        new_node->next=NULL;
         node<T> *t=head->next;
         int count=1;
         while(count!=(pos-1)&& t!=NULL)
         {
             t=t->next;
             count++;
         }
         if(t==tail)
         {
           cout<<"this position doesnot exist";
         }
         else
         {
         new_node->next=t->next;
         new_node->prev=t;
         t->next->prev=new_node;
         t->next=new_node;
         }
         
     }
     template<typename T> 
     void double_ll<T>:: listReverse(double_ll& L) 
	 {  
	    double_ll F; 
		while (!L.empty()) 
		{
		  T s = L.front(); 
		L.removeFront(); 
		F.addFront(s); } 
		while (!F.empty()) 
		{ 
		   T s = F.front();
		   F.removeFront();
		   L.addBack(s); 
		   }  
	}
		   
      int main()
      {
          double_ll<int> c;
          string m;
      do
      {
	  cout<<"Menu:";
      cout<<endl;
      cout<<"1.Insertion at beginning"<<endl;
      cout<<"2.Insertion at end"<<endl;
      cout<<"3.Insertion at random position"<<endl;
      cout<<"4.Deletion at beginning"<<endl;
      cout<<"5.Deletion at a position"<<endl;
      cout<<"6.Deletion at end"<<endl;
	  cout<<"7.reverse a list"<<endl;
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
		       	c.addFront(s);
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
		       	c.addBack(s);
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
		       c.addpos(num,pos);
		       c.display();
		       break;
		case 4: 
      	       
      	       if(!c.empty())
      	       {
		       	c.removeFront();
		       	c.display();
		       }
		       	break;
		case 5:
			   int g;
			   cout<<"enter the position to be deleted"<<endl;
			   cin>>g;
			   c.removepos(g);
			   c.display();
			   break;
		case 6: 
      	       if(!c.empty())
      	       {
      	        c.removeBack();
		       	c.display();
		   }
		        break;
		case 7:
			   c.listReverse(c);
			   c.display();
			   break;
	
		default:cout<<"wrong no entered";
	}
	cout<<endl;
	cout<<"do you want to continue? n or y:"<<endl;
    cin>>m;
}while(m!="n");
      }
