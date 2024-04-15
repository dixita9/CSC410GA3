#include "population.h"
#include <iostream>   // this is so that the << redirect operators and 
                      // cout works
using namespace std;  // we use this so that we do not have to have 
#include <math.h> 


population::population(){
//constructor

 individuals = NULL;
 nIndividuals = 0;
 nCrossover = 1; 
  
  
}
  
population::~population(){
//destructor

if (individuals != NULL){

delete individuals;  

individuals = NULL;

}

nIndividuals = 0;

}


population:: generate_population(int popSize, int nGenes){

nIndividuals = popSize;

individuals = new genome[nIndividuals];

for (int i = 0; i < nIndividuals; ++i){

individuals[i].allocate(nGenes);

}
