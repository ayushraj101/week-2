//Delete duplicate-value nodes from a sorted linked list



#include <iostream>
using namespace std;

class element
	{
		public:
		int data;
		element * next;
		element()
		{
			next = NULL;
		}
	};
	
class linklist
	{
		public:
		element * head;
		element * tail;
		
		linklist()
		{	
			head=NULL;
			tail=NULL;
		}
		
	void insert(int value);
	void insertat(int posi, int value );
	void delet();
	void deleteat(int posi);
	int countitems();
	void display();
	void sort();
	void del_dup();
	};
	
void linklist:: insert(int value )
	{
		// If 1st Node is added
		element * temp = new element;
		// Insert value in the node
		temp->data = value;
		// 1st Node only
		if (head == NULL)
		{
			head = temp;
		}
		// Any other Node only.
		 else 
		 {
		 	tail->next = temp;
		 }
		 tail = temp;   
	};
void linklist:: insertat(int posi, int value )
	{
		if(countitems()>posi)
		cout<< "Linked List does not have that many elements"<<endl;
		else 
		{
			element * current = head;
			for (int counter=2; counter< posi; counter++  )
			{
				current = current -> next ; 
			}
			element * temp = new element;
			temp->data = value;
			temp->next = current->next;
			current->next = temp;
		}	
	}
void linklist:: delet ()
	{
		element * temp = tail;
		element* current = head;
		while(current->next!= tail)
		{
			current = current -> next;
		}
		delete temp;
		tail = current;
		tail-> next = NULL;
	}
void linklist:: deleteat(int posi)
	{
		if(countitems() < posi)
		cout<< "Linked List does not have that many elements"<<endl;
		
		else 
		{
			element * current = head;
			for(int counter = 1; counter< posi; counter++ )
			{
				current = current-> next;
			}
			element * temp;
			temp = current ->next;
			//temp = temp -> next;
			delete current;
			head = temp;
		}
	}
int linklist :: countitems()
	{
		element*current = head;
		int counter = 1; 
		for (; current->next != NULL;counter++)
		{
			current = current -> next;
		}
		return counter;
	}
void linklist :: display ()
	{
		element * current=head;
		while( current != NULL)
		{
			cout<< current->data<< " -> ";
			current = current ->next;
		}
		cout<< "NULL";
		cout<<endl;
	}
void linklist:: sort()
	{
		element * current = head;
		element * fixer = head;
		element * temp;
		element * copy;
		while(fixer->next !=tail)
		{
			while(current -> next != NULL)
			{
				temp = current->next;
				if (temp->data < current-> data)
				{
					
					copy->data = current->data;
					current->data = temp->data;
					temp->data = copy-> data;
				}
				current = current -> next;
			}
			fixer= fixer -> next;
		}
	}
void linklist:: del_dup()
	{
		element * current = head->next;
		element * fixer = head;
		while(fixer -> next != NULL)
			{
				while(current -> next !=NULL)
					{
						if (fixer-> data == current-> data)
							{
								element * temp;
								temp = current ->next;
								delete current;
								head = temp;
							}
					}
			}
	}


int main()
	{
		linklist l1;
		l1.insert(21);
		l1.insert(2);
		l1.insert(3);
		l1.insert(1);
		l1.insert(32);
		l1.insert(41);
		l1.insert(13);
		l1.sort();
		l1.display();
		//l1.insertat(6, 45);
		return 0;
	}
	
