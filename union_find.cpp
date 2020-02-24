#include "union_find.h"
#include <iostream>
#include <vector>

using namespace std;

union_find::union_find(){}

union_find::union_find(int m_element): s(m_element){
}

int union_find::find(int x){
	if(s[x].parent == -1) return x;
	else{
		s[x].parent = find(s[x].parent);
		return s[x].parent;
	}
}

bool union_find::connected(int x, int y){
	return find(x) == find(y);
}

void union_find::unionSets(int x, int y){
	int root1 = find(x);
	int root2 = find(y);

	if(root1 == root2) return;

	if(s[root1].cmp_num >= s[root2].cmp_num){
		s[root2].parent = root1;
		s[root1].cmp_num += s[root2].cmp_num;
	}
	else{
		s[root1].parent = root2;
		s[root2].cmp_num += s[root1].cmp_num;
	}
}

int union_find::count(int x){
	int root = find(x);
	return s[root].cmp_num;
}
