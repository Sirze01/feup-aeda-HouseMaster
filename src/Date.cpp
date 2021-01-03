#include "Date.h"
#include <iostream>
#include <algorithm>

/**
 * @brief default date
 */
Date::Date() {
    time_t timestamp;
    time(&timestamp);
    _date = *(localtime(&timestamp));
}


/**
 * @brief Sets the date with the integer numbers provided
 * @param day sets the day
 * @param month sets the month
 * @param year sets the year
 * @param hours sets the hours
 * @param minutes sets the minutes
 */
Date::Date(int day, int month, int year, int hours, int minutes) {
    checkIfValid(day, month, year, hours, minutes);
    time_t timestamp;
    time(&timestamp);
    _date = *(localtime(&timestamp));
    _date.tm_mday = day;
    _date.tm_mon = month - 1;
    _date.tm_year = year - 1900;
    _date.tm_hour = hours;
    _date.tm_min = minutes;
    _date.tm_sec = 0;
    mktime(&_date);
}

/**
 * @brief Sets the date with a given string
 * @param date the date in the form of a string
 */
Date::Date(const std::string &date) {
    std::stringstream ss(date);
    char sep{};
    int day, month, year, hours, minutes;
    // DD/MM/YYYY HH:mm
    ss >> day >> sep >> month >> sep >> year >> hours >> sep >> minutes;
    checkIfValid(day, month, year, hours, minutes);
    time_t timestamp;
    time(&timestamp);
    _date = *(localtime(&timestamp));
    _date.tm_mday = day;
    _date.tm_mon = month - 1;
    _date.tm_year = year - 1900;
    _date.tm_hour = hours;
    _date.tm_min = minutes;
    _date.tm_sec = 0;
    timestamp = mktime(&_date);
}

tm Date::getDate() const {
    return _date;
}

/**
 * @brief Converts the saved date in a string. Useful to show during output operations.
 * @return A string with the date in DD/MM/YYYY HH:mm
 */
std::string Date::getString() const {
    std::ostringstream stream;
    stream << std::setfill('0');
    stream << std::setw(2) << _date.tm_mday << '/' << _date.tm_mon + 1 << '/' << std::setw(4)
           << _date.tm_year + 1900 << "  " << std::setw(2) << _date.tm_hour << ':' << _date.tm_min;
    return stream.str();
}

/**
 * @brief Sees if a date is valid or not (year, month, day in correct range), throwing adequate exception if not
 */
void Date::checkIfValid( int &day,  int &month,  int &year,  int &hours,  int &minutes) {
    if (day < 1 || day > getDaysInMonth(day, month, year, hours, minutes) || month < 1 || month > 12 || hours > 23 || minutes > 59) {
        throw InvalidDate(getString_err(day, month, year, hours, minutes) + " isn't a valid date!");
    }
}

/**
 * @brief checks if it is a leap year
 * @return true is leap year false otherwise
 */
bool Date::isLeapYear( int &year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

/**
 * @brief Searches for the number of days that a month has
 * @return The number of days of a specific month
 */
int Date::getDaysInMonth( int day,  int month,  int year,  int hours,  int minutes) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            throw InvalidDate(getString_err(day, month, year, hours, minutes) + " - this month doesn't exist!");
    }
}

/**
 * @brief Converts the input date in a string. Useful to show during error throws.
 * @return A string with the date in DD/MM/YYYY HH:mm
 */

std::string Date::getString_err( int &day,  int &month,  int &year,  int &hours,  int &minutes) {
    std::ostringstream stream;
    stream << std::setfill('0');
    stream << std::setw(2) << day << '/' << month << '/' << std::setw(4)
           << year << "  " << std::setw(2) << hours << ':' << minutes;
    return stream.str();
}


/**
 * @brief Constructor of the exception to be thrown when a date is invalid
 * @param error_msg the message to be shown
 */
Date::InvalidDate::InvalidDate(const std::string &error_msg) : std::invalid_argument(error_msg) {}




/**
 * @brief Adds two dates (or a date and a duration) together and returns the final value
 * @param d1 the other operand
 * @return A final date corresponding to the addition of two dates or a date and a duration
 */
Date Date::operator+(const Date &d1) const {
    Date result_date;
    tm temp{};
    temp.tm_mday = _date.tm_mday + d1.getDate().tm_mday;
    temp.tm_mon = _date.tm_mon + d1.getDate().tm_mon;
    temp.tm_year = _date.tm_year + d1.getDate().tm_year;
    temp.tm_hour = _date.tm_hour+ d1.getDate().tm_hour;
    temp.tm_min = _date.tm_min+ d1.getDate().tm_min;
    temp.tm_sec = 0;
    mktime(&temp);
    result_date._date = temp;
    return result_date;
}

/**
 * @brief subtracts two dates (or a date and a duration) together and returns the final value
 * @param d1 the other operand
 * @return A final date corresponding to the subtractions of two dates or a date and a duration
 */
Date Date::operator-(const Date &d1) const {
    Date result_date;
    tm temp{};
    temp.tm_mday = _date.tm_mday - d1.getDate().tm_mday;
    temp.tm_mon = _date.tm_mon - d1.getDate().tm_mon;
    temp.tm_year = _date.tm_year - d1.getDate().tm_year;
    temp.tm_hour = _date.tm_hour - d1.getDate().tm_hour;
    temp.tm_min = _date.tm_min - d1.getDate().tm_min;
    temp.tm_sec = 0;
    mktime(&temp);
    result_date._date = temp;
    return result_date;
}

