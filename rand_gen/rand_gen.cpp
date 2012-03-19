/** @file		rand_gen.cpp
 *
 *  @brief		Random number generator
 *
 *  @details	These functions generate random numbers. (Generator for normal
 *  			distributed numbers taken from Wikipedia, http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution)
 *
 * 	@author		Francesco Ferrara
 *
 * 	@date		03/19/2012
 */


#include "rand_gen.hpp"


// Generate number using an uniform distribution
double uni_gen( double min, \
				double max )
{
#if DEBUG__UNI_GEN
	cout << "min: " << min << endl;

	cout << "max: " << max << endl;

	double rand_val = rand();

	cout << "rand(): " << rand_val << endl;

	cout << "RAND_MAX: " << ( double )RAND_MAX << endl;

	cout << "rand() / RAND_MAX: " << rand_val / ( double )RAND_MAX << endl;

	double rand_num = min + rand_val / ( double )RAND_MAX * ( max - min );

	cout << "rand_num: " << rand_num << endl;

	return rand_num;
#else
	// Scale and shift the C++ rand() function
	return min + ( double )rand() / ( double )RAND_MAX * ( max - min );
#endif
}

// Generate number using a normal distribution
double norm_gen( double mu, \
				 double sigma )
{
#if DEBUG__NORM_GEN
	cout << "mu: " << mu << endl;

	cout << "sigma: " << sigma << endl;
#endif

	// Procedure to generate values from a normal distribution (Wikipedia)
	double U, V, S;

	do
	{
		U = uni_gen( -1.0, 1.0 );
		V = uni_gen( -1.0, 1.0 );

		S = U * U + V * V;

#if DEBUG__NORM_GEN
		cout << "U: " << U << endl;

		cout << "V: " << V << endl;

		cout << "S: " << S << endl;
#endif
	}
	while ( S >= 1 );

#if DEBUG__NORM_GEN
	double rand_num = mu + sigma * ( U * sqrt( -2 * log( S ) / S ) );

	cout << "rand_num: " << rand_num << endl;

	return rand_num;
#else
	// Stretch and shift the distribution
	return mu + sigma * ( U * sqrt( -2 * log( S ) / S ) );
#endif
}
