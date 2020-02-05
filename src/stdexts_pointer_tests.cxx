
#include <iostream>

#include "stdexts.h"

using namespace stdexts;

template < class T >
void testFunc( T x ) { T y = x; std::cout << "\nIn Test Func\n" << std::endl; }

void test1();

void test2();

void test3();

void test4();

int main( int, char** )
{
  std::cout << "\nTesting Standard Extensions\n" << std::endl;

  std::cout << "Testing Auto Pointer with integers\n" << std::endl;

  test1();

  std::cout << "\n///////////////////////////////////////////////////////////\n" << std::endl;

  test2();

  std::cout << "\n///////////////////////////////////////////////////////////\n" << std::endl;
  std::cout << "\n///////////////////////////////////////////////////////////\n" << std::endl;
  std::cout << "\nTesting Shared Pointer with integers\n" << std::endl;

  test3();

  std::cout << "\n///////////////////////////////////////////////////////////\n" << std::endl;

  test4();

  std::cout << "\nTests Complete!\n" << std::endl;

  return 0;
}





void test1()
{
  std::cout << "Initialising int pointer with value 78" << std::endl;
  autoPtr< int > p1( new int(78) );

  std::cout << "Initialising int pointer with value 10" << std::endl;
  autoPtr< int > p2( new int(10) );

  std::cout << "Initialising int pointer with value 100" << std::endl;
  autoPtr< int > p3( new int(100) );

  std::cout << "Value  P1 = " << *p1 << std::endl;
  std::cout << "Value  P2 = " << *p2 << std::endl;
  std::cout << "Value  P3 = " << *p3 << std::endl;

  std::cout << "Assigning P1 with P2\n" << std::endl;

  p1 = p2;

  if ( p1 )
    std::cout << "Value  P1 = " << *p1 << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Value  P2 = " << *p2 << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Value  P3 = " << *p3 << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;

  std::cout << "Initialising int pointer with pointer P3\n" << std::endl;
  autoPtr< int > p4( p3 );

  if ( p1 )
    std::cout << "Value  P1 = " << *p1 << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Value  P2 = " << *p2 << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Value  P3 = " << *p3 << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;
  if ( p4 )
    std::cout << "Value  P4 = " << *p4 << std::endl;
  else
    std::cout << "P4 Not Valid" << std::endl;


  std::cout << "Reassining P4 to 1" << std::endl;
  (*p4) = 1;
  if ( p4 )
    std::cout << "Value  P4 = " << *p4 << std::endl;
  else
    std::cout << "P4 Not Valid" << std::endl;
}


void test2()
{
  std::cout << "Testing Auto Array Pointer" << std::endl;

  std::cout << "Initializing 3 Auto Pointers\n" << std::endl;

  autoPtr<int[]> p1( new int[4] );
  autoPtr<int[]> p2( new int[4] );
  autoPtr<int[]> p3( new int[4] );

  for ( int i = 0; i < 4; ++i )
  {
    p1[i] = i;
    p2[i] = i*i;
    p3[i] = (int)10.0*i;
  }

  if ( p1 )
    std::cout << "Values of P1 : " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Values of P2 : " << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Values of P3 : " << p3[0] << " " << p3[1] << " " << p3[2] << " " << p3[3] << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;

  std::cout << "Setting P2 to P3\n" << std::endl;

  p2 = p3;

  if ( p1 )
    std::cout << "Values of P1 : " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Values of P2 : " << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Values of P3 : " << p3[0] << " " << p3[1] << " " << p3[2] << " " << p3[3] << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;
}



void test3()
{
  std::cout << "Creating shared int pointer with value 1\n" << std::endl;

  sharedPtr<int> p1( new int(1) );

  std::cout << "Value P1 = " << *p1 << std::endl;

  std::cout << "Sharing Pointer 3 times\n";

  sharedPtr<int> p2( p1 );
  sharedPtr<int> p3( p1 );
  sharedPtr<int> p4( p1 );

  if ( p1 )
    std::cout << "Value P1 = " << *p1 << " Count = " << p1.count() << std::endl;
  else 
    std::cout << "P1 Not Valid!" << std::endl;
  if ( p2 )
    std::cout << "Value P2 = " << *p2 << " Count = " << p2.count() << std::endl;
  else 
    std::cout << "P2 Not Valid!" << std::endl;
  if ( p3 )
    std::cout << "Value P3 = " << *p3 << " Count = " << p3.count() << std::endl;
  else 
    std::cout << "P3 Not Valid!" << std::endl;
  if ( p4 )
    std::cout << "Value P4 = " << *p4 << " Count = " << p4.count() << std::endl;
  else 
    std::cout << "P4 Not Valid!" << std::endl;

  std::cout << "\nReleasing P2\n" << std::endl;

  p2.release();

  if ( p1 )
    std::cout << "Value P1 = " << *p1 << " Count = " << p1.count() << std::endl;
  else 
    std::cout << "P1 Not Valid!" << std::endl;
  if ( p2 )
    std::cout << "Value P2 = " << *p2 << " Count = " << p2.count() << std::endl;
  else 
    std::cout << "P2 Not Valid!" << std::endl;
  if ( p3 )
    std::cout << "Value P3 = " << *p3 << " Count = " << p3.count() << std::endl;
  else 
    std::cout << "P3 Not Valid!" << std::endl;
  if ( p4 )
    std::cout << "Value P4 = " << *p4 << " Count = " << p4.count() << std::endl;
  else 
    std::cout << "P4 Not Valid!" << std::endl;

  std::cout << "\nChanging P2\n" << std::endl;

  p2.set( new int(7) );

  if ( p1 )
    std::cout << "Value P1 = " << *p1 << " Count = " << p1.count() << std::endl;
  else 
    std::cout << "P1 Not Valid!" << std::endl;
  if ( p2 )
    std::cout << "Value P2 = " << *p2 << " Count = " << p2.count() << std::endl;
  else 
    std::cout << "P2 Not Valid!" << std::endl;
  if ( p3 )
    std::cout << "Value P3 = " << *p3 << " Count = " << p3.count() << std::endl;
  else 
    std::cout << "P3 Not Valid!" << std::endl;
  if ( p4 )
    std::cout << "Value P4 = " << *p4 << " Count = " << p4.count() << std::endl;
  else 
    std::cout << "P4 Not Valid!" << std::endl;
  
  std::cout << "\nChanging P3\n" << std::endl;

  p3.set( new int(15) );

  if ( p1 )
    std::cout << "Value P1 = " << *p1 << " Count = " << p1.count() << std::endl;
  else 
    std::cout << "P1 Not Valid!" << std::endl;
  if ( p2 )
    std::cout << "Value P2 = " << *p2 << " Count = " << p2.count() << std::endl;
  else 
    std::cout << "P2 Not Valid!" << std::endl;
  if ( p3 )
    std::cout << "Value P3 = " << *p3 << " Count = " << p3.count() << std::endl;
  else 
    std::cout << "P3 Not Valid!" << std::endl;
  if ( p4 )
    std::cout << "Value P4 = " << *p4 << " Count = " << p4.count() << std::endl;
  else 
    std::cout << "P4 Not Valid!" << std::endl;
}

