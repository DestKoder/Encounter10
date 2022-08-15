#pragma once
#include <iostream>

using namespace std;

class Date
{
	int day;
	int mounth;
	int year;

	public:
		Date(int day, int mounth, int year) {
			this->day = day;
			this->mounth = mounth;
			this->year = year;
		}
		Date(int day, int year) {
			this->day = day;
			this->mounth = 1;
			this->year = year;
		}
		Date(int day) {
			this->day = day;
			this->mounth = 1;
			this->year = 1970;
		}

		Date() {
			this->day = 1;
			this->mounth = 1;
			this->year = 1970;
		}

		Date(Date& date) {
			this->day = date.day;
			this->mounth = date.mounth;
			this->year = date.year;
		}

		Date(Date&& date) : Date(date) {
			date.day = 0;
			date.year = 0;
			date.mounth = 0;
		}

		void incrementDay();
		void incrementYear();
		void incrementMounth();
		
		void addDays(int days);
		void addYears(int years);
		void addMounth(int mounth);

		friend ostream& operator<<(ostream& os, const Date& date) {
			os << "Date: " << date.day << "." << date.mounth << "." << date.year;
			return os;
		}

		friend istream& operator>>(istream& is, Date& date) {
			cout << "День: ";
			is >> date.day;
			cout << "Месяц: ";
			is >> date.mounth;
			cout << "Год: ";
			is >> date.year;

			return is;
		}
		
		Date& operator++();
		Date& operator--();
		Date& operator+=(int days);
		Date& operator-=(int days);

		bool operator==(const Date& date) const;
		bool operator!=(const Date& date) const;
		bool operator>(const Date& date) const;
		bool operator<(const Date& date) const;

		Date& operator=(const Date& date);
		Date& operator()(int day, int mounth, int year);
};

