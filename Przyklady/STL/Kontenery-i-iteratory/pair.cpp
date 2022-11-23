#include <iostream>
#include <string>

int main()
{
   std::pair<std::string, double> p;
   p.first = "pi";
   p.second = 3.14;

   std::pair<std::string, double> q("e", 2.72);

   std::cout << p << " " << q << std:endl;

   return 0;
}