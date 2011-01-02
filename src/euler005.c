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
* Problem 5
*
* 2520 is the smallest number that can be divided by each of the 
* numbers from 1 to 10 without any remainder.
* 
* What is the smallest number that is evenly divisible by all of 
* the numbers from 1 to 20?
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define TARGET 20

int main()
{
  uint8_t factors[TARGET + 1];
  uint8_t i;
  memset (factors, 0, sizeof (uint8_t) * (TARGET + 1));
  /* We have to count the factors of 2 <= x <= TARGET */
  for (i = 2; i <= TARGET; ++i)
    {
      uint8_t dividend = i;
      uint8_t j;
      for (j = 2; dividend > 1; ++j)
        {
          uint8_t count = 0;
          while (dividend % j == 0)
            {
              dividend /= j;
              ++count;
            }
          /* Only the max num of a factor are relevant */
          if (factors[j] < count)
            {
              factors[j] = count;
            }
        }
    }

  /* Now we can calculate our number */
  double result = 1;
  for (i = 2; i <= TARGET; ++i)
    {
      result *= pow ((double) i, factors[i]);
    }
  printf ("%ld\n", (uint64_t) result);
  return 0;
}
