#include "printer.hpp"
#include <iostream>

void printer::print(const window& w) const
{
   if(w.name().empty())
      return;

   std::cout << "top(f) ";

   auto r = w.getRect();
   std::cout << "pos("
      << r.left << ","
      << r.top << ","
      << r.right << "," 
      << r.bottom
   << ") ";

   std::cout << "name: '" << w.name() << "'" << std::endl;
}
