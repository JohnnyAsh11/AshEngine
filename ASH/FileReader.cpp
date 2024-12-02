#include "pch.h"
#include "FileReader.h"

using namespace ASH;

FileReader* FileReader::m_pInstance = nullptr;

FileReader::~FileReader(void) { Release(); }

FileReader::FileReader(void) {}

FileReader* FileReader::GetInstance(void)
{
	// Instantiating the 
	if (m_pInstance == nullptr)
	{
		m_pInstance = new FileReader();
	}

	return m_pInstance;
}

void FileReader::Release(void)
{
	// Reallocate any memory here.
}

void FileReader::ReleaseInstance(void)
{
	// If there is an instance of the FileReader:
	if (m_pInstance != nullptr)
	{
		// Reallocate the memory.
		Realloc(m_pInstance);
	}
}

String FileReader::ReadFile(String a_sfilepath)
{
	// Initializing the stream reader.
	String fileContent;
	std::ifstream reader(a_sfilepath, std::ios::in);

	// Checking that the file was successfully opened.
	if (reader.is_open())
	{
		String Line = "";

		// Compiling all of the lines in the single string.
		while (getline(reader, Line))
		{
			fileContent += "\n" + Line;
		}

		// Closing the file.
		reader.close();
	}
	else 
	{
		std::cout << "There was an error opening the file." << std::endl;
	}

	return fileContent;
}