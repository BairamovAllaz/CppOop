#include <iostream>
#include <Windows.h>
#include <cmath>
#include <corecrt_math_defines.h>
using namespace std;
#define PI M_PI
//create type variable Color


namespace Geometry
{
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


		Shape(Color color, unsigned int start_x, unsigned int start_y, unsigned int linewidth) : color(color) {
			set_start_x(start_x);
			set_start_y(start_y);
			set_linewidth(linewidth);
		}

		virtual ~Shape() {}
		virtual double get_area()const = 0;
		virtual double get_perimetr()const = 0;
		virtual void draw()const = 0;

		virtual void print()const {
			cout << "Start_X : " << start_x << endl;
			cout << "Start_Y : " << start_y << endl;
			cout << "Linewidth : " << linewidth << endl;
		}
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
		) : Shape(color, start_x, start_y, linewidth) {
			set_side(side);
		}
		~Square() {}

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
			::Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);
			DeleteObject(hPen);
			DeleteObject(hbrush);
			ReleaseDC(hconsole, hdc);
		}

		void print()const {
			Shape::print();
			cout << "Side: " << side << endl;
			cout << "Perimetr: " << get_perimetr() << endl;
			cout << "Area: " << get_area() << endl;
		}

	};


	class Rectangel : public Shape {
	private:
		double top, side;
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
		) : Shape(color, start_x, start_y, linewidth) {
			set_top(top);
			set_side(side);
		}

		~Rectangel() {}

		double get_area()const {
			return (top * side);
		}

		double get_perimetr()const {
			return (side + top) * 2;
		}


		void draw()const {
			HWND hconsole = GetConsoleWindow();
			HDC hcontext = GetDC(hconsole);
			HPEN mypen = CreatePen(PS_SOLID, linewidth, color);
			SelectObject(hcontext, mypen);
			HBRUSH brush = CreateSolidBrush(color);
			SelectObject(hcontext, brush);
			::Rectangle(hcontext, start_x, start_y, start_x + top, start_y + side);
			DeleteObject(mypen);
			DeleteObject(brush);
			ReleaseDC(hconsole, hcontext);
		}

		void print()const {
			Shape::print();
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
		) : Shape(color, start_x, start_y, linewidth) {
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
			Shape::print();
			cout << "Radius of circle: " << radius << endl;
			cout << "Area of circle: " << get_area() << endl;
			cout << "Perimetr of circle: " << get_perimetr() << endl;
		}

	};
	class Triangel : public Shape {

	public:

		Triangel(
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			unsigned int linewidth
		) : Shape(color, start_x, start_y, linewidth) {}
		virtual double get_height()const = 0;
		~Triangel() {}
	};


	class EqualTriangel : public Triangel {
	private:
		double side;
	public:
		double get_side()const {
			return side;
		}

		void set_side(double side) {
			if (side < 50) {
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

		~EqualTriangel() {}

		double get_height()const {
			return (sqrt(3) / 2) * side;
		}

		double get_area()const {
			return (sqrt(3) / 4) * side * side;
		}

		double get_perimetr() const {
			return 3 * side;
		}

		void draw()const {
			HWND hconsole = GetConsoleWindow();
			HDC hcontext = GetDC(hconsole);
			HPEN hPen = CreatePen(PS_SOLID, linewidth, color);
			SelectObject(hcontext, hPen);
			SetBkColor(hcontext, color);
			SelectObject(hcontext, CreateSolidBrush(color));
			POINT vertices[] = {
				{start_x, start_y + side},
				{start_x + side, start_y + side}, 
				{start_x + side / 2, start_y}
			};
			Polygon(hcontext, vertices, sizeof(vertices) / sizeof(vertices[0]));
			DeleteObject(hcontext);
			DeleteObject(hPen);
			ReleaseDC(hconsole, hcontext);
		}

		void print()const {
			Shape::print();
			cout << "Side of Eqaultriangel: " << side << endl;
			cout << "Height of Eqaultriangel: " << get_height() << endl;
			cout << "Area of Eqaultriangel: " << get_area() << endl;
			cout << "Perimetr of Eqaultriangel: " << get_perimetr() << endl;
		}
	};

	class RightTriangel : public Triangel {
	private:
		double hypotenuse, cathetus1, cathetus2;
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


		double get_cathetus1()const {
			return cathetus1;
		}

		void set_cathetus1(double k) {
			if (k < 50) {
				k = 50;
			}
			this->cathetus1 = k;
		}
		double get_cathetus2()const {
			return cathetus2;
		}

		void set_cathetus2(double k) {
			if (k < 50) {
				k = 50;
			}
			this->cathetus2 = k;
		}

		RightTriangel(
			double hypotenuse,
			double cathetus1,
			double cathetus2,
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			unsigned int linewidth
		) : Triangel(color, start_x, start_y, linewidth) {
			set_hypotenus(hypotenuse);
			set_cathetus1(cathetus1);
			set_cathetus2(cathetus2);
		}

		~RightTriangel() {}


		double get_perimetr()const {
			return (hypotenuse + cathetus1 + cathetus2);
		}

		double get_area()const {
			return (1.0 / 2.0) * cathetus1 * cathetus2;
		}

		double get_height() const {
			return 2 * get_area() / hypotenuse;
		}

		void print()const {
			Shape::print();
			cout << "Hypotenus of right triangel: " << hypotenuse << endl;
			cout << "Cathetus-1 of right triangel: " << cathetus1 << endl;
			cout << "Cathetus-2 of right triangel: " << cathetus2 << endl;
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
			POINT vertices[] = {
				/*{100, 300},
				{200,300},
				{100, 200} */
				{start_x + cathetus1,start_y + cathetus1 + cathetus2},
				{start_y + cathetus1, start_y + cathetus1 + cathetus2},
				{start_x + cathetus1,start_y + cathetus1}
			};

			Polygon(hcontext, vertices, sizeof(vertices) / sizeof(vertices[0]));
			DeleteObject(hcontext);
			DeleteObject(hPen);
			ReleaseDC(hconsole, hcontext);
		}
	};

	class IsoscalesTriangle : public Triangel {
	private:
		double leg;
		double base;
	public:

		double get_leg()const {
			return leg;
		}

		void set_leg(double leg) {
			if (leg < 50) {
				leg = 50;
			}
			this->leg = leg;
		}

		double get_base()const {
			return base;
		}

		void set_base(double base) {
			if (base < 50) {
				base = 50;
			}
			this->base = base;
		}

		IsoscalesTriangle(
			double leg,
			double base,
			Color color,
			unsigned int start_x,
			unsigned int start_y,
			unsigned int linewidth
		) : Triangel(color, start_x, start_y, linewidth) {
			set_leg(leg);
			set_base(base);
		}
		~IsoscalesTriangle() {}

		double get_perimetr()const {
			return 2 * leg + base;
		}

		double get_area()const {
			return (1.0 / 2.0) * base * sqrt(leg * leg - (base * base / 4));
		}

		double get_height()const {
			return (1.0 / 2.0) * base * leg;
		}

		void draw()const {
			HWND hconsole = GetConsoleWindow();
			HDC hcontext = GetDC(hconsole);
			HPEN hPen = CreatePen(PS_SOLID, linewidth, color);
			SelectObject(hcontext, hPen);
			SetBkColor(hcontext, color);
			SelectObject(hcontext, CreateSolidBrush(color));
			POINT vertices[] = {
				{start_x, start_y + leg},
				{start_x + leg + (base/2),start_y + leg},
				{start_x + base,start_y}
			};
			Polygon(hcontext, vertices, sizeof(vertices) / sizeof(vertices[0]));
			DeleteObject(hcontext);
			DeleteObject(hPen);
			ReleaseDC(hconsole, hcontext);
		}

		void print()const {
			Shape::print();
			cout << "Leg : " << leg << endl;
			cout << "Base : " << base << endl;
		}
	};

}

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

	/*Geometry::EqualTriangel equaltriangel(200, Geometry::Color::green, 100, 200, 5);
	equaltriangel.print();
	equaltriangel.draw();*/

	/*Geometry::RightTriangel righttriangel(400, 150, 150, Geometry::Color::green, 10, 100, 5);
	righttriangel.print();
	righttriangel.draw();*/
	Geometry::IsoscalesTriangle istriangel(200, 100, Geometry::Color::green, 10, 100, 5);
	istriangel.print();
	istriangel.draw();
	return 0;
}
