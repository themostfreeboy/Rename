#include <stdio.h>
#include <stdlib.h>

void print_help()
{
	FILE *fp;
	errno_t err;
	err=fopen_s(&fp,"此程序使用说明.txt","w");
	if(err!=0)
	{
		printf("\"此程序使用说明.txt\"打印失败\n");
		return;
	}
	fprintf(fp,"此程序使用说明：\n此程序为批量修改文件名的程序，请将需要修改文件名的规则写入到与本程序在同一目录下的\"data.txt\"文件中，如果没有，请自行创建，文件内每行为待修改的文件，格式如下：\n123.txt 456.txt\n上面即代表将\"123.txt\"修改为\"456.txt\"，每行为一条待修改的文件名，每行中的文件名必须带有文件格式后缀。\n此程序必须和待修改的文件在同一目录下。\n为了避免出问题，请在使用本程序前将原始文件先自行复制到其他地方做一下备份，以免出错。\nMade By JXL\n");
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
		printf("\"data.txt\"不存在或打开失败\n此程序的详细使用说明请参考\"此程序使用说明.txt\"\nMade By JXL\n");
		system("pause");
		return 0;
	}
	printf("正在修改中......\n");
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
	printf("全部修改完成\nMade By JXL\n");
	system("pause");
	return 0;
}