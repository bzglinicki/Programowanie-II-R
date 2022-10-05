/********************************************************************
 * Programowanie II R
 * Zadania - seria 1.
 * Zadanie 3.
********************************************************************/

#include <iostream>

// Operacje matematyczne, w tym potęgowanie: std::pow
#include <cmath>

// Operacje matematyczne na liczbach zespolonych
#include <complex> 

int main()
{
   double a, b, c;
   
   std::cout << "ax^2 + bx + c = 0" << std::endl;
   
   std::cout << "   a = ";
   std::cin >> a;
   
   std::cout << "   b = ";
   std::cin >> b;
   
   std::cout << "   c = ";
   std::cin >> c;
   
   // Wypisujemy na wyjście pustą linię.
   std::cout << std::endl;
   
   double delta = std::pow(b, 2) - 4 * a * c;
   // Zamiast std::pow(b, 2) można też napisać po prostu b * b.
   
   if(delta == 0)
   {
      double x0 = - b / (2 * a);
	  std::cout << "Rozwiązanie (rzeczywiste):" << std::endl << "   x0 = " << x0 << std::endl;
   }
   else if (delta > 0)
   {
      double x1 = (-b - std::sqrt(delta)) / (2 * a);
	  double x2 = (-b + std::sqrt(delta)) / (2 * a);
	  std::cout << "Rozwiązania (rzeczywiste):" << std::endl;
      std::cout << "   x1 = " << x1 << std::endl;
	  std::cout << "   x2 = " << x2 << std::endl;
   }
   else
   {
      std::complex<double> sqroot = sqrt(std::complex<double>(delta));
	  std::complex<double> x1 = (-b - sqroot) / (2 * a);
	  std::complex<double> x2 = (-b + sqroot) / (2 * a);
	  std::cout << "Rozwiązania (zespolone):" << std::endl;
      std::cout << "   x1 = " << x1 << std::endl;
	  std::cout << "   x2 = " << x2 << std::endl;
   }
   
   return 0;
}