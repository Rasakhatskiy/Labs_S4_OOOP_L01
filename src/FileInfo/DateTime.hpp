#ifndef DATETIME_HPP
#define DATETIME_HPP

struct DateTime
{
    unsigned short
    year,
    month,
    day,
    hour,
    minute,
    second;

    DateTime():
        year(0),
        month(0),
        day(0),
        hour(0),
        minute(0),
        second(0){}

    DateTime(
            unsigned short year,
            unsigned short month,
            unsigned short day,
            unsigned short hour,
            unsigned short minute,
            unsigned short second) :
        year(year),
        month(month),
        day(day),
        hour(hour),
        minute(minute),
        second(second){}

};

#endif // DATETIME_HPP
