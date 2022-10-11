#include "Song_Node.h"

class List
{
private:
	Node* head;
	Node* tail;
	int count;
	string order;
	
public:
	
	Node *returnhead()
	{
		return head;
	}
	List()
	{
		head = NULL;
		tail = NULL;
		count = 0;
		order = "";
	}
	
	void add(string value)
	{
		count++;
		Node *temp = new Node();
		temp->setData(value);
		temp->setNext(NULL);
		
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->setNext(temp);
			cout<<"Song Added Successfully.";
			tail = tail->getNext();
		}
	}
	
	// void push(string value)
	// {
	// 	Node *temp = new Node();
	// 	temp->setData(value);
	// 	temp->setNext(head);
		
	// 	head = temp;
		
	// 	count++;
	// }
	
	void display()
	{
		int numbering = 1;
		Node* tmp = head;
		while(tmp != NULL)
		{
			cout << numbering << ". " << tmp->getData() << endl;
			tmp = tmp->getNext();
			numbering++;
		}
		cout << endl;
	}
	
	void DelAtHead()
	{
		count--;
	
		Node* temp = head;
		
		head = temp->getNext();
		
		delete temp;
	}
	
	void DelAtTail()
	{
		count--;
		
		Node* temp = head;
		Node* temp2 = NULL;
		
		while(true)
		{
			if(temp->getNext() == tail)
			{
				temp2 = temp->getNext();
				tail = temp;
				delete temp2;
				tail->setNext(NULL);
				break;
			}
			else
			{
				temp = temp->getNext();
			}
		}
		return;
	}
	void search(string n)
	{
		Node *temp = head;
		while(temp!= NULL)
		{
			if(temp->getData()== n)
			{
				cout<<"Song found : "<< temp->getData()<<endl;
				break;
				
			}
			else
			{
				temp->setNext(temp->getNext());
			}
		}
		
		
	}
	
	void delAtNum(int n)
	{
		Node* temp1 = head;
		Node* del = NULL;
		int size = getCount();
		
		if(n==1)
		{
			DelAtHead();
			return;
		}
		
		if(n==size)
		{
			DelAtTail();
			return;
		}
		
		if(n>size)
		{
			cout << "This Number does not exist!" << endl;
			return;
		}
		
		for(int i=2; i<size; i++)
		{
			if(i == n)
			{
				count--;
				del = temp1->getNext();
				temp1->setNext(del->getNext());
				delete del;
				return;
			}
			else
			{
				temp1 = temp1->getNext();
			}
		}
	}

	string displayAtNum(int n)
	{
		Node* temp1 = head;
		Node* del = NULL;
		int size = getCount();
		
		if(n==1)
		{
			order = getHead();
			return order;
		}
		
		if(n==size)
		{
			order = getTail();
			return order;
		}
		
		if(n>size)
		{
			return "This Number does not exist!\n";
		}
		
		for(int i=2; i<size; i++)
		{
			if(i == n)
			{
				count--;
				del = temp1->getNext();
				order = del->getData();
				return order;
			}
			else
			{
				temp1 = temp1->getNext();
			}
		}
	}
	
	int getCount()
	{
		return count;
	}
	
	string getHead()
	{
		return head->getData();
	}
	string getTail()
	{
		return tail->getData();
	}
	string getOrder()
	{
		return order;
	}

	void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL)
		{
            // Store next
            next = current->getNext();
 
            // Reverse current node's pointer
            current->setNext(prev);
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        tail = head;
        head = prev;
    }
    bool isEmpty()
    {
    	if(head == NULL)
    	{
    		return true;
		}
		else
		{
			return false;
		}
	}
};

