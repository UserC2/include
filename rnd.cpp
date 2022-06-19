#include "rnd.h"
#include <cassert>
#include <random>

namespace rnd
{
    /* Default random_device for system. Do not call. */
    std::random_device rdv{};
    /* Seed used to seed Mersenne Twister. Generated using 8 calls to
    * std::random_device. */
    std::seed_seq seed{ rdv(), rdv(), rdv(), rdv(), rdv(), rdv(), rdv(), rdv() };
    /* Mersenne twister used to generate random numbers. */
    std::mt19937 mt{ seed };
    /* Returns a random number between min and max (inclusive). */
    int get(int min, int max)
    {
        std::uniform_int_distribution distribution{ min, max };
        return distribution(mt);
    }
    /* Returns a random number between min and max (exclusive). */
    int getex(int min, int max)
    {
        return get(++min, --max);
    }
    /* Returns true if chance succeeded. Odds is the chance of a successful
    * outcome. It should be a percentage between 0.01 and 1.0 (inclusive). */
    bool chance(double odds)
    {
        // first this assert always returned false if the value was *valid*
        assert(((odds < 1.0) || (odds > 0.01)) 
            && "Random.h: 'odds' out of range");
        int generated{ get(1, 1000) };
        // and then I used >= so the odds were the opposite (e.g. 0.81 = 0.19)
        return (static_cast<double>(generated) <= (odds * 1000));
    }
}