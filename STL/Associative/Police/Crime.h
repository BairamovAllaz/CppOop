#pragma once
#include <iostream>
#include <cstring>
#include <map>
#include <ctime>
#include <fstream>

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
    // char *times;

public:
    size_t get_id() const
    {
        return id;
    }

    const std::string &get_place() const
    {
        return place;
    }

    // const char *getTimes() const
    // {
    //     return times;
    // }

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
        // time_t start = time(NULL);
        // this->times = ctime(&start);
    }
    ~Crime() {}
};

std::ostream &operator<<(std::ostream &os, const Crime &obj)
{
    // return os << crimes.at(obj.get_id()) << ", " << obj.get_place() << ", " << obj.getTimes();
    return os << crimes.at(obj.get_id()) << ", " << obj.get_place();
}
std::ofstream &operator<<(std::ofstream &ofs, const Crime &obj)
{
    ofs << obj.get_id() << " " << obj.get_place();
    return ofs;
}
