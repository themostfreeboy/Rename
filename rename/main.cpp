#include <stdio.h>
#include <stdlib.h>

void print_help()
{
	FILE *fp;
	errno_t err;
	err=fopen_s(&fp,"�˳���ʹ��˵��.txt","w");
	if(err!=0)
	{
		printf("\"�˳���ʹ��˵��.txt\"��ӡʧ��\n");
		return;
	}
	fprintf(fp,"�˳���ʹ��˵����\n�˳���Ϊ�����޸��ļ����ĳ����뽫��Ҫ�޸��ļ����Ĺ���д�뵽�뱾������ͬһĿ¼�µ�\"data.txt\"�ļ��У����û�У������д������ļ���ÿ��Ϊ���޸ĵ��ļ�����ʽ���£�\n123.txt 456.txt\n���漴����\"123.txt\"�޸�Ϊ\"456.txt\"��ÿ��Ϊһ�����޸ĵ��ļ�����ÿ���е��ļ�����������ļ���ʽ��׺��\n�˳������ʹ��޸ĵ��ļ���ͬһĿ¼�¡�\nΪ�˱�������⣬����ʹ�ñ�����ǰ��ԭʼ�ļ������и��Ƶ������ط���һ�±��ݣ��������\nMade By JXL\n");
	fclose(fp);
	return;
}

int main()
{
	print_help();
	FILE *fp;
	errno_t err;
	err=fopen_s(&fp,"data.txt","r");
	if(err!=0)
	{
		printf("\"data.txt\"�����ڻ��ʧ��\n�˳������ϸʹ��˵����ο�\"�˳���ʹ��˵��.txt\"\nMade By JXL\n");
		system("pause");
		return 0;
	}
	printf("�����޸���......\n");
	char name1[255];
	char name2[255];
	while(fscanf_s(fp,"%s",name1,255)!=EOF)
	{
		fscanf_s(fp,"%s",name2,255);
		char cmd[255];
		sprintf_s(cmd,"rename %s %s",name1,name2,255);
		system(cmd);
	}
	fclose(fp);
	printf("ȫ���޸����\nMade By JXL\n");
	system("pause");
	return 0;
}