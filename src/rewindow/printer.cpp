#include "printer.hpp"
#include <iostream>

printer::printer()
{
   std::cout << "; Save this to a file and reuse it with the --apply switch" << std::endl;
   std::cout << "; Remove the windows you don't want to move" << std::endl;
   std::cout << "; Change top(f) to top(t) to also set the window topmost in Z order" << std::endl;
}

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
