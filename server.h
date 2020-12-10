
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include <cstdio>
#include<conio.h>
#include<stdio.h>

using namespace std;
using std::flush;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
int size_adujust;

namespace front
{
	void before() 
	{
		system("color 0d");
		cout << "\n\n\n\t\t\t\t\t\tPlease wait while loading\n\n";
		char a = 177, b = 219;
		string query;
		cout << "\t\t\t\t";
		for (int i = 0; i <= 50; i++)
			cout << a;
		cout << "\r";
		cout << "\t\t\t\t";
		for (int i = 0; i <= 50; i++)
		{
			cout << b;
			for (int j = 0; j <= 1e7; j++);
		}
		cout << "\n\n";
		system("CLS");
		cout << "\n\n\t\t\t\t\t";
		cout << char(197);

		for (int i = 0; i < 50; i++)
		{
			cout << char(205);
		}
		cout << char(197);
		cout << "\n\n\t\t\t\t\t\t\tEnter Your Query\n";
	}

	void slow_print(const string& message, int millis_per_char)
	{
		for (const char c : message)
		{
			cout << c << flush;
			sleep_for(milliseconds(millis_per_char));
		}
	}

	void after() 
	{

		cout << "\t\t\t\t\t";
		cout << char(197);

		for (int i = 0; i < 50; i++)
		{
			cout << char(205);
		}
		cout << char(197);


		string message = "\n\n\t\t\t\t\t0. Search with Trexa\n\t\t\t\t\t1. Are you new here? Sign up\n\t\t\t\t\t2. Already Have Account? Log in\n\t\t\t\t\t3. Log in as admin\n\n";
		slow_print(message, 50);


		cout << "\n\n\t\t\t\t\t";
		cout << char(197);

		for (int i = 0; i < 50; i++)
		{
			cout << char(205);
		}
		cout << char(197);
		cout << "\n\n\t\t\t\t\t\tWelcome to the Search Engine Applicaton\n\n";

		cout << "\t\t\t\t\t";
		cout << char(197);

		for (int i = 0; i < 50; i++) { cout << char(205); }
		cout << char(197);


	}

}
namespace data 
{
	void write_user_data(std::string filename , std::string data ) 
	{
		std::fstream write_file;
		write_file.open(filename + ".txt" , std::ios::app);
		if (!write_file.is_open())
		{
			std::cout << "\nConnection of file not Established\n....";
			return ;
		}
		write_file << data<<"\t\t";
	}

	void read_user(std::string filename)
	{
		std::ifstream read_file;
		read_file.open(filename + ".txt", std::ios::in);
		if (!read_file.is_open())
		{
			std::cout << "\nConnection of file not Established\n....";
			return;
		}
		std::string data;
		cout << "\n\t\t\t\t\t***************************************************\n";

		while (!read_file.eof())
		{
			getline(read_file, data);
			std::cout  << data<<"\n";
		}
		cout << "\n\t\t\t\t\t***************************************************\n";
	}

}
namespace create_file
{
	std::string ctr_file()
	{
		std::fstream file;
		std::string filename;
		cout << "Enter your File Name ....:";
		cin >> filename;
		file.open(filename + ".txt", std::ios::app);
		if (!file.is_open())
		{
			std::cout << "\nConnection of file not Established\n....";
			return filename;
		}
		else 
		{
			cout << "Your File is Created Successfully...:";
		}
		return filename;
		}

	void insert_onFile(std::string filename)
	{
		cout << "\n_____________________________\n";
		cout<<"\nEnter Data Wisely and Don't Worry about Management \n I will manage your data and present it in great way";
		cout << "\n_____________________________\n";
		
		cout << "\n_____________________________\n";
		cout << "\nPlease Write ---exist-- for ending the editing... ";
		cout << "\n_____________________________\n";
		string ch , get_;

		fstream file;
		file.open(filename + ".txt", std::ios::app);
		if (!file.is_open())
		{
			std::cout << "\nConnection of file not Established\n....";
		}
		std::string wtr_data;
	
		while (ch != "ext")
		{
			cin.ignore();
			getline(cin, wtr_data);
			file << wtr_data <<"\n";
			cout << "\nDo You want to exist Now press ---exist---\n";
			cin >> ch;
		}

		std::fstream file1;
		file1.open("all_doc_names.txt" , std::ios::app);
		if (!file1.is_open())
		{
			std::cout << "\nConnection of file not Established\n....";
		}
		else
		{
			while (!file.eof())
			{
				file1<<" "<< filename << " ";
				file1.close();
				break;
			}
		}
	}

