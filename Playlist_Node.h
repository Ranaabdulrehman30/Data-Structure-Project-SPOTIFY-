#include<iostream>
using namespace std;

class PNode
{
private:
	string pldata;
	string playlistname;
	string genre;
	PNode* next;

	
public:
	string getData()
	{
		return pldata;
	}
	
	void setData(string value)
	{
		this->pldata = value;
	}
	


	string getplaylistname()
	{
		return playlistname;
	}
	
	void setplaylistname(string value)
	{
		this->playlistname = value;
	}
	string getgenre()
	{
		return genre;
	}
	
	void setgenre(string value)
	{
		this->genre = value;
	}

	
	PNode *getNext()
	{
		return next;
	}
	
	PNode *setNext(PNode *nNode)
	{
		this->next = nNode;
	}
};
