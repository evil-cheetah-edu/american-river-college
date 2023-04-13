#include "Vector.h"


using namespace std;


///-------------- Constructors --------------///
template <typename T>
Vector<T>::Vector(int Vindex)
{
    _a      = NULL;
    _size   = 0;
    _length = 0;
    _zero   = Vindex;
}


template <typename T>
Vector<T>::Vector(const T* a, unsigned s, int Vindex)
{
    _a      = NULL;
    _size   = 0;
    _length = 0;
    _zero   = Vindex;
    
    for(unsigned i = 0; i < s; ++i)
        operator+=( a[i] );
}


template <typename T>
Vector<T>::Vector(const Vector& v)
{
    _a      = NULL;
    _size   = 0;
    _length = 0;
    _zero   = v._zero;

    for (unsigned i = 0; i < v._length; ++i)
        operator+=( v._a[i] );
}


///-------------- Destructor --------------///
template <typename T>
Vector<T>::~Vector()
{
    delete [] _a;
}


///-------------- Operators --------------///
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if (this == &v)
        return *this;

    delete [] _a;

    _a      = NULL;
    _size   = 0;
    _length = 0;
    _zero   = v._zero;

    for(unsigned i = 0; i < v._length; ++i)
        operator+=( v._a[i] );

    return *this;
}


template <typename OT>
ostream& operator<<(ostream& os, const Vector<OT>& v)
{
    if (v._length != 0)
    {
        os << v._a[0];

        for (unsigned i = 1; i < v._length; ++i)
            os << ", " << v._a[i];

        return os;
    }
    else
    {
        throw unsigned(203);
    }
}

template <typename OT>
ostream& operator<<(ostream& os, const Vector<OT>* v)
{
    if ((*v)._length != 0)
    {
        os << (*v);
        return os;
    }
    else
    {
        throw unsigned(204);
    }
}


template <typename T>
T& Vector<T>::operator[](int Vindex)
{
    int Aindex = Vindex - _zero;

    if ( Aindex < 0 || _length < Aindex )
        throw unsigned(401);

    return _a[Aindex];
}


template <typename T>
const T& Vector<T>::operator[](int Vindex) const
{
    int Aindex = Vindex - _zero;
    
    if ( Aindex < 0 || _length < Aindex )
        throw unsigned(402);

    return _a[Aindex];
}


template <typename T>
Vector<T> Vector<T>::operator()(int Vfirst, int Vlast) const
{
    if ( (Vlast - Vfirst) < 0 )
        throw unsigned(403);

    int Afirst  = Vfirst - _zero;
    int Alast   = Vlast  - _zero;

    Vector<T> temp(_zero);

    for(unsigned i = Afirst; i < Alast; ++i)
        temp += _a[i];

    return temp;
}


template <typename T>
Vector<T>& Vector<T>::operator+=(const T& item)
{
    if (_length >= _size)
    {
        _size   = (_size == 0) ? 1 : (_size * 2);
        
        T* temp = new T[_size];

        for (unsigned i = 0; i < _length; ++i)
            temp[i] = _a[i];

        delete [] _a;
        _a = temp;
    }

    _a[_length++] = item;

    return *this;
}


template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector& v)
{
    for (unsigned i = 0; i < v._length; ++i)
        operator+=( v._a[i] );

    return *this;
}


///--------------Remove/Insert--------------///
template <typename T>
void Vector<T>::Remove(const int Vindex)
{
    int Aindex = Vindex - _zero;

    if ( Aindex < 0 || _length < Aindex )
        throw unsigned(404);

    Vector<T> temp(_zero);
    for (unsigned i = 0; i < _length; ++i)
        if (i != Aindex)
            temp += _a[i];

    *this = temp;
}


template <typename T>
void Vector<T>::Remove(int Vfirst, int Vlast)
{
    for (int i = Vfirst; i < Vlast; ++i)
        Remove(Vfirst);
}


template <typename T>
void Vector<T>::Remove()
{
    Remove(_zero);
}


template <typename T>
void Vector<T>::Insert(const T& item, int Vindex)
{
    int Aindex = Vindex - _zero;

    if (Aindex < 0 || Aindex >= _length)
        throw unsigned(405);

    Vector<T> temp(_zero);
    for (unsigned i=0; i<_length; ++i)
    {
        if (i == Aindex)
            temp += item;
    
        temp += _a[i];
    }

    *this = temp;
}


template <typename T>
void Vector<T>::Insert(const T& item)
{
    Insert(item, _zero);
}


///-------------- Read/Write --------------///
template <typename T>
void Vector<T>::write( ofstream& ofs ) const
{
    if ( !ofs )
        throw unsigned(500);

    ofs.write(reinterpret_cast<const char*>(&_zero),    sizeof(_zero));
    ofs.write(reinterpret_cast<const char*>(&_length),  sizeof(_length));
    ofs.write(reinterpret_cast<const char*>(_a),        sizeof(T)*_length);
}


template <typename T>
void  Vector<T>::read(ifstream& ifs)
{
    if ( !ifs )
        throw unsigned(501);

    ifs.read(reinterpret_cast<char*>(&_zero),   sizeof(_zero));
    ifs.read(reinterpret_cast<char*>(&_length), sizeof(_length));

    T* temp = new T[_length];
    ifs.read(reinterpret_cast<char*>(temp),     sizeof(T)*_length);
    
    *this = Vector<T>(temp, _length, _zero);
    delete [] temp;
}