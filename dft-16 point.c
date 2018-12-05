#include <msp430.h> 
#include <stdio.h>
#include <math.h>


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	float x[8]={1,1,1,1,1,1,1,1};
    float y[16];
    float w;
	int n,k,k1;
	static const int m=16;

	for(k=0;k<2*m;k=k+2)
	{
	    y[k]=0;
	    y[k+1]=0;
	    k1=k/2;
	    for(n=0;n<8;n++)
	    {
	        w=-2*3.1415*n*k1/m;
	        y[k]=y[k]+x[n]*cos(w);
	        y[k+1]=y[k+1]+x[n]*sin(w);

	    }
	    printf("%f+j%f\t",y[k],y[k+1]);
	}

	return 0;
}
