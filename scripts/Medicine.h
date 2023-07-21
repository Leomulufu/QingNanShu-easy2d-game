#pragma once
#include <easy2d/easy2d.h>
#include <vector>

using namespace std;
using namespace easy2d;

class MedicineData
{
public:
	//�����ֲ�ҩ����
	vector<int> HerbData;
	//�Ƿ�ˮ��
	bool Water = 0;
	//�Ƿ����
	bool Fire = 0;
};

class SavedMedicineData :public MedicineData	 //�����������
{
public:
	SavedMedicineData();
	string Name;
	//���������ҩ
	string Medicine;
	//��������
	string Prepare;
	//���Ʒ���
	string Explain;
	//������ǩ
	string Tag;
};

class PlayerMedicineData :public MedicineData		//������������������ݶԱ�
{
public:
	PlayerMedicineData();
	SavedMedicineData medicine[35];
	//QTE�Ƿ�ɹ�
	bool QTE;
	//�ж�QTE��QTE�ӿ�

	//�ж���ҷ����Ƿ��뼴�з���ƥ��
	int Match(vector<int> HerbData,bool Water, bool Fire);
};
