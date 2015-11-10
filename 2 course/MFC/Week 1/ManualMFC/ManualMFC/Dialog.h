class CMyDialog : public CDialog
{
public:
	int a;
	CMyDialog():CDialog(MAKEINTRESOURCE(IDD_DIALOG1)){};
	BOOL OnInitDialog();
	void OnOK();
};