#ifndef AYDAN_RANDOM_H
#define AYDAN_RANDOM_H

#include <random>

/* Header name should be changed: Identical to standard library <random.h> */

namespace random
{
    /* Default random_device for system. Do not call. */
    extern std::random_device rdv;
    /* Seed used to seed Mersenne Twister. Generated using 8 calls to
    * std::random_device. */
    extern std::seed_seq seed;
    /* Mersenne twister used to generate random numbers. */
    extern std::mt19937 mt;
    /* Returns a random number between min and max (inclusive). */
    int get(int min, int max);
    /* Returns a random number between min and max (exclusive). */
    int getex(int min, int max);
    /* Returns true if chance succeeded. Odds is the chance of a successful
    * outcome. It should be a percentage between 0.01 and 1.0 (inclusive). */
    bool chance(double odds);
}

#endif