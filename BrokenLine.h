#pragma once
#include <iostream>
#include <utility>
#include <cmath>

class BrokenLine;

class Point
{
public:
	double _x, _y;
	BrokenLine operator+(const BrokenLine& rhs);//вставка в начало
	Point(double x, double y) : _x(x), _y(y) {}
	Point() : _x(0), _y(0) {}
};

class BrokenLine {
private:
	Point* _p;
	unsigned _size;
public:
	BrokenLine();
	BrokenLine(unsigned int size);
	BrokenLine(const BrokenLine& rhs);

	unsigned GetSize() const {
		return _size;
	}

	void SetSize(unsigned size) {
		_size = size;
		_p = new Point[_size];
	}

	void Swap(BrokenLine& rhs);

	// по ссылке для записи данных, константый для чтения
	Point& operator[](unsigned int index);
	Point operator[](unsigned int index) const;

	BrokenLine operator+(const BrokenLine& rhs); //конкатенация
	BrokenLine operator+(const Point& rhs); //вставка в конец

	void AddToHead(const Point& point);
	void AddToEnd(const Point& point);


	BrokenLine& operator=(const BrokenLine& rhs);

	bool operator==(const BrokenLine& rhs);

	bool operator!=(const BrokenLine& rhs);

	double SizeLine(const BrokenLine& rhs) const;

	friend std::istream& operator>>(std::istream& in, BrokenLine& lhs);
	friend std::ostream& operator<<(std::ostream& out, const BrokenLine& lhs);

	~BrokenLine();

};
