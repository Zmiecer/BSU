#include <afxdlgs.h>
#include "stdafx.h"
#include "resource.h"

class CMyDialog : public CDialog
{
public:
	int a;
	CMyDialog() :CDialog(MAKEINTRESOURCE(IDD_DIALOG1)){};
	BOOL OnInitDialog();
	void OnOK();
};