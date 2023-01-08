/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#include <iostream>
#include <string>

#include "Type.h"

Type::Type(string name) {
	this->name = name;
}

Type::Type() {
	
}

string Type::getName() {
	cout << this->name;
}
