#include "commandLine.hpp"

commandLine::commandLine(int argc, const char *argv[])
: m_argc(argc), m_argv(argv)
{
   reset();
}

commandLine& commandLine::reset()
{
   m_i = 1;
   m_good = true;
   m_args.clear();
   return *this;
}

//   0      1
// program arg1 argc=2

commandLine& commandLine::literal(const std::string& l)
{
   if(m_good)
   {
      if(m_i >= m_argc)
         m_good = false;
      else
         m_good = (l == m_argv[m_i++]);
   }
   return *this;
}

commandLine& commandLine::arg()
{
   if(m_good)
   {
      if(m_i >= m_argc)
         m_good = false;
      else
         m_args.push_back(m_argv[m_i++]);
   }
   return *this;
}

std::string commandLine::getArg(int i) const
{
   return m_args[i];
}

bool commandLine::end()
{
   if(m_good)
   {
      if(m_i != m_argc)
         m_good = false;
   }
   return m_good;
}
