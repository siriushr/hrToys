#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define KEY 222220 // 解密密码 
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

// 文件解密 
void decrypt(char toBeDecFileName[], int key) 
{ 
	char newFileName[FILE_NAME_MAX_SIZE] = {'i', 'j', 'k'}; 

	strcat(newFileName, toBeDecFileName); 
	FILE *fp1 = fopen(toBeDecFileName, "rb"); 
	FILE *fp2 = fopen(newFileName, "wb"); 

	int i, s, t, size = getFileSize(toBeDecFileName); 

	for(i = 0; i < size; i++) { 
		s = getc(fp1); 
		t = genFun(size, key, i) ^ s; 

		// 解密 
		putc(t, fp2); 
	} 

	fclose(fp1); 
	fclose(fp2); 
} 

int main() 
{ 
	printf("这是一个文件解密软件!\n"); 
	printf("请输入密码："); 

	int key; 
	scanf("%d", &key); 

	if(KEY != key) { 
		printf("密码错误!\n"); 
		exit(1); 
	} 

	printf("请输入文件的文件名(包括后缀):"); 

	char fileName[FILE_NAME_MAX_SIZE]; 
	scanf("%s", fileName); 

	decrypt(fileName, key); 
	printf("解密完成！\n"); 

	return 0; 
}