/**
 * @brief Checks whether the two dates are the same
 * @param d2 the other operand
 * @return Whether a date is equal to another
 */
bool Date::operator==(const Date &d1) const {
    return _date.tm_mday == d1.getDate().tm_mday &&
            _date.tm_mon == d1.getDate().tm_mon &&
            _date.tm_year == d1.getDate().tm_year &&
            _date.tm_hour == d1.getDate().tm_hour &&
            _date.tm_min == d1.getDate().tm_min;
}


/**Checks whether the first date is before the second
 * Compares two dates and checks if the first one is before de second.
 * \return Whether the first date is before the second one*/
bool Date::operator<(const Date &d1) const {
    return _date.tm_year < d1.getDate().tm_year &&
            _date.tm_mon < d1.getDate().tm_mon &&
            _date.tm_mday < d1.getDate().tm_mday &&
            _date.tm_hour < d1.getDate().tm_hour &&
            _date.tm_min < d1.getDate().tm_min;
}


/**
 * @brief Checks whether the first date is after the second
 * @param d2 the other operand
 * @return Whether the first date is after the second one
 */
bool Date::operator>(const Date &d1) const {
    return _date.tm_year > d1.getDate().tm_year &&
           _date.tm_mon > d1.getDate().tm_mon &&
           _date.tm_mday > d1.getDate().tm_mday &&
           _date.tm_hour > d1.getDate().tm_hour &&
           _date.tm_min > d1.getDate().tm_min;
}

/**
 * @brief getter
 * @return weekdays
 */
std::vector<std::string> Date::getWeekdays() {
    return _weekdays;
}

/**
 * @brief default duration
 */
Duration::Duration() = default;

/**
 * @brief Sets the duration with the integer numbers provided
 * @param hours sets the hours
 * @param minutes sets the minutes
 */
Duration::Duration( int hours,  int minutes):Date() {
    _date.tm_hour = hours;
    _date.tm_min = minutes;

    _date.tm_mday = 0;
    _date.tm_mon = 0;
    _date.tm_year = 0;
    _date.tm_sec = 0;

    mktime(&_date);
}

/**
 * @brief Sets the duration with a given string
 * @param duration sets the duration
 */
Duration::Duration(const std::string &duration) : Date(){
    std::stringstream ss(duration); //HH:mm
    int hours, minutes;
    char sep{};
    ss >> hours >> sep >> minutes;
    _date.tm_hour = hours;
    _date.tm_min = minutes;

    _date.tm_mday = 0;
    _date.tm_mon = 0;
    _date.tm_year = 0;
    _date.tm_sec = 0;

    mktime(&_date);
}

/**
 * @brief Function to retrieve the tm structure with the duration
 * @return duration
 */
tm Duration::getDuration() const{
    return _date;
}

/**
 * @brief Uses the format: HHhmm. Useful to show during outputs
 * @return A string with the corresponding duration
 */
std::string Duration::getString() const {
    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(2) <<  _date.tm_mday * 24 + _date.tm_hour << "h" << _date.tm_min;
    return stream.str();
}

/**
 * @brief default availability
 */
Availability::Availability() = default;

/**
 * @brief Sets the availability with the weekday provided
 * @param weekday sets the weekday
 */
Availability::Availability(int weekday):Date(){
    checkIfValid(weekday);
    _date.tm_hour = 0;
    _date.tm_min = 0;

    _date.tm_mday = 0;
    _date.tm_mon = 0;
    _date.tm_year = 0;
    _date.tm_sec = 0;
    _date.tm_wday = weekday;
}

/**
 * @brief Sets the availability with a given string
 * @param weekday sets the weekday
 */
Availability::Availability(const std::string &weekday) : Date() {
    std::vector<std::string> weekdays = getWeekdays();
    auto it = std::find_if(weekdays.begin(), weekdays.end(), [weekday](const std::string &test){
        return test == weekday;
    });
    checkIfValid((it - weekdays.begin()));
    _date.tm_hour = 0;
    _date.tm_min = 0;
    _date.tm_mday = 0;
    _date.tm_mon = 0;
    _date.tm_year = 0;
    _date.tm_sec = 0;
    _date.tm_yday = 0;
    _date.tm_wday = (it - weekdays.begin());
}

/**
 * @brief Sees if a availability is valid or not (weekday in correct range), throwing adequate exception if not
 */
void Availability::checkIfValid(int day) {
    if(day < 0 || day > 6)
        throw InvalidDate(std::string(1,day)+ " isn't a valid weekday!");
}

/**
 * @brief Converts the saved availability in a string. Useful to show during output operations.
 * @return A string with the weekday
 */
std::string Availability::getString() const {
    return _weekdays.at(_date.tm_wday);
}

/**
 * @brief getter
 * @return weekday
 */
int Availability::getWeekday() const {
    return _date.tm_wday;
}

/**
 * @brief Checks whether the first weekday is before the second
 * @param d1 the other operand
 * @return Whether the first weekday is before the second one
 */
bool Availability::operator<(const Availability &d1) const {
    return _date.tm_wday < d1.getDate().tm_wday;
}

