
// MFCApplication3Dlg.h : ���� ���������
//

#pragma once
#include "msflexgrid1.h"


// ���������� ���� CMFCApplication3Dlg
class CMFCApplication3Dlg : public CDialogEx
{
// ��������
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMsflexgrid1 grid;
};
