#include <msp430.h> 
#include <stdio.h>
#include <math.h>

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	unsigned int x[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	unsigned int h[20]={2,1,3,4,5,7,6,8,9,10,12,11,13,14,15,17,16,18,19,20};
	int y[40];
	static const int m=20;
	int n,k,i;

	for(n=0;n<m;n++)
	{
	    y[n]=0;
	    for(k=0;k<m;k++)
	    {
	        i=(n-k)%m;
	        if(i<0)
	            i+=m;
	        y[n]=y[n]+x[k]*h[i];
	    }
	    printf("%d\t",y[n]);

	}

	return 0;
}
