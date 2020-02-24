#ifndef uNioN_FiND
#define uNioN_FiND

#include <vector>

using namespace std;

struct cmpnt{
    int parent = -1;
    int cmp_num = 1;
};

class union_find{
public:
    union_find(); //constructor
    union_find(int m_element); //constructor
		
    int find(int x);
    bool connected(int x, int y);
    void unionSets(int root1, int root2);
    int count(int x);

private:
    vector<cmpnt> s;
};
		
#endif
