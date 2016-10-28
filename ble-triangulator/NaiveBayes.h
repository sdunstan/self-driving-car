#ifndef NAIVE_BAYES_H
#define NAIVE_BAYES_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
  #include <stdint.h>
  #include <cstdlib>
  #include <cmath>
//  #include "WProgram.h"
#endif

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

typedef struct {
    uint8_t id;
    double mean;
    double standardDeviation;
} Model;

typedef struct {
    uint8_t id; // the unique id of the category you are predicting (e.g., left = 1, right = 2, center = 0)
    double probability; // the Bayesian probability of this category given observations
    double softmax; // the softmax function with respect to all categories 
} Category;

class NaiveBayes {
    public:
        NaiveBayes();
        ~NaiveBayes();

        /*
         * Setup the model by adding as many categories as you have.
         */
        NaiveBayes* addModel(const uint8_t id, const double mean, const double standardDeviation);

        /*
         * call classify like so: Category categories[n]; myNaiveBayes.classify(categories, observations);
         * upon return, categories will be populated with the result. We do it like this so that you
         * can use automatic memory allocation instead of worrying about deallocating.
         */
        void classify(Category categories[], const int numCategories, const double observations[], const int numObservations);

    private:
        Model** model;
        uint16_t modelSize;
};

#endif
