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
 * Problem 4
 *
 * A palindromic number reads the same both ways. The largest palindrome
 * made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
  /* We start from the greates palindrome < 1000 * 1000 */
  uint32_t palindrome = 999999;
  uint32_t count = 0, f1 = 0, f2 = 0;

  while ( !(f1 * f2 == palindrome))
    {
      float radix;
      uint16_t i;
      f1 = 0;
      f2 = 0;
      radix = sqrt ((float) palindrome);
      /* Search for the smallest divisor of n in ceil(radix) <= f1 < 1000 */
      for (i = (uint16_t) ceil (radix); (i < 1000) && !(f1); ++i)
        if (palindrome % i == 0)
          f1 = i;

      /* Search for the biggest divisor in 99 < f2 <= ceil(radix) */
      if (f1)
        for (i = (uint16_t) ceil (radix); (i > 99) && !(f2); --i)
          if (palindrome % i == 0)
            f2 = i;

      /* We use count for track how many loop we did */
      ++count;
      /* !(f1 * f2 == palindrome) means f1 o f2 are equals to 0. Probably
		   * f1 = 0 because n have no divisors in [sqrt(n),1000].
		   */
		  if(!(f1 * f2 == palindrome))
		    {
			  /* A new palindrome number will be created */
          if(count % 100 == 0)
            {
              palindrome -= 100001;
              palindrome +=  90090;
              palindrome +=   9900;
            } 
          else if(count % 10 == 0) 
            {
              palindrome -=  10010;
              palindrome +=   9900;
            } 
          else 
            {
              palindrome -=   1100;
            }
        }
		/* Else we've found n and his two divisors and loop will stop */
    }
  printf ("%d * %d = %d\n", f1, f2, palindrome);

  return 0;
}
