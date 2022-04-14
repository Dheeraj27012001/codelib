#include<stdio.h>
void check(int n)
{
   if(n&1)  //last bit 1
   {
      printf("ODD");
   }
   else
   {
      printf("EVEN");
   }
}

int main()
{
    int n;
    scanf("%d",&n);
    check(n);
}
