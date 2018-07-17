#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y);

int main(void)
{
  return 0;
}

int saturating_add(int x, int y)
{
   int shift = (sizeof(int)<<3)-1;
   int add = x + y;
   int sa = add >> shift;
   int sx = x >> shift;
   int sy = y >> shift;
   int po = sa & ~sx & ~sy;
   int no = ~sa & sx & sy;
   int lianxiao = ((~po & ~no) & add) | (no & INT_MIN) | (po & INT_MAX);
   return lianxiao;
} 
