/*-----------------------------------------------

	�ڵ������߿��� �۵����ϱ�

-----------------------------------------------*/
VAR OnAuto:#30194;
if( OnAuto ) { return (0); }

/*-----------------------------------------------

	���ʻ��

-----------------------------------------------*/
VAR TRUE(1), FALSE(0);

/*-----------------------------------------------

	ƼĪ �ý��� �ʱ�ȭ
	
-----------------------------------------------*/
// �����޸� ����
VAR TeachConfigTable[5000]:#50000;
VAR TeachConfigTableMax(5000);

// ������
VAR AXIS_X(1), AXIS_Y(2), AXIS_Z(4), AXIS_A(8), AXIS_B(16), AXIS_C(32);

VAR TeachMasterEnable	:#50000;	// ƼĪ ������ �ο��̺�(������)
VAR TeachOpEnable		:#50001;	// ƼĪ �ο��̺�
VAR TeachAxis			:#50002;	// ƼĪ ������
VAR TeachStepMax		:#50003;	// ƼĪ �ִ� ���ܼ�
VAR TeachCurStep		:#50004;	// ƼĪ ���� ���ܹ�ȣ
VAR TeachCurStepMax		:#50005;	// ƼĪ ���� ���� �ִ��ȣ(������)
VAR TeachStepExeOn		:#50006;	// ƼĪ ���ܽ��� ��
VAR TeachAllExeOn		:#50007;	// ƼĪ ��ü���� ��
VAR TeachGTransOn		:#50008;	// ƼĪ G�ڵ���� ��
VAR TeachMIOn			:#50009;	// ƼĪ ������ ���ߺ��� ���������
VAR TeachEditEnable		:#50010;	// ƼĪ ���� �ο��̺�

VAR TeachDataTableMem	:#50020;	// ƼĪ ������ �޸𸮹���
VAR TeachDataTableSize	:#50021;	// ƼĪ ������ ���� ũ��
VAR TeachCmdTableMem	:#50022;	// ƼĪ ��� �޸𸮹���
VAR TeachCmdTableSize	:#50023;	// ƼĪ ��� ���� ũ��
VAR TeachCmdTableMax	:#50024;	// ƼĪ ������̺� ũ��(��ɼ�)
VAR TeachCustomPosTableMem:#50025;	// ƼĪ ����� ������ġ �޸�
VAR TeachCustomPosTableMax:#50026;	// ƼĪ ����� ������ġ ��

// ���� �ؼ� ��ɽ���(��ȯ)
VAR TeachCurStepNo		:#50030;	// ���� �ؼ� ��ɽ��ܹ�ȣ
VAR TeachCurGFile_FP	:#50031;	// G�ڵ�  ��ȯ�� ���� ����������
	
// ���� �ؼ� ��ɹ���
VAR TeachCurCmdBuf[10]  :#50040;	// ���� �ؼ� ��ɹ���
VAR TeachCurCmd			:#50040;	// ���� �ؼ� ���
VAR TeachCurCmdNo		:#50041;	// ���� �ؼ� ��ɹ�ȣ
VAR TeachCurParaX		:#50042;	// ���� �ؼ� �Ķ���� X
VAR TeachCurParaY		:#50043;	// ���� �ؼ� �Ķ���� Y
VAR TeachCurParaZ		:#50044;	// ���� �ؼ� �Ķ���� Z
VAR TeachCurParaA		:#50045;	// ���� �ؼ� �Ķ���� A
VAR TeachCurParaB		:#50046;	// ���� �ؼ� �Ķ���� B
VAR TeachCurParaC		:#50047;	// ���� �ؼ� �Ķ���� C
VAR TeachCurPara7		:#50048;	// ���� �ؼ� �Ķ���� 7
VAR TeachCurPara8		:#50049;	// ���� �ؼ� �Ķ���� 8

