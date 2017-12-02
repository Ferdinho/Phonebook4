/*
 * Contact.h
 *
 *  Created on: Oct 4, 2017
 *      Author: ferdinandtembo
 */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
using namespace std;


class Contact {
private:
	string firstname;
	string lastname;
	int phoneNumber;
public:
	Contact();
	Contact(string firstname, string lastname , int number);
	Contact(string firstname, string lastname);
	Contact(const Contact& other){
			firstname = other.firstname;
			lastname = other.lastname;
			phoneNumber = other.phoneNumber;
		}
	void setPhoneNumber(int number);
	string getFirstName();
	string getLastName();
	int getNumber();
	friend void displayContactDetail(Contact contact);
    Contact& operator=(const Contact &other);
    friend ostream& operator<<(ostream &out, const Contact & contact){
        			out<<contact.firstname<<" "<<contact.lastname<<" "<<contact.phoneNumber<<endl;
        				return out;
        		}
	virtual ~Contact();

    bool operator < (const Contact &contact);
    bool operator > (const Contact &contact);
    bool operator == (const Contact &contact);

};


#endif /* CONTACT_H_ */
