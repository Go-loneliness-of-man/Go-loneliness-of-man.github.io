[1mdiff --git a/README.md b/README.md[m
[1mindex 61429e0..2f002a9 100644[m
[1m--- a/README.md[m
[1m+++ b/README.md[m
[36m@@ -1,4 +1,2 @@[m
 # Go-loneliness-of-man.github.io[m
 主要是笔记[m
[31m-[m
[31m-[m
[1mdiff --git a/index.html b/index.html[m
[1mindex 84970db..c5e8e9e 100644[m
[1m--- a/index.html[m
[1m+++ b/index.html[m
[36m@@ -8,8 +8,8 @@[m
     @font-face{[m
       font-family:'微软雅黑';[m
       src:url("微软雅黑.ttf");[m
[31m-    }                                                                       /*Web字体*/[m
[31m-    body{  background:url(图片/右上角.PNG) no-repeat top left/cover; }        /*页面整体背景*/[m
[32m+[m[32m    }                                                                      /*Web字体*/[m
[32m+[m[32m    body{  background:url(图片/右上角.PNG) no-repeat top left/cover; }       /*页面整体背景*/[m
     div ul{[m
       margin:1% 10px;[m
       padding:0px;[m
[36m@@ -26,7 +26,8 @@[m
       margin:10px 20px;[m
       padding:6px;[m
       border:3px solid black;[m
[31m-      border-radius:10px;                                                 /*li样式*/[m
[32m+[m[32m      border-radius:10px;[m
[32m+[m[32m      transition:all 0.4s;                                                /*li样式*/[m
     }[m
     li:hover{[m
       width:80px;[m
[36m@@ -51,19 +52,19 @@[m
     }[m
     #shu:hover{ padding:5px 0px 15px 20px; }[m
     a{ text-decoration:none; }[m
[31m-    div ul li span{ color:rgb(20,20,20); font-weight:bold; }                             /*指定 li 的细节样式*/[m
[32m+[m[32m    div ul li span{ color:rgb(20,20,20); font-weight:bold;transition:all 0.4s; }         /*指定 li 的细节样式*/[m
     div ul li span:hover{ color:white; text-decoration:none; font-weight:bold; }         /*li 被点击时的样式*/[m
     #study:hover iframe,#time:hover iframe,#artical:hover iframe,#shu:hover iframe{ display:block; }[m
     /*使各个 li 的悬浮框在指针悬停下可见*/[m
     #time2,#artical2,#study2,#shu2{[m
       position:absolute;[m
[31m-      top:148px;[m
[32m+[m[32m      top:140px;[m
       left:144px;[m
       border:3px solid black;[m
       border-radius:10px;[m
       display:none;[m
       width:600px;[m
[31m-      height:480px;[m
[32m+[m[32m      height:500px;[m
     }                                                                      /*各个 li 菜单的样式 */[m
     audio{[m
       position:absolute;[m
[36m@@ -112,10 +113,10 @@[m
           <iframe id="artical2" src="随笔/index.html"></iframe></li>[m
         <li id="time">[m
           <a href="#time2"><span>岁月如梭</span></a>[m
[31m-          <iframe id="time2" style="width:1100px; height:480px;" src="珍惜时间.html"></iframe>[m
[32m+[m[32m          <iframe id="time2" style="width:1100px;" src="珍惜时间.html"></iframe>[m
         </li>[m
           <li id="shu"><a href="#shu2"><span>我的书</span></a>[m
[31m-          <iframe id="shu2" style="width:1100px; height:480px;" src="面向考试编程/index.html"></iframe>[m
[32m+[m[32m          <iframe id="shu2" style="width:1100px;" src="面向考试编程/index.html"></iframe>[m
         </li>[m
       </ul>[m
   </div>[m
[1mdiff --git "a/\345\255\246\344\271\240/C\350\257\255\350\250\200/\347\233\256\345\275\225/shitidaan.html" "b/\345\255\246\344\271\240/C\350\257\255\350\250\200/\347\233\256\345\275\225/shitidaan.html"[m
[1mindex 613bc9d..459fd76 100644[m
[1m--- "a/\345\255\246\344\271\240/C\350\257\255\350\250\200/\347\233\256\345\275\225/shitidaan.html"[m
[1m+++ "b/\345\255\246\344\271\240/C\350\257\255\350\250\200/\347\233\256\345\275\225/shitidaan.html"[m
[36m@@ -6,6 +6,10 @@[m
   <meta charset="UTF-8">[m
   <link rel="stylesheet" href="../../H5_ps_php_计算机基础.css">[m
   <style>[m
[32m+[m[32m    #body {[m
[32m+[m[32m      margin: 0% 5% 3% 5%;[m
[32m+[m[32m      line-height:1.7em;[m
[32m+[m[32m    }[m
     #caidan{[m
       color:rgb(150,195,120);[m
       font-size:25px;[m
[36m@@ -17,8 +21,17 @@[m
       width:15%;[m
       height:40%;[m
       position:fixed;[m
[31m-      left:82%;[m
[32m+[m[32m      left:91%;[m
       top:0%;[m
[32m+[m[32m      transition:all 0.7s;[m
[32m+[m[32m    }[m
[32m+[m[32m    #ks:hover{[m
[32m+[m[32m      position:fixed;[m
[32m+[m[32m      left:82%;[m
[32m+[m[32m    }[m
[32m+[m[32m    #ks:active{[m
[32m+[m[32m      position:fixed;[m
[32m+[m[32m      left:82%;[m
     }[m
     #ks span,#ks li,#ks li a{ display:inline-block; }[m
     #ks span{[m
[36m@@ -43,6 +56,15 @@[m
     #ks li a{ margin:0% 5%; }[m
     #ks li:hover{ padding: 6px; border:5px solid white; color:white; }[m
     #ks li:hover a{ color:white; font-size:27px; }[m
[32m+[m[32m    .ti{[m
[32m+[m[32m      float:left;[m
[32m+[m[32m      display:block;[m
[32m+[m[32m      width:40%;[m
[32m+[m[32m      border:2px dashed rgb(82, 255, 234);[m
[32m+[m[32m      border-radius:20px;[m
[32m+[m[32m      padding:15px;[m
[32m+[m[32m      margin:2%;[m
[32m+[m[32m    }[m
   </style>[m
 </head>[m
 [m
[36m@@ -57,6 +79,7 @@[m
       <li>4.<a href="#four">编程题</a></li>[m
       <li style="border:5px solid red;"><a href="#five" style="color:red;">5.三处错误 !</a></li>[m
       <li>6.<a href="#six" style="font-size:18px;">考试范围、重点</a></li>[m
[32m+[m[32m      <li>7.<a href="#seven">高频、易错</a></li>[m
     </ol>[m
     <div id="caidan">[m
       相信能找到这里的童鞋大部分都是已经看完《面向考试编程》的了吧，鉴于大家刚刚艰苦卓绝的学习完 C 语言，在这里就先给童鞋们调剂下，放一个本书的小彩蛋，[m
[36m@@ -455,6 +478,286 @@[m
         <li>指针：什么是指针变量、指针变量的本质、指针指向数组、指针引用字符串、地址运算</li>[m
         <li>结构体：声明、定义、打印</li>[m
       </ol>[m
[32m+[m[32m    <h2 id="seven">高频、易错题型</h2>[m
[32m+[m[32m      最近我又刷了七套往届题，发现一些高频、易错的题型，所以总结汇总在这里，一共二十几道，下面会按不同类型分别标注分类。其中有些题出现频率非常高，七套中[m
[32m+[m[32m      有四套以上会考，而且是原封不动的原题，这种题被我用（高频）标出或是归类到了“概念”一栏下。<br><br>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        1.（计算）定义一个变量使之保存至的范围是 0 ~ 65535，应选择的变量类型是（ ）<br>[m
[32m+[m[32m        A. unsigned short int<br>B. int<br>C. short<br>D. long int[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 A。首先， 0 ~ 65535 是 65536 个数字，而变量的值是保存在内存中的，一字节内存是 8 位二进制，所以计算 2 的多少次方等于 65536 ，据此得出字[m
[32m+[m[32m          节数来判断变量的类型。至于计算，如果笔试，只能手算，如果是上机，可以利用 C 语言位运算来计算，如下：[m
[32m+[m[32m          <code>[m
[32m+[m[32m#include&lt;stdio.h&gt;[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m[32m  int i, x;[m
[32m+[m[32m  for (x = 1, i = 1; ((i << (x - 1)) != 65536); x++)[m
[32m+[m[41m  [m	[32mprintf("\n  2 的 %d 次方： %d\n\n  ", x, i << x);[m
[32m+[m[32m  return 0;[m
[32m+[m[32m}[m
[32m+[m[32m          </code>[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        2.（易错）设 x、y、z 都是整型变量，x、y 的初值都是 5，执行 z = （++x）+（y--）+ 1 后，x、y、z 三变量的值按顺序是（ ）<br>[m
[32m+[m[32m        A.5，5，11<br>B.6，6，13<br>C.4，6，12<br>D.6，4，12[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 D。<span class="em">在同一表达式中</span>，自增（自减）的顺序会影响到取值，注意观察到底是先取值再自增还是先自增再取值。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        3.（高频）若有声明：char c = '\72'; 则变量 c（ ）<br>[m
[32m+[m[32m        A. 包含一个字符<br>B. 包含两个字符<br>C. 包含三个字符<br>D. 声明不合法，c 的值不确定[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 A。'\72' 是转义字符，算一个字符。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        4. （易错）在 C 语言中，一维数组的定义方式是： 类型说明符 数组名_____<br>[m
[32m+[m[32m        A. 常量表达式<br>B. 整型表达式<br>C. 整型常量或整型表达式<br>D. 任何类型[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 C。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        5.（易错）下列表达式不为实型的是（ ）<br>[m
[32m+[m[32m        A. sqrt(9)<br>B. 5 % 2<br>C. 1.0e3<br>D. 3.1415926[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 B。A 选项是个求根函数，返回值是 double 类型。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        6.（易错）下列选项中，不能作为合法常量的是（ ）<br>[m
[32m+[m[32m        A. 1.234e04<br>B. 1.234e0.4<br>C. 1.234e+4<br>D. 1.234e0[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 B。常量的指数部分只能是整型数字[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        7.（易错）在 C 语言中，下列数据按存储空间大小排列顺序正确的是（ ）<br>[m
[32m+[m[32m        A. '5' < 5 < 5L<br>B. '5' = 5 < 5L<br>C. '5' < 5 = 5L<br>D. '5' = 5 = 5L[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 A。在 C 语言中，long 型的长度一定是不小于 int 型的，在不同编译器下可能长度相等，但严格意义上讲 long >= int[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        8.（易错）int a = 5; a /= a *= a += 3; 则 a 的值（ ）<br>[m
[32m+[m[32m        A. 5<br>B. 3<br>C. 6<br>D. 1[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 D。复杂赋值运算符优先级相同，结合方向由右向左，所以依次是 a + 3、a * a、a / a，不难发现，由于最后一个是自己除自己，所以其实无论前面怎么计算，[m
[32m+[m[32m          结果都是 1。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        9.（易错）下列表达式中值为 0 的是（ ）<br>[m
[32m+[m[32m        A. 3 / 5<br>B. 3 % 5<br>C. 3 && 5<br>D. 3 < 5[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          选 A。B、C、D 依次是 5、1、1，当两个整型进行除法运算时，会省略小数部分， 3 / 5 等于 0.6，省略小数部分为 0。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        10.（易错）有语句：int a[3] = { 1 , 2 , 3 }; int *p; p = a; 则 *p++ 的值为_____<br>[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          *p++ 是个运算表达式，所以对 p 来说是先取值再自增，因此取出的是第一个数组元素的值，即 1。[m[41m [m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        11.（易错）阅读程序：[m
[32m+[m[32m        <code>[m
[32m+[m[32m          #include&lt;stdio.h&gt;[m
[32m+[m[32m          void main()[m
[32m+[m[32m          {[m
[32m+[m[32m            int a , b , c;[m
[32m+[m[32m            a = 2; b = 3; c = 1;[m
[32m+[m[32m            if( a > b )[m
[32m+[m[32m              if( a > c )[m
[32m+[m[32m                printf( "%d\n", a);[m
[32m+[m[32m              else[m
[32m+[m[32m                printf( "%d\n", b );[m
[32m+[m[32m            printf( "end\n" );[m
[32m+[m[32m          }[m
[32m+[m[32m        </code><br>[m
[32m+[m[32m        运行结果是______。[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          两层的选择结构，若第一个判断为假，则第二个直接不判断，由题知 a > b，所以不执行 if，直接输出 end。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        12.（高频）阅读：[m
[32m+[m[32m        <code>[m
[32m+[m[32m          #include&lt;stdio.h&gt;[m
[32m+[m[32m          void main()[m
[32m+[m[32m          {[m
[32m+[m[32m            int i , j , m , n;[m
[32m+[m[32m            i = 8; j = 10;[m
[32m+[m[32m            m = ++i;[m
[32m+[m[32m            n = j++;[m
[32m+[m[32m            printf("%d , %d , %d , %d", i,j ,m ,n);[m
[32m+[m[32m          }[m
[32m+[m[32m        </code><br>[m
[32m+[m[32m        执行结果______。<br>[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          m 对 i 是先自增再取值，因此 m 等于 9，n 对 j 是先取值再自增，因此 n 等于 10，最后，i、j 都自增过，因此 i、j 分别等于 9、11。[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        13.（高频）计算数列：2 / 1、3 / 2、5 / 3、8 / 5、13 / 8、21 / 13  的前 40 项之和。（精确到两位小数）[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          观察数列，不难发现分子分母的每一项都来源于这样一个数列：1、2、3、5、8、13、21 ...... 从第三项开始，每一项等于前两项之和，由此可得两种解法：[m
[32m+[m[32m          <code>[m
[32m+[m[32m#include&lt;stdio.h&gt;[m
[32m+[m[32m/*第一种解法，利用数组，先推出分子分母数列的前 41 项，再利<br>用其计算出题目要求的数列的前 40 项之和*/[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m	[32mdouble nums[41], x;	int i;[m
[32m+[m	[32mfor (nums[0] = 1, nums[1] = 2, i = 2; i < 41; i++)[m
[32m+[m		[32mnums[i] = nums[i - 1] + nums[i - 2];[m
[32m+[m	[32mfor (x = 0, i = 0; i < 40; i++)[m
[32m+[m		[32mx += nums[i + 1] / nums[i];[m
[32m+[m	[32mprintf("\n  数列前 40 项之和为: %.2lf\n\n  ", x);[m
[32m+[m	[32mreturn 0;[m
[32m+[m[32m}[m
[32m+[m[32m          </code>[m
[32m+[m[32m          <code>[m
[32m+[m[32m#include&lt;stdio.h&gt;[m
[32m+[m[32m/*第二种解法，利用两个变量，推出分子分母数列的下一项，相加后<br>再推，直到第 40 项*/[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m	[32mdouble a, b, x, temp;	int i;[m
[32m+[m	[32mfor (a = 1, b = 2, x = 0, i = 0; i < 40; i++)[m
[32m+[m	[32m{[m
[32m+[m		[32mx += b / a;[m
[32m+[m		[32mtemp = b;		//保存前一项的值[m
[32m+[m		[32mb += a;			//推出下一项到 b[m
[32m+[m		[32ma = temp;		//将前一项的值赋值给 a[m
[32m+[m	[32m}[m
[32m+[m	[32mprintf("\n  数列前 40 项之和为: %.2lf\n\n  ", x);[m
[32m+[m	[32mreturn 0;[m
[32m+[m[32m}[m
[32m+[m[32m          </code>[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        14.（高频）输入一行字符，分别统计其中英文字母、空格、数字、其它字符的个数。<br>[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          利用 ASCⅡ 码分辨字符的类别即可。[m
[32m+[m[32m          <code>[m
[32m+[m[32m#include&lt;stdio.h&gt;[m
[32m+[m[32m//统计一串字符中字母、数字、空格、其它字符的个数[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m	[32mint a = 0, b = 0, c = 0, d = 0; char e;[m
[32m+[m[32m  for (; (e = getchar()) != '\n';)[m
[32m+[m[32m  //注意这里括号的使用，很重要[m
[32m+[m	[32m{[m
[32m+[m		[32mif (e >= 'a'&&e <= 'z' || e >= 'A'&&e <= 'Z')[m
[32m+[m			[32ma++;[m
[32m+[m		[32melse if (e >= '0'&&e <= '9')[m
[32m+[m			[32mb++;[m
[32m+[m		[32melse if (e == ' ')[m
[32m+[m			[32mc++;[m
[32m+[m		[32melse[m
[32m+[m			[32md++;[m
[32m+[m	[32m}[m
[32m+[m[32m  printf("\n  字母 %d 个，数字 %d 个，空格 %d 个，其它字符[m
[32m+[m[32m  %d 个\n\n  ", a, b, c, d);[m
[32m+[m	[32mreturn 0;[m
[32m+[m[32m}[m
[32m+[m[32m          </code>[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        15.（经典）定义一个二维数组，通过键盘输入各元素的值，求数组中所有元素的和。<br>[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          用一个两层的 for 读入，再用一个两层的 for 循环相加。[m
[32m+[m[32m          <code>[m
[32m+[m[32m#include&lt;stdio.h&gt;[m
[32m+[m[32m//求一个二维数组所有元素的和[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m	[32mdouble nums[3][4], sum;	int i, j;[m
[32m+[m	[32mfor (i = 0; i < 3; i++)[m
[32m+[m	[32m{[m
[32m+[m		[32mfor (j = 0; j < 4; j++)[m
[32m+[m			[32mscanf_s("%lf", &nums[i][j]);[m
[32m+[m	[32m}[m
[32m+[m	[32mfor (i = 0, sum = 0; i < 3; i++)[m
[32m+[m	[32m{[m
[32m+[m		[32mfor (j = 0; j < 4; j++)[m
[32m+[m			[32msum += nums[i][j];[m
[32m+[m	[32m}[m
[32m+[m	[32mprintf("\n  所有元素和：%lf\n\n  ", sum);[m
[32m+[m	[32mreturn 0;[m
[32m+[m[32m}[m
[32m+[m[32m          </code>[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        16.（经典）一个 3 x 4 的矩阵，要求编程找出其中的最大值，以及其所在的行号和列号。<br>[m
[32m+[m[32m        <details>[m
[32m+[m[32m          <summary>解析</summary>[m
[32m+[m[32m          定义一个变量 max，从第一个数组元素开始，依次往后比较，遇到更大的数就更新值并保存行号、列号，直到遍历完整个数组。[m
[32m+[m[32m          <code>[m
[32m+[m[32m#include&lt;stdio.h&gt;[m
[32m+[m[32m//找出二维数组最大元素及其行号、列号[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m[32m  double nums[3][4], max;	int i, j, x, y;[m
[32m+[m[32m  for (i = 0; i < 3; i++)[m
[32m+[m[32m  {[m
[32m+[m[32m    for (j = 0; j < 4; j++)[m
[32m+[m[32m      scanf_s("%lf", &nums[i][j]);[m
[32m+[m[32m  }[m
[32m+[m[32m  for (i = 0, max = nums[0][0]; i < 3; i++)[m
[32m+[m[32m  {[m
[32m+[m[32m    for (j = 0; j < 4; j++)[m
[32m+[m[32m    {[m
[32m+[m[32m      if (max < nums[i][j])[m
[32m+[m[32m      {[m
[32m+[m[32m        max = nums[i][j];[m
[32m+[m[32m        x = i;[m
[32m+[m[32m        y = j;[m
[32m+[m[32m      }[m
[32m+[m[32m    }[m
[32m+[m[32m  }[m
[32m+[m[32m  printf("\n  最大值：%lf\t行号: %d\t列号： %d\n\n  ", max, x, y);[m
[32m+[m[32m  return 0;[m
[32m+[m[32m}[m
[32m+[m[32m          </code>[m
[32m+[m[32m        </details>[m
[32m+[m[32m      </div>[m
[32m+[m[32m      <div class="ti">[m
[32m+[m[32m        <h3>概念</h3>[m
[32m+[m[32m        <ol>[m
[32m+[m[32m          <li>C语言中函数<span class="em">不可以嵌套定义</span>，可以嵌套调用。</li>[m
[32m+[m[32m          <li>在 C 语言中，要求运算数必须是整型的运算符是 %</li>[m
[32m+[m[32m          <li>C 语言的标识符只能由字母、数字、下划线组成，且<span class="em">第一个字符必须是字母或下划线</span>。</li>[m
[32m+[m[32m          <li><span class="em">指针不是</span> C 语言的基本数据类型</li>[m
[32m+[m[32m          <li>一个算法应该具有的 5 个特点是：<span class="em">有穷性、有效性、确定性、0 个或多个输入、1 个或多个输出</span></li>[m
[32m+[m[32m          <li>按生存周期划分，变量分两种类型：静态变量、动态变量</li>[m
[32m+[m[32m          <li>C 语言变量的存储类别有 4 种，分别是：自动变量（auto）、寄存器变量（register）、静态变量（static）、外部变量（extern）</li>[m
[32m+[m[32m          <li>结构化程序设计使用的三种基本结构是：顺序、选择、循环结构，它们都具有的 4 个共同特点是：一个入口、一个出口、没有死循环、无永远执行不到的[m
[32m+[m[32m            语句</li>[m
[32m+[m[32m          <li>输入函数 scanf() 有两类参数，分别是：格式字符串、地址列表</li>[m
[32m+[m[32m          <li>continue 是用来结束<span class="em">本次循环</span>的，而 break 是用来结束<span class="em">整个循环</span>的。</li>[m
[32m+[m[32m        </ol>[m
[32m+[m[32m      </div>[m
   </div>[m
 </body>[m
 [m
[1mdiff --git "a/\345\255\246\344\271\240/index.html" "b/\345\255\246\344\271\240/index.html"[m
[1mindex b2123d5..7d361f3 100644[m
[1m--- "a/\345\255\246\344\271\240/index.html"[m
[1m+++ "b/\345\255\246\344\271\240/index.html"[m
[36m@@ -9,7 +9,8 @@[m
           line-height:1.9em;[m
           background:url(../图片/学习背景.PNG);[m
          }[m
[31m-    a:link { color: rgb(143, 114, 247); text-decoration: none; font-size:16px; }[m
[32m+[m[32m    a{ display:inline-block; margin:3px 1px; }[m
[32m+[m[32m    a:link { color: rgb(143, 114, 247); text-decoration: none; font-size:16px; transition:all 0.5s; }[m
     a:visited { color: black; text-decoration: none; }[m
     a:hover { color: white; text-decoration: none; font-size:27px; }[m
   </style>[m
[36m@@ -20,25 +21,25 @@[m
   <div id="body">[m
     <ol>[m
       <li><a href="《Head First HTML与CSS》笔记/index.html"[m
[31m-             target="_blank">《Head First HTML与CSS》笔记</a></li>[m
[32m+[m[32m             target="_blank">《Head First HTML与CSS》 笔记</a></li>[m
       <li><a href="HTML5笔记"[m
[31m-             target="_blank">HTML5笔记</a></li>[m
[32m+[m[32m             target="_blank">HTML5 笔记</a></li>[m
[32m+[m[32m      <li><a href="CSS"[m
[32m+[m[32m             target="_blank">CSS 笔记</a></li>[m
       <li><a href="git与github笔记"[m
[31m-             target="_blank">git与github笔记</a></li>[m
[32m+[m[32m             target="_blank">git与github 笔记</a></li>[m
       <li><a href="3Dmax"[m
              target="_blank">3Dmax</a></li>[m
       <li><a href="photpshop笔记"[m
[31m-             target="_blank">photpshop笔记</a></li>[m
[32m+[m[32m             target="_blank">photpshop 笔记</a></li>[m
       <li><a href="计算机基础"[m
              target="_blank">计算机基础</a></li>[m
[31m-      <li><a href="CSS"[m
[31m-             target="_blank">CSS</a></li>[m
       <li><a href="php"[m
[31m-             target="_blank">php</a></li>[m
[32m+[m[32m             target="_blank">php 笔记</a></li>[m
       <li><a href="算法集合"[m
              target="_blank">算法集合</a></li>[m
       <li><a href="C语言"[m
[31m-             target="_blank">C语言</a></li>[m
[32m+[m[32m             target="_blank">C 语言</a></li>[m
     </ol>[m
   </div>[m
 </body>[m
