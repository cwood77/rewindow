#include "error.hpp"

error::error(const char *file, unsigned long line, const char *msg)
: m_file(file), m_line(line)
{
   m_stream << msg << " [" << file << ":" << line << "]";
}

double error::raise()
{
   throw std::runtime_error(m_stream.str());
   return 3.14;
}
