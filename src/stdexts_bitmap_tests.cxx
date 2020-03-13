
#include <iostream>
#include <string>

#include "stdexts.h"

const std::string file_out = "./test_data/bitmap_test.bmp";

int main( int, char** )
{
  std::cout << "Testing Bitmap Functionality" << std::endl;
  std::cout << "Building test bitmap\n" << std::endl;

  stdexts::bitmap bm = stdexts::bitmap( 100, 100 );

  for ( unsigned int i = 0; i < 100; ++i )
  {
    for ( unsigned int j = 0; j < 100; ++j )
    {
      bm.setPixel( i, j, stdexts::bitmap::pixel( 1.0, 0.0, 0.0 ) );
    }
  }

  std::cout << "Bitmap details:" << std::endl;

  std::cout << "File Size: " << bm.getFileSize() << "\n"
            << "Num Pixels: " << bm.getNumPixels() << "\n"
            << "Width: " << bm.getWidth() << "\n"
            << "Height: " << bm.getHeight() << '\n' << std::endl;

  std::cout << "Saving test bitmap to: " << file_out << std::endl;

  bm.saveFile( file_out );

  std::cout << "Test complete!" << std::endl;
}

