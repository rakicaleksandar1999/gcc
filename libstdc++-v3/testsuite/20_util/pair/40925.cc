// { dg-options "-std=gnu++0x" }
// { dg-do compile }

// Copyright (C) 2009 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <utility>

struct X
{ 
  explicit X(int, int) { }

private:
  X(const X&) = delete;
};

// libstdc++/40925
void test01()
{
  int *ip = 0;
  int X::*mp = 0;

  std::pair<int*, int*> p1(0, 0);
  std::pair<int*, int*> p2(ip, 0);
  std::pair<int*, int*> p3(0, ip);
  std::pair<int*, int*> p4(ip, ip);

  std::pair<int X::*, int*> p5(0, 0);
  std::pair<int X::*, int X::*> p6(mp, 0);
  std::pair<int X::*, int X::*> p7(0, mp);
  std::pair<int X::*, int X::*> p8(mp, mp);
}
