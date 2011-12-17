/*
 * rand_gen.hpp
 *
 *  Created on: Dec 17, 2011
 *      Author: ferraraf
 */

#ifndef RAND_GEN_HPP_
#define RAND_GEN_HPP_


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>


using namespace std;


#define DEBUG__UNI_GEN 0
#define DEBUG__NORM_GEN 0


// Generate number using an uniform distribution
double uni_gen( double min, double max );


// Generate number using a normal distribution
double norm_gen( double mu, double sigma );


// Generate a multiple number of uniformly distributed numbers
vector< double > multi_uniGen( int n, double min, double max );

// Generate a multiple number of normal distributed numbers
vector< double > multi_normGen( int n, double mu, double sigma );

#endif /* RAND_GEN_HPP_ */
