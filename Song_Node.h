#include<iostream>
using namespace std;

#include <iostream>
#include <cstring>
#include <limits>
#include <fstream>

using namespace std;

class Node
{
private:
	string data;
	Node* next;
	
public:
	
	
	string getData()
	{
		return data;
	}
	
	void setData(string value)
	{
		this->data = value;
	}
	
	Node *getNext()
	{
		return next;
	}
	
	Node *setNext(Node* nNode)
	{
		this->next = nNode;
	}
};
