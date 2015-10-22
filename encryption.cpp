#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define KEY 729520 // 加密密码 
#define FILE_NAME_MAX_SIZE 100 // 文件名长度

// 变换法则 
int genFun(int size, int key, int i) 
{ 
	return size + key + i - size / key; 
} 

// 获得文件大小 
int getFileSize(char str[]) 
{
	FILE *fp = fopen(str, "rb"); 
	fseek( fp, 0, SEEK_END ); 
	int size = ftell(fp); 
	fclose(fp); 
	return size; 
} 

// 文件加密 
void encrypt(char toBeEncFileName[], int key) 
{ 
	char newFileName[FILE_NAME_MAX_SIZE] = {'i', 'j', 'k'}; 

	strcat(newFileName, toBeEncFileName); 
	FILE *fp1 = fopen(toBeEncFileName, "rb"); 
	FILE *fp2 = fopen(newFileName, "wb"); 

	int i, s, t, size = getFileSize(toBeEncFileName); 

	for(i = 0; i < size; i++) { 
		s = getc(fp1); 
		t = genFun(size, key, i) ^ s; 

		// 加密 
		putc(t, fp2); 
	} 
	fclose(fp1); 
	fclose(fp2); 
} 

int main() 
{ 
	printf("这是一个文件加密软件!\n"); 
	printf("请输入您的加密身份认证："); 

	int key; 
	scanf("%d", &key); 

	if(KEY != key) { 
		printf("身份认证错误!\n"); 
		exit(1); 
	} 

	printf("请输入文件的文件名(包括后缀):"); 

	char fileName[FILE_NAME_MAX_SIZE]; 
	scanf("%s", fileName); 

	encrypt(fileName, KEY); 
	printf("加密完成!\n"); 

	return 0; 
}