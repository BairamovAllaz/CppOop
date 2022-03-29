#include <iostream>
using namespace std;

class Vehicle {
private:
public:
	virtual void move() = 0;
	virtual void stop() = 0;
};

class GroundVehicle:private Vehicle{};

class Car : public GroundVehicle {
public: 
	void move() {
		cout << "Our car is going!" << endl;
	}

	void stop() {
		cout << "Our car is stopped!" << endl;
	}
};

class Bike :public GroundVehicle{
public:
	void move() {
		cout << "Our bike is going!" << endl;
	}

	void stop() {
		cout << "Our bike is stopped!" << endl;
	}
	
};

class SeaVehicles : public Vehicle {};

class Boat : public SeaVehicles {
	
public:
	void move() {
		cout << "Our boat is going!" << endl;
	}

	void stop() {
		cout << "Our Boat is stopped!" << endl;
	}

};

class Yacht : public SeaVehicles {
	
public: 
	void move() {
		cout << "Our Yacht going" << endl; 
	}

	void stop() {
		cout << "Our Yacht is stopped!" << endl;
	}
};


class AirVehicle : public Vehicle{};
	

class Airplane : public AirVehicle {
public: 
	void move() {
		cout << "Our Airplane is going!" << endl;
	}
	void stop() {
		cout << "Our Airplane is stopped!" << endl;
	}
};

class Helicopter : public AirVehicle {
public:
	void move() {
		cout << "Our helicopter is going!" << endl;
	}
	void stop() {
		cout << "Our Helicopter is stopped!" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "");
	Helicopter a;
	a.move();

	return 0;
}