#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y);

int main(void)
{
     return 0;
}

int saturating_add(int x, int y)
{
   int add = x + y;
   int shift = (sizeof(int)<<3)-1;
   int nf = ~((__builtin_add_overflow_p(x, y, (__typeof__((x)+(y)))0))<<shift>>shift);
   int sa = add >> shift;
   int sx = x >> shift;
   int sy = y >> shift;
   int po = sa & ~sx & ~sy;
   int no = ~sa & sx & sy;
   int lianxiao = (po & INT_MAX) | (nf & add) | (no & INT_MIN);
        return lianxiao;
}