// ���� �ؼ� ��ǥ
VAR TeachLastCmdBuf[10] :#50050;	// �ֱ� �ؼ� ��ɹ���
VAR TeachLastCmd		:#50050;	// �ֱ� �ؼ� ���
VAR TeachLastCmdNo		:#50051;	// �ֱ� �ؼ� ��ɹ�ȣ
VAR TeachLastPos[8]		:#50052;
VAR TeachLastPosX		:#50052;	// �ֱ� �ؼ� �Ķ���� X
VAR TeachLastPosY		:#50053;	// �ֱ� �ؼ� �Ķ���� Y
VAR TeachLastPosZ		:#50054;	// �ֱ� �ؼ� �Ķ���� Z
VAR TeachLastPosA		:#50055;	// �ֱ� �ؼ� �Ķ���� A
VAR TeachLastPosB		:#50056;	// �ֱ� �ؼ� �Ķ���� B
VAR TeachLastPosC		:#50057;	// �ֱ� �ؼ� �Ķ���� C
VAR TeachLastFeed		:#50058;	// �ֱ� �ؼ� �Ķ���� 7
VAR TeachLastRPM		:#50059;	// �ֱ� �ؼ� �Ķ���� 8

// ����� �� �ɼ�
VAR TeachCmdAxis		:#50060;	// ƼĪ ��� ��
VAR TeachCmdPlane		:#50061;	// ƼĪ ��� ��� 0=XY, 1=YZ, 2=ZX
VAR TeachCmdDir			:#50062:	// ƼĪ ��� ���� 0=CW, 1=CCW;
VAR TeachWorkStart		:#50063;	// ƼĪ ��� �۾����� ���ۻ�Ȳ
VAR TeachMIOnStart		:#50064:	// ���ߺ��� ���� ��Ȳ
VAR TeachAutoWorkOn		:#50065:
VAR TeachWorkOnMacroNo	:#50070;	// -1�̸� ������
VAR TeachWorkOffMacroNo	:#50071;	// -1�̸� ������
VAR TeachOpMoveOffsetMode:#50072;	// ƼĪ ���� �̵� �ɼ¸�� (0:�Ϲݿɼ�)
VAR TeachCmdMoveMode	:#50073:	// �̵���� ���� (0:�⺻����)
	

// ��ɼӵ�
VAR TeachCmdSpeed		:#50100;	// ƼĪ �ָ�ɼӵ�
VAR TeachCmdMoveSpeed	:#50101;	// ƼĪ �̵���ɼӵ� (G0�� ��� ��������)
VAR TeachOpMoveSpeed	:#50102;	// ƼĪ �̵��Ӽӵ�
VAR TeachOpMoveLoSpeed	:#50103;	// ƼĪ �̵��ӵ���lo (������)
VAR TeachSafeSpeed		:#50104;
VAR TeachCmdRpm			:#50108;

//  �߰� ���� �ӵ�
VAR TeachCmdSpeed2		:#50110;
VAR TeachCmdSpeed3		:#50111;
VAR TeachCmdSpeed4		:#50112;
	
// ������ ƼĪ�̵��ӵ�
VAR TeachOpMoveSpeedX	:#50120;
VAR TeachOpMoveSpeedY	:#50121;
VAR TeachOpMoveSpeedZ	:#50122;
VAR TeachOpMoveSpeedA	:#50123;
VAR TeachOpMoveSpeedB	:#50124;
VAR TeachOpMoveSpeedC	:#50125;
	
// ���� ���ļ�/�ֱ�
VAR TeachBeep1Freq		:#50180;
VAR TeachBeep1Time		:#50181;
VAR TeachBeep2Freq		:#50182;
VAR TeachBeep2Time		:#50183;
VAR TeachBeep3Freq		:#50184;
VAR TeachBeep3Time		:#50185;
VAR TeachBeep4Freq		:#50186;
VAR TeachBeep4Time		:#50187;

// �����ð���
VAR TeachDelayTime		:#50190;
VAR TeachDelayTime2		:#50191;
VAR TeachDelayMainWork	:#50195; // ���۾� �����ð�

// ��ġ�ɼ� ���̺� (��ġ�ɼ����̺��� �׻� 10���� ���� �Ϸķ� ��ġ�ȴ�. �ִ� 50������
VAR TeachPosOptionTable[500]:#50200;

