/*
 * FitStudioReg.cpp 
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: Vivian
 * Last modified: Sept. 2022
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Member.h"
#include "List.h"

using std::cout;
using std::cin;

//prototypes
void add(List* Members);
void remove(List* Members);
void search(List* Members);
void modify(List* Members);
void print(List* Members);
bool checkPhone(string aPhone);

int main() {

    // Variables declaration
    List* Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << endl << "----Welcome to the Fitness Studio Registration System!" << endl;
        cout << endl << "Enter ..." << endl << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
		
		switch(input) {
            case 'a': add(Members); break;
            case 'r': remove(Members); break;
            case 's': search(Members); break;
            case 'm': modify(Members); break;
            case 'p': print(Members); break;
            case 'x': cout << "\n----Bye!\n" << endl; done = true; break; 
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    return 0;
}


//add function 
void add(List* Members) {
	//have to prompt user for details of member they want to enter and how
	string aName;                      
    string aPhone;
    string aEmail;
    string aCreditCard;
	
	cout << "You have selected to add a new member" << endl;
	cout << "Please enter a phone number with the format XXX-XXX-XXXX otherwise will default to 000-000-0000: ";
	cin >> aPhone;
	
	//check phone number if valid 
	if (not checkPhone(aPhone)) {// phone number inavlid -> construct with the default
		aPhone = "000-000-0000";
	}
	
	Member aMember = Member(aPhone);
	
	// search to see if its in the db already 
	if (Members->search(aMember) != NULL) {//found a match
		cout << "Sorry a member with this number already exists, or the number you have entered is invalid, please try again" << endl;
		return;
	} else {
		cout << "Please enter a name: ";
		cin >> aName;
		cout << "Please enter a email: ";
		cin >> aEmail;
		cout <<	"Please enter your credit card number: ";
		cin >> aCreditCard;
		//set the member with the 4 characteristic 
		aMember = Member(aName, aPhone, aEmail, aCreditCard);
		
		//now insert
		if (Members->insert(aMember)) {
			cout << "Member was successfully added" << endl;
		} else {
			cout << "Member was NOT successfully added, please try again" << endl;
		}
	}
	return; 
}


void remove(List* Members) { //test -> enter jiv, viv, jim,  delete jiv but since they are all under aMember what happens?
	
	bool notValid = true;
	string aPhone;
	cout << "You have selected to remove a member" << endl;
	//ensure number is valid
	do {
		cout << "Please provide the phone number of the member you would like to remove: \n";
		//need ot provide the name of the entity -> problem cause i named it as aMember above rip 
		cin >> aPhone;
		if (checkPhone(aPhone)) {
			notValid = false;
		}
	} while (notValid);
		
	Member aMember = Member(aPhone);
	
	if (Members->remove(aMember)) {
		cout << "member was successfully removed" << endl;
	} else {
		cout << "member was NOT successfully removed, please try again" << endl;
	}
	
	return; 
}

void search(List* Members) {
	string aPhone;
	cout << "Please enter the phone of the member you want to search for: " << endl;
	cin >> aPhone;
	
	//check phone number if valid 
	if (not checkPhone(aPhone)) {// phone number inavlid -> construct with the default
		cout << "Your phone will be set to the default phone (000-000-0000)" << endl;
		aPhone = "000-000-0000";
	}
	
	Member aMember = Member(aPhone);
	Member* ptr = Members->search(aMember);
	if (ptr != NULL) {
		cout << "Member has been found, and here are the details: " << endl;
		cout << "Name: " << ptr->getName() << ", phone: " << ptr->getPhone() << ", email: " << ptr->getEmail() << ", credit card: " << ptr->getCreditCard() << endl;
	} else {
		cout << "Member could not be found in the data base" << endl;
	}
	
	return;
}

void modify(List* Members) {
	string aPhone;
	char input = 0;
	bool done = false;
	
	cout << "Please enter the phone number of the member you would like modify: " << endl;
	cin >> aPhone;
	Member aMember = Member(aPhone);
	//make sure the member is already in the db
	Member* ptr = Members->search(aMember);
	if (ptr != NULL) {
		//cout << "The member is found data base" << endl;
		bool done = false;
		while (not done) {
			cout << "What would you like to modify?" << endl;
			cout << "n -> to modify name" << endl;
		    cout << "e -> to modify email" << endl;
		    cout << "c -> to modify credit card number" << endl;
		    cout << "x -> to exit\n" << endl;
		
			cout << "Your choice: ";
		    cin >> input;
		    cout << endl;
		    input = tolower(input);
			
			if (input == 'n') {
	        	string aName;
	        	cout << "Please enter a new name: " << endl;
	        	cin >> aName;
	        	ptr->setName(aName);
	        	cout << "Name was successfully updated" << endl;
	        	cout << "Here are the updated details: " << endl;
	        	cout << "Name: " << ptr->getName() << ", phone: " << ptr->getPhone() << ", email: " << ptr->getEmail() << ", credit card: " << ptr->getCreditCard() << endl;
	        	break;
	        } else if (input == 'e') {
	        	string anEmail;
	        	cout << "Please enter a new email: " << endl;
	        	cin >> anEmail;
	        	ptr->setEmail(anEmail);
	        	cout << "Email was successfully updated" << endl;
	        	cout << "Here are the updated details: " << endl;
	        	cout << "Name: " << ptr->getName() << ", phone: " << ptr->getPhone() << ", email: " << ptr->getEmail() << ", credit card: " << ptr->getCreditCard() << endl;
	        	break;
	        } else if (input == 'c') {
	        	string aCreditCard;
	        	cout << "Please enter a new credit card number: " << endl;
	        	cin >> aCreditCard;
	        	ptr->setCreditCard(aCreditCard);
	        	cout << "Credit card was successfully updated" << endl;
	        	cout << "Here are the updated details: " << endl;
	        	cout << "Name: " << ptr->getName() << ", phone: " << ptr->getPhone() << ", email: " << ptr->getEmail() << ", credit card: " << ptr->getCreditCard() << endl;
	        	break;
	        } else if (input == 'x') {
		        cout << "\n----Bye!\n" << endl; 
		        done = true; 
		        break; 
		    } else {
		    	cout << "Not sure what you mean! Please, try again!" << endl;
		    }
		}
	} else {
		cout << "The member is not in the data base" << endl;
	}
	return;
}



void print(List* Members) { //print works fine, you need to add multiple members first
	cout << "Here are the list of members in descending phone number order: " << endl;
	Members->printList();
	return;
}

//helper function
bool checkPhone(string aPhone) {
	if ((aPhone.length() == 12) && (isdigit(aPhone[0])) && (isdigit(aPhone[1])) && (isdigit(aPhone[2])) && (aPhone[3] == 45) && (isdigit(aPhone[4])) && (isdigit(aPhone[5])) && (isdigit(aPhone[6])) && (aPhone[7] == 45) && (isdigit(aPhone[8])) && (isdigit(aPhone[9])) && (isdigit(aPhone[10])) && (isdigit(aPhone[11])))
		return true;
	else return false;
} 




