#include "NaiveBayes.h"
#include <iostream>

int main() {

    std::cout << "Starting test" << std::endl;
    NaiveBayes* nb = new NaiveBayes();
    Model m1, m2;
    m1.id = 1;
    m1.mean = 0.01;
    m1.standardDeviation = 0.001;
    m2.id = 2;
    m2.mean = 0.02;
    m2.standardDeviation = 0.03;
    nb  ->addModel(1, 0.01, 0.001)
        ->addModel(2, 0.02, 0.002);

    std::cout << "Model is set." << std::endl;

    Category categories[2];
    categories[0].id = 1;
    categories[1].id = 2;
    double observations[2];
    observations[0] = -0.01;
    observations[1] = 0.15;

    nb->classify(categories, 2, observations, 2);

    std::cout << "Category 1 p = " << categories[0].probability << std::endl;
    std::cout << "Category 2 p = " << categories[1].probability << std::endl;

    delete nb;

    return 0;
}
