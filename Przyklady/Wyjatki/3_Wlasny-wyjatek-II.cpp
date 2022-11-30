#include <iostream>
#include <exception>

class MyException : public std::exception
{
   private:
      char *msg;

   public:
      MyException(char *message) : msg(message) {}
      
	  virtual const char *what() const throw()
      {
         return message;
      }
};

int main()
{
   try
   {
      throw MyException("Coś poszło nie tak :(");
   }
   catch(MyException &e)
   {
      std::cerr << "Wyjątek MyException!" << std::endl;
      std::cerr << "Komunikat: " << e.what() << std:endl;
   }
   
   return 0;
}