#pragma once


// CDialogdispute 对话框

class CDialogdispute : public CDialog
{
	DECLARE_DYNAMIC(CDialogdispute)

public:
	CDialogdispute(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogdispute();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_dispute };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
