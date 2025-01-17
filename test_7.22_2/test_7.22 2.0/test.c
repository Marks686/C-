#define _CRT_SECURE_NO_WARNINGS
文章目录
一、指针运算
1.指针 + -整数
2.指针 - 指针
3.指针的关系运算
一、指针运算
1.指针±整数
#define N_VALUES 5
float values[N_VALUES];
float* vp;
//指针+-整数；指针的关系运算
for (vp = &values[0]; vp < &values[N_VALUES];)
{
	*vp++ = 0;
}
1
2
3
4
5
6
7
8
分析代码：

结合下图分析， define N_VALUES 5实质是就是定义 N_VALUES这个符号的值就是5，float values[N_VALUES]，大家注意其实这个地方就是定义values这个数组是五个元素且没有初始化，然后float * vp，vp也没有初始化，此时此刻vp就是野指针了，但是我们暂时还没解引用它，危险还没有发生，紧接着往下看，vp初始化了，将values[0]的地址赋值给vp，vp有指向了，此时此刻vp不再是野指针了，初始化完后判断 vp < &values[N_VALUES]即vp小于values下标为5这个元素的地址，我们知道数组的地址是由低到高变化的，所以我们知道vp的地址一定是小于values[N_VALUES]的地址的，这里两个指针比较大小，叫做指针的关系运算， vp < &values[N_VALUES]的话就进入循环，* vp++ = 0，++优先级高，但是他是后置的先使用再++，所以vp++这个表达式的值本身是vp的值，所以解引用vp的时候，还是指向原位置的，将0放进去，然后++的效果产生，vp++，它指向它的下一个位置去了（用红笔表示它指向的下一个位置），不断++，不断去往下一个位置，当vp走到蓝色笔所指向的位置时，大家注意vp小于values[N_VALUES]的地址，已经不成立了，所以结束循环。这一块不仅用到了指针±整数运算还用到了关系运算。


	应用：

	将数组元素初始化1：

	//数组下标的写法：
	int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		arr[i] = 1;
	}
	return 0;
}
1
2
3
4
5
6
7
8
9
10
11
12
//指针的写法1：
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	for (i = 0; i < sz; i++)
	{
		*p = 1;
		p++;
	}
	return 0;
}
//指针的写法2：
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	for (i = 0; i < sz; i++)
	{
		*(p + i) = 1;
	}
	return 0;
}

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
2.指针 - 指针
int main()
{
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);
	return 0;
}
1
2
3
4
5
6

程序一走，发现得到的结果是9，那么9是如何得来的呢？
取出下标为0和9的地址，这两个地址之间有9个元素，36个字节，实质上呢，指针 - 指针得到的是指针和指针之间元素的个数。那反过来我们用下标为0的元素减去下标为9的元素，这个时候我们发现结果是 - 9，那就可以这样理解： | 指针 - 指针 | 得到的是指针和指针之间元素的个数。


不是所有的指针都能够相减的，指向同一块空间的两个指针才能相见，这样才有意义。下面的指针相减就没有意义

int main()
{
	int arr[10] = { 0 };
	char ch[5] = { 0 };
	printf("%d\n", &ch[0] - &arr[5]);
	return 0;
}
1
2
3
4
5
6
7
这种写法没道理也没意义，本质上是错误的。

应用：

求字符串长度，我们之前是使用库函数

#include<string.h>
int main()
{
	int len = strlen("abcdef");
	printf("%d\n", len);
	return 0;
}
1
2
3
4
5
6
7

那如果我们自己实现一个求字符产长度的函数呢？

//版本1：
int my_strlen(char* str)//找\0
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	int len = my_strlen("abcdef");//a b c d e f \0
	printf("%d\n", len);
	return 0;
}

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
//版本2：指针-指针
//其实你要知道\0的地址和起始位置的地址，相减就可以了
int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}
int main()
{
	int len = my_strlen("abcdef");//a b c d e f \0
	printf("%d\n", len);
	return 0;
}

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17

那指针 + 指针的运算能不能运算呢？
想象一下指针 + 指针就是地址 + 地址，有什么意义呢？其实没什么太大意义，生活中也有相似的例子，比如：
日期
日期 + 天数有意义，日期 - 天数有意义，日期 - 日期有意义，那么日期加日期是不是就感觉很奇怪了，所以地址 + 地址是没有什么意义的。

3.指针的关系运算
指针的关系运算其实就是比较大小。

#define N_VALUES 5
int main()
{
	float values[N_VALUES];
	float* vp;
	for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0;
	}
	return 0;
}
1
2
3
4
5
6
7
8
9
10
11
分析：

我们可以简化代码：

#define N_VALUES 5
int main()
{
	float values[N_VALUES];
	float* vp;
	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
	{
		*vp = 0;
	}
	return 0;
}
1
2
3
4
5
6
7
8
9
10
11
先给vp赋值N_VALUES - 1，下标就为4 ，大于等于下标为0的元素，然后改成0，改完后vp–，直到vp指向valuse[0]的地址，把所有元素都改成0了，再–，就指向下标为0的前面有个一个元素，这个时候循环就结束了。

这样简化后的代码实际在绝大部分编译器上是可以顺利完成任务的，然而我们还是应该避免这样写，因为标准并不保证它可行。
标准规定：
允许指向数组元素的指针与指针向数组最后一给元素后面的内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较

假设红色框框是arr数组，相对于arr数组来说p2指针和p3指针都是越界了 ，p2向后越界，p3向前越界，标准规定说允许p1和p2比，但是不允许p1和p3比。实际理论上讲是没什么区别的，但是标准是那样规定的。

————————————————
版权声明：本文为CSDN博主「这代码还能再酷一点吗」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https ://blog.csdn.net/m0_68800221/article/details/125344447