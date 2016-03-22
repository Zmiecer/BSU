
// MFCBinaryTreeDlg.h : файл заголовка
//

#pragma once
#include "afxcmn.h"


// диалоговое окно CMFCBinaryTreeDlg
class CMFCBinaryTreeDlg : public CDialogEx
{
// Создание
public:
	CImageList m_imageList;
	CMFCBinaryTreeDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_MFCBINARYTREE_DIALOG };

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
	void showTreePoint(node treePoint);
	void showTree(int* arr, int arrSize, int i, HTREEITEM hParent, CTreeCtrl* result);
};
