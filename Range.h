#ifndef C2_INCLUDE_RANGE_H
#define C2_INCLUDE_RANGE_H

#ifdef RANGE_HAS_RANDOM
#include "rnd.h"
#endif

/* Define RANGE_HAS_RANDOM to access randomWithin(). 
* Only use RANGE_HAS_RANDOM if T is an integral type. */
template <typename T>
class Range
{
private:
	T m_min{};
	T m_max{};

public:
	constexpr Range(T lower, T upper)
		: m_min{ lower }
		, m_max{ upper }
	{
	}

	/* Returns lower range */
	constexpr T min() { return m_min; }
	/* Returns upper range */
	constexpr T max() { return m_max; }

	/* Returns true if value is within the range. Inclusive. */
	constexpr bool within(T value) const
	{
		return (value <= m_max) && (value >= m_min);
	}

#ifdef RANGE_HAS_RANDOM
	/* Returns random number within range (inclusive). */
	T randomWithin() const
	{
		return static_cast<T>(rnd::get(m_min, m_max));
	}

	/* Returns random number within range (exclusive). */
	T randomWithinEx() const
	{
		return static_cast<T>(rnd::getex(m_min, m_max));
	}
#endif
};

#endif
