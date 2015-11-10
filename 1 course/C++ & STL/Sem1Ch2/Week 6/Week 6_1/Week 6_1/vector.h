#include  <iostream>

using namespace std;

const int j=100;

template <class T> class vector
{	
public:
	T* p;
	int size;

	typedef T* iterator;
	explicit vector(int n);
	vector(const vector<T>& v);
	vector(const T* a, int n);
	virtual ~vector() {delete[] p;}
	iterator begin(){ return p;}
	iterator end(){ return p + size;}
	vector<T>& operator=(const vector<T>& v);

	T front() { return p[0]; }

	T back() { return p[size-1]; }

	T at(int n)
	{
		if (n<size)
			return p[n];
		else cout << "Error" << endl;
	}

	T& operator[] (int i)
	{
		if(i >= 0 && i < size) return p[i];
		else 
		{
			size+=size;
			p = new T[size];
			return p[i];
		}
	}

	const T& operator[](int i) const
	{
		if(i >= 0 && i < size) return p[i];
		else 
		{
			size+=size;
			p = new T[size];
			return p[i];
		}

	}

	/*void push_back (T x)
	{
		if (p==0) p[0]=x;
		p[size-1]=x;
	}*/

	int max_size () { return j; }

};


template <class T>
	vector<T>::vector(int n = 100): size(n)
	{
		p = new T[size+1];
	}
	template <class T>
	vector<T>::vector(const T a[], int n)
	{
		size = n;	   
		p = new T[size];
		for (int i = 0; i < size; ++i)  
			p[i] = a[i];
	}
	template <class T>
	vector<T>::vector(const vector<T>& v)
	{
		size = v.size;
		p = new T[size];
		for (int i = 0; i < size; ++i)
			p[i] = v.p[i];
	}
	template <class T>
	vector<T>& vector<T>::operator=(const vector<T>& v)
	{
		for (int i = 0; i < size; ++i)
			p[i] = v.p[i];
		size=v.size;
		return *this;
	}