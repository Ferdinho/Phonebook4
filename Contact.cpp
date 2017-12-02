/*
 * Contact.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: ferdinandtembo
 */

#include "Contact.h"

Contact::Contact() {
	// TODO Auto-generated constructor stub
	firstname = "";
	lastname= "";
	phoneNumber = 0;

}

Contact::Contact(string firstname,string lastname, int number){
	this->firstname = firstname;
	this->lastname = lastname;
	this->phoneNumber = number;
}

Contact::Contact(string firstname,string lastname){
	this->firstname = firstname;
	this->lastname = lastname;
}

string Contact::getFirstName(){
	return firstname;
}

string Contact::getLastName(){
	return lastname;
}

int Contact::getNumber(){
	return phoneNumber;
}
Contact& Contact::operator =(const Contact &other){
	if(this != &other){
		firstname = other.firstname;
		lastname = other.lastname;
		phoneNumber = other.phoneNumber;
	}
	return *this;
}

void displayContactDetail(Contact contact){
	cout<<"Firstname: :"<<contact.firstname<<" Lastname: "<<contact.lastname<<" Phone: "<<contact.phoneNumber<<endl;;
}

Contact::~Contact() {
	// TODO Auto-generated destructor stub
}

bool Contact::operator > (const Contact &contact)
{
	if(firstname == contact.firstname){
		return lastname > contact.lastname;
	}
  return (firstname > contact.firstname);
}

bool Contact::operator < (const Contact &contact)
{
	if(firstname == contact.firstname){
			return lastname < contact.lastname;
	}
	return (firstname < contact.firstname);
}

bool Contact::operator == (const Contact &contact)
{
	return firstname == contact.firstname && lastname == contact.lastname;
}
