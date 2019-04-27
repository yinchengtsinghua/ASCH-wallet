#include"stdafx.h"
#include"CClient.h"



HANDLE     m_hPipe;//�����ܵ�ʵ�����
void OnPipeConnect()
{
	//�ж��Ƿ��п������õ������ܵ�
	if (!WaitNamedPipe(L"\\\\.\\pipe\\MyPipe", //����ǿ�����ͨ�ţ�����Բ�㴦ָ���������˳������ڵ�������
		NMPWAIT_USE_DEFAULT_WAIT))
	{
		//MessageBox(0, L"��ǰû�п������õ������ܵ�ʵ����", L"", 0);
		return;
	}

	//�򿪿��õ������ܵ�������������˽��̽���ͨ��
	m_hPipe = CreateFile(L"\\\\.\\pipe\\MyPipe",
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == m_hPipe)
	{
		//MessageBox(0, L"�������ܵ�ʧ�ܣ�", L"", 0);
		m_hPipe = NULL;
		return;
	}
}


CString  OnPipeRead()
{
	wchar_t buf[100] = { 0 };
	DWORD dwRead;
	if (!ReadFile(m_hPipe, buf, 100, &dwRead, NULL))//���������ܵ���ȡ����  
	{
		MessageBox(0, L"��ȡ����ʧ�ܣ�", L"", 0);
		return L"";
	}
	else
	{
		//wprintf(L"%s", buf);
		//MessageBox(0, buf, buf, 0);
		return buf;
	}
}


void OnPipeWrite(CString mystr)
{


	DWORD dwWrite;
	if (!WriteFile(m_hPipe, mystr, 2 * mystr.GetLength()+ 2, &dwWrite, NULL))//���������ܵ�д������  
	{
		MessageBox(0, L"д������ʧ�ܣ�", L"", 0);
		return;
	}
}






