
// MFCApplication5View.h : ��������� ������ CMFCApplication5View
//

#pragma once


class CMFCApplication5View : public CView
{
protected: // ������� ������ �� ������������
	CMFCApplication5View();
	DECLARE_DYNCREATE(CMFCApplication5View)

// ��������
public:
	CMFCApplication5Doc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����������
public:
	virtual ~CMFCApplication5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���������� ������ � MFCApplication5View.cpp
inline CMFCApplication5Doc* CMFCApplication5View::GetDocument() const
   { return reinterpret_cast<CMFCApplication5Doc*>(m_pDocument); }
#endif

