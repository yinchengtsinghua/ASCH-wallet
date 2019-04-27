// CDialog_projects.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialog_projects.h"
#include "afxdialogex.h"


// CDialog_projects 对话框

IMPLEMENT_DYNAMIC(CDialog_projects, CDialog)

CDialog_projects::CDialog_projects(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_projects, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialog_projects::~CDialog_projects()
{
}

void CDialog_projects::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(CDialog_projects, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialog_projects::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDialog_projects::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialog_projects::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialog_projects 消息处理程序


void CDialog_projects::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"投资成功",L"投资成功", 0);
}


BOOL CDialog_projects::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// TODO:  在此添加额外的初始化
	// TODO:  在此添加额外的初始化
	m_list.AddString(L"YinchengASCH");
	m_list.AddString(L"QingMeiChain");
	m_list.AddString(L"OpenChain");
	m_list.AddString(L"AIChain");
	m_list.AddString(L"OracleChain");


	m_edit1.SetWindowTextW(L"源于ASCH平台的二次发币 请求募资，欢迎韭菜升级股东与投资人监管我们干成大事");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialog_projects::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString str = m_list.SelectString(;
	int id=m_list.GetCurSel();
	CString mystr;
	//m_list.GetItemData(id);
	m_list.GetText(id, mystr);
	if (L"OpenAIChain"==mystr) {
		m_edit1.SetWindowTextW(L"OpenAIChain致力于打造人工智能区块链，打造数据，模型，算法于一体的人工智能平台");
	}
	else if (L"QingMeiChain" == mystr)
	{
		m_edit1.SetWindowTextW(L"OpenAIChain致力于打造美术行业的波场区块链，打造去中心化的艺术交易平台");
	}
	else if (L"OpenChain" == mystr)
	{
		m_edit1.SetWindowTextW(L"OpenChain致力于打造全行业最顶尖的开源公链，打造去中心化的项目交易平台");
	}
	else if (L"AIChain" == mystr)
	{
		m_edit1.SetWindowTextW(L"AIChain致力于打造全行业最顶尖的开源人工智能公链，打造AI的顶级公链");
	}
	else if (L"OracleChain" == mystr)
	{
		m_edit1.SetWindowTextW(L"OracleChain全球顶级数据库公链，源于Oracle数据库");
	}
	else {
		m_edit1.SetWindowTextW(L"源于ASCH平台的二次发币 请求募资，欢迎韭菜升级股东与投资人监管我们干成大事");
	}
	//MessageBox(mystr, mystr, 0);
	


}


void CDialog_projects::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}
