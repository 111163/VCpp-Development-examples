// SerialClass.cpp : 实现文件
//

#include "stdafx.h"
#include "Serialize.h"
#include "SerialClass.h"


// CSerialClass

CSerialClass::CSerialClass()
{
}

CSerialClass::~CSerialClass()
{
}

IMPLEMENT_SERIAL(CSerialClass, CObject, VERSIONABLE_SCHEMA|1)
// CSerialClass 成员函数
void CSerialClass::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_Data << m_Text;
	}
	else
	{
		ar >> m_Data >> m_Text;
	}
}