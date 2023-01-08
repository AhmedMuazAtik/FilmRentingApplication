/** 
 *@file FilmRentingApplication 
 *@description A program that customers can rent films from stores.
 *@assignment 3
 *@date 08/01/2023
 *@author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
 */

#ifndef TYPE_H
#define TYPE_H

using namespace std;

class Type {
	private:
		string name;
		
	public: 
		Type(string);
		Type();
		string getName();
};

#endif
