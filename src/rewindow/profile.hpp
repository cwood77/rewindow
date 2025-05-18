#pragma once

#include "walker.hpp"
#include <map>
#include <string>

class profile {
public:
   class window {
   public:
      bool top;
      rect r;
   };

   std::map<std::string,window> windows;
};
