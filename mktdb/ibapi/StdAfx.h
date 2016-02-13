/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once

#ifndef DLLEXP
#define DLLEXP __declspec( dllexport )
#endif

#ifdef _MSC_VER

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define assert ASSERT
#define snprintf _snprintf

// my own:
class CException //: public CObject
{
	// abstract class for dynamic type checking
	//DECLARE_DYNAMIC(CException)

public:
// Constructors
    CException() {}   // sets m_bAutoDelete = TRUE
    explicit CException(BOOL bAutoDelete) {}   // sets m_bAutoDelete = bAutoDelete

// Operations
	void Delete();  // use to delete exception in 'catch' block

	virtual BOOL GetErrorMessage(_Out_z_cap_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
        _Out_opt_ PUINT pnHelpContext = NULL) const {}
	virtual BOOL GetErrorMessage(_Out_z_cap_(nMaxError) LPTSTR lpszError, _In_ UINT nMaxError,
        _Out_opt_ PUINT pnHelpContext = NULL) {}
    virtual int ReportError(UINT nType = MB_OK, UINT nMessageID = 0) {}
};

//#include <afxwin.h>

#endif

