#pragma once


// CDialogViewCost 对话框

class CDialogViewCost : public CDialog
{
	DECLARE_DYNAMIC(CDialogViewCost)

public:
	CDialogViewCost(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogViewCost();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_costlist };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
