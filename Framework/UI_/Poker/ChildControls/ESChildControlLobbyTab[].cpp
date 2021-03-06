// ESChildControlLobbyTab.cpp : implementation file
//

#include "stdafx.h"
#include "..\..\..\Image\ImageHelper.h"
#include "..\PokerGUI.h"
#include "ESChildControlLobbyTab.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ESChildControlLobbyTab

ESChildControlLobbyTab::ESChildControlLobbyTab(){
	m_nActiveItem			= -1;
	m_pImageTabItem			= NULL;
	m_pImageTabItemActive	= NULL;
	m_pTabItemFont			= NULL;
	m_pTabItemActiveFont	= NULL;

	m_crTabItemText			= RGB(0, 0, 0);
	m_crActiveTabItemText	= RGB(0, 0, 0);
	}

ESChildControlLobbyTab::~ESChildControlLobbyTab(){
	}

bool
ESChildControlLobbyTab::Create(int nId, CRect rcRect, MercuryBaseView* pOwner, ESChildControl* pParent){
	ESChildControl::Create(nId, rcRect, pOwner, pParent);
	return true;
	}

bool
ESChildControlLobbyTab::SetPos(int x, int y, bool bRedraw){
	ESChildControl::SetPos(x, y, bRedraw);
	return true;
	}

bool
ESChildControlLobbyTab::SetSize(int cx, int cy, bool bRedraw){
	ESChildControl::SetSize(cx, cy, bRedraw);
	return true;
	}

bool
ESChildControlLobbyTab::Destroy(){
	ESChildControl::Destroy();
	return true;
	}

void
ESChildControlLobbyTab::OwnerWindowSizeChanged(int cx, int cy){
	ESChildControl::OwnerWindowSizeChanged(cx, cy);
	}

void
ESChildControlLobbyTab::SetTabItemImages(CImage* pImageTabItem, CImage* pImageTabItemActive, CRect rcTabItemOmitBorder){
	m_pImageTabItem			= pImageTabItem;
	m_pImageTabItemActive	= pImageTabItemActive;
	m_rcTabItemOmitBorder	= rcTabItemOmitBorder;
	}

void
ESChildControlLobbyTab::SetTabItemFonts(CFont* pFontTab, CFont* pFontTabItemActive){
	m_pTabItemFont			= pFontTab;
	m_pTabItemActiveFont	= pFontTabItemActive;
	}

void
ESChildControlLobbyTab::SetTabItemTextColors(COLORREF crTabItemText, COLORREF crActiveTabItemText){
	m_crTabItemText			= crTabItemText;
	m_crActiveTabItemText	= crActiveTabItemText;
	}

UINT
ESChildControlLobbyTab::GetItemData(int nItem){
	ESLobbyTabItem* pItem = m_listTabItems.GetAt(nItem);
	if( !pItem )
		return 0L;
	return pItem->nData;
	}

int
ESChildControlLobbyTab::AddTabItem(CString sTitle, UINT nData){
	ESLobbyTabItem* pItem	= new ESLobbyTabItem();
	pItem->sTitle			= sTitle;
	pItem->nData			= nData;
	m_listTabItems.Add(pItem);
	
	if( m_nActiveItem == -1 )
		m_nActiveItem = 0;
	return true;
	}

bool
ESChildControlLobbyTab::RemoveTabItem(int nIndex){
	bool bRet = m_listTabItems.RemoveAt(nIndex, true);
	if( nIndex == m_nActiveItem && bRet )
		m_nActiveItem = -1;
	return bRet;
	}

bool
ESChildControlLobbyTab::RemoveAllTabItem(){
	m_listTabItems.RemoveAll();
	m_nActiveItem = -1;
	return true;
	}

bool
ESChildControlLobbyTab::ActivateTabItem(int nIndex,  bool bRedraw /*= false*/){
	if( nIndex < 0 || nIndex >= m_listTabItems.GetCount() )
		return false;

	m_nActiveItem = nIndex;
	if( bRedraw )
		Redraw();
	return true;
	}

