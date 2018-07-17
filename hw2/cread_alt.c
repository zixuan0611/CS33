
/* I use -O2 to compile the program and the jump instructions are not involved.
 */ 


long cread(long *xp)
{
   long lianxiao = 0;
   long *zixuan = xp?xp:&lianxiao;
   return *zixuan;
}
