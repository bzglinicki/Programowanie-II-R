/********************************************************************
 * Programowanie II R
 * Zadania - seria 1.
 * Zadanie 2.
********************************************************************/

#include <iostream>

int main()
{
   std::cout << "ax + b = 0" << std::endl;
   
   double a;
   std::cout << "   a = ";
   std::cin >> a;
   
   double b;
   std::cout << "   b = ";
   std::cin >> b;
   
   // Wypisujemy na wyjście pustą linię.
   std::cout << std::endl;
   
   double x = -b / a;
   
   std::cout << "Rozwiązanie:" << std::endl << "   x = " << x << std::endl;
   
   return 0;
}