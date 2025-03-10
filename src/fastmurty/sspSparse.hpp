/**
Michael Motro github.com/motrom/fastmurty 4/2/19
*/
#ifdef SPARSE

#include "subproblem.hpp"
#include "sparsematrix.hpp" // cs_di

typedef cs_di inputmatrixtype;

typedef struct Pathtype{
    double val;
    int i;
    int j;
} Pathtype;

typedef struct WorkvarsforSSP {
	Pathtype* Q;
	int* pathback;
	int m;
	int n;
} WorkvarsforSSP;

WorkvarsforSSP allocateWorkvarsforSSP(int m, int n);

void deallocateWorkvarsforSSP(WorkvarsforSSP workvars);

/*
Runs the successive shortest paths algorithm to find the best association for a problem.
Returns the total cost of the association.
*/
double SSP(cs_di c, Subproblem* prb, WorkvarsforSSP* workvars);

/*
Runs a single shortest path step to find the best association for a subproblem given the
solution to the originating problem.
Returns the increase in cost between the new and originating solutions.
If the increase in cost is greater than cost_bound, stops early and returns infinity.
*/
double spStep(cs_di c, Subproblem* prb, WorkvarsforSSP* workvars, double cost_bound);

#endif
