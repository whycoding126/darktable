/*
 *    This file is part of darktable,
 *    copyright (c) 2016 johannes hanika.
 *
 *    darktable is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    darktable is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with darktable.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <inttypes.h>

typedef struct tonecurve_t
{
  double x[100]; // input L positions, max 100, assumed to be strictly monotonic x[i+1] > x[i]
  double y[100]; // output L values, max 100, assumed to be monotonic y[i+1] >= y[i]
  int32_t num;   // number of values, max 100
} tonecurve_t;

void tonecurve_create(tonecurve_t *c, const double *Lin, const double *Lout, const int32_t num);

double tonecurve_apply(const tonecurve_t *c, const double L);


double tonecurve_unapply(const tonecurve_t *c, const double L);

// modelines: These editor modelines have been set for all relevant files by tools/update_modelines.sh
// vim: shiftwidth=2 expandtab tabstop=2 cindent
// kate: tab-indents: off; indent-width 2; replace-tabs on; indent-mode cstyle; remove-trailing-spaces modified;
