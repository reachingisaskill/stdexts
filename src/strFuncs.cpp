
#include "stdexts_strFuncs.h"

namespace stdexts
{

  unsigned long int strLen( const char* c )
  {
    unsigned long int size = 1;
    while ( *c != '\0' )
    {
      ++size;
      ++c;
    }
    return size;
  }

  void strCpy( const char* src, char* dest )
  {
    *dest = *src;
    while ( *src != '\0' )
    {
      ++dest;
      ++src;
      *dest = *src;
    }
    *dest = *src;
  }

  void strCpyQuote( const char*& src, char*& dest, char quote )
  {
    *dest = *src;
    while ( *src != '\0' )
    {
      ++dest;
      ++src;

      if ( *src == quote )
      {
        return;
      }

      switch ( *src )
      {
        case '\"':
          *dest = *src;
          strCpyQuote( src, dest, '\"' );
          *dest = *src;
          break;

        case '\'':
          *dest = *src;
          strCpyQuote( src, dest, '\'' );
          *dest = *src;
          break;

        default:
          *dest = *src;
          break;
      }
    }
  }

  bool isComment( const char* c )
  {
    while ( *c != '\0' )
    {
      switch ( *c++ )
      {
        case '#' : 
          return true;
          break;
        case ' ' : // Skip the whitespace
          continue;
          break;
        case '\t' :
          continue;
          break;
        default:
          return false;
          break;
      }
    }
    return true; // If it's empty!
  }





//////////////////////////////////////////////////////////////////////////////

  tokenize::tokenize( std::string str, const char* spl ) :
    _tokens( new stdexts::linkedList< std::string > ),
    _splitCharLen( strLen( spl ) ),
    _splitChars( new char[ _splitCharLen ] )
  {
    strCpy( spl, _splitChars );
    _tokenize( str );
  }

  void tokenize::_tokenize( std::string& str )
  {
    bool split = true;
    bool action = true;
    std::string current = "";
    const char* pos = str.c_str();

    do
    {
      action = true;

      for ( unsigned int i = 0; i < _splitCharLen; ++i )
      {
        if ( _splitChars[i] == *pos )
        {
          action = false;

          if ( split == true )
          {
            break;
          }

          split = true;
          _tokens->push_back( current );
          current = "";
        }
      }

      if ( action )
      {
        split = false;
        current += *pos;
      }
    }
    while  ( *pos++ != '\0' );

  }

//  std::string tokenize::get( unsigned int num ) const
//  {
//    linkedList< std::string >::linkItem* item = _tokens->first();
//    for ( unsigned int i = 0; i < num; ++i )
//    {
//      item = item->next();
//    }
//    return item->get();
//  }

  std::string tokenize::pop_front()
  {
    return _tokens->pop_front();
  }

  std::string tokenize::pop_back()
  {
    return _tokens->pop_back();
  }

}

