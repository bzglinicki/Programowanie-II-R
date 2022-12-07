/********************************************************************
 * Programowanie II R
 * Zadania - seria 9.
 * Zadanie 2.: velocity
********************************************************************/

#include <iostream>

/**
 * Klasa Velocity
 */
class Velocity
{
   private:
      double v;
   public:
      Velocity(double value = 0);
      double Gamma();
      friend Velocity operator+(const Velocity &lhs, const Velocity &rhs);
      friend std::ostream &operator<<(std::ostream &os, const Velocity &obj);
      friend std::istream &operator>>(std::istream &is, Velocity &obj);
};

Velocity::Velocity(double value): v(value) { }

double Velocity::Gamma()
{
   return 1/(1 - v*v);
}

Velocity operator+(const Velocity &lhs, const Velocity &rhs)
{
   return Velocity((lhs.v + rhs.v) / (1 + lhs.v * rhs.v));
}

std::ostream &operator<<(std::ostream &os, const Velocity &obj)
{
   return os << obj.v;
}

std::istream &operator>>(std::istream &is, Velocity &obj)
{
   return is >> obj.v;
}

/**
 * Główny kod programu.
 */
int main ()
{
   Velocity v1, v2;
   std::cin >> v1 >> v2;

   std::cout << "beta = " << v1 + v2 << std::endl;
   std::cout << "gamma = " << (v1 + v2).Gamma() << std::endl;
   return 0;
}