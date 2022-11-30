#include <iostream>
#include <exception>

class MyException : public std::exception
{
   virtual const char *what() const throw()
   {
      return "Coś poszło nie tak :(";
   }
};

int main()
{
   try
   {
      throw MyException();
   }
   catch(MyException &e)
   {
      std::cerr << "Wyjątek MyException!" << std::endl;
   }
   
   return 0;
}