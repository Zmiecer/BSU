#include <vector>
// MFCApplication5Doc.h : ��������� ������ CMFCApplication5Doc
//


#pragma once


class CMFCApplication5Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CMFCApplication5Doc();
	DECLARE_DYNCREATE(CMFCApplication5Doc)

// ��������
public:
	std::vector<int> v;

// ��������
public:

// ���������������
public:
	virtual void DeleteContents();
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CMFCApplication5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
