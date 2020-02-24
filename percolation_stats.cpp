#include <iostream>
#include <stdexcept>
#include <random>
#include <vector>
#include <cmath>
#include "percolation_stats.h"

using namespace std;

PercolationStats::PercolationStats(int n, int trials){
	if(n <= 0 || trials <= 0) throw out_of_range("two inputs must be larger than 0!!");
	
	while(trials--){
		Percolation per_exp(n);
		
		while(!per_exp.percolates()){
			const int range_from = 1;
			const int range_to = n;
			random_device rnd_dev;
			mt19937 generator(rnd_dev());
			uniform_int_distribution<int> distr(range_from, range_to);
			
			int m_row = distr(generator);
			int m_col = distr(generator);

			per_exp.open(m_row, m_col);
		}
			
		vec.push_back(per_exp.numberOfOpenSites()/(double)(n*n));
	}
}
			
double PercolationStats::mean(){
	double mean_val, sum = 0.0;
	for(int i = 0; i < vec.size(); i++){
		sum += vec[i];
	}
	
	return mean_val = sum/vec.size();
}

double PercolationStats::stddev(){
	double sqr_stddev, sum = 0.0;
	double mean_val = mean();
	
	if(vec.size() == 1) return 0;
	
	for(int i = 0; i < vec.size(); i++){
		sum += pow(vec[i] - mean_val, 2);
	}
	
	sqr_stddev = sum/(vec.size()-1);
	
	return sqrt(sqr_stddev);

}

double PercolationStats::confidenceLo(){
	double mean_val = mean();
	double stddev_val = stddev();

	return mean_val - 1.96*stddev_val/sqrt(vec.size());
}

double PercolationStats::confidenceHi(){
	double mean_val = mean();
	double stddev_val = stddev();

	return mean_val + 1.96*stddev_val/sqrt(vec.size());
}
