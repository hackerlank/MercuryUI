// PokerGUI.cpp : implementation file
//

#include "stdafx.h"
#include <MMSystem.h>
#include "PokerGUI.h"
#include "..\..\Path\Path.h"
#include "..\..\Image\ImageHelper.h"
#include "..\..\Image\GdiDrawStream.h"
#include "..\..\Controls\ESChildControl.h"

#define RESOURCE_MODULE _T("ResourceDLL.dll")

PokerGUI::PokerGUI(){
	m_bInited				= FALSE;
	m_pChipLabelFont		= NULL;
	m_pSeatLabelFont		= NULL;
	m_pTotalPotLabelFont	= NULL;
	m_pMainPotLabelFont		= NULL;
	m_pPushButtonFont		= NULL;
	m_pActionButtonFont		= NULL;
	m_pLang					= NULL;
	m_hResModule			= NULL;

#ifdef LOAD_FILES_FROM_DLL
	CString sModulePath		= RESOURCE_MODULE;
	Path::BuildFullPath(sModulePath);
	m_hResModule			= LoadLibrary(sModulePath);
#endif
	}

BEGIN_DECLARE_VAR(PokerGUI, Serializable)
	DECLARE_VAR("PokerGUI", _T(""),				VariableType::None, 0, false, true, false)
	DECLARE_VAR("TablePosX", _T(""),			VariableType::Int32, offsetof(PokerGUI,m_ptTablePos.x), false, false, false)
	DECLARE_VAR("TablePosY", _T(""),			VariableType::Int32, offsetof(PokerGUI,m_ptTablePos.y), false, false, false)

	DECLARE_VAR("DefWindowSizeCX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szDefWindowSize.cx), false, false, false)
	DECLARE_VAR("DefWindowSizeCY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szDefWindowSize.cy), false, false, false)	
	DECLARE_VAR("CardCX", _T(""),				VariableType::Int32, offsetof(PokerGUI,m_szCardDimension.cx), false, false, false)
	DECLARE_VAR("CardCY", _T(""),				VariableType::Int32, offsetof(PokerGUI,m_szCardDimension.cy), false, false, false)

	DECLARE_VAR("SeatPanelCX", _T(""),			VariableType::Int32, offsetof(PokerGUI,m_szSeatPanel.cx), false, false, false)
	DECLARE_VAR("SeatPanelCY", _T(""),			VariableType::Int32, offsetof(PokerGUI,m_szSeatPanel.cy), false, false, false)

	DECLARE_VAR("SeatCard1PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard1Pos.x), false, false, false)
	DECLARE_VAR("SeatCard1PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard1Pos.y), false, false, false)
	DECLARE_VAR("SeatCard2PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard2Pos.x), false, false, false)
	DECLARE_VAR("SeatCard2PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard2Pos.y), false, false, false)
	DECLARE_VAR("SeatCard3PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard3Pos.x), false, false, false)
	DECLARE_VAR("SeatCard3PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard3Pos.y), false, false, false)
	DECLARE_VAR("SeatCard4PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard4Pos.x), false, false, false)
	DECLARE_VAR("SeatCard4PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatCard4Pos.y), false, false, false)
/*
	DECLARE_VAR("SeatInfo2", _T(""),			VariableType::None, offsetof(PokerGUI,m_seatInfo2), false, true, true)
	DECLARE_VAR("SeatInfo4", _T(""),			VariableType::None, offsetof(PokerGUI,m_seatInfo4), false, true, true)
	DECLARE_VAR("SeatInfo6", _T(""),			VariableType::None, offsetof(PokerGUI,m_seatInfo6), false, true, true)
	DECLARE_VAR("SeatInfo9", _T(""),			VariableType::None, offsetof(PokerGUI,m_seatInfo9), false, true, true)
	DECLARE_VAR("SeatInfo10", _T(""),			VariableType::None, offsetof(PokerGUI,m_seatInfo10), false, true, true)
	*/
	DECLARE_VAR("FloorBgImage", _T(""),			VariableType::String, offsetof(PokerGUI,m_sFloorBgImage), false, false, false)
	DECLARE_VAR("TableBgImage", _T(""),			VariableType::String, offsetof(PokerGUI,m_sTableBgImage), false, false, false)
	DECLARE_VAR("TotalPotLabelPosX", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptTotalPotLabelPos.x), false, false, false)
	DECLARE_VAR("TotalPotLabelPosY", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptTotalPotLabelPos.y), false, false, false)
	DECLARE_VAR("CardBackImage", _T(""),		VariableType::String, offsetof(PokerGUI,m_sCardBackImage), false, false, false)
	DECLARE_VAR("SeatPanelBgImage", _T(""),		VariableType::String, offsetof(PokerGUI,m_sSeatPanelBgImage), false, false, false)
	DECLARE_VAR("SeatPanelBgImageDis", _T(""),	VariableType::String, offsetof(PokerGUI,m_sSeatPanelBgDisImage), false, false, false)
	DECLARE_VAR("SeatPanelActBgImage", _T(""),	VariableType::String, offsetof(PokerGUI,m_sSeatPanelActBgImage), false, false, false)

	DECLARE_VAR("CardsFolder", _T(""),			VariableType::String, offsetof(PokerGUI,m_sCardsFolder), false, false, false)
	DECLARE_VAR("ChipsFolder", _T(""),			VariableType::String, offsetof(PokerGUI,m_sChipsFolder), false, false, false)
	
	DECLARE_VAR("TableCard1PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard1.x), false, false, false)
	DECLARE_VAR("TableCard1PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard1.y), false, false, false)
	DECLARE_VAR("TableCard2PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard2.x), false, false, false)
	DECLARE_VAR("TableCard2PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard2.y), false, false, false)
	DECLARE_VAR("TableCard3PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard3.x), false, false, false)
	DECLARE_VAR("TableCard3PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard3.y), false, false, false)
	DECLARE_VAR("TableCard4PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard4.x), false, false, false)
	DECLARE_VAR("TableCard4PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard4.y), false, false, false)
	DECLARE_VAR("TableCard5PosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard5.x), false, false, false)
	DECLARE_VAR("TableCard5PosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTableCard5.y), false, false, false)
	DECLARE_VAR("ChipLabelFont", _T(""),		VariableType::String, offsetof(PokerGUI,m_sChipLabelFont), false, false, false)
	DECLARE_VAR("ChipLabelFontHeight", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_nChipLabelFontHeight), false, false, false)
	DECLARE_VAR("crChipLabel", _T(""),			VariableType::Int32, offsetof(PokerGUI,m_crChipLabel), false, false, false)
	DECLARE_VAR("ChipCountInRow", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_nChipCountInCol), false, false, false)

	DECLARE_VAR("SeatLabelFont", _T(""),		VariableType::String, offsetof(PokerGUI,m_sSeatLabelFont), false, false, false)
	DECLARE_VAR("SeatLabelFontHeight", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_nSeatLabelFontHeight), false, false, false)

	DECLARE_VAR("crSeatUserNameLabel", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_crSeatUserNameLabel), false, false, false)
	DECLARE_VAR("crSeatBalanceLabel", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_crSeatBalanceLabel), false, false, false)
	DECLARE_VAR("crSeatActionLabel", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_crSeatActionLabel), false, false, false)

	DECLARE_VAR("SeatUserNameLabelX", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptSeatUserNameLabel.x), false, false, false)
	DECLARE_VAR("SeatUserNameLabelY", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptSeatUserNameLabel.y), false, false, false)
	DECLARE_VAR("SeatBalanceLabelX", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptSeatBalanceLabel.x), false, false, false)
	DECLARE_VAR("SeatBalanceLabelY", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptSeatBalanceLabel.y), false, false, false)
	DECLARE_VAR("SeatActionLabelX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatActionLabel.x), false, false, false)
	DECLARE_VAR("SeatActionLabelY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptSeatActionLabel.y), false, false, false)

	DECLARE_VAR("AvatarCX", _T(""),				VariableType::Int32, offsetof(PokerGUI,m_szAvatar.cx), false, false, false)
	DECLARE_VAR("AvatarCY", _T(""),				VariableType::Int32, offsetof(PokerGUI,m_szAvatar.cy), false, false, false)
	DECLARE_VAR("AvatarPosX", _T(""),			VariableType::Int32, offsetof(PokerGUI,m_ptAvatarPos.x), false, false, false)
	DECLARE_VAR("AvatarPosY", _T(""),			VariableType::Int32, offsetof(PokerGUI,m_ptAvatarPos.y), false, false, false)
	DECLARE_VAR("DealerBtnImage", _T(""),		VariableType::String, offsetof(PokerGUI,m_sDealerBtnImage), false, false, false)

	DECLARE_VAR("RankIndicatorPosX", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptRankIndicatorPos.x), false, false, false)
	DECLARE_VAR("RankIndicatorPosY", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_ptRankIndicatorPos.y), false, false, false)

	DECLARE_VAR("TotalPotLblPosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTotalPotLabelPos.x), false, false, false)
	DECLARE_VAR("TotalPotLblPosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptTotalPotLabelPos.y), false, false, false)
	DECLARE_VAR("TotalPotLblFont", _T(""),		VariableType::String, offsetof(PokerGUI,m_sTotalPotLabelFont), false, false, false)
	DECLARE_VAR("TotalPotLblFontHeight", _T(""),VariableType::Int32, offsetof(PokerGUI,m_nTotalPotLabelFontHeight), false, false, false)
	DECLARE_VAR("crTotalPotLabel", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_crTotalPotLabel), false, false, false)

	DECLARE_VAR("MainPotChipPosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptMainPotChipsPos.x), false, false, false)
	DECLARE_VAR("MainPotChipPosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptMainPotChipsPos.y), false, false, false)
	DECLARE_VAR("MainPotLblFont", _T(""),		VariableType::String, offsetof(PokerGUI,m_sMainPotLabelFont), false, false, false)
	DECLARE_VAR("MainPotLblFontHeight", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_nMainPotLabelFontHeight), false, false, false)
	DECLARE_VAR("crMainPotLabel", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_crMainPotLabel), false, false, false)

	DECLARE_VAR("ProgressBarCX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szProgressBar.cx), false, false, false)
	DECLARE_VAR("ProgressBarCY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szProgressBar.cy), false, false, false)
	DECLARE_VAR("ProgressBarPosX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptProgressBarPos.x), false, false, false)
	DECLARE_VAR("ProgressBarPosY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_ptProgressBarPos.y), false, false, false)

	DECLARE_VAR("PBarBgImage", _T(""),			VariableType::String, offsetof(PokerGUI,m_sPBarBgImage), false, false, false)
	DECLARE_VAR("PBarFillImage", _T(""),		VariableType::String, offsetof(PokerGUI,m_sPBarFillImage), false, false, false)

	DECLARE_VAR("PushButtonImage", _T(""),		VariableType::String, offsetof(PokerGUI,m_sPushButtonImage), false, false, false)
	DECLARE_VAR("PushBtnOmitBorderL", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_rcPushButtonOmitBorder.left), false, false, false)
	DECLARE_VAR("PushBtnOmitBorderT", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_rcPushButtonOmitBorder.top), false, false, false)
	DECLARE_VAR("PushBtnOmitBorderR", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_rcPushButtonOmitBorder.right), false, false, false)
	DECLARE_VAR("PushBtnOmitBorderB", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_rcPushButtonOmitBorder.bottom), false, false, false)

	DECLARE_VAR("PushButtonItemCX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szPushButtonItem.cx), false, false, false)
	DECLARE_VAR("PushButtonItemCY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szPushButtonItem.cy), false, false, false)
	DECLARE_VAR("PushButtonTextColor", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_crPushButtonText), false, false, false)
	DECLARE_VAR("PushButtonFont", _T(""),		VariableType::String, offsetof(PokerGUI,m_sPushButtonFont), false, false, false)
	DECLARE_VAR("PushButtonFontHeight", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_nPushButtonFontHeight), false, false, false)
	DECLARE_VAR("PushButtonFontWeight", _T(""),	VariableType::Int32, offsetof(PokerGUI,m_nPushButtonFontWeight), false, false, false)

	DECLARE_VAR("EmptySeatLogo", _T(""),		VariableType::String, offsetof(PokerGUI,m_sEmptySeatLogoImage), false, false, false)
	DECLARE_VAR("EmptySeatLogoCX", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szEmptySeatLogo.cx), false, false, false)
	DECLARE_VAR("EmptySeatLogoCY", _T(""),		VariableType::Int32, offsetof(PokerGUI,m_szEmptySeatLogo.cy), false, false, false)
END_DECLARE_VAR()

PokerGUI::~PokerGUI(){
	if( m_hResModule )
		FreeLibrary(m_hResModule);
	Destroy();
	}

BOOL
PokerGUI::Initialize(){
	if( m_bInited ) return FALSE;
	m_pLang						= new GUILanguage();
	CString sLangXML			= LoadXML(_T("Theme\\lang\\en.xml"));
	((Serializable*)m_pLang)->DeserializeAsXML(&sLangXML);

	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));

//	Deserialize(_T("c:\\22.txt"));

	// Lobby images. {{
	m_pLobbyLogo					= LoadImage(_T("Theme\\lobby___\\logo.png"));
	m_pLobbyTabItemActive2x			= LoadImage(_T("Theme\\lobby___\\tab_item_active2x.png"));
	m_pLobbyTabItem2x				= LoadImage(_T("Theme\\lobby___\\tab_item2x.png"));
	m_pLobbyTabItemActive			= LoadImage(_T("Theme\\lobby___\\tab_item_active1.png"));
	m_pLobbyTabItem					= LoadImage(_T("Theme\\lobby___\\tab_item1.png"));

	m_pLobbyCashierButtonClick		= LoadImage(_T("Theme\\lobby___\\cashier-click.png"));
	m_pLobbyCashierButtonDef		= LoadImage(_T("Theme\\lobby___\\cashier-default.png"));
	m_pLobbyCashierButtonHover		= LoadImage(_T("Theme\\lobby___\\cashier-hover.png"));

	m_pLobbyLoginButtonClick		= LoadImage(_T("Theme\\lobby___\\login-click.png"));
	m_pLobbyLoginButtonDef			= LoadImage(_T("Theme\\lobby___\\login-default.png"));
	m_pLobbyLoginButtonHover		= LoadImage(_T("Theme\\lobby___\\login-hover.png"));

	m_pLobbyButtonClick				= LoadImage(_T("Theme\\lobby___\\button-click.png"));
	m_pLobbyButtonDef				= LoadImage(_T("Theme\\lobby___\\button-default.png"));
	m_pLobbyButtonHover				= LoadImage(_T("Theme\\lobby___\\button-hover.png"));
	m_pLobbyButtonDisable			= LoadImage(_T("Theme\\lobby___\\button-disabled.png"));

	m_pImageBannerButtonDef			= LoadImage(_T("Theme\\lobby___\\banner-button.png"));
	m_pImageBannerButtonActive		= LoadImage(_T("Theme\\lobby___\\banner-button-active.png"));
	m_pUserInfoBkgnd				= LoadImage(_T("Theme\\lobby___\\user-info.png"));

	m_pImageResizeBar				= LoadImage(_T("Theme\\lobby___\\resize.png"));
	m_pImageCheckBox_Checked		= LoadImage(_T("Theme\\lobby___\\checkbox-checked.png"));
	m_pImageCheckBox_NoCheck		= LoadImage(_T("Theme\\lobby___\\checkbox.png"));
	m_pImageTextBoxBg				= LoadImage(_T("Theme\\lobby___\\textbox-bg.png"));


	m_listUsedImages.Add(m_pImageResizeBar);
	m_listUsedImages.Add(m_pImageCheckBox_Checked);
	m_listUsedImages.Add(m_pImageCheckBox_NoCheck);
	m_listUsedImages.Add(m_pImageTextBoxBg);
	m_listUsedImages.Add(m_pUserInfoBkgnd);
	m_listUsedImages.Add(m_pImageBannerButtonDef);
	m_listUsedImages.Add(m_pImageBannerButtonActive);
	m_listUsedImages.Add(m_pLobbyLogo);
	m_listUsedImages.Add(m_pLobbyTabItemActive2x);
	m_listUsedImages.Add(m_pLobbyTabItem2x);
	m_listUsedImages.Add(m_pLobbyTabItemActive);
	m_listUsedImages.Add(m_pLobbyTabItem);
	m_listUsedImages.Add(m_pLobbyCashierButtonClick);
	m_listUsedImages.Add(m_pLobbyCashierButtonDef);
	m_listUsedImages.Add(m_pLobbyCashierButtonHover);
	m_listUsedImages.Add(m_pLobbyLoginButtonClick);
	m_listUsedImages.Add(m_pLobbyLoginButtonDef);
	m_listUsedImages.Add(m_pLobbyLoginButtonHover);

	m_listUsedImages.Add(m_pLobbyButtonClick);
	m_listUsedImages.Add(m_pLobbyButtonDef);
	m_listUsedImages.Add(m_pLobbyButtonHover);
	m_listUsedImages.Add(m_pLobbyButtonDisable);

	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight			= 18;
	lf.lfWidth			= 7;

	_tcscpy_s(lf.lfFaceName, _T("Aero Matics"));
	lf.lfWeight			= FW_LIGHT;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= ANTIALIASED_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pLobbyTabItemFont = new CFont();
	m_pLobbyTabItemFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pLobbyTabItemFont);


//	lf.lfHeight			= 18;
//	lf.lfWidth			= 6;
	_tcscpy_s(lf.lfFaceName, _T("Aero Matics"));
	lf.lfWeight			= FW_LIGHT;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= ANTIALIASED_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pLobbyActiveTabItemFont = new CFont();
	m_pLobbyActiveTabItemFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pLobbyActiveTabItemFont);

	m_rcTabItemOmitBorder2x			.SetRect(5, 15, 5, 15);
	m_rcActiveTabItemOmitBorder2x	.SetRect(5, 15, 5, 15);
	m_rcTabItemOmitBorder			.SetRect(5, 10, 5, 10);
	m_rcActiveTabItemOmitBorder		.SetRect(5, 10, 5, 10);
	// }}

	m_sAvatarsCacheFolder		= _T("Theme\\avatars_cache");
	// Sound files.
	m_sSystemMessageSnd			= _T("Theme\\sounds\\alert.wav");	
	m_sAttentionSnd				= _T("Theme\\sounds\\0.wav");	
	m_sCardsDealtSnd			= _T("Theme\\sounds\\card_dealt.wav");	
	m_sChipsMovedToPotSnd		= _T("Theme\\sounds\\Sweep-3.wav");	
	m_sChipsMovedFromPotSnd		= _T("Theme\\sounds\\client_runit.wav");	
	m_sFoldSnd					= _T("Theme\\sounds\\fold.wav");	
	m_sCheckSnd					= _T("Theme\\sounds\\check.wav");	
	m_sBetSnd					= _T("Theme\\sounds\\bet_raise_allin.wav");	
	m_sRaiseSnd					= _T("Theme\\sounds\\bet_raise_allin.wav");	
	m_sCallSnd					= _T("Theme\\sounds\\bet_raise_allin.wav");	
	m_sAllInSnd					= _T("Theme\\sounds\\bet_raise_allin.wav");	
	m_sTimeWarningSnd			= _T("Theme\\sounds\\alert.wav");	
	m_sChatMessageSnd			= _T("Theme\\sounds\\Bell-2.wav");

	// Image files.
	m_sFloorBgImage				= _T("Theme\\floor.png");
	m_sTableBgImage				= _T("Theme\\table.png");
	m_sCardBackImage			= _T("Theme\\cards1\\back1.png");
	m_sSeatPanelBgImage			= _T("Theme\\seat_bg.png");
	m_sSeatPanelBgDisImage		= _T("Theme\\seat_empty_blur.png");
	m_sSeatPanelActBgImage		= _T("Theme\\seat_bg2.png");
	m_sRankImage				= _T("Theme\\rank_star.png");
	m_sDealerBtnImage			= _T("Theme\\dealer_btn.png");
	m_sCardsFolder				= _T("Theme\\cards1\\");
//	m_sChipsFolder				= _T("Theme\\chips1\\");
	m_sChipsFolder				= _T("Theme\\chips2\\");
	m_sPBarBgImage				= _T("Theme\\pbar_bkgnd.png");
	m_sPBarFillImage			= _T("Theme\\pbar_fill.png");
	m_sPushButtonImage			= _T("Theme\\PushButton.bmp");
	m_sEmptySeatLogoImage		= _T("Theme\\empty_seat_logo.png");
	m_sActionPanelImage			= _T("Theme\\action_panel_bg.png");
	m_sActionBtnImageClk		= _T("Theme\\action_button_clicked.png");
	m_sActionBtnImageDef		= _T("Theme\\action_button_default.png");
	m_sShortcutBtnImageDef		= _T("Theme\\shortcut_button_default.png");
	m_sShortcutBtnImageClicked	= _T("Theme\\shortcut_button_clicked.png");
	m_sSliderMinusImage			= _T("Theme\\Slider\\minus.png");
	m_sSliderPlusImage			= _T("Theme\\Slider\\plus.png");
	m_sSliderCursorImage		= _T("Theme\\Slider\\cursor.png");
	m_sSliderBarBgImage			= _T("Theme\\Slider\\bar_bg.png");
	m_sSliderBgImage			= _T("Theme\\Slider\\slider_bg.png");
	m_sPreActionBg				= _T("Theme\\pre-actions\\bg.png");
	m_sPreActionChecked			= _T("Theme\\pre-actions\\checked.png");
	m_sPreActionUnchecked		= _T("Theme\\pre-actions\\unchecked.png");
	m_sTabViewItemActive		= _T("Theme\\tab_item_active.png");
	m_sTabViewItemDefault		= _T("Theme\\tab_item_default.png");
	m_sAddChipsBkgnd			= _T("Theme\\addChips_bg.png");
	m_sTableMessageBk			= _T("Theme\\message_bk.png");

	m_sLobbyBkgnd				= _T("Theme\\lobby\\bg.png");
	m_sLogoImage				= _T("Theme\\lobby\\logo.png");

	m_sLobbyTabDefaultImage		= _T("Theme\\lobby\\lobby_tab_item_default.png");
	m_sLobbyTabActiveImage		= _T("Theme\\lobby\\lobby_tab_item_selected.png");
	m_sLobbyTabHoverImage		= _T("Theme\\lobby\\lobby_tab_item_default.png");

	m_sCashierImageDefault		= _T("Theme\\lobby\\cashier.png");
	m_sCashierImageSelected		= _T("Theme\\lobby\\cashier_click.png");
	m_sCashierImageHover		= _T("Theme\\lobby\\cashier_hover.png");
	m_sCashierImageDisabled		= _T("Theme\\lobby\\cashier_disabled.png");

	m_sLogInImageDefault		= _T("Theme\\lobby\\log_in.png");
	m_sLogInImageSelected		= _T("Theme\\lobby\\log_in_click.png");
	m_sLogInImageHover			= _T("Theme\\lobby\\log_in_hover.png");
	m_sLogInImageDisabled		= _T("Theme\\lobby\\log_in_disabled.png");

	m_sLobbyButtonDefault		= _T("Theme\\lobby\\button_default.png");
	m_sLobbyButtonSelected		= _T("Theme\\lobby\\button_click.png");
	m_sLobbyButtonHover			= _T("Theme\\lobby\\button_hover.png");
	m_sLobbyButtonDisabled		= _T("Theme\\lobby\\button_disabled.png");

	m_sUserInfoBkgnd			= _T("Theme\\lobby\\user_info_bg.png");
	m_sUserInfoRankImage		= _T("Theme\\lobby\\star.png");
	m_sUserInfoRankImageDis		= _T("Theme\\lobby\\star_disabled.png");

	m_sVScrollBar				= _T("Theme\\vscroll_bar.png");
	m_sCloseButtonImage			= _T("Theme\\close.png");

	m_sDiamondLogoSmall			= _T("Theme\\diamond_small.png");		
	m_sHeartLogoSmall			= _T("Theme\\heart_small.png");		
	m_sSpadeLogoSmall			= _T("Theme\\spade_small.png");
	m_sClubLogoSmall			= _T("Theme\\club_small.png");
	m_sMoneyTransferArrow		= _T("Theme\\money_transfer.png");
	m_sDialogImage				= _T("Theme\\dialog\\bk.png");

	m_sDialogCloseNormalImage	= _T("Theme\\dialog\\close_normal.png");
	m_sDialogCloseHoverImage	= _T("Theme\\dialog\\close_hover.png");
	m_sDialogClosePushedImage	= _T("Theme\\dialog\\close_pushed.png");

	m_fMinStretch				= 0.8f;
	// Table position.
	m_ptTablePos.SetPoint(10, 24);
//	m_ptTablePos.SetPoint(26, 24);

	// Table size.
	m_szTable.SetSize(780, 455);
//	m_szTable.SetSize(754, 475);

	// Seat panel
	m_szSeatPanel.SetSize(128, 52);

	// Best hand label rect.
	m_rcPlayerBestHandLabel.SetRect(630, 400, 790, 420);

	// Table card parameters. {{
	m_ptTableCard1.SetPoint(270, 176);
	m_ptTableCard2.SetPoint(326, 176);
	m_ptTableCard3.SetPoint(382, 176);
	m_ptTableCard4.SetPoint(438, 176);
	m_ptTableCard5.SetPoint(494, 176);
	// }}

	// Lobby button. {{
	m_crLobbyButton				= RGB(255, 255, 255);	
	m_sLobbyButtonFont			= _T("Aero Matics");
	m_nLobbyButtonFontHeight	= 22;			
	m_nLobbyButtonBigFontHeight	= 30;			
	m_nLobbyButtonFontWeight	= FW_SEMIBOLD;

	lf.lfHeight			= m_nLobbyButtonFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sLobbyButtonFont.GetBuffer());
	lf.lfWeight			= m_nLobbyButtonFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= PROOF_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pLobbyButtonFont = new CFont();
	m_pLobbyButtonFont->CreateFontIndirect(&lf);

	lf.lfHeight			= m_nLobbyButtonBigFontHeight;
	m_pLobbyButtonFontBig = new CFont();
	m_pLobbyButtonFontBig->CreateFontIndirect(&lf);

	m_listUsedFonts.Add(m_pLobbyButtonFontBig);
	m_listUsedFonts.Add(m_pLobbyButtonFont);
	// }}

	// Pushbutton. {{	
	m_rcPushButtonOmitBorder.SetRect(13, 11, 12, 11);
	m_szPushButtonItem		.SetSize(34, 23);
	m_crPushButtonText		= RGB(0, 0, 0);			// Pushbutton text color.
	m_sPushButtonFont		= _T("Segoe UI");			// Pushbutton font name.
	m_nPushButtonFontHeight = 18;	// Pushbutton font height.
	m_nPushButtonFontWeight	= FW_BOLD;

	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight			= m_nPushButtonFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sPushButtonFont.GetBuffer());
	lf.lfWeight			= m_nPushButtonFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= PROOF_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pPushButtonFont = new CFont();
	m_pPushButtonFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pPushButtonFont);
	// }}

	m_szEmptySeatLogo	.SetSize(39, 39);
	m_szProgressBar		.SetSize(128, 8);
	m_nMinProgressBarCY = 6;
	m_nMaxProgressBarCY = 8;
	m_ptProgressBarPos	.SetPoint(0, 52);
	m_szDealer			.SetSize(30, 30);
	m_ptDealerCardPos	.SetPoint(390, 126);

	/*
	m_nChipLabelFontHeight		= 16;
	m_crChipLabel				= RGB(255, 255, 255);
	m_sChipLabelFont			= _T("Segoe UI");
	m_szChipImage.SetSize		(36, 37);
	m_szChipContainer.SetSize	(80, 60);
	m_fChipsZoomMax				= 1.0f;
	m_fChipsZoomMin				= 0.8f;
	m_nChipCountInCol			= 5;
	m_nChipsDistanceCY			= 3;*/

	m_nChipLabelFontHeight		= 16;
	m_crChipLabel				= RGB(255, 255, 255);
	m_sChipLabelFont			= _T("Century Gothic");
	m_szChipImage.SetSize		(38, 35);
	m_szChipContainer.SetSize	(130, 50);
	m_fChipsZoomMax				= 1.f;
	m_fChipsZoomMin				= 0.5f;
	m_nChipCountInCol			= 4;
	m_nChipsDistanceCY			= 7;

	m_ptMainPotChipsPos.SetPoint(355, 250);
	m_sMainPotLabelFont			= _T("Segoe UI");
	m_nMainPotLabelFontHeight	= 16;
	m_crMainPotLabel			= RGB(255, 255, 255);

	// Create main pot label font. {{
	lf.lfHeight			= m_nMainPotLabelFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sMainPotLabelFont.GetBuffer());
	lf.lfWeight			= FW_NORMAL;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= PROOF_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pMainPotLabelFont = new CFont();
	m_pMainPotLabelFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pMainPotLabelFont);
	// }}

	m_ptTotalPotLabelPos	.SetPoint(325, 144);
	m_szTotalPotLabel		.SetSize(160, 24);
	m_sTotalPotLabelFont		= _T("Segoe UI");
	m_nTotalPotLabelFontHeight	= 18;
	m_crTotalPotLabel			= RGB(255, 255, 255);

	// Create total pot label font. {{
	lf.lfHeight			= m_nTotalPotLabelFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sTotalPotLabelFont.GetBuffer());
	lf.lfWeight			= FW_MEDIUM;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pTotalPotLabelFont = new CFont();
	m_pTotalPotLabelFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pTotalPotLabelFont);
	// }}

	// Create chip label font. {{
	lf.lfHeight			= m_nChipLabelFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sChipLabelFont.GetBuffer());
	lf.lfWeight			= FW_BOLD;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pChipLabelFont = new CFont();
	m_pChipLabelFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pChipLabelFont);
	// }}

	m_crSeatUserNameLabel	= RGB(255, 246, 0);	
	m_crSeatBalanceLabel	= RGB(255, 255, 255);
	m_crSeatActionLabel		= RGB(0, 185, 50);

	// Empty seat label. {{
	m_sEmptySeatLabelFont		= _T("Segoe UI");
	m_nEmptySeatLabelFontHeight	= 18;
	m_nEmptySeatLabelFontWeight = FW_BOLD;
	m_crEmptySeatLabel			= RGB(255, 255, 255);

	lf.lfHeight			= m_nEmptySeatLabelFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sEmptySeatLabelFont.GetBuffer());
	lf.lfWeight			= m_nEmptySeatLabelFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pEmptySeatLabelFont = new CFont();
	m_pEmptySeatLabelFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pEmptySeatLabelFont);
	// }}

	// Seat label positions. {{
	m_ptSeatUserNameLabel.SetPoint(52, 2);	
	m_ptSeatBalanceLabel.SetPoint(52, 18);	
	m_ptSeatActionLabel.SetPoint(52, 34);	
	// }}

	m_nSeatLabelFontHeight	= 17;
	m_sSeatLabelFont		= _T("Segoe UI");

	// Create seat label(s) font. {{
	lf.lfHeight			= m_nSeatLabelFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sSeatLabelFont.GetBuffer());
	lf.lfWeight			= FW_NORMAL;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pSeatLabelFont	= new CFont();
	m_pSeatLabelFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pSeatLabelFont);

	lf.lfItalic				= 1;
	m_pSeatLabelFontItalic	= new CFont();
	m_pSeatLabelFontItalic->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pSeatLabelFontItalic);
	// }}

	m_szCardDimension		.SetSize(50, 70);
	m_szHiddenCardDimension	.SetSize(25, 35);
	m_szAvatar				.SetSize(50, 50);
	m_ptAvatarPos			.SetPoint(1, 1);
	m_ptRankIndicatorPos	.SetPoint(0, 0);

	m_nSeatCardsPanelCX	= 110;

	m_szDefWindowSize	.SetSize(800, 600);

	m_ptSeatCard1Pos	.SetPoint(10, -42);
	m_ptSeatCard2Pos	.SetPoint(30, -42);
	m_ptSeatCard3Pos	.SetPoint(0, -42);
	m_ptSeatCard4Pos	.SetPoint(0, -42);

	// Shortcut button. {{
	m_ptShortcutButton	.SetPoint	(310, 496);
	m_szShortcutButton	.SetSize	(40, 21);
	m_sShortcutButtFont			= _T("Segoe UI");
	m_nShortcutButtFontHeight	= 14;
	m_nShortcutButtFontWeight	= FW_BOLD;
	m_crShortcutButtText		= RGB(0, 0, 0);
	m_crShortcutButtTextClicked	= RGB(153, 0, 0);

	lf.lfHeight			= m_nShortcutButtFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sShortcutButtFont.GetBuffer());
	lf.lfWeight			= m_nShortcutButtFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pShortcutButtFont	= new CFont();
	m_pShortcutButtFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pShortcutButtFont);
	// }}

	// Slider. {{
	m_ptSlider				.SetPoint	(560, 488);
	m_szSlider				.SetSize	(228, 38);
	m_szSliderMinus			.SetSize(11, 11);
	m_szSliderPlus			.SetSize(11, 11);
	m_szSliderBar			.SetSize(187, 14);
	m_szSliderCursor		.SetSize(15, 18);
	m_rcSliderMoneyEdit		.SetRect(645, 534, 745, 564);

	m_sSliderLabelFont			= _T("Segoe UI");
	m_nSliderLabelFontHeight	= 24;
	m_nSliderLabelFontWeight	= FW_BOLD;
	m_crSliderLabel				= RGB(0, 0, 0);

	lf.lfHeight			= m_nSliderLabelFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sSliderLabelFont.GetBuffer());
	lf.lfWeight			= m_nSliderLabelFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pSliderFont	= new CFont();
	m_pSliderFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pSliderFont);
	// }}

	// Action button. {{
	m_crActionButtonText		= RGB(255, 255, 255);
	m_sActionButtonFont			= _T("Segoe UI");
	m_nActionButtonFontHeight	= 22;
	m_nActionButtonFontWeight	= FW_BOLD;
	m_ptActionButton.SetPoint	(310, 530);
	m_szActionButton.SetSize	(100, 40);

	// Create action button label font. 
	lf.lfHeight			= m_nActionButtonFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sActionButtonFont.GetBuffer());
	lf.lfWeight			= m_nActionButtonFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pActionButtonFont = new CFont();
	m_pActionButtonFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pActionButtonFont);
	// }}

	// Dialog control. {{
	m_sDialogFont			= _T("Segoe UI");
	m_nDialogFontHeight		= 18;
	m_nDialogFontWeight		= FW_BOLD;
	m_crDialogText			= RGB(102, 102, 102);
	m_crDialogFill			= RGB(200, 200, 200);
	m_rcDialogBkOmitBorder.SetRect(4, 26, 4, 4);
	m_szDialogCloseButton.SetSize(18, 18);

	// Create font.
	lf.lfHeight			= m_nDialogFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sDialogFont.GetBuffer());
	lf.lfWeight			= m_nDialogFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pDialogFont = new CFont();
	m_pDialogFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pDialogFont);
	// }}

	// Pre-Action checkbox. {{
	m_szPreAction.SetSize(148, 20);
	m_sPreActionLabelFont		= _T("Segoe UI");
	m_nPreActionLabelFontHeight	= 14;
	m_nPreActionLabelFontWeight	= FW_SEMIBOLD;
	m_crPreActionLabel			= RGB(198, 201, 198);

	AddPreActionPosition(PreActionButton::PreAction_WaitForBB_PostBB, CPoint(310, 528));

	AddPreActionPosition(PreActionButton::PreAction_CheckFold, CPoint(310, 528));
	AddPreActionPosition(PreActionButton::PreAction_Fold, CPoint(310, 551));
	AddPreActionPosition(PreActionButton::PreAction_Check, CPoint(310, 575));
	AddPreActionPosition(PreActionButton::PreAction_Call, CPoint(468, 528));
	AddPreActionPosition(PreActionButton::PreAction_CallAny, CPoint(468, 551));
	AddPreActionPosition(PreActionButton::PreAction_CallAnyCheck, CPoint(468, 575));

	lf.lfHeight			= m_nPreActionLabelFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sPreActionLabelFont.GetBuffer());
	lf.lfWeight			= m_nPreActionLabelFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= PROOF_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pPreActionFont = new CFont();
	m_pPreActionFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pPreActionFont);
	// }}
	/*
	SeatPanelInfo* pInfo		= NULL;
	SeatPanelInfo* pInfoCopy	= NULL;
	// Seat panel info parameters. {{
	pInfo = new SeatPanelInfo(); // Seat 1
	pInfo->m_ptPos				.SetPoint(467, 50);
	pInfo->m_ptChipPos			.SetPoint(432, 114);
	pInfo->m_ptDealerButtonPos	.SetPoint(562, 114);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x + m_szSeatPanel.cx/2, pInfo->m_ptPos.y + m_szSeatPanel.cy + 10);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Left;
	pInfo->m_chipGrowDir		= ChipGrowDirection::LeftToRight;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 2
	pInfo->m_ptPos				.SetPoint(633, 122);
	pInfo->m_ptChipPos			.SetPoint(526, 176);
	pInfo->m_ptDealerButtonPos	.SetPoint(602, 126);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x - 20, pInfo->m_ptPos.y + m_szSeatPanel.cy/2);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Left;
	pInfo->m_chipGrowDir		= ChipGrowDirection::LeftToRight;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 3
	pInfo->m_ptPos				.SetPoint(652, 230);
	pInfo->m_ptChipPos			.SetPoint(514, 238);
	pInfo->m_ptDealerButtonPos	.SetPoint(624, 248);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x - 20, pInfo->m_ptPos.y + m_szSeatPanel.cy/2);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Left;
	pInfo->m_chipGrowDir		= ChipGrowDirection::LeftToRight;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 4
	pInfo->m_ptPos				.SetPoint(634, 335);
	pInfo->m_ptChipPos			.SetPoint(500, 295);
	pInfo->m_ptDealerButtonPos	.SetPoint(602, 330);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x, pInfo->m_ptPos.y - m_szHiddenCardDimension.cy - 12);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Left;
	pInfo->m_chipGrowDir		= ChipGrowDirection::LeftToRight;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 5
	pInfo->m_ptPos				.SetPoint(466, 414);
	pInfo->m_ptChipPos			.SetPoint(406, 318);
	pInfo->m_ptDealerButtonPos	.SetPoint(436, 404);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x, pInfo->m_ptPos.y - m_szHiddenCardDimension.cy - 12);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Left;
	pInfo->m_chipGrowDir		= ChipGrowDirection::LeftToRight;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 6
	pInfo->m_ptPos				.SetPoint(210, 414);
	pInfo->m_ptChipPos			.SetPoint(300, 316);
	pInfo->m_ptDealerButtonPos	.SetPoint(346, 404);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x, pInfo->m_ptPos.y - m_szHiddenCardDimension.cy - 12);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Right;
	pInfo->m_chipGrowDir		= ChipGrowDirection::RightToLeft;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 7
	pInfo->m_ptPos				.SetPoint(46, 335);
	pInfo->m_ptChipPos			.SetPoint(206, 308);
	pInfo->m_ptDealerButtonPos	.SetPoint(180, 330);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x, pInfo->m_ptPos.y - m_szHiddenCardDimension.cy - 12);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Right;
	pInfo->m_chipGrowDir		= ChipGrowDirection::RightToLeft;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 8
	pInfo->m_ptPos				.SetPoint(20, 230);
	pInfo->m_ptChipPos			.SetPoint(182, 238);
	pInfo->m_ptDealerButtonPos	.SetPoint(150, 242);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x, pInfo->m_ptPos.y - m_szHiddenCardDimension.cy - 12);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Right;
	pInfo->m_chipGrowDir		= ChipGrowDirection::RightToLeft;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 9
	pInfo->m_ptPos				.SetPoint(46, 122);
	pInfo->m_ptChipPos			.SetPoint(180, 166);
	pInfo->m_ptDealerButtonPos	.SetPoint(178, 126);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x, pInfo->m_ptPos.y - m_szHiddenCardDimension.cy - 12);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Right;
	pInfo->m_chipGrowDir		= ChipGrowDirection::RightToLeft;
	m_seatInfo10.Add(pInfo);

	pInfo = new SeatPanelInfo(); // Seat 10
	pInfo->m_ptPos				.SetPoint(205, 50);
	pInfo->m_ptChipPos			.SetPoint(274, 114);
	pInfo->m_ptDealerButtonPos	.SetPoint(218, 114);
	pInfo->m_ptHiddenCard1		.SetPoint(pInfo->m_ptPos.x, pInfo->m_ptPos.y - m_szHiddenCardDimension.cy - 12);
	pInfo->m_ptHiddenCard2		.SetPoint(pInfo->m_ptHiddenCard1.x + 6, pInfo->m_ptHiddenCard1.y + 4);
	pInfo->m_ptHiddenCard3		.SetPoint(pInfo->m_ptHiddenCard2.x + 6, pInfo->m_ptHiddenCard2.y + 4);
	pInfo->m_ptHiddenCard4		.SetPoint(pInfo->m_ptHiddenCard3.x + 6, pInfo->m_ptHiddenCard3.y + 4);
	pInfo->m_chipLabelTextPos	= PositionDef::Right;
	pInfo->m_chipGrowDir		= ChipGrowDirection::RightToLeft;
	m_seatInfo10.Add(pInfo);
	// }}

	// Max players 2. {{
	pInfo = m_seatInfo10.GetAt(2);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo2.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(7);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo2.Add(pInfoCopy);
	// }}

	// Max players 4. {{
	pInfo = m_seatInfo10.GetAt(1);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo4.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(3);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo4.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(6);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo4.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(8);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo4.Add(pInfoCopy);
	// }}

	// Max players 6. {{
	pInfo = m_seatInfo10.GetAt(1);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo6.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(2);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo6.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(3);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo6.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(6);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo6.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(7);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo6.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(8);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo6.Add(pInfoCopy);
	// }}

	// Max players 9. {{
	CPoint ptOffset(0, 0);
	pInfo = m_seatInfo10.GetAt(0);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo9.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(1);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	ptOffset.SetPoint(0, 10);
	pInfoCopy->m_ptPos.x += ptOffset.x;
	pInfoCopy->m_ptPos.y += ptOffset.y;
	pInfoCopy->m_ptChipPos.x += ptOffset.x;
	pInfoCopy->m_ptChipPos.y += ptOffset.y;
	pInfoCopy->m_ptDealerButtonPos.x += ptOffset.x;
	pInfoCopy->m_ptDealerButtonPos.y += ptOffset.y;
	m_seatInfo9.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(2);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	ptOffset.SetPoint(0, 10);
	pInfoCopy->m_ptPos.x += ptOffset.x;
	pInfoCopy->m_ptPos.y += ptOffset.y;
	pInfoCopy->m_ptChipPos.x += ptOffset.x;
	pInfoCopy->m_ptChipPos.y += ptOffset.y;
	pInfoCopy->m_ptDealerButtonPos.x += ptOffset.x;
	pInfoCopy->m_ptDealerButtonPos.y += ptOffset.y;
	m_seatInfo9.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(3);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	ptOffset.SetPoint(-10, 10);
	pInfoCopy->m_ptPos.x += ptOffset.x;
	pInfoCopy->m_ptPos.y += ptOffset.y;
	pInfoCopy->m_ptChipPos.x += ptOffset.x;
	pInfoCopy->m_ptChipPos.y += ptOffset.y;
	pInfoCopy->m_ptDealerButtonPos.x += ptOffset.x;
	pInfoCopy->m_ptDealerButtonPos.y += ptOffset.y;
	m_seatInfo9.Add(pInfoCopy);


	pInfo = m_seatInfo10.GetAt(4);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	ptOffset.SetPoint(-120, 0);
	pInfoCopy->m_ptPos.x += ptOffset.x;
	pInfoCopy->m_ptPos.y += ptOffset.y;
	pInfoCopy->m_ptChipPos.x += -40;
	pInfoCopy->m_ptChipPos.y += -10;
	pInfoCopy->m_ptDealerButtonPos.x += ptOffset.x;
	pInfoCopy->m_ptDealerButtonPos.y += ptOffset.y;
	m_seatInfo9.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(6);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	ptOffset.SetPoint(-10, 10);
	pInfoCopy->m_ptPos.x += ptOffset.x;
	pInfoCopy->m_ptPos.y += ptOffset.y;
	pInfoCopy->m_ptChipPos.x += ptOffset.x;
	pInfoCopy->m_ptChipPos.y += ptOffset.y;
	pInfoCopy->m_ptDealerButtonPos.x += ptOffset.x;
	pInfoCopy->m_ptDealerButtonPos.y += ptOffset.y;
	m_seatInfo9.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(7);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	ptOffset.SetPoint(0, 10);
	pInfoCopy->m_ptPos.x += ptOffset.x;
	pInfoCopy->m_ptPos.y += ptOffset.y;
	pInfoCopy->m_ptChipPos.x += ptOffset.x;
	pInfoCopy->m_ptChipPos.y += ptOffset.y;
	pInfoCopy->m_ptDealerButtonPos.x += ptOffset.x;
	pInfoCopy->m_ptDealerButtonPos.y += ptOffset.y;
	m_seatInfo9.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(8);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	ptOffset.SetPoint(0, 10);
	pInfoCopy->m_ptPos.x += ptOffset.x;
	pInfoCopy->m_ptPos.y += ptOffset.y;
	pInfoCopy->m_ptChipPos.x += ptOffset.x;
	pInfoCopy->m_ptChipPos.y += ptOffset.y;
	pInfoCopy->m_ptDealerButtonPos.x += ptOffset.x;
	pInfoCopy->m_ptDealerButtonPos.y += ptOffset.y;
	m_seatInfo9.Add(pInfoCopy);

	pInfo = m_seatInfo10.GetAt(9);
	pInfoCopy = new SeatPanelInfo();
	pInfo->Copy(pInfoCopy);
	m_seatInfo9.Add(pInfoCopy);
	// }}
	*/
	// Action panel. {{
	m_rcActionPanel.left	= 0;
	m_rcActionPanel.top		= 482;
	m_rcActionPanel.right	= 800;
	m_rcActionPanel.bottom	= 600;
	// }}

	// Add chips panel. {{
	m_rcAddChips.left		= 338;
	m_rcAddChips.top		= 486;
	m_rcAddChips.right		= 694;
	m_rcAddChips.bottom		= 596;
	// }}

	// TabView control. {{
	m_szTabView.SetSize	(300, 122);
	m_ptTabView.SetPoint(0, 480);
	m_crTabViewBorder			= RGB(0, 0, 0);
	m_nTabViewItemCY			= 16;

	m_nTabViewItemLabelHeight	= 16;
	m_sTabViewItemLabelFont		= _T("Segoe UI");
	m_crTabViewItemLabel		= RGB(255, 255, 255);
	m_crTabViewItemLabelAct		= RGB(102, 102, 102);

	// Create font. 
	lf.lfHeight			= m_nTabViewItemLabelHeight;
	_tcscpy_s(lf.lfFaceName, m_sTabViewItemLabelFont.GetBuffer());
	lf.lfWeight			= FW_NORMAL;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pTabViewItemFont = new CFont();
	m_pTabViewItemFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pTabViewItemFont);
	// }}

	// Chat control. {{
	m_crChatTime		= RGB(122, 0, 0);
	m_crChatUserName	= RGB(0, 122, 0);
	m_crChatMessage		= RGB(0, 0, 122);
	m_crChatSystem		= RGB(255, 0, 0);
	m_crChatDealer		= RGB(122, 122, 0);
	m_sChatFont			= _T("Segoe UI");

	m_nChatTimeFontHeight		= 14;
	m_nChatUserNameFontHeight	= 16;
	m_nChatSystemFontHeight		= 14;
	m_nChatMessageFontHeight	= 14;
	m_nChatDealerFontHeight		= 14;
	m_nChatEditHeight			= 22;
	// }}

	// Lobby
	m_nLobbyHeaderCY	= 110;

	// Lobby logo. {{
	m_szLogo.SetSize	(310, 110);
	m_ptLogo.SetPoint	(0, 0);
	// }}

	// Lobby tab. {{
	m_nLobbyTabCY			= 30;
	m_nLobbyTabLabelHeight	= 16;
	m_sLobbyTabLabelFont	= _T("Segoe UI");
	m_crLobbyTabItemLabelAct= RGB(255, 255, 255);
	m_crLobbyTabItemLabel	= RGB(255, 255, 255);

	lf.lfHeight			= m_nLobbyTabLabelHeight;
	_tcscpy_s(lf.lfFaceName, m_sLobbyTabLabelFont.GetBuffer());
	lf.lfWeight			= FW_NORMAL;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pLobbyTabFont		= new CFont();
	m_pLobbyTabFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pLobbyTabFont);

	m_ptLobbyGamesTab		.SetPoint(0, 105);
	m_ptLobbyGameLimitTab	.SetPoint(0, 134);
	// }}

	// Lobby user info. {{
	m_szUserInfo			.SetSize(222, 68);
	m_rcUserNameLabel		.SetRect(4, 2, 90, 20);
	m_rcUserBalanceLabel	.SetRect(6, 20, 60, 44);
	m_rcUserBalanceAmount	.SetRect(66, 20, 150, 44);
	m_rcUserInPlayLabel		.SetRect(6, 42, 60, 66);
	m_rcUserInPlayAmount	.SetRect(66, 42, 150, 66);
	m_crUserInfoText		= RGB(255, 255, 255);
	m_rcUserAvatar			.SetRect(158, 0, 222, 64);
	m_ptUserRankStar		.SetPoint(90, 4);

	m_nUserInfoFontHeight	= 16;
	m_sUserInfoFont			= _T("Segoe UI");

	lf.lfHeight			= m_nUserInfoFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sUserInfoFont);
	lf.lfWeight			= FW_NORMAL;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pLobbyUserInfoFont= new CFont();
	m_pLobbyUserInfoFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pLobbyUserInfoFont);
	// }}

	// Table message. {{
	m_rcTableMessageOmit.SetRect(5, 6, 5, 6);
	m_sTMessageFont			= _T("Segoe UI");
	m_nTMessageFontHeight	= 16;
	m_nTMessageFontWeight	= FW_MEDIUM;
	m_crTMessageText		= RGB(0, 0, 0);

	lf.lfHeight			= m_nTMessageFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sTMessageFont);
	lf.lfWeight			= m_nTMessageFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pTMessageFont		= new CFont();
	m_pTMessageFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pTMessageFont);
	// }}

	// Hand history window. {{
	m_crHistoryTitleLabel	= RGB(255, 255, 255);		// Hand history window title color.
	m_crHistoryTitleLabelFill	= RGB(102, 102, 102);
	m_nHistoryTitleHeight	= 40;
	m_sHistoryTitleFont		= _T("Segue UI");
	m_nHistoryTitleFontHeight	= 20;
	m_nHistoryTitleFontWeight	= FW_BOLD;

	lf.lfHeight			= m_nHistoryTitleFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sHistoryTitleFont);
	lf.lfWeight			= m_nHistoryTitleFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pHistoryTitleFont		= new CFont();
	m_pHistoryTitleFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pHistoryTitleFont);

	m_crHistoryListText	= RGB(102, 102, 102);
	m_nHistoryWindowFontHeight = 18;
	lf.lfHeight			= m_nHistoryWindowFontHeight;
	_tcscpy_s(lf.lfFaceName, m_sHistoryWindowFont);
	lf.lfWeight			= m_nHistoryWindowFontWeight;
	lf.lfCharSet		= ANSI_CHARSET;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfQuality		= CLEARTYPE_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	m_pHistoryWindowFont		= new CFont();
	m_pHistoryWindowFont->CreateFontIndirect(&lf);
	m_listUsedFonts.Add(m_pHistoryWindowFont);
	// }}


	m_pTableBgImg				= LoadTableImage(m_sTableBgImage, m_sFloorBgImage);
	m_pFloorBgImg				= LoadImage(m_sFloorBgImage);
	m_pCardBackImg				= LoadImage(m_sCardBackImage); 
	m_pSeatPanelBgImg			= LoadImage(m_sSeatPanelBgImage);
	m_pSeatPanelBgDisImg		= LoadImage(m_sSeatPanelBgDisImage);
	m_pSeatPanelActBgImg		= LoadImage(m_sSeatPanelActBgImage);
	m_pRankImg					= LoadImage(m_sRankImage);
	m_pDealerBtnImg				= LoadImage(m_sDealerBtnImage);
	m_pPBarBgImg				= LoadImage(m_sPBarBgImage);
	m_pPBarFillImg				= LoadImage(m_sPBarFillImage);
	m_pPushButton				= LoadImage(m_sPushButtonImage);
	m_pEmptySeatLogo			= LoadImage(m_sEmptySeatLogoImage);
	m_pActionPanelBg			= LoadImage(m_sActionPanelImage);
	m_pActionButtonClicked		= LoadImage(m_sActionBtnImageClk);
	m_pActionButtonDefault		= LoadImage(m_sActionBtnImageDef);
	m_pShortcutButtonDefault	= LoadImage(m_sShortcutBtnImageDef);
	m_pShortcutButtonClicked	= LoadImage(m_sShortcutBtnImageClicked);
	m_pSliderMinus				= LoadImage(m_sSliderMinusImage);
	m_pSliderPlus				= LoadImage(m_sSliderPlusImage);
	m_pSliderCursor				= LoadImage(m_sSliderCursorImage);
	m_pSliderBarBg				= LoadImage(m_sSliderBarBgImage);
	m_pSliderBg					= LoadImage(m_sSliderBgImage);
	m_pPreActionBg				= LoadImage(m_sPreActionBg);
	m_pPreActionChecked			= LoadImage(m_sPreActionChecked);
	m_pPreActionUnchecked		= LoadImage(m_sPreActionUnchecked);
	m_pTabViewItemActive		= LoadImage(m_sTabViewItemActive);
	m_pTabViewItemDefault		= LoadImage(m_sTabViewItemDefault);
	m_pAddChipskgnd				= LoadImage(m_sAddChipsBkgnd);
	m_pTableMessageBk			= LoadImage(m_sTableMessageBk);

	m_pLobbyBkgndImage			= LoadImage(m_sLobbyBkgnd);
	m_pLobbyLogoImage			= LoadImage(m_sLogoImage);
	m_pLobbyTabDefaultImage		= LoadImage(m_sLobbyTabDefaultImage);
	m_pLobbyTabActiveImage		= LoadImage(m_sLobbyTabActiveImage);
	m_pLobbyTabHoverImage		= LoadImage(m_sLobbyTabHoverImage);

	m_pCashierImageDef			= LoadImage(m_sCashierImageDefault);
	m_pCashierImageSel			= LoadImage(m_sCashierImageSelected);
	m_pCashierImageHover		= LoadImage(m_sCashierImageHover);
	m_pCashierImageDis			= LoadImage(m_sCashierImageDisabled);

	m_pLogInImageDef			= LoadImage(m_sLogInImageDefault);
	m_pLogInImageSel			= LoadImage(m_sLogInImageSelected);
	m_pLogInImageHover			= LoadImage(m_sLogInImageHover);
	m_pLogInImageDis			= LoadImage(m_sLogInImageDisabled);
