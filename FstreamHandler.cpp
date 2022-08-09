#include "FstreamHandler.h"

#include "C2Utility.h" // utility::getLines()
#include <exception> // std::runtime_error
#include <fstream>
#include <string>
#include <string_view>

FstreamHandler::FstreamHandler(std::string_view filename)
	: m_fstream{ static_cast<std::string>(filename) }
	, m_filename{ static_cast<std::string>(filename) }
	, m_maxLines{ utility::getLines(m_fstream) }
{
	if (m_fstream.fail())
	{
		throw std::runtime_error(m_filename + " not found or inaccessable.");
	}
}
