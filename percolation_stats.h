#ifndef __PercolaTion_Stats_
#define __PercolaTion_Stats_

#include <vector>
#include "percolation.h"

using namespace std;

class PercolationStats {
public:
	PercolationStats(int n, int trials);

	double mean();

	double stddev();

	double confidenceLo();

	double confidenceHi();

private:
	vector<double> vec;

};	

#endif
