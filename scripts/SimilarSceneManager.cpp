#include "SimilarSceneManager.h"
#include "StartScene.h"
#include "StartScene.h"
#include <easy2d/easy2d.h>
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include <string>
#include<iostream>
#include "SimilarSceneManager.h"
void SimilarSceneManager::enter(Scene* sceneInit, SimilarSceneAction* actionClass, int action) {
    // ���ⳡ���仯
    static auto scene = sceneInit;
	Scene* similarScene = actionClass->modify(scene, action);
	SceneManager::enter(similarScene);
};
Scene* StartSimilarScene::modify(Scene* scene, int actionID) {
    auto callbackStart = [&](ButtonEvent evt)
    {
        if (evt == ButtonEvent::Clicked)
        {
           
            // �������������ʵ��
            PlotController& controller = PlotController::getInstance();
            //controller.setPlot("start", "./plot/1/1.txt");
            // ��ȡ�浵ʵ�����������ʹ�õ���ģʽ
            Archive& archive = Archive::getInstance(0);
            string path = "";
            int flagError = 0;
            
            try {
                //cout << "start: " << archive.archiveID << endl;
                // ����0�Ŵ浵�Ľ��ȶ�Ӧ�ľ�����Դ·��
                path = controller.findPlot(archive.getPlotFlag());
                if ("" == path) {
                    // �����ǰ�浵����
                    cout << "�浵���� " + archive.getPlotFlag() + " �浵id " + to_string(archive.getID());
                    throw "û���ҵ���Ļ�����ļ�";
                }
            }
            catch (const char* msg) {
                cerr << msg << endl;
                flagError = -1;
            }
            
            if (flagError == 0) {
                // ��������ʵ��
                Plot plot;

                // ����������Ⱦ��ʵ��
                RenderInterface* render = new PlotRender;

                // ���þ���ʵ������Ⱦ��
                plot.setRender(render);

                // ��Ⱦ����
                plot.render(path);
            }
        }
    };
    auto callbackButtonStatus = [&](ButtonEvent evt)
    {
        if (evt == ButtonEvent::Clicked)
        {
            SimilarSceneManager::enter(scene, this, 1);
        }
    };
    auto lisStart = gcnew ButtonListener(callbackStart);
    auto lisButtonStatus = gcnew ButtonListener(callbackButtonStatus);
    switch (actionID)
    {
      // �����ҿ��԰�һ���ڵ�ɾ�ˣ��滻��������
    case 1:
    {
      // �Ƴ���ť1

      scene->removeChild(scene->getChild("StartBtn01"));
      // ����һ�����飬��ť����״̬��ʾ
      auto StartBtn02 = gcnew Sprite("images/StartBtn02.png");
      StartBtn02->setName("StartBtn02");
      StartBtn02->setScaleX(0.5f);
      StartBtn02->setScaleY(0.5f);
      StartBtn02->setPos(0, 450);
      StartBtn02->addListener(lisStart);
      scene->addChild(StartBtn02);
      break;
    }
    default:
    {
      //����һ�����飬��ť��ͨ״̬��ʾ
      auto StartBtn01 = gcnew Sprite("images/StartBtn01.png");
      StartBtn01->setName("StartBtn01");
      StartBtn01->setScaleX(0.5f);
      StartBtn01->setScaleY(0.5f);
      StartBtn01->setPos(0, 450);
      StartBtn01->addListener(lisButtonStatus);
      scene->addChild(StartBtn01);
      break;
    }
    }
	return scene;
}