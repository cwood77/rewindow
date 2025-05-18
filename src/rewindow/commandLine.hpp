#pragma once

#include <functional>
#include <string>
#include <vector>

class commandLine {
public:
   commandLine(int argc, const char *argv[]);

   commandLine& reset();

   commandLine& literal(const std::string& l);

   commandLine& arg();

   bool end();

   std::string getArg(int i) const;

private:
   commandLine& consumeArg(std::function<void()> f);

   const int m_argc;
   const char **m_argv;
   int m_i;
   bool m_good;
   std::vector<std::string> m_args;
};
