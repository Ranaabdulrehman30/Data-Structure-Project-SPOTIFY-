using namespace std;
#include<iostream>


class Anode
{
private:
	string albumname;
	Anode* next;
	//////////////////////////
  	Anode * left;
  	Anode * right;
	
public:
	string getalbumname()
	{
		return albumname;
	}
	
	void setalbumname(string value)
	{
		this->albumname = value;
	}	
	Anode *getNext()
	{
		return next;
	}
	
	Anode *setNext(Anode *nNode)
	{
		this->next = nNode;
	}
	////////////////////////////////////////////////////////////////////////////////
  	// CONSTRUCTOR WITHOUT PARAMETRE
  	Anode()
	{
    	albumname = " ";
    	left = NULL;
    	right = NULL;
  	}	
  		
  	Anode * getLeft()
  	{
  		return left;
  	}
  	Anode * getRight()
  	{
  		return right;
  	}
  	void setLeft(Anode*l)
  	{
  		left=l;
  	}
  	void setRight(Anode*r)
  	{
  		right=r;
  	}
  // CONSTRUCTOR WITH PARAMETRE
  	Anode(string albumname)
	{
    	this -> albumname = albumname;
    	this->left = NULL;
    	this->right = NULL;
  	}
};
