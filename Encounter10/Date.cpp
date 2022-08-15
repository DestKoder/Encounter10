#include "Date.h"


void Date::incrementDay() {
	this->day+ 1 == 31 ? this->day = 1 : this->day+=1;
}

void Date::incrementMounth() {
	this->mounth + 1 == 13 ? this->mounth = 1 : this->mounth += 1;
}

void Date::incrementYear() {
	this->year++;
}

void Date::addDays(int days) {
	this->day + days > 31 ? this->day = days - 31 : this->day += days;
}

void Date::addMounth(int mounths) {
	this->mounth += mounth;
}

void Date::addYears(int years) {
	this->year += years;
}

Date& Date::operator++() {
	this->incrementDay();
	return *this;
}

Date& Date::operator--() {
	if (this->day - 1 <= 0) {
		if (this->mounth - 1 <= 0) {
			this->year--;
			this->mounth = 12;
			this->day = 31;
		}
		else {
			this->mounth -= 1;
			this->day = 31;
		}
	}
	else {
		this->day -= 1;
	}

	return *this;
}

Date& Date::operator+=(int days) {
	this->addDays(days);
	return *this;
}

Date& Date::operator-=(int days) {
	if (this->day - days <= 0) {
		if (this->mounth - 1 <= 0) {
			this->year--;
			this->mounth = 12;
			this->day -= days;
		}
		else {
			this->mounth -= 1;
			this->day -= days;
		}
	}
	else {
		this->day -= days;
	}

	return *this;
}

bool Date::operator==(const Date& date) const {
	return date.day == day && date.mounth == mounth && date.year == year;
}

bool Date::operator!=(const Date& date) const {
	return date.day != day || date.mounth != mounth || date.year != year;
}

bool Date::operator>(const Date& date) const {
	return date.day > day || date.mounth > mounth || date.year > year;
}

bool Date::operator<(const Date& date) const {
	return date.day < day || date.mounth < mounth || date.year < year;
}

Date& Date::operator=(const Date& date) {
	this->day = date.day;
	this->mounth = date.mounth;
	this->year = date.year;

	return *this;
}

Date& Date::operator()(int day, int mounth, int year) {
	this->day = day;
	this->mounth = mounth;
	this->year = year;

	return *this;
}