#pragma once


// FindDialog dialog

class FindDialog : public CDialog
{
	DECLARE_DYNAMIC(FindDialog)

public:
	FindDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~FindDialog();

// Dialog Data
	enum { IDD = IDD_FIND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_find;
};
