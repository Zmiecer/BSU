// StudentEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "StudentEditDlg.h"
#include "afxdialogex.h"


// CStudentEditDlg dialog

IMPLEMENT_DYNAMIC(CStudentEditDlg, CDialog)

CStudentEditDlg::CStudentEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentEditDlg::IDD, pParent)
	, m_strName(_T(""))
	, m_StrSpeciality(_T(""))
{

}

CStudentEditDlg::~CStudentEditDlg()
{
}

void CStudentEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDV_MaxChars(pDX, m_strName, 15);
	//if (m_strName.GetLength() < 2)
	//	AfxMessageBox(_T("Simple message box."));
	DDX_Text(pDX, IDC_EDIT2, m_StrSpeciality);
	DDV_MaxChars(pDX, m_StrSpeciality, 15);
}


BEGIN_MESSAGE_MAP(CStudentEditDlg, CDialog)
END_MESSAGE_MAP()


// CStudentEditDlg message handlers
