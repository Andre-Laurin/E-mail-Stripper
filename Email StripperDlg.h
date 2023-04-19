// Email StripperDlg.h : header file
//

#if !defined(AFX_EMAILSTRIPPERDLG_H__5E341F66_23A1_11D7_A9AE_0050BAE2EDE2__INCLUDED_)
#define AFX_EMAILSTRIPPERDLG_H__5E341F66_23A1_11D7_A9AE_0050BAE2EDE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEmailStripperDlg dialog

class CEmailStripperDlg : public CDialog
{
// Construction
public:
	CEmailStripperDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEmailStripperDlg)
	enum { IDD = IDD_EMAILSTRIPPER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmailStripperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEmailStripperDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnStrip();
	afx_msg void OnWhatsthis();
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMAILSTRIPPERDLG_H__5E341F66_23A1_11D7_A9AE_0050BAE2EDE2__INCLUDED_)
