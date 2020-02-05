
#include <iostream>

#include "stdexts.h"


stdexts::fifo< double > testFunc();

int main ( int, char** )
{
  std::cout << "Hello World!" << std::endl;

  {
    std::cout << "CREATING FIFO" << std::endl;
    stdexts::fifo< int > test1( 1 );
    test1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;

    std::cout << "Me Again" << std::endl;

    while ( test1 ) std::cout << "Val = " << *test1 << std::endl;

    std::cout << "Me Again" << std::endl;

    stdexts::fifo<double> test2 = testFunc();

    while ( test2 ) std::cout << "Val = " << *test2 << std::endl;

    std::string teststring = "hello penis   poo";
    stdexts::tokenize tokenTest( teststring, " " );
    std::cout << "Last = " << tokenTest.pop_back() << std::endl;

    while ( tokenTest )
    {
      std::cout << "Token = " << tokenTest.pop_front() << std::endl;
    }

    std::cout << "REMOVING FIFOS" << std::endl;
  }

  std::cout << std::endl;
  return 0;
}

stdexts::fifo< double > testFunc()
{
  return ( stdexts::fifo<double>(1.0), 1.1, 1.2, 1.3, 1.4, 1.5 );
}

