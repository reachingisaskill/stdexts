
#ifndef __STDEXTS_LIST_TYPES_H__
#define __STDEXTS_LIST_TYPES_H__

#include "stdexts_linkedList.h"

namespace stdexts
{


  template < class C >
  struct triplet
  {
    triplet( C c1, C c2, C c3 ) : first( c1 ), second( c2 ), third( c3 ) {}
    C first;
    C second;
    C third;
  };

  template < class C >
  triplet< C > make_triplet( C t1, C t2, C t3 )
  {
    triplet< C > newTriplet( t1, t2, t3 );
    return newTriplet;
  }


  template < class C >
  class fifo
  {
    private:
      stdexts::sharedPtr< stdexts::linkedList< C > > _list;

    public:
      fifo();
      fifo( C );

      fifo& operator,  ( C );
      fifo& operator<< ( C );
      fifo& operator<< ( fifo );

      C operator* ();
      operator bool () const { return ( *_list ); }
  };

////////////////////////////////////////

  template < class C >
  class dll
  {
    private:
      stdexts::sharedPtr< stdexts::linkedList< C > > _list;

    public:
      dll();
      dll( C );

      dll& operator,  ( C );
      dll& operator<< ( C );
      dll& operator+= ( dll );

      C pop_front();
      C pop_back();
      void push_front( C );
      void push_back( C );

      unsigned int count() const { return _list->count(); }

      const typename stdexts::linkedList< C >::linkItem* first() const { return _list->first(); }
      const typename stdexts::linkedList< C >::linkItem* last() const { return _list->last(); }
      typename stdexts::linkedList< C >::linkItem* first() { return _list->first(); }
      typename stdexts::linkedList< C >::linkItem* last() { return _list->last(); }

      operator bool () const { return ( *_list ); }

      typedef typename stdexts::linkedList< C >::linkItem iterator;
  };



///////////////////////////////////////////////////////////////////////////////


  template < class C >
  fifo< C >::fifo() :
   _list( new stdexts::linkedList< C >() )
  {
  }

  template < class C >
  fifo< C >::fifo( C c ) :
   _list( new stdexts::linkedList< C >( c ) )
  {
  }

  template < class C >
  fifo< C >& fifo< C >::operator, ( C obj )
  {
    _list->push_back( obj );
    return *this;
  }

  template < class C >
  fifo< C >& fifo< C >::operator<< ( C obj )
  {
    _list->push_back( obj );
    return *this;
  }


  template < class C >
  fifo< C >& fifo< C >::operator<< ( fifo< C > f )
  {
    while ( f ) _list->push_back( *f );
    return *this;
  }

  template < class C >
  C fifo< C >::operator* ()
  {
    return _list->pop_front();
  }


////////////////////////////////////////


  template < class C >
  dll< C >::dll() :
   _list( new stdexts::linkedList< C >() )
  {
  }

  template < class C >
  dll< C >::dll( C c ) :
   _list( new stdexts::linkedList< C >( c ) )
  {
  }

  template < class C >
  dll< C >& dll< C >::operator, ( C obj )
  {
    _list->push_back( obj );
    return *this;
  }

  template < class C >
  dll< C >& dll< C >::operator<< ( C obj )
  {
    _list->push_back( obj );
    return *this;
  }


  template < class C >
  dll< C >& dll< C >::operator+= ( dll< C > f )
  {
    while ( f ) _list->push_back( *f );
    return *this;
  }

  template < class C >
  C dll< C >::pop_front()
  {
    return _list->pop_front();
  }

  template < class C >
  C dll< C >::pop_back()
  {
    return _list->pop_back();
  }

  template < class C >
  void dll< C >::push_front( C c )
  {
    _list->push_front( c );
  }

  template < class C >
  void dll< C >::push_back( C c )
  {
    _list->push_back( c );
  }

}

#endif // __STDEXTS_LIST_TYPES_H__

