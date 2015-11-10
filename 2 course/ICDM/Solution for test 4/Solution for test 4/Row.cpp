#include "Row.h"
#include <iostream>

// ����������� ��-���������
Row::Row() :
// ������������� ������ ������ ��-���������
_size(1)
{
	// �������� ������ ��� ������
	_row = new double[_size];

	// ��������� ������ �������� ����������
	for (unsigned i = 0; i < _size; ++i)
		_row[i] = 0.0;
}

// ����������� � �����������
// size - ������ ������
// fill - ��������, ������� ���������� ����� ��������� ������ (��-��������� 0)
Row::Row(unsigned size, double fill) :
// ������������� ������ ������
_size(size)
{
	// �������� ������ ��� ������
	_row = new double[_size];

	// ��������� ������ ��������� ����������
	for (unsigned i = 0; i < _size; ++i)
		_row[i] = fill;
}

// ����������� �����������
Row::Row(const Row &original) :
// ������������� ������ ������
_size(original._size)
{
	// �������� ������ ��� ������
	_row = new double[_size];

	// �������������� �������� ����� ������
	// ���������� ������ original
	for (unsigned i = 0; i < _size; ++i)
		_row[i] = original._row[i];
}

// ����������
Row::~Row()
{
	// ����������� ������, ��������� ��� ������
	delete[] _row;
}

// �������, ������������ ������ ������
unsigned Row::size() const
{
	// ���������� ������ ������
	return _size;
}

// ������� ��������� ������� ������
void Row::resize(unsigned size, double fill)
{
	// ���� �������� ������ ������ ��
	// ��������� � ��������
	if (_size != size)
	{
		// ������������� ������ ������
		// ������ ���������
		_size = size;

		// ����������� ������ ��-��� �������� ������
		delete[] _row;

		// �������� ������ ��� ������ ������ �������
		_row = new double[_size];
	}

	// ��������� ������ ��������� ����������
	for (unsigned i = 0; i < _size; ++i)
		_row[i] = fill;
}

// ������������� �������� ������ �������� �� �������
double &Row::operator[](unsigned index)
{
	// ���������� ������ �� �������� ��������
	return _row[index];
}

// ������������� �������� ������ �������� �� ������� (�����������)
const double &Row::operator[](unsigned index) const
{
	// ���������� ����������� ������ �� �������� ��������
	return _row[index];
}

// ������������� �������� ������ �� ������ input
std::istream &operator>>(std::istream &input, Row &rhs)
{
	// ��� �� ��������� ��������� ������
	for (unsigned i = 0; i < rhs._size; ++i)
		// ������� �������� �� ������
		// input � ��������� �������
		// ������
		input >> rhs._row[i];

	// ���������� ������ �� ����� input
	return input;
}

// ������������� �������� ����� � ����� output
std::ostream &operator<<(std::ostream &output, const Row &rhs)
{
	// ��� �� ��������� ��������� ������
	for (unsigned i = 0; i < rhs._size; ++i)
	{
		// ���� ��������� �������
		// ������������� - �������
		// � ����� output ���� "�����"
		if (rhs._row[i] < 0.0)
			output << '-';
		// ����� - ������� ������
		else
			output << ' ';

		// ������� ������ �������� � ����� output
		output << (rhs._row[i] < 0.0 ? -rhs._row[i] : rhs._row[i]) << "\t";
	}

	// ���������� ������ �� ����� output
	return output;
}

// ������������� �������� ��������� �����
bool Row::operator==(const Row &rhs) const
{
	// ���� ������� ����� �� ���������, �� ������ �������� �� �����
	if (_size != rhs._size)
		return false;

	// ���� �� �����-���� �������� ����� �����������,
	// �� ������ �� �����
	for (unsigned i = 0; i < _size; ++i)
		if (_row[i] != rhs._row[i])
			return false;

	// ���� ��� �������, ��� � ��� �������� ����� ���������,
	// �� ������ �����
	return true;
}

// ������������� �������� ����������� �����
bool Row::operator!=(const Row &rhs) const
{
	// ������������ ��� ������������� �������� ��������� �����
	return !(*this == rhs);
}

// ������������� �������� ������������ ����� ������ ������
const Row &Row::operator=(const Row &rhs)
{
	// �������� �� ����������������
	if (this != &rhs)
	{
		// ���� ������� ����� �� ���������
		if (_size != rhs._size)
		{
			// ������� ������ ��-��� ������ ������
			delete[] _row;

			// ������������� ����� ������
			_size = rhs._size;

			// �������� ������ ��� ����� ������
			_row = new double[_size];
		}

		// ��������� ����� ������ ���������� ��
		// �������������
		for (unsigned i = 0; i < _size; ++i)
			_row[i] = rhs._row[i];
	}

	return *this;
}

// Returns the sum of the elements of Row
double Row::sum() const
{
	double s = 0.0;
	for (unsigned i = 0; i < _size; ++i)
		s += abs(_row[i]);
	return s;
}