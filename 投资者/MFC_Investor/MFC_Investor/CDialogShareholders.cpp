// CDialogShareholders.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialogShareholders.h"
#include "afxdialogex.h"


// CDialogShareholders 对话框

IMPLEMENT_DYNAMIC(CDialogShareholders, CDialog)

CDialogShareholders::CDialogShareholders(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_shareholders, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogShareholders::~CDialogShareholders()
{
}

void CDialogShareholders::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(CDialogShareholders, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogShareholders::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogShareholders::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialogShareholders 消息处理程序


void CDialogShareholders::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("Word文件(*.doc)|*.doc|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	//CFileDialog fileDlg(FALSE, _T("选择文件"), _T("选择白皮书"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	CFileDialog fileDlg(TRUE, _T("说明文件"), NULL, 0, szFilter, this);

	CString strFilePath;

	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		m_edit2.SetWindowTextW(strFilePath);
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
}


void CDialogShareholders::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"股东大会发起成功", L"股东大会发起成功", 0);
}
