#pragma once
#include <easy2d/easy2d.h>
#include <iostream>
#include <string>
#include <vector>

#include "StartScene.h"
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include "Medicine.h"
#include "MedicineGame.h"
#include "PlotConfig.h"
#include "SimilarSceneManager.h"

using namespace easy2d;
using namespace std;

int main() {
	/* ��ʼ�� */
	if (Game::init())
	{
		/* �������� */
		Window::setTitle("������");
		Window::setSize(960, 540);

		//�����ʼ��
		 
		PlotConfig::init();

		// �浵��ʼ��
		Archive& archive = Archive::getInstance(0);
		archive.setPlotFlag("start");

		//  ��ҩ��Ϸҳ���ʼ��
		// �ҷŵ�����ģ���ʼ����
		//InitButton(new PlayerMedicineData);
		
		//��ʼ����
		StartScene::StartScene();

		/* ��ʼ��Ϸ */
		Game::start();

	}

};