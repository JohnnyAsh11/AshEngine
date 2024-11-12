#include "Definitions.h"
#include <iostream>

class FileReader
{
private:
	FileReader* m_fInstance;

public:
	FileReader GetInstance(void);
private:
	FileReader();
	~FileReader(void);

};