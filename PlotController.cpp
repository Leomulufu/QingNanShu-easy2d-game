#include <string>
#include <iostream>
#include "TmpData.h"
#include "plotController.h"
using namespace std;

string PlotController::findPlot(string plotFlag) {
	//cout << "plotFlag: " << plotFlag << endl;
	return this->data.get(plotFlag);
}
void PlotController::setPlot(string plotFlag, string path) {
	//cout << "work: " << plotFlag << endl;
	this->data.setPath("./tmp/");
	this->data.set(plotFlag, path);
}
PlotController::PlotController() {

}
PlotController& PlotController::getInstance() {
	// ȷ����ͬ����������ǵ���
	static PlotController instance;
	//cout << "Instance address: " << &instance << endl; 
	// ��ӡ�����ַ
	return instance;

}
