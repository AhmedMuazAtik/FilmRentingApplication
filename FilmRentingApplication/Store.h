/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#ifndef STORE_H
#define STORE_H

#include "Customer.h"
#include "Film.h"
#include "Type.h"

#include <vector>

using namespace std;

class Store {
	private:
	string name;
	float balance;
	int income;
	vector <Film> film_list;
	vector <Film> rentedfilm_list;
	vector <Customer> customer_list;
	
	public:
	Store (string, float);
	string getName();
	void setName(string);
	float getBalance();
	void setBalance(float);
	void addFilm(Film&);
	void deleteFilm(Film&);
	void addStock(Film&);
	void showFilms();
	void rentFilm(Film&, Customer&);
	void returnFilm(Film&, Customer&);
	void addCustomer(Customer&);
	void showCustomer();
	void filmAmount();
	void showIncome();
	void showRentedFilms();
	void updateFilm(Film&, string, string, int, float, int, Type);
	void toString();
};

#endif
