
#ifndef __STDEXTS__SINGLETON_BASE_H__
#define __STDEXTS__SINGLETON_BASE_H__

#include "stdexts_autoPtr.h"
#include "stdexts_nonCopyable_base.h"

namespace stdexts
{

  template < class T >
  class singleton : public non_copyable
  {
    private:
      static T* _theInstance;

    protected:
      singleton() { }
      virtual ~singleton() { }

    public:
      static T* createInstance() { if ( _theInstance ) delete _theInstance; _theInstance = new T(); return _theInstance; }
      static T* getInstance() { return _theInstance; }
      static void killInstance() { if ( _theInstance ) delete _theInstance; _theInstance = 0; }

      virtual operator bool () const { return ( _theInstance != 0 ); }
      bool isAlive() const { return ( _theInstance != 0 ); }
  };

  template < class T >
  T* singleton< T >::_theInstance = 0;

}

#endif // __STDEXTS__SINGLETON_BASE_H__