/*
	m_pLobbyButtonDef			= LoadImage(m_sLobbyButtonDefault);
	m_pLobbyButtonSel			= LoadImage(m_sLobbyButtonSelected);
	m_pLobbyButtonHover			= LoadImage(m_sLobbyButtonHover);
	m_pLobbyButtonDis			= LoadImage(m_sLobbyButtonDisabled);
*/
//	m_pUserInfoBkgnd			= LoadImage(m_sUserInfoBkgnd);
	m_pUserInfoRank				= LoadImage(m_sUserInfoRankImage);
	m_pUserInfoRankDis			= LoadImage(m_sUserInfoRankImageDis);

	m_pVScrollBar				= LoadImage(m_sVScrollBar);
	m_pCloseButton				= LoadImage(m_sCloseButtonImage);

	m_pDiamondLogo_Small		= LoadImage(m_sDiamondLogoSmall);
	m_pHeartLogo_Small			= LoadImage(m_sHeartLogoSmall);
	m_pSpadeLogo_Small			= LoadImage(m_sSpadeLogoSmall);
	m_pClubLogo_Small			= LoadImage(m_sClubLogoSmall);
	m_pMoneyTransferArrow		= LoadImage(m_sMoneyTransferArrow);
	m_pDialogBk					= LoadImage(m_sDialogImage);
	m_pDialogCloseNormal		= LoadImage(m_sDialogCloseNormalImage);	
	m_pDialogCloseHover			= LoadImage(m_sDialogCloseHoverImage);	
	m_pDialogClosePushed		= LoadImage(m_sDialogClosePushedImage);	

	CImage imageDest;
	if( GetImageFromImage(m_pPushButton, CRect(0, 0, 34, 23), imageDest) ){
		m_pPushButtonNormal = new CImage();
		m_pPushButtonNormal->Attach(imageDest.Detach());
		m_listUsedImages.Add(m_pPushButtonNormal);
		}
	else
		m_pPushButtonNormal = NULL;

	if( GetImageFromImage(m_pPushButton, CRect(0, 23, 34, 46), imageDest) ){
		m_pPushButtonHover = new CImage();
		m_pPushButtonHover->Attach(imageDest.Detach());
		m_listUsedImages.Add(m_pPushButtonHover);
		}
	else
		m_pPushButtonHover = NULL;

	if( GetImageFromImage(m_pPushButton, CRect(0, 46, 34, 69), imageDest) ){
		m_pPushButtonPushed = new CImage();
		m_pPushButtonPushed->Attach(imageDest.Detach());
		m_listUsedImages.Add(m_pPushButtonPushed);
		}
	else
		m_pPushButtonPushed = NULL;

	if( GetImageFromImage(m_pPushButton, CRect(0, 69, 34, 92), imageDest) ){
		m_pPushButtonDisabled = new CImage();
		m_pPushButtonDisabled->Attach(imageDest.Detach());
		m_listUsedImages.Add(m_pPushButtonDisabled);
		}
	else
		m_pPushButtonDisabled = NULL;

	CreateAlphaChannelImage(m_pCardBackImg);
	CreateAlphaChannelImage(m_pDealerBtnImg);
	CreateAlphaChannelImage(m_pSliderBarBg);
	CreateAlphaChannelImage(m_pSliderBg);
	CreateAlphaChannelImage(m_pRankImg);

	m_listUsedImages.Add(m_pDialogBk);
	m_listUsedImages.Add(m_pMoneyTransferArrow);
	m_listUsedImages.Add(m_pDiamondLogo_Small);
	m_listUsedImages.Add(m_pHeartLogo_Small);
	m_listUsedImages.Add(m_pSpadeLogo_Small);
	m_listUsedImages.Add(m_pClubLogo_Small);
	m_listUsedImages.Add(m_pCloseButton);
	m_listUsedImages.Add(m_pTableBgImg);
	m_listUsedImages.Add(m_pFloorBgImg);
	m_listUsedImages.Add(m_pCardBackImg);
	m_listUsedImages.Add(m_pSeatPanelBgImg);
	m_listUsedImages.Add(m_pSeatPanelBgDisImg);
	m_listUsedImages.Add(m_pSeatPanelActBgImg);
	m_listUsedImages.Add(m_pRankImg);
	m_listUsedImages.Add(m_pDealerBtnImg);
	m_listUsedImages.Add(m_pPBarBgImg);
	m_listUsedImages.Add(m_pPBarFillImg);
	m_listUsedImages.Add(m_pPushButton);
	m_listUsedImages.Add(m_pEmptySeatLogo);
	m_listUsedImages.Add(m_pActionPanelBg);
	m_listUsedImages.Add(m_pActionButtonClicked);
	m_listUsedImages.Add(m_pActionButtonDefault);
	m_listUsedImages.Add(m_pShortcutButtonDefault);
	m_listUsedImages.Add(m_pShortcutButtonClicked);
	m_listUsedImages.Add(m_pSliderMinus);
	m_listUsedImages.Add(m_pSliderPlus);
	m_listUsedImages.Add(m_pSliderCursor);
	m_listUsedImages.Add(m_pSliderBarBg);
	m_listUsedImages.Add(m_pSliderBg);
	m_listUsedImages.Add(m_pPreActionBg);
	m_listUsedImages.Add(m_pPreActionChecked);
	m_listUsedImages.Add(m_pPreActionUnchecked);
	m_listUsedImages.Add(m_pTabViewItemActive);
	m_listUsedImages.Add(m_pTabViewItemDefault);
	m_listUsedImages.Add(m_pAddChipskgnd);
	m_listUsedImages.Add(m_pTableMessageBk);
	m_listUsedImages.Add(m_pLobbyBkgndImage);
	m_listUsedImages.Add(m_pLobbyLogoImage);
	m_listUsedImages.Add(m_pLobbyTabDefaultImage);
	m_listUsedImages.Add(m_pLobbyTabActiveImage);
	m_listUsedImages.Add(m_pLobbyTabHoverImage);
	m_listUsedImages.Add(m_pCashierImageDef);
	m_listUsedImages.Add(m_pCashierImageSel);
	m_listUsedImages.Add(m_pCashierImageHover);
	m_listUsedImages.Add(m_pCashierImageDis);
