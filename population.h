#pragma once
#include <iostream>   // this is so that the << redirect operators and 
#include "genome.h"              // cout works

using namespace std;  // we use this so that we do not have to have 
#include <math.h> 

class population{
public:

population(); //constructor

~population(); //destructor

void generate_population(int popSize, int nGenes);

void set_target(Pixel* target, int imageSize);

void select_parents();


void set_nCrossover(int nCrossover);


int get_nCrossover();

void set_mutation(double mRate);

void generate_new_population(int useRoulette);

double calculate_overall_fitness();

void print_parents();

void print_population();

void find_roulette_top_individuals();


friend std::ostream& operator<<(std::ostream& os, const population& pop);




private:

int nIndividuals;

genome* individuals;

int nCrossover;

double mutationRate;

int nPixels;

int parentIndex1;

int parentIndex2;

Pixel* targetGenome;





};
