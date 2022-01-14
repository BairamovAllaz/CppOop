#include <iostream>
#include <math.h>
#include <cmath>
#include <corecrt_math_defines.h>
using namespace std;

///draw to console is not done!!!!!
#define PI M_PI //for pi = 3.14......
class Square{
private:
	double side; /// corners of square
public:
	double get_side()const {
		return side;
	}
	void set_side(double side){
		this->side = side;
	}

	double get_area(){
		return side * side;
	}
	
	double get_perimetr() {
		return side * 4;
	}

	Square(double side) {
		this->side = side;
		cout << "Sconstructor\t" << this << endl;
	}
	~Square() {
		cout << "Sdesctructor\t" << endl;
	}

	void print() {
		//Figure::print();
		cout << "Side: " << side << endl;
		cout << "Perimetr: " << get_perimetr() << endl;
		cout << "Area: " << get_area() << endl;
	}

};

class EqualTriangel{
private:
	double side; //left right and bottom side of triangel
public:
	
	double get_side() {
		return side;
	}

	void set_side(double side) {
		this->side = side;
	}


	double get_height() {
		return (sqrt(3) / 2) * side;
	}

	double get_area() {
		return (sqrt(3) / 4) * side * side;
	}

	double get_perimetr() {
		return 3 * side;
	}

	EqualTriangel(double side){
		this->side = side;
		cout << "Tconstructor\t" << this << endl;
	}

	~EqualTriangel() {
		cout << "Tdesctructor\t" << this << endl;
	}

	void print(){ 
		///Figure::print();
		cout << "Side : " << side << endl;
		cout << "Perimetr: " << get_perimetr() << endl;
		cout << "Area: " << get_area() << endl;
		cout << "Height: " << get_height() << endl;
	}
};

class Circle{
private:
	double radius;
public:

	double get_radius() {
		return radius;
	}
	void set_radius(double radius) {
		if (radius == 0 || radius == 0.0) {
			radius = 1;
		}
		this->radius = radius;
	}

	double get_area()const {
		double area = PI * radius * radius;
		return area;
	}

	double get_diametr()const {
		return 2 * this->radius;
	}

	double get_circumference() const {
		return 2 * PI * radius;
	}

	Circle(double radius) {
		this->radius = radius;
		cout << "Cconstructor\t" << this << endl;
	}

	~Circle() {
		cout << "Cdesctructor\t" << this << endl;
	}


	void print()const {
		cout << "Radius: " << radius << endl;
		cout << "Area: " << get_area() << endl;
		cout << "Radius: " << get_diametr() << endl;
	}

};



int main() {

	Square b(6);
	b.print();

	EqualTriangel c(6);
	c.print();

	Circle d(5);
	d.print();

	return 0;
}