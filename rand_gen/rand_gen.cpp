/*
 * rand_gen.cpp
 *
 *  Created on: Dec 17, 2011
 *      Author: ferraraf
 */


#include "rand_gen.hpp"


// Generate number using an uniform distribution
double uni_gen( double min, double max )
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
	return min + ( double )rand() / ( double )RAND_MAX * ( max - min );
#endif
}

// Generate number using a normal distribution
double norm_gen( double mu, double sigma )
{
#if DEBUG__NORM_GEN
	cout << "mu: " << mu << endl;

	cout << "sigma: " << sigma << endl;
#endif

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
	return mu + sigma * ( U * sqrt( -2 * log( S ) / S ) );
#endif
}

// Generate a multiple number of uniformly distributed numbers
vector< double > multi_uniGen( int n, double min, double max )
{
	// Initialize the random number generator
	srand( ( unsigned int )time( 0 ) );

	vector< double > rand_nums;

	for ( int i = 0; i < n; i++ )
	{
		rand_nums.push_back( uni_gen( min, max ) );
	}
	return rand_nums;
}

// Generate a multiple number of normal distributed numbers
vector< double > multi_normGen( int n, double mu, double sigma )
{
	// Initialize the random number generator
	srand( ( unsigned int )time( 0 ) );

	vector< double > rand_nums;

	for ( int i = 0; i < n; i++ )
	{
		rand_nums.push_back( norm_gen( mu, sigma ) );
	}
	return rand_nums;
}
