
#include <iostream>
#include <fstream>
#include <cmath>

#include "stdexts_functions.h"


int main( int, char** )
{
  std::cout << "Testing Functions\n" << std::endl;

  double min = 1.7;
  double max = 13.65;
  unsigned int num = 500;
  stdexts::function_1D_data func( min, max, num );


  for ( unsigned int i = 0; i < num; ++ i )
  {
    func.setValue( i, sin( 2.0*3.1415926*i/250 ) );
  }


  std::cout << "\nIntegral = " << func.integrate();

  std::cout << "\nNormalising";
  func.normalise();
  std::cout << "\nIntegral = " << func.integrate();


  std::ofstream output( "out.txt" );

  func.print( output );

  output.close();



  std::cout << std::endl;


  return 0;
}

