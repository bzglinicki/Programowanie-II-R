/********************************************************************
 * Programowanie II R
 * Zadania - seria 1.
 * Zadanie 4.
********************************************************************/

#include <iostream>
#include <cmath>

/**
 * Funkcja IsPrime
 * ******************************************************************
 * 
 * Zwraca true, gdy argument n jest liczbą pierwszą, lub false
 * w przeciwnym przypadku. Wykorzystujemy zoptymalizowany algorytm
 * opisany np. na stronie https://en.wikipedia.org/wiki/Primality_test
*/
bool IsPrime(int n)
{
   if(n <= 1) return false;   // Te dwie instrukcje można zapisać łącznie:
   if(n <= 3) return true;    //    if(n <= 3) return (n > 1);
   
   if(n%2 == 0 || n%3 == 0) return false;
   
   for(int i = 5; i*i <= n; i += 6) if(n%i == 0 || n%(i+2) == 0) return false;
   
   return true;
}

/**
 * Funkcja NextPrime
 * ******************************************************************
 * 
 * Zwraca najmniejszą liczbę pierwszą większą od liczby całkowitej n.
*/
unsigned int NextPrime(int n)
{
   if(n <= 1) return 2;

   unsigned int result = n;
   bool prime = false;

   while(!prime)
   {
      result++;
      if(IsPrime(result)) prime = true;
   }

   return result;
}

/**
 * Główny kod programu.
*/
int main()
{
   int n;
   std::cout << "Podaj liczbę całkowitą: ";
   std::cin >> n;

   std::cout << "Najmniejsza liczba pierwsza większa od " << n << ": " << NextPrime(n) << std::endl;

   return 0;
}