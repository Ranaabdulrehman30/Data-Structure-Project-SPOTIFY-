#include"Final_song.h"
#include"playlist.h"
using namespace std;

class queue : public LL 
{
	PNode *front; 
	PNode *rare;
	Node *sfront;
	Node *srare;
	
	public:
		int count1;
		int qnum;
		queue()
		{
			front = NULL;
			rare = NULL;
			sfront = NULL;
			srare = NULL;
		}
		bool isempty()
		{
			if(front == NULL && rare == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void enque(PNode *head)
		{
			PNode* tmp = head;
		while(tmp != NULL)
		{
			if(isempty())
			{
				front=tmp;
				rare= tmp;
				cout<<"First Song added to queue successfully."<<endl;
			}
			else
			{
				rare->setNext(tmp);
				rare = tmp;
				cout<<"Song added to queue successfully."<<endl;	
			}
			tmp = tmp->getNext();
		}
		}
		PNode *deque()
		{
			PNode *temp= NULL;
			if(isempty())
			{
				cout<<"No songs in queue."<<endl;
				return NULL;
			}
			else if(front == rare)
			{
				temp= front;
				front = NULL;
				rare = NULL;
				return temp;
			}
			else
			{
				temp= front;
				front = front->getNext();
				return temp->getNext();
			}
		}
		bool s_isempty()
		{
			if(sfront == NULL && srare == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void senque(Node *head)
		{
			Node* tmp = head;
		while(tmp != NULL)
		{
			if(s_isempty())
			{
				sfront=tmp;
				srare= tmp;
				cout<<"First Song added to queue successfully."<<endl;
			}
			else
			{
				srare->setNext(tmp);
				srare = tmp;
				cout<<"Song added to queue successfully."<<endl;	
			}
			tmp = tmp->getNext();
		}
		}
		Node *sdeque()
		{
			Node *temp= NULL;
			if(s_isempty())
			{
				cout<<"No songs in queue."<<endl;
				return NULL;
			}
			else if(sfront == srare)
			{
				temp= sfront;
				sfront = NULL;
				srare = NULL;
				return temp;
			}
			else
			{
				temp= sfront;
				sfront = sfront->getNext();
				return temp->getNext();
			}
		}

	
};
