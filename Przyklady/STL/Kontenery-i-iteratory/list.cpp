#include <iostream>
#include <string>
#include <list>

int main()
{
   std::list<std::string> l;

   std::string str;
   while(std::cin >> str)
   {
      l.push_back(str);
   }

   std::cout << l.size() << std::endl;
   
   // Instrukcja
   //    for(auto &item: l) { ... }
   // jest skróconą wersją
   //    for(const std::string &item: l) { ... }
   for(auto &item: l)
   {
      std::cout << item << " ";
   }
   std::cout << std::endl;

   // Instrukcja
   //    auto it = l.begin()
   // jest skróconą wersją
   //    std::list<std::string>::iterator it = l.begin()
   for(auto it = l.begin(); it != l.end(); ++it)
   {
      std::cout << *it << " ";
   }
   std::cout << std::endl;

   return 0;
}
