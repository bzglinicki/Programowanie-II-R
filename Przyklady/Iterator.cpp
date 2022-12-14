/*******************************************************************
 * Programowanie II R
 * Przykład: Iterator.
 * *****************************************************************
 * Przykład przedstawia tworzenie własnych iteratorów w stylu
 * standardu C++17.
 * *****************************************************************
 * Opracowano na podstawie:
 *    https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
 *******************************************************************/

#include <iostream>
#include <iterator>
#include <cstddef>

/**
 * Klasa IntContainer
 * 
 * Przykładowy prosty kontener, który wykorzystamy do zilustrowania towrzenia iteratora.
 * Kontener ten jako wewnętrzną strukturę danych będzie wykorzystywał tablicę. Przyjmujemy,
 * że chcemy w naszym kontenerze przechowywać liczby całkowite w ilości nie większej niż 10.
 * Tablica, w której je umieścimy, będzie prywatna, co uniemożliwi użytkownikowi naszego kontenera
 * bezpośredni dostęp do jej elementów - jest to rozwiązanie eleganckie i często niezbędne.
 * Zadaniem iteratora będzie właśnie zapewnienie dostępu do danych zawartych w tej tablicy.
 */
class IntContainer
{
public:
   /**
    * Iterator dla kontenera IntContainer
	*
	* W przykładzie tym utworzymy jeden z najprostszych typów iteratora - tzw. iterator jednokierunkowy
	* (ang. forward iterator). Iterator tego typu może wielokrotnie przebiegać po kontenerze, ale tylko
	* w kierunku "do przodu" (tzn. "od begin to end"), oraz odczytywać i modyfikować wartość elementu, na
	* który wskazuje. Iterator taki można łatwo rozbudować - na przykład dodanie operatorów predekrementacji
	* i postdekrementacji (--) zamieni go w operator dwukierunkowy (ang. bidirectional iterator).
	* 
	* Iterator dla kontenera implementujemy jako strukturę (czyli klasę, której składowe - pola oraz
	* metody - są domyślnie publiczne) zdefiniowaną wewnątrz klasy kontenera.
	*/
   struct Iterator
   {
      // Tagi iteratora - określają typ iteratora oraz typ iterowanych przez niego danych.
	  using iterator_category = std::forward_iterator_tag;   // Typ iteratora: forward iterator.
      using difference_type   = std::ptrdiff_t;
      using value_type        = int;                         // Typ danych: int.
      using pointer           = value_type*;
      using reference         = value_type&;

      // Konstruktor iteratora.
	  Iterator(pointer ptr) : m_ptr(ptr) {}

      // Operatory przeciążone dla iteratora.
	  reference operator*() const { return *m_ptr; }                              // Operator dereferencji *.
      pointer operator->() { return m_ptr; }                                      // Operator dostępu do składowych dla wskaźnika ->.
      Iterator& operator++() { m_ptr++; return *this; }                           // Operator preinkrementacji ++.
      Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }   // Operator postinkrementacji ++.
      friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };   // Operator porównania ==.
      friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };   // Operator porównania !=.  

   private:
      // Wewnętrzny wskaźnik iteratora - będzie to wskaźnik na ten element tablicy, na który iterator
	  // aktualnie wskazuje.
	  pointer m_ptr;
   }; // Koniec struktury Iterator - ciąg dalszy to już składowe nadrzędnej klasy IntContainer.

   // Metoda begin w klasie kontenera zwraca iterator wskazujący na pierwszy z elementów
   // przechowywanych przez kontener.
   Iterator begin() { return Iterator(&m_data[0]); }
   
   // Metoda end w klasie kontenera zwraca iterator wskazujący na "pierwszy po ostatnim" z elementów
   // przechowywanych przez kontener - element ten oczywiście nie istnieje, jest to jednak wygodna konwencja.
   Iterator end()   { return Iterator(&m_data[10]); }

private:
   // Wewnętrzna struktura danych kontenera IntContainer - tablica dziesięciu liczb całkowitych.
   int m_data[10];
};


/**
 * Główny kod programu.
 *
 * Celem programu jest przetestowanie naszego iteratora.
 */
 
int main()
{
   IntContainer c;
   
   int i = 100;
   for(auto it = c.begin(); it != c.end(); ++it)
   {
      *it = i;
	  i += 100;
   }
   
   for(auto it = c.begin(); it != c.end(); ++it)
   {
      std::cout << *it << " ";
   }
   std::cout << std::endl;
   
   for(auto item: c)
   {
      std::cout << item << " ";
   }
   std::cout << std::endl;
   
   return 0;
}