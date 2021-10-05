#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

struct stu
{
	int age;
	char name[20];
};

void Exchange(char* x, char* y, size_t width)
{
	while (width)
	{
		char temp = *x;
		*x = *y;
		*y = temp;
		x++;
		y++;
		width--;
	}
}

int compare(const void* e1, const void* e2)
{
	//return *(int*)e1 - *(int*)e2;        //排整形数据
	//return *(float*)e1 - *(float*)e2;    //排浮点数数据
	//return *(char*)e1 - *(char*)e2;        //排字符串
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);  //排结构体数组 - 名字排序
	//return ((struct stu*)e1)->age - ((struct stu*)e2)->age;             //排结构体数组 - 年龄排序
}

my_qsort(void* base, size_t num, size_t width, int (*compare)(void*, void*))
{
	size_t i = 0;
	for (i = 0; i < num - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare((char*)base + (j * width), (char*)base + ((j + 1) * width)) > 0)
			{
				//交换两个数
				Exchange((char*)base + (j * width), (char*)base + ((j + 1) * width), width);
			}
		}
	}
}

int main()
{
	//int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	//my_qsort(arr, 10, sizeof(arr[0]), compare);
	
	//float arr[] = { 10.0,9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
	//my_qsort(arr, 10, sizeof(arr[0]), compare);
	
	//char arr[] = "nmlkjihgfedcba";
	//my_qsort(arr, 14, sizeof(arr[0]), compare);
	//printf("%s", arr);
	
	struct stu arr[] = { {20,"张三"},{15,"李四"},{10,"王五"} };
	my_qsort(arr, 3, sizeof(arr[0]), compare);
	printf("%d %s\n%d %s\n%d %s\n", arr[0].age, arr[0].name, arr[1].age, arr[1].name, arr[2].age, arr[2].name);

	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d  ", arr[i]);
	//}
	return 0;
}


