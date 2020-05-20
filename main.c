#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    char parameter[5];
    char input_file_name[50];
    int num=0;
    printf("输入操作类型: ");
    gets(parameter);
    printf("输入属一个文件名: ");
    gets(input_file_name);
    if((fp=fopen(input_file_name,"r"))==NULL)
    {
        printf("文件打开失败..\n");
        return ;
    }
    if(parameter[1]=='c')  //统计字符数
    {
        while(!feof(fp))
            fgetc(fp)&&num++;
        printf("%s 文件中共有字符个数: %d\n",input_file_name,num-1);
        fclose(fp);
    }
    if(parameter[1]=='w')  //统计单词数
    {
        char buf[1000];
        int num1=0;
        int num2=0;
        for(int i=0;!feof(fp);i++)
        {
            buf[i]=fgetc(fp);
            num1++;
        }
        num1--;
        if(num1>0)
                num2++;
        for(int i = 0;i<num1;i++)
        {
            if((buf[i]==' '||buf[i]==',')&&((buf[i-1]>='A'&&buf[i-1]<='Z')||(buf[i-1]>='a'&&buf[i-1]<='z')))
                num2++;
        }
        printf("%s 文件中共有单词个数: %d\n",input_file_name,num2);
    }
    return ;
}
