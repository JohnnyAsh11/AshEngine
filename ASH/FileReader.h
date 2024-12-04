#ifndef __FILEREADER_H_
#define __FILEREADER_H_

#include "Definitions.h"
#include <fstream>

namespace ASH
{

/// <summary>
/// Contains functionality for reading from external files.
/// </summary>
class ASH_API FileReader
{
private:
	static FileReader* m_pInstance;

public:
	/// <summary>
	/// Retrieves the instance of the FileReader.
	/// </summary>
	/// <returns>The single instance of the FileReader.</returns>
	static FileReader* GetInstance(void);

	/// <summary>
	/// Removes the single instance of the FileReader from memory.
	/// </summary>
	static void ReleaseInstance(void);

	/// <summary>
	/// Reads the contents of an entire file to a single string and returns that string.
	/// </summary>
	/// <param name="a_sfilepath">The filepath to what is being read in.</param>
	/// <returns>Returns the contents of the file as a single string.</returns>
	String ReadFile(String a_sFilepath = NULL_STR);

private:
	/// <summary>
	/// Constructs an instance of the FileReader object.
	/// </summary>
	FileReader(void);

	/// <summary>
	/// Destructs the instances of the FileReader object.
	/// </summary>
	~FileReader(void);

	/// <summary>
	/// Frees the memory allocated by the FileReader object.
	/// </summary>
	static void Release(void);
};

}

#endif //__FILEREADER_H_