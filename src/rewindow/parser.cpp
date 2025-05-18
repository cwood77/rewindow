#include "error.hpp"
#include "parser.hpp"
#include "profile.hpp"
#include <cstring>
#include <fstream>

parser::parser(profile& p)
: m_profile(p)
{
}

void parser::parse(const std::string& filePath)
{
   std::ifstream f(filePath);
   if(!f.good())
      error(errLoc,"file can't be loaded")
         .with("path",filePath)
         .raise();

   do
   {
      std::string line;
      std::getline(f,line);
      parseLine(line);
   }
   while(f.good());
}

void parser::parseLine(const std::string& line)
{
   if(line.empty())
      return; // blank line

   if(line.c_str()[0] == ';')
      return; // comments

   // example:
   // top(f) pos(634,0,1286,678) name: parser.cpp (~\dev\rewindow\src\rewindow) - GVIM
   char topC;
   int l,t,r,b,n;
   char name[260];
   ::memset(name,0,260);
   int rval = ::sscanf(
      line.c_str(),
      "top(%c) pos(%d,%d,%d,%d) name: %n",
      &topC,&l,&t,&r,&b,&n
   );
   if(rval != 5)
      error(errLoc,"can't parse line")
         .with("line",line)
         .raise();

   bool top = false;
   if(topC == '1')
      top = true;
   else if(topC == '0')
      ;
   else
      error(errLoc,"illegal value for 'top'")
         .with("line",line)
         .raise();

   auto& w = m_profile.windows[name];
   w.top      = top;
   w.r.left   = l;
   w.r.top    = t;
   w.r.right  = r;
   w.r.bottom = b;
}
