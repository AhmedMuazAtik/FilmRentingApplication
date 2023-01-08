#ifndef CUSTOMER_H
/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#define CUSTOMER_H

#include "Film.h"

#include <vector>

using namespace std;

class Customer {
	private:
		string name;
		int age;
		float balance;
		int limit;
		vector<Film> film_list;
		vector<Film> oldfilm_list;
		
	public:
		Customer(string, int, float);
		string getName();
		void setName(string);
		int getAge();
		void setAge(int);
		float getBalance();
		void setBalance(float);
		int getLimit();
		int listCounter(Film&);
		void setLimit(int);
		void getFilmList();
		void addFilmList(Film&);
		void removeFilmList(Film&);
		void oldFilmList();
		void toString();
};

#endif
