
struct Pixel {
int red;
int blue;
int green;
};



class genome {
public:
    genome(); // constructor
    ~genome(); // destructor
    void allocate( int nGenes ); // Allocate memory for genes array
    void deallocate();// Deallocate memory for genes array
    void randomize(); // Randomly assign values to genes array
    void set_red( int index, int value); // Set the red value of a pixel at a particular index
    int get_red( int index); // Get the red value of a pixel at a particular index
    void set_green( int index, int value);  // Set the green value of a pixel at a particular index
    int get_green( int index);  // Get the red value of a pixel at a particular index
    void set_blue( int index, int value);  // Set the blue value of a pixel at a particular index
    int get_blue( int index);  // Get the blue value of a pixel at a particular index
    void print();// Print genes array
    void set_mRate(double val);
    double get_mRate();
    void mutate_gene(int index);
    void mutate();
    double calculate_gene_fitness(int index, Pixel targetPixel);
    double calculate_overall_fitness(Pixel* target, int nPixel);
    void set_pixel(int index, Pixel newPixel);
    Pixel get_pixel(int index);


private:
    Pixel* genes; // Pointer to an array of Pixel structs
    int nGenes; // Number of genes in the genome
    double mRate;
};
