
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<math.h>
#include <windows.h>
#include <thread>
#include <chrono>

//***********libray files........

#include"server.h"

using namespace std;
int doc_index = 0 , display_index = 0 ;
int check = 0;
int Arraydoc_freq[4];
string Arraydoc_name[4];
string* arr = new string[10];
int no_words = 1 , *take_addr;

class signup
{
public:
	void sign_up(string a, string b)
	{
		fstream file;
		file.open("signup.txt", ios::app);
		file << "\n" << a << "\t" << b;
		file.close();
	}
};

class login
{
public:
	string username_login;
	string pass_login;
	void set_username(string a)
	{
		username_login = a;
	}
	void set_pass(string b)
	{
		pass_login = b;
	}

	bool check_login()
	{
		fstream f;
		bool check = 0;
		string user, pass;
		f.open("signup.txt", ios::in);
		while (!f.eof()) 
		{
			f >> user >> pass;
			if (username_login == user && pass_login == pass)
			{
				return 1;
				check = 1;
			}
		}
		if (check == 0)
		{
		std:cout << "Password Or Username is Wrong\n";
			return 0;
		}
	}
};

class admin
{
public:
	string username_login  , pass_login;
	void set_username(string a)
	{
		username_login = a;
	}
	void set_pass(string b)
	{
		pass_login = b;
	}

