#include "genome.h" // Include the header file for the genome class

int main() {
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

    return 0;
}













