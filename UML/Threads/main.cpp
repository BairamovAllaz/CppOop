#include <iostream>
#include <thread>
using namespace std;
using namespace std::chrono_literals;

bool finish = false;
void Hello()
{
    while (!finish)
    {
        cout << "+";
        std::this_thread::sleep_for(100ms);
    }
}

void World()
{
    while (!finish)
    {
        cout << "- ";
        std::this_thread::sleep_for(100ms);
    }
}

int main()
{
    // std::thread hello_thread(Hello);
    // std::thread world_thread(World);
    
    std::thread hello_thread; 
    std::thread world_thread;
    
    hello_thread  = std::thread(Hello);
    world_thread  = std::thread(World);
    cin.get();
    finish = true;
    hello_thread.join();
    world_thread.join();
    return 0;
}