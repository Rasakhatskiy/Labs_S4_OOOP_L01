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
