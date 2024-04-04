#include "genome.h"
int main() {
  genome myGenome;
  Pixel* myPixel = new Pixel;
  myGenome.print();
  myGenome.allocate(4);
  myGenome.print();
  myGenome.randomize();
  myGenome.print();
  myGenome.set_blue(0, 226);
  myGenome.print();
  myGenome.get_blue(0);
  myGenome.print();
  myGenome.set_green(0, 226);
  myGenome.print();
  myGenome.get_green(0);
  myGenome.print();
  myGenome.set_red(1, 210);
  myGenome.print();
  myGenome.get_red(1);
  myGenome.print();
  myGenome.set_pixel(3, *myPixel);
  myGenome.print();
  myGenome.get_pixel(3);
  myGenome.print();
  myGenome.set_mRate(7.0);
  myGenome.print();
  myGenome.get_mRate();
  myGenome.print();
  myGenome.mutate_gene(2);
  myGenome.print();
  myGenome.mutate();
  myGenome.print();
  myGenome.calculate_gene_fitness(1, *myPixel);
  

  return 0;
}












