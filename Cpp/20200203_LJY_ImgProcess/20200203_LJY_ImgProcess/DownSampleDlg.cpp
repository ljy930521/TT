// DownSampleDlg.cpp: 구현 파일
//

#include "pch.h"
#include "20200203_LJY_ImgProcess.h"
#include "DownSampleDlg.h"
#include "afxdialogex.h"


// CDownSampleDlg 대화 상자

IMPLEMENT_DYNAMIC(CDownSampleDlg, CDialog)

CDownSampleDlg::CDownSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, m_DownSampleRate(0)
{

}

CDownSampleDlg::~CDownSampleDlg()
{
}

void CDownSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_DownSampleRate);
}


BEGIN_MESSAGE_MAP(CDownSampleDlg, CDialog)
END_MESSAGE_MAP()


// CDownSampleDlg 메시지 처리기
