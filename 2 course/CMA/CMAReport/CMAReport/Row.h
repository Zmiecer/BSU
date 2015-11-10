#ifndef ROW_H
#define ROW_H

#include <iostream>

class Row
{
private:
	double *_row;
	unsigned _size;

public:
	Row();
	Row(unsigned, double = 0.0);
	Row(const Row &);
	~Row();

	unsigned size() const;

	void resize(unsigned = 1, double = 0.0);

	double &operator[](unsigned);
	const double &operator[](unsigned) const;

	friend std::istream &operator>>(std::istream &, Row &);
	friend std::ostream &operator<<(std::ostream &, const Row &);

	bool operator==(const Row &) const;
	bool operator!=(const Row &) const;

	const Row &operator=(const Row &);

	//CMA functions
	double sum() const;
};

#endif