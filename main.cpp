/*
 * main.cpp
 *
 *  Created on: Dec 17, 2011
 *      Author: ferraraf
 */


#include "rand_gen.hpp"


int main( int argc, char * argv[] )
{
	if ( argc < 3 || argc > 6 )
	{
		cout << "Wrong number of arguments!\n";

		return -1;
	}

	double min = atof( argv[ 1 ] );
	double max = atof( argv[ 2 ] );
	int n = atof( argv[ 3 ] );

	vector< double > rand_nums = multi_uniGen( n, min, max );

	if ( rand_nums.empty() )
	{
		cout << "n <= 0\n";

		return -2;
	}

	for ( vector< double >::iterator it = rand_nums.begin(); it != rand_nums.end(); it++ )
	{
		cout << *it << endl;

		if ( *it < min || *it > max )
		{
			cout << "Value lies not in the distribution!\n";

			return -3;
		}
	}

	cout << "All values lie in the uniform distribution U[" << min << ", " << max << "]\n";

	double mu = atof( argv[ 4 ] );
	double sigma = atof( argv[ 5 ] );

	rand_nums = multi_normGen( n, mu, sigma );

	for ( vector< double >::iterator it = rand_nums.begin(); it != rand_nums.end(); it++ )
	{
		cout << *it << endl;
	}

	return 0;
}
