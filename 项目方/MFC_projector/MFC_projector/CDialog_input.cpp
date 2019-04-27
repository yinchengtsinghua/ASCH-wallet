// CDialog_input.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialog_input.h"
#include "afxdialogex.h"


// CDialog_input 对话框

IMPLEMENT_DYNAMIC(CDialog_input, CDialog)

CDialog_input::CDialog_input(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_INPUT, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialog_input::~CDialog_input()
{
}

void CDialog_input::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_edit1);
	DDX_Control(pDX, IDC_EDIT3, medit2);
}


BEGIN_MESSAGE_MAP(CDialog_input, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog_input::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialog_input::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialog_input 消息处理程序


void CDialog_input::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"收款等待中", L"收款等待中", 0);
}


void CDialog_input::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetWindowTextW(L"");
	medit2.SetWindowTextW(L"");
}


BOOL CDialog_input::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	this->SetWindowTextW(L"收款");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
