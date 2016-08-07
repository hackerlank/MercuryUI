#pragma once

/////////////////////////////////////////////////////////////////////////////
// ESChildControlTabView window

#include "..\..\..\Controls\ESChildControl.h"

class ESChildControlTabViewPage;

struct ESTabViewItem{
	CString		sTitle;
	int			nData;
	ESChildControlTabViewPage*	pPage;
	};

class ESChildControlTabView : public ESChildControl
{
// Construction
public:
	ESChildControlTabView();
	virtual ~ESChildControlTabView();

	virtual bool	Create			(int nId, CRect rcRect, MercuryBaseView* pOwner, ESChildControl* pParent);
	virtual bool	SetPos			(int x, int y, bool bRedraw = true);
	virtual bool	SetSize			(int cx, int cy, bool bRedraw = true);
	virtual bool	Destroy			();
	virtual void	OwnerWindowSizeChanged	(int cx, int cy);

	bool			AddTabPage		(ESChildControlTabViewPage* pPage, int nId, CString sTitle, int nData);
	bool			RemoveTabPage	(int nIndex);
	bool			ActivateTabPage	(int nIndex, bool bRedraw = false);

protected:
	virtual void	OnPaintClient		(CDC* pDC, CRect* pRectDC, CRect* pRectClient);

	virtual	void	OnMouseHover		(CPoint pt, UINT nFlags);
	virtual void	OnMouseLeave		(UINT nFlags);
	virtual void	OnMouseEnter		(UINT nFlags);
	virtual BOOL	OnSetCursor			(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual	void	OnLButtonClick		(CPoint pt, UINT nFlags);
	virtual	void	OnRButtonClick		(CPoint pt, UINT nFlags);
	virtual	void	OnMButtonClick		(CPoint pt, UINT nFlags);
	virtual	void	OnLButtonDown		(CPoint pt, UINT nFlags);
	virtual	void	OnLButtonUp			(CPoint pt, UINT nFlags);
	virtual	void	OnLButtonDblClick	(CPoint pt, UINT nFlags);
	virtual	void	OnRButtonDblClick	(CPoint pt, UINT nFlags);
	virtual	void	OnMButtonDblClick	(CPoint pt, UINT nFlags);

protected:
	int				GetItemByPoint		(CPoint pt);
	bool			RedrawItems			();

protected:
	List<ESTabViewItem>	m_listTabItems;
	int					m_nActiveItem;
	int					m_nItemUnderCursor;
};