#include <msp430.h> 
#include <stdio.h>
#include <math.h>


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	float x[25],y[25];
	static const float a1=-1.8,a2=0.8,b0=0.0925,b1=0.335,b2=0.0925;
	int i,j;
	static const int m=25;

	x[0]=1;
	for(i=1;i<m;i++)
	    x[i]=0;

	for(j=0;j<m;j++)
	{
	    y[j]=b0*x[j];
	    if(j>0)
	        y[j]=y[j]+b1*x[j-1]-a1*y[j-1];
	    if(j-1>0)
	        y[j]=y[j]+b2*x[j-2]-a2*y[j-2];
	    printf("%f\t",y[j]);
	}


	return 0;
}
