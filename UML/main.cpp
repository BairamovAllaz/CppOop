#include <iostream>
#include <conio.h>
#include <thread>
using namespace std;
using namespace std::chrono_literals;
#define KEY_UP 72
#define KEY_DOWN 80
#define Escape 27
#define Enter 13
#define MIN_TANK_VOLUME 20
#define MAX_TANK_VOLUME 80
#define MIN_ENGINE_CONSUMPTION 3
#define MAX_ENGINE_CONSUMPTION 25
#define FKEYBOARD 'f'
#define delimetr "\t\t\t\t"
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

    double give_fuel(double amount) {
        if (fuel_level - amount > 0)fuel_level -= amount;
        else fuel_level = 0;
        return fuel_level;
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
    double speed;
    size_t max_speed;
    double acceleration;
    struct Control
    {
        std::thread panel_thread;
        std::thread engine_idle_thread;
        std::thread free_wheeling_thread;
        std::thread speed_idle_thread;
        std::thread speed_panel_thread;
    } control;

public:
    Car(
        double engine_consumption,
        unsigned int tank_volume,
        size_t maxspeed,
        double acceleration
        ) : engine(engine_consumption), tank(tank_volume)
    {
        set_acceleration(acceleration);
        set_max_speed(maxspeed);
        this->speed = 0;
        this->driver_inside = false;
        cout << "Your car is ready" << endl;
    }
    ~Car()
    {
        cout << "Your car is over" << endl;
    }


    void speed_panel() {
        while (driver_inside)
        { 
            system("cls");
            std::cout << "Speed: " << this->speed << endl; 
            std::cout << "Acceleration of the car: " << this->acceleration << std::endl; 
            std::this_thread::sleep_for(2s);
        }
    }

    void up_Speed() {
        while (this->speed < this->max_speed && tank.get_fuel_level())
        {
            this->speed += acceleration;
            std::this_thread::sleep_for(1s);
        }
    }

    void down_Speed() {
        while (this->speed > 0 && tank.get_fuel_level())
        {
            this->speed -= acceleration;
            std::this_thread::sleep_for(1s);
        }
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
            case 'I':
            case 'i':
                if (engine.started()) {
                    stop_engine();
                }
                else {
                    start_engine();
                }
                break;
            case KEY_UP:
            case KEY_DOWN:
                if (key == KEY_UP) {
                    control.speed_idle_thread = std::thread(&Car::up_Speed, this);
                    control.speed_panel_thread = std::thread(&Car::speed_panel, this);
                    if (control.speed_idle_thread.joinable())control.speed_idle_thread.join();
                }
                //not working yet!
               /* else if (key == KEY_DOWN) {
                    control.speed_idle_thread = std::thread(&Car::down_Speed, this);
                    control.speed_panel_thread = std::thread(&Car::speed_panel, this);
                    if (control.speed_idle_thread.joinable())control.speed_idle_thread.join();
                }*/
                if (this->speed == max_speed) {
                   
                    if (control.speed_panel_thread.joinable())control.speed_panel_thread.join();
                }
                break;
            case FKEYBOARD:
                if (driver_inside) {
                    cout << "You need to out car !!" << endl;
                }
                else {
                    double fuel;
                    cout << "Enter fuel level: ";
                    cin >> fuel;
                    tank.fill(fuel);
                    cout << "Fuelling is done! you can go!" << endl;
                }
            case Escape:
                stop_engine();
                get_out();
                break;
            default:
                std::cout << "Try another key(F I ESCAPE ENTER)" << std::endl;
                break;
            }
        } while (key != Escape);
    }

    void panel() const
    {
        while (driver_inside)
        {
            system("CLS");
            cout << "Fuel level: " << tank.get_fuel_level() << " liters\n";
            if (tank.get_fuel_level() <= 5) {
                std::cout << delimetr << "LOW FUEL" << delimetr << std::endl;
            }
            cout << "Engine is " << (engine.started() ? "started" : "stopped") << endl;
            std::this_thread::sleep_for(2s);
        }
    }


    void engine_idle()
    {
        while (engine.started() && tank.give_fuel(engine.get_consumption_per_second()))
        {
            std::this_thread::sleep_for(1s);
        }
    }

    void set_speed(double speed) {
        this->speed = speed;
    }

    double get_speed()const {
        return speed;
    }

    void set_max_speed(size_t maxspeed) {
        if (maxspeed < 100) {
            maxspeed = 100;
        }
        else if (maxspeed > 180) {
            maxspeed = 180;
        }
        this->max_speed = maxspeed;
    }

    size_t get_max_speed()const {
        return max_speed;
    }

    void set_acceleration(double acceleration) {
        if (acceleration >= 5) {
            acceleration = 10;
        }
        this->acceleration = acceleration;
    }

    double get_acceleration()const {
        return acceleration;
    }

    void get_in()
    {
        this->driver_inside = true;
        // panel();
        control.panel_thread = std::thread(&Car::panel, this);
    }

    void get_out()
    {
        this->driver_inside = false;
        if (control.panel_thread.joinable()) {
            control.panel_thread.join();
        }
        system("CLS");
        cout << "You are out of your car!!!" << endl;
    }


    void start_engine() {
        if (driver_inside && tank.get_fuel_level())
        {
            engine.start();
            control.engine_idle_thread = std::thread(&Car::engine_idle, this);
        }
    } 

    void stop_engine() {
        engine.stop();
        if (control.engine_idle_thread.joinable())control.engine_idle_thread.join();
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
    Car bmw(12,60,140,14);
    bmw.control_car();
#endif

    return 0;
}