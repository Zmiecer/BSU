
// MFCApplication1View.h : интерфейс класса CMFCApplication1View
//

#pragma once
#include <vector>

class CMFCApplication1View : public CListView
{
protected: // создать только из сериализации
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// Атрибуты
public:
	CMFCApplication1Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	void FillList();
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// Созданные функции схемы сообщений
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

#ifndef _DEBUG  // отладочная версия в MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