//	m_listUsedImages.Add(m_pLobbyButtonDef);
//	m_listUsedImages.Add(m_pLobbyButtonSel);
//	m_listUsedImages.Add(m_pLobbyButtonHover);
//	m_listUsedImages.Add(m_pLobbyButtonDis);
//	m_listUsedImages.Add(m_pUserInfoBkgnd);
	m_listUsedImages.Add(m_pLogInImageDef);
	m_listUsedImages.Add(m_pLogInImageSel);
	m_listUsedImages.Add(m_pLogInImageHover);
	m_listUsedImages.Add(m_pLogInImageDis);
	m_listUsedImages.Add(m_pUserInfoRank);
	m_listUsedImages.Add(m_pUserInfoRankDis);
	m_listUsedImages.Add(m_pVScrollBar);

	LoadCardImages();
	LoadChipImages();
	/*
	m_pImageBg				= LoadImage(_T("C:\\Program Files (x86)\\PokerStars\\themes\\black\\bg.jpg"));
	m_pImageFg				= LoadImage(_T("C:\\Program Files (x86)\\PokerStars\\themes\\black\\fg.png"));
	m_pImageFgBorder		= LoadImage(_T("C:\\Program Files (x86)\\PokerStars\\themes\\black\\fg-border.png"));

	ImageHelper::MultiplyBlendImageBpp32(*m_pImageFg, RGB(186, 0, 0));
	

	CImage* pImage	= CombineImages(m_pImageBg, m_pImageFgBorder, false);
	if( pImage ){
		m_pImageTable = CombineImages(pImage, m_pImageFg, false);
		delete pImage;
		}
	else
		m_pImageTable = NULL;

	m_listUsedImages.Add(m_pImageBg);
	m_listUsedImages.Add(m_pImageFgBorder);
	m_listUsedImages.Add(m_pImageTable);
*/

	/*
	CImage* pImg = LoadImage(_T("D:\\C++\\ESPoker\\poker new design\\black\\label\\seat.bmp"));
	CImage* pImg1 = LoadImage(_T("D:\\C++\\ESPoker\\poker new design\\black\\label\\seat1.a.bmp"));

	CImage* pImgDest = CombineImages(pImg, pImg1, true);


	GUID guidPng = {0xb96b3caf,0x0728,0x11d3,0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e};

	pImgDest->SetHasAlphaChannel(true);
	pImgDest->Save(_T("D:\\C++\\ESPoker\\poker new design\\black\\label\\seat.png"), guidPng);
	*/

