#ifndef _TINY_PINYIN_H_
#define _TINY_PINYIN_H_

typedef struct
{
	const char *PYList;  	//ƴ�������ַ���
	int			num;		//�ܺ�����
	const char *HZGB;		//���������ƴ����ϵĺ���GB���ָ��
}PinYinDef;


//ƴ����ϵĺ����ֿ�
//ƴ�������Ľṹ��
struct PinYinPCB
{
	char *PYSerList;  		//ƴ�������ַ�
	const unsigned char *PYRankOneList;  	//���������ƴ����ϵĺ����ֿ��ָ��
};

char *PYSearch(unsigned char *msg , int *num);

#endif //_TINY_PINYIN_H_
