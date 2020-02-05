
// 20200131_LJY_imgProcessingView.cpp: CMy20200131LJYimgProcessingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20200131_LJY_imgProcessing.h"
#endif

#include "20200131_LJY_imgProcessingDoc.h"
#include "20200131_LJY_imgProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200131LJYimgProcessingView

IMPLEMENT_DYNCREATE(CMy20200131LJYimgProcessingView, CView)

BEGIN_MESSAGE_MAP(CMy20200131LJYimgProcessingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy20200131LJYimgProcessingView 생성/소멸

CMy20200131LJYimgProcessingView::CMy20200131LJYimgProcessingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20200131LJYimgProcessingView::~CMy20200131LJYimgProcessingView()
{
}

BOOL CMy20200131LJYimgProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20200131LJYimgProcessingView 그리기

void CMy20200131LJYimgProcessingView::OnDraw(CDC* pDC)
{
	CMy20200131LJYimgProcessingDoc* pDoc = GetDocument();
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

}


// CMy20200131LJYimgProcessingView 인쇄

BOOL CMy20200131LJYimgProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20200131LJYimgProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20200131LJYimgProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy20200131LJYimgProcessingView 진단

#ifdef _DEBUG
void CMy20200131LJYimgProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200131LJYimgProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200131LJYimgProcessingDoc* CMy20200131LJYimgProcessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200131LJYimgProcessingDoc)));
	return (CMy20200131LJYimgProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200131LJYimgProcessingView 메시지 처리기
