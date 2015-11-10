#pragma once


// CStudentEditDlg dialog

class CStudentEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudentEditDlg)

public:
	CStudentEditDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CStudentEditDlg();

// Dialog Data
	enum { IDD = IDD_DLG_STUDENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_StrSpeciality;
	int m_nYear;
};
