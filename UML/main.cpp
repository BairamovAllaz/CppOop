#include <iostream>
#include <conio.h>
using namespace std;
#define Escape 27
#define Enter 13
#define MIN_TANK_VOLUME 20
#define MAX_TANK_VOLUME 80
#define MIN_ENGINE_CONSUMPTION 3
#define MAX_ENGINE_CONSUMPTION 25
#define FKEYBOARD 'f'
class Tank
{
private:
    const unsigned int VOLUME = 20;
    double fuel_level;

public:
    unsigned int get_VOLUME() const
    {
        return this->VOLUME;
    }

    double get_fuel_level() const
    {
        return this->fuel_level;
    }

    void fill(double fuel_level)
    {
        if (fuel_level <= 0)
            return;
        if (this->fuel_level + fuel_level <= VOLUME)
            this->fuel_level += fuel_level;
        else
        {
            this->fuel_level = VOLUME;
        }
    }

    Tank(unsigned int volume) : VOLUME(volume >= MIN_TANK_VOLUME && volume <= MAX_TANK_VOLUME ? volume : 60)
    {
        this->fuel_level = 0;
        cout << "Tank is ready" << endl;
    }
    ~Tank()
    {
        cout << "Tank is over" << endl;
    }

    void info() const
    {
        cout << "Tank volume: " << this->VOLUME << " liters\n";
        cout << "Fuel level: " << this->fuel_level << " liters\n";
    }
};

class Engine
{
private:
    double consumption;
    double consumption_per_second;
    bool is_started;

public:
    double get_consumption() const
    {
        return consumption;
    }

    double get_consumption_per_second() const
    {
        return consumption_per_second;
    }

    void set_consumption(double consumption)
    {
        if (consumption >= MIN_ENGINE_CONSUMPTION && consumption <= MAX_ENGINE_CONSUMPTION)
            this->consumption = consumption;
        else
            this->consumption = 10;
        this->consumption_per_second = this->consumption * 3e-5;
    }

    void set_consumption_per_second(double consumption_per_second)
    {
        if (consumption >= MIN_ENGINE_CONSUMPTION && consumption <= MAX_ENGINE_CONSUMPTION)
            this->consumption = consumption;
        else
            this->consumption = 10;
        this->consumption_per_second = this->consumption * 3e-5;
    }

    void start()
    {
        is_started = true;
    }

    void stop()
    {
        is_started = false;
    }

    bool started() const
    {
        return is_started;
    }

    void info() const
    {
        cout << "Consumption per 100 km: " << consumption << " liters\n";
        cout << "Consumption per 100 seconde: " << consumption_per_second << " liters\n";
    }

    Engine(double consumption)
    {
        set_consumption(consumption);
        this->is_started = false;
        cout << "Engine is ready" << endl;
    }
    ~Engine()
    {
        cout << "Engine is over" << endl;
    }
};

class Car
{
private:
    Engine engine;
    Tank tank;
    bool driver_inside;

public:
    Car(double engine_consumption, unsigned int tank_volume) : engine(engine_consumption), tank(tank_volume)
    {
        this->driver_inside = false;
        cout << "Your car is ready" << endl;
    }
    ~Car()
    {
        cout << "Your car is over" << endl;
    }

    void control_car()
    {
        char key;
        do
        {
            cout << "Press enter to get in or press f to fuel car: " << endl;
            key = _getch();
            switch (key)
            {
            case Enter: // Key code enter
                if (driver_inside)
                    get_out();
                else
                    get_in();
                break;
            case FKEYBOARD:
                double fuel;
                cout << "Enter fuel level: ";
                cin >> fuel;
                tank.fill(fuel);
                tank.info();
                cout << "Fuelling is done! you can go!" << endl;
            default:
                break;
            }
        } while (key != Escape);
    }

    void panel() const
    {
        system("CLS");
        cout << "Fuel level: " << tank.get_fuel_level() << " liters\n";
        cout << "Engine is " << (engine.started() ? "started" : "stopped") << endl;
    }

    void get_in()
    {
        this->driver_inside = true;
        panel();
    }

    void get_out()
    {
        this->driver_inside = false;
        system("CLS");
        cout << "You are out of your car!!!" << endl;
    }

    void info() const
    {
        engine.info();
        tank.info();
    }
};

// #define TANK_CHECK
// #define ENGINE_CHECK
#define CAR_CHECK
int main()
{
#ifdef TANK_CHECK

    Tank tank(40);
    tank.info();
    int fuel;

    while (true)
    {
        std::cout << "Enter fuel level: ";
        std::cin >> fuel;
        tank.fill(fuel);
        tank.info();
    }
#endif // DEBUG

#ifdef ENGINE_CHECK
    Engine engine(10);
    engine.info();
#endif // DEBUG

#ifdef CAR_CHECK
    Car bmw(12, 60);
    bmw.control_car();
#endif

    return 0;
}
