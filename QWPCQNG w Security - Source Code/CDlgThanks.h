// CDlgThanks.h : Declaration of the CCDlgThanks

#pragma once

#include "resource.h"       // main symbols
#include <atlhost.h>
#include "Security.h"

// CCDlgThanks

class CCDlgThanks : 
	public CAxDialogImpl<CCDlgThanks>
{
public:
	CCDlgThanks()
	{
	}

	~CCDlgThanks()
	{
	}

	CSecurity Security;

	enum { IDD = IDD_CDLGTHANKS };

BEGIN_MSG_MAP(CCDlgThanks)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
	COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
	CHAIN_MSG_MAP(CAxDialogImpl<CCDlgThanks>)
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		char* sMainText = new char[500];
		strcpy(sMainText, "Thank you for evaluating the PCQNG device. The evaluation period will expire in 10 days. To continue using the PCQNG after the evaluation period, you must purchase a license at our website www.ComScire.com. After purchase, your licensing information will be sent by email.\n\nTo activate your license. Please enter the licensing information below and click Activate License.");
		int ExpDate = Security.CheckDate();
		if (ExpDate<10)
		{
			sMainText[80] = '0';
			sMainText[81] = 48+ExpDate;
		}
		else
		{
			sMainText[80] = '1';
			sMainText[81] = 38+ExpDate;
		}

		SetDlgItemText(IDC_STATIC1, sMainText);

		CAxDialogImpl<CCDlgThanks>::OnInitDialog(uMsg, wParam, lParam, bHandled);

		delete sMainText;

		return 1;  // Let the system set the focus
	}

	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}
};


