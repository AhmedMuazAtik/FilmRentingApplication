/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#include <iostream>
#include <string>

#include "Film.h"
#include "Store.h"
#include "Customer.h"
#include "Type.h"

Store::Store(string name, float balance) {
	this->name = name;
	this->balance = balance;
	this->income = 0;
}

void Store::toString() {
	cout << "Name: " << this->name << "\nBalance: ";
}

string Store::getName() {
	return this->name;
}

float Store::getBalance() {
	return this->balance;
}

void Store::setName(string t_name) {
	this->name = t_name;
}

void Store::setBalance(float t_balance) {
	this->balance = t_balance;
}

//Adding films into store's film list.
void Store::addFilm(Film &f) {
	
	int counter = 0;
	
	int i;
	
	for (i = 0; i < this->film_list.size(); i++) {
		
		if (this->film_list[i].getName() == f.getName()) {
			this->film_list[i].setStock(this->film_list[i].getStock() + f.getStock());
			counter++;
			break;
		}
	}
	
	if (counter == 0) {
		this->film_list.push_back(f);
	}
	
	cout << f.getName() << " has been added to the store";
}

//Adding stock into store's film list.
void Store::addStock(Film &f) {
	
	int i;
	
	for (i = 0; i < this->film_list.size(); i++) {
		
		if (this->film_list[i].getName() == f.getName()) {
//			this->film_list[i].setStock(this->film_list[i].getStock + 1);
			break;	
		} 
	}
}

//Deleting films from store's film list.
void Store::deleteFilm(Film &f) {
	
	int counter = 0;
	
	int i;
	
	for(i = 0; i < this->film_list.size(); i++) {
		
		//If f exists in store's film list.
		if(f.getName() == this->film_list[i].getName()) {
		 this->film_list.erase(this->film_list.begin() + i);
		 cout << f.getName() << " has been removed from the " << this->getName();
		 counter++;
		 break;
		}
		
	}
	
	if (counter == 0) {
		cout << f.getName() << " doesn't exist in " << this->getName();
	}
}

//Updating films from store's film list.
void Store::updateFilm(Film &f1, string name, string date, int age_limit, float price, int stock, Type type) {

	f1.setName(name);
	f1.setDate(date);
	f1.setAge(age_limit);
	f1.setPrice(price);
	f1.setStock(stock);
	f1.setType(type);
	
}

//Returning films that customer bought.
void Store::returnFilm(Film &f, Customer &c) {
	
	int counter = 0;
	
	int i;
	
	counter = c.listCounter(f);
	
	//If there exists 'f' film in customer's film list.
	if (counter > 0) {
		
		//Removing film from customer's film list.
		cout << f.getName() << " film removed from " << c.getName() << "'s list\n";
		c.removeFilmList(f);
		
		//Returning balance to the customer.
		cout << c.getName() << "'s balance returned back: ";
		c.setBalance(c.getBalance() + f.getPrice());
		cout << c.getBalance();
		cout << "\n";
		
		//Getting back balance from store.
		cout << this->getName() << "'s balance: ";
		this->setBalance(this->getBalance() - f.getPrice());
		cout << this->getBalance();
		cout << "\n";
		
		//Returning stock back to store.
		cout << f.getName() << " film stock is refilled from " << f.getStock();
		f.setStock(f.getStock() + 1);
		cout << " to " << f.getStock();
		cout << "\n";
		
		//Returning limit back to customer.
		cout << c.getName() << "'s limit returned back: ";
		c.setLimit(c.getLimit() + 1);
		cout << c.getLimit();
		cout << "\n";
		
		if(f.getName() == this->rentedfilm_list[i].getName()) {
		 this->rentedfilm_list.erase(this->rentedfilm_list.begin() + i);
		 counter++;
		}
	} else {
		cout << "this film doesn't exist in list";
	}
	
}

//Printing films in store's film list.
void Store::showFilms() {
	
	int i;
	
	for (i = 0; i < this->film_list.size(); i++) {
		this->film_list[i].toString();
	}
}

//Printing films in store's rented film list.
void Store::showRentedFilms() {
	
	int i;
	
	for (i = 0; i < this->rentedfilm_list.size(); i++) {
		this->rentedfilm_list[i].toString();
	}
}

//Renting film.
void Store::rentFilm(Film &f, Customer &c) {
	
	int counter = 0;
	
	int i;
	
	for (i = 0; i < this->film_list.size(); i++) {
		
		//If there exists 'f' film in store's film list.
		if (this->film_list[i].getName() == f.getName()) {
			
			counter++;
			
			//If age limit is not exceeded.
			if (c.getAge() >= f.getAge()) {
		
		//If stock left.
		if (this->film_list[i].getStock() > 0) {
			//If customer's balance is enough for the film.
			if (c.getBalance() >= f.getPrice()) {
			
			//Buying film.
			c.setBalance(c.getBalance() - f.getPrice());
			this->setBalance(this->getBalance() + f.getPrice());
			this->income += f.getPrice();
			c.addFilmList(f);
			this->addCustomer(c);
			f.setStock(f.getStock() - 1);
			this->addFilm(f);
			this->rentedfilm_list.push_back(f);
			cout << "\n";
			
			cout << c.getName() << " bought " << f.getName() << " for " << f.getPrice() << " dollars";
			cout << "\n" << c.getName() << "'s balance: " << c.getBalance() << " dollars";
			break;
			
		} else {
			cout << "Your balance is not enough";
		} 
		} else {
			cout << "Insufficient stock";
		}
		
	} else {
		cout << "Your age is exceeded film's age limit";
	}
		}
	}
	
	if (counter == 0) {
		cout << "This store doesn't have this film";
	}
}

//Adding customer into the store's film list.
void Store::addCustomer(Customer &c) {
	
	int counter = 0;
	
	int i;
	
	for (i = 0; i < this->customer_list.size(); i++) {
		
		if (this->customer_list[i].getName() == c.getName()) {
			counter++;
			break;
		}
	}
	
	if (counter == 0) {
		this->customer_list.push_back(c);
	}
	
	cout << c.getName() << " has been added to the store\n";
}

//Printing customers in store's customer list.
void Store::showCustomer() {
	
	int i;
	
	for (i = 0; i < this->customer_list.size(); i++) {
		this->customer_list[i].toString();
	}
}

//Printing film amount in store's film list.
void Store::filmAmount() {
	
	cout << this->getName() << "'s film amount: " << this->film_list.size();
}

//Printing store's income.
void Store::showIncome() {
	
	cout << this->getName() << "'s income: " << this->income;
}
