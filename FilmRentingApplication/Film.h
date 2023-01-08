/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#ifndef FILM_H
#define FILM_H

#include "Type.h"

using namespace std;

class Film {
	private:
		string name;
		int age_limit;
		float price;
		int stock;
		string date;
		Type type;
		
	public: 
		Film (string, string, int, float, int, Type);
		string getName();
		void setName(string);
		string getDate();
		void setDate(string);
		Type getType();
		void setType(Type);
		int getAge();
		void setAge(int);
		float getPrice();
		void setPrice(float);
		int getStock();
		void setStock(int);
		void toString();
};

#endif
