#include <iostream>
#include <Windows.h>
#include <cmath>
#include <corecrt_math_defines.h>
using namespace std;
#define PI M_PI
//create type variable Color
enum Color {
	red = 0x000000FF,
	green = 0x0000FF00,
	blue = 0x00FF0000,
	some_color,  /// enum started in 0          
	console_blue = 0x99, // 9 color code
	console_green = 0xAA, 
	console_red = 0xCC,
	console_default = 0x07
};

class Shape {
protected: 
	unsigned int start_x, start_y, linewidth; 
	Color color;

public:
	void set_start_x(unsigned int start_x) {
		if (start_x > 300) {
			start_x = 300;
		}
		this->start_x = start_x;
	}	
	
	void set_start_y(unsigned int start_y) {
		if (start_y > 300) {
			start_y = 300;
		}
		this->start_y = start_y;
	}

	void set_linewidth(unsigned int linewidth) {
		if (linewidth > 20) {
			linewidth = 20;
		}
		this->linewidth = linewidth;
	}


	Shape(Color color,unsigned int start_x,unsigned int start_y,unsigned int linewidth): color(color) {
		set_start_x(start_x);
		set_start_y(start_y);
		set_linewidth(linewidth); 
	}

	virtual ~Shape() {}
	virtual double get_area()const = 0;
	virtual double get_perimetr()const = 0; 
	virtual void draw()const = 0;
	virtual void print()const = 0;
};

class Square : public Shape {
private:	
	double side;
public: 

	double get_side()const {
		return side;
	}

	void set_side(double side) {
		if (side <= 0) {
			side = 10;
		}
		this->side = side;
	}
	Square(
		double side,
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		unsigned int linewidth
	) : Shape(color,start_x,start_y,linewidth) {
		set_side(side);
	}
	~Square(){}

	double get_area()const {
		return side * side;
	}

	double get_perimetr()const {
		return side * 4;
	}


	void draw()const {
		HWND hconsole = GetDesktopWindow(); 
		HDC hdc = GetDC(hconsole);
		HPEN hPen = CreatePen(PS_SOLID, linewidth, color);
		SelectObject(hdc, hPen);	
		HBRUSH hbrush = CreateSolidBrush(color);
		SelectObject(hdc, hbrush);
		Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);
		DeleteObject(hPen);
		DeleteObject(hbrush);
		ReleaseDC(hconsole, hdc);
	}

	void print()const {
		cout << "Side: " << side << endl;
		cout << "Perimetr: " << get_perimetr() << endl;
		cout << "Area: " << get_area() << endl;
	}

};


class Rectangel : public Shape {
private: 
	double top,side;
public: 

	double get_top()const {
		return top;
	}

	double get_side()const {
		return side;
	}

	void set_top(double top) {
		if (top <= 100 || top <= 0) {
			top = 100;
		}
		this->top = top;
	}

	void set_side(double side) {
		if (side <= 50 || side <= 0) {
			side = 50;
		}
		this->side = side;
	}


	Rectangel(
		double top,
		double side,
		Color color,
		unsigned int start_x,
		unsigned int start_y, 
		unsigned int linewidth
		) : Shape(color,start_x,start_y,linewidth) { 
		set_top(top);
		set_side(side);
		}

	~Rectangel(){}

	double get_area()const {
		return (top * side);
	}

	double get_perimetr()const{
		return (side + top) * 2;
	}


	void draw()const {
		HWND hconsole = GetConsoleWindow(); 
		HDC hcontext = GetDC(hconsole); 
		HPEN mypen = CreatePen(PS_SOLID, linewidth, color);
		SelectObject(hcontext, mypen); 
		HBRUSH brush = CreateSolidBrush(color);
		SelectObject(hcontext, brush);
		Rectangle(hcontext, start_x, start_y, start_x + top, start_y + side);
		DeleteObject(mypen); 
		DeleteObject(brush); 
		ReleaseDC(hconsole, hcontext);
	}

	void print()const {
		cout << "Top of rectangel: " << top << endl;
		cout << "Side of rectangel: " << side << endl;
		cout << "Perimetr of rectangel: " << get_perimetr() << endl;
		cout << "Area of rectangel: " << get_area() << endl;
	}
};

class Circle : public Shape {
private: 
	double radius;
public:

	double get_radius()const {
		return radius;
	}

	void set_radius(double radius) { 
		if (radius < 50 || radius < 0) {
			radius = 50;
		}
		this->radius = radius;
	}

	Circle(
		double radius,
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		unsigned int linewidth
	) : Shape(color, start_x, start_y,linewidth) {
		set_radius(radius);
	}
	~Circle() {}


	void draw()const {
		HWND hconsole = GetConsoleWindow();
		HDC hcontext = GetDC(hconsole);
		HPEN mypen = CreatePen(PS_SOLID, linewidth, color);
		SelectObject(hcontext, mypen);
		HBRUSH brush = CreateSolidBrush(color);
		SelectObject(hcontext, brush);
		Ellipse(hcontext, start_x, start_y, start_x + radius, start_y + radius);
		DeleteObject(mypen);
		DeleteObject(brush);
		ReleaseDC(hconsole, hcontext);
	}


