һ��
whole�ļ��д�ŵ���ȫ�������ļ�����ԭ���������¼��������ļ���
1)entity.txt;	  	813
2)event.txt;  	  	141
3)attribute value.txt 	433
4)syntax.txt 		41
5)quantity value.txt 	13
6)secondary feature.txt 100

������attribute value.txt��quantity value.txt���Ѿ�������attribute.txt��quantity value.txt�е�����λ��ϵ��

hownet�ṩ�������ļ�����converse.txt��antonym.txt��event role && features.txt������Щ�ļ��ж��塢���塢

����
whole.dat�ļ�����whole����,ÿһ�е��������£�
	��ԭ�����  ��ԭ������	     ����ԭ�ĸ��ڵ����
e.g 	  1  	    static|��̬             0

��ĳ����ԭ�����ڸ��ڵ�ʱ���丸�ڵ���Ϊ����

����
syntax:
dealhownet.pl < inputfilename > outfilename
dealhownet.pl < whole > whole.dat
�õ���ԭ������ϵ������λ��ϵ��

semidx.pl <whole.dat > semno.dat
����semno.dat�ļ��ĸ�ʽΪ
whole.dat��ÿһ�����һ��������ԭ����
����Ϊwhole.dat��semno.datɾ������whole.dat�ļ���ʽΪ��
	��ԭ�����  ��ԭ������	     ����ԭ�ĸ��ڵ���� ������ԭ��
e.g 	  1  	    static|��̬             0		  ��̬



Ŀ����Ϊ�˵����뺺����ԭʱ��������Ҹ���ԭ�ĺ��롣

�ģ�
GetSemDict.pl < whole > semdict.dat
�õ�ÿ����ԭ�Ľ��ͣ���ʾ�˸���ԭ��������ԭ�Ĺ�ϵ��
����Ϊwhole�ļ������Ϊsemdict.dat;

semdict.dat�ļ�ÿһ��ĸ�ʽ���£�
	��ԭ���  	 ����ԭ�Ķ���
e.g	1506	  	[$consume|��ȡ]

1506���Դ�whole.dat�ļ��в鵽��ԭΪ1506  flesh|�⣻

ProcSemdict.pl�����õ���Ҫ���ļ���ʽ
perl ProcSemdict.pl < semdict.dat > semdict
semdict�ļ�ÿһ��ĸ�ʽ���£�
	��ԭ���	��������Ŀ  	 ����ԭ�Ķ���
e.g	1506	  	  1		[$consume|��ȡ]

1506���Դ�whole.dat�ļ��в鵽��ԭΪ1506  flesh|�⣻


�壩
ProcessDict.c
���ܣ� ��hownet.txt�ļ��еĴʵ��ȡ��������һ�������ļ�dict.dat��;
���ֻ���Ǻ���Ļ������ԴӴʵ���ֻ��ȡ��������
�ļ���ÿһ��Ĵ�Ÿ�ʽ���£�
	����	 �������  	����
	����       V	 	beat|��

������ں��ʡ����ա�������5������(����Ӣ�﷭��Ĳ�ͬ���������ǵõ��Ľ���ǣ�
W_C=����	G_C=V 	DEF=control|����
W_C=����	G_C=V	DEF=know|֪��

������ԣ���ȡ���д�����Ȼ��ͨ��delsame.exeɾ����ȫ��ͬ���У����Եõ���ͬ�ĺ��ʼ������干66181�У�Ϊglossary.dat

1)ProcessDict.c��������ɵĿ�ִ���ļ�a.out
a.out hownet.txt dicttmp.dat
2)delsame dicttmp.dat glossary.dat
��glossary.dat���д�����һЩ�������еĿո񻻳��»����Ա����״��������ļ�glossary.dic��
���磺the Ivory Coast|��������
��Ϊ��the_Ivory_Coast|��������

����semeset.h semeset.cpp ��������ԭ���Ͻ��в��������Եõ���λ�����Ƚ�
�㡣

����Ҫ�Ľӿڣ�
 1)�ж���ԭ֮��Ĺ�ϵ��
 	int SemeSet::IsAncestor(seme1,seme2);
	���룺��������ԭ
	�����һ������
	   ���Ϊ0,����ԭ֮�䲻��������λ��ϵ��
	   ���Ϊ����+n,��seme1Ϊseme2��n�����ȣ�
	   ���Ϊ����-n,��seme2Ϊseme1��n�����ȣ�	   
 2)�Ӵʵ��еõ��ʵĸ��ֹ�ϵ
 	int Word_Relation(char *word, Set *rels)
 	
��ִ�г���semeset
  ���룺wordpair.inf
  �����wp_rel.inf
  ���ܣ�����������ƶȣ������ļ���ÿһ�������ʣ�����ļ��и���ÿһ���������ʵ����ƶȣ�������
  

�ߣ�GetStatistics.pl�����õ�ͳ�����ݣ�ÿһ�����ʵ�DEFƽ���м��������
syntax:
perl GetStatistics.pl < dictnew.dat > statisdata

ÿһ�����ʵ�ƽ�������ϵ����ĿΪ 2.328221����
ÿһ����ԭ��ƽ�������ϵ����ĿΪ 0.358858����

�ˣ�Sem_WordIdx.pl (û����
����Ϊ����������ÿһ����ԭ��Ӧ��Щ�ʣ��γ�һ���������飬
sem1->{wd1,wd2}