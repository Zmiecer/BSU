#include <iostream>

using namespace std;

const int n=100;

template <class T> 
class vector
{
public:
	T* arr;
	int size;

	vector()
	{
		size=0;
		arr = new T;
	}

	vector (const vector<T>& vi)
	{
		size=vi.size();
		p= new T size;
		for (i=0; i<size; i++)
			arr[i]=vi.arr[i];
	}

	vector (int n, const T& val = T())
	{
		size=n;
		for (int i=0; i<size; i++)
			arr[i]=val;
	}

	/*vector (T* begin, T* end)
	{
		for (int i=0; i<n; i++)
			arr[i]=T[i];
	}*/

	T* begin()
	{
		return &arr[0];
	}

	T* end()
	{
		return &arr[size-1];
	}

	T front()
	{
		return arr[0];
	}

	T back()
	{
		return arr[size-1];
	}

	T at(int n)
	{
		if (n<size)
			return arr[n];
		else cout << "Error" << endl;
	}

	T& operator[] (int i)
	{
		if(i < 0)
			return arr[0];
        if(i >= size)
			return arr[size-1];
		return arr[i];
	}

	const T& operator[](int i) const
	{
		if(i < 0)
			return arr[0];
		if(i >= size)
			return arr[size-1];
		return arr[i];
	}


	virtual ~vector()
	{
		delete[] arr;
	}

	void push_back (T x)
	{
		//if (size == n) arr = new T;
		arr[size]=x;
		size++;
	}

	int max_size ()
	{
		return n;
	}



	vector& operator =( const vector &vu )
	{
		for (int i=0; i<vu.size; i++)
			arr[i]=vu[i];
		size=vu.size;
		return *this;
	}

};












void main()
{
	vector<int> vu;
	vector<int> fu;
	vu.push_back(10);
	vu.push_back(20);
	vu.push_back(30);
	vu[1]=15;

	cout << vu.front() << " " << vu[1] << " " << vu.back() << " " << endl;

	fu = vu;
	fu[2]=25;
	cout << fu.front() << " " << fu[1] << " " << fu.back() << " " << endl;

}