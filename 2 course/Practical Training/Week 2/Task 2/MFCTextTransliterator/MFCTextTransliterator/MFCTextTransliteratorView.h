
// MFCTextTransliteratorView.h : ��������� ������ CLeftView
//

#pragma once

#include "resource.h"

class CMFCTextTransliteratorDoc;
class CLeftView : public CFormView
{
protected: // ������� ������ �� ������������
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

public:
	enum{ IDD = IDD_MFCTEXTTRANSLITERATOR_FORM };

// ��������
public:
	CMFCTextTransliteratorDoc* GetDocument() const;
	CString text;

// ��������
public:

// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������

// ����������
public:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // ���������� ������ � MFCTextTransliteratorView.cpp
inline CMFCTextTransliteratorDoc* CLeftView::GetDocument() const
   { return reinterpret_cast<CMFCTextTransliteratorDoc*>(m_pDocument); }
#endif

