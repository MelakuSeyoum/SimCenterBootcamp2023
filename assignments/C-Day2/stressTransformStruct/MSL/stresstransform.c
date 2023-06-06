#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stresstransform.h"

// 
// check out the new function header:
// ... much more compact
// ... much easier to adapt to 3d states of stress (just change STRESS)
//

void StressTransform(STRESS stressIn, STRESS *stressOut, double theta) {

	double pi = 4.0*atan(1.);
	double th = theta * pi/180.;

	double sn = sin(th);
	double cs = cos(th);

	// these next lines need to be adapted to work with the new header ...

	stressOut->sigx = stressIn.sigx*cs*cs + stressIn.sigy*sn*sn + 2.*stressIn.tau*sn*cs;
    stressOut->sigy = stressIn.sigx*sn*sn + stressIn.sigy*cs*cs - 2.*stressIn.tau*sn*cs;
    stressOut->tau  = (stressIn.sigy - stressIn.sigx)*sn*cs + stressIn.tau*(cs*cs - sn*sn);
}

