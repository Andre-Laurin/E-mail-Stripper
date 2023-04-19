// Email Stripper.h : main header file for the EMAIL STRIPPER application
//

#if !defined(AFX_EMAILSTRIPPER_H__5E341F64_23A1_11D7_A9AE_0050BAE2EDE2__INCLUDED_)
#define AFX_EMAILSTRIPPER_H__5E341F64_23A1_11D7_A9AE_0050BAE2EDE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEmailStripperApp:
// See Email Stripper.cpp for the implementation of this class
//

class CEmailStripperApp : public CWinApp
{
public:
	CEmailStripperApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailStripperApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEmailStripperApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILSTRIPPER_H__5E341F64_23A1_11D7_A9AE_0050BAE2EDE2__INCLUDED_)
