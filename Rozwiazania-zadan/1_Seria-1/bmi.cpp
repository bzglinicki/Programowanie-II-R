/********************************************************************
 * Programowanie II R
 * Zadania - seria 1.
 * Zadanie 1.
********************************************************************/

#include <iostream>

int main()
{
   float m;
   std::cout << "Podaj masę ciała (w kilogramach): ";
   std::cin >> m;
   
   float h;
   std::cout << "Podaj wzrost (w metrach): ";
   std::cin >> h;
   
   float bmi = m / (h * h);
   
   std::cout << "BMI = " << bmi << std::endl;
   
   if(bmi < 18.5)
   {
      std::cout << "Niedowaga." << std::endl;
   }
   else if(bmi < 25)
   {
      std::cout << "Waga prawidłowa." << std::endl;
   }
   else if(bmi < 30)
   {
      std::cout << "Nadwaga." << std::endl;
   }
   else
   {
      std::cout << "Otyłość." << std::endl;
   }
   
   return 0;
}