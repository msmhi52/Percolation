#include <iostream>
#include <vector>
#include <stdexcept>
#include "percolation.h"

using namespace std;

Percolation::Percolation(int n): open_num(0), max_ind(n) {
	if(n <= 0) throw out_of_range("received negative value"); // cannot construct if input is  negative integer 

	grid.assign(n, vector<int>(n, 0)); // assign n*n grid vector
	
	union_find temp_graph(n*n+2); //construct graph of size n*n+2
	graph = temp_graph; //pointer designates temp_graph
	
	for(int i = 0; i<n; i++){
		graph.unionSets(n*n,i); // union tops with making root as n*n.
	}
	for(int i = n*(n-1); i<n*n; i++){
		graph.unionSets(n*n+1, i); //union bottoms with maing root as n*n1.
	}
}

bool Percolation::isOpen(int row, int col){
	if(row <= 0 || col <= 0 || row > max_ind || col > max_ind) throw out_of_range("inputs should be larger than 0 and smaller than n!"); // throw exception
	
	if(grid[row-1][col-1] == 0) return false;
	else return true;
}

void Percolation::open(int row, int col){//if the site was already opened, executes nothing.
	if(!isOpen(row, col)){
		grid[row-1][col-1] = 1; // opens the site (row, col) if it is not open already
		open_num++;

		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};
		for(int i = 0; i < 4; i++){
			int ncol = col + dx[i], nrow = row + dy[i];
			if(ncol <= max_ind && ncol > 0 && nrow <= max_ind && nrow > 0){
				if(isOpen(nrow, ncol)){ // if adjacent indices were already opened
					graph.unionSets(max_ind*(row-1) + col - 1, max_ind*(nrow-1) + ncol -1); // union two elements
				}
			}
		}
	}
}

bool Percolation::isFull(int row, int col){
	if(row <= 0 || col <= 0 || row > max_ind || col > max_ind) throw out_of_range("inputs should be larger than 0 and smaller than n!"); // throw exception

	if(isOpen(row, col)){
		if(graph.connected(max_ind*(row-1) + col-1, max_ind*max_ind)) return true; //does this space is open and connected with top root?
		else return false;
	}

	return false;
}

int Percolation::numberOfOpenSites(){
	return open_num;
}

bool Percolation::percolates(){
	if(graph.connected(max_ind*max_ind, max_ind*max_ind+1)) return true;
	return false;
}


