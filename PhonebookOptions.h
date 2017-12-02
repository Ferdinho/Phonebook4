/*
 * PhonebookOptions.h
 *
 *  Created on: Oct 3, 2017
 *      Author: ferdinandtembo
 */

#ifndef PHONEBOOKOPTIONS_H_
#define PHONEBOOKOPTIONS_H_

#include <iostream>
#include "Contact.h"
using namespace std;

string getName();
int getNumber();
void readData(string filename);
int search(string name);
string * parseName(string name);
#endif /* PHONEBOOKOPTIONS_H_ */
