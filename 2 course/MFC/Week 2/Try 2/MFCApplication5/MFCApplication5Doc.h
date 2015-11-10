#include <vector>
// MFCApplication5Doc.h : интерфейс класса CMFCApplication5Doc
//


#pragma once


class CMFCApplication5Doc : public CDocument
{
protected: // создать только из сериализации
	CMFCApplication5Doc();
	DECLARE_DYNCREATE(CMFCApplication5Doc)

// Атрибуты
public:
	std::vector<int> v;

// Операции
public:

// Переопределение
public:
	virtual void DeleteContents();
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMFCApplication5Doc();
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
};
