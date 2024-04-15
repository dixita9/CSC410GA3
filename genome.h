// Define a struct to represent a pixel with red, blue, and green color components
struct Pixel {
    int red;
    int blue;
    int green;
};

// Define a class named 'genome' to manage genetic information
class genome {
public:
    genome(); // Constructor
    ~genome(); // Destructor
    void allocate(int nGenes); // Allocate memory for genes array
    void deallocate(); // Deallocate memory for genes array
    void randomize(); // Randomly assign values to genes array
    void set_red(int index, int value); // Set the red value of a pixel at a particular index
    int get_red(int index); // Get the red value of a pixel at a particular index
    void set_green(int index, int value); // Set the green value of a pixel at a particular index
    int get_green(int index); // Get the green value of a pixel at a particular index
    void set_blue(int index, int value); // Set the blue value of a pixel at a particular index
    int get_blue(int index); // Get the blue value of a pixel at a particular index
    void print(); // Print genes array
    void set_mRate(double val); // Set mutation rate
    double get_mRate(); // Get mutation rate
    void mutate_gene(int index); // Mutate a gene at a given index
    void mutate(); // Mutate the genes array
    double calculate_gene_fitness(int index, Pixel targetPixel); // Calculate fitness of a gene compared to a target pixel
    double calculate_overall_fitness(Pixel* target, int nPixel); // Calculate overall fitness of the genome compared to an array of target pixels
    void set_pixel(int index, Pixel newPixel); // Set a pixel at a particular index
    Pixel get_pixel(int index); // Get a pixel at a particular index

private:
    Pixel* genes; // Pointer to an array of Pixel structs representing genes
    int nGenes; // Number of genes in the genome
    double mRate; // Mutation rate
};
