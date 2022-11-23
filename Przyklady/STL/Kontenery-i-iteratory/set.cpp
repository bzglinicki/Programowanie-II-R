#include <iostream>
#include <string>
#include <set>

int main()
{
   std::set<std::string> s;

   std::string str;
   while(std::cin >> str)
   {
      s.insert(str);
   }

   std::cout << s.size() << std::endl;
   
   // Instrukcja
   //    for(auto &item: s) { ... }
   // jest skróconą wersją
   //    for(const std::string &item: s) { ... }
   for(auto &item: s)
   {
      std::cout << item << " ";
   }
   std::cout << std::endl;

   // Instrukcja
   //    auto it = s.begin()
   // jest skróconą wersją
   //    std::set<std::string>::iterator it = s.begin()
   for(auto it = s.begin(); it != s.end(); ++it)
   {
      std::cout << *it << " ";
   }
   std::cout << std::endl;

   return 0;
}