	double get_area()const {
		double area = PI * radius * radius;
		return area;
	}

	double get_perimetr()const {
		return 2 * this->radius;
	}


	void print()const {
		cout << "Radius of circle: " << radius << endl;
		cout << "Area of circle: " << get_area() << endl;
		cout << "Perimetr of circle: " << get_perimetr() << endl;
	}

};


class Triangel : public Shape{

public:

	Triangel(
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		unsigned int linewidth
		) : Shape(color,start_x,start_y,linewidth) {}

	virtual double get_height()const = 0;

};


class EqualTriangel : public Triangel {
private:
	double side;

public:
	double get_side()const {
		return side;
	}

	void set_side(double side) {
		if (side > 50) {
			side = 50;
		}
		this->side = side;
	}

	EqualTriangel(
		double side,
		Color color,
		unsigned int start_x,
		unsigned int start_y,
		unsigned int linewidth
	) : Triangel(color, start_x, start_y, linewidth) {
		set_side(side);
	}

	~EqualTriangel(){}

	double get_height()const{
		return (sqrt(3) / 2) * side;
	}

	double get_area()const {
		return (sqrt(3) / 4) * side * side;
	}

	double get_perimetr() const{
		return 3 * side;
	}

	void draw()const {
		HWND hconsole = GetConsoleWindow();
		HDC hcontext = GetDC(hconsole);
		HPEN hPen = CreatePen(PS_SOLID, linewidth, color);
		SelectObject(hcontext, hPen);
		SetBkColor(hcontext, color);
		SelectObject(hcontext, CreateSolidBrush(color));
		POINT vertices[] = { {200, 100}, {300, 300}, {100, 300} };
		Polygon(hcontext, vertices, sizeof(vertices) / sizeof(vertices[0]));
		DeleteObject(hcontext);
		DeleteObject(hPen);
		ReleaseDC(hconsole, hcontext);
	}

	void print()const {
		cout << "Side of Eqaultriangel: " << side << endl;
		cout << "Height of Eqaultriangel: " << get_height() << endl;
		cout << "Area of Eqaultriangel: " << get_area() << endl;
		cout << "Perimetr of Eqaultriangel: " << get_perimetr() << endl;
	}
};

class RightTriangel : public Triangel {
private: 
	double hypotenuse, cathetus;

public: 
	double get_hypotenus()const {
		return hypotenuse;
	}

	void set_hypotenus(double h) {
		if (h < 100) {
			h = 100;
		}
		this->hypotenuse = h;
	}


	double get_cathetus()const {
		return cathetus;
	}

	void set_cathetus(double k) {
		if (k < 50) {
			k = 50;
		}
		this->cathetus = k;
	}

	RightTriangel(
		double hypotenuse,
		double cathetus1,
		Color color,
		unsigned int start_x, 
		unsigned int start_y, 
		unsigned int linewidth
		) : Triangel(color,start_x,start_y,linewidth) {
		set_hypotenus(hypotenuse); 
		set_cathetus(cathetus);
		}

	~RightTriangel() {}


	double get_perimetr()const {
		return (hypotenuse + cathetus + cathetus);
	}

	double get_area()const {
		return (2/1) * hypotenuse * cathetus;
	}

	double get_height() const {
		return 2 * get_area() / hypotenuse;
	}

	void print()const {
		cout << "Hypotenus of right triangel: " << hypotenuse << endl;
		cout << "Cathetus of right triangel: " << cathetus << endl;
		cout << "Perimetr of right triangel: " << get_perimetr() << endl;
		cout << "Area of right triangel: " << get_area() << endl;
		cout << "Height of right triangel: " << get_height() << endl;
	}

	void draw()const {
		HWND hconsole = GetConsoleWindow();
		HDC hcontext = GetDC(hconsole);
		HPEN hPen = CreatePen(PS_SOLID, linewidth, color);
		SelectObject(hcontext, hPen);
		SetBkColor(hcontext, color);
		SelectObject(hcontext, CreateSolidBrush(color));
		POINT vertices[] = { {300, 100}, {300, 300}, {100, 300} };
		Polygon(hcontext, vertices, sizeof(vertices) / sizeof(vertices[0]));
		DeleteObject(hcontext);
		DeleteObject(hPen);
		ReleaseDC(hconsole, hcontext);
	}
};


int main() {
	setlocale(LC_ALL, "");
	//Square square(250, Color::blue,100,200,5);
	//square.print();
	//square.draw();

	/*Rectangel rectangel(100, 50, Color::red, 100, 200, 5);
	rectangel.print();
	rectangel.draw();*/

	//Circle circle(200, Color::blue, 100, 200, 5);
	//circle.print();
	//circle.draw();

	//EqualTriangel equaltriangel(100, Color::green, 100, 200, 5);
	//equaltriangel.print();
	//equaltriangel.draw();
	
	RightTriangel righttriangel(200, 100, Color::green, 100, 200, 5); 
	righttriangel.print();
	righttriangel.draw();
	return 0;	
}