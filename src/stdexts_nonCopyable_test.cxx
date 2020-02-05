
#include "stdexts.h"

class test : public stdexts::non_copyable
{
  private:
    int _val;

  public:
    test( int a = 1 ) : non_copyable(), _val( a ) {}

    int& get() { return _val; }
};

int main( int, char** )
{

  test test1(2);

  // test test2( test1 );

  return 0;
}

