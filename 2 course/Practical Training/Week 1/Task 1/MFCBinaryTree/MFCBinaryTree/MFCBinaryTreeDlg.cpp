
// MFCBinaryTreeDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFCBinaryTree.h"
#include "MFCBinaryTreeDlg.h"
#include "afxdialogex.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMFCBinaryTreeDlg



CMFCBinaryTreeDlg::CMFCBinaryTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCBinaryTreeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBinaryTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_TREE1, m_tree);
}

BEGIN_MESSAGE_MAP(CMFCBinaryTreeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// ����������� ��������� CMFCBinaryTreeDlg

void treeOut(node* arg, CTreeCtrl& result, HTREEITEM hParent)
{
	char* buf = new char[256];
	_itoa(arg->key_value, buf, 10);
	const char* port = buf;
	size_t size = strlen(port) + 1;
	wchar_t* res = new wchar_t[size];
	size_t outSize;
	mbstowcs_s(&outSize, res, size, port, size - 1);
	
	HTREEITEM center;
	center = result.InsertItem(res, hParent);
	if (arg->left) {
		treeOut(arg->left, result, center);
	}
	if (arg->right) {
		treeOut(arg->right, result, center);
	}
}

void func(CString str, CTreeCtrl& result, HTREEITEM hParent, int i)
{
	/*
	HTREEITEM center = hParent;
	CString x = _T("");
	x.AppendChar(str[0]);
	center = result.InsertItem(x, hParent);

	
	for (int i = 0; i < str.GetLength(); i += 2)
	{
		CString x = _T("");
		x.AppendChar(str[i]);
		center = result.InsertItem(x, center);
	}
	


	center = result.InsertItem(res, hParent);
	if (arg->left) {
		func(str, result, center);
	}
	if (arg->right) {
		func(str, result, center);
	}
	*/
}

BOOL CMFCBinaryTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	


	CFileDialog fileDialog(true, NULL, NULL, OFN_HIDEREADONLY | OFN_NOCHANGEDIR, _T("Text files (*.txt)|*.txt|All files (*.*)|*.*||"));

	if (fileDialog.DoModal() == IDOK)
	{
		
		ifstream fin;
		fin.open(fileDialog.GetFileName());
		btree data;
		int size = 0;
		while (fin)
		{
			int tmp;
			fin >> tmp;
			data.insert(tmp);
			size++;
		}
		
		if (size != 1)
		{
			CTreeCtrl* result = new CTreeCtrl;
			result->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP |
				TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT |
				TVS_SINGLEEXPAND | TVS_SHOWSELALWAYS |
				TVS_TRACKSELECT,
				CRect(10, 10, 500, 300), this, 0x1221);

			int arrSize = 1 << size;
			int *arr = new int[arrSize];
			for (int i = 1; i <= arrSize; i++){
				arr[i] = 0;
			}

			data.intoArray(arr, 1);
			showTree(arr, arrSize, 1, NULL, result);
		}
		
	}
	else
		EndDialog(0);


	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
	
}

void CMFCBinaryTreeDlg::showTree(int* arr, int arrSize, int i, HTREEITEM hParent, CTreeCtrl* result)
{
	CString str;
	if (arr[i] != 0 && i < arrSize){
		str.Format(_T("%d"), arr[i]);
		HTREEITEM root = result->InsertItem((LPCTSTR)str, hParent);
		result->Expand(hParent, TVE_EXPAND);

		showTree(arr, arrSize, 2 * i, root, result);
		showTree(arr, arrSize, 2 * i + 1, root, result);
	}
}

void CMFCBinaryTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMFCBinaryTreeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMFCBinaryTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

