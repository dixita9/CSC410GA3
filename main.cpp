
#include "genome.h" // Include the header file for the genome class
#include "population.h"


int main() {
    srand(time(NULL));
    genome myGenome; // Create an instance of the genome class
    Pixel* myPixel = new Pixel; // Create a pointer to a Pixel object
    myGenome.print(); // Print the genes array (initially empty)
    myGenome.allocate(4); // Allocate memory for genes array with 4 elements
    myGenome.print(); // Print the genes array after allocation
    myGenome.randomize(); // Randomly assign values to genes array
    myGenome.print(); // Print the genes array after randomization
    myGenome.set_blue(0, 226); // Set the blue value of the pixel at index 0
    myGenome.print(); // Print the genes array after setting blue value
    myGenome.get_blue(0); // Get the blue value of the pixel at index 0
    myGenome.print(); // Print the genes array
    myGenome.set_green(0, 226); // Set the green value of the pixel at index 0
    myGenome.print(); // Print the genes array after setting green value
    myGenome.get_green(0); // Get the green value of the pixel at index 0
    myGenome.print(); // Print the genes array
    myGenome.set_red(1, 210); // Set the red value of the pixel at index 1
    myGenome.print(); // Print the genes array after setting red value
    myGenome.get_red(1); // Get the red value of the pixel at index 1
    myGenome.print(); // Print the genes array
    myGenome.set_pixel(3, *myPixel); // Set a pixel at index 3
    myGenome.print(); // Print the genes array after setting pixel
    myGenome.get_pixel(3); // Get the pixel at index 3
    myGenome.print(); // Print the genes array
    myGenome.set_mRate(7.0); // Set mutation rate to 7.0
    myGenome.print(); // Print the genes array after setting mutation rate
    myGenome.get_mRate(); // Get the mutation rate
    myGenome.print(); // Print the genes array
    myGenome.mutate_gene(2); // Mutate gene at index 2
    myGenome.print(); // Print the genes array after gene mutation
    myGenome.mutate(); // Mutate the genes array
    myGenome.print(); // Print the genes array after mutation
    myGenome.calculate_gene_fitness(1, *myPixel); // Calculate fitness of gene at index 1
   // Create a population object
    population myPopulation;
    
    
// Create an array of Pixel objects with size 4
    Pixel* myArray = new Pixel[4];
     // Set the target pixels with 4 elements
    for(int i = 0; i < 4; ++i) {
        myArray[i].red = 17;
        myArray[i].green = 67;
        myArray[i].blue = 98;
    }

// Set the target pixels for the population
    
    myPopulation.set_target(myArray, 4);
    myPopulation.generate_population(10, 4);// Generate a population with 10 individuals, each with 4 pixels
    myPopulation.set_mutation(0.7); // Set the mutation rate for the population to 0.7
    
    
    std::cout << myPopulation << std::endl; // Print the population
    
    myPopulation.select_parents(); // Select parents using simple top two selection
    myPopulation.print_parents(); // Print the selected parents
    
    myPopulation.find_roulette_top_individuals(); // Select parents using roulette wheel selection
    myPopulation.print_parents(); // Print the selected parents

    myPopulation.set_nCrossover(3);
    std::cout << "nCrossover: "<< myPopulation.get_nCrossover() << endl;
    
    cout << "select parents strategy" << endl;
    for(int i = 0; i < 10; ++i){
     //select parents
    myPopulation.generate_new_population(0); 
    
    myPopulation.print_population();
    
    }
    
    
     cout << "Roulette strategy" << endl;
    for(int i = 0; i < 10; ++i){
    
    //Roulette strategy
    
    myPopulation.generate_new_population(1);
    
    cout << "Fitness:" << myPopulation.calculate_overall_fitness() << endl;
    std::cout << myPopulation << std::endl;
   
    }
    
    
    

    delete[] myArray;
    delete myPixel;

    return 0;
}













