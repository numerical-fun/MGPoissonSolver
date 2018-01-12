#ifndef grid_H
#define grid_H

#include "multigrid.h"

class Grid{
	private:
		const double L; // Lenght of the box to simulate
		const double G; // Gravitational constant, default set to 1.
		vector<Particle> particles;
		vector2d<double> rho; // density 
		vector2d<double> phi;// potential
	
	public:

		const int  MAXGRID; // Grid size
		const double h; // Cell separation 
		vector2d<double> fx; // force, x component
		vector2d<double> fy; // force, y component
		Grid(const int MAXNPART, const double L );
		void add_particle(Particle part);
		void compute_density(); // Assigns density to the grid using CIC 
		double get_density(int, int);
						// mass assignment
		//void potential(); // Computes the gravitational potential on the grid
		void compute_force(); // Computes fx and fy
		vector2d<double> get_fx();
		vector2d<double> get_fy();
};

#endif