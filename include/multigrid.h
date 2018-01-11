#ifndef multigrid_H 
#define multigrid_H 

#include <math.h>
#include "iostream"
#include "vector"
#include "vector3d.cpp"

class Multigrid{
	private:
		int gridlevel;
		int currentstep;
		int maxlevel;
		double h;
		int MAXGRID;

	public:
	vector3d<double> left;
	vector3d<double> right;
	vector3d<double> residual;
	
Multigrid(int gridlevel, int currentstep,
				int maxlevel, double h, int MAXGRID);
	void Initial_conditions(vector3d<double> left, vector3d<double> right, vector3d<double> residual);

	int get_currentstep();
	void restrict(vector3d<double> &aux); // restricts a given quantity to a finer grid via interpolation
		void prolong(vector3d<double> &left);// prolongs a given quantity to a coarser grid via interpolation
		void gauss(int n_iters); // Performs n_iters gauss_seidel steps
		void compute_residual();
		void result(int n_iters0);
		void vcycle(int n_iters);
		//vector3d<double> get_left();

};
vector<int> applyBC(int i, int j, int step, int MAXGRID); // Applies periodic boundary conditions

void print(vector3d<double> &matrix, int, int, int);
#endif
