#pragma once

#include "stdafx.h"
#include "merror.h"
#include <opencv2\opencv.hpp>
#include <vector>

//#define PAY

#ifdef PAY
#include "pay/arcsoft_face_sdk.h"
#else

#include "free/arcsoft_face_sdk.h"

#endif



class ArcFaceEngine
{
public:
	ArcFaceEngine();
	~ArcFaceEngine();

	void ReadSetting(char*, char*, char*, char*);			//��ȡ�����ļ�
	MRESULT ActiveSDK();									//����
	MRESULT InitEngine(MLong mode);		//��ʼ��
	MRESULT UnInitEngine();				//����ʼ��
	MRESULT PreExtractFeature(IplImage* image, ASF_FaceFeature& feature, ASF_SingleFaceInfo& faceRect); //FR
	MRESULT PreDetectFace(IplImage* image, ASF_SingleFaceInfo& faceRect);                               //FD
	MRESULT FacePairMatching(MFloat &confidenceLevel, ASF_FaceFeature feature1, ASF_FaceFeature feature2);			//�����Ա�
	MRESULT FaceASFProcess(ASF_MultiFaceInfo detectedFaces, IplImage *img, ASF_AgeInfo &ageInfo,
		ASF_GenderInfo &genderInfo, ASF_Face3DAngle &angleInfo, ASF_LivenessInfo& liveNessInfo);									//Process
	const ASF_VERSION* GetVersion();


private:
	MHandle m_hEngine;
};

void PicCutOut(IplImage* src, IplImage* dst, int x, int y);