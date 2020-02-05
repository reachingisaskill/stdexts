
#include "stdexts_functions.h"

#include <cmath>

namespace stdexts
{

  function_1D::function_1D( double min, double max ) :
    function_base< double, double, double >( min, max )
  {
  }

  function_1D::function_1D( const function_1D& f ) :
    function_base< double, double, double >( f )
  {
  }

  function_1D& function_1D::operator= ( const function_1D& f )
  {
    function_base< double, double, double >::operator= ( f );
    return *this;
  }





  function_1D_data::function_1D_data( double min, double max, unsigned int num ) :
    function_1D( min, max ),
    _data( new double[ num ] ),
    _numBins( num ),
    _binWidth( ( max - min ) / num )
  {
    for ( unsigned int i = 0; i < _numBins; ++i )
      _data[ i ] = 0.0;
  }

  function_1D_data::function_1D_data( const function_1D_data& f ) :
    function_1D( f ),
    _data( new double[ f._numBins] ),
    _numBins( f._numBins ),
    _binWidth( f._binWidth )
  {
    for ( unsigned int i = 0; i < _numBins; ++i )
    {
      this->_data[i] = f._data[i];
    }
  }

  function_1D_data& function_1D_data::operator= ( const function_1D_data& f )
  {
    delete[] _data;

    function_1D::operator= ( f );

    _numBins = f._numBins;
    _binWidth = f._binWidth;

    _data = new double[ _numBins ];

    for ( unsigned int i = 0; i < _numBins; ++i )
    {
      this->_data[i] = f._data[i];
    }
    return *this;
  }


  function_1D_data::~function_1D_data()
  {
    delete[] _data;
  }

  double function_1D_data::_calculate( double x )
  {
    // if ( ! this->contains( x ) ) // THROW AN ERROR HERE!
    return _data[ binNumber( x ) ];
  }

  
  double function_1D_data::integrate( double min, double max ) const 
  {
    double sum = 0.0;
    for ( unsigned int num = binNumber( min ); num <= binNumber( max ); ++num )
    {
      sum += _data[ num ];
    }
    return sum;
  }

  double function_1D_data::differentiate( double x )
  {
    unsigned int num = binNumber( x );
    if ( num == 0 )
    {
      return 1.5 * ( _data[ num + 1 ] - _data[ num ] ) / _binWidth;
    }
    else if ( num == (_numBins - 1) )
    {
      return 1.5 * ( _data[ num ] - _data[ num - 1 ] ) / _binWidth;
    }
    else
    {
      return ( 0.5 * ( _data[ num + 1 ] - _data[ num - 1 ] ) ) / _binWidth;
    }
  }

  void function_1D_data::normalise()
  {
    double integral = this->integrate();
    for ( unsigned int num = 0; num < _numBins; ++num )
    {
      _data[ num ] = _data[ num ] / integral;
    }
  }

  double function_1D_data::funcMax() const
  {
#ifdef INFINITY
    double current = -INFINITY;
#else
    double current = -1.0e+300;
#endif
    for ( unsigned int i = 0; i < _numBins; ++i )
    {
      if ( _data[ i ] > current ) current = _data[ i ];
    }

    return current;
  }

  double function_1D_data::funcMin() const
  {
#ifdef INFINITY
    double current = INFINITY;
#else
    double current = 1.0e+300;
#endif
    for ( unsigned int i = 0; i < _numBins; ++i )
    {
      if ( _data[ i ] < current ) current = _data[ i ];
    }

    return current;
  }

  bool function_1D_data::setValue( unsigned int num, double val )
  {
    // NEED ERROR CHECKING HERE!
    if ( num >= _numBins ) return false;
    _data[ num ] = val;
    return true;
  }

  bool function_1D_data::setValue( double x, double val )
  {
    // if ( ! this->contains( x ) ) // THROW AN ERROR HERE!
    if ( ( x > this->rangeMax() ) || ( x < this->rangeMin() ) ) return false;
    _data[ binNumber( x ) ] = val;
    return true;
  }

  unsigned int function_1D_data::binNumber( double x ) const
  {
    if ( x == this->rangeMax() ) x -= _binWidth;
    return  ( unsigned int )( ( x - this->rangeMin() ) / _binWidth );
  }

  double function_1D_data::binValue( unsigned int num ) const
  {
    return (double)( this->rangeMin() + ( num * _binWidth ) );
  }



  void function_1D_data::print( std::ostream& stream )
  {
    for ( unsigned int i = 0; i < _numBins; ++i )
    {
      stream << i << '\t' << this->binValue( i ) << '\t' << _data[i] << '\t' << this->differentiate( binValue( i ) ) << '\n';
    }
  }

}

