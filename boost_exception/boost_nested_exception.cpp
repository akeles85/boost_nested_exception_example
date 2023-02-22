#include <iostream>
#include <stdexcept>
#include <thread>
#include <future>
#include <boost/thread.hpp>
#include <boost/exception_ptr.hpp>
#include <boost/exception/enable_current_exception.hpp>
#include <boost/exception/enable_error_info.hpp>
#include <boost/exception/errinfo_errno.hpp>
#include <boost/exception/errinfo_nested_exception.hpp>

#define HZ_BOOST_THROW_WITH_NESTED(e) \
  BOOST_THROW_EXCEPTION(boost::enable_current_exception(boost::enable_error_info(e)) \
     << boost::errinfo_nested_exception(boost::current_exception())) 

void print_exception(const boost::exception& ex, int level =  0)
{
    std::cout << boost::diagnostic_information(ex) << std::endl;
}

int main()
{
   try
   {
      boost::async(
         boost::launch::async,
         [](){
            try
            {
               BOOST_THROW_EXCEPTION( std::runtime_error { "Child" } );
            }
            catch (const boost::exception& ex)
            {                
                HZ_BOOST_THROW_WITH_NESTED(std::logic_error("Parent"));
            }
         }
      ).get();
   }
   catch (const boost::exception& e)
   {
      print_exception(e);
   }
}