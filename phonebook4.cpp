//============================================================================
// Name        : PhoneBook.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/* This is a  Phonebook application program which can add a new contact load contacts from a file
 *  print the contacts in ascending order and search for a contact using Binary Search Tree.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "PhonebookOptions.h"
#include "Contact.h"
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree<Contact> BST;


int size =0;
Contact* contacts;



int main() {


	char answer = ' ';

	cout<< "***MY PHONEBOOK APPLICATION***\n"
			"Please choose an operation:";
	do{
		cout<<endl;
		cout<<"A(Add) | L(Load) | S(Search) | P(Print) |F(Filter) |Q(Quit): ";
		cin >> answer;
		answer = tolower(answer);

		switch(answer){
		case 'a': {string name = getName();
		string firstname = parseName(name)[0];
		string lastname = parseName(name)[1];
		int phone = getNumber();
		Contact newContact(firstname, lastname, phone);
		BST.insert(newContact);
		size +=1;;
		break;
		}

		case 'l': {
			string filename;
			cout<<"Enter file name:";
			cin >>filename;
			readData(filename);
			break;
		}

		case 'p':{
			BST.inOrder();

			break;
		}
		case 'f' :{
			int number_of_contacts = 0;
			string name = getName();
			string firstname = parseName(name)[0];
			string lastname = parseName(name)[1];
			Contact contact(firstname, lastname);
			number_of_contacts = BST.inOrder(contact);
			if(number_of_contacts == size){
				number_of_contacts = 0;
			}
			cout<<"Contacts..."<<number_of_contacts<<endl;
			break;
		}
		case 's':{
			int phonenumber = 0;
			string name = getName();
			string firstname = parseName(name)[0];
			string lastname = parseName(name)[1];
			Contact contact(firstname, lastname);
			clock_t begin = clock();
			Contact* contact1 = BST.searchTree(contact);
		//	clock_t end = clock();
		//	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			if(contact1 != NULL){
				cout<<"Number "<< (*contact1).getNumber() <<endl;
		//		cout<<"Time taken is "<<elapsed_secs<<endl;
			}
			else{
				cout<<"Contact not found"<<endl;
			}
			break;
		}
		default: break;

		}
	}while (answer!='q');

	cout<<"Thank you for using the software!"<< endl;

	return 0;
}


// This method divide name into firstname and lastname
string* parseName(string name){
	string namedetails[2];

	int blank = name.find(" ");
	string firstname = name.substr(0,blank);
	namedetails[0] = firstname;
	name = name.substr(blank+1);
	blank = name.find(" ");
	string lastname = name.substr(0,blank);
	namedetails[1] = lastname;
	return namedetails;

}

// This method just read correctly the data from the file and distinguish the firstname from the lastname while reading
void readData(string filename){

	ifstream infile;
	infile.open(filename);

	string s;
	while (getline(infile,s)){
		int blank = s.find(" ");
		string firstname = s.substr(0,blank);
		s = s.substr(blank+1);
		blank = s.find(" ");
		string lastname = s.substr(0,blank);
		s = s.substr(blank+1);
		int number = stoi(s);
		Contact contact(firstname, lastname, number);
		BST.insert(contact);
		size ++;
	}
}
// this method just ask the name and store it and return it
string getName(){
	string name = "";
	cout<<"Please enter a Name :"<<endl;
	cin.ignore();
	getline(cin,name);
	return name;
}

// this method just ask for numbers and store it , and return it
int getNumber(){
	int number;
	cout<<"Please enter your number :"<<endl;;
	cin>>number;
	return number;
}
