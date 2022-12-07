/********************************************************************
 * Programowanie II R
 * Zadania - seria 9.
 * Zadanie 3.: rational
********************************************************************/

#include <iostream>
#include <cmath>

/**
 * Klasa RationalNumber
 */
class RationalNumber
{
   int p, q;
   int nwd(int m, int n);

   public:
      RationalNumber(int p = 0, int q = 1);
      int Numerator() const;
      int Denominator() const;

   operator double() const;
   operator string() const;
   RationalNumber operator-() const;
   RationalNumber &operator++();
   RationalNumber operator++(int);
   RationalNumber &operator+=(const RationalNumber &s);
   RationalNumber &operator*=(const RationalNumber &s);

   friend std::ostream &operator<<(std::ostream &stream, const RationalNumber &r);
   friend std::istream &operator>>(std::istream &stream, RationalNumber &r);

   friend RationalNumber operator+(const RationalNumber &r, const RationalNumber &s);
   friend RationalNumber operator*(const RationalNumber &r, const RationalNumber &s);

   friend bool operator<(const RationalNumber &r, const RationalNumber &s);
};

int RationalNumber::nwd(int m, int n)
{
   int c;   
   while(n)
   {
      c = m%n;
      m = n;
      n = c;
   }
   return m;
}

RationalNumber::RationalNumber(int p, int q)
{
   this->p = p / nwd(abs(p),abs(q));
   this->q = q / nwd(abs(p),abs(q));

   if(q < 0)
   {
      this->p = -(this->p);
      this->q = -(this->q);
   }
}

int RationalNumber::numerator() const
{
   return p;
}

int RationalNumber::denominator() const
{
   return q;
}

std::ostream &operator<<(std::ostream &stream, const RationalNumber &r)
{
   /*
   stream << r.p << "/" << r.q;
   return stream;
   */

   // Krótsza wersja:
   return stream << r.p << "/" << r.q;
}

std::istream &operator>>(std::istream &stream, RationalNumber &r)
{
   char c; // służy do pominięcia znaku "/" w zapisie liczby
   /* Można po prostu tak:
         return stream >> r.p >> c >> r.q;
      jednak wtedy nie uzyskamy skracania (np. 2/4 nie przejdzie w 1/2), bo nie wywołujemy kostruktora.
   */

   stream >> r.p >> c >> r.q;
   r = RationalNumber(r.p, r.q);
   return stream;
}

RationalNumber::operator double() const
{
   return (double) p / q;
}

RationalNumber RationalNumber::operator-() const
{
   return RationalNumber(-p, q);
}

RationalNumber &RationalNumber::operator++()
{
   p += q;
   return *this;
}

RationalNumber RationalNumber::operator++(int)
{
   RationalNumber temp = *this;
   ++*this;
   return temp;
}

/* Bez wykorzystania operatora +:
RationalNumber &RationalNumber::operator+=(const RationalNumber &s)
{
   int wm = q * s.q;
   int pr = p * s.q;
   int ps = s.p * q;
   
   return *this = RationalNumber(pr + ps, wm);
   //return RationalNumber(p * s.q + s.p * q, q * s.q); - wersja jednolinijkowa
}
*/

RationalNumber &RationalNumber::operator+=(const RationalNumber &s) //wersja z wykorzystaniem operatora +
{
   return *this = *this + s;
}

RationalNumber &RationalNumber::operator*=(const RationalNumber &s)
{
   return *this = RationalNumber(p * s.p, q * s.q);
}

RationalNumber operator+(const RationalNumber &r, const RationalNumber &s)
{
   return RationalNumber(r.p * s.q + s.p * r.q, r.q * s.q);
}

RationalNumber operator*(const RationalNumber &r, const RationalNumber &s)
{
   return RationalNumber(r.p * s.p, r.q * s.q);
}

bool operator<(const RationalNumber &r, const RationalNumber &s) //niezbędny do dynamicznych struktur danych typu Map itp.
{
   return (r.p * s.q) < (r.q * s.p);
}

/**
 * Główny kod programu.
 */
int main()
{   
   RationalNumber r, s;
   std::cin >> r >> s;

   std::cout << (double)r << " " << (double) s << std::endl;
   std::cout << -r << " " << -s << std::endl;

   if(r < s)
   {
	   std::cout << r << " " << s << std::endl;
   }
   else
   {
	   std::cout << s << " " << r << std::endl;
   }
   
   std::cout << r + s << " " << r * s << std::endl;
   
   return 0;
}
