#pragma once

// CSerialClass ÃüÁîÄ¿±ê

class CSerialClass : public CObject
{
public:
	CSerialClass();
	DECLARE_SERIAL(CSerialClass)
public:
	int m_Data;
	CString m_Text;
public:
	virtual void Serialize(CArchive& ar);
public:
	virtual ~CSerialClass();
};


