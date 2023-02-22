#include <iostream>
#include <stdexcept>
#include <thread>
#include <future>

#include <boost/thread.hpp>

void print_exception(const std::exception& e, int level =  0)
{
    std::cerr << std::string(level, ' ') << "exception: " << e.what() << '\n';
    try {
        std::rethrow_if_nested(e);
    } catch(const std::exception& nestedException) {
        print_exception(nestedException, level+1);
    } catch(...) {}
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
               throw std::logic_error { "Child" };
            }
            catch (const std::exception& e)
            {
               std::throw_with_nested(
                  std::runtime_error { "Parent" }
               );
            }
         }
      ).get();
   }
   catch (const std::exception& e)
   {
      print_exception(e);
   }
}