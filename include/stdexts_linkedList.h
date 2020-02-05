
#ifndef __STDEXTS__LINKED_LIST_H__
#define __STDEXTS__LINKED_LIST_H__

#include "stdexts_sharedPtr.h"
#include "stdexts_nonCopyable_base.h"


namespace stdexts
{

  template < class T >
  class linkedList : public stdexts::non_copyable
  {
    public:

      class linkItem
      {
        friend class linkedList;

        private:
          T _data;

          linkItem* _prev;
          linkItem* _next;

        protected:
          linkItem( T, linkItem* = 0, linkItem* = 0 );

          linkItem* clear();
          unsigned int _count();

        public:
          virtual ~linkItem();

          linkItem* append( linkItem* );
          linkItem* preppend( linkItem* );
          linkItem* remove();
          T extract();

          linkItem* next();
          linkItem* prev();
          linkItem* first();
          linkItem* last();
          const linkItem* next() const;
          const linkItem* prev() const;
          const linkItem* first() const;
          const linkItem* last() const;

          T get() const { return _data; }

          T* operator->() { return &_data; }
          T& operator* () { return _data; }
          const T* operator->() const { return &_data; }
          const T& operator* () const { return _data; }
      };

    private:
      linkItem* _list;
      linkItem* _last;

    public:
      linkedList() : _list( 0 ), _last( 0 ) {}
      linkedList( T );

      ~linkedList() { if ( _list ) _list->clear(); }

      linkedList& push_front( T );
      linkedList& push_back( T );
      T pop_front();
      T pop_back();

      linkItem* first() const { return _list->first(); }
      linkItem* last() const { return _last->last(); }

      bool isEmpty() const { return ( _list == 0 ); }
      operator bool () const { return ( _list != 0 ); }

      unsigned int count();
  };

///////////////////////////////////////////////////////////////////////////////

  template < class T >
  linkedList< T >::linkedList( T obj ) :
    _list( new typename linkedList< T >::linkItem( obj ) ),
    _last( _list )
  {
  }

  template < class T >
  linkedList< T >& linkedList< T >::push_front( T obj )
  {
    if ( _list != 0 )
      _list = _list->preppend( new typename linkedList< T >::linkItem( obj ) );
    else
    {
      _list = new typename linkedList< T >::linkItem( obj );
      _last = _list;
    }

    return *this;
  }

  template < class T >
  linkedList< T >& linkedList< T >::push_back( T obj )
  {
    if ( _list != 0 )
      _last = this->last()->append( new typename linkedList< T >::linkItem( obj ) );
    else
    {
      _list = new typename linkedList< T >::linkItem( obj );
      _last = _list;
    }

    return *this;
  }

  template < class T >
  T linkedList< T >::pop_front()
  {
    T temp = _list->get();
    _list = _list->remove();
    if ( ! _list ) _last = 0;
    return temp;
  }

  template < class T >
  T linkedList< T >::pop_back()
  {
    T temp = this->last()->get();
    if ( _list == _list->last() )
    {
      _list = _list->remove();
      _last = _list;
    }
    else
      _last =_list->last()->remove();
    return temp;
  }

  template < class T >
  unsigned int linkedList< T >::count()
  {
    return this->first()->_count();
  }

//////////////////////////////////////////////////////////////////////////////

  template < class T >
  linkedList< T >::linkItem::linkItem( T d, linkedList< T >::linkItem* prev, linkedList< T >::linkItem* next ) :
    _data( d ),
    _prev( prev ),
    _next( next )
  {
    if ( _prev ) _prev->_next = this;
    if ( _next ) _next->_prev = this;
  }

  template < class T >
  linkedList< T >::linkItem::~linkItem()
  {
    if ( _prev != 0 || _next != 0 ) // Deleted Without Remove!
      this->_next->clear();
  }

  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::clear()
  {
    typename linkedList< T >::linkItem* next = this;
    while ( next != 0 ) next = next->remove();
    return 0;
  }

  template < class T >
  unsigned int linkedList< T >::linkItem::_count() 
  {
    if ( this ) return _next->_count() + 1;
    else return 0; 
  }


  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::append( linkedList< T >::linkItem* item )
  {
    if ( _next )
    {
      _next->_prev = item;
      item->_next = _next;
    }
    item->_prev = this;
    _next = item;

    return _next;
  }

  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::preppend( linkedList< T >::linkItem* item )
  {
    if ( _prev )
    {
      _prev->_next = item;
      item->_prev = _prev;
    }
    item->_next = this;
    _prev = item;

    return _prev;
  }

  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::remove()
  {
    if ( _next ) _next->_prev = this->_prev;
    if ( _prev ) _prev->_next = this->_next;
    typename linkedList< T >::linkItem* next = _next;
    this->_prev = 0;
    this->_next = 0;

    delete this;
    return next;
  }

  template < class T >
  T linkedList< T >::linkItem::extract()
  {
    T temp = this->_data;
    this->remove();

    return temp;
  }

  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::next()
  {
    return _next;
  }

  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::prev()
  {
    return _prev;
  }

  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::first()
  {
    if ( _prev ) return _prev->first();
    else return this;
  }

  template < class T >
  typename linkedList< T >::linkItem* linkedList< T >::linkItem::last()
  {
    if ( _next ) return _next->last();
    else return this;
  }


  template < class T >
  const typename linkedList< T >::linkItem* linkedList< T >::linkItem::next() const
  {
    return _next;
  }

  template < class T >
  const typename linkedList< T >::linkItem* linkedList< T >::linkItem::prev() const
  {
    return _prev;
  }

  template < class T >
  const typename linkedList< T >::linkItem* linkedList< T >::linkItem::first() const
  {
    if ( _prev ) return _prev->first();
    else return this;
  }

  template < class T >
  const typename linkedList< T >::linkItem* linkedList< T >::linkItem::last() const
  {
    if ( _next ) return _next->last();
    else return this;
  }

}

#endif // __STDEXTS__LINKED_LIST_H__

