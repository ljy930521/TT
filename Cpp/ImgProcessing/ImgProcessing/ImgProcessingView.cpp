﻿
// ImgProcessingView.cpp: CImgProcessingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImgProcessing.h"
#endif

#include "ImgProcessingDoc.h"
#include "ImgProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImgProcessingView

IMPLEMENT_DYNCREATE(CImgProcessingView, CView)

BEGIN_MESSAGE_MAP(CImgProcessingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DOWN_SAMPLING, &CImgProcessingView::OnDownSampling)
END_MESSAGE_MAP()

// CImgProcessingView 생성/소멸

CImgProcessingView::CImgProcessingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImgProcessingView::~CImgProcessingView()
{
}

BOOL CImgProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImgProcessingView 그리기

void CImgProcessingView::OnDraw(CDC* pDC)
{
	CImgProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = G = B = pDoc->m_InputImage[i*pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CImgProcessingView 인쇄

BOOL CImgProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImgProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImgProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImgProcessingView 진단

#ifdef _DEBUG
void CImgProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CImgProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImgProcessingDoc* CImgProcessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImgProcessingDoc)));
	return (CImgProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CImgProcessingView 메시지 처리기


void CImgProcessingView::OnDownSampling()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
