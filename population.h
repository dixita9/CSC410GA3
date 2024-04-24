

class population{
public:

population(); //constructor

~population(); //destructor

void generate_population(int popSize, int nGenes);

void set_target(Pixel* target, int imageSize);

void select_parents();


void set_nCrossover(int nCrossover);


int get_nCrossover();

void set_mutation(double mRate)





private:

int nIndividuals

genome* individuals

int nCrossover

double mutationRate;

Pixel* mytarget;

int nPixels;

int parentIndex1;

int parentIndex2;













}
