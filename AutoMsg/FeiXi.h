/************************************************************************/ 
/* 
文件名称：FeiXin.h
功能介绍：利用飞信的免费API接口发送短信
版本：v1.00（初版）
作者：moki
日期：2014.01.06
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
	//发送短信
	static int FX_SendMessage(char* _usrname,char* _password,char* _number,char* _sms);
	//发送http请求
	static int FX_SendHttp(char* _url);
private:
	static std::string m_url;

public:
	CFeiXi(void);
	~CFeiXi(void);
};

#endif
