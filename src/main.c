/**
 *  eflt
 *  A simple electronic filter calculation.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include <stdlib.h>
#include "rc.h"

int main(int argc, char **argv) {
	//rc_lowpass_plot(1000, 0.1);
	rc_highpass_plot(10000, 1.0);

	return EXIT_SUCCESS;
}

