#pragma once


#include "MFCTextTransliteratorDoc.h"
#include "afxwin.h"

// CRightView form view

class CRightView : public CFormView
{
	DECLARE_DYNCREATE(CRightView)

protected:
	CRightView();           // protected constructor used by dynamic creation
	virtual ~CRightView();

public:
	enum { IDD = IDD_RIGHTVIEW };
	CMFCTextTransliteratorDoc* GetDocument() const;
	CString text;
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
	CEdit edit;
};


