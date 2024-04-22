#include "population.h"
#include <iostream>   // this is so that the << redirect operators and 
#include "genome.h"              // cout works
#include "genome.cpp" 
using namespace std;  // we use this so that we do not have to have 
#include <math.h> 


population::population(){
//constructor

 individuals = nullptr
 nIndividuals = 0;
 nCrossover = 1; 
 targetGenome = nullptr;
  
  
}
  
population::~population(){
//destructor

if (individuals != nullptr){

delete individuals;  

individuals = nullptr;

}

nIndividuals = 0;

}


population:: generate_population(int popSize, int nGenes){

nIndividuals = popSize;

individuals = new genome[nIndividuals];

for (int i = 0; i < nIndividuals; ++i){

individuals[i].allocate(nGenes);

}


void population::set_target(Pixel* target, int imageSize) {
    // Sets the target fitness image in the class
    targetGenome = new Pixel[imageSize];
    for (int i = 0; i < imageSize; ++i) {
        targetGenome[i] = target[i];
    }
}


void population::select_parents(){

    int bestIndex1 = 0;
    int bestIndex2 = 1;
    double bestFitness1 = individuals[0].get_fitness();
    double bestFitness2 = individuals[1].get_fitness();
    
    for (int i = 2; i < nIndividuals; ++i) {
            double fitness = individuals[i].get_fitness();
            if (fitness > bestFitness1) {
                bestIndex2 = bestIndex1;
                bestFitness2 = bestFitness1;
                bestIndex1 = i;
                bestFitness1 = fitness;
            } else if (fitness > bestFitness2) {
                bestIndex2 = i;
                bestFitness2 = fitness;
            }
    
        parentIndex1 = bestIndex1;
        parentIndex2 = bestIndex2;
        
}

void population::set_nCrossover(int nCrossover){

  this->nCrossover = nCrossover;


}

int population::get_nCrossover(){


return nCrossover;

}



void population::set_mutation(double mRate){

    for (int i = 0; i < nIndividuals; ++i) {
            individuals[i].set_mRrate(mRate);
        }
}


void generate_new_population(){
// Determine parents selection method
if (useRoulette == 1) {
        // Use roulette selection
        find_roulette_top_individuals();
    } else if (useRoullette == 0) {
        // Use simple top two selection
        select_parents();
    }
    
  int offspring = 1;
  

    // Perform crossover if offspring <= 2, else mutate other individuals
    if (offspring <= 2) {
        int crossoverPoints = get_nCrossover();
        for (int point = 0; point < crossoverPoints; ++point) {
            // Randomly select crossover points
            int crossoverPoint1 = rand() % nGenes;
            int crossoverPoint2 = rand() % nGenes;
            if (crossoverPoint1 > crossoverPoint2) {
                swap(crossoverPoint1, crossoverPoint2);
                
            }

            // Perform crossover between crossover points
            for (int i = crossoverPoint1; i <= crossoverPoint2; ++i) {
                swap(individuals[parentIndex1].genome[i], individuals[parentIndex2].genome[i]);
                offspring++;
            }
        }
    } else {
        // Mutate other individuals
        double mutationRate = get_mutation(); // Get mutation rate from class member
        for (int i = 0; i < nIndividuals; ++i) {
            if (i != parentIndex1 && i != parentIndex2) {
                individuals[i].set_mRrate(mutationRate);
                individuals[i].mutate();
            }
        }
    }

    //Delete current population
    delete[] individuals;
    individuals = nullptr;

    // Create new population
    individuals = new genome[nIndividuals];
    for (int i = 0; i < nIndividuals; ++i) {
        individuals[i].allocate(nGenes);
    }
    
    
}


double calculate_overall_fitness(Pixel* mytarget, int nPixels) {
    int sum = 0;
    for (int i = 0; i < nIndividuals; ++i) {
        sum += individuals[i].calculate_overall_fitness(mytarget, nPixels);
    }
    
    double average = sum / static_cast<double>(nIndividuals);
    return average;
}


void print_parents(){




}



void print_population(){


}


void find_roulette_top_individuals(){



}


//Overload the �<<� operator to output the population using streams. 







