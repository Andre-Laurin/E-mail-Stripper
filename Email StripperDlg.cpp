// Email StripperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Email Stripper.h"
#include "Email StripperDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailStripperDlg dialog

CEmailStripperDlg::CEmailStripperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmailStripperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmailStripperDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEmailStripperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmailStripperDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEmailStripperDlg, CDialog)
	//{{AFX_MSG_MAP(CEmailStripperDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STRIP, OnStrip)
	ON_BN_CLICKED(IDC_WHATSTHIS, OnWhatsthis)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmailStripperDlg message handlers

BOOL CEmailStripperDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEmailStripperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEmailStripperDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEmailStripperDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CEmailStripperDlg::OnStrip() 
{
	// Alright strip the text ok :)
	
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	CString strData, strTempData, strLine[20];

	// Get how many lines to be stripped are in the edit box
	int m_nCount = pEdit->GetLineCount();
	int nLineLength, nLength[20], nLineMax, nLoop, nSelected, nCounter, nIndex, nTotal;
	int nTempData, nCheckSpace;

	nIndex = nSelected = nCounter = 0;
	nLoop = TRUE;

	nSelected = pEdit->LineIndex(0);
	nLineLength = pEdit->LineLength(nSelected);

	if(nLineLength < 1 && m_nCount == 1) {
		strData = "Oops, nothing to do.";
		AfxMessageBox(strData);
		return FALSE;
	}
	while (nLoop == TRUE)
	{
		nLineMax = 0;
		while (nLineMax < 20 && m_nCount - nLineMax > 0 )
		{
			nTotal = nIndex + nLineMax;
			nSelected = pEdit->LineIndex(nTotal);
			nLineLength = nLength[nLineMax] = pEdit->LineLength(nSelected);
			pEdit->GetLine(nTotal, strData.GetBuffer(nLineLength), nLineLength);
			strData.ReleaseBuffer(nLineLength);

			
			nCheckSpace = TRUE;
			while(nCheckSpace) {				
				if(strData.Left(1) == " ") {
					nTempData = nLineLength;
					strTempData = strData;
					while(strData.Left(1) == " ") {
						strData = strData.Right(nLineLength - 1);
						--nLineLength;
					}
					if(strData.Left(1) != ">") {
						strData = strTempData;
						nLineLength = nTempData;						
						nCheckSpace = FALSE;

					}				
				}						
				while (strData.Left(1) == ">" && nLineLength != -1) {
					if(strData.Left(2) == "> ") {
						strData = strData.Right(nLineLength - 2);
						nLineLength -= 2;
					} else {
						strData = strData.Right(nLineLength - 1);
						--nLineLength;
					}
				}				
				if(strData.Left(1) != " ") nCheckSpace = FALSE;								
			}
			strLine[nLineMax] = strData;
			++nLineMax;					
		}
		for(nCounter = 0; nCounter < nLineMax; nCounter++) {
			nSelected = pEdit->LineIndex(nIndex + nCounter);
			pEdit->SetSel(nSelected, nSelected + nLength[nCounter]);
			pEdit->ReplaceSel(strLine[nCounter]);
		}
		nIndex += nLineMax;
		m_nCount -= nLineMax;
		if(m_nCount < 1) nLoop = FALSE;
	}
	return TRUE;
}

void CEmailStripperDlg::OnWhatsthis() 
{
	// Somewhat of a help file
	
	CString strString;

	strString = "When you forward an e-mail, most e-mail programs will add >> at the\nbeginning of each line. The more an e-mail gets forwarded, the more\n>> are added. Well this program will strip those annoying >> at the\nbeginning of the lines to make it easier to read and/or send someone\nelse a nicer looking e-mail :). Just select your e-mail <ctrl-a>,\ncopy <ctrl-c> it and paste <ctrl-v> into the edit box. Click on the\nStrip E-mail button and voila a nice clean e-mail. Read away, or if you\nprefer select your clean e-mail <ctrl-a>, copy <ctrl-c> and paste\n<ctrl-v> into whatever program you want.\nYou can also just right mouse click in the box to get a list\nof commands instead of using the keyboard shortcuts like <ctrl-c>.";
	AfxMessageBox(strString);
	
}

void CEmailStripperDlg::OnAbout() 
{
	// About me :)

	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}
