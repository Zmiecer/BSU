
// MFCApplication5Doc.cpp : реализация класса CMFCApplication5Doc
//

#include "stdafx.h"
#include <vector>
using namespace std;
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication5Doc

IMPLEMENT_DYNCREATE(CMFCApplication5Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplication5Doc, CDocument)
END_MESSAGE_MAP()


// создание/уничтожение CMFCApplication5Doc

CMFCApplication5Doc::CMFCApplication5Doc()
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CMFCApplication5Doc::~CMFCApplication5Doc()
{
}

BOOL CMFCApplication5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// сериализация CMFCApplication5Doc

void CMFCApplication5Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << v.size();
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			ar << *it;
	}
	else
	{
		int k;
		ar >> k;
		while (k)
		{
			int x;
			ar>>x;
			v.push_back(x);
			k--;
		}
	}
}

void CMFCApplication5Doc::DeleteContents()
{
	v.erase(v.begin(), v.end());
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CMFCApplication5Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CMFCApplication5Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задайте содержимое поиска из данных документа. 
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CMFCApplication5Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// диагностика CMFCApplication5Doc

#ifdef _DEBUG
void CMFCApplication5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplication5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// команды CMFCApplication5Doc
