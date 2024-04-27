#include "population.h"
#include <iostream>   // this is so that the << redirect operators and 
              // cout works

using namespace std;  // we use this so that we do not have to have 
#include <math.h> 
#include <vector>
#include <algorithm>


population::population(){
//constructor

 individuals = nullptr;
 nIndividuals = 0;
 nCrossover = 1; 
 targetGenome = nullptr;
 parentIndex1 = -1; 
 parentIndex2 = -1;
  
}
  
population::~population(){
//destructor

if (individuals != nullptr){

  delete[] individuals;  
  
  individuals = nullptr;

}

  nIndividuals = 0;

if (targetGenome != nullptr) {
        delete[] targetGenome;
        targetGenome = nullptr;
    }

}

//generate population

void population:: generate_population(int popSize, int nGenes){

  nIndividuals = popSize; // Set the number of individuals in the population
  
  individuals = new genome[nIndividuals];
  
  for (int i = 0; i < nIndividuals; ++i){
  
    individuals[i].allocate(nGenes);
    individuals[i].randomize(); // Randomize the genome of the individual
    
  }
}


void population::set_target(Pixel* target, int imageSize) {
    // Sets the target fitness image in the class
    if (targetGenome) delete[] targetGenome; // Deletes the existing target genome if it exists
      targetGenome = new Pixel[imageSize];
      nPixels = imageSize;
      // Copy the target image pixels to the target genome
    for (int i = 0; i < imageSize; ++i) {
        targetGenome[i] = target[i];
    }
}



void population::select_parents() {
//select top two parents
    int bestIndex1 = 0;
    int bestIndex2 = 1;
    double bestFitness1 = individuals[0].calculate_overall_fitness(targetGenome, nPixels);
    double bestFitness2 = individuals[1].calculate_overall_fitness(targetGenome, nPixels);
    
    //update the two individuals by calculating fitness
    for (int i = 2; i < nIndividuals; ++i) {
        double fitness = individuals[i].calculate_overall_fitness(targetGenome, nPixels);
        if (fitness > bestFitness1) {
            bestIndex2 = bestIndex1;
            bestFitness2 = bestFitness1;
            bestIndex1 = i;
            bestFitness1 = fitness;
        } else if (fitness > bestFitness2) {
            bestIndex2 = i;
            bestFitness2 = fitness;
        }
    }
    
     // Set parent indices 
    parentIndex1 = bestIndex1;
    parentIndex2 = bestIndex2; 
    
    // Output parent indices for debugging
    
   cout << "Parent Index 1: " << parentIndex1 << endl;
   cout << "Parent Index 2: " << parentIndex2 << endl;

}


void population::set_nCrossover(int nCrossover){

  this->nCrossover = nCrossover; // Set the number of crossovers for the population


}

int population::get_nCrossover(){


return nCrossover; // Retrieve the number of crossovers for the population

}



void population::set_mutation(double mRate){

    for (int i = 0; i < nIndividuals; ++i) {
            individuals[i].set_mRate(mRate); // Set mutation rate for each individual in the population
        
        }
}


void population:: generate_new_population(int useRoulette){
  // Determine parents selection method
  if (useRoulette == 1) {
    // Use roulette selection
    find_roulette_top_individuals();
  } else if (useRoulette == 0) {
    // Use simple top two selection
    select_parents();
  }
      
      
  //initialze offsprings
      
  int offspring1 = 0;
  int offspring2 = 1;
  
  
  bool* check = new bool[nIndividuals]; // a parallel array to keep check of modified individuals
  
  for(int i = 0; i < nIndividuals; ++i){
    check[i] = true;   
  }
      //set parent indices to false
      check[parentIndex1] = false;
      check[parentIndex2] = false;
      
      // Find the first available index for offspring1
  while (check[offspring1] == false){
    offspring1++;
  }
  
  cout << "After first while loop, offspring1: " << offspring1 << ", offspring2: " << offspring2 << endl;
  
  // Mark offspring1 as unavailable for further offspring
  check[offspring1] = false;
  
  // Set offspring2 to the next available index
  offspring2 = offspring1 + 1;
  
  // Find the next available index for offspring2
  while (check[offspring2] == false){
  
   offspring2++;
  
  }

      // Main loop for generating offspring
      
    while (offspring1 < nIndividuals && offspring2 < nIndividuals ){
    
    
      
     cout << "Current offspring1: " << offspring1 << ", offspring2: " << offspring2 << endl;
          
     int crossoverPoint = -1;
     
      
      
      vector<int> crossoverPoints;
      // Generate crossover points ensuring they are not the parents' indices or duplicates
      
      for (int point = 0; point < nCrossover; ++point) {
        while (count(crossoverPoints.begin(), crossoverPoints.end(), crossoverPoint) != 0 || crossoverPoint == parentIndex1 || crossoverPoint == parentIndex2 ){
          crossoverPoint = rand() % nPixels;
        }
        crossoverPoints.push_back(crossoverPoint);
      }
  
  cout << "After third while loop, offspring1: " << offspring1 << ", offspring2: " << offspring2 << endl;
  
        // Apply crossover to generate offspring
        for (int point = 0; point < nPixels; ++point){
        
          if (count(crossoverPoints.begin(), crossoverPoints.end(), point) != 0){
              // Swap parents for crossover
              int temp = parentIndex1;
              parentIndex1 = parentIndex2;
              parentIndex2 = temp;
              cout << "swapping parentIndices " << endl;
    
          }
           // Generate offspring by inheriting pixels from parents
           individuals[offspring1].set_pixel(point, individuals[parentIndex1].get_pixel(point));
           individuals[offspring2].set_pixel(point, individuals[parentIndex2].get_pixel(point));
           cout << "After generating offsprings " << endl;
        
        }
        // Find the next available index for offspring1
          while (check[offspring1] == false && offspring1 < nIndividuals){
            offspring1++;
          }
          
          cout << "After second last while loop, offspring1: " << offspring1 << ", offspring2: " << offspring2 << endl;
         
         if (offspring1 < nIndividuals) check[offspring1] = false;
         
         // Set offspring2 to the next available index
         offspring2 = offspring1 + 1;
         // Mark offspring1 as unavailable for further offspring if within bounds
         while (check[offspring2] == false && offspring2 < nIndividuals){
         
           offspring2++;
     
         }
         // Mark offspring2 as unavailable for further offspring if within bounds
         if (offspring2 < nIndividuals) check[offspring2] = false;
        
        } // end of while loop
        
        // Mutate individuals excluding parents
        
         for (int i = 0; i < nIndividuals; ++i) {
              if (i != parentIndex1 && i != parentIndex2) { //set mutation rate in the main
                  individuals[i].mutate();
                  
              }
           }  
           
           cout << "After mutating " << endl;
           
           
            // Free dynamically allocated memory
    delete[] check;
 
 }
        
        
  
        

