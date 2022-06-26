#pragma once
class CIniFile
{
public:
	CIniFile(void);
	~CIniFile(void);
static bool WriteData(char* pszFileName, char* pApp, char* pszKey, char* pValue);
static unsigned int ReadData(char* pszFileNmae, char* pApp, char* pszKey, char* pValue);
};

