
#ifndef __STDEXTS__STRFUNCS_H__
#define __STDEXTS__STRFUNCS_H__

#include "stdexts_linkedList.h"

#include <string>
#include <sstream>

namespace stdexts
{

  unsigned long int strLen( const char* c );
  void strCpy( const char*, char* );
  void strCpyQuote( const char*&, const char*&, char = '\"' ); // UNTESTED!!!

  template < typename T > T ssConvert( std::string );
  template < typename T > std::string stringConvert( T );

  bool isComment( const char* );

  class tokenize
  {
    private:
      stdexts::sharedPtr< stdexts::linkedList< std::string > > _tokens;
      unsigned int _splitCharLen;
      char* _splitChars;

      void _tokenize( std::string& );

    public:
      tokenize( std::string, const char* = " " );
      tokenize( const tokenize& );
      ~tokenize() { delete [] _splitChars; }

      // std::string get( unsigned int ) const;

      std::string pop_front();
      std::string pop_back();

      int size() const { return _tokens->count(); }

      operator bool () const { return (*_tokens); }
  };


//////////////////////////////////////////////////////////////////////////////

  template < typename T >
  T ssConvert( std::string s )
  {
    std::istringstream iss( s );
    T temp;
    iss >> temp;
    return temp;
  }

  template < typename T >
  std::string stringConvert( T t )
  {
    std::ostringstream oss( "" );
    oss << t;
    return oss.str();
  }

}

#endif // __STDEXTS__STRFUNCS_H__

