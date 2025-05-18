#include "commandLine.hpp"
#include "error.hpp"
#include "parser.hpp"
#include "printer.hpp"
#include "profile.hpp"
#include "walker.hpp"
#include <iostream>

namespace {

void capture()
{
   printer p;
   windowWalker::walk([&](auto& w){ p.print(w); });
}

void apply(const std::string& filePath)
{
   profile p;
   parser(p).parse(filePath);
}

void printUsage()
{
   std::cout
      << "rewindow - simple window placement/sizing app for Windows" << std::endl
      << "usage:" << std::endl
      << "   --capture      - dump to stdout all current window state" << std::endl
      << "   --apply <file> - apply window state from file" << std::endl
   ;
}

} // anonymous namespace

int main(int argc, const char *argv[])
{
   try
   {
      commandLine cl(argc,argv);

      if(cl.reset().literal("--help").end())
         printUsage();
      else if(cl.reset().literal("--capture").end())
         capture();
      else if(cl.reset().literal("--apply").arg().end())
         apply(cl.getArg(0));
      else
         error(errLoc,"bad usage; use --help")
            .raise();

      return 0;
   }
   catch(std::exception& x)
   {
      std::cerr << "ERROR: " << x.what() << std::endl;
      return -1;
   }
}
