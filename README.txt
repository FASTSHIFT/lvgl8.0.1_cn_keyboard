�����ڵ�Ƭ����lvgl�����ļ���ƴ�����뷨��ʹ��QT5.14������ֱ�Ӵ򿪼�������ģ����

GUI: lvgl8.0.1
1. ����
�����ڵ�Ƭ��������ƴ�����뷨������һ��ƴ������ļ��̣�����ƴ�����룬����ʾƴ����Ӧ�ĺ�ѡ�֣�ͨ���������ѡ��Ŀ���ѡ���֣�guiƽ̨��lvgl8.0.1��

2. ԭ��
��lvglԭ�ļ�"lv_keyboard.c"�����Ͻ��м��̵ĸ�д�����ļ���Ϊ"lv_cn_keyboard.c"����ͬ�����"lvgl\src\extra\widgets\keyboard\"Ŀ¼�£���صĶ��⺯��������"lv_cn_xxx"��ͷ��
�紴��һ������ƴ�����뷨�ĺ�������Ϊ
lv_obj_t * lv_cn_keyboard_create(lv_obj_t * parent, const lv_font_t *cn_font)��
ԭ�ٷ��ļ�"lv_keyboard.c"�뱾��������"lv_cn_keyboard.c"�ɸ���ʵ���������ѡ��ʹ�ã�����ƴ�����뷨lv_cn_keyboard.c�Ѿ������˹ٷ�lv_keyboard.c���̵����й��ܡ�

3. �漰�ļ�˵��
(1) lvgl\src\extra\widgets\keyboard\lv_cn_keyboard.c������ƴ�����뷨���̿ؼ�Դ�ļ����ɴ���һ������ƴ�����뷨���̿ؼ�
(2) user\tiny_pinyin.c���򵥵�ƴ�����뷨����Դ������
(3) myfont\my_cn_font1.c ���������ɹ��� Lvgl Font Tool V0.4 ���������ֿ�
(4) lvgl\examples\widgets\keyboard\lv_example_keyboard_1.c��ʹ������ƴ�����뷨���̵ļ�Ӧ������

4. ʹ��˵��

ʾ����
(1) ��������
	static lv_obj_t *kb = NULL;
	lv_obj_t * ta;
	
	/*����һ��textarea�����ռ�������*/
	ta = lv_textarea_create(lv_scr_act());				
	....
	
	if(NULL == kb){
		/*ʹ��lv_cn_keyboard_create�������̣�ע����lv_cn_ǰ׺���ڶ�����my_cn_font1���ֿ�*/
		kb = lv_cn_keyboard_create(lv_scr_act(), &my_cn_font1);	
		
		/*����ѡ��ʹ��lv_cn_keyboard_set_kb_type���ü������ͣ���������0ʱΪӢ�ļ��̣�����1ʱΪ���ļ���*/
		//lv_cn_keyboard_set_kb_type(0);  
	}
	if(NULL != kb){
		/*ʹ��lv_cn_keyboard_set_textarea��������textarea�󶨣�ע����lv_cn_ǰ׺*/
		lv_cn_keyboard_set_textarea(kb, ta);			
	}

(2) ɾ������
	�����������󣬿�ɾ���������ͷ���Դ
	lv_obj_del(kb);                 //ɾ������,�Ա��ͷż�����Դ
    kb = NULL;

(3) ע������
	a. ��ƴ�����뷨����lv_keyboard.c�������޸ģ���غ����޸�Ϊlv_cn_ǰ׺�������ϵġ�En/Cn���������л�Ӣ�Ļ��������뷨
	b. lv_cn_keyboard_create������ԭlv_keyboard_create�����������һ�����������
	lv_obj_t * lv_cn_keyboard_create(lv_obj_t * parent, const lv_font_t *cn_font)
	�����ĵڶ�������const lv_font_t *cn_font�������ֿ⣬��ͨ��lvgl�����̳�����������ֱ�������������ɹ��� Lvgl Font Tool V0.4 ����
	c. ��ƴ�����뷨������һ��ʵ�����У���ʱ��֧�ֶ��ʵ�����С�
	
5. �йز���
tiny_pinyin.cֻ��һ���򵥡���Դռ�м��͡�������ƴ�����뷨�����ܽ��е��ֵĺ�ѡ��δ�ж��������ѡ����