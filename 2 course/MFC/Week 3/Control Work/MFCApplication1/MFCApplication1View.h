
// MFCApplication1View.h : ��������� ������ CMFCApplication1View
//

#pragma once
#include <vector>

class CMFCApplication1View : public CListView
{
protected: // ������� ������ �� ������������
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// ��������
public:
	CMFCApplication1Doc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���������� � ������ ��� ����� ������������

// ����������
public:
	void FillList();
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnUpdateDelete(CCmdUI *pCmdUI)
	{
		BOOL bEnable = FALSE;
		if (GetListCtrl().GetSelectedCount() > 0)
			bEnable = TRUE;
		pCmdUI->Enable();
	}
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnModifyEdit();
};

#ifndef _DEBUG  // ���������� ������ � MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

