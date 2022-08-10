#ifndef C2_INCLUDE_FSTREAMHANDLER_H
#define C2_INCLUDE_FSTREAMHANDLER_H

#include <fstream>
#include <string>

/* fstream with a filename and line count. Checks for errors when constructed. */
class FstreamHandler
{
private:
	std::fstream m_fstream;
	std::string m_filename;
	// changed to std::string in case filename goes out of scope
	const int m_maxLines;
public:
	FstreamHandler(std::string_view filename
		, std::ios_base::openmode mode=std::ios_base::in | std::ios_base::out);
	virtual ~FstreamHandler() = default;
	/* Returns filename. */
	std::string_view filename() const { return m_filename; }
	/* Returns amount of lines in file */
	int maxLines() const { return m_maxLines; }
	/* Call before reading after writing. */
	void read() { m_fstream.seekg(m_fstream.tellg(), std::ios::beg); }
	/* Returns reference to the fstream */
	std::fstream& stream() { return m_fstream; }
	/* Call before writing after reading. */
	void write() { m_fstream.seekp(m_fstream.tellg(), std::ios::beg); }
};

#endif
