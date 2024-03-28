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
  mRate = 0;
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




//GA2


void set_mRate ( double val) {
  if( 0 < val < 1){
  
   mRate = val
}
}

double get_mRate(){

return mRate

}

void mutate_gene (int index){

for (int i = 0; i < nGenes ; ++i) {

if ((double) rand() % RAND_MAX < mRate){
genes[i].red = rand() % 256;

}

if ((double) rand() % RAND_MAX < mRate){
genes[i].blue = rand() % 256;

}

if ((double) rand() % RAND_MAX < mRate){
genes[i].green = rand() % 256;

}

}

void mutate(){
for (int i = 0; i < nGenes ; ++i) {
mutate_gene(i);

}

}


double calculate_gene-fitness(int index, Pixel targetPixel){



double average = (fabs((taregtPixel.red - gene[index].red) + fabs(taregtPixel.green - gene[index].green ) + fabs(taregtPixel.blue - gene[index].blue)) / 3)/ 256.0

return average;

}

double calculate_overall_fitness(Pixel* target, int nPixel) {

if (nGenes = nPixel){

double totalError = 0.0;

    for (int i = 0; i < nPixels; ++i) {

        double errorRed = fabs(target[i].red - produced[i].red);
        double errorGreen = fabs(target[i].green - produced[i].green);
        double errorBlue = fabs(target[i].blue - produced[i].blue);

        
        totalError += errorRed * errorRed + errorGreen * errorGreen + errorBlue * errorBlue;
    }

   
    double averageError = totalError / nPixels;

    return averageError;

}

}

void set_pixel(int index, Pixel newPixel){

 (0 <= index && index <= nGenes - 1 &&
    0 <= newPixel.red && newPixel.red <= 255 &&
    0 <= newPixel.green && newPixel.green <= 255 &&
    0 <= newPixel.blue && newPixel.blue <= 255){
    
  
  
  genes[index] = newPixel;
    
}
 

}


Pixel get_pixel (int index){

return genes[index];
}