	bool check_login()
	{
		if (username_login == "Husnain" && pass_login == "1111")
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

class newnode
{
public:
	int data;
	string file_name;
	newnode* next;
	newnode* root = NULL;
	newnode* head = NULL ;

	void insert_frequencylist(newnode** file_root, string item, int d)
	{
		newnode* temp = new newnode;
		newnode* ptr1;
		head = *file_root;
		temp->data = d;
		temp->file_name = item;
		temp->next = NULL;
		if (*file_root == NULL)
		{
			*file_root = temp;
		}

		else
		{
			ptr1 = *file_root;
			while (ptr1->next != NULL)
			{
				ptr1 = ptr1->next;
			}				
			ptr1->next = temp;
		}
	}

	newnode* file_linklist()
	{
		string word;
		int dat;
		for (int i = 0; i < 4; i++)
		{
			word = Arraydoc_name[i];
			dat = Arraydoc_freq[i];
			insert_frequencylist(&root, word, dat);
		}
		return root;
	}
	 

	void insertAtBeginning(newnode** head, int dataToBeInserted, std::string filename)
	{
		newnode* curr = new newnode;
		curr->data = dataToBeInserted;
		curr->file_name = filename;
		curr->next = NULL;

		if (*head == NULL)
		{    
			*head = curr;
		}
		else
		{
			curr->next = *head;
			*head = curr;
		}
	}

	void display(newnode **head_node)
	{
		newnode* temp = *head_node;
		while (temp != NULL)
		{
			if (temp->next != NULL)
			{
				Arraydoc_freq[display_index] = temp->data;
				Arraydoc_name[display_index] = temp->file_name;
				display_index++;
			}
			else
			{
				Arraydoc_name[display_index] = temp->file_name;
				Arraydoc_freq[display_index] = temp->data;
				display_index++;
			}
			temp = temp->next;
		}
		cout << endl;
	}


	void display_final_result()
	{
		int in;
		for (int i = 3; i >= 0; i--)
		{
				cout << "\n\t\t\t**************************\n";
				cout << "Highest Priority Result ....:" << Arraydoc_freq[i] << "\n";
				cout << "Highest Priority Result ....:" << Arraydoc_name[i]<<"\n";
				cout << "\n\t\t\t**************************\n";
		}
		cout << "\nWhich Document Do you want to open....:";
		cout << "\nPress 1 for =====1st Doc=====\n";
		cout << "Press 2 for =====2nd Doc=====\n";
		cout << "Press 3 for =====3rd Doc=====\n";
		cout << "Press 4 for =====4rth Doc=====\n";
		cout << "Press 5 for =====ALL Documents=====\n";
		cin >> in;
		switch (in)
		{
		case 1:
			data::read_user(Arraydoc_name[3]);
			break;
		case 2:
			data::read_user(Arraydoc_name[2]);
			break;
		case 3:
			data::read_user(Arraydoc_name[1]);
			break;
		case 4:
			data::read_user(Arraydoc_name[0]);
			break;
		case 5:
			for(int i = 3 ; i >= 0 ; i--)
				data::read_user(Arraydoc_name[i]);
			break;
		default:
			cout << "Invalid Input...:";
			break;
		}

	}

	newnode* getTail(newnode* cur)
	{
		while (cur != NULL && cur->next != NULL)
		{
			cur = cur->next;
		}
		return cur;
	}

	newnode* partition(newnode* head, newnode* end, newnode** newHead, newnode** newEnd)
	{
		newnode* pivot = end;
		newnode* prev = NULL, * cur = head, * tail = pivot;

		while (cur != pivot)
		{
			if (cur->data < pivot->data)
			{
				if ((*newHead) == NULL)
					(*newHead) = cur;

				prev = cur;
				cur = cur->next;
			}
			else
			{
				if (prev)
					prev->next = cur->next;

				newnode* tmp = cur->next;
				cur->next = NULL;
				tail->next = cur;
				tail = cur;
				cur = tmp;
			}
		}

		if ((*newHead) == NULL)
			(*newHead) = pivot;

		(*newEnd) = tail;

		return pivot;
	}

	newnode* quickSortRecur(newnode* head, newnode* end)
	{
		if (!head || head == end)
			return head;

		newnode* newHead = NULL, * newEnd = NULL;
		newnode* pivot = partition(head, end, &newHead, &newEnd);

		if (newHead != pivot)
		{
			newnode* tmp = newHead;

			while (tmp->next != pivot)
			{
				tmp = tmp->next;
			}	
			tmp->next = NULL;

			newHead = quickSortRecur(newHead, tmp);

			tmp = getTail(newHead);
			tmp->next = pivot;
		}

		pivot->next = quickSortRecur(pivot->next, newEnd);

		return newHead;
	}

	newnode* quickSort(newnode** headRef)
	{
		(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
		return *headRef;
	}
};

class Operating_Node
{
public:
	string data;
	Operating_Node* next;


	void insert_sear(Operating_Node** file_root, string item)
	{
		Operating_Node* temp = new Operating_Node;
		Operating_Node* ptr1;
		temp->data = item;
		temp->next = NULL;

		if (*file_root == NULL)
		{
			*file_root = temp;
		}
		else
		{
			ptr1 = *file_root;
			while (ptr1->next != NULL)
			{
				ptr1 = ptr1->next;
			}
			ptr1->next = temp;
		}
	}


	int search_query(Operating_Node* root, int k, string arr[], string doc_name)
	{
		int doc_number;
		string exten = ".txt";
		int frequencey = 0;
		Operating_Node* newptr = root;
		for (int i = 0; i < k; i++)
		{
			root = newptr;
			while (root != NULL) 
			{
				fstream file;
				file.open((doc_name + exten).c_str(), ios::in);
				if (arr[i] == root->data)
				{
					frequencey = frequencey + 1;
				}
				root = root->next;
			}
		}
		return frequencey;
	}

	//Extract data from file and insert it into the linked list

	Operating_Node* file_linklist(string doc)
	{
		string word;
		string exten = ".txt";
		fstream linklist_file;
		linklist_file.open((doc + exten).c_str(), ios::in);
		Operating_Node* root = NULL;

		while (!linklist_file.eof())
		{
			linklist_file >> word;
			insert_sear(&root, word);
		}
		linklist_file.close();
		return root;
	}
};

class history
{
public:
	void show_history(string str)
	{
		fstream f;
		string user;
		string his;
		f.open("history.txt", ios::in);
		cout << "-----------------------------HISTORY-----------------------------\n";
		while (!f.eof())
		{
			f >> user >> his;
			if (user == str)
			{
				cout << "-----------------------------HISTORY-----------------------------\n";
				std::cout << his << std::endl;
				cout << "-----------------------------HISTORY-----------------------------\n";
			}
		}
	}
};

void removeDupWord(string str, Operating_Node* root, string currentDoc)
{
	//	newnode forFrequency;
	Operating_Node newobj;
	int doc_frequency;
	newnode* p;

	if (check == 0) 
	{
		newnode* root1 = NULL;
		fstream fileHistory;
		int index = 0;
		string hash = "_";
		string newword;
		string word = "";
		for (auto x : str)
		{
			if (x == ' ')
			{
				no_words = no_words + 1;
				arr[index] = word;
				fileHistory.open("history.txt", ios::app);
				newword = word + hash;
				fileHistory << newword;
				fileHistory.close();
				word = "";
				index = index + 1;
			}
			else
			{
				word = word + x;
			}
		}
	
		arr[index] = word;
		fileHistory.open("history.txt", ios::app);
		newword = word;
		fileHistory << newword;
		fileHistory.close();
		doc_frequency = newobj.search_query(root, no_words, arr, currentDoc);
		Arraydoc_freq[doc_index] = doc_frequency;
		Arraydoc_name[doc_index] = currentDoc;
		doc_index = doc_index + 1;
		check = 1;
	}
	else
	{
		//newobj.search_query(root, no_words, arr, currentDoc);
		doc_frequency = newobj.search_query(root, no_words, arr, currentDoc);
		Arraydoc_freq[doc_index] = doc_frequency;
		Arraydoc_name[doc_index] = currentDoc;
		doc_index = doc_index + 1;
	
	}

}

int main()
{
	front::before();
	front::after();
	Operating_Node obj2 , obj3;
	newnode n , fre;
	string* ptr = NULL;
	fstream file;
	ofstream fileNew;


	signup obj;
	login login;
	admin admin;
	string username, pass;
	string search;
	int in;
	string currentDoc;
	int count1 = 0;
	string str;
	newnode* new_n_root , * new_n_root_1;
	newnode* new_n_roo , * roo_1;
	string str_2;
	int again = 0;
	do
	{
		std::cout << "\t\t\t\t\t Enter Your Choice: ";
		std::cin >> in;
	
		switch (in)
		{
		case 0:
			cout << "Search With Trexa: ";
		
			cin.ignore();
			getline(cin, str);
			file.open("all_doc_names.txt", ios::in);
			if (!file.is_open())
			{
				cout << "\nSomethong Went Wrong\n";
			}
			else
			{
				while (!file.eof())
				{
					file >> currentDoc;
					Operating_Node* otpr_root = obj2.file_linklist(currentDoc);
					removeDupWord(str, otpr_root, currentDoc);
				}
			}

			new_n_root = n.file_linklist();
			new_n_roo = n.quickSort(&new_n_root);
			n.display(&new_n_roo);
			front::before();
			n.display_final_result();
			front::after();
			break;
		case 1:
			std::cout << "Enter Your Username: ";
			std::cin >> username;
			std::cout << "Enter Your Password: ";
			std::cin >> pass;
			obj.sign_up(username , pass);
			break;

		case 2:
			std::cout << "Enter Your Username: ";
			std::cin >> username;
			std::cout << "Enter Your Password: ";
			std::cin >> pass;
			login.set_username(username);
			login.set_pass(pass);
			if (login.check_login() == 1)
			{
				system("CLS");
				int a;
				std::cout << "1. For Browsing/Searching\n";
				std::cout << "2. For History\n";
				std::cout << "Your Choice: ";
				std::cin >> a;
				if (a == 1) 
				{
					std::cout << endl;
					std::cout << "--------------------------Search With Trexa: ";
		
					cin.ignore();
					getline(cin, str_2);
					file.open("history.txt", ios::app);
					if (!file.is_open())
					{
						cout << "Connection not established..:";
					}
					file << "\n" << username << "\t";
					file.close();
					int DocArray[4];
					ifstream file_doc;
					string currentDoc_1;
					file_doc.open("all_doc_names.txt", ios::in);
					if (!file_doc.is_open())
					{
						cout << "Somethong Went Wrong\n";
					}
					else
					{
						while (!file_doc.eof())
						{
							file_doc >> currentDoc_1;
							Operating_Node* root_ = obj3.file_linklist(currentDoc_1);
							removeDupWord(str_2, root_, currentDoc_1);
						}
					}
			
					new_n_root_1 = fre.file_linklist();
					roo_1 = fre.quickSort(&new_n_root_1);
					fre.display(&roo_1);
					front::before();
					fre.display_final_result();
				}
				if (a == 2)
				{
					history historyobj;
					historyobj.show_history(username);
				}
				else
					cout << "Invalid Input\n";
			}
			break;

		case 3:
			system("CLS");
			std::cout << "Enter Your Username: ";
			std::cin >> username;
			std::cout << "Enter Your Password: ";
			std::cin >> pass;
			admin.set_username(username);
			admin.set_pass(pass);
			if (admin.check_login() == 1)
			{
				std::string get_, name_file, prefile;
				int DocArray[10];
				cout << "\nWelcome and Create More Files to Make yours Seach Engine Attractive...:\n";
				cout << "\nDo you want to create File....: Press 1 and 0 if not....:\n";
				cout << "\nDo you want to Delete File....: Press 2 and 0 if not....:\n";
				cin >> in;
				if (in == 1)
				{
					name_file = create_file::ctr_file();
					create_file::insert_onFile(name_file);
					in = 1;
				}
				if (in == 2)
				{
					cout << "Enter Your filename in which files are contain....:";
					cin >> name_file;
					create_file::delete_filename(name_file);
				}
				if (in == 3)
				{
					cout << "Enter Your filename in which files are contain....:";
					cin >> name_file;
					_node::initialize(name_file);
				}

				fstream file;
				file.open("admin.txt", ios::in || ios::app);
				if (!file.is_open())
				{
					cout << "...Somethong Went Wrong\n";
				}
				else if (in == 1)
				{
					file << name_file << " ";
				}
				else if (file.is_open())
				{
					cout << "\nEnter yours Previuos File Name that you want to Open....:\n";
					cin.ignore();
					getline(cin, prefile);
					while (!file.eof())
					{
						file >> get_;
						if (prefile == get_)
						{
							cout << "Your Opening DOC Name is ....:" << get_;
							create_file::insert_onFile(prefile);
						}
					}
				}
				else
				{
					create_file::insert_onFile(name_file);
				}
				std::cout << "\n***********Welcome Admin**************\n";
			}
			break;
		}
		cout << "\nPress 1 for more searching...: or 0 if not...:";
		cin >> again;
		if (again == 0)
		{
			break;
		}
	} while (again == 1);
}