VAR TeachOpMoveOffset[8]:#50200; 
VAR TeachOpMoveOffsetX	:#50200; 
VAR TeachOpMoveOffsetY	:#50201; 
VAR TeachOpMoveOffsetZ	:#50202; 			
VAR TeachOpMoveOffsetA	:#50203; 
VAR TeachOpMoveOffsetB	:#50204; 
VAR TeachOpMoveOffsetC	:#50205; 

// ��ġȦ�� ON/OFF
VAR TeachOpHoldPosOn[8] :#50210;
VAR TeachOpHoldPosXOn	:#50210;
VAR TeachOpHoldPosYOn	:#50211;
VAR TeachOpHoldPosZOn	:#50212;
VAR TeachOpHoldPosAOn	:#50213;
VAR TeachOpHoldPosBOn	:#50214;
VAR TeachOpHoldPosCOn	:#50215;
	
// Ȧ����ġ
VAR TeachOpHoldPos[8] 	:#50220;
VAR TeachOpHoldPosX 	:#50220;
VAR TeachOpHoldPosY 	:#50221;
VAR TeachOpHoldPosZ 	:#50222;
VAR TeachOpHoldPosA 	:#50223;
VAR TeachOpHoldPosB 	:#50224;
VAR TeachOpHoldPosC 	:#50225;

// ƼĪ��� �ɼ�
VAR TeachCmd_Offset[8]	:#50230:	
VAR TeachCmd_OffsetX	:#50230:	
VAR TeachCmd_OffsetY	:#50231:	
VAR TeachCmd_OffsetZ	:#50232:	
VAR TeachCmd_OffsetA	:#50233:	
VAR TeachCmd_OffsetB	:#50234:	
VAR TeachCmd_OffsetC	:#50235:	

// �̵���� �ɼ�
VAR TeachCmdMove_Offset[8]	:#50240:	
VAR TeachCmdMove_OffsetX	:#50240:	
VAR TeachCmdMove_OffsetY	:#50241:	
VAR TeachCmdMove_OffsetZ	:#50242:	
VAR TeachCmdMove_OffsetA	:#50243:	
VAR TeachCmdMove_OffsetB	:#50244:	
VAR TeachCmdMove_OffsetC	:#50245:	

// ������ġ���̺�
VAR TeachCustomPosTable[10][10]	:#50400;
	
// ���ϰ�ι���
VAR TeachFilePath[100]			:#50500;
VAR TeachGFilePath[100]			:#50600;

/* 
	��ɱ������̺� �ɼ�
---------------------------------------
 0 : ���ENABLE
 1 : ��� �̸�
 2 : ��� ��ȣ (���̺� �ε���+1)�� ����
 4 : ������
 4~6 : ��ư Ÿ��Ʋ
 7 : ������ ��
 8 : ��Ͻ� ��޸�ɹ�ȣ -1 ����, 0 = �������, 1~..., �ش��ɹ�ȣ
 9 : ��ũ�ι�ȣ(Mxxxx : xxxx��ȣ) -1 �̸� ��ũ�θ�ɾƴ��� �ǹ�
 10 : �ָ���� �ƴ� �����Ķ���͸��
 11 : �����ӵ�, Ư���� �ӵ��� ���ɵ� �� (-1 = �̸� �ǹ̾���)
 12 : ƼĪ���ۿ��� ��ɱ��԰� ���ÿ� ����Ŀ����ġ �㰡
 13 : ƼĪ���ۿ��� ��ġ���� �㰡
 14 : �������� ���۾� ����̴�.
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
VAR TeachCmdTableOffset_Plane(15); //0 = Ư�����䱸����, 1= 1�����䱸, 2=2���� ���䱸

// ���̺�
VAR	TeachCmdTable[40][50]		:#51000;
VAR TeachDataTable[500][10]		:#55000;

/*-----------------------------------------------

	Į���ڵ� ���� ����

-----------------------------------------------*/
VAR WHITE	(0xffffff);
VAR RED		(0x0000ff);
VAR GREEN	(0x00ff00);
VAR BLUE	(0xff0000);
VAR CYAN	(0xffff00);
VAR YELLOW	(0x00ffff);
VAR BLACK	(0x000000);
VAR GRAY	(0XE0E0E0);

