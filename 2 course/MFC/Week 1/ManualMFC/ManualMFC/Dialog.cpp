#include <afxwin.h>

#include "resource.h"
#include "Dialog.h"

BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetDlgItemInt(IDC_EDIT1,a);
	return TRUE;
}

void CMyDialog::OnOK()
{
	a=GetDlgItemInt(IDC_EDIT1);
	CDialog::OnOK();
}