//	Serialize(_T("c:\\22.txt"), TRUE);
	m_bInited = TRUE;
	return TRUE;
	}

void
PokerGUI::Destroy(){
	m_bInited = FALSE;

	// Delete alpha channel images.
	for(int i=0; i<m_arrAlphaChannel.GetCount(); i++){
		CImage* pImage = (CImage*)m_arrAlphaChannel.GetData(i);
		if( pImage ) delete pImage;
		}
	m_arrAlphaChannel.DeleteAll();

	if( m_pLang ){
		delete m_pLang;
		m_pLang = NULL;
		}

	m_listUsedImages.RemoveAll();
	m_cardImages	.RemoveAll();
	m_listUsedFonts	.RemoveAll();

	m_pChipLabelFont		= NULL;
	m_pSeatLabelFont		= NULL;
	m_pTotalPotLabelFont	= NULL;
	m_pMainPotLabelFont		= NULL;
	m_pPushButtonFont		= NULL;
	m_pSeatLabelFontItalic	= NULL;
	m_pActionButtonFont		= NULL;
	m_pShortcutButtFont		= NULL;
	m_pSliderFont			= NULL;
	m_pPreActionFont		= NULL;
	}

CImage*
PokerGUI::LoadPngFromResource(HMODULE hResModule, LPCTSTR lpszResName){
	CImage* pImage	= new CImage;
	HRSRC	hRsrc	= ::FindResource(hResModule, lpszResName, _T("PNG"));
	HGLOBAL hRes	= ::LoadResource(hResModule, hRsrc);
	if( hRes == NULL ){
		delete pImage;
		return NULL;
		}

	int		nResDataSize	= (int)::SizeofResource(hResModule, hRsrc);
	void*	lpResData		= ::LockResource(hRes);
	HGLOBAL hMem			= GlobalAlloc(GMEM_MOVEABLE, nResDataSize);
	void*	lpGMem			= ::GlobalLock(hMem);
	memcpy(lpGMem, lpResData, nResDataSize);
	::GlobalUnlock(hMem);
	::UnlockResource(hRes);
	::FreeResource(hRes);

	LPSTREAM pStream = NULL;
	if( ::CreateStreamOnHGlobal(hMem, FALSE, &pStream) != S_OK ){
		delete pImage;
		return NULL;
		}

	pImage->Load(pStream);

	pStream->Release();
	::GlobalFree(hMem);
	return pImage;
	}

