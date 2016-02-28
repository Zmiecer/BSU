#pragma once

#include "MyDoc.h"
#include "msflexgrid1.h"

// RightView form view

class RightView : public CFormView
{
	DECLARE_DYNCREATE(RightView)

protected:
	RightView();           // protected constructor used by dynamic creation
	virtual ~RightView();

public:
	enum { IDD = IDD_RIGHTVIEW };
	CMyDoc* GetDocument() const;
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMsflexgrid1 grid;
	DECLARE_EVENTSINK_MAP()
	void KeyUpMsflexgrid1(short* KeyCode, short Shift);
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual void OnInitialUpdate();
};


