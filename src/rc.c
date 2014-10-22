/**
 *  rc.c
 *  Resistor-Capacitor.
 *
 *  @author Nathan Campos <nathanpc@dreamintech.net>
 */

#include "rc.h"
#include <stdio.h>

// Prototypes.
void plot(char *title, double items[], unsigned int n);

/**
 * RC Low-Pass filter.
 *
 * @param items Array which will store the results. (allocated by the function)
 * @param r Resistor value. (Ohms)
 * @param c Capacitor values. (uF)
 * @return Number of values in the results array.
 */
unsigned int rc_lowpass(double items[], unsigned int r, double c) {
	double uc = c * pow(10, -6);

	for (unsigned int f = 1; f < STEPS; f++) {
		double r2 = (1 / (2 * M_PI * f * uc));
		double db = 10 * log10(r2 / (r + r2));

		// TODO: Stop when it reaches -60dB?
		items[f] = db;
	}

	// TODO: Allocate memory dynamically.
	return STEPS;
}

/**
 * RC Low-Pass filter plot.
 *
 * @param r Resistor value. (Ohms)
 * @param c Capacitor values. (uF)
 */
void rc_lowpass_plot(unsigned int r, double c) {
	double items[STEPS];
	unsigned int n = rc_lowpass(items, r, c);

	plot("RC Low-Pass Filter", items, n);
}

/**
 * RC High-Pass filter.
 *
 * @param items Array which will store the results. (allocated by the function)
 * @param r Resistor value. (Ohms)
 * @param c Capacitor values. (uF)
 * @return Number of values in the results array.
 */
unsigned int rc_highpass(double items[], unsigned int r, double c) {
	double uc = c * pow(10, -6);

	for (unsigned int f = 1; f < STEPS; f++) {
		double r2 = (1 / (2 * M_PI * f * uc));
		double db = 10 * log10(r / (r2 + r));

		// TODO: Stop when it reaches -60dB?
		items[f] = db;
	}

	// TODO: Allocate memory dynamically.
	return STEPS;
}

/**
 * RC High-Pass filter plot.
 *
 * @param r Resistor value. (Ohms)
 * @param c Capacitor values. (uF)
 */
void rc_highpass_plot(unsigned int r, double c) {
	double items[STEPS];
	unsigned int n = rc_highpass(items, r, c);

	plot("RC High-Pass Filter", items, n);
}

/**
 * Plots the data.
 *
 * @param title Plot title.
 * @param items Array of doubles.
 * @param n Number of items in the array.
 */
void plot(char *title, double items[], unsigned int n) {
	// Initialize gnuplot.
	gnuplot_ctrl *gp;
	gp = gnuplot_init();

	// Disable the legend.
	gnuplot_cmd(gp, "set key off");

	// Setup the axis.
	gnuplot_set_xlabel(gp, "Frequency (Hz)");
	gnuplot_set_ylabel(gp, "Magnitude (dB)");
	gnuplot_cmd(gp, "set logscale x");
	gnuplot_cmd(gp, "set format x \"%%.0s%%c\"");

	// Plot.
	gnuplot_setstyle(gp, "lines");
	gnuplot_plot_x(gp, items, n, title);
	// TODO: Put label with -3db point somewhere.
	sleep(5);

	gnuplot_close(gp);
}

