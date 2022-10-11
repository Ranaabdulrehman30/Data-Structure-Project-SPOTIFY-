using namespace std;

#include<iostream>
#include"Node.h"
#define SPACE 10


class Album : public Anode
{
private:
	Anode* head;
	
public:
	Anode * getHead()
    {
  		return head;
  	}
  	void setHead(Anode*h)
  	{
  		head=h;
  	}
	Song()
	{
		head = NULL;
	}
	bool isTreeEmpty()
		{
    		if (getHead() == NULL)
			 {
      			return true;
    		 }
		 
			else
			{
      			return false;
    		}
  		}
	
  	void insertNode(string name)
	{
  	
  		Anode* temp=new Anode();
  		temp->setalbumname(name) ;
  	
    	if (getHead()== NULL)
		{
      		setHead(temp);
      		cout << "Album Inserted as head node!" << endl;
    	}
		else
		{	
        	Anode * temp1= getHead();
      	while (temp1!= NULL)
		{
        	if (temp -> getalbumname() == temp1-> getalbumname())
				{
        			cout << "Album Already exist," <<
        			"Insert another Album!" << endl;
          			return;
        		}
			else if ((temp -> getalbumname() < temp1-> getalbumname()) && (temp1-> getLeft() == NULL))
				{
        			temp1-> setLeft(temp) ;
        			cout << "Album Inserted to the left!" << endl;
        			break;
        		}
			else if (temp -> getalbumname() < temp1-> getalbumname())
				{
						// traverses to the left child
        			temp1= temp1-> getLeft();
        		}
			else if ((temp -> getalbumname() > temp1-> getalbumname()) && (temp1-> getRight() == NULL)) 
				{
        			temp1-> setRight(temp) ;
        			cout << "Album Inserted to the right!" << endl;
        			break; 
        		}
			else 
				{
					// traverses to right child
        			temp1= temp1-> getRight();
        		}
      		}
    	}
	}
	
Anode * traverse(string v) 
   		{
    		if (getHead() == NULL) 
			{
      			return getHead();
    		}	 
			else 
			{
      			Anode * temp = getHead();
      			while (temp != NULL) 
				{
        			if (v == temp ->getalbumname())
					{
          				return temp;
        			}
					else if (v < temp -> getalbumname()) 
					{
          				temp = temp -> getLeft();
        			} 
					else 
					{
          				temp = temp -> getRight();
        			}
      			}
      			return NULL;
    		}
  		}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
    	Anode * deleteNode(Anode * r, string v)
		{
    		 
    		Anode*l;
    		Anode*x;

    
    		if (r == NULL) 
			{
      			return NULL;
    		}
    			// If the data to be deleted is smaller than the head's data, then it lies in left subtree
    		else if (v < r->getalbumname() )
			{
      			l= deleteNode(r -> getLeft(), v);
      			r -> setLeft(l) ;
	  
    		}
    			// If the data to be deleted is greater than the head's data, then it lies in right subtree 
    			
    		else if (v > r -> getalbumname()) 
			{
      			x= deleteNode(r -> getRight(), v);
      			r -> setRight(x); 
	  
    		}
    		 
    		else 
			{
      		// node with only one child or no child 
      			if (r -> getLeft() == NULL) 
				{	
        			Anode * temp = r -> getRight();
        			delete r;
        			return temp;
      			} 
				else if  (r -> getRight() == NULL) 
				{
        			Anode * temp = r -> getLeft();
        			delete r;
        			return temp;
      			} 
				else 
				{
					Anode *temp;
					cout<<"every child node of this parent node will be deleted as it is a parent node that is been deleted";
					delete r;
					return temp;
      			}
        	}
    			return r;
   		}
	
};
class Tree : public Album
{
	public:
		
  	void print2D(Anode * r, int space) 
	{
    	if (r == NULL)
      	return;
    	space += SPACE; 
    	print2D(r -> getRight(), space);  
    	cout << endl;
    	for (int i = SPACE; i < space; i++) 
      	cout << " "; 
    	cout << r -> getalbumname() << "\n"; 
    	print2D(r -> getLeft(), space);
  	}

  	int height(Anode * r) 
	{
    	if (r == NULL){
    		return -1;
		}
      	else 
		{
      			/* compute the height of each subtree */
			int lheight = height(r -> getLeft());
      		int rheight = height(r -> getRight());

      			/* use the larger one */
      		if (lheight > rheight)
        	return (lheight + 1);
      		else 
			return (rheight + 1);
    	}
  	}
  		
  	void printGivenLevel(Anode * r, int level) 
	{
    	if (r == NULL)
     	return;
    	else if (level == 0)
    	{
      		cout << r -> getalbumname() << "->"; 
      	}
    	else // level > 0  
    	{
    			//cout<<"\t\t\t";
    		printGivenLevel(r -> getLeft(), level - 1);
    			
      		printGivenLevel(r -> getRight(), level - 1);
      			
      	}
  	}
  		
  	void printLevelOrderBFS(Anode * r) 
	{
    	int h = height(r);
    	for (int i = 0; i <= h; i++)
      	printGivenLevel(r, i);
      	cout << "NULL" << endl;
  	}
};

