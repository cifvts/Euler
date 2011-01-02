/* Copyright (c) 2011 Andrea Agosti
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

/* Project Euler - http://projecteuler.net
 * Problem 6
 *
 * The sum of the squares of the first ten natural numbers is,
 * 1^(2) + 2^(2) + ... + 10^(2) = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^(2) = 55^(2) = 3025
 *
 * Hence the difference between the sum of the squares of the first 
 * ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first 
 * one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <stdint.h>

#define LIMIT 100

int main()
{
  /* Gauss
	 * 1 + 2 + ... + n = ((n + 1) * n) / 2
	 */
  uint64_t sum_quads = ((LIMIT + 1) * LIMIT) / 2;
  sum_quads *= sum_quads;

  /* 1^2 + 2^2 + ... + n^2 = (n * (n + 1) * (2n + 1)) / 6 */
  uint64_t quads_sum = (LIMIT * (LIMIT +1) * ((LIMIT * 2) + 1)) / 6;
  printf ("%ld\n", sum_quads - quads_sum);

  return 0;
}
