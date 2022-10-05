/********************************************************************
 * Programowanie II R
 * Zadania - seria 1.
 * Zadanie 2.
********************************************************************/

#include <iostream>

int main()
{
   double a, b;
   
   std::cout << "ax + b = 0" << std::endl;
   
   std::cout << "   a = ";
   std::cin >> a;
   
   std::cout << "   b = ";
   std::cin >> b;
   
   std::cout << std::endl;   // Wypisujemy na wyjście pustą linię.
   
   double x = -b / a;
   
   std::cout << "Rozwiązanie:" << std::endl << "   x = " << x << std::endl;
   
   return 0;
}