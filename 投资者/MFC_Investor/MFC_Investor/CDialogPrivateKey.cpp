// CDialogPrivateKey.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialogPrivateKey.h"
#include "afxdialogex.h"


// CDialogPrivateKey 对话框

IMPLEMENT_DYNAMIC(CDialogPrivateKey, CDialog)

CDialogPrivateKey::CDialogPrivateKey(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_private, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogPrivateKey::~CDialogPrivateKey()
{
}

void CDialogPrivateKey::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_COMBO1, m_com);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDialogPrivateKey, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogPrivateKey::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDialogPrivateKey 消息处理程序


BOOL CDialogPrivateKey::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_com.AddString(_T("ASCH"));
	// 为组合框控件的列表框添加列表项“百度”   
	m_com.AddString(_T("Ethereum"));
	m_com.AddString(_T("BitCoin"));
	m_com.AddString(_T("BitCoinCash"));
	m_com.AddString(_T("HT"));
	m_com.AddString(_T("ASCH"));
	// 默认选择第一项   
	m_com.SetCurSel(0);


	LONG lStyle;
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件

	m_list.InsertColumn(0, L"私钥类型", LVCFMT_LEFT, 100);//插入列 
	m_list.InsertColumn(1, L"私钥", LVCFMT_LEFT, 100);
	

	//int nRow = 0;
	//nRow = m_list.InsertItem(0, L"ASCH");//插入行
	//m_list.SetItemText(0, 1, _T("0"));
	


	//nRow = m_list.InsertItem(0, L"Ethereum");//插入行
	//m_list.SetItemText(0, 1, _T("0"));


	//nRow = m_list.InsertItem(0, L"BitCoin");//插入行
	//m_list.SetItemText(0, 1, _T("0"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogPrivateKey::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString mykey;
	m_edit.GetWindowTextW(mykey);
	int nRow = 0;
	CString keytype;
	m_com.GetWindowTextW(keytype);
	nRow = m_list.InsertItem(0, keytype);//插入行
	m_list.SetItemText(0, 1, mykey);


}
