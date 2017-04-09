#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "integrator.h"

#define NBODY 2

void F(double *y, double t, double *res){
 
  res[0] = y[1];
  res[1] = -y[0];

}



int main(int argc, char** argv)

{

  double f[2] = {1, 0};
  double t = 0;
  double dt = atof(argv[1]);
  double tstop = atof(argv[2]);;

	for (; t<tstop-dt/2; t+=dt)	{

		double f_new[2];
		integrate_rk4(f, 2, t, dt, f_new, F);

// Print the output:	
    printf("%6.3f ", t); 
    for(int i=0; i<2; ++i) printf ("%.15e ", f_new[i]); 
    printf ("\n");
//Update value of the function:  
  	for (int i=0; i < 2; ++i) f[i]=f_new[i];
	}

return 0;
}


