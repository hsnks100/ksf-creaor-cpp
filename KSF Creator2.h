// KSF Creator2.h : KSF Creator2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CKSFCreator2App:
// �� Ŭ������ ������ ���ؼ��� KSF Creator2.cpp�� �����Ͻʽÿ�.
//

class CKSFCreator2App : public CWinApp
{
public:
	CKSFCreator2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

extern CKSFCreator2App theApp;