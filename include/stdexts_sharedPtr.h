
#ifndef __STDEXTS_SHAREDPTR_H__
#define __STDEXTS_SHAREDPTR_H__

namespace stdexts
{

//////////////////////////////////////////////////////////////////
//// Shared Pointer Declarations
//////////////////////////////////////////////////////////////////

  template < class T >
  class sharedPtr
  {
    private:
      T* _obj;
      long unsigned int* _ptrCount;

    public:
      sharedPtr( T* = 0 );

      ~sharedPtr();
      sharedPtr( const sharedPtr<T>& );
      sharedPtr<T>& operator=( const sharedPtr<T>& );

      void set( T* );
      T* get() const { return _obj; }
      const T* getConst() const { return _obj; }
      long unsigned int count() const { return *_ptrCount; }
      void release();

      operator bool() const { return ( _obj ? true : false ); }
      T& operator *() const { return *_obj; }
      T* operator ->() const { return _obj; }
  };

//////////////////////////////////////////////////////////////////
//// Shared Pointer Function Definitions
//////////////////////////////////////////////////////////////////

  template < class T >
  sharedPtr<T>::sharedPtr( T* obj ) :
    _obj( obj ),
    _ptrCount( new long unsigned int( 1 ) )
  {
  }


  template < class T >
  sharedPtr<T>::~sharedPtr()
  {
    if ( _ptrCount )
    {
      --*_ptrCount;
      if ( *_ptrCount == 0 )
      {
        delete _obj;
        delete _ptrCount;
      }
    }
  }

  template < class T >
  sharedPtr<T>::sharedPtr( const sharedPtr<T>& p ) :
    _obj( p._obj ),
    _ptrCount( p._ptrCount )
  {
    if ( _ptrCount ) ++*_ptrCount;
  }

  template < class T >
  sharedPtr<T>& sharedPtr<T>::operator=( const sharedPtr<T>& p )
  {
    this->release();
    this->_obj = p._obj;
    this->_ptrCount = p._ptrCount;
    if ( _ptrCount ) ++*_ptrCount;
    return *this;
  }


  template < class T >
  void sharedPtr<T>::set( T* o ) 
  {
    this->release();
    this->_obj = o;
    this->_ptrCount = new long unsigned int( 1 );
  }

  template < class T >
  void sharedPtr<T>::release()
  {
    if ( _ptrCount )
    {
      --*_ptrCount;
      if ( *_ptrCount == 0 )
      {
        delete _obj;
        delete _ptrCount;
      }
      _obj = 0;
      _ptrCount = 0;
    }
  }



//////////////////////////////////////////////////////////////////
//// Shared Pointer Partial Specialization
//////////////////////////////////////////////////////////////////

  template < class T >
  class sharedPtr< T[] >
  {
    private:
      T* _obj;
      long unsigned int* _ptrCount;

    public:
      sharedPtr( T* = 0 );

      ~sharedPtr();
      sharedPtr( const sharedPtr<T[]>& );
      sharedPtr<T[]>& operator=( const sharedPtr<T[]>& );

      void set( T* );
      T* get() const { return _obj; }
      long unsigned int count() const { return ( _ptrCount ? *_ptrCount : 0 ); }
      void release();

      operator bool() const { return ( _obj ? true : false ); }
      T& operator *() const { return *_obj; }
      T* operator ->() const { return _obj; }
      T& operator []( unsigned int n ) const { return _obj[ n ]; }
  };

//////////////////////////////////////////////////////////////////
//// Shared Pointer Function Definitions
//////////////////////////////////////////////////////////////////

  template < class T >
  sharedPtr< T[] >::sharedPtr( T* obj ) :
    _obj( obj ),
    _ptrCount( new long unsigned int( 1 ) )
  {
  }


  template < class T >
  sharedPtr< T[] >::~sharedPtr()
  {
    if ( _ptrCount )
    {
      --(*_ptrCount);
      if ( *_ptrCount == 0 )
      {
        delete [] _obj;
        delete _ptrCount;
      }
    }
  }

  template < class T >
  sharedPtr< T[] >::sharedPtr( const sharedPtr< T[] >& p ) :
    _obj( p._obj ),
    _ptrCount( p._ptrCount )
  {
    if ( _ptrCount ) ++(*_ptrCount);
  }

  template < class T >
  sharedPtr< T[] >& sharedPtr< T[] >::operator=( const sharedPtr< T[] >& p )
  {
    this->release();
    this->_obj = p._obj;
    this->_ptrCount = p._ptrCount;
    if ( _ptrCount ) ++(*_ptrCount);
    return *this;
  }


  template < class T >
  void sharedPtr< T[] >::set( T* o ) 
  {
    this->release();
    this->_obj = o;
    this->_ptrCount = new long unsigned int( 1 );
  }

  template < class T >
  void sharedPtr< T[] >::release()
  {
    if ( _ptrCount )
    {
      --(*_ptrCount);
      if ( *_ptrCount == 0 )
      {
        delete [] _obj;
        delete _ptrCount;
      }
      _obj = 0;
      _ptrCount = 0;
    }
  }

}


#endif // __STDEXTS_SHAREDPTR_H__

