#include "Render.h"
#include "Plot.h"

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <iostream>
#include <vector>

using namespace std;

void Plot::setRender(RenderInterface *renderhandle) {
	this->renderHandle = renderhandle;
}

void Plot::render(string path) {
	this->renderHandle->render(plotWord(path), plotImage(path), plotVoice(path));
}

string Plot::plotWord(string path) {
	string value;
	fstream wordPlot;
	try {
		wordPlot.open(path, ios::in);
		while (!wordPlot.eof()) {
			string line = "";
			getline(wordPlot, line);
			value += line + "\n";
		}
		wordPlot.close();
	}catch (exception) {
		throw exception("û�ҵ�������Դ");
	}
	return value;
}

string Plot::plotImage(string path) {
	string image = "";
	
	string name;
	fstream wordPlot;
	string line = "";
	try {
		wordPlot.open(path, ios::in);
		getline(wordPlot, line);
		//std::cout << "�������� " + line << std::endl;
	}
	catch (exception) {
		throw exception("û�ҵ�������Դ");
	}

	// ƥ��˵�����ˣ�ע����������������
	std::regex pattern("/?([^/]+)��");
	std::smatch match1;
	if (std::regex_search(line, match1, pattern)) {
		std::cout << match1[1] << std::endl;
		if ("" != match1[1].str()) {
			image = "images/" + match1[1].str() + ".png";
		}else {
			// ���û�����￪ͷ�Ի�������Ϊ��Ĭ�ϳ���
			image = "images/ClassBackGround.png";
		}
	}
	try {
		std::ifstream file(image);
		if (!file.good()) {
			throw exception("û�ҵ�ͼƬ��Դ");
		}
	}
	catch(exception){
		image = "images/ClassBackGround.png";
	}
	std::cout << image << std::endl;
	return image;
}
string Plot::plotVoice(string path) {
	string voice = "./musics/Speak.mp3";
	return voice;
}
