#ifndef _PercolaTion__
#define _PercolaTion__

#include <vector>
#include "union_find.h"

using namespace std;

class Percolation{
public:
	Percolation(int n);
	
	bool isOpen(int row, int col);

	void open(int row, int col);

	bool isFull(int row, int col);
	
	int numberOfOpenSites();

	bool percolates();

private:
	vector<vector<int> > grid;
	int open_num;
	int max_ind;
	union_find graph;
};



#endif
