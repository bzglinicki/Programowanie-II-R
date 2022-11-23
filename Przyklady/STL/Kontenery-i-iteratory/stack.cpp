#include <iostream>
#include <string>
#include <stack>

int main()
{
   std::stack<std::string> s;

   std::string str;
   while(std::cin >> str)
   {
      s.push(str);
   }

   std::cout << s.size() << std::endl;

   while(!s.empty())
   {
      std::cout << s.top() << " ";
      s.pop();
   }
   std::cout << std::endl;

   return 0;
}