#pragma once

#include <string>

class profile;

class parser {
public:
   explicit parser(profile& p);

   void parse(const std::string& filePath);

private:
   void parseLine(const std::string& l);

   profile& m_profile;
};
