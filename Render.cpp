#include <easy2d/easy2d.h>
#include <string>
#include<iostream>

#include "Render.h"
#include "Archive.h"
#include "PlotController.h"
#include "Render.h"
#include "Plot.h"
#include "SceneInstance.h"
#include "Medicine.h"
#include "MedicineGame.h"

using namespace easy2d;
using namespace std;

PlotRender::PlotRender() {
    // ��ʼ��ҳ��
    /*
    auto scene = new Scene;
    SceneManager::enter(scene);
    auto text = new Text("������");
    scene->addChild(text);
   */
    // ��Ϸģ���ʼ�� 
    auto static game = InitButton(new PlayerMedicineData);
}

void PlotRender::render(string word, string image, string voice) {
    // ����ҳ����Ⱦ
    auto scene = SceneInstance::getInstance(1).getScene();
    //auto scene = gcnew Scene;
    SceneManager::enter(scene);
    auto imagePlot = gcnew Sprite(image);
    auto wordPlot = new Text(word);
    imagePlot->setName("plot");
    wordPlot->setName("plot");
    wordPlot->setPos(40,370);
    // �����Զ�����,���������Զ����еĿ��
    wordPlot->setWrapping(true); 
    wordPlot->setWrappingWidth(500);
    // �������ֻ�ͼ��ʽ
    DrawingStyle style;
    style.fillColor = Color(50, 52, 46);         // �������ɫ
    style.strokeColor = Color::Black;       // �������ɫ
    style.strokeWidth = 1.1;                // ������߿��

    // ���û�ͼ��ʽ
    wordPlot->setDrawingStyle(style);
    //�ı���
    auto TextBox = gcnew Sprite("images/TextBox.png");
    scene->addChild(TextBox,1);
    TextBox->setScale(0.51f, 0.51f);
    TextBox->setPos(-10, -10);
    //�󱳾�
    auto BackGround = gcnew Sprite("images/ClassBackGround.png");
    BackGround->setScale(0.8f, 0.8f);
    scene->addChild(BackGround, -1);
    
    scene->addChild(imagePlot,0);
    imagePlot->setScale(0.15f, 0.15f); 
    imagePlot->setPos(-20, 0);
    scene->addChild(wordPlot,2);
    auto music = MusicPlayer::preload(voice);
    // �ж�ָ���Ƿ�Ϊ��
    if (music)
    {
        // ��������
        music->play();
    }
    auto callback = [=](Event* evt)
    {
        // �ݹ�����������ҿ���һֱ������
        // ����������������
        if (evt->type == Event::MouseDown && wordPlot->containsPoint(Input::getMousePos()))
        {
            // �������������ʵ��
            PlotController& controller = PlotController::getInstance();

            // ��ȡ�浵ʵ�����������ʹ�õ���ģʽ
            Archive& archive = Archive::getInstance(0);
            // ����ǰ���ȸı����0�Ŵ浵
            archive.setPlotFlag(archive.getPlotFlag() + "1");
            string path = "";
            int flagError = 0;
            try{
                // ����0�Ŵ浵�Ľ��ȶ�Ӧ�ľ�����Դ·��
                path = controller.findPlot(archive.getPlotFlag());
                if ("" == path) {
                    // �����ǰ�浵����
                    cout << "�浵���� " + archive.getPlotFlag() + " �浵id " + to_string(archive.getID());
                    throw "û���ҵ��������";
                }
            }
            catch (const char* msg) {
                cout << msg << endl;
                flagError = -1;
            }
            if (flagError == 0) {
                // ��������ʵ��
                Plot plot;
                if (path == "option") {
                    // ��������ѡ����Ⱦ��ʵ��
                    RenderInterface* render = new PlotOptionRender;
                    plot.setRender(render);
                }
                else {
                    // ������Ⱦ��ʵ��
                    RenderInterface* render = new PlotRender;
                    plot.setRender(render);
                }
                // ��ʼ������
                scene->removeChildren("plot");
                // ��Ⱦ����
                plot.render(path);
            }

        }
    };
    auto lis = gcnew Listener(callback);
    //imagePlot->addListener(lis);
    // ���ֱ����
    wordPlot->addListener(lis);
}
PlotOptionRender::PlotOptionRender() {
    // ��ʼ��ҳ��
    /*
    auto scene = new Scene;
    SceneManager::enter(scene);
    auto text = new Text("������");
    scene->addChild(text);
    */
}

void PlotOptionRender::render(string word, string image, string voice) {
    // ����ѡ����Ⱦ
    auto scene = SceneInstance::getInstance(1).getScene();
    SceneManager::enter(scene);
    auto imagePlot = gcnew Sprite(image);
    auto wordPlot = new Text(word);
    imagePlot->setName("plot");
    wordPlot->setName("plot");
    // �������ֻ�ͼ��ʽ
    DrawingStyle style;
    style.mode = DrawingStyle::Mode::Solid; // ��ͼģʽΪ���
    style.fillColor = Color(50, 52, 46);         // �������ɫ
    style.strokeColor = Color::Blue;       // �������ɫ
    style.strokeWidth = 2.0;                // ������߿��Ϊ 2.0
    style.lineJoin = LineJoin::Miter;       // �����ཻ��ʽ

    // ���û�ͼ��ʽ
    wordPlot->setDrawingStyle(style);
    scene->addChild(imagePlot);
    scene->addChild(wordPlot);
    auto music = MusicPlayer::preload(voice);

    // �ж�ָ���Ƿ�Ϊ��
    if (music)
    {
        // ��������
        music->play();
    }

    // ����ѡ��ڵ�
    auto callback = [&](Event* evt)
    {
        if (evt->type == Event::MouseDown)
        {
            String option = imagePlot->getName();  // ��ȡѡ������
            Archive& archive = Archive::getInstance(0); // ��ȡ0�Ŵ浵
 
            // ��Ⱦѡ���ľ���
            
            // �������������ʵ��
            PlotController& controller = PlotController::getInstance();

            string path = "";
            int flagError = 0;
            try {
                // ����0�Ŵ浵�Ľ��ȶ�Ӧ�ľ�����Դ·��
                path = controller.findPlot(archive.getPlotFlag());
                if ("" == path) {
                    // �����ǰ�浵����
                    cout << archive.getPlotFlag() + " test" + to_string(archive.getID());
                    throw "û���ҵ�����ѡ��Ľ���" + archive.getPlotFlag();
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
                // ��ʼ������
                scene->removeChildren("plot");
                // ��Ⱦ����
                plot.render(path);
            }
        }
    };
    auto lis = gcnew Listener(callback);
    //imagePlot->addListener(lis);
     // ���ֱ����
    wordPlot->addListener(lis);
    imagePlot->setName("C");    // ����ѡ������
}