CImage*
PokerGUI::LoadImage(CString sImageFile, int nWidth /*= -1*/, int nHeight /*= -1*/){
	CImage* pImage = NULL;
#ifdef LOAD_FILES_FROM_DLL
	CString sTemp = sImageFile;
	sTemp.Replace('\\', '@');
	sTemp.MakeUpper();

	CString sResName;
	sResName.Format(_T("~%s~"), sTemp);
	sResName.Replace('~', '\x22');
	HMODULE hResModule = GetModuleHandle(RESOURCE_MODULE);
	pImage = LoadPngFromResource(hResModule, sResName.GetBuffer());
#endif

	if( !pImage ){
		pImage = new CImage();
		Path::BuildFullPath(sImageFile);
		if( pImage->Load(sImageFile.GetBuffer()) != 0 ){
			delete pImage;
			return NULL;
			}
		}

	if( nWidth > 0 && nHeight > 0 ){
		CBitmap bmStretch;
		if( ImgHlp::CreateBitmap32bpp(bmStretch, (COLORREF)0L, nWidth, nHeight, NULL) ){
			CDC memDC;
			memDC.CreateCompatibleDC(NULL);
			memDC.SelectObject(&bmStretch);
			if( pImage->StretchBlt(memDC, CRect(0, 0, nWidth, nHeight), SRCCOPY) ){
				DeleteObject( pImage->Detach() );
				pImage->Attach((HBITMAP)bmStretch.Detach());
				}
			else
				DeleteObject(bmStretch.Detach());
			memDC.DeleteDC();
			}
		}

	// Convert into 32bpp. ################
	if( pImage->GetBPP() != 32 ){
		CBitmap bmTemp;
		bmTemp.Attach(pImage->Detach());
		ImageHelper::ConvertToBitmap32bpp(bmTemp);
		pImage->Attach((HBITMAP)bmTemp.Detach());

		// Make image opaque
		BITMAP bmImage;
		::GetObject(*pImage, sizeof(BITMAP), &bmImage);
		RGBQUAD* p = (RGBQUAD*)bmImage.bmBits;

		int nLoop	= 0;
		int nCt		= bmImage.bmWidth*bmImage.bmHeight;

		while( nLoop < nCt ){
			p->rgbReserved = 255;
			p ++;
			nLoop ++;
			}
		}
	// #######################################
	return pImage;
	}

