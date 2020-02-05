
#ifndef __STDEXTS__EXCEPTION_H__
#define __STDEXTS__EXCEPTION_H__

#include <list>
#include <string>
#include <sstream>


#define EX_CREATE( exc ) exc.log( stdexts::exception::throwPoint( stdexts::exception::throwPoint::Tcreate, __LINE__, __FILE__ ) )

#define THROW( exc ) throw exc.log( stdexts::exception::throwPoint( stdexts::exception::throwPoint::Tinit, __LINE__, __FILE__ ) )

#define RETHROW( exc ) throw exc.log( stdexts::exception::throwPoint( stdexts::exception::throwPoint::Trethrow, __LINE__, __FILE__ ) )

#define EX_LOG( exc, string ) exc.log( stdexts::exception::throwPoint( stdexts::exception::throwPoint::Tinfo, __LINE__, __FILE__, string ) )

#ifdef __DEBUG_OFF__
#define ELUCIDATE( exc ) exc.log( stdexts::exception::throwPoint( stdexts::exception::throwPoint::Telucidate, __LINE__, __FILE__ ) ).what()
#else
#define ELUCIDATE( exc ) exc.log( stdexts::exception::throwPoint( stdexts::exception::throwPoint::Telucidate, __LINE__, __FILE__ ) ).elucidate()
#endif


namespace stdexts
{

  class exception
  {
    public:

      class throwPoint
      {
        public:
          enum typeT { Tcreate, Tinit, Trethrow, Tinfo, Telucidate };

        private:
          typeT _type;
          unsigned int _line;
          std::string _file;
          std::string _info;

        public:
          throwPoint( typeT t, unsigned int n, const char* c, std::string i = "" ) : _type( t ), _line( n ), _file( c ), _info( i ) {}

          const typeT& type() const { return _type; }
          const unsigned int& line() const { return _line; }
          const std::string& file() const { return _file; }
          const std::string& info() const { return _info; }
      };



    private:
      std::list< throwPoint > _throws;
      std::string _cause;
      std::string _info;

    protected:

    public:
      exception( const char* c, std::string i = "" ) : _cause( c ), _info( i ) {}
      virtual ~exception() {}

      virtual std::string what() const;
      virtual std::string elucidate() const;

      exception& log( throwPoint );
      
      const std::string& cause() const { return _cause; }
      const std::string& info() const { return _info; }
  };

}

#endif // __STDEXTS__EXCEPTION_H__

