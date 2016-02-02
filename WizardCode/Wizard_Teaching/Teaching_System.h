/*-----------------------------------------------

	자동동작중에는 작동안하기

-----------------------------------------------*/
VAR OnAuto:#30194;
if( OnAuto ) { return (0); }

/*-----------------------------------------------

	기초상수

-----------------------------------------------*/
VAR TRUE(1), FALSE(0);

/*-----------------------------------------------

	티칭 시스템 초기화
	
-----------------------------------------------*/
// 구성메모리 정의
VAR TeachConfigTable[5000]:#50000;
VAR TeachConfigTableMax(5000);

// 축정의
VAR AXIS_X(1), AXIS_Y(2), AXIS_Z(4), AXIS_A(8), AXIS_B(16), AXIS_C(32);

VAR TeachMasterEnable	:#50000;	// 티칭 마스터 인에이블(사용안함)
VAR TeachOpEnable		:#50001;	// 티칭 인에이블
VAR TeachAxis			:#50002;	// 티칭 동작축
VAR TeachStepMax		:#50003;	// 티칭 최대 스텝수
VAR TeachCurStep		:#50004;	// 티칭 현재 스텝번호
VAR TeachCurStepMax		:#50005;	// 티칭 현재 스텝 최대번호(사용안함)
VAR TeachStepExeOn		:#50006;	// 티칭 스텝실행 중
VAR TeachAllExeOn		:#50007;	// 티칭 전체실행 중
VAR TeachGTransOn		:#50008;	// 티칭 G코드번역 중
VAR TeachMIOn			:#50009;	// 티칭 번역중 다중보간 실행시퀀스
VAR TeachEditEnable		:#50010;	// 티칭 편집 인에이블

VAR TeachDataTableMem	:#50020;	// 티칭 데이터 메모리번지
VAR TeachDataTableSize	:#50021;	// 티칭 데이터 단위 크기
VAR TeachCmdTableMem	:#50022;	// 티칭 명령 메모리번지
VAR TeachCmdTableSize	:#50023;	// 티칭 명령 단위 크기
VAR TeachCmdTableMax	:#50024;	// 티칭 명령테이블 크기(명령수)
VAR TeachCustomPosTableMem:#50025;	// 티칭 사용자 지정위치 메모리
VAR TeachCustomPosTableMax:#50026;	// 티칭 사용자 지정위치 수

// 현재 해석 명령스텝(변환)
VAR TeachCurStepNo		:#50030;	// 현재 해석 명령스텝번호
VAR TeachCurGFile_FP	:#50031;	// G코드  변환시 사용될 파일포인터
	
// 현재 해석 명령버퍼
VAR TeachCurCmdBuf[10]  :#50040;	// 현재 해석 명령버퍼
VAR TeachCurCmd			:#50040;	// 현재 해석 명령
VAR TeachCurCmdNo		:#50041;	// 현재 해석 명령번호
VAR TeachCurParaX		:#50042;	// 현재 해석 파라메터 X
VAR TeachCurParaY		:#50043;	// 현재 해석 파라메터 Y
VAR TeachCurParaZ		:#50044;	// 현재 해석 파라메터 Z
VAR TeachCurParaA		:#50045;	// 현재 해석 파라메터 A
VAR TeachCurParaB		:#50046;	// 현재 해석 파라메터 B
VAR TeachCurParaC		:#50047;	// 현재 해석 파라메터 C
VAR TeachCurPara7		:#50048;	// 현재 해석 파라메터 7
VAR TeachCurPara8		:#50049;	// 현재 해석 파라메터 8

