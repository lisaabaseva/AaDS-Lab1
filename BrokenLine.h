#pragma once
#include <iostream>
#include <utility>

/*
*	ƒобавить:
* -1- ѕерегрузка операторов сравнени€ (==, !=)
*/

struct Point
{
	double _x, _y;
	friend std::istream& operator>>(std::istream& in, Point& lhs);
	friend std::ostream& operator<<(std::ostream& out, const Point& lhs);
};

class broken_line {
private:
	Point* _p;
	unsigned _size;
public:
	broken_line();
	broken_line(unsigned int size);
	broken_line(const broken_line& rhs);

	void swap(broken_line& rhs);

	// по ссылке дл€ записи данных, константый дл€ чтени€
	Point& operator[](unsigned int index);
	Point operator[](unsigned int index) const;

	broken_line operator+(const broken_line& rhs);
	broken_line operator+(const Point& rhs);

	friend std::istream& operator>>(std::istream& in, broken_line& lhs);
	friend std::ostream& operator<<(std::ostream& out, const broken_line& lhs);

	~broken_line();

};