bool
ESChildControlLobbyTab::SetTabItemTitle(int nItem, CString sTitle, bool bRedraw){
	if( nItem < 0 || nItem >= m_listTabItems.GetCount() )
		return false;

	ESLobbyTabItem* pItem = m_listTabItems.GetAt(nItem);
	if( !pItem )
		return false;

	pItem->sTitle	= sTitle;
	if( bRedraw )
		Redraw();
	return true;
	}

int
ESChildControlLobbyTab::GetItemByPoint(CPoint pt){
	if( !m_listTabItems.GetCount() )
		return -1;

	PokerGUI*	pGUI	= PokerGUI::GetInstance();
	int nItemCt			= m_listTabItems.GetCount();
	int nItem			= 0;
	int nBorderWidth	= 0;
	int nItemHeight		= m_rcRect.Height();
	int nItemWidth		= m_rcRect.Width() / nItemCt;

	int nLoop			= 0;
	int nCt				= m_listTabItems.GetCount();

	CRect rcTabItem;
	rcTabItem.left		= m_rcRect.left + nBorderWidth;
	rcTabItem.top		= m_rcRect.top + nBorderWidth;
	rcTabItem.right		= 0;
	rcTabItem.bottom	= rcTabItem.top + nItemHeight;

	while( nLoop < nCt ){
		ESLobbyTabItem* pItem = m_listTabItems.GetAt(nLoop);
		rcTabItem.right = rcTabItem.left + nItemWidth;

		if( rcTabItem.PtInRect(pt) )
			return nLoop;
		
		rcTabItem.left = rcTabItem.right;
		nLoop ++;
		}
	return -1;
	}

bool
ESChildControlLobbyTab::RedrawItems(){
	PokerGUI*	pGUI	= PokerGUI::GetInstance();
	int nItemCt			= m_listTabItems.GetCount();
	int nItem			= 0;
	int nBorderWidth	= 0;
	int nItemHeight		= m_rcRect.Height();

	CRect rcTabItem;
	rcTabItem.left		= m_rcRect.left + nBorderWidth;
	rcTabItem.top		= m_rcRect.top + nBorderWidth;
	rcTabItem.right		= m_rcRect.right - nBorderWidth;
	rcTabItem.bottom	= rcTabItem.top + nItemHeight;

	if( m_pOwner )
		m_pOwner->RedrawRect(rcTabItem, 1);
	return (m_pOwner != NULL);
	}

// ========================================================
//
//	Event methods.
//
// ========================================================

