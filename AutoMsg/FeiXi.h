/************************************************************************/ 
/* 
�ļ����ƣ�FeiXin.h
���ܽ��ܣ����÷��ŵ����API�ӿڷ��Ͷ���
�汾��v1.00�����棩
���ߣ�moki
���ڣ�2014.01.06
*/
/************************************************************************/

#ifndef __FEIXIN__H_
#define __FEIXIN__H_

#include <Windows.h>
#include <string>
#include <wininet.h>
#include <stdio.h>

#define FX_MAXSIZE 4096
#pragma comment(lib, "Wininet.lib") 

class CFeiXi
{
public:
	//���Ͷ���
	static int FX_SendMessage(char* _usrname,char* _password,char* _number,char* _sms);
	//����http����
	static int FX_SendHttp(char* _url);
private:
	static std::string m_url;

public:
	CFeiXi(void);
	~CFeiXi(void);
};

#endif
