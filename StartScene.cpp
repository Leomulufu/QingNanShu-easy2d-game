#include "StartScene.h"
#include <easy2d/easy2d.h>
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include "SimilarSceneManager.h"
#include <string>
#include<iostream>
#include "SimilarSceneManager.h"
#include "SceneInstance.h"

using namespace easy2d;
using namespace std;


StartScene::StartScene() {
      auto StartScene = SceneInstance::getInstance(0).getScene();
      auto StartMenu = gcnew Menu;


      // �Ȳ����볡��
      // SceneManager::enter(StartScene);
      //bgm
      MusicPlayer::preload("musics/StartGame.mp3");
      MusicPlayer::play("musics/StartGame.mp3");
      
     

      auto BackGround01 = gcnew Sprite("images/BackGround01.png");
      auto profile01 = gcnew Sprite("images/profile01.png");
 
      StartScene->addChild(BackGround01);
      BackGround01->setScaleX(0.52f); BackGround01->setScaleY(0.52f);
      StartScene->addChild(StartMenu,1);
      

      // �ҵ����С�޸ĵĵط�
      // �����СС�޸�д�� StartSimilarScene����������̳е���
      StartSimilarScene* actionClass = new StartSimilarScene;
      // �����0�ᴥ��deafult�����д��
      SimilarSceneManager::enter(StartScene, actionClass, 0);
      // �ڻص���������case 1
      
      
      //����һ�����飬��ť��ͨ״̬��ʾ
      auto StartBtn01 = gcnew Sprite("images/StartBtn01.png"); 
      StartBtn01->setScaleX(0.5f); 
      StartBtn01->setScaleY(0.5f);
      StartBtn01->setPos(0, 450);
      StartMenu->addChild(StartBtn01);
      // ����һ�����飬��ť����״̬��ʾ
      auto StartBtn02 = gcnew Sprite("images/StartBtn02.png");
      

      //������Ϸ��ť
      auto ResumeBtn = gcnew Sprite("images/ResumeBtn01.png");
      StartMenu->addChild(ResumeBtn);
      ResumeBtn->setScaleX(0.5f); ResumeBtn->setScaleY(0.5f);
      ResumeBtn->setPos(192, 450);

      //��Ϸ���ð�ť
      auto SetBtn = gcnew Sprite("images/SetBtn01.png");
      StartMenu->addChild(SetBtn);
      SetBtn->setScaleX(0.5f); SetBtn->setScaleY(0.5f);
      SetBtn->setPos(384, 450);

      //������Ա��ť
      auto StaffBtn = gcnew Sprite("images/StaffBtn01.png");
      StartMenu->addChild(StaffBtn);
      StaffBtn->setScaleX(0.5f); StaffBtn->setScaleY(0.5f);
      StaffBtn->setPos(576, 450);

      //�˳���Ϸ��ť
      auto ExitBtn = gcnew Sprite("images/ExitBtn01.png");
      StartMenu->addChild(ExitBtn);
      ExitBtn->setScaleX(0.5f); ExitBtn->setScaleY(0.5f);
      ExitBtn->setPos(768, 450);
      
      //auto callbackStart = [](ButtonEvent evt)
      //{
      //    if (evt == ButtonEvent::Clicked)
      //    {

      //        // �������������ʵ��
      //        PlotController& controller = PlotController::getInstance();
      //        //controller.setPlot("start", "./plot/1/1.txt");
      //        // ��ȡ�浵ʵ�����������ʹ�õ���ģʽ
      //        Archive& archive = Archive::getInstance("0");
      //        archive.setPlotFlag("start");
      //        string path = "";
      //        int flagError = 0;
      //        try {
      //            //cout << "start: " << archive.archiveID << endl;
      //            // ����0�Ŵ浵�Ľ��ȶ�Ӧ�ľ�����Դ·��
      //            path = controller.findPlot(archive.getPlotFlag());
      //            if ("" == path) {
      //                throw "û���ҵ���Ļ�����ļ�";
      //            }
      //        }
      //        catch (const char* msg) {
      //            cerr << msg << endl;
      //            flagError = -1;
      //        }
      //        if (flagError == 0) {
      //            // ��������ʵ��
      //            Plot plot;

      //            // ����������Ⱦ��ʵ��
      //            RenderInterface* render = new PlotRender;

      //            // ���þ���ʵ������Ⱦ��
      //            plot.setRender(render);

      //            // ��Ⱦ����
      //            plot.render(path);
      //        }
      //    }
      //};
      
      auto callbackContinue = [](ButtonEvent evt)
      {
          if (evt == ButtonEvent::Clicked)
          {

              // �������������ʵ��
              PlotController& controller = PlotController::getInstance();

              // ��ȡ�浵ʵ�����������ʹ�õ���ģʽ
              Archive& archive = Archive::getInstance(0);
              string path = "";
              int flagError = 0;
              try {
                  // ����0�Ŵ浵�Ľ��ȶ�Ӧ�ľ�����Դ·��
                  path = controller.findPlot(archive.getPlotFlag());
                  if ("" == path) {
                      throw "û���ҵ��浵�Ľ���";
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
      auto callbackQuit = [](ButtonEvent evt)
      {
          if (evt == ButtonEvent::Clicked)
          {
              Game::quit();
          }
      };

      //auto lisStart = gcnew ButtonListener(callbackStart);
      auto lisQuit = gcnew ButtonListener(callbackQuit);
      auto lisContinue = gcnew ButtonListener(callbackContinue);

    
      //StartBtn01->addListener(lisStart);
      ExitBtn->addListener(lisQuit);
      ResumeBtn->addListener(lisContinue);
    }

