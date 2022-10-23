/********************************************************************
 * Programowanie II R
 * Zadania - seria 1.
 * Zadanie 5.
********************************************************************/

#include <iostream>
#include <cmath>
#include <chrono>

/**
 * Funkcja FactorialI
 * ******************************************************************
 * 
 * Oblicza i zwraca silnię liczby naturalnej n, posługując się
 * algorytmem iteracyjnym.
*/
unsigned int FactorialI(unsigned int n)
{
   unsigned int result = 1;
   for(int i = 2; i <= n; ++i) result *= i;
   return result;
}

/**
 * Funkcja FactorialR
 * ******************************************************************
 * 
 * Oblicza i zwraca silnię liczby naturalnej n, posługując się
 * algorytmem rekurencyjnym.
*/
unsigned int FactorialR(unsigned int n)
{
   return (n == 0 || n == 1) ? 1 : n * FactorialR(n - 1);

   // Powyższy kod wykorzystuje operator trójargumentowy ?:. Ten sam
   // kod bez użycia tego operatora miałby następującą postać:
   //    if(n == 0 || n == 1) return 1;
   //    return n * FactorialR(n - 1);
}

/**
 * Główny kod programu.
*/
int main()
{
   unsigned int n;
   std::cout << "Podaj liczbę naturalną: ";
   std::cin >> n;
   std::cout << std::endl;

   // Obliczamy n! wykorzystując algorytm iteracyjny (funkcja FactorialI).
   unsigned int iResult;
   auto iBegin = std::chrono::high_resolution_clock::now();
   iResult = FactorialI(n);
   auto iEnd = std::chrono::high_resolution_clock::now();
   auto iTime = std::chrono::duration_cast<std::chrono::nanoseconds>(iEnd - iBegin).count();

   // Obliczamy n! wykorzystując algorytm rekurencyjny (funkcja FactorialR).
   unsigned int rResult;
   auto rBegin = std::chrono::high_resolution_clock::now();
   rResult = FactorialR(n);
   auto rEnd = std::chrono::high_resolution_clock::now();
   auto rTime = std::chrono::duration_cast<std::chrono::nanoseconds>(rEnd - rBegin).count();

   std::cout << "Silnia liczby " << n << ":" << std::endl;
   std::cout << "   Algorytm iteracyjny:" << std::endl;
   std::cout << "   - wynik:         " << iResult << std::endl;
   std::cout << "   - czas obliczeń: " << iTime << " ns" << std::endl;
   std::cout << "   Algorytm rekurencyjny:" << std::endl;
   std::cout << "   - wynik:         " << rResult << std::endl;
   std::cout << "   - czas obliczeń: " << rTime << " ns" << std::endl;

   return 0;
}