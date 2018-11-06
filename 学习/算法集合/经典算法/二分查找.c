#include<stdio.h>
//二分查找几乎是搜索有序信息的最快方法，其时间复杂度是 log2(n) ，下面用求平方根的整数解来演示二分查找

int gh(long long num);										//利用二分法求一个整数的平方根

int main()
{
	long long num;
	printf("\n  请输入要开根号的整数：");
	scanf_s("%lld", &num);
	printf("\n  该数开根号的整数解是：%d\n\n  ", gh(num));
}

int gh(long long num)										//利用二分法求一个整数的平方根
{
	if (num*num == num)	return num;							//1 或 0 的情况
	if (num < 4)	return 1;								//小于 4 的情况
	long long l = 0, r = num, mid = num / 2;				//区间三点
	for (; mid != l; mid = l + (r - l) / 2)					//进行二分查找
		if (num / mid / mid == 1 && num / (mid + 1) / (mid + 1) == 0)	return mid;		//已找到
		else if (mid*mid > num)	r = mid;					//中点偏大，更新右端点
		else if (mid*mid < num)	l = mid;					//中点偏小，更新左端点
	return 0;												//忽略这行，编译器要求非 void 函数所有分支必须返回值
}

/*
注意：求中点时要用 mid = l + (r-l) / 2 而不要用 mid = (l+r) / 2，因为在 l、r 均大于 long long 型的情况下，二者相加会造成溢
出，导致求错中点的值，第一种就不会有这种错误。当然，在这个求平方根的例子中不存在这种情况，但在其它例子中可就不一定了，所以建议使用第一个
式子求中点。
同样的，为了避免溢出，判断条件也用了 num / mid / mid == 1 && num / (mid + 1) / (mid + 1) == 0 这样的相除来达到目的。
*/