#include<stdio.h>
#include<stdlib.h>

int main()
{

    float a,b,m,fa,fb,fm;
    a=-15;
    b=-10;

    while(b-a>0.000001)
    {
       m=a+(b-a)/2;
       fa=a*a*a+12*a*a+1;
       fb=b*b*b+12*b*b+1;
       fm=m*m*m+12*m*m+1;

       if(fa*fm<=0) b=m;
       else a=m;
    }

    fa=a*a*a+12*a*a+1;
    printf("%.5f %.5f\n",a,fa);

    system("pause");
    return 0;
}




