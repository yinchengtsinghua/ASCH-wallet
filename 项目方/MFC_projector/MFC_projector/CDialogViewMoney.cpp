// CDialogViewMoney.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialogViewMoney.h"
#include "afxdialogex.h"


// CDialogViewMoney 对话框

IMPLEMENT_DYNAMIC(CDialogViewMoney, CDialog)

CDialogViewMoney::CDialogViewMoney(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_viewMoney, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogViewMoney::~CDialogViewMoney()
{
}

void CDialogViewMoney::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDialogViewMoney, CDialog)
END_MESSAGE_MAP()


// CDialogViewMoney 消息处理程序


BOOL CDialogViewMoney::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化


	LONG lStyle;
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件

	m_list.InsertColumn(0, L"代币类型", LVCFMT_LEFT, 150);//插入列 
	m_list.InsertColumn(1, L"代币数量", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"是否锁定", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"是否直接权限", LVCFMT_LEFT, 500);

	int nRow = 0;
	nRow = m_list.InsertItem(0, L"YinchengASCH锁定");//插入行
	m_list.SetItemText(0, 1, _T("0"));
	m_list.SetItemText(0, 2, _T("0"));
	m_list.SetItemText(0, 3, _T("0"));

	nRow = m_list.InsertItem(0, L"YinchengASCH非锁定");//插入行
	m_list.SetItemText(0, 1, _T("0"));
	m_list.SetItemText(0, 2, _T("0"));
	m_list.SetItemText(0, 3, _T("0"));


	nRow = m_list.InsertItem(0, L"ASCH");//插入行
	m_list.SetItemText(0, 1, _T("0"));
	m_list.SetItemText(0, 2, _T("0"));
	m_list.SetItemText(0, 3, _T("0"));
	this->SetWindowTextW(L"融资数据与金额总览");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
