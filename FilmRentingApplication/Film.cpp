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
#include "Type.h"

Film::Film(string name, string date, int age_limit, float price, int stock, Type type) {
	this->name = name;
	this->price = price;
	this->stock = stock;
	this->date = date;
	this->age_limit = age_limit;
	this->type = type;
}

//Printing film.
void Film::toString() {
	cout << "Name: " << this->name << "\nDate: " << this->date << "\nAge Limit: " << this->age_limit << "\nPrice: " << this->price << "\nStock: " << this->stock  << "\nType: ";
	this->type.getName();
	cout << "\n\n";
}

int Film::getAge() {
	return this->age_limit;
}

string Film::getName() {
	return this->name;
}

float Film::getPrice() {
	return this->price;
} 

int Film::getStock() {
	return this->stock;
}

string Film::getDate() {
	return this->date;
}

void Film::setDate(string t_date) {
	this->date = t_date;
}

Type Film::getType() {
	return this->type.getName();
}

void Film::setType(Type t_type) {
	this->type = t_type;
}

void Film::setAge(int t_age) {
	this->age_limit = t_age;
} 

void Film::setName(string t_name) {
	this->name = t_name;
}

void Film::setPrice(float t_price) {
	this->price = t_price;
}

void Film::setStock(int t_stock) {
	this->stock = t_stock;
}
