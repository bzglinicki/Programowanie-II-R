#include <iostream>
#include <exception>

int main()
{
   double x = 3.;
   double y = 0.;
   
   try
   {
      double z = x / y;
   }
   catch(std::exception &e)
   {
      std::cerr << "Wyjątek!" << std::endl;
	  std::cerr << "Komunikat: " << e.what() << std::endl;
   }
   
   return 0;
}