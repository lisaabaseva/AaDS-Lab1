#include "BrokenLine.h"

broken_line::broken_line(): _p(NULL), _size(0) {}

broken_line::broken_line(unsigned int size)
{
	_size = size;
	_p = new Point[_size];
}

broken_line::broken_line(const broken_line& rhs)
{
	_size = rhs._size;
	_p = new Point[_size];

	for (unsigned int i = 0; i < _size; i++) {
		_p[i] = rhs._p[i];
	}
}

void broken_line::swap(broken_line& rhs)
{
	std::swap(_size, rhs._size);
	std::swap(_p, rhs._p);
}

Point& broken_line::operator[](unsigned int index)
{
	if (_size <= index)
		throw std::logic_error("error");
	return _p[index];
}

Point broken_line::operator[](unsigned int index) const
{
	if (_size <= index)
		throw std::logic_error("error");
	return _p[index];
}

broken_line broken_line::operator+(const broken_line& rhs)
{
	//if (_p[_size - 1]._x != rhs._p[0]._x && _p[_size - 1]._y != rhs._p[0]._y || _p[]._x != rhs._p[0]._x && _p[_size - 1]._y != rhs._p[0]._y)
	//	throw std::logic_error("error");
	broken_line tmp(_size + rhs._size - 1);
	for (unsigned int i = 0; i < _size; i++) {
		tmp._p[i] = _p[i];
	}
	for (unsigned int i = _size; i < _size + rhs._size; i++) {
		tmp._p[i] = rhs._p[i-_size];
	}
	return tmp;
}

broken_line broken_line::operator+(const Point& rhs)
{
	return broken_line();
}



broken_line::~broken_line()
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

std::istream& operator>>(std::istream& in, broken_line& lhs)
{
	for (unsigned int i = 0; i < lhs._size; i++) {
		in >> lhs._p[i];
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const broken_line& lhs)
{
	for (unsigned int i = 0; i < lhs._size; i++) {
		out << i << "	point is: "<< lhs._p[i];
		out << '\n';
	}

	return out;
}
