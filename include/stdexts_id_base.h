
#ifndef __STDEXTS__ID_BASE_H__
#define __STDEXTS__ID_BASE_H__

namespace stdexts
{

  template < class T >
  class id_base
  {
    private: 
      static unsigned long int _currentId;
      static unsigned long int _counter;
      unsigned long int _id;
      unsigned long int _num;

    protected:
      id_base();

      id_base( const id_base& );
      id_base& operator= ( const id_base& );

      ~id_base();

    public:

      const unsigned long int& id() const { return _id; }
      const unsigned long int& number() const { return _num; }

      static const unsigned long int& currentId() { return id_base::_currentId; }
      static const unsigned long int& currentCounter() { return id_base::_counter; }

  };


  template < class T >
  unsigned long int id_base< T >::_currentId = 0;
  template < class T >
  unsigned long int id_base< T >::_counter = 0;


  template < class T >
  id_base< T >::id_base() :
    _id( ++_currentId ),
    _num( ++_counter )
  {
  }

  template < class T >
  id_base< T >::id_base( const id_base& obj ) : 
    _id( obj._id ),
    _num( ++_counter )
  {
  }

  template < class T >
  id_base< T >& id_base< T >::operator= ( const id_base& obj )
  {
    _id = obj._id;   
    return *this;
  }

  template < class T >
  id_base< T >::~id_base()
  {
    --_counter;
  }

}

#endif // __STDEXTS__ID_BASE_H__

