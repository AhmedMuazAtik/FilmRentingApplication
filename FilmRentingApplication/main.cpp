/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#include <iostream>
#include <string>

#include "Customer.h"
#include "Film.h"
#include "Store.h"
#include "Type.h"

int main(int argc, char** argv) {
	Customer customer_1("Muaz",20,300);
	Customer customer_2("Yunus",11,150);
	
	Type horror("Horror");
	Type scifi("Sci-fi");
	Type fantastic("Fantastic");
	
	Film film_1("Harry Potter", "02.03.2003", 13, 40, 10, fantastic);
	Film film_2("Lord of the Rings", "04.05.1999", 13, 40, 5, fantastic);
	Film film_3("Insidious", "04.11.2012", 18, 30, 15, horror);
	Film film_4("Exorcist", "03.10.2002", 18, 30, 20, horror);
	Film film_5("Avatar", "12.10.2005", 8, 50, 30, scifi);
	
	Store store_1("Cinemaximum", 0);
	Store store_2("Bestfilm", 500);
	
	store_1.addFilm(film_3);
	cout << "\n";
	store_1.addFilm(film_5);
	
	cout << "\n\n";
	
	store_1.showFilms();
	
	cout << "\n-----------------------\n";
	
	store_1.rentFilm(film_3,customer_2);
	cout << "\n\n";
	store_1.rentFilm(film_5,customer_2);
	
	cout << "\n-----------------------\n";
	
	store_1.filmAmount();
	cout << "\n\n";
	store_1.showCustomer();
	cout << "\n\n";
	store_1.showIncome();
	cout << "\n\nRented films:\n";
	store_1.showRentedFilms();
	
	cout << "\n-----------------------\n";
	
	store_1.returnFilm(film_3,customer_2);
	
	cout << "\n-----------------------\n";
	
	customer_2.toString();
	cout << "\n\nOld films:\n";
	customer_2.oldFilmList();
	cout << "\n\nCurrent films:\n";
	customer_2.getFilmList();
	
	cout << "\n------ GENERAL TEST --------\n";
	
	store_1.addFilm(film_1);
	cout << "\n";
	cout << "\n";
	store_1.addFilm(film_1);
	cout << "\n";
	cout << "\n";
	store_1.updateFilm(film_1,film_1.getName(), film_1.getDate(), film_1.getAge(), film_1.getPrice(), 20, film_1.getType());
	cout << "\n";
	cout << "\n";
	store_1.deleteFilm(film_2);
	cout << "\n";
	cout << "\n";
	store_1.rentFilm(film_1, customer_1);
	cout << "\n";
	cout << "\n";
	store_1.showCustomer();
	cout << "\n";
	cout << "\n";
	cout <<	store_1.getBalance();
	cout << "\n";
	cout << "\n";
	store_1.filmAmount();
	cout << "\n";
	cout << "\n";
	store_2.filmAmount();
	cout << "\n";
	cout << "\n";
	store_1.showIncome();
	cout << "\n";
	cout << "\n";
	store_2.showIncome();
	cout << "\n";
	cout << "\n";
}
