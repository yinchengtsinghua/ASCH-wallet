#pragma once


// CDialog_Output 对话框
#include<Windows.h>

class CDialog_Output : public CDialog
{
	DECLARE_DYNAMIC(CDialog_Output)

public:
	CDialog_Output(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialog_Output();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUTPUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