CString
PokerGUI::LoadXML(CString sXMLFile){
#ifdef LOAD_FILES_FROM_DLL
	CString sTemp = sXMLFile;
	sTemp.Replace('\\', '@');
	sTemp.MakeUpper();

	CString sResName;
	sResName.Format(_T("~%s~"), sTemp);
	sResName.Replace('~', '\x22');

	HMODULE hResModule	= GetModuleHandle(RESOURCE_MODULE);
	HRSRC	hRsrc		= ::FindResource(hResModule, sResName.GetBuffer(), _T("XML"));
	HGLOBAL hRes		= ::LoadResource(hResModule, hRsrc);
	if( hRes == NULL ){
		return _T("");
		}

	int		nResDataSize		= (int)::SizeofResource(hResModule, hRsrc);
	void*	lpResData			= ::LockResource(hRes);
	char*	pszData				= new char[nResDataSize + 1];
	pszData[nResDataSize]		= '\0';
	memcpy(pszData, lpResData, nResDataSize);
	sXMLFile					= pszData;
	delete [] pszData;
	::UnlockResource(hRes);
	::FreeResource(hRes);
	return sXMLFile;
#else
	CString sSource;
	Path::BuildFullPath(sXMLFile);
	HANDLE hFile = CreateFile(sXMLFile.GetBuffer(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0L, NULL);
	if( hFile != INVALID_HANDLE_VALUE ){
		int		nFileSize	= (int)::GetFileSize(hFile, NULL);
		DWORD	dwRead		= 0L;
		BYTE*	lpBuffer	= new BYTE[nFileSize];
		if( ReadFile(hFile, lpBuffer, nFileSize, &dwRead, NULL) ){
			sSource = (LPCTSTR)lpBuffer;
			}
		delete [] lpBuffer;
		CloseHandle(hFile);
		}
	return sSource;
#endif
	}

bool
PokerGUI::GetImageFromImage(CImage* pDestImage, CRect rcDest, CImage& image){
	if( !pDestImage || rcDest.IsRectEmpty() )
		return false;

	if( !image.IsNull() ) return false;

	BITMAP bmImage;
	::GetObject(*pDestImage, sizeof(BITMAP), &bmImage);

	CBitmap bmpImage;
	if( !ImageHelper::CreateBitmap32bpp(bmpImage, RGB(0, 0, 0), rcDest.Width(), rcDest.Height()) )
		return false;

	BITMAP bmImageDest;
	::GetObject(bmpImage, sizeof(BITMAP), &bmImageDest);

	ImageHelper::BitmapOnBitmapEx(&bmImageDest, 0, 0, &bmImage, 
								rcDest.left, rcDest.top, bmImage.bmWidth, bmImage.bmHeight, rcDest.Width(), rcDest.Height()); 
	
	image.Attach((HBITMAP)bmpImage.Detach());
	return true;
	}

CString	
PokerGUI::CardNameByIndex(int nIndex){
	const CString arrCardNum[] = {_T("2"), _T("3"), _T("4"), _T("5"), _T("6"), _T("7"), _T("8"), _T("9"), _T("T"), _T("J"), _T("Q"), _T("K"), _T("A")};
	const CString arrCardType[] = {_T("C"), _T("D"), _T("S"), _T("H")};

	if( nIndex < 0 || nIndex > 52 )
		return _T("");
	return CString(arrCardNum[nIndex%13] + arrCardType[nIndex/13]);
	}

bool
PokerGUI::LoadCardImages(){
	m_cardImages.RemoveAll();

	CString sCardsFolder = m_sCardsFolder;
	if( sCardsFolder.IsEmpty() )
		return false;

	if( sCardsFolder.GetAt(sCardsFolder.GetLength() - 1) != '\\' )
		sCardsFolder += "\\";

	const CString arrCardNum[] = {_T("2"), _T("3"), _T("4"), _T("5"), _T("6"), _T("7"), _T("8"), _T("9"), _T("T"), _T("J"), _T("Q"), _T("K"), _T("A")};
	const CString arrCardType[] = {_T("C"), _T("D"), _T("S"), _T("H")};

	int nLoop1 = 0, nLoop2 = 0;
	int nLen1 = sizeof(arrCardType) / sizeof(CString);
	int nLen2 = sizeof(arrCardNum) / sizeof(CString);

	while(nLoop1 < nLen1 ){
		while( nLoop2 < nLen2 ){
		//	m_cardImages.Add(LoadImage(sCardsFolder + arrCardNum[nLoop2] + arrCardType[nLoop1] + _T(".png"), m_szCardDimension.cx, m_szCardDimension.cy));
			CImage* pCard = LoadImage(sCardsFolder + arrCardNum[nLoop2] + arrCardType[nLoop1] + _T(".png"));
			if( pCard ){
				CreateAlphaChannelImage(pCard);
				m_cardImages.Add(pCard);
				}
			nLoop2 ++;
			}
		nLoop2 = 0;
		nLoop1 ++;
		}

	return true;
	}

void
PokerGUI::CreateAlphaChannelImage(CImage* pImage){
	if( !pImage ) return;
	// Create alpha channel image. {{
	CImage img;
	if( PokerGUI::GetImageFromImage(pImage, CRect(0, 0, pImage->GetWidth(), pImage->GetHeight()), img) ){
		CImage* pImageAlphaChannel = new CImage();
		pImageAlphaChannel->Attach(img.Detach());

		BITMAP bmImage;
		::GetObject(*pImageAlphaChannel, sizeof(BITMAP), &bmImage);
		RGBQUAD* p = (RGBQUAD*)bmImage.bmBits;

		int nLoop	= 0;
		int nCt		= bmImage.bmWidth*bmImage.bmHeight;

		while( nLoop < nCt ){
			p->rgbBlue = p->rgbGreen = p->rgbRed = p->rgbReserved;
			p ++;
			nLoop ++;
			}
		m_arrAlphaChannel.Add((long)pImage, (long)pImageAlphaChannel);
		}
	// }}
	}


bool
PokerGUI::LoadChipImages(){
	// Destroy all. ##################
	m_chipImages		.RemoveAll();
	m_chipImageByAmount	.DeleteAll();
	// ###############################

	CString sChipsFolder = m_sChipsFolder;
	if( sChipsFolder.IsEmpty() )
		return false;

	if( sChipsFolder.GetAt(sChipsFolder.GetLength() - 1) != '\\' )
		sChipsFolder += "\\";
/*
	const CString arrChipImgs[] = 
		{
			_T("0.01"), _T("0.02"), _T("0.05"), 
			_T("0.1"), _T("0.2"), _T("0.5"), 
			_T("1"), _T("2"), _T("5"), 
			_T("10"), _T("20"), _T("50"), 
			_T("100"), _T("200"), _T("500"), 
			_T("1000"), _T("2000"), _T("5000"), 
			_T("10000"), _T("20000"), _T("50000"), 
			_T("100000"), _T("200000"), _T("500000"), 
			_T("1000000"), _T("2000000"), _T("5000000"), 	
		};
*/
	const CString arrChipImgs[] = 
		{
			_T("0.01"), _T("0.05"), 
			_T("0.25"), _T("1")	
		};

	int nCt		= sizeof(arrChipImgs) / sizeof(CString);
	int nLoop	= 0;
	while( nLoop < nCt ){
		int nAmountValue = _tstof(arrChipImgs[nLoop])*100;
		CImage* pImage = LoadImage(sChipsFolder + arrChipImgs[nLoop] + _T(".png"));
		if( pImage ){
			CreateAlphaChannelImage(pImage);
			
			m_chipImages		.Add(pImage);
			m_chipImageByAmount	.Add(nAmountValue, pImage);
			}
		nLoop ++;
		}
	return true;
	}

CImage*
PokerGUI::LoadTableImage(CString sTableImage, CString sFloorImage){
	CImage* pTableImage = LoadImage(sTableImage);
	CImage* pFloorImage = LoadImage(sFloorImage);

	if( !pTableImage || !pFloorImage ){
		if( pTableImage ) delete pTableImage;
		if( pFloorImage ) delete pFloorImage;
		return NULL;
		}

	CBitmap bmpCombined;
	if( !ImageHelper::CreateBitmap32bpp(bmpCombined, RGB(0, 0, 0), pTableImage->GetWidth(), pTableImage->GetHeight()) ){
		delete pTableImage;
		delete pFloorImage;
		return NULL;
		}

	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	memDC.SelectObject(&bmpCombined);

	// Draw floor.
	CRect rcDraw(0, 0, pTableImage->GetWidth(), pTableImage->GetHeight());
	ImgHlp::DrawImage32bpp_Repeated(&memDC, pFloorImage, rcDraw, rcDraw);
	// Draw table.
	ImageHelper::BitmapOnBitmap(bmpCombined, 0, 0, *pTableImage, 0, 0, rcDraw.Width(), rcDraw.Height(), rcDraw.Width(), rcDraw.Height(), 1, 255); 
//	pTableImage->Draw(memDC, 0, 0, rcDraw.Width(), rcDraw.Height(), 0, 0, rcDraw.Width(), rcDraw.Height());

	// Clean up.
	memDC.DeleteDC();
	::DeleteObject(pTableImage->Detach());
	delete pFloorImage;
	
	pTableImage->Attach((HBITMAP)bmpCombined.Detach());
	return pTableImage;
	} 

int
PokerGUI::GetChipImagesByAmount(int nAmount, CPtrArray& arrChipImages){
	arrChipImages.RemoveAll();
	if( nAmount <= 0 )
		return 0;

	int nLoop	= m_chipImageByAmount.GetCount() - 1;
	while( nLoop >= 0 ){
		int nDiv = (nAmount / m_chipImageByAmount[nLoop]);
		if( nDiv > 0 ){
			nAmount = nAmount % m_chipImageByAmount[nLoop];
			// Add chip image. {{
			CImage* pChipImage = m_chipImageByAmount.GetData(nLoop);
			int i = 0;
			while( i < nDiv){
				arrChipImages.Add(pChipImage);
				i ++;
				}
			// }}
			}
		nLoop --;
		}
	return (int)arrChipImages.GetCount();
	}

CImage*
PokerGUI::GetCardImageByIndex(int nIndex){
	if( nIndex == -2 )
		return m_pCardBackImg;
	return m_cardImages.GetAt(nIndex);
	}

bool
PokerGUI::GetPushButtonItemRect(PushButtonState state, CRect& rcSrcImage){
	rcSrcImage.left		= 0;
	rcSrcImage.top		= m_szPushButtonItem.cy*((int)state);
	rcSrcImage.right	= m_szPushButtonItem.cx;
	rcSrcImage.bottom	= m_szPushButtonItem.cy*((int)state) + m_szPushButtonItem.cy;
	return true;
	}

bool
PokerGUI::AddPreActionPosition(PreActionButton preAction, CPoint pos){
	__int64	nPos = (((__int64)pos.x) << 32)|((__int64)pos.y);
	int nIndex = m_arrPreActionPosByType.IndexOf((__int64)preAction);
	if( nIndex == -1 ){
		m_arrPreActionPosByType.Add((__int64)preAction, nPos);
		return true;
		}

	m_arrPreActionPosByType.SetData(nIndex, nPos);
	return true;
	}

bool
PokerGUI::GetPreActionPosition(PreActionButton preAction, CPoint& pos){
	int nIndex = m_arrPreActionPosByType.IndexOf((__int64)preAction);
	if( nIndex == -1 ){
		return false;
		}

	__int64 nPos = m_arrPreActionPosByType.GetData(nIndex);
	pos.x		= (int)(nPos >> 32);
	pos.y		= (int)(nPos & 0xFFFFFFFF);
	return true;
	}

bool
PokerGUI::RenderMipmapImage(CDC* pDC, const CRect rcClipDestDC, const CRect rcDestDC, MipmapImage* pImageSrc, bool bStretch /*= true*/, bool bMemDC /*= false*/){
	if( !pDC || !pImageSrc )
		return false;

	int		nImageWidth		= pImageSrc->GetWidth();
	int		nImageHeight	= pImageSrc->GetHeight();

	int		nSrcImageX		= (rcClipDestDC.left - rcDestDC.left);
	int		nSrcImageY		= (rcClipDestDC.top - rcDestDC.top);
	int		nImageDrawCX	= rcClipDestDC.Width();
	int		nImageDrawCY	= rcClipDestDC.Height();

	if( bStretch ){ //Stretch image
		float	fStretchCX		= rcDestDC.Width() / ((float)nImageWidth);
		float	fStretchCY		= rcDestDC.Height() / ((float)nImageHeight);

		nSrcImageX				/= fStretchCX;
		nSrcImageY				/= fStretchCY;
		nImageDrawCX			/= fStretchCX;
		nImageDrawCY			/= fStretchCY;

		if( bMemDC ){
			CBitmap bmpMem;
			if( ImageHelper::CreateBitmap32bpp(bmpMem, RGB(0, 0, 0), rcDestDC.Width(), rcDestDC.Height()) ){
				CDC memDC;
				memDC.CreateCompatibleDC(pDC);
				memDC.SelectObject(&bmpMem);

				pImageSrc->Draw(memDC, 0, 0, rcDestDC.Width(), rcDestDC.Height(), 0, 0, pImageSrc->GetWidth(), pImageSrc->GetHeight());
				pDC->BitBlt	(rcClipDestDC.left, rcClipDestDC.top, rcClipDestDC.Width(), rcClipDestDC.Height(), &memDC, (rcClipDestDC.left - rcDestDC.left), (rcClipDestDC.top - rcDestDC.top), SRCCOPY);

				memDC	.DeleteDC();
				bmpMem	.DeleteObject();
				return true;
				}
			}
		else{
			if( nImageDrawCX > 0 && nImageDrawCY > 0 ){
				BOOL bRet = pImageSrc->Draw(*pDC, rcClipDestDC.left, rcClipDestDC.top, rcClipDestDC.Width(), rcClipDestDC.Height(),
					nSrcImageX, nSrcImageY, min(nImageDrawCX, nImageWidth), min(nImageDrawCY, nImageHeight));
				return (bRet == TRUE);
				}
			}
		}
	return false;
	}

void
PokerGUI::PlaySoundByType(SoundTypes soundType, int nPlayCt, int nDelayBetween){
	if( nPlayCt <= 0 )
		return;

	const CString* arrSoundFiles[] = {
		&m_sSystemMessageSnd, &m_sAttentionSnd, &m_sCardsDealtSnd, 
		&m_sChipsMovedToPotSnd, &m_sChipsMovedFromPotSnd, &m_sFoldSnd, 
		&m_sCheckSnd, &m_sBetSnd, &m_sRaiseSnd, &m_sCallSnd, &m_sAllInSnd,
		&m_sTimeWarningSnd, &m_sChatMessageSnd
		};
 
	if( soundType < Sound_SystemMessage || soundType > Sound_ChatMessage )
		return;

	return;

	CString sSoundFile = *arrSoundFiles[(int)soundType];

#ifdef LOAD_FILES_FROM_DLL
	CString sTemp = sSoundFile;
	sTemp.Replace('\\', '@');
	sTemp.MakeUpper();

	CString sResName;
	sResName.Format(_T("~%s~"), sTemp);
	sResName.Replace('~', '\x22');
	HMODULE hResModule = GetModuleHandle(RESOURCE_MODULE);

	HRSRC	hRsrc	= ::FindResource(hResModule, sResName.GetBuffer(), _T("WAV"));
	HGLOBAL hRes	= ::LoadResource(hResModule, hRsrc);
	if( hRes == NULL ) return;
		
	void*	lpResData = ::LockResource(hRes);
	::sndPlaySound((LPCTSTR)lpResData, SND_MEMORY|SND_ASYNC|SND_NODEFAULT|SND_NOSTOP);

	::UnlockResource(hRes);
	::FreeResource(hRes);
#else
	Path::BuildFullPath(sSoundFile);
	int nLoop = 0;
	while( nLoop < nPlayCt ){
		::PlaySound(sSoundFile, NULL, SND_FILENAME);
		nLoop ++;
		}
#endif
	}

void
PokerGUI::DrawText(CDC* pDC, CFont* pFont, int x, int y, int flag, CRect rcClipRect, TCHAR* pszText, float fStretchCX, float fStretchCY){
	if( !pDC || !pFont ) return;

	LOGFONT lf;
	pFont->GetLogFont(&lf);

	lf.lfWidth = (lf.lfWidth * fStretchCX);
	lf.lfHeight = (lf.lfHeight * fStretchCY);

	CFont fontNew;
	if( fontNew.CreateFontIndirect(&lf) ){
		CFont* pFontOld = pDC->SelectObject(&fontNew);
		PokerGUI::ExtTextOut(pDC, x, y, flag, rcClipRect, pszText);
		pDC->SelectObject(pFontOld);
		fontNew.DeleteObject();
		}
	else{
		CFont* pFontOld = pDC->SelectObject(pFont);
		PokerGUI::ExtTextOut(pDC, x, y, flag, rcClipRect, pszText);
		pDC->SelectObject(pFontOld);
		}
	}

bool
PokerGUI::StretchedTextFont(CFont* pFontIn, CFont* pFontOut, float fStretchCX, float fStretchCY, bool bUnderLine /*= false*/, bool bBold /*= false*/){
	if( !pFontIn || !pFontOut ) return false;

	LOGFONT lf;
	pFontIn->GetLogFont(&lf);
/*
	if( fStretchCX < 0.8f )
		fStretchCX = 0.08f;
*/
	float fMin = PokerGUI::GetInstance()->m_fMinStretch;
	if( fStretchCY < fMin ){
		fStretchCY = fMin;
		}

	lf.lfWidth = (lf.lfWidth * fStretchCX);
	lf.lfHeight = (lf.lfHeight * fStretchCY);

	if( bUnderLine )
		lf.lfUnderline = 1;
	else
		lf.lfUnderline = 0;

	if( bBold )
		lf.lfWeight = FW_BOLD;

	CFont fontNew;
	if( pFontOut->CreateFontIndirect(&lf) ){
		return true;
		}
	return false;
	}

bool
PokerGUI::ExtTextOut(CDC* pDC, int x, int y, UINT nOptions, const RECT* lpRect, CString sText){
	if( !pDC || sText.GetLength() <= 0 ) 
		return false;

	wchar_t wszText[255];
	int nLen = ImageHelper::UTF8ToUnicode(&sText, wszText, 255);

	BOOL bRet = ::ExtTextOutW(pDC->m_hDC, x, y, nOptions, lpRect, wszText, nLen, NULL);
	return bRet ? true : false;
	}

CString	
PokerGUI::GetLangValue(TCHAR* pszKey){
	PokerGUI* pGUI = PokerGUI::GetInstance();
	if( !pGUI->m_pLang )
		return _T("");
	return pGUI->m_pLang->GetValue(pszKey);
	}

///////////////////////////////////////////////////////////
///
///	class GUILaguageItem
///
///////////////////////////////////////////////////////////

GUILaguageItem::GUILaguageItem(){
	ZeroInit();
	}

BEGIN_DECLARE_VAR(GUILaguageItem, Serializable)
	DECLARE_VAR(_T("Item"),			_T(""), VariableType::None, 0, false, true, false)
	DECLARE_VAR(_T("Key"),			_T(""), VariableType::String, offsetof(GUILaguageItem,m_sKey), false, false, false)
	DECLARE_VAR(_T("Value"),		_T(""), VariableType::String, offsetof(GUILaguageItem,m_sValue), false, false, false)
END_DECLARE_VAR()

GUILaguageItem::~GUILaguageItem(){
	}


///////////////////////////////////////////////////////////
///
///	class GUILanguage
///
///////////////////////////////////////////////////////////

GUILanguage::GUILanguage(){
	}

BEGIN_DECLARE_VAR(GUILanguage, Serializable)
	DECLARE_VAR(_T("GUILanguage"),	_T(""), VariableType::None, 0, false, true, false)
	DECLARE_VAR(_T("Items"),		_T(""), VariableType::None, offsetof(GUILanguage,m_listItems), false, true, true)
END_DECLARE_VAR()

GUILanguage::~GUILanguage(){
	}

CString
GUILanguage::GetValue(TCHAR* pszKey){
	if( !pszKey ) 
		return _T("");
	long lCode = (long)DecodeString(pszKey);
	int nIndex = m_arrKeyArray.IndexOf(lCode);
	if( nIndex == -1 )
		return _T("");

	GUILaguageItem* pItem = (GUILaguageItem*)m_arrKeyArray.GetData(nIndex);
	if( !pItem )
		return _T("");
	return pItem->m_sValue;
	}

BOOL
GUILanguage::DeserializeAsXML(CString sXmlFile){
	BOOL bRet = Serializable::DeserializeAsXML(sXmlFile);
	if( bRet ){
		int nLoop	= 0;
		int nCt		= m_listItems.GetCount();
		m_arrKeyArray.DeleteAll();

		while( nLoop < nCt ){
			GUILaguageItem* pItem = m_listItems.GetAt(nLoop);
			if( pItem ){
				long lCode = (long)DecodeString(pItem->m_sKey.GetBuffer());
				m_arrKeyArray.Add(lCode, (long)pItem);
				}
			nLoop ++;
			}
		}
	return bRet;
	}

BOOL
GUILanguage::DeserializeAsXML(CString* psXmlSource){
	BOOL bRet = Serializable::DeserializeAsXML(psXmlSource);
	if( bRet ){
		int nLoop	= 0;
		int nCt		= m_listItems.GetCount();
		m_arrKeyArray.DeleteAll();

		while( nLoop < nCt ){
			GUILaguageItem* pItem = m_listItems.GetAt(nLoop);
			if( pItem ){
				long lCode = (long)DecodeString(pItem->m_sKey.GetBuffer());
				m_arrKeyArray.Add(lCode, (long)pItem);
				}
			nLoop ++;
			}
		}
	return bRet;
	}