void test4()
{
  std::cout << "Testing Shared Array Pointer" << std::endl;

  std::cout << "Initializing 3 Shared Pointers\n" << std::endl;

  sharedPtr<int[]> p1( new int[4] );
  sharedPtr<int[]> p2( new int[4] );
  sharedPtr<int[]> p3( new int[4] );

  for ( int i = 0; i < 4; ++i )
  {
    p1[i] = i;
    p2[i] = i*i;
    p3[i] = (int)10.0*i;
  }

  if ( p1 )
    std::cout << "Values of P1 : " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << " With " << p1.count() << " copies" << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Values of P2 : " << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << " With " << p2.count() << " copies" << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Values of P3 : " << p3[0] << " " << p3[1] << " " << p3[2] << " " << p3[3] << " With " << p3.count() << " copies" << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;

  std::cout << "\nSetting P2 to P3\n" << std::endl;

  p2 = p3;

  if ( p1 )
    std::cout << "Values of P1 : " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << " With " << p1.count() << " copies" << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Values of P2 : " << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << " With " << p2.count() << " copies" << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Values of P3 : " << p3[0] << " " << p3[1] << " " << p3[2] << " " << p3[3] << " With " << p3.count() << " copies" << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;


  std::cout << "\nInitialising fourth pointer with p1\n" << std::endl;
  stdexts::sharedPtr< int[] > p4 = p1;

  if ( p1 )
    std::cout << "Values of P1 : " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << " With " << p1.count() << " copies" << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Values of P2 : " << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << " With " << p2.count() << " copies" << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Values of P3 : " << p3[0] << " " << p3[1] << " " << p3[2] << " " << p3[3] << " With " << p3.count() << " copies" << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;
  if ( p4 )
    std::cout << "Values of P4 : " << p4[0] << " " << p4[1] << " " << p4[2] << " " << p4[3] << " With " << p4.count() << " copies" << std::endl;
  else
    std::cout << "P4 Not Valid" << std::endl;

  std::cout << "\nUsing Test Function\n" << std::endl;

  testFunc( p1 );
  testFunc( p2 );
  testFunc( p3 );
  testFunc( p4 );

  p1.release();
  p1.release();
  p1.release();
  p1.release();

  std::cout << "Manually copying values from P2 to P4\n" << std::endl;

  for ( int i = 0; i < 4; ++i )
    p4[i] = p2[i];

  if ( p1 )
    std::cout << "Values of P1 : " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << " With " << p1.count() << " copies" << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Values of P2 : " << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << " With " << p2.count() << " copies" << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Values of P3 : " << p3[0] << " " << p3[1] << " " << p3[2] << " " << p3[3] << " With " << p3.count() << " copies" << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;
  if ( p4 )
    std::cout << "Values of P4 : " << p4[0] << " " << p4[1] << " " << p4[2] << " " << p4[3] << " With " << p4.count() << " copies" << std::endl;
  else
    std::cout << "P4 Not Valid" << std::endl;

  std::cout << "Releasing P2\n" << std::endl;

  p2.release();

  if ( p1 )
    std::cout << "Values of P1 : " << p1[0] << " " << p1[1] << " " << p1[2] << " " << p1[3] << " With " << p1.count() << " copies" << std::endl;
  else
    std::cout << "P1 Not Valid" << std::endl;
  if ( p2 )
    std::cout << "Values of P2 : " << p2[0] << " " << p2[1] << " " << p2[2] << " " << p2[3] << " With " << p2.count() << " copies" << std::endl;
  else
    std::cout << "P2 Not Valid" << std::endl;
  if ( p3 )
    std::cout << "Values of P3 : " << p3[0] << " " << p3[1] << " " << p3[2] << " " << p3[3] << " With " << p3.count() << " copies" << std::endl;
  else
    std::cout << "P3 Not Valid" << std::endl;
  if ( p4 )
    std::cout << "Values of P4 : " << p4[0] << " " << p4[1] << " " << p4[2] << " " << p4[3] << " With " << p4.count() << " copies" << std::endl;
  else
    std::cout << "P4 Not Valid" << std::endl;
}

