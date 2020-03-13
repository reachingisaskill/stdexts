
#ifndef __STDEXTS__BMP_H__
#define __STDEXTS__BMP_H__

#include <string>

namespace stdexts
{

  class bitmap
  {
    public :
      struct pixel;

    private:

      static const unsigned int _bytesPerPixel = 3;
      static const unsigned int _headerSize = 14;
      static const unsigned int _infoSize = 40;

      unsigned int _width;
      unsigned int _height;
      unsigned int _paddingSize;
      unsigned int _fileSize;
      unsigned int _numPixels;

      unsigned char _fileHeader[_headerSize];
      unsigned char _infoHeader[_infoSize];
      pixel* _data;

    protected:
      void buildMetaData();
      unsigned int _pixelNum( unsigned int x, unsigned int y );

    public:
      bitmap( unsigned int, unsigned int );

      ~bitmap();

      void setPixel( unsigned int x, unsigned int y, pixel p );

      void saveFile( std::string ) const ;

      unsigned int getFileSize() const { return this->_fileSize; }
      unsigned int getWidth() const { return this->_width; }
      unsigned int getHeight() const { return this->_height; }
      unsigned int getNumPixels() const { return this->_numPixels; }

      struct pixel
      {
        unsigned char blue;
        unsigned char green;
        unsigned char red;

        // Double values ~ [0,1]
        pixel();
        pixel(double r, double g, double b);
      };

  };

}

#endif // __STDEXTS__BMP_H__

