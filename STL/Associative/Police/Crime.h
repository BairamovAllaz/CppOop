#pragma once
#include <iostream>
#include <cstring>
#include <map>
#include <ctime>
#include <fstream>
#include <chrono>
#include <sstream>

using namespace std;
const std::map<size_t, std::string> crimes = {
    {1, "проезд на красный"},
    {2, "привышение скорости"},
    {3, "езда по встречной полосе"},
    {4, "дрифт на перекрестке"},
    {5, "оскорбление офицера"},
};

class Crime
{
private:
    size_t id;
    std::string place;
    std::string times;
public:
    size_t get_id() const
    {
        return id;
    }

    const std::string &get_place() const
    {
        return place;
    }

    std::string getTimes() const
    {
        return times;
    }

    bool operator==(const Crime &other) const
    {
        return this->id == other.id && this->place == other.place;
    }
    bool operator!=(const Crime &other) const
    {
        return this->id != other.id && this->place != other.place;
    }

    Crime(size_t id, std::string place) : id(id), place(place)
    {
        // https://en.cppreference.com/w/cpp/chrono/c/localtime
        // https://en.cppreference.com/w/cpp/chrono/c/tm
        
        //TODO do this!!
        // auto currtime = std::chrono::system_clock::now(); 
        // time_t timet = std::chrono::system_clock::to_time_t(currtime); 
        // this->times = to_string(timet);
        
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        this->times = std::to_string(timeinfo->tm_hour) +
        ":" + std::to_string(timeinfo->tm_min) +
        ":" + std::to_string(timeinfo->tm_sec) +
        "-" + std::to_string(timeinfo->tm_mon + 1) +
        "-" + std::to_string(timeinfo->tm_mday) +
        "-" + std::to_string(timeinfo->tm_year);
    }
    ~Crime() {
    }
};

std::ostream &operator<<(std::ostream &os, const Crime &obj)
{
    return os << crimes.at(obj.get_id()) << ", " << obj.get_place() << ", " << obj.getTimes();
}
std::ofstream &operator<<(std::ofstream &ofs, const Crime &obj)
{
    ofs << obj.get_id() << " " << obj.get_place() << " " << obj.getTimes();
    return ofs;
}
