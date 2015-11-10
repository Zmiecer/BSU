#ifndef MATRIX_H
#define MATRIX_H

#include "Row.h"
#include <iostream>
#include <vector>
#include <algorithm> 

//using namespace std;

class Matrix
{
	template< typename T >
	friend void swap(T &, T &);

private:
	Row *_matrix;
	unsigned _cols;
	unsigned _rows;

public:
	Matrix(unsigned = 1, unsigned = 1, double = 0.0);
	Matrix(const Matrix &);
	~Matrix();

	void resize(unsigned = 1, unsigned = 1, double = 0.0);

	double det() const;
	Matrix inverse() const;
	int rang() const;
	Matrix transpose() const;

	Row &operator[](unsigned);
	const Row &operator[](unsigned) const;

	friend std::istream &operator>>(std::istream &, Matrix &);
	friend std::ostream &operator<<(std::ostream &, const Matrix &);

	Matrix operator+(const Matrix &) const;
	const Matrix &operator+=(const Matrix &);

	Matrix operator-(const Matrix &) const;
	const Matrix &operator-=(const Matrix &);

	Matrix operator*(const Matrix &) const;
	const Matrix &operator*=(const Matrix &);
	friend Matrix operator*(const Matrix &, const double);
	friend const Matrix &operator*=(Matrix &, const double);
	friend Matrix operator*(const double, const Matrix &);

	Matrix operator/(const Matrix &) const;
	const Matrix &operator/=(const Matrix &);
	friend Matrix operator/(const Matrix &, const double);
	friend const Matrix &operator/=(Matrix &, const double);
	friend Matrix operator/(const double, const Matrix &);

	Matrix operator^(const int) const;
	const Matrix &operator^=(const int);

	bool operator==(const Matrix &) const;
	bool operator!=(const Matrix &) const;

	const Matrix &operator=(const Matrix &);

	//CMA functions

	// ���������� ������ ��������� �����
	double norm() const;
	// ������� ������������� �� �������� �������
	int maxsize() const;
	// �������
	void clear(); 
};

#endif