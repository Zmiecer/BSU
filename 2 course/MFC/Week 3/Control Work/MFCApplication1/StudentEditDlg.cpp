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
	, m_nYear(0)
{

}

CStudentEditDlg::~CStudentEditDlg()
{
}

void CStudentEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_StrSpeciality);
	DDX_Text(pDX, IDC_EDIT3, m_nYear);
	DDV_MinMaxInt(pDX, m_nYear, 2011, 2015);
}


BEGIN_MESSAGE_MAP(CStudentEditDlg, CDialog)
END_MESSAGE_MAP()


// CStudentEditDlg message handlers
