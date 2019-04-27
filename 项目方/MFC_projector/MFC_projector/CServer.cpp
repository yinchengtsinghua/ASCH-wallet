#include"CServer.h"
#include "stdafx.h"

HANDLE     m_hPipe;//�����ܵ�ʵ�����

void OnPipeCreate()
{
	//���������ܵ�
	m_hPipe = CreateNamedPipe(L"\\\\.\\pipe\\MyPipe",
		PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, 0, 1, 1024, 1024, 0, NULL);
	if (INVALID_HANDLE_VALUE == m_hPipe)
	{
		MessageBox(0, L"���������ܵ�ʧ�ܣ�", L"", 0);
		m_hPipe = NULL;
		return;
	}

	//�����������˹������¼�����
	HANDLE hEvent;
	hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (!hEvent)
	{
		MessageBox(0, L"�����¼�����ʧ��", L"", 0);
		CloseHandle(m_hPipe);
		m_hPipe = NULL;
		return;
	}

	OVERLAPPED ovlap;
	ZeroMemory(&ovlap, sizeof(OVERLAPPED));
	ovlap.hEvent = hEvent;

	//�ȴ��ͻ�������ĵ���
	if (!ConnectNamedPipe(m_hPipe, &ovlap))
	{
		if (ERROR_IO_PENDING != GetLastError())
		{
			MessageBox(0, L"�ȴ��ͻ�������ʧ�ܣ�", L"", 0);
			CloseHandle(m_hPipe);
			CloseHandle(hEvent);
			m_hPipe = NULL;
			return;
		}
	}
	if (WAIT_FAILED == WaitForSingleObject(hEvent, INFINITE))
	{
		MessageBox(0, L"�ȴ��¼�����ʧ�ܣ�", L"", 0);
		CloseHandle(m_hPipe);
		CloseHandle(hEvent);
		m_hPipe = NULL;
		return;
	}

	CloseHandle(hEvent);//ִ�е���һ����˵���Ѿ��пͻ������������ܵ�ʵ����������Ҫ���¼�������

}


CString OnPipeRead()
{
	wchar_t buf[100] = { 0 };
	DWORD dwRead;
	if (!ReadFile(m_hPipe, buf, 100, &dwRead, NULL))
	{
		//MessageBox(0, L"��ȡ����ʧ�ܣ�", L"", 0);
		return L"";
	}
	//MessageBox(0, buf, L"", 0);
	wprintf(L"%s", buf);
	return buf;
}


void OnPipeWrite(CString mystr)
{
	//wchar_t buf[] = L"abcdefghijk";
	//printf("%d", wcslen(mystr) + 1);
	DWORD dwWrite;
	if (!WriteFile(m_hPipe, mystr, mystr.GetLength()*2+2, &dwWrite, NULL))
	{
		MessageBox(0, L"д������ʧ�ܣ�", L"", 0);
		return;
	}
}