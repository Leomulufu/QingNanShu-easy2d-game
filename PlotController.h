#pragma once
#include <string>

#include "TmpData.h"

using namespace std;

class PlotController {
public:
	string plotFlag;

	string findPlot(string plotFlag);
	void setPlot(string plotFlag, string path);
	// ���ﱾ�����õ���ģʽ�����ǳ�������ֵ�Bug���Ȳ��ܷ�װ����һ��
	
	PlotController(const PlotController&) = delete;//���ÿ������캯��
	PlotController& operator=(const PlotController&) = delete;//���ø�ֵ�����
	static PlotController& getInstance();


private:
	PlotController();
	TmpData data;
	string path;
};
