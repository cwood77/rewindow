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
   return consumeArg([&](){ m_good = (l == m_argv[m_i++]); });
}

commandLine& commandLine::arg()
{
   return consumeArg([&](){ m_args.push_back(m_argv[m_i++]); });
}

bool commandLine::end()
{
   if(m_good && m_i != m_argc)
      m_good = false;
   return m_good;
}

std::string commandLine::getArg(int i) const
{
   return m_args[i];
}

commandLine& commandLine::consumeArg(std::function<void()> f)
{
   if(!m_good) return *this;

   if(m_i >= m_argc)
      m_good = false;
   else
      f();

   return *this;
}
