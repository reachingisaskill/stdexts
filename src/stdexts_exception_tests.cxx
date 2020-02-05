
#include <iostream>

#include "stdexts.h"

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();

int main( int, char** )
{
  std::cout << "Testing Exception Functionality" << std::endl;

  try
  {
    test1();
  }
  catch( stdexts::exception& e )
  {
    std::cout << "Error Caught!\n" << ELUCIDATE( e );
  }

  std::cout << std::endl;
  return 0;
}

void test1()
{
  try
  {
    test2();
  }
  catch( stdexts::exception& e )
  {
    RETHROW( e );
  }
}
void test2()
{
  try
  {
  test3();
  }
  catch( stdexts::exception& e )
  {
    RETHROW( e );
  }
}
void test3()
{
  test4();
}
void test4()
{
  try
  {
  test5();
  }
  catch( stdexts::exception& e )
  {
    EX_LOG( e, "Added Some Info Here" );
    RETHROW( e );
  }
}
void test5()
{
  test6();
}
void test6()
{
  try
  {
  test7();
  }
  catch( stdexts::exception& e )
  {
    RETHROW( e );
  }
}
void test7()
{
  test8();
}
void test8()
{
  try
  {
    test9();
  }
  catch( stdexts::exception& e )
  {
    RETHROW( e );
  }
}
void test9()
{
  stdexts::exception ex("FOUND YOU", "Some information for the error...");
  EX_CREATE( ex );
  THROW( ex );
}

