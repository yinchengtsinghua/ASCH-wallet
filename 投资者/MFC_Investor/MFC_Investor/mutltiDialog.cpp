// mutltiDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "mutltiDialog.h"
#include "afxdialogex.h"


// mutltiDialog 对话框

IMPLEMENT_DYNAMIC(mutltiDialog, CDialog)

mutltiDialog::mutltiDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

mutltiDialog::~mutltiDialog()
{
}

void mutltiDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mutltiDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &mutltiDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &mutltiDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// mutltiDialog 消息处理程序


void mutltiDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"递交成功", L"同意提议", 0);
	CDialog::OnOK();
}


void mutltiDialog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"递交成功", L"拒绝提议", 0);
	CDialog::OnOK();
}
