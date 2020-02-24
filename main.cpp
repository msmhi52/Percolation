#include <iostream>
#include "percolation_stats.h"

using namespace std;

int main(int argc, char** argv){
    try{
         PercolationStats pstats(atoi(argv[1]), atoi(argv[2]));
         cout << "mean  =  " << pstats.mean() << "\n" << "stddev  =  " << pstats.stddev() << "\n" << "95%% confidence interval  =  [" << 
             pstats.confidenceLo() << ", " << pstats.confidenceHi() << "]\n";
     }
     catch(const out_of_range& oor){
         cerr << "Out of Range error: " << oor.what() << "\n";
     }
     return 0;
}
	 
