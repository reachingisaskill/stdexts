
#include <iostream>

#include "stdexts.h"



class test_class : public stdexts::singleton< test_class >
{
  private:
    int _val;

  public:
    test_class() : _val( 0 ) {}

    int& getVal() { return _val; }
};


int main( int, char** )
{

  std::cout << "Singleton Base Class Testing\n" << std::endl;

  std::cout << "Value of GET pointer = " << test_class::getInstance() << "\n";

  std::cout << "Initialising with value = 27\n" << std::endl;

  test_class::createInstance()->getVal() = 27;

  std::cout << "Value of GET pointer = " << test_class::getInstance() << "\n";
  std::cout << "Value stored         = " << test_class::getInstance()->getVal() << "\n";

  std::cout << std::endl;
  std::cout << "Initialising another with value = 37\n" << std::endl;

  test_class::createInstance()->getVal() = 37;

  std::cout << "Value of GET pointer = " << test_class::getInstance() << "\n";
  std::cout << "Value stored         = " << test_class::getInstance()->getVal() << "\n";

  std::cout << "Initialising a stack variable\n" << std::endl;

  test_class test1;

  std::cout << "Value stored         = " << test1.getVal() << "\n\n";

  std::cout << "Value of GET pointer = " << test_class::getInstance() << "\n";
  std::cout << "Value stored         = " << test_class::getInstance()->getVal() << "\n";


  test_class::killInstance();
  std::cout << std::endl;
  return 0;
}

