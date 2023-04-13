#include <iostream>
#include <fstream>


using namespace std;


#ifndef VECTOR_H_DEF_
#define VECTOR_H_DEF_


template <typename T>
class Vector
{
	public:
		Vector(int Vindex = 0);
		Vector (const T*, unsigned s, int Vindex = 0);
		Vector (const Vector&);
		~Vector ();

		Vector& operator= (const Vector&);

		template <typename OT>
		friend ostream& operator<< (ostream&, const Vector<OT>&);
		template <typename OT>
		friend ostream& operator<< (ostream&, const Vector<OT>*);

		T& operator[] (int Vindex);
		const T& operator[] (int Vindex) const;

		Vector operator() (int Vfirst, int Vlast) const;

		Vector& operator+= (const T&);
		Vector& operator+= (const Vector&);

		unsigned Length() const{return _length;};

		void Remove (const int Vindex);
		void Remove (int Vfirst, int Vlast);
		void Remove ();

		void Insert (const T&, int Vindex);
		void Insert (const T&);

        void write(ofstream&) const;
        void  read(ifstream&);

  private:
        T*       _a;
        unsigned _size;
        unsigned _length;
        int      _zero;


};


#endif // VECTOR_H_DEF_