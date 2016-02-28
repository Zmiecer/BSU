
// MFCApplication3Dlg.h : файл заголовка
//

#pragma once
#include "msflexgrid1.h"


// диалоговое окно CMFCApplication3Dlg
class CMFCApplication3Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMsflexgrid1 grid;
};
