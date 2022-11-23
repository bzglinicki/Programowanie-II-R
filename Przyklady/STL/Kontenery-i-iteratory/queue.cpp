#include <iostream>
#include <string>
#include <queue>

int main()
{
   std::queue<std::string> q;

   std::string str;
   while(std::cin >> str)
   {
      q.push(str);
   }

   std::cout << q.size() << std::endl;

   while(!q.empty())
   {
      std::cout << q.front() << " ";
      q.pop();
   }
   std::cout << std::endl;

   return 0;
}