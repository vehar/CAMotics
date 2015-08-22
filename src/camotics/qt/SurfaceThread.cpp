/******************************************************************************\

    CAMotics is an Open-Source CAM software.
    Copyright (C) 2011-2015 Joseph Coffland <joseph@cauldrondevelopment.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#include "SurfaceThread.h"

#include <cbang/util/DefaultCatch.h>

#include <limits>

using namespace std;
using namespace CAMotics;


void SurfaceThread::run() {
  try {
    if (!time) time = numeric_limits<double>::max();
    surface = cutSim->computeSurface(path, bounds, resolution, time);
  } CATCH_ERROR;
  completed();
}