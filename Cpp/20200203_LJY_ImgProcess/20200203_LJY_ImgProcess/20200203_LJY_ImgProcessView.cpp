
// 20200203_LJY_ImgProcessView.cpp: CMy20200203LJYImgProcessView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "20200203_LJY_ImgProcess.h"
#endif

#include "20200203_LJY_ImgProcessDoc.h"
#include "20200203_LJY_ImgProcessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20200203LJYImgProcessView

IMPLEMENT_DYNCREATE(CMy20200203LJYImgProcessView, CView)

BEGIN_MESSAGE_MAP(CMy20200203LJYImgProcessView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DOWN_SAMPLEING, &CMy20200203LJYImgProcessView::OnDownSampleing)
//	ON_COMMAND(ID_UPSAMPLING, &CMy20200203LJYImgProcessView::OnUpsampling)
ON_COMMAND(ID_UP_SAMPLING, &CMy20200203LJYImgProcessView::OnUpSampling)
ON_COMMAND(ID_QUANTIZATION, &CMy20200203LJYImgProcessView::OnQuantization)
ON_COMMAND(ID_SUM_CONSTANT, &CMy20200203LJYImgProcessView::OnSumConstant)
ON_COMMAND(ID_SUB_CONSTANT, &CMy20200203LJYImgProcessView::OnSubConstant)
ON_COMMAND(ID_MUL_CONSTANT, &CMy20200203LJYImgProcessView::OnMulConstant)
ON_COMMAND(ID_DIV_CONSTANT, &CMy20200203LJYImgProcessView::OnDivConstant)
ON_COMMAND(ID_AND_OPERATE, &CMy20200203LJYImgProcessView::OnAndOperate)
ON_COMMAND(ID_OR_OPERATE, &CMy20200203LJYImgProcessView::OnOrOperate)
ON_COMMAND(ID_XOR_OPERATE, &CMy20200203LJYImgProcessView::OnXorOperate)
ON_COMMAND(ID_NEGA_TRANSFORM, &CMy20200203LJYImgProcessView::OnNegaTransform)
ON_COMMAND(ID_GAMMA_CORRECTION, &CMy20200203LJYImgProcessView::OnGammaCorrection)
END_MESSAGE_MAP()

// CMy20200203LJYImgProcessView 생성/소멸

CMy20200203LJYImgProcessView::CMy20200203LJYImgProcessView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy20200203LJYImgProcessView::~CMy20200203LJYImgProcessView()
{
}

BOOL CMy20200203LJYImgProcessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy20200203LJYImgProcessView 그리기

void CMy20200203LJYImgProcessView::OnDraw(CDC* pDC)
{
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();
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
	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i*pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}


	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy20200203LJYImgProcessView 인쇄

BOOL CMy20200203LJYImgProcessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy20200203LJYImgProcessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy20200203LJYImgProcessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy20200203LJYImgProcessView 진단

#ifdef _DEBUG
void CMy20200203LJYImgProcessView::AssertValid() const
{
	CView::AssertValid();
}

void CMy20200203LJYImgProcessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20200203LJYImgProcessDoc* CMy20200203LJYImgProcessView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20200203LJYImgProcessDoc)));
	return (CMy20200203LJYImgProcessDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy20200203LJYImgProcessView 메시지 처리기


void CMy20200203LJYImgProcessView::OnDownSampleing()
{
	// TODO: Add your command handler code here
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CMy20200203LJYImgProcessView::OnUpSampling()
{
	// TODO: Add your command handler code here
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CMy20200203LJYImgProcessView::OnQuantization()
{
	// TODO: Add your command handler code here
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CMy20200203LJYImgProcessView::OnSumConstant()
{
	// TODO: Add your command handler code here
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSumConstant();

	Invalidate(TRUE);

}


void CMy20200203LJYImgProcessView::OnSubConstant()
{

	// TODO: Add your command handler code here
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSubConstant();

	Invalidate(TRUE);

}


void CMy20200203LJYImgProcessView::OnMulConstant()
{
	// TODO: Add your command handler code here
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnMulConstant();

	Invalidate(TRUE);

}


void CMy20200203LJYImgProcessView::OnDivConstant()
{
	// TODO: Add your command handler code here
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnDivConstant();

	Invalidate(TRUE);

}


void CMy20200203LJYImgProcessView::OnAndOperate()
{
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndOperate();

	Invalidate(TRUE);
}


void CMy20200203LJYImgProcessView::OnOrOperate()
{
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrOperate();

	Invalidate(TRUE);
}


void CMy20200203LJYImgProcessView::OnXorOperate()
{
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);
}


void CMy20200203LJYImgProcessView::OnNegaTransform()
{
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNegaTransform();

	Invalidate(TRUE);
}


void CMy20200203LJYImgProcessView::OnGammaCorrection()
{
	CMy20200203LJYImgProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);
}
