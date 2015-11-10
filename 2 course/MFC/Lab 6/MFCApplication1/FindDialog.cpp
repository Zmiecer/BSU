// FindDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FindDialog.h"
#include "afxdialogex.h"


// FindDialog dialog

IMPLEMENT_DYNAMIC(FindDialog, CDialog)

FindDialog::FindDialog(CWnd* pParent /*=NULL*/)
	: CDialog(FindDialog::IDD, pParent)
	, m_find(_T(""))
{

}

FindDialog::~FindDialog()
{
}

void FindDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FIND, m_find);
	DDV_MaxChars(pDX, m_find, 15);
}


BEGIN_MESSAGE_MAP(FindDialog, CDialog)
END_MESSAGE_MAP()


// FindDialog message handlers
