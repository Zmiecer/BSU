
// MFCApplication1Dlg.h : ���� ���������
//

#pragma once
#include "msflexgrid1.h"


// ���������� ���� CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// ��������
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

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
	DECLARE_EVENTSINK_MAP()
	void KeyUpMsflexgrid1(short* KeyCode, short Shift);
};
