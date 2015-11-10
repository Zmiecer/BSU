
// MFCApplication1Doc.h : интерфейс класса CMFCApplication1Doc
//


#pragma once
#include <vector>
using namespace std;

#define UPDATE_ADD_STUDENT 1
#define UPDATE_DEL_STUDENT 2
#define UPDATE_EDIT_STUDENT 3

class CMFCApplication1Doc : public CDocument
{
protected: // создать только из сериализации
	CMFCApplication1Doc();
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// Атрибуты
public:
	vector<pair<CString, CString>> students;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
