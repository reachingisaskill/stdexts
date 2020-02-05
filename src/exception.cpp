
#include "stdexts_exception.h"

namespace stdexts
{

  std::string exception::elucidate() const
  {
    std::stringstream result;
    result << "Error : " << _cause << "\n\n";

    for ( std::list< throwPoint >::const_iterator it = _throws.begin(); it != _throws.end(); ++it )
    {
      result << "   +-- Event Logged : ";

      switch ( it->type() )
      {
        case throwPoint::Tcreate :
          result << "Error Created\n";
          if ( this->info() != "" ) result << "   | - " << this->info() << "\n";
          break;
        case throwPoint::Tinit :
          result << "First Thrown\n";
          break;
        case throwPoint::Trethrow :
          result << "Rethrow\n";
          break;
        case throwPoint::Tinfo :
          result << "Information Appended\n" << "   | - " << it->info() << "\n";
          break;
        case throwPoint::Telucidate :
          result << "Elucidation\n";
          break;
        default:
          break;
      }

      result << "   | - At Line : " << it->line() << ". In : " << it->file() << "\n"
             << ( ( it->type() == throwPoint::Telucidate ) ? "\n" : "   | \n" );
    }

    return result.str();
  }


  std::string exception::what() const
  {
    std::stringstream result;
    result << "Error : " << _cause << "\n";
    if ( this->info() != "" ) result << this->info() << "\n\n";

    for ( std::list< throwPoint >::const_iterator it = _throws.begin(); it != _throws.end(); ++it )
    {
      if ( it->type() == throwPoint::Tinfo )
      {
        result << " - " << it->info() << "\n";
      }
    }
    result << "\n";

    return result.str();
  }


  exception& exception::log( throwPoint pt )
  {
    _throws.push_back( pt );
    return *this;
  }

  
}

