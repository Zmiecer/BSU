
// MFCBinaryTreeDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFCBinaryTree.h"
#include "MFCBinaryTreeDlg.h"
#include "afxdialogex.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CMFCBinaryTreeDlg



CMFCBinaryTreeDlg::CMFCBinaryTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCBinaryTreeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCBinaryTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCBinaryTreeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// обработчики сообщений CMFCBinaryTreeDlg

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

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию


	CFileDialog fileDialog(true, NULL, NULL, OFN_HIDEREADONLY | OFN_NOCHANGEDIR, _T("Text files (*.txt)|*.txt|All files (*.*)|*.*||"));

	if (fileDialog.DoModal() == IDOK)
	{
		btree data;
		ifstream fin;
		fin.open(fileDialog.GetFileName());
		while (fin)
		{
			int tmp;
			fin >> tmp;
			data.insert(tmp);
		}
		CString test;
		data.straight(&test);
		cout << test << "lol" << endl;

		CTreeCtrl* result = new CTreeCtrl;// = (CTreeCtrl*)GetDlgItem(IDC_TREE1);
		result->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP |
			TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT |
			TVS_SINGLEEXPAND | TVS_SHOWSELALWAYS |
			TVS_TRACKSELECT,
			CRect(10, 10, 500, 300), this, 0x1221);
		//treeOut(data.getRoot(), *result, NULL);
		func(test, *result, NULL, 0);
		
		
	}
	else
		EndDialog(0);


	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
	
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCBinaryTreeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCBinaryTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

