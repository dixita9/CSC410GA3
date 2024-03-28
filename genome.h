
struct Pixel {
int red;
int blue;
int green;
};



class genome {
public:
    genome(); // constructor
    ~genome(); // destructor
<<<<<<< HEAD
    void allocate( int nGenes );/ // Allocate memory for genes array
    void deallocate();// Deallocate memory for genes array
    void randomize(); // Randomly assign values to genes array
    void set_red( int index, int value); // Set the red value of a pixel at a particular index
    int get_red( int index); // Get the red value of a pixel at a particular index
    void set_green( int index, int value);  // Set the green value of a pixel at a particular index
    int get_green( int index);  // Get the red value of a pixel at a particular index
    void set_blue( int index, int value);  // Set the blue value of a pixel at a particular index
    int get_blue( int index);  // Get the blue value of a pixel at a particular index
    void print();// Print genes array
=======
    void allocate( int nGenes );
    void deallocate();
    void randomize();
    void set_red( int index, int value); 
    int get_red( int index);  
    void set_green( int index, int value);  
    int get_green( int index);  // I added the other two
    void set_blue( int index, int value);  
    int get_blue( int index);  
    void print();
>>>>>>> dc7eb94674d9a35c726d1ee559103cc253ce44d3

private:
    Pixel* genes; // Pointer to an array of Pixel structs
    int nGenes; / Number of genes in the genome
};
