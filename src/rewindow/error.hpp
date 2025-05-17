#include <sstream>

#define errLoc __FILE__,__LINE__

class error {
public:
   error(const char *file, unsigned long line, const char *msg);

   template<class T>
   error& with(const std::string& key, const T& value)
   {
      m_stream << std::endl << "   with " << key << " = " << value;
      return *this;
   }

   double raise();

private:
   const char *m_file;
   unsigned long m_line;
   std::stringstream m_stream;
};
