#pragma once


// mutltiDialog 对话框

class mutltiDialog : public CDialog
{
	DECLARE_DYNAMIC(mutltiDialog)

public:
	mutltiDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~mutltiDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
