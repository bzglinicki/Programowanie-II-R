#include <iostream>
#include <string>
#include <vector>

int main()
{
   std::vector<std::string> v;
   
   std::string str;
   while(std::cin >> str)
   {
      v.push_back(str);
   }

   std::cout << v.size() << std::endl;

   for(int i = 0; i < v.size(); ++i)
   {
      std::cout << v[i] << " ";
   }
   std::cout << std::endl;
   
   // Instrukcja
   //    for(auto &item: v) { ... }
   // jest skróconą wersją
   //    for(std::string &item: v) { ... }
   for(auto &item: v)
   {
      std::cout << element << " ";
   }
   std::cout << std::endl;

   // Instrukcja
   //    auto it = v.begin()
   // jest skróconą wersją
   //    std::vector<std::string>::iterator it = v.begin()
   for(auto it = v.begin(); it < v.end(); ++it)
   {
      std::cout << *it << " ";
   }
   std::cout << std::endl;

   return 0;
}