//caculate overall fitness of the population
double population::calculate_overall_fitness() {

// Calculate the overall fitness of each individual and add it to the sum.
    double sum = 0;
    for (int i = 0; i < nIndividuals; ++i) {
        sum += individuals[i].calculate_overall_fitness(targetGenome, nPixels);
    }
    // Calculate the average fitness of the population.
    double average = sum / (double) nIndividuals;
    return average;
}


//this fucntion prints parents
void population::print_parents(){

// Check if parents have been set yet.
if (parentIndex1 == -1 || parentIndex2 == -1) {
        cout << "No parents have been set yet." << endl; 
        return;
    }
    // Print parent 1.
    cout << "Parent 1:" << endl;
    individuals[parentIndex1].print();

    // Print parent 2.
    cout << "Parent 2:" << endl;
    individuals[parentIndex2].print();


}


//this fucntion prints the currently generated population
void population::print_population(){

// Print the number of crossover points and mutation rate.
cout << "Number of Crossover Points: " << nCrossover << endl;
    cout << "Mutation Rate: " << mutationRate << endl;
    // Print the overall fitness of the population.
    cout << "Fitness:" << this -> calculate_overall_fitness() << endl;
  // Print each individual in the population.
    cout << "Population:" << endl;
    for (int i = 0; i < nIndividuals; ++i) {
        cout << "Individual " << i << ":" << endl;
        individuals[i].print(); 
        cout << endl;
    }



}

// Function to find the top individuals in the population using roulette wheel selection

void population:: find_roulette_top_individuals(){
// Calculate total fitness of the population
    double totalFitness = 0.0;
    for (int i = 0; i < nIndividuals; ++i) {
        totalFitness += individuals[i].calculate_overall_fitness(targetGenome, nPixels);
    }
    
    // Create a wheel of fitness probabilities
    vector<double> fitness_wheel;
    double cumulativeProbability = 0.0;
    for (int i = 0; i < nIndividuals; ++i) {
    // Calculate relative fitness and accumulate probabilities
        double relativeFitness = individuals[i].calculate_overall_fitness(targetGenome, nPixels) / totalFitness;
        cumulativeProbability += relativeFitness;
        fitness_wheel.push_back(cumulativeProbability);
    }
    
    // Generate random numbers for selection
    double randNum1 = (double)rand() / (double)RAND_MAX; 
    double randNum2 = (double)rand() / (double)RAND_MAX;
    
     randNum1 *= cumulativeProbability;
     randNum2 *= cumulativeProbability;
    

    // Variables to store selected indices
    int selectedIndex1 = -1;
    int selectedIndex2 = -1;

    // Select parent indices using roulette wheel selection
    for (int i = 0; i < nIndividuals; ++i) {
        if (randNum1 <= fitness_wheel[i]) {
            selectedIndex1 = i;
            break;
        }
    }
    // Ensure second parent is different from the first one
    for (int i = 0; i < nIndividuals; ++i) {
        if (randNum2 <= fitness_wheel[i]){
        
          if(i != selectedIndex1) {
            selectedIndex2 = i;
            break;
        } else if (i == nIndividuals -1){
        
        selectedIndex2 = selectedIndex1 -1;
        }
        
        }
    }

    parentIndex1 = selectedIndex1;
    parentIndex2 = selectedIndex2;

}

//Overload the “<<” operator to output the population using streams. 

std::ostream& operator<<(std::ostream& os, const population& pop) {
    os << "Population:" << std::endl;
    // Output each individual in the population
    for (int i = 0; i < pop.nIndividuals; ++i) {
        os << "Individual " << i << ":" << std::endl;
        os << pop.individuals[i];  // Output individual using overloaded << operator
        os << std::endl;
    }
    
    return os;
}














