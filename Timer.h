#ifndef C2_INCLUDE_TIMER_H
#define C2_INCLUDE_TIMER_H
#include <chrono> // for std::chrono functions

/* Instantiate a Timer object to begin timing */
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_type = std::chrono::steady_clock;
	using second_type = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_type> m_beg { clock_type::now() };

public:
	/* Reset the timer to 0 */
	void reset()
	{
		m_beg = clock_type::now();
	}
	/* Returns seconds since clock was reset or created (if not reset) */
	double elapsed() const
	{
		return std::chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
	}
};
#endif
