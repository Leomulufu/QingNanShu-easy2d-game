#pragma once
#include <string>
#include <easy2d/easy2d.h>
using namespace std;
using namespace easy2d;

class SceneInstance {
public:
	static SceneInstance& getInstance(int number);
	int getID();
	Scene* getScene();
private:
	/*
	    0�ų����ǿ�ʼ���棻
		1�ų�������Ϸ������ҳ�棻
	*/
	int id;
	Scene* scene;
	static SceneInstance instances[5];
	SceneInstance() = default;
	SceneInstance(int id);
};