void
ESChildControlLobbyTab::OnPaintClient(CDC* pDC, CRect* pRectDC, CRect* pRectClient){
	PokerGUI*	pGUI		= PokerGUI::GetInstance();
	int nItemCt				= m_listTabItems.GetCount();
	int nItem				= 0;
	int nBorderWidth		= 1;
	int nItemWidth			= m_rcRect.Width() / nItemCt;
	int nItemHeight			= m_rcRect.Height();

	CImage*	pImage			= NULL;
	CImage*	pItemActive		= m_pImageTabItemActive;
	CImage*	pItemDefault	= m_pImageTabItem;
	if( !pItemActive || !pItemDefault ) return;

	CRect	rcTabViewDC, rcInvalid;
	rcTabViewDC.left	= (m_rcRect.left - pRectClient->left) + pRectDC->left; 
	rcTabViewDC.top		= (m_rcRect.top - pRectClient->top) + pRectDC->top; 
	rcTabViewDC.right	= rcTabViewDC.left + m_rcRect.Width(); 
	rcTabViewDC.bottom	= rcTabViewDC.top + m_rcRect.Height(); 

	int				nOffsetX	= rcTabViewDC.left;
	ESLobbyTabItem*	pItem		= NULL;
	CSize			szText;
	bool			bActive		= false;

	while( nItem < nItemCt ){
		pItem				= m_listTabItems.GetAt(nItem);
		bActive				= (nItem == m_nActiveItem);

		CRect rcTabItemDC;
		rcTabItemDC.left	= nOffsetX;
		rcTabItemDC.top		= rcTabViewDC.top;
		rcTabItemDC.right	=  (nItem == nItemCt-1) ? (rcTabViewDC.right) : rcTabItemDC.left + nItemWidth;
		rcTabItemDC.bottom	= rcTabItemDC.top + nItemHeight;

		// Draw tabview item.
		pImage		= bActive ? pItemActive : pItemDefault;
		rcInvalid	= rcTabItemDC & *pRectDC;
		if( pImage && !rcInvalid.IsRectEmpty() )
			PokerGUI::RenderImage_OmitBorder(pDC, rcInvalid, rcTabItemDC, pImage, m_rcTabItemOmitBorder);

		// Draw item label. {{
		CFont* pFontOld = NULL;
		if( nItem == m_nActiveItem ){
			pFontOld = pDC->SelectObject(m_pTabItemActiveFont);
			ImgHlp::GetTextSize(&pItem->sTitle, m_pTabItemActiveFont, szText);
			}
		else{
			pFontOld = pDC->SelectObject(m_pTabItemFont);
			ImgHlp::GetTextSize(&pItem->sTitle, m_pTabItemFont, szText);
			}
		
		CPoint ptLabel		(rcTabItemDC.left + (rcTabItemDC.Width() - szText.cx)/2, rcTabItemDC.top + (rcTabItemDC.Height() - szText.cy)/2);
		pDC->SetBkMode		(TRANSPARENT);
		pDC->SetTextColor	(bActive ? m_crActiveTabItemText : m_crTabItemText);
		PokerGUI::ExtTextOut(pDC, ptLabel.x, ptLabel.y, ETO_CLIPPED, rcTabItemDC, pItem->sTitle);
		pDC->SelectObject	(pFontOld);
		// }}

		nOffsetX	+= nItemWidth;
		nItem		++;
		}

	ESChildControl::OnPaintClient(pDC, pRectDC, pRectClient);
	}

void	
ESChildControlLobbyTab::OnMouseHover(CPoint pt, UINT nFlags){
	m_nItemUnderCursor = GetItemByPoint(pt);
	}

BOOL	
ESChildControlLobbyTab::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message){
	if( m_nItemUnderCursor == -1 )
		return 0;
	SetCursor(LoadCursor(NULL, IDC_HAND));
	return 1;
	}

void	
ESChildControlLobbyTab::OnMouseLeave(UINT nFlags){
	}

void	
ESChildControlLobbyTab::OnMouseEnter(UINT nFlags){
	}

void
ESChildControlLobbyTab::OnLButtonDown(CPoint pt, UINT nFlags){
	}

void
ESChildControlLobbyTab::OnLButtonUp(CPoint pt, UINT nFlags){
	}

void	
ESChildControlLobbyTab::OnLButtonClick(CPoint pt, UINT nFlags){
	if( m_nItemUnderCursor != -1 ){
		ESLobbyTabItem* pItemOld = m_listTabItems.GetAt(m_nActiveItem);
		ActivateTabItem(m_nItemUnderCursor, true);
		ESLobbyTabItem* pItem = m_listTabItems.GetAt(m_nActiveItem);
		if( pItem && pItem != pItemOld ){
			SendEvent(this, EventCode_TabItemChange);
			}
		}
	}

void	
ESChildControlLobbyTab::OnRButtonClick(CPoint pt, UINT nFlags){
	}

void	
ESChildControlLobbyTab::OnMButtonClick(CPoint pt, UINT nFlags){
	}

void	
ESChildControlLobbyTab::OnLButtonDblClick(CPoint pt, UINT nFlags){
	}

void	
ESChildControlLobbyTab::OnRButtonDblClick(CPoint pt, UINT nFlags){
	}

void	
ESChildControlLobbyTab::OnMButtonDblClick(CPoint pt, UINT nFlags){
	}