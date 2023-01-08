/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#include <iostream>
#include <string>
#include <vector>

#include "Customer.h"
#include "Film.h"

Customer::Customer(string name, int age, float balance) {
	this->name = name;
	this->age = age;
	this->limit = 5;
	
	//Controlling age limits.
	if (this->age < 13) {
		
		if (balance > 100) {
			this->balance = 100;
		} else {
			this->balance = balance;
		}
	} else {
		this->balance = balance;
	}
}

void Customer::toString() {
	cout << "Name: " << this->name << "\nAge: " << this->age << "\nBalance: " << this->balance;
}

int Customer::getAge() {
	return this->age;
}

void Customer::setAge(int t_age) {
	this->age = t_age;
}

float Customer::getBalance() {
	return this->balance;
}

int Customer::getLimit() {
	return this->limit;
}

void Customer::setLimit(int t_limit) {
	this->limit = t_limit;
}

void Customer::setBalance(float t_balance) {
	this->balance = t_balance;
}

string Customer::getName() {
	return this->name;
}

void Customer::setName(string t_name) {
	this->name = t_name;
}

//Getting customer's film list.
void Customer::getFilmList() {
	
	int i;
	
	for (i = 0; i < this->film_list.size(); i++) {
		this->film_list[i].toString();
	}
}

//Adding films into customer's film list.
void Customer::addFilmList(Film &f) {

	if (this->limit > 0) {
		this->film_list.push_back(f);
		limit--;
	} else {
		cout << "\nExceeded rent limit";	
	}
}

//Removing films into customer's film list.
void Customer::removeFilmList(Film &f) {
	
	int counter = 0;
	
	int i;
	
	for(i = 0; i < this->film_list.size(); i++){
		
		if(f.getName() == this->film_list[i].getName()) {
         this->oldfilm_list.push_back(f);
		 this->film_list.erase(this->film_list.begin() + i);
		 counter++;
		 break;
		}
		
	}
	
	if (counter == 0) {
		cout << this->getName() << " doesn't have " << f.getName() << " in his list";
	}
}

//Adding films into customer's old film list.
void Customer::oldFilmList() {
	
	int i;
	
	for (i = 0; i < this->oldfilm_list.size(); i++) {
		this->oldfilm_list[i].toString();
	}
	
}

//Getting customer's film list's film amount.
int Customer::listCounter(Film &f) {
	
	int i;
	
	int counter = 0;
	
	for (i = 0; i < this->film_list.size(); i++) {
		
		if (this->film_list[i].getName() == f.getName()) {
			counter++;
		}
	}
	
	return counter;
}
