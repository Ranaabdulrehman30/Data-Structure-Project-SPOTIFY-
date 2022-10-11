#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Queue.h"
#include "Album.h"


using namespace std;

int main()
{
	List s;
	Album a;
	LL l[20];
	queue  q;
	string data;
	string albumname;
	Tree t;
	string name;
	string input;
	string data2;
	int input1;
	int listnum = 1;
	int listnum2 =1 , listnum3;
	char choice;
 	int option;
 	do{
 		cout<<" \n\n|||||||||||||||||||||||||||||    S  P  O  T  I  F  Y     |||||||||||||||||||||||||||||";
 		cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit.\n\n" << endl;
		cout<<"1. Add song()\n"<<endl;
		cout<<"2. Delete song()\n"<<endl;
		cout<<"3. Forward Display()\n"<<endl;
		cout<<"4. Backward Display()\n"<<endl;
		cout<<"5. Search for a Specific Song()\n"<<endl;
		cout<<"6. Add songS to the Queue()\n"<<endl;
		cout<<"7. NOW PLAYING.\n"<<endl;
		cout<<"8. Add Album()\n"<<endl;
		cout<<"9. Show Album()\n"<<endl;
		cout<<"10. Delete Album()\n "<<endl;
    	cout<<"11. Playlist Menu()\n"<<endl;
 		cin >> option;
 		cin.ignore();
 		system("CLS");
 	Anode * new_node = new Anode();
 	PNode * new_node1 = new PNode();
 	Node * new_node2 = new Node();
 	
 		
 	switch (option) {
    case 0:
      break;
    case 1:
    	cout<<"Enter Name of the song: ";
    	getline(cin, input);
    	s.add(input);
    	break;
    case 2:
    	cout<<"Enter the number of the song you want to delete : ";
    	cin>>input1;
    	cin.ignore();
    	s.delAtNum(input1);
    	break;
    case 3:
    	cout<<" FORWARD SONG LIST IS : "<<endl;
    	s.display();
    	break;
    case 4:
    	cout<<" BACKWARD SONG LIST :"<<endl;
    	s.reverse();
    	
    	break;
    case 5:
    	cout<<"Enter the name of the song you want to search :";
    	getline(cin, input);
    	s.search(input);
    	break;
    case 6:
    	q.senque(s.returnhead());
    	break;
    case 7:
		new_node2 = q.sdeque();
   		cout<<"Now PLaying : "<<new_node2->getData() <<endl;
   		delete new_node2;
		cout<<endl;
		break;
	case 8:
	    cout << "Enter the name of the Album." << endl;
        getline(cin, albumname);
        a.insertNode(albumname);
        
		break;
	case 9:
		cout << "/n/nYour Song list."<< endl;
        cout << " \t\t\t\t\t\tPRINT 2D: " << endl;
        t.print2D(a.getHead(), 5);
      
        cout<<endl;
	    cout<<endl;	
        cout << " \t\t\t\t\t\tPrint Level Order BFS: \n";
        cout<<"\t\t\t\t\t\t";
        t.printLevelOrderBFS(a.getHead());
        cout << endl;
        system("pause");
		break;
	case 10:
        cout<<"Enter the Number of the Album you want to delete."<<endl;
      	cin >> name;
     	new_node = a.traverse(name);
      	if (new_node != NULL) {
      	a.deleteNode(a.getHead(), name);
        cout<<endl;
        cout<<endl;
        system("pause");
        cout << "\t\t\t\tAlbum Removed" << endl;
      } else {
      	cout<<endl;
      	cout<<endl;
        cout << "\t\t\t\tAlbum not found" << endl;
        system("pause");
      }
		break;
    case 11:
    	do{
    		cout<<"\n\n\n||||||||||||||||||||||||       WELCOME TO THE PLAYLIST MENU           |||||||||||||||||||||||\n\n";
    		cout<<"1. Open Playlist.\n"<<endl;
    		cout<<"2. Create Playlist\n"<<endl;
    		cout<<"3. Enter Song to the playlist.\n"<<endl;
    		cout<<"4. Show Playlist.\n"<<endl;
    		cout<<"5. Add Playlist to queue\n"<<endl;
    		cout<<"6. Now Plaing()\n"<<endl;
    		cout<<"7. Merge & sort two Playlists()\n"<<endl;
    		cout<<"8. Recently PLayed Playlist()\n"<<endl;
    		cin>>option;
    		cin.ignore();
    		switch(option)
    		{
    			case 1:
    				break;
    			case 2:
    				cout<<endl;
    				cout<<"Enter the name of the playlist."<<endl;
    				getline(cin, data);
    				l[listnum].add(data);
    				listnum++;
    				break;
    			case 3:
    				cout<<"Enter the number of list to which you want to add data. ";
    				cin>>listnum2;
    				cin.ignore();
    				while(true){
    				cout<<"Enter the name of the song.    Press 0 to Exist"<<endl;
    				getline(cin, data);
    				cout<<"Do you want to Enter more songs?"<<endl;
    				cin>>choice;
    				cin.ignore();
    				if((choice == 'n'|| choice =='N')){
    					break;
					}
    				l[listnum2].add(data);
    				}
    				
    				break;
    			case 4:
    				cout<<"\r";
    				for(int i = 1; i<listnum; i++)
					{
					cout<<"\r" <<i<<": \r"<<l[i].gethead()<<"\n";
					}
    				cout<<"Enter the number of playlist you want to see."<<endl;
    				cin>>listnum3;
    				cin.ignore();
    				l[listnum3].display();
    				break;
    			case 5:
      				cout<<"Enter the number of playlist you want to add to queue."<<endl;
    				cin>>listnum3;
    				cin.ignore();
    				q.enque(l[listnum3].returnhead());
     			
     				break;
     			case 6:
     				new_node1 = q.deque();
     				cout<<"Now PLaying : "<<new_node1->getData() <<endl;
     				delete new_node1;
					cout<<endl;
					break;
				case 7:
					int x, y;
					cout<<"Enter the number of the number of first playlist.";
					cin>>x;
					cin.ignore();
					cout<<"Enter the number of the number of second playlist.";
					cin>>y;
					cin.ignore();
					l[x].SortedMerge(l[x].returnhead(), l[y].returnhead());
					l[x].display();
					break;
				case 8:
					l[listnum3].recentlyplayedlist(l[listnum3].returnhead());
					break;

     				
     				
    				
			}
		}while(option != 0);
    	
	}
	}while (option != 0);
	return 0;	

}

