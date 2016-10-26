#include "NaiveBayes.h"
#include <iostream>

NaiveBayes::NaiveBayes() {
    this->model = new Model*[0];
    this->modelSize = 0;
}

NaiveBayes* NaiveBayes::addModel(const uint8_t id, const double mean, const double standardDeviation) {
    uint16_t n = this->modelSize;
    Model** temp = new Model*[n+1];
    this->modelSize++;
    for(int i = 0; i < n; i++) {
        temp[i] = this->model[i];
    }
    temp[n] = new Model();
    temp[n]->id = id;
    temp[n]->mean = mean;
    temp[n]->standardDeviation = standardDeviation;

    Model** oldModel = this->model;
    this->model = temp;
    delete oldModel;
    
    return this;
}


void NaiveBayes::classify(Category categories[], const size_t numCategories, const double observations[], const size_t numObservations) {
    size_t n = this->modelSize;

    std::cout << "working on classifing for models of size " << n << std::endl;

    if(n != numCategories || n == 0) return;

    for(int i = 0; i < n; i++) {
        Model* category = this->model[i];
        std::cout << "working on category " << category->id << " mean is " << category->mean << std::endl;
        categories[i].probability = 1.0 / n;
        for(int observationIndex = 0; observationIndex < numObservations; observationIndex++) {
        //resultList[resultList.length-1].p *= (1.0/math.sqrt(2.0 * math.pi * agg.std)) * math.exp( (-math.pow(value- agg.mean, 2)) / (2.0*agg.std) )
            double value = observations[observationIndex];
            categories[i].probability *= (1.0/sqrt(2.0 * M_PI * category->standardDeviation)) * exp( (-pow(value - category->mean, 2)) / (2.0 * category->standardDeviation) );
        }
    }
}