// 최종 해석 좌표
VAR TeachLastCmdBuf[10] :#50050;	// 최근 해석 명령버퍼
VAR TeachLastCmd		:#50050;	// 최근 해석 명령
VAR TeachLastCmdNo		:#50051;	// 최근 해석 명령번호
VAR TeachLastPos[8]		:#50052;
VAR TeachLastPosX		:#50052;	// 최근 해석 파라메터 X
VAR TeachLastPosY		:#50053;	// 최근 해석 파라메터 Y
VAR TeachLastPosZ		:#50054;	// 최근 해석 파라메터 Z
VAR TeachLastPosA		:#50055;	// 최근 해석 파라메터 A
VAR TeachLastPosB		:#50056;	// 최근 해석 파라메터 B
VAR TeachLastPosC		:#50057;	// 최근 해석 파라메터 C
VAR TeachLastFeed		:#50058;	// 최근 해석 파라메터 7
VAR TeachLastRPM		:#50059;	// 최근 해석 파라메터 8

// 명령축 및 옵션
VAR TeachCmdAxis		:#50060;	// 티칭 명령 축
VAR TeachCmdPlane		:#50061;	// 티칭 명령 평면 0=XY, 1=YZ, 2=ZX
VAR TeachCmdDir			:#50062:	// 티칭 명령 방향 0=CW, 1=CCW;
VAR TeachWorkStart		:#50063;	// 티칭 명령 작업동작 시작상황
VAR TeachMIOnStart		:#50064:	// 다중보간 시작 상황
VAR TeachAutoWorkOn		:#50065:
VAR TeachWorkOnMacroNo	:#50070;	// -1이면 사용안함
VAR TeachWorkOffMacroNo	:#50071;	// -1이면 사용안함
VAR TeachOpMoveOffsetMode:#50072;	// 티칭 동작 이동 옵셋모드 (0:일반옵셋)
VAR TeachCmdMoveMode	:#50073:	// 이동명령 형태 (0:기본동작)
	

// 명령속도
VAR TeachCmdSpeed		:#50100;	// 티칭 주명령속도
VAR TeachCmdMoveSpeed	:#50101;	// 티칭 이동명령속도 (G0일 경우 지정없음)
VAR TeachOpMoveSpeed	:#50102;	// 티칭 이동속속도
VAR TeachOpMoveLoSpeed	:#50103;	// 티칭 이동속도도lo (사용안함)
VAR TeachSafeSpeed		:#50104;
VAR TeachCmdRpm			:#50108;

//  추가 지정 속도
VAR TeachCmdSpeed2		:#50110;
VAR TeachCmdSpeed3		:#50111;
VAR TeachCmdSpeed4		:#50112;
	
// 개별축 티칭이동속도
VAR TeachOpMoveSpeedX	:#50120;
VAR TeachOpMoveSpeedY	:#50121;
VAR TeachOpMoveSpeedZ	:#50122;
VAR TeachOpMoveSpeedA	:#50123;
VAR TeachOpMoveSpeedB	:#50124;
VAR TeachOpMoveSpeedC	:#50125;
	
// 비프 주파수/주기
VAR TeachBeep1Freq		:#50180;
VAR TeachBeep1Time		:#50181;
VAR TeachBeep2Freq		:#50182;
VAR TeachBeep2Time		:#50183;
VAR TeachBeep3Freq		:#50184;
VAR TeachBeep3Time		:#50185;
VAR TeachBeep4Freq		:#50186;
VAR TeachBeep4Time		:#50187;

// 지연시간값
VAR TeachDelayTime		:#50190;
VAR TeachDelayTime2		:#50191;
VAR TeachDelayMainWork	:#50195; // 주작업 지연시간

// 위치옵션 테이블 (위치옵션테이블은 항상 10개씩 묶어 일렬로 배치된다. 최대 50개까지
VAR TeachPosOptionTable[500]:#50200;

VAR TeachOpMoveOffset[8]:#50200; 
VAR TeachOpMoveOffsetX	:#50200; 
VAR TeachOpMoveOffsetY	:#50201; 
VAR TeachOpMoveOffsetZ	:#50202; 			
VAR TeachOpMoveOffsetA	:#50203; 
VAR TeachOpMoveOffsetB	:#50204; 
VAR TeachOpMoveOffsetC	:#50205; 

// 위치홀딩 ON/OFF
VAR TeachOpHoldPosOn[8] :#50210;
VAR TeachOpHoldPosXOn	:#50210;
VAR TeachOpHoldPosYOn	:#50211;
VAR TeachOpHoldPosZOn	:#50212;
VAR TeachOpHoldPosAOn	:#50213;
VAR TeachOpHoldPosBOn	:#50214;
VAR TeachOpHoldPosCOn	:#50215;
	
