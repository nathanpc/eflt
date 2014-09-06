/**
 *  rc.h
 *  Resistor-Capacitor.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#ifndef _RC_H
#define _RC_H

#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "gnuplot_i.h"

#define STEPS 100001

unsigned int rc_lowpass(double items[], unsigned int r, double c);
void rc_lowpass_plot(unsigned int r, double c);

#endif
