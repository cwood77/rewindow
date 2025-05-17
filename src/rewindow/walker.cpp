#include "walker.hpp"
#include <memory>

rect::rect()
: left(0), top(0), right(0), bottom(0)
{
}

rect::rect(RECT& r)
: left(r.left), top(r.top), right(r.right), bottom(r.bottom)
{
}

long rect::width() const
{
   return right - left;
}

long rect::height() const
{
   return bottom - top;
}

window::window(HWND h) : m_h(h) {}

std::string window::name() const
{
   char buffer[MAX_PATH];
   ::memset(buffer,0,sizeof(char)*MAX_PATH);
   ::GetWindowTextA(m_h,buffer,MAX_PATH);
   return std::string(buffer);
}

rect window::getRect() const
{
   RECT r;
   ::GetWindowRect(m_h,&r);
   return r;
}

void window::move(const rect& r)
{
   ::MoveWindow(m_h,
      r.left,     // X
      r.top,      // Y
      r.width(),  // nWidth
      r.height(), // nHeight
      TRUE        // bRepaint
   );
}

void window::bringToTop()
{
   ::SetForegroundWindow(m_h);
}

void windowWalker::walk(std::function<void(window&)> f)
{
   windowWalker(f).walk();
}

BOOL CALLBACK windowWalker::thunk(HWND h, LPARAM p)
{
   reinterpret_cast<windowWalker*>(p)->onWindow(h);
   return TRUE; // continue enumeration
}

windowWalker::windowWalker(std::function<void(window&)> f)
: m_f(f)
{
}

void windowWalker::walk()
{
   ::EnumWindows(&thunk,reinterpret_cast<LPARAM>(this));
}

void windowWalker::onWindow(HWND h)
{
   window w(h);
   m_f(w);
}