// 홀딩위치
VAR TeachOpHoldPos[8] 	:#50220;
VAR TeachOpHoldPosX 	:#50220;
VAR TeachOpHoldPosY 	:#50221;
VAR TeachOpHoldPosZ 	:#50222;
VAR TeachOpHoldPosA 	:#50223;
VAR TeachOpHoldPosB 	:#50224;
VAR TeachOpHoldPosC 	:#50225;

// 티칭명령 옵셋
VAR TeachCmd_Offset[8]	:#50230:	
VAR TeachCmd_OffsetX	:#50230:	
VAR TeachCmd_OffsetY	:#50231:	
VAR TeachCmd_OffsetZ	:#50232:	
VAR TeachCmd_OffsetA	:#50233:	
VAR TeachCmd_OffsetB	:#50234:	
VAR TeachCmd_OffsetC	:#50235:	

// 이동명령 옵셋
VAR TeachCmdMove_Offset[8]	:#50240:	
VAR TeachCmdMove_OffsetX	:#50240:	
VAR TeachCmdMove_OffsetY	:#50241:	
VAR TeachCmdMove_OffsetZ	:#50242:	
VAR TeachCmdMove_OffsetA	:#50243:	
VAR TeachCmdMove_OffsetB	:#50244:	
VAR TeachCmdMove_OffsetC	:#50245:	

// 지정위치테이블
VAR TeachCustomPosTable[10][10]	:#50400;
	
// 파일경로버퍼
VAR TeachFilePath[100]			:#50500;
VAR TeachGFilePath[100]			:#50600;

/* 
	명령구조테이블 옵셋
---------------------------------------
 0 : 명령ENABLE
 1 : 명령 이름
 2 : 명령 번호 (테이블 인덱스+1)과 동일
 4 : 동작축
 4~6 : 버튼 타이틀
 7 : 경유점 수
 8 : 기록시 모달명령번호 -1 없음, 0 = 상위명령, 1~..., 해당명령번호
 9 : 매크로번호(Mxxxx : xxxx번호) -1 이면 매크로명령아님을 의미
 10 : 주명령이 아닌 보조파라메터명령
 11 : 지정속도, 특정한 속도로 지령될 때 (-1 = 이면 의미없음)
 12 : 티칭동작에서 명령기입과 동시에 다음커서위치 허가
 13 : 티칭동작에서 위치기입 허가
 14 : 현재명령은 주작업 명령이다.
 */
VAR TeachCmdTableOffset_Enable(0);
VAR TeachCmdTableOffset_Name(1);
VAR TeachCmdTableOffset_ID(2);
VAR TeachCmdTableOffset_Axis(3);
VAR TeachCmdTableOffset_Title(4);
VAR TeachCmdTableOffset_ViaNo(7);
VAR TeachCmdTableOffset_Modal(8);
VAR TeachCmdTableOffset_MacroNo(9);
VAR TeachCmdTableOffset_IsPara(10);
VAR TeachCmdTableOffset_Vel(11);
VAR TeachCmdTableOffset_ImNext(12);
VAR TeachCmdTableOffset_ImPos(13);
VAR TeachCmdTableOffset_MainWork(14);
VAR TeachCmdTableOffset_Plane(15); //0 = 특정평면요구없음, 1= 1차원요구, 2=2차원 평면요구

// 테이블
VAR	TeachCmdTable[40][50]		:#51000;
VAR TeachDataTable[500][10]		:#55000;

/*-----------------------------------------------

	칼라코드 변수 선언

-----------------------------------------------*/
VAR WHITE	(0xffffff);
VAR RED		(0x0000ff);
VAR GREEN	(0x00ff00);
VAR BLUE	(0xff0000);
VAR CYAN	(0xffff00);
VAR YELLOW	(0x00ffff);
VAR BLACK	(0x000000);
VAR GRAY	(0XE0E0E0);

