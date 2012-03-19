/** @file		rand_gen.hpp
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

#ifndef RAND_GEN_HPP_
#define RAND_GEN_HPP_


// STL
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>


using namespace std;


/**	@brief	Set to 1 to print out values for debugging of the function uni_gen.
 */
#define DEBUG__UNI_GEN 0

/**	@brief	Set to 1 to print out values for debugging of the function norm_gen.
 */
#define DEBUG__NORM_GEN 0


/**	@brief	Sample a number from an uniform distribution.
 *
 * 	@param min	Low boundary of uniform distribution
 * 	@param max	High boundary of uniform distribution
 *
 * 	@return	Random uniformly generated number
 */
double uni_gen( double min, \
				double max );

/**	@brief	Sample a number from an normal distribution.
 *
 * 	@param mu		Mean of distribution
 * 	@param sigma	Standard deviation of distribution
 *
 * 	@return	Random normal generated number
 */
double norm_gen( double mu, \
				 double sigma );

#endif /* RAND_GEN_HPP_ */
