
#ifndef __STDEXTS__NON_COPYABLE_H__
#define __STDEXTS__NON_COPYABLE_H__

namespace stdexts
{

  class non_copyable
  {
    private:
      non_copyable( const non_copyable& ) {}
      non_copyable& operator=( const non_copyable& ) { return *this; }

    protected:
      non_copyable() {}
      virtual ~non_copyable() {}

    public:

  };

}

#endif // __STDEXTS__NON_COPYABLE_H__

