
#include "stdexts_bitmap.h"

#include <cstdio>

namespace stdexts
{

  const unsigned int bitmap::_bytesPerPixel;
  const unsigned int bitmap::_headerSize;
  const unsigned int bitmap::_infoSize;


  bitmap::bitmap( unsigned int w, unsigned int h ) :
    _width( w ),
    _height( h ),
    _paddingSize( 0 ),
    _fileSize( 0 ),
    _numPixels( w*h ),
    _fileHeader{ 0 },
    _infoHeader{ 0 },
    _data( 0 )
  {
    _paddingSize = ( 4 - (_width*_bytesPerPixel) % 4 ) % 4;
    _fileSize = _headerSize + _infoSize + (_bytesPerPixel*_width+_paddingSize) * _height;

    _data = new pixel[ _numPixels ];

    buildMetaData();
  }

  bitmap::~bitmap()
  {
    delete[] _data;
  }

  void bitmap::buildMetaData()
  {
    _fileHeader[0] = (unsigned char)('B');
    _fileHeader[1] = (unsigned char)('M');
    _fileHeader[2] = (unsigned char)(_fileSize    );
    _fileHeader[3] = (unsigned char)(_fileSize>> 8);
    _fileHeader[4] = (unsigned char)(_fileSize>>16);
    _fileHeader[5] = (unsigned char)(_fileSize>>24);
    _fileHeader[10] = (unsigned char)(_headerSize + _infoSize);

    _infoHeader[ 0] = (unsigned char)(_infoSize);
    _infoHeader[ 4] = (unsigned char)(_width    );
    _infoHeader[ 5] = (unsigned char)(_width>> 8);
    _infoHeader[ 6] = (unsigned char)(_width>>16);
    _infoHeader[ 7] = (unsigned char)(_width>>24);
    _infoHeader[ 8] = (unsigned char)(_height    );
    _infoHeader[ 9] = (unsigned char)(_height>> 8);
    _infoHeader[10] = (unsigned char)(_height>>16);
    _infoHeader[11] = (unsigned char)(_height>>24);
    _infoHeader[12] = (unsigned char)(1);
    _infoHeader[14] = (unsigned char)(_bytesPerPixel*8);
  }


  unsigned int bitmap::_pixelNum( unsigned int x, unsigned int y )
  {
    return y*_width + x;
  }


  void bitmap::setPixel( unsigned int x, unsigned int y, pixel p )
  {
    _data[_pixelNum( x, y )] = p;
  }


  void bitmap::saveFile( std::string fileName ) const
  {
    unsigned char padding[] = { 0, 0, 0 };
    FILE* file = fopen(fileName.c_str(), "wb");

    fwrite( _fileHeader, 1, _headerSize, file );
    fwrite( _infoHeader, 1, _infoSize, file );

    for ( unsigned int i = 0; i < _height; ++i )
    {
      unsigned int row = _height - (i+1);
      fwrite( _data+(row*_width), _bytesPerPixel, _width, file );
      fwrite( padding, 1, _paddingSize, file );
    }

    fclose( file );
  }



  bitmap::pixel::pixel() :
    blue( 0 ),
    green( 0 ),
    red( 0 )
  {
  }

  bitmap::pixel::pixel( double r, double g, double b ) :
    blue( (unsigned char)(b*255) ),
    green( (unsigned char)(g*255) ),
    red( (unsigned char)(r*255) )
  {
  }
}

