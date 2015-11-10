
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
#include "FindDialog.h"
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
	ON_COMMAND(ID_MODIFY_FIND, &CMFCApplication1View::OnModifyFind)
	ON_COMMAND(ID_MODIFY_CLEAR, &CMFCApplication1View::OnModifyClear)
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
	FillList(_T(""));
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
	GetListCtrl().InsertColumn(0, L"Термин", LVCFMT_LEFT, 150);
	GetListCtrl().InsertColumn(1, L"Перевод", LVCFMT_LEFT, 150);
	//GetListCtrl().InsertColumn(2, L"Год поступления", LVCFMT_LEFT, 150);
	// TODO:  Add your specialized creation code here

	return 0;
}

//ID_MODIFY_ADD
void CMFCApplication1View::OnAdd()
{
	CStudentEditDlg dlg;
	dlg.m_strName = "Термин";
	dlg.m_StrSpeciality = "Перевод";
	int k = 1;
	while (k)
	{
		if (IDOK == dlg.DoModal())
		{
			if (dlg.m_strName.GetLength() > 2 && dlg.m_StrSpeciality.GetLength() > 2)
			{
				std::pair<CString, CString> para;
				para.first = dlg.m_strName;
				para.second = dlg.m_StrSpeciality;

				GetDocument()->students.push_back(para);

				GetDocument()->SetModifiedFlag(TRUE);

				GetDocument()->UpdateAllViews(NULL, UPDATE_ADD_STUDENT, NULL);
				k = 0;
			}
			else
			{
				if (dlg.m_strName.GetLength() <= 2)
					MessageBox(L"Введённый термин слишком короток!", L"Ошибка ввода", MB_ICONERROR);
				else
					MessageBox(L"Введённый перевод слишком короток!", L"Ошибка ввода", MB_ICONERROR);
			}

		}
		else
			k = 0;
		//Добавить студента
	}

	
}

void CMFCApplication1View::OnDelete()
{
	CListCtrl& rList = GetListCtrl();
	int n = rList.GetSelectedCount();
	if (n == 1)
	{
		if (IDYES != MessageBox(L"Удалить термин?", L"Подтверждение", MB_YESNO | MB_ICONQUESTION))
		{
			return;
		}
	}
	else
	{
		if (IDYES != MessageBox(L"Удалить термины?", L"Подтверждение", MB_YESNO | MB_ICONQUESTION))
		{
			return;
		}
	}

	

	POSITION pos = rList.GetFirstSelectedItemPosition();

	while (pos)
	{
		int nItem = rList.GetNextSelectedItem(pos);
		GetDocument()->students.erase(GetDocument()->students.begin() + nItem);
	}

	GetDocument()->SetModifiedFlag(TRUE);
	GetDocument()->UpdateAllViews(NULL, UPDATE_DEL_STUDENT, NULL);
}


void CMFCApplication1View::FillList(CString k)
{
	CListCtrl& rList = GetListCtrl();
	rList.DeleteAllItems();
	for (vector<pair<CString, CString>>::iterator it = GetDocument()->students.begin(); it != GetDocument()->students.end(); ++it)
	{
		if (it->first.Find(k) >= 0)
		{
			int nPos = rList.InsertItem(rList.GetItemCount(), it->first, 0);
			CString sSpec;
			sSpec.Format(L"%s", it->second);
			rList.SetItemText(nPos, 1, sSpec);
		}
	}
}

void CMFCApplication1View::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	FillList(_T(""));
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
	CListCtrl& rList = GetListCtrl();
	/*int n = rList.GetSelectedCount();
	if (n == 1)
	{
		if (IDYES != MessageBox(L"Изменить термин?", L"Подтверждение", MB_YESNO | MB_ICONQUESTION))
		{
			return;
		}
	}
	else
	{
		if (IDYES != MessageBox(L"Изменить термины?", L"Подтверждение", MB_YESNO | MB_ICONQUESTION))
		{
			return;
		}
	}*/

	POSITION pos = rList.GetFirstSelectedItemPosition();

	while (pos)
	{
		int nItem = rList.GetNextSelectedItem(pos);
		vector<pair<CString, CString>>::iterator it = GetDocument()->students.begin();
		it += nItem;
		CStudentEditDlg dlg;
		dlg.m_strName = it->first;
		dlg.m_StrSpeciality = it->second;
		int k = 1;
		while (k)
		{
			if (IDOK == dlg.DoModal())
			{
				if (dlg.m_strName.GetLength() > 2 && dlg.m_StrSpeciality.GetLength() > 2)
				{
					GetDocument()->students.erase(GetDocument()->students.begin() + nItem);
					std::pair<CString, CString> para;
					para.first = dlg.m_strName;
					para.second = dlg.m_StrSpeciality;

					GetDocument()->students.insert(GetDocument()->students.begin() + nItem, para);
					GetDocument()->SetModifiedFlag(TRUE);
					GetDocument()->UpdateAllViews(NULL);
					//GetDocument()->students.push_back(para);
					k = 0;
				}
				else
				{
					if (dlg.m_strName.GetLength() <= 2)
						MessageBox(L"Введённый термин слишком короток!", L"Ошибка ввода", MB_ICONERROR);
					else
						MessageBox(L"Введённый перевод слишком короток!", L"Ошибка ввода", MB_ICONERROR);
				}

			}
			else
				k = 0;
		}
	}


	
	// TODO: Add your command handler code here
}


void CMFCApplication1View::OnModifyFind()
{
	FindDialog dlg;
	dlg.m_find = "Поиск";
	CListCtrl& rList = GetListCtrl();
	//rList.SetItemState(1, LVIS_SELECTED, LVIS_SELECTED);
	if (IDOK == dlg.DoModal());
	{
	//	FillList(dlg.m_find);
	//	int i = 0;
	//	dlg.m_find;
	//	rList.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
		int i = 0;
		for (vector<pair<CString, CString>>::iterator it = GetDocument()->students.begin(); it != GetDocument()->students.end(); ++it)
		{
			if (it->first.Find(dlg.m_find) >= 0)
			{
				rList.SetItemState(i, LVIS_SELECTED, LVIS_SELECTED);
				break;
			}
			i++;
		}
	}
	
	
	// TODO: Add your command handler code here
}


void CMFCApplication1View::OnModifyClear()
{
	FillList(_T(""));
	// TODO: Add your command handler code here
}
