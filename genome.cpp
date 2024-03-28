#include "genome.h"   // this is assuming that the file has the same name as the
                      // class.
#include <iostream>   // this is so that the << redirect operators and 
                      // cout works
using namespace std;  // we use this so that we do not have to have 
                      // "std:" before cout and endl


genome::genome(){
//constructor
  genes = NULL;
  nGenes = 0;
}
  
genome::~genome(){
//destructor
deallocate();


}

// Allocate memory for genes array
void genome::allocate(int numgenes){
if (genes != NULL){

deallocate();

}

nGenes = numgenes;

genes = new Pixel[numgenes];

for (int i = 0; i < nGenes ; ++i) {
// Initialize genes to default values
genes[i].red = 0;
genes[i].green = 0;
genes[i].blue = 0;

}

}

// Deallocate memory for genes array

void genome::deallocate(){
if (genes == NULL){
return;
}

delete[] genes;//free the genes array

nGenes = 0; //set nGenes back to 0

}

void genome::print() {
// Print genes array
   for (int i = 0; i < nGenes ; ++i) {
   
   cout << i + 1 << ". Red: " << genes[i].red << endl;
    cout << i + 1 << ". Green: " << genes[i].green << endl;
     cout << i + 1 << ". Blue: " << genes[i].blue << endl;
   
   }
}

// Randomly assign values to genes array
void genome::randomize(){

srand(time(NULL));

// Generate random number between 0 and 255

for (int i = 0; i < nGenes ; ++i) {
genes[i].red = rand() % 256;
genes[i].green = rand() % 256;
genes[i].blue = rand() % 256;

}

}

// Set the red value of a pixel at a particular index

void genome::set_red(int index, int value){

if (0 <= index < nGenes){
genes[index].red = value;

}
}

// Set the green value of a pixel at a particular index

void genome::set_green(int index, int value){

if (0 <= index < nGenes){
genes[index].green = value;

}
}

// Set the blue value of a pixel at a particular index

void genome::set_blue(int index, int value){

if (0 <= index < nGenes){
genes[index].blue = value;

}
}

// Get the red value of a pixel at a particular index

int genome::get_red(int index){

if (0 <= index < nGenes){

return genes[index].red;

} else {return -1;}

}
// Get the blue value of a pixel at a particular index
int genome::get_blue(int index){

if (0 <= index < nGenes){

return genes[index].blue;

} else {return -1;}

}
// Get the green value of a pixel at a particular index
int genome::get_green(int index){

if (0 <= index < nGenes){

return genes[index].green;

} else {return -1;}

}






