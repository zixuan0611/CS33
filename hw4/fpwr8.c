static float u2f(unsigned u)
{
   union{
     unsigned u;
     float    f;
   }lianxiao;
   lianxiao.u = u;
   return lianxiao.f;
}

float fpwr8(int x)
{
   unsigned exp, frac;
   unsigned u;
   if (x < -49){
      exp = 0;
      frac = 0;
   }else if (x < -42){
      exp = 0;
      frac = 1 << (3 * x + 149);
   }else if (x < 43){
      exp = 3 * x + 127;
      frac = 0;
   }else{
      exp = 255;
      frac = 0;
   }
   u = exp << 23 | frac;
   return u2f(u);
}
