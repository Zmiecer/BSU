// RightView.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "RightView.h"
#include <fstream>
#include <cstring>
#include <sstream>
#include <map>


// RightView

IMPLEMENT_DYNCREATE(RightView, CFormView)

RightView::RightView()
	: CFormView(RightView::IDD)
{

}

RightView::~RightView()
{
}

void RightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSFLEXGRID1, grid);
}

BEGIN_MESSAGE_MAP(RightView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &RightView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &RightView::OnBnClickedButton2)
END_MESSAGE_MAP()


// RightView diagnostics

#ifdef _DEBUG
void RightView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void RightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// RightView message handlers
BEGIN_EVENTSINK_MAP(RightView, CFormView)
	ON_EVENT(RightView, IDC_MSFLEXGRID1, DISPID_KEYUP, RightView::KeyUpMsflexgrid1, VTS_PI2 VTS_I2)
END_EVENTSINK_MAP()


void RightView::KeyUpMsflexgrid1(short* KeyCode, short Shift)
{
	// TODO: Add your message handler code here
	int x = _ttoi(grid.get_Text());
	if (*KeyCode >= 48 && *KeyCode <= 57)
	{
		x *= 10;
		x += *KeyCode - 48;
	}
	if (*KeyCode == 189 && grid.get_Text() != "")
	{
		x *= -1;
	}
	if (*KeyCode == 8)
	{
		x /= 10;
	}
	CString tmp;
	tmp.Format(_T("%d"), x);
	grid.put_Text(tmp);
	//GetDocument()->arr.insert(std::make_pair(std::make_pair(grid.get_Row(), grid.get_Col()), x));
	GetDocument()->arr[std::make_pair(grid.get_Row(), grid.get_Col())] = x;

	if (*KeyCode == 46)
	{
		CString tmp = _T("");
		grid.put_Text(tmp);

		GetDocument()->arr.erase(std::make_pair(grid.get_Row(), grid.get_Col()));
	}

	GetDocument()->UpdateAllViews(this);
}

CMyDoc* RightView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}

void RightView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class
	if (!GetDocument()->arr.empty())
	{
		//grid.put_Rows(GetDocument()->arr.rbegin()->first.first);
		//grid.put_Cols(GetDocument()->arr.rbegin()->first.second);
		for (std::map<std::pair<int, int>, int>::iterator it = GetDocument()->arr.begin(); it != GetDocument()->arr.end(); ++it)
		{
			it->first.first;
			CString tmp;
			tmp.Format(_T("%d"), it->second);
			grid.put_TextMatrix(it->first.first, it->first.second, tmp);
		}
	}
}



void RightView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	
	CFileDialog fileDialog(true, NULL, NULL, OFN_HIDEREADONLY | OFN_NOCHANGEDIR, _T("Text files (*.txt)|*.txt|All files (*.*)|*.*||"));
	if (fileDialog.DoModal() == IDOK)
	{
		grid.Clear();
		GetDocument()->arr.clear();
		std::ifstream fin;
		fin.open(fileDialog.GetPathName());
		bool ok = true;
		bool coma = false;
		int nCount = 0;
		std::map<std::pair<int, int>, int> tmp;
		while (fin)
		{
			char x;
			fin >> x;
			if (x >= '0' && x <= '9')
			{
				nCount *= 10;
				nCount += x - '0';
			}
			else 
				if (x == ' ' || x == '\n' || x == ',')
					break;
				else
				{
					AfxMessageBox(_T("Error!"));
					ok = false;
					coma = true;
					break;
				}

		}
		int t[3];
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
		int i = 0;
		if (ok)
		{
			while (fin)
			{
				char x;
				fin >> x;
				if (x >= '0' && x <= '9')
				{
					t[i] *= 10;
					t[i] += x - '0';
				}
				else
					if (x == ' ' || x == '\n' || x == ',')
					{
						coma = true;
						i++;
						if (i == 3)
						{
							tmp.insert(std::make_pair(std::make_pair(t[0], t[1]), t[2]));
							i = 0;
							t[0] = 0;
							t[1] = 0;
							t[2] = 0;
						}
					}
					else
					{
						AfxMessageBox(_T("Error!"));
						ok = false;
						break;
					}
			}
		}
		if (!coma || !ok)
			AfxMessageBox(_T("Error!"));
		else
			GetDocument()->arr = tmp;
		GetDocument()->UpdateAllViews(0);
		fin.close();
	}

}


void RightView::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	//CFileDialog fileDialog(false, NULL, NULL, OFN_HIDEREADONLY | OFN_NOCHANGEDIR, _T("Text files (*.txt)"));
	CFileDialog fileDialog(FALSE, CString(".txt"), NULL, 0, _T("Text files (*.txt)|*.txt|All files (*.*)|*.*||"));
	if (fileDialog.DoModal() == IDOK)
	{
		//std::string outFileName = fileDialog.GetFileName();
		//std::ofstream fout(fileDialog.GetFileName(), std::ios::out | std::ios::app | std::ios::_Nocreate);
		std::ofstream fout;
		fout.open(fileDialog.GetPathName());
		int nCount = GetDocument()->arr.size();
		fout << nCount << ",\n";

		for (std::map<std::pair<int, int>, int>::iterator it = GetDocument()->arr.begin(); it != GetDocument()->arr.end(); ++it)
		{
			fout << it->first.first << ", " << it->first.second << ", " << it->second << ",\n";
		}
		GetDocument()->UpdateAllViews(0);
		fout.close();
	}
}


void RightView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	grid.Clear();
	GetDocument()->UpdateAllViews(0);
}
