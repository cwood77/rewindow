#pragma once

#define WIN32_LEAN_AND_MEAN
#include <functional>
#include <string>
#include <windows.h>

class rect {
public:
   rect();
   rect(RECT& r);
   long width() const;
   long height() const;

   long left;
   long top;
   long right;
   long bottom;
};

class window {
public:
   window(HWND h);

   std::string name() const;
   rect getRect() const;

   void move(const rect& r);
   void bringToTop();

private:
   HWND m_h;
};

class windowWalker {
public:
   static void walk(std::function<void(window&)> f);

private:
   static BOOL CALLBACK thunk(HWND h, LPARAM p);

   windowWalker(std::function<void(window&)> f);
   void walk();
   void onWindow(HWND h);

   std::function<void(window&)> m_f;

   windowWalker(const windowWalker&);
   windowWalker& operator=(const windowWalker&);
};
