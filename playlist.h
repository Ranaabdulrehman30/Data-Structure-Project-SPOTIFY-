#include<iostream>
#include"Playlist_Node.h"
using namespace std;

class LL
{
private:
	PNode* head;
	PNode* tail;
	int count;
	
public:

	LL()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}
	PNode *returnhead()
	{
		return head;
	}
	
	void add(string value)
	{
		count++;
		PNode *temp= new PNode();
		temp->setData(value);
		
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->setNext(temp);
			tail = tail->getNext();
		}	temp->setNext(NULL);
	}
	 
	void display()
	{
		PNode* tmp = head;
		int number = 1;
		while(tmp != NULL)
		{
			cout<<number <<". "<< tmp->getData()<<endl;
			tmp = tmp->getNext();
			number++;
		}cout<<endl;
		cout <<"______________________________ "<< endl;
	}
	
	void DelAtHead()
	{
		count--;
	
		PNode* temp= head;
		
		head = temp->getNext();
		
		delete temp;
	}
	
	int getCount()
	{
		return count;
	}
	PNode *getHead()
	{
		return head;
	}
	
	string gethead()
	{
		return head->getData();
	}
	string getTail()
	{
		return tail->getData();
	}
	PNode* SortedMerge(PNode* a, PNode* b)
	{
    PNode* result = NULL;
     
    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);
     
    /* Pick either a or b, and recur */
    if (a->getNext()->getData() <= b->getNext()->getData())
    {
        result = a->getNext();
        result->setNext(SortedMerge(a->getNext(), b));
        
    }
    else
    {
        result = b->getNext();
        result->setNext(SortedMerge(a, b->getNext()));
    }
    return(result);
}
	void recentlyplayedlist(PNode *head)
	{
		PNode* tmp = head;
		int number = 1;
		while(tmp != NULL)
		{
			cout<<number << tmp->getData();
			tmp = tmp->getNext();
			number++;
		}cout<<endl;
		cout <<"______________________________ "<< endl;
		
	}
};
