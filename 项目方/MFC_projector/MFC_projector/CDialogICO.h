#pragma once


// CDialogICO 对话框

class CDialogICO : public CDialog
{
	DECLARE_DYNAMIC(CDialogICO)

public:
	CDialogICO(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogICO();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGICO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	CEdit m_edit4;
	CEdit m_edit5;
	CEdit m_edit6;
	CEdit medit_6;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	CComboBox m_com;
};
