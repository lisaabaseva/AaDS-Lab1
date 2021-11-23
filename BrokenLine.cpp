#include "BrokenLine.h"

BrokenLine::BrokenLine(): _p(NULL), _size(0) {}

BrokenLine::BrokenLine(unsigned int size)
{
	_size = size;
	_p = new Point[_size];
}

BrokenLine::BrokenLine(const BrokenLine& rhs)
{
	_size = rhs._size;
	_p = new Point[_size];

	for (unsigned int i = 0; i < _size; i++) {
		_p[i] = rhs._p[i];
	}
}

void BrokenLine::Swap(BrokenLine& rhs)
{
	std::swap(_size, rhs._size);
	std::swap(_p, rhs._p);
}

Point& BrokenLine::operator[](unsigned int index)
{
	if (_p == nullptr) throw "Line is empty";
	if ((index >= _size) || (index < 0)) throw "Invalid index";
	return _p[index];
}

Point BrokenLine::operator[](unsigned int index) const
{
	if (_p == nullptr) throw "Line is empty";
	if ((index >= _size) || (index < 0)) throw "Invalid index";
	return _p[index];
}

BrokenLine BrokenLine::operator+(const BrokenLine& rhs)
{
	BrokenLine tmp(_size + rhs._size);

	for (unsigned int i = 0; i < _size; i++) {
		tmp._p[i] = _p[i];
	}
	for (unsigned int i = 0; i < _size + rhs._size; i++) {
		tmp._p[i + _size] = rhs._p[i];
	}

	return tmp;
}

BrokenLine& BrokenLine::operator=(const BrokenLine& rhs)
{
	BrokenLine tmp(rhs);
	Swap(tmp);
	return *this;
}

bool BrokenLine::operator==(const BrokenLine& rhs)
{
	if (_size!=rhs._size) //сравниваем размеры массивов объектов
	{
		std::cout << "The curves have different lengths\n";
		return false;
	}

		for (int i = 0; i < _size; i++)
		{
			if ((_p[i]._x != rhs._p[i]._x)||(_p[i]._y != rhs._p[i]._y))
			{
				std::cout << "Different values\n";
				return false;
			}
		}
	return true;
}

bool BrokenLine::operator!=(const BrokenLine& rhs)
{
	return !this->operator==(rhs);
}

void BrokenLine::AddToHead(const Point& point)
{
	_size += 1;
	Point* tmp = new Point[_size];
	tmp[0] = point;
	for (size_t i = 1; i < _size; i++)
	{
		tmp[i] = _p[i - 1];
	}
	if (_p != NULL) delete[] _p;
	_p = tmp;
}

void BrokenLine::AddToEnd(const Point& point)
{
	_size += 1;
	Point* tmp = new Point[_size];
	for (size_t i = 0; i < _size - 1; i++)
	{
		tmp[i] = _p[i];
	}
	tmp[_size - 1] = point;
	if (_p != NULL) delete[] _p;
	_p = tmp;
}

BrokenLine BrokenLine::operator+(const Point& rhs)
{
	BrokenLine tmp;
	tmp = *this;
	tmp.AddToEnd(rhs);

	return tmp;
}

BrokenLine Point::operator+(const BrokenLine& rhs)
{
	BrokenLine tmp;
	tmp = rhs;
	tmp.AddToHead(*this);
	return tmp;
}

double BrokenLine::SizeLine(const BrokenLine& rhs) const
{
	if (_p == nullptr) throw "Line is empty";
	double res = 0;
	for (int i = 0; i < _size-1; i++)
	{
		res += sqrt(pow(_p[i + 1]._x - _p[i]._x, 2) + (pow(_p[i + 1]._y - _p[i]._y, 2)));
	}
	return res;
}    

BrokenLine::~BrokenLine()
{
	delete[] _p;
}

std::istream& operator>>(std::istream& in, Point& lhs)
{
	std::cout << "Input x: ";
	in >> lhs._x;
	std::cout << "Input y: ";
	in >> lhs._y;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Point& lhs)
{
	out << "\nx - " << lhs._x;
	out << "\ny - " << lhs._y;
	return out;
}

std::istream& operator>>(std::istream& in, BrokenLine& lhs)
{
	for (unsigned int i = 0; i < lhs._size; i++) {
		in >> lhs._p[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const BrokenLine& lhs)
{
	for (unsigned int i = 0; i < lhs._size; i++) {
		out << i << "	point is: "<< lhs._p[i];
		out << '\n';
	}

	return out;
}
