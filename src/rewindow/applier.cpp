#include "applier.hpp"
#include "profile.hpp"
#include <iostream>

applier::applier(profile& p)
: m_profile(p)
{
}

void applier::apply(window& w) const
{
   auto it = m_profile.windows.find(w.name());
   if(it == m_profile.windows.end())
      return;

   std::cout << "applying profile to window '" << w.name() << "'" << std::endl;
   w.move(it->second.r);
   if(it->second.top)
      w.bringToTop();
}
