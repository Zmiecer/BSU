#pragma once
#include "msflexgrid1.h"
#include "MFCApplication3Doc.h"


// CRightView form view
//class CMyDoc;

class CRightView : public CFormView
{
	DECLARE_DYNCREATE(CRightView)

protected:
	CRightView();           // protected constructor used by dynamic creation
	virtual ~CRightView();

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
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};


