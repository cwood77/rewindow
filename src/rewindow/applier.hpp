#pragma once

#include "walker.hpp"

class profile;

class applier {
public:
   explicit applier(profile& p);

   void apply(window& w) const;

private:
   profile& m_profile;
};
