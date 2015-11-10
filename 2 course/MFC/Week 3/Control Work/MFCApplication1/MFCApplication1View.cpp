
// MFCApplication1View.cpp : реализация класса CMFCApplication1View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "StudentEditDlg.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CListView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CListView)
	ON_WM_CREATE()
	ON_COMMAND(ID_MODIFY_ADD, OnAdd)
	ON_COMMAND(ID_MODIFY_DELETE, OnDelete)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_DELETE, OnUpdateDelete)
	ON_COMMAND(ID_MODIFY_EDIT, &CMFCApplication1View::OnModifyEdit)
END_MESSAGE_MAP()

// создание/уничтожение CMFCApplication1View

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: добавьте код создания

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	GetListCtrl().DeleteAllItems();
	FillList();
	// TODO: ListView можно заполнить элементами посредством непосредственного обращения
	//  к элементам управления этого списка через вызов GetListCtr().
}


// диагностика CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CListView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMFCApplication1View


int CMFCApplication1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	GetListCtrl().InsertColumn(0, L"Фамилия", LVCFMT_LEFT, 150);
	GetListCtrl().InsertColumn(1, L"Специальность", LVCFMT_LEFT, 150);
	GetListCtrl().InsertColumn(2, L"Год поступления", LVCFMT_LEFT, 150);
	// TODO:  Add your specialized creation code here

	return 0;
}

//ID_MODIFY_ADD
void CMFCApplication1View::OnAdd()
{
	CStudentEditDlg dlg;
	dlg.m_strName = "Фамилия";
	dlg.m_StrSpeciality = "Специальность";
	dlg.m_nYear = 2011;
	if (IDOK == dlg.DoModal())
	{
		std::pair<CString, std::pair<CString, int>> para;
		para.first = dlg.m_strName;
		para.second.first = dlg.m_StrSpeciality;
		para.second.second = dlg.m_nYear;

		GetDocument()->students.push_back(para);

		GetDocument()->SetModifiedFlag(TRUE);

		GetDocument()->UpdateAllViews(NULL, UPDATE_ADD_STUDENT, NULL);

		
		//Добавить студента
	}

	
}

void CMFCApplication1View::OnDelete()
{
	if (IDYES != MessageBox(L"Удалить студентов?", L"Подтверждение", MB_YESNO | MB_ICONQUESTION))
	{
		return;
	}

	CListCtrl& rList = GetListCtrl();

	POSITION pos = rList.GetFirstSelectedItemPosition();

	while (pos)
	{
		int nItem = rList.GetNextSelectedItem(pos);
		GetDocument()->students.erase(GetDocument()->students.begin() + nItem);
	}

	GetDocument()->SetModifiedFlag(TRUE);
	GetDocument()->UpdateAllViews(NULL, UPDATE_DEL_STUDENT, NULL);
}


void CMFCApplication1View::FillList()
{
	CListCtrl& rList = GetListCtrl();
	rList.DeleteAllItems();

	for (vector<pair<CString, pair<CString, int>>>::iterator it = GetDocument()->students.begin(); it != GetDocument()->students.end(); ++it)
	{
		int nPos = rList.InsertItem(rList.GetItemCount(), it->first, 0);
		
		CString sSpec;
		sSpec.Format(L"%s", it->second.first);
		rList.SetItemText(nPos, 1, sSpec);

		CString sYear;
		sYear.Format(L"%d", it->second.second);
		rList.SetItemText(nPos, 2, sYear);

	}
}

void CMFCApplication1View::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	FillList();
	/*switch (lHint)
	{
	case UPDATE_ADD_STUDENT:
		break;

	case UPDATE_DEL_STUDENT:
		break;

	case UPDATE_EDIT_STUDENT:
		break;
	}*/
	// TODO: Add your specialized code here and/or call the base class
}


void CMFCApplication1View::OnModifyEdit()
{
	if (IDYES != MessageBox(L"Изменить студентов?", L"Подтверждение", MB_YESNO | MB_ICONQUESTION))
	{
		return;
	}

	CListCtrl& rList = GetListCtrl();

	POSITION pos = rList.GetFirstSelectedItemPosition();

	while (pos)
	{
		int nItem = rList.GetNextSelectedItem(pos);
		vector<pair<CString, pair<CString, int>>>::iterator it = GetDocument()->students.begin();
		it += nItem;
		CStudentEditDlg dlg;
		dlg.m_strName = it->first;
		dlg.m_StrSpeciality = it->second.first;
		dlg.m_nYear = it->second.second;
		GetDocument()->students.erase(GetDocument()->students.begin() + nItem);
		if (IDOK == dlg.DoModal())
		{
			std::pair<CString, std::pair<CString, int>> para;
			para.first = dlg.m_strName;
			para.second.first = dlg.m_StrSpeciality;
			para.second.second = dlg.m_nYear;

			GetDocument()->students.insert(GetDocument()->students.begin() + nItem, para);
			//GetDocument()->students.push_back(para);
		}
	}



	GetDocument()->SetModifiedFlag(TRUE);
	GetDocument()->UpdateAllViews(NULL, UPDATE_DEL_STUDENT, NULL);
	// TODO: Add your command handler code here
}
