
#ifndef __AUTOPTR_H__
#define __AUTOPTR_H__

#include <utility>

namespace stdexts
{

//////////////////////////////////////////////////////////////////
//// Auto Pointer Declaration
//////////////////////////////////////////////////////////////////

  template < class T >
  class autoPtr
  {
    private:
      T* _obj;

    public:
      autoPtr( T* = 0 );

      ~autoPtr();
      autoPtr( autoPtr<T>& );
      autoPtr( autoPtr<T>&& ) noexcept;
      autoPtr<T>& operator=( autoPtr<T>& );
      autoPtr<T>& operator=( T* t ) { set(t); return *this; }

      T* get() const { return _obj; }
      void set( T* );
      void release();

      T& operator*() const { return *_obj; }
      T* operator->() const { return _obj; }

      operator bool() const { return ( _obj != 0 ); }
  };



//////////////////////////////////////////////////////////////////
//// Auto Pointer Function Definitions
//////////////////////////////////////////////////////////////////


  template < class T >
  autoPtr<T>::autoPtr( T* obj ) :
    _obj( obj )
  { }

  template < class T >
  autoPtr<T>::~autoPtr()
  {
    if ( _obj )
      delete _obj;
  }

  template < class T >
  autoPtr<T>::autoPtr( autoPtr<T>& p ) :
    _obj( p._obj )
  {
    p._obj = 0;
  }

  template < class T >
  autoPtr<T>::autoPtr( autoPtr<T>&& p ) noexcept :
    _obj( std::move(p._obj) )
  {
    p._obj = 0;
  }

  template < class T >
  autoPtr<T>& autoPtr<T>::operator=( autoPtr<T>& p )
  {
    this->release();

    this->_obj = p._obj;
    p._obj = 0;
    return *this;
  }


  template < class T >
  void autoPtr<T>::set( T* o )
  {
    this->release();
    this->_obj = o;
  }

  template < class T >
  void autoPtr<T>::release()
  {
    if ( _obj )
    {
      delete _obj;
      _obj = 0;
    }
  }



//////////////////////////////////////////////////////////////////
//// Auto Pointer Partial Spec. Declaration
//////////////////////////////////////////////////////////////////


  template < class T >
  class autoPtr< T[] >
  {
    private:
      T* _objArray;

    public:
      autoPtr( T* = 0 );

      ~autoPtr();
      autoPtr( autoPtr<T[]>& );
      autoPtr<T[]>& operator=( autoPtr<T[]>& );

      void release();
      T* get() const { return _objArray; }

      T& operator*() const { return *_objArray; }
      T* operator->() const { return _objArray; }
      T& operator[]( int num ) const { return _objArray[num]; }

      operator bool() const { return ( _objArray == 0 ? false : true ); }
  };



//////////////////////////////////////////////////////////////////
//// Auto Pointer Partial Spec. Function Definitions
//////////////////////////////////////////////////////////////////



  template < class T >
  autoPtr<T[]>::autoPtr( T* objArray ) :
    _objArray( objArray )
  { }

  template < class T >
  autoPtr<T[]>::~autoPtr()
  {
    if ( _objArray )
      delete [] _objArray;
  }

  template < class T >
  autoPtr<T[]>::autoPtr( autoPtr<T[]>& p ) :
    _objArray( p._objArray )
  {
    p._objArray = 0;
  }

  template < class T >
  autoPtr<T[]>& autoPtr<T[]>::operator=( autoPtr<T[]>& p )
  {
    delete [] this->_objArray;
    this->_objArray = p._objArray;
    p._objArray = 0;
    return *this;
  }

  template < class T >
  void autoPtr<T[]>::release()
  {
    if ( _objArray )
    {
      delete [] _objArray;
      _objArray = 0;
    }
  }

}

#endif // __AUTOPTR_H__

