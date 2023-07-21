#pragma once
#include "Medicine.h"
#include <easy2d/easy2d.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace easy2d;
using namespace std;

//HerbData,��0-6���ֱ������������£��Ժ�����ƽ��ζ����ζ�࣬ζ��

SavedMedicineData::SavedMedicineData()
{
	//ʡ�����·���
}

PlayerMedicineData::PlayerMedicineData()
{
	Sprite** medicineIcon = new Sprite * [34];

	medicine[0].Name = "�������ε���ҩ";
	medicine[0].HerbData = { 0,0,0,0,0,0,0 };
	medicine[0].Water = 0;
	medicine[0].Fire = 0;
	medicine[0].Medicine = "";
	medicine[0].Prepare = "";
	medicine[0].Explain = "";
	medicine[0].Tag = "";

	medicine[1].Name = "�˲ΰܶ�ɢ";
	medicine[1].HerbData = { 7,2,0,0,2,3,0 };
	medicine[1].Water = 1;
	medicine[1].Fire = 0;
	medicine[1].Medicine = "�������²�ҩ������ζ����ҩ������ζ���ҩ ��";
	medicine[1].Prepare = "ˮ�ơ�";
	medicine[1].Explain = "���˲ΰܶ�����ܺ��Ǽ����ǰ�׽�ͬ���������ɼ����������ʪ��Ч�ꡣ��";
	medicine[1].Tag = "���ҩ�����Ȼ��Σ������ߡ�";

	medicine[2].Name = "�����";
	medicine[2].HerbData = { 9,4,0,0,3,2,0 };
	medicine[2].Water = 1;
	medicine[2].Fire = 1;
	medicine[2].Medicine = "�������²�ҩ������ζ����ҩ������ζ���ҩ ��";
	medicine[2].Prepare = "ˮ���ơ�";
	medicine[2].Explain = "����������ù�֦�����ʸʲ��İ�ʩ�� ���ȶ�ͷ��ʹ���޺�������֮�ˡ���";
	medicine[2].Tag = "���ҩ������ƽ�����η纮��";

	medicine[3].Name = "έ����";
	medicine[3].HerbData = { 8,0,3,1,0,0,4 };
	medicine[3].Water = 1;
	medicine[3].Fire = 0;
	medicine[3].Medicine = " �����Ժ���ҩ��һ����ƽ��ҩ���ķ�ζ�ʲ�ҩ��";
	medicine[3].Prepare = "ˮ�ơ�";
	medicine[3].Explain = "��έ���ϰ������ʣ���λ�̵�����ܣ��ȶ�̵���·�Ӹ��ŧ��δ�ɾ�ʤ�Ρ���";
	medicine[3].Tag = "���ȼ�����λ�̵���η�Ӹ��";

	medicine[4].Name = "��ĸ����ɢ";
	medicine[4].HerbData = { 10,1,1,1,1,3,3 };
	medicine[4].Water = 1;
	medicine[4].Fire = 0;
	medicine[4].Medicine = " һ�����²�ҩ��һ���Ժ���ҩ��һ����ƽ��ҩ��һ��ζ����ҩ������ζ���ҩ ������ζ�ʲ�ҩ��";
	medicine[4].Prepare = "ˮ�ơ�";
	medicine[4].Explain = "����ĸ����ɢ���ߣ���Ƥ�۹��������������ʸ�̵�ѿ������ﻯ̵�����塣��";
	medicine[4].Tag = "��̵������λ�̵���ο��ԡ�";

	medicine[5].Name = "�׻���";
	medicine[5].HerbData = { 8,0,3,1,0,1,3 };
	medicine[5].Water = 1;
	medicine[5].Fire = 0;
	medicine[5].Medicine = " �����Ժ���ҩ��һ����ƽ��ҩ�� һ��ζ���ҩ ������ζ�ʲ�ҩ��";
	medicine[5].Prepare = "ˮ�ơ�";
	medicine[5].Explain = "���׻���֪���׸ʣ���������ֹ�ʷ���������ʢ�Ĵ�֤�����������˲�����";
	medicine[5].Tag = "���ȼ��������������ϻ�";

	medicine[6].Name = "��һɢ";
	medicine[6].HerbData = { 9,0,4,1,0,0,4 };
	medicine[6].Water = 1;
	medicine[6].Fire = 0;
	medicine[6].Medicine = " �ķ��Ժ���ҩ��һ����ƽ��ҩ�� �ķ�ζ�ʲ�ҩ��";
	medicine[6].Prepare = "ˮ�ơ�";
	medicine[6].Explain = "����һɢ�û�ʯ�ݣ�������ʪ�й�Ч����Ԫ�����뼦�գ�ɰ�챡�ɼ�֮�á���";
	medicine[6].Tag = "�������������ʪ������ʪ֢��";

	medicine[7].Name = "���߸�¶�";
	medicine[7].HerbData = { 10,0,3,2,1,0,4 };
	medicine[7].Water = 1;
	medicine[7].Fire = 0;
	medicine[7].Medicine = " �����Ժ���ҩ��������ƽ��ҩ��һ��ζ����ҩ�� �ķ�ζ�ʲ�ҩ��";
	medicine[7].Prepare = "ˮ�ơ�";
	medicine[7].Explain = "�����߸�¶���߸࣬����ˮ��ʯ�ݣ�������������ʪ�����ȷ�����к������";
	medicine[7].Tag = "�������������ʪ������ʪ֢��";

	medicine[8].Name = "Ѫ��������";
	medicine[8].HerbData = { 8,1,1,2,1,2,1 };
	medicine[8].Water = 1;
	medicine[8].Fire = 0;
	medicine[8].Medicine = " һ�����²�ҩ��һ���Ժ���ҩ��������ƽ��ҩ��һ��ζ����ҩ������ζ���ҩ ��һ��ζ�ʲ�ҩ��";
	medicine[8].Prepare = "ˮ�ơ�";
	medicine[8].Explain = "��Ѫ�����������ң��컨�ʲݿǳ��֣����ܺ��ţϥ�ȣ�Ѫ�����в����͡���";
	medicine[8].Tag = "��Ѫ������Ѫ������������Ѫ��֢��";

	medicine[9].Name = "��Ƥ��";
	medicine[9].HerbData = { 10,2,1,1,1,2,3 };
	medicine[9].Water = 1;
	medicine[9].Fire = 1;
	medicine[9].Medicine = " �������²�ҩ��һ���Ժ���ҩ��һ����ƽ��ҩ��һ��ζ����ҩ������ζ���ҩ ������ζ�ʲ�ҩ��";
	medicine[9].Prepare = "ˮ���ơ�";
	medicine[9].Explain = "�����κ����ᣬ����������Ӳ����֮��ճ����֮���𡣡�";
	medicine[9].Tag = "��Ѫ����������Ѫֹʹ���ε������ˡ�";

	medicine[10].Name = "�̾���";
	medicine[10].HerbData = { 9,0,3,0,0,3,3 };
	medicine[10].Water = 1;
	medicine[10].Fire = 1;
	medicine[10].Medicine = " �ķ��Ժ���ҩ���ķ�ζ���ҩ ���ķ�ζ�ʲ�ҩ��";
	medicine[10].Prepare = "ˮ���ơ�";
	medicine[10].Explain = "���̾����ù������ưش�Ƥ�㸽�ˣ�������ҩ�������©�±��о���������";
	medicine[10].Tag = "��ɬ����ֹ����Ѫ�����¾����ࡣ";

	medicine[11].Name = "ǧ��������";
	medicine[11].HerbData = { 8,1,0,3,0,0,4 };
	medicine[11].Water = 1;
	medicine[11].Fire = 0;
	medicine[11].Medicine = " һ�����²�ҩ�� ������ƽ��ҩ���ķ�ζ�ʲ�ҩ ��";
	medicine[11].Prepare = "ˮ�ơ�";
	medicine[11].Explain = "��ǧ������ˮ�׷�������������Ƥ������Ƣ��������ˮ����Ѫ��̥�����ˡ���";
	medicine[11].Tag = "���������Ѫ��̥��������ˮ�ס�";

	medicine[12].Name = "������ɢ";
	medicine[12].HerbData = { 10,3,0,0,1,2,4 };
	medicine[12].Water = 1;
	medicine[12].Fire = 1;
	medicine[12].Medicine = " �������²�ҩ�� һ��ζ����ҩ������ζ���ҩ ���ķ�ζ�ʲ�ҩ��";
	medicine[12].Prepare = "ˮ���ơ�";
	medicine[12].Explain = "��������ɢ�����飬�������綦���Σ����麹���׸�ð�������̱�ֹ���񡣡�";
	medicine[12].Tag = "�����ɬ���������̱�ֹ�����α���������";

	medicine[13].Name = "������";
	medicine[13].HerbData = { 10,4,0,2,3,0,1 };
	medicine[13].Water = 1;
	medicine[13].Fire = 1;
	medicine[13].Medicine = " �ķ����²�ҩ�� ������ƽ��ҩ������ζ����ҩ�� һ��ζ�ʲ�ҩ��";
	medicine[13].Prepare = "ˮ���ơ�";
	medicine[13].Explain = "���������ð��ĳ£��������߸ʲݳɣ��������м���ʪ��һ��̵���˷��䡣��";
	medicine[13].Tag = "��̵������ʪ��̵����ʪ̵֢��";

	medicine[14].Name = "������̵��";
	medicine[14].HerbData = { 7,2,1,0,1,2,1 };
	medicine[14].Water = 0;
	medicine[14].Fire = 1;
	medicine[14].Medicine = " �������²�ҩ��һ���Ժ���ҩ��һ��ζ����ҩ������ζ���ҩ ��һ��ζ�ʲ�ҩ��";
	medicine[14].Prepare = "���ơ�";
	medicine[14].Explain = "����ĸ����ɢ���ߣ���Ƥ�۹��������������ʸ�̵�ѿ������ﻯ̵�����塣��";
	medicine[14].Tag = "��̵��������ֹ�ȣ���̵�ȿ��ԡ�";

	medicine[15].Name = "������";
	medicine[15].HerbData = { 8,2,2,0,0,2,2 };
	medicine[15].Water = 1;
	medicine[15].Fire = 0;
	medicine[15].Medicine = " �������²�ҩ�������Ժ���ҩ������ζ���ҩ ������ζ�ʲ�ҩ��";
	medicine[15].Prepare = "ˮ�ơ�";
	medicine[15].Explain = "������ʵ���ƽ����������Գ�ˮʪ���·�����������Ὺ��Ӳ���ӡ���";
	medicine[15].Tag = "��ʳ������Ƣ��ˮ��������������";

	medicine[16].Name = "޽������ɢ";
	medicine[16].HerbData = { 10,3,0,1,4,1,1 };
	medicine[16].Water = 1;
	medicine[16].Fire = 1;
	medicine[16].Medicine = " �������²�ҩ��һ����ƽ��ҩ���ķ�ζ����ҩ��һ��ζ���ҩ ��һ��ζ�ʲ�ҩ��";
	medicine[16].Prepare = "ˮ���ơ�";
	medicine[16].Explain = "��޽���������գ��ʽ۳������Ӿ㣬�������Ƽӽ��棬������β���������";
	medicine[16].Tag = "��ʪ�����������У��η纮ʪ�͡�";

	medicine[17].Name = "�ϵ�ɢ";
	medicine[17].HerbData = { 4,0,1,1,0,1,1 };
	medicine[17].Water = 1;
	medicine[17].Fire = 0;
	medicine[17].Medicine = " һ���Ժ���ҩ��һ����ƽ��ҩ��һ��ζ���ҩ ��һ��ζ�ʲ�ҩ��";
	medicine[17].Prepare = "ˮ�ơ�";
	medicine[17].Explain = "���ϵ�ɢ�г�С��������֭�����գ���аӿ�¹���ݣ�����̵ʳ��֮񬡣��";
	medicine[17].Tag = "ӿ�¼���ӿ��̵����ʳ����̵����ʳ��";

	medicine[18].Name = "�ȼ�ϡ��ɢ";
	medicine[18].HerbData = { 10,5,1,0,4,0,0 };
	medicine[18].Water = 1;
	medicine[18].Fire = 0;
	medicine[18].Medicine = " ������²�ҩ��һ���Ժ���ҩ���ķ�ζ����ҩ��";
	medicine[18].Prepare = "ˮ�ơ�";
	medicine[18].Explain = "��ϡ�������׷������ȿ�������̵���з��������֤�����ܿ�����ͨ�ء���";
	medicine[18].Tag = "���ϼ��������������з粻ʡ���¡�";

	medicine[19].Name = "��Ƹ�����";
	medicine[19].HerbData = { 10,1,2,0,3,0,4 };
	medicine[19].Water = 1;
	medicine[19].Fire = 0;
	medicine[19].Medicine = " һ�����²�ҩ�������Ժ���ҩ������ζ����ҩ���ķ�ζ�ʲ�ҩ��";
	medicine[19].Prepare = "ˮ�ơ�";
	medicine[19].Explain = "�����Ѵ�Ƹ�������ϸ��ɢ��ֹʹ��������ڽ��ʵ֤����ר������ǳ�����";
	medicine[19].Tag = "к�¼���ͨ��ֹʹ���θ�ʹ���ء�";

	medicine[20].Name = "������";
	medicine[20].HerbData = { 9,3,0,1,2,0,3 };
	medicine[20].Water = 0;
	medicine[20].Fire = 1;
	medicine[20].Medicine = " �������²�ҩ��һ����ƽ��ҩ������ζ����ҩ������ζ�ʲ�ҩ��";
	medicine[20].Prepare = "���ơ�";
	medicine[20].Explain = "������������ɽ髣����������߰��ģ�����Ϊ������£���ʳ��θЧ���䡣��";
	medicine[20].Tag = "��ʳ������θ���ͣ���ʳ��θ�䡣";

	medicine[21].Name = "������";
	medicine[21].HerbData = { 10,5,0,0,3,1,1 };
	medicine[21].Water = 1;
	medicine[21].Fire = 1;
	medicine[21].Medicine = " ������²�ҩ������ζ����ҩ��һ��ζ���ҩ ��һ��ζ�ʲ�ҩ��";
	medicine[21].Prepare = "ˮ����ơ�";
	medicine[21].Explain = "�������֬�����ǣ���ޢ������ζ�ߣ���������ͬ��ϣ������й�����ˡ���";
	medicine[21].Tag = "��ɬ������Ƣů������Ƣ������֮��к��";

	medicine[22].Name = "��ɰ������";
	medicine[22].HerbData = { 10,1,2,1,1,2,3 };
	medicine[22].Water = 1;
	medicine[22].Fire = 1;
	medicine[22].Medicine = " һ�����²�ҩ�������Ժ���ҩ��һ����ƽ��ҩ��һ��ζ����ҩ������ζ���ҩ ������ζ�ʲ�ҩ��";
	medicine[22].Prepare = "ˮ����ơ�";
	medicine[22].Explain = "����ɰ����ԫ���������ʲݺϵػƣ����粻���ķ��ң��������ȿɸ�������";
	medicine[22].Tag = "����������İ�����ʧ�߶��Ρ�";

	medicine[23].Name = "��������";
	medicine[23].HerbData = { 10,1,1,3,1,1,3 };
	medicine[23].Water = 1;
	medicine[23].Fire = 1;
	medicine[23].Medicine = " һ�����²�ҩ��һ���Ժ���ҩ��������ƽ��ҩ��һ��ζ����ҩ��һ��ζ���ҩ ������ζ�ʲ�ҩ��";
	medicine[23].Prepare = "ˮ����ơ�";
	medicine[23].Explain = "������������ʧ�ߣ���֪ܺ�����߼壬��Ѫ���������ȣ���Ȼ��˯�����𡣡�";
	medicine[23].Tag = "���������Ѫ�������Ѫ��ʧ�ߡ�";

	medicine[24].Name = "ƽθɢ";
	medicine[24].HerbData = { 9,3,0,0,3,3,0 };
	medicine[24].Water = 1;
	medicine[24].Fire = 1;
	medicine[24].Medicine = " �������²�ҩ������ζ����ҩ������ζ���ҩ ��";
	medicine[24].Prepare = "ˮ����ơ�";
	medicine[24].Explain = "��ƽθɢ�ھ����������ӳ²ݽ�������ʪ��Ƣ�ֺ�θ��ʪ��Ƣθ����������";
	medicine[24].Tag = "��ʪ������ʪ��Ƣ����ʪ��Ƣθ��";

	medicine[25].Name = "��÷��";
	medicine[25].HerbData = { 10,1,1,1,3,3,1 };
	medicine[25].Water = 0;
	medicine[25].Fire = 1;
	medicine[25].Medicine = "һ�����²�ҩ��һ���Ժ���ҩ��һ����ƽ��ҩ������ζ����ҩ������ζ���ҩ ������ζ�ʲ�ҩ��";
	medicine[25].Prepare = "���ơ�";
	medicine[25].Explain = "����÷����ϸ���𣬻����ưؼ����飬�˲ν��������ӣ�����Ԣ���ڰ��ס���";
	medicine[25].Tag = "�����������ֹʹ���λ׳档";

	medicine[26].Name = "��ζ�ػ���";
	medicine[26].HerbData = { 7,1,0,2,0,0,4 };
	medicine[26].Water = 0;
	medicine[26].Fire = 1;
	medicine[26].Medicine = " һ�����²�ҩ��������ƽ��ҩ���ķ�ζ�ʲ�ҩ��";
	medicine[26].Prepare = "���ơ�";
	medicine[26].Explain = "���غ�ɫ���ں�ɫ�Ĵ����裬ζ����ᡣ��";
	medicine[26].Tag = "��������θ�Ƣ���������飬���ס�";

	medicine[27].Name = "�Һ˳�����";
	medicine[27].HerbData = { 10,0,2,2,0,3,3 };
	medicine[27].Water = 1;
	medicine[27].Fire = 1;
	medicine[27].Medicine = " �����Ժ���ҩ��������ƽ��ҩ������ζ���ҩ������ζ�ʲ�ҩ��";
	medicine[27].Prepare = "ˮ���ơ�";
	medicine[27].Explain = "���Һ˳������ʩ���ʲ����Ʋ���֦�����Ȼ���С���ͣ���Ѫ��������ˡ���";
	medicine[27].Tag = "��������θ�Ƣ���������顣";

	medicine[28].Name = "����ɢ";
	medicine[28].HerbData = { 10,3,0,0,3,2,2 };
	medicine[28].Water = 1;
	medicine[28].Fire = 1;
	medicine[28].Medicine = " �������²�ҩ������ζ����ҩ������ζ���ҩ������ζ�ʲ�ҩ��";
	medicine[28].Prepare = "ˮ���ơ�";
	medicine[28].Explain = "������ɢ�����˷磬���ؽ������Ź�������׸�Ǽ���ƣ�����ڷ�һ��ͨ����";
	medicine[28].Tag = "���ҩ����绯̵�������˷硣";

	medicine[29].Name = "������";
	medicine[29].HerbData = { 10,4,0,1,2,1,2 };
	medicine[29].Water = 1;
	medicine[29].Fire = 1;
	medicine[29].Medicine = "�ķ����²�ҩ��һ��ζƽ��ҩ������ζ����ҩ��һ��ζ���ҩ������ζ�ʲ�ҩ��";
	medicine[29].Prepare = "ˮ���ơ�";
	medicine[29].Explain = "��������׳���������������ָ�������������ʹ��ˮ������ѣ�p(sh��n)��(t��)����������";
	medicine[29].Tag = "��ʪҩ��������ˮ���η��Ĳ���";

	medicine[30].Name = "��ܺ���ɢ";
	medicine[30].HerbData = { 8,3,0,0,4,0,1 };
	medicine[30].Water = 1;
	medicine[30].Fire = 0;
	medicine[30].Medicine = " �������²�ҩ��һ��ζƽ��ҩ���ķ�ζ����ҩ��һ��ζ���ҩ��һ��ζ�ʲ�ҩ��";
	medicine[30].Prepare = "ˮ�ơ�";
	medicine[30].Explain = "����ܺ����о��������Ʊ��ɸʲ�Ǽ��Ŀ������繥�ϣ�ƫ��ͷʹϤ�ܿ�����";
	medicine[30].Tag = "���ҩ�����ֹʹ������ƫͷʹ��";

	medicine[31].Name = "��٢";
	medicine[31].HerbData = { 0,0,0,0,0,0,0 };
	medicine[31].Water = 0;
	medicine[31].Fire = 0;
	medicine[31].Medicine = "";
	medicine[31].Prepare = "";
	medicine[31].Explain = "������ʱ�ڵ���ҽ�����š�����";
	medicine[31].Tag = "��ҽ����������֢��";

	medicine[32].Name = "����ˮ";
	medicine[32].HerbData = { 0,0,0,0,0,0,0 };
	medicine[32].Water = 0;
	medicine[32].Fire = 0;
	medicine[32].Medicine = "";
	medicine[32].Prepare = "";
	medicine[32].Explain = "����ͨ��Ʒ���������������á����˵��˶�˵�á���";
	medicine[32].Tag = "����Ʒ������Ѫ������Ѫ���㡣";

	medicine[33].Name = "�ϳ���";
	medicine[33].HerbData = { 0,0,0,0,0,0,0 };
	medicine[33].Water = 0;
	medicine[33].Fire = 0;
	medicine[33].Medicine = "";
	medicine[33].Prepare = "";
	medicine[33].Explain = "��һ���ж�ֲ��ļ�ơ����ֹʹ���ڷ��綾����Ϊҽ�ߣ���;���ȡ�����ġ���";
	medicine[33].Tag = "���ҩ����ҩ��ɢ�����ף�ֹʹ��";
}

int PlayerMedicineData::Match(vector<int> HerbData, bool Water, bool Fire)
{
	int p = 0;
	for (int i = 1; i <= 33; i++)
	{
		if (HerbData == medicine[i].HerbData && Water == medicine[i].Water && Fire == medicine[i].Fire) 
		{
			p = i;
			break;
		}
	}

	return p;
}






