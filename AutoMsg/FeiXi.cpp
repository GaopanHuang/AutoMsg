#include "StdAfx.h"
#include "FeiXi.h"

std::string CFeiXi::m_url = "https://quanapi.sinaapp.com/fetion.php";
int CFeiXi::FX_SendMessage(char* _usrname,char* _password,char* _number,char* _sms)
{
	int ret = 0;
	char chbuf[FX_MAXSIZE] = {0};
	sprintf(chbuf,"%s?u=%s&p=%s&to=%s&m=%s",m_url.c_str(),_usrname,_password,\
		_number,_sms);
	ret = FX_SendHttp(chbuf);
	return ret;
}
//发送http请求
int CFeiXi::FX_SendHttp(char* _url)
{
	int ret = 0;
	HINTERNET hSession = InternetOpen("UrlFeiXin", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	char strresult[256] = {0};
	if(hSession != NULL)
	{
		HINTERNET hHttp = InternetOpenUrl(hSession, _url, NULL, 0, 
			INTERNET_FLAG_DONT_CACHE, 0);
		if (hHttp != NULL)
		{
			BYTE Temp[FX_MAXSIZE];
			ULONG Number = 1;
			while (Number > 0)
			{
				InternetReadFile(hHttp, Temp, FX_MAXSIZE - 1, &Number);
				Temp[Number] = '\0';
				sprintf(strresult,"%s", Temp);
				//解析返回码
				std::string str = strresult;
				int startpos = str.find_first_of(":")+1;
				int endpos = str.find_first_of(",");
				std::string strcode = str.substr(startpos,endpos-startpos);
				ret = atol(strcode.c_str());
			}
			InternetCloseHandle(hHttp);
			hHttp = NULL;
		}
		InternetCloseHandle(hSession);
		hSession = NULL;
	} 
	return ret;
}