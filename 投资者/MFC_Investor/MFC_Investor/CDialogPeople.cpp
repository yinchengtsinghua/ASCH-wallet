// CDialogPeople.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_Investor.h"
#include "CDialogPeople.h"
#include "afxdialogex.h"

// CDialogPeople 对话框

IMPLEMENT_DYNAMIC(CDialogPeople, CDialog)

CDialogPeople::CDialogPeople(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_people, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogPeople::~CDialogPeople()
{
}

void CDialogPeople::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDialogPeople, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogPeople::OnBnClickedButton1)
	ON_NOTIFY(LVN_DELETEITEM, IDC_LIST1, &CDialogPeople::OnLvnDeleteitemList1)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &CDialogPeople::OnHdnItemdblclickList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogPeople::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialogPeople 消息处理程序


BOOL CDialogPeople::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	this->SetWindowTextW(L"投资人群聊");
	HICON myIcon[8];
	for (int i = 0; i < 8; i++)
		myIcon[i] = AfxGetApp()->LoadIcon(IDR_MAINFRAME);//这里使用LoadIcon获得HICON  其中IDR_MAINFRAME为系统默认图标
	m_ImageList.Create(32, 32, ILC_COLOR32, 4, 4);
	for (int i = 0; i<8; i++)
		m_ImageList.Add(myIcon[i]);
	m_list.SetImageList(&m_ImageList, LVSIL_NORMAL);
	for (int i = 0; i < 1; i++)
	{
		LVITEM lvitem;
		lvitem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvitem.iItem = i;
		lvitem.pszText = L"尹成";
		lvitem.iImage = i;
		lvitem.iSubItem = 0;
		m_list.InsertItem(&lvitem);
		// ((CListCtrl *) lParam)->InsertItem(i,m_strTitle, i);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogPeople::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	vector <LPWSTR> mystd;
	mystd.push_back(L"骆嫣然");
	mystd.push_back(L"刘茂华");
	mystd.push_back(L"李笑来");
	mystd.push_back(L"李哭去");
	mystd.push_back(L"王晓伟");
	mystd.push_back(L"张小虎");
	mystd.push_back(L"朱小美");

	for (int i = 0; i < 1; i++)
	{
		LVITEM lvitem;
		lvitem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvitem.iItem = i;
		//lvitem.pszText = L"骆嫣然";
		srand((unsigned)time(NULL)); //初始化随机数
		int jd=rand() % 6;
		lvitem.pszText = mystd.at(jd);
		lvitem.iImage = i;
		lvitem.iSubItem = 0;
		m_list.InsertItem(&lvitem);
		// ((CListCtrl *) lParam)->InsertItem(i,m_strTitle, i);
	}
}


void CDialogPeople::OnLvnDeleteitemList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int nItem = -1;
	POSITION pos =(&m_list)->GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		while (pos)
		{
			nItem = (&m_list)->GetNextSelectedItem(pos);
			// nItem即是选中行的序号
		}
	}
	*pResult = 0;
}


void CDialogPeople::OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	int nItem = -1;
	POSITION pos = (&m_list)->GetFirstSelectedItemPosition();
	if (pos != NULL)
	{
		while (pos)
		{
			nItem = (&m_list)->GetNextSelectedItem(pos);
			// nItem即是选中行的序号
		}
	}
	*pResult = 0;
}


void CDialogPeople::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//只删除当前行
	// TODO: Add your control notification handler code here
	int ok = AfxMessageBox(L"确认删除当前行吗？", MB_YESNO);
	if (ok != IDYES) { return; }
	m_list.SetRedraw(FALSE);       //更新内容

	for (int i = m_list.GetItemCount() - 1; i >= 0; i--)
	{
		if (m_list.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)//当前点击的行
		{
			m_list.DeleteItem(i);
			break;//只删除当前行，所以删除就退出
		}
	}
	m_list.SetRedraw(TRUE);
	m_list.Invalidate();
	m_list.UpdateWindow();

}
