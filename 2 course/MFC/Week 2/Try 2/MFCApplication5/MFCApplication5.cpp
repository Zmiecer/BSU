
// MFCApplication5.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApplication5.h"
#include "MainFrm.h"

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5App

BEGIN_MESSAGE_MAP(CMFCApplication5App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMFCApplication5App::OnAppAbout)
	// ����������� ������� �� ������ � ������� ����������
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// �������� CMFCApplication5App

CMFCApplication5App::CMFCApplication5App()
{
	// TODO: �������� ���� ������ �������������� ���������� ������� ����������� ��������������; �������������
	// ������ ��� ������: �����������.�����������.����������.���������������
	SetAppID(_T("MFCApplication5.AppID.NoVersion"));

	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}

// ������������ ������ CMFCApplication5App

CMFCApplication5App theApp;


// ������������� CMFCApplication5App

BOOL CMFCApplication5App::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// ��� ������������� �������� ���������� RichEdit ��������� ����� AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ����������
	// ���������� ��������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));
	LoadStdProfileSettings(4);  // ��������� ����������� ��������� INI-����� (������� MRU)


	// ��������������� ������� ���������� ����������.  ������� ����������
	//  ��������� � ���� ���������� ����� �����������, ������ ����� � ���������������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMFCApplication5Doc),
		RUNTIME_CLASS(CMainFrame),       // �������� ���� ����� SDI
		RUNTIME_CLASS(CMFCApplication5View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// ��������� ������������� ����������� �������� � ������� �������� ����
	CMFCToolBar::m_bExtCharTranslation = TRUE;

	// �������������� ������ ��������� ������ �� ����������� ������� ��������, DDE, �������� ������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ������� ���������������, ��������� � ��������� ������.  �������� FALSE ����� ����������, ����
	// ���������� ���� �������� � ���������� /RegServer, /Register, /Unregserver ��� /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// ���� � ������ ���� ���� ���� ����������������, ������� ���������� � �������� ���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// ����������� ��������� CMFCApplication5App


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

// ������� ���������� ��� ������� �������
void CMFCApplication5App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// ����������� ��������� CMFCApplication5App



