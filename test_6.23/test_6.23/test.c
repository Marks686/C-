#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;//*˵��pc��ָ�� char��������pcָ��Ķ���ch����������char����
//	//�����char*�����һ��pcָ�����
//	*pc = 'b';//pc�ҵ�ch���ı���
//
//	printf("%c\n", ch);
//	return 0;
//}
//int main()
//{
//	const char* p = "abcdef";
//	*p = 'w';
//	printf("%s\n", p);
//	return 0;
//}
//int main()
//{
//    const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	if (p1 == p2)
//		printf("p1==p2\n");
//	else
//		printf("p1 != p2");
//	if (arr1 == arr2)
//		printf("arr1 == arr2");
//	else
//		printf("arr1 != arr2");
//
//	return 0;
//}
//����Ŀ¼
//һ���ַ�ָ��
//�ڳ���ָ���������Ѿ������Ѿ�ѧϰ��ָ�룬�ڳ���ָ��Ļ����������������ھ�һЩָ���֪ʶ�����ַ�ָ�롢����ָ�롢ָ�����顢���鴫�κ�ָ�봫�Ρ�����ָ�롢����ָ�����顢ָ����ָ�������ָ�롢�ص�������ָ���������������Ľ�����
//
//ָ��ĸ��
//
//1.ָ����Ǹ�������������ŵ�ַ����ַΨһ��ʶһ���ڴ�ռ䡣
//2.ָ��Ĵ�С�ǹ̶���4 / 8���ֽڣ�32λƽ̨ / 64λƽ̨��
//3.ָ���������ͣ�ָ������;�����ָ��ġ������Ĳ�����ָ������ò�����ʱ���Ȩ�ޡ�
//4.ָ������㡭
//���Ǽ���̽��ָ��ĸ߼����⡣
//
//һ���ַ�ָ��
//�ַ�ָ�룺char *
//
//��c�����������ֳ�������д��ʽ��
//��һ�֣�
//
//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	//*˵��pc��ָ�� char��������pcָ��Ķ���ch����������char����
//	//�����char*�����һ��pcָ�����
//	*pc = 'b';//pc�ҵ�ch���ı���
//
//	printf("%c\n", ch);
//	return 0;
//}
//�ַ�ָ����Դ��һ���ַ��ĵ�ַ
//�ڶ��֣�
//
//int main()
//{
//	char* p = "abcdef";
//	printf("%s\n", p);
//	return 0;
//}
//���������ͼƬ����
//���Ƿ��ִ�ӡ�Ľ����abcdef��һ���ַ�������ô����ط�p����ŵ��ǲ��Ǿ����ַ�����
//�𰸣����ǡ�
//���������ͼƬ����
//
//int a = 10��
//int b = a + 2��
//a+2��ֵ����b��a+2�Ǳ���ʽ ����ʽ�ĸ�ֵ��b
//����ʽ��ֵ���Ժ��������ԣ�
//a+2��ֵ���Ծ���12��
//��Ϊa��int���ͣ�2Ҳ��int���ͣ�����a+2������������int��
/*�����ǿ���abcdef�ַ�����Ϊ����ʽһ���֣����ַ���abcdef����p��ʱ�򣬰ѡ�abcdef������һ������ʽ���������ʽ����p�������ַ�a�ĵ�ַ����Ҫ��abcdef�ŵ�p����ȥ�ǷŲ��µģ�abcdef�Ѿ�6���ַ��ˣ��ټ��Ϻ��滹���ص�\0������ŵ�p����ȥ��p�п�����
4���ֽڣ�1���ַ���Ҫ1���ֽڵĿռ䣬4���ֽ��ǷŲ���7���ַ��ģ����Ծ��Բ������ǰ�abcdef�ŵ�p����ȥ������д���ǰ��ַ������ַ�a �ĵ�ַ��ֵ��p����Ϊp����ŵ���a�ĵ�ַ����ӡ�ַ�����ʱ����� % s��ӡ�ַ�����ֻ��Ҫ���ߴ��Ŀ�ʼ�Ϳ����ˣ�p��ŵ���a�ĵ�ַ������֪����a���������ӡ��ֱ������\0��

int main()
{
	char* p = "abcdef";
	*p = 'w';
	printf("%s\n", p);
	return 0;
}
�����������ڱ������ϱ����棬��ʵ�ǰ�a�ĵ�ַ�ŵ�p���ǲ���ȫ�ģ�abcdef�Ǹ������ַ�������˼���������ܱ��ģ��Ұ���ʼ��ַ�ŵ�p��ȥ�����pȨ�޾ͱ���ˣ�pû�б����Σ�Ҳ����p��ȥ��abcdef�����ݣ������Ҫǿ�иģ�����ͻ���������Ա�������ʵ�Ǻ�������

���������ͼƬ����

���ǿ����ڼӸ�const������������p���ܸģ�֮��p = ��w������д��������ֱ���жϴ���, ��������Ч�ı����ַ�����

int main()
{
	const char* p = "abcdef";
	*p = 'w';
	printf("%s\n", p);
	return 0;
}
���������ͼƬ����

һ�������⣺

int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcdef";

	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	if (p1 == p2)
		printf("p1==p2\n");
	else
		printf("p1 != p2");
	if (arr1 == arr2)
		printf("arr1 == arr2");
	else
		printf("arr1 != arr2");

	return 0;
}
����ǣ�

p1 == p2
arr1 != arr2
p1��p2ָ��ͬһ���ַ���������ַ����ǳ����ַ����������ڴ��е�ֻ�����ֻ�����Ŀռ�ֻ�ܶ�����д��ֻ���ò��ܸģ���Ȼabcdef�ǳ����ַ����Ļ����ܱ��ģ���abcdef�����ĳ����ַ�����û�б�Ҫ���ڶ�ݣ���ʵ��һ�ݾ͹��ˣ�����a����ʼ��ַ��0x0012ff40����ôp1���ľ������ֵ��p2Ҳ�����ֵ������p1 == p2����Ϊ��������ŵ�ֵ����ȵģ������£�����arr1 �� arr2����ȣ���Ϊ��������Ǵ����������������飬��abcdef��ʼ��arr1[]���飬arr1[]Ҫ����abcdef\0����Ҫ���ڴ��п���һ�οռ䣬arr2[]Ҳһ��������ռ����ʼ��ַ��*/һ����arr1��arr2������ʼ��ַ���������ڴ��еĵ�ַ�����ǲ���ȵġ