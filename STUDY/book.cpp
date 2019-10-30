// 동적계획법(DP)
// boj	11053	가장 긴 증가하는 부분 수열
// boj	2602	돌다리 건너기
// boj	9251	LCS
// boj	10844	쉬운 계단 수
// boj	11722	가장 긴 감소하는 부분 수열
// boj	9095	1,2,3 더하기
// boj	10164	격자상의 경로
// boj	1890	점프

// 다익스트라
// boj	1916	최소비용 구하기
// boj	6118	숨바꼭질
// boj	1504	특정한 최단경로

// 유니온파인드
// boj 1717 집합의 표현 ... 해결 But 좋은 문제

// 플로이드와샬
// boj 2458 키 순서
// boj 11404 플로이드

// 크루스칼
// boj 1197 최소 스패닝 트리 ... 해결 But 좋은 문제

// DFS와 BFS (그래프)
// boj	1697	숨바꼭질

// 최저공통조상
// boj 11437 LCA

// 에라토스테네스의 체
// boj 2960 에라토스테네스의 체

// 위상정렬
// boj	2252	줄 세우기
// boj	1005	ACM Craft
// boj	2623	음악프로그램

// 스택
// 

// CCW (기하학)
// boj 1708 볼록 껍질 ... 어려움
// 

// 투포인터
// boj 1806 부분합

// 최소신장트리 (최소 스패닝)
// boj 1922 네트워크 연결

// 자료구조
// boj 1874 스택 수열
// boj 10409 서버 : queue 만들어보기

// 구현
// boj 2869 달팽이는 올라가고 싶다

// 개수정렬
// boj	10989	수 정렬하기 3



// IOSTREAM의 cin이 시간초과 발생시
/*	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
*/

// Vector에 있는 값 바로 사용하기
/*
	for(auto i : vec)
*/

/*
	비트 문제
	#include <bitset>

	bitset<100000> b1;

*/

/*
	문장 받을 때
	string str;
	getline(str);
	만약 버퍼에 남아있는 경우
	while (getchar() != '\n');	버퍼 제거
*/

/*
	특정 문자열 찾을 때
	void find_(int start) {
		int k = str.find(cmp_s, start);
		if (k != -1) {
			ans += 1; find_(k + 1);
		}
	}

*/

/*
	마름모 모양 만들기
	for(int i=0; i<half; i++){
		for(int j=half - i; j <= half + i; j++){
			ret += map[i][j];
		}
	}
*/


// 삼성문제
// boj	12100	2048(Easy)
// boj	140501	퇴사
// boj	15683	감시
// boj	15685	드래곤 커브
// boj	16234	인구이동
// boj	16236	아기상어
// swea 1824 혁준이의 프로그래밍 검증