	void save_data( std::string doc_name, int data_ , std::string filename)
	{
		std::fstream file1;
		file1.open(filename + ".txt", std::ios::app);
		if (!file1.is_open())
		{
			std::cout << "\nConnection of file not Established\n";
		}

		else
		{
			file1 <<"\n" << doc_name << " "  << data_ << " " ;
		}
	}

	void delete_filename(std::string filename)
	{
		string fielToDelete ,  fileOpt;
		std::fstream file1;
		file1.open(filename + ".txt", std::ios::in || std::ios::app );
		if (!file1.is_open())
		{
			std::cout << "\nConnection of file not Established\n";
		}
		cout << "Enter a file name which do you want to del...: ";
		cin >> fileOpt;
	
		while (!file1.eof())
		{
			file1 >> fielToDelete;
			if (fileOpt == fielToDelete)
			{
				if (remove(fileOpt.c_str()) != 0)
				{
					cout << "Remove operation failed" << endl;
				}
				else
				{
					cout << fileOpt << " has been removed." << endl;
				}
				break;
			}
		}
	}

	
}
namespace sort
{
	void swap(int* a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}

}
namespace _node
{


	// Create a node
	class Node
	{
	public:

		string item;
		Node* next;
	};



	void insertAfter(Node** root, string data)
	{
		Node* temp = new Node;
		Node* ptr;
		temp->item = data;
		temp->next = NULL;

		if (*root == NULL)
		{
			*root = temp;
		}
		else
		{
			ptr = *root;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = temp;
		}
	}



	void insertUpdatedNOde(Node** newroot, string data)
	{
		Node* newtemp = new Node;
		Node* newptr;
		newtemp->item = data;
		newtemp->next = NULL;

		if (*newroot == NULL)
		{
			*newroot = newtemp;
		}
		else
		{
			newptr = *newroot;
			while (newptr->next != NULL)
				newptr = newptr->next;
			newptr->next = newtemp;
		}
	}

	void printListAfter(Node* node , std::string filename)
	{
		fstream ff;
		ff.open(filename +".txt", ios::out);
		while (node != NULL)
		{
			cout << node->item << " ";
			ff << node->item << " ";
			node = node->next;
		}
		ff.close();
	}
	void printList(Node* node)
	{
		while (node != NULL)
		{
			cout << node->item << " ";
			node = node->next;
		}
	}
	Node* updateLinklist(Node* root, string check, string updatedstr)
	{
		Node* newnode = NULL;
		while (root != NULL)
		{
			if (root->item == check)
			{
				insertUpdatedNOde(&newnode, updatedstr);
				root = root->next;
			}

			insertUpdatedNOde(&newnode, root->item);
			root = root->next;
		}
		return newnode;
	}

	void initialize(std::string filename)
	{
		fstream file , file1;
		std::string word, data_extract, data_com;
		Node obj;
		Node* filenode = NULL;
		std::string fileOpt;
		file1.open(filename + ".txt", std::ios::in || std::ios::app);
		if (!file1.is_open())
		{
			std::cout << "\nConnection of file not Established\n";
		}
		cout << "Enter a file name which do you want to Update...: ";
		cin >> fileOpt;

		while (!file1.eof())
		{
			file1 >> data_extract;
			if (fileOpt == data_extract)
			{
				file.open(fileOpt + ".txt", ios::in);
				if (!file.is_open())
				{
					cout << "\nConnection Not Established....:\n";
				}

				while (!file.eof())
				{
					file >> word;
					insertAfter(&filenode, word);
				}
				int c;
				cout << endl;
				cout << "Do you want to update this linklist (1/0):\n";
				cin >> c;
				if (c == 1)
				{
					string str, sstr;
					cout << "Enter the word which you wantto update\n";
					cin >> str;
					cout << "Enter the word to replace with that word\n";
					cin >> sstr;
					Node* ptr = updateLinklist(filenode, str, sstr);
					printListAfter(ptr, fileOpt);
				}
			}
		}
	}
}


