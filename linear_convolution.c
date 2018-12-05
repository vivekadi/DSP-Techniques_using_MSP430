#include <msp430.h> 
#include <stdio.h>
#include <math.h>
#include <string.h>


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    unsigned int x[8]={1,2,3,4,5,6,7,8};
    unsigned int h[8]={3,3,3,3,3,3,3,3};
    unsigned int y[16];
    static const int xlen=8,hlen=8;
    static const int m=15;
    unsigned int n,k;

    for(n=0;n<m;n++)
    {
        y[n]=0;
        for(k=0;k<hlen;k++)
        {
            if(((n-k)<xlen))
                y[n]=y[n]+x[k]*h[n-k];
        }
        printf("%d\t",y[n]);
    }
    return 0;
}
