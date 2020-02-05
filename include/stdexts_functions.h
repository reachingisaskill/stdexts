
#ifndef __STDEXTS__FUNCTIONS_H__
#define __STDEXTS__FUNCTIONS_H__

#include <iostream>

namespace stdexts
{

  template < class RET_TYPE, class TYPE, typename INTEGRATED = double >
  class function_base
  {
    private:
      INTEGRATED _scale;
      TYPE _rangeMin;
      TYPE _rangeMax;

    protected:
      virtual RET_TYPE _calculate( TYPE ) = 0;

    public:
      function_base( TYPE, TYPE );
      function_base( const function_base& );
      function_base& operator= ( const function_base& );

      virtual ~function_base() {}

      virtual RET_TYPE operator() ( TYPE t ) { return _scale * this->_calculate( t ); };
      virtual RET_TYPE integrate() const = 0;
      virtual RET_TYPE integrate( TYPE, TYPE ) const = 0;
      virtual RET_TYPE differentiate( TYPE ) = 0;
      virtual void normalise() = 0;

      virtual bool contains( TYPE t ) const { return ( t >= _rangeMin ) && ( t < _rangeMax ); }

      virtual const TYPE& rangeMin() const { return _rangeMin; }
      virtual const TYPE& rangeMax() const { return _rangeMax; }

      virtual RET_TYPE funcMin() const = 0;
      virtual RET_TYPE funcMax() const = 0;

      virtual void rangeMin( TYPE t ) { _rangeMin = t; }
      virtual void rangeMax( TYPE t ) { _rangeMax = t; }

      virtual void scale( INTEGRATED s ) { _scale = s; }
      virtual const INTEGRATED& scale() const { return _scale; }
  };


  class function_1D : public function_base< double, double, double >
  {
    private:
    public:
      function_1D( double, double );
      function_1D( const function_1D& );
      function_1D& operator= ( const function_1D& );
      virtual ~function_1D() {}
  };

  class function_1D_data : public function_1D
  {
    private:
      double* _data;
      unsigned int _numBins;
      double _binWidth;

    protected:
      virtual double _calculate( double );

    public:
      function_1D_data( double, double, unsigned int );
      function_1D_data( const function_1D_data& ); // FINISH ME!
      function_1D_data& operator= ( const function_1D_data& ); // FINISH ME!
      virtual ~function_1D_data();

      virtual double integrate() const { return integrate( this->rangeMin(), this->rangeMax() ); }
      virtual double integrate( double, double ) const;
      virtual double differentiate( double );
      virtual void normalise();

      virtual double funcMin() const;
      virtual double funcMax() const;

      bool setValue( unsigned int, double );
      bool setValue( double, double );

      unsigned int binNumber( double ) const;
      double binValue( unsigned int ) const;

      const unsigned int& numBins() const { return _numBins; }

      void print( std::ostream& );
  };


////////////////////////////////////////////////////////////////////////////////

  template < class RET_TYPE, class TYPE, typename INTEGRATED >
  function_base< RET_TYPE, TYPE, INTEGRATED >::function_base( TYPE min, TYPE max ) :
    _scale( 1.0 ),
    _rangeMin( min ),
    _rangeMax( max )
  {
  }

  template < class RET_TYPE, class TYPE, typename INTEGRATED >
  function_base< RET_TYPE, TYPE, INTEGRATED >::function_base( const function_base< RET_TYPE, TYPE, INTEGRATED >& f) :
    _scale( f._scale ),
    _rangeMin( f._rangeMin ),
    _rangeMax( f._rangeMax )
  {
  }


  template < class RET_TYPE, class TYPE, typename INTEGRATED >
  function_base< RET_TYPE, TYPE, INTEGRATED>& function_base< RET_TYPE, TYPE, INTEGRATED >::operator= ( const function_base< RET_TYPE, TYPE, INTEGRATED >& f)
  {
    _scale = f._scale;
    _rangeMin = f._rangeMin;
    _rangeMax = f._rangeMax;
    return *this;
  }

}

#endif

