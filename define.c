#include<stdio.h>

#define maxsize 1024   //simple use
#define max(x,y) (x)>(y)?(x):(y);  //define function
#define add(a,b) a+b;
//------------rare use----------
#define A(x) T_##x
#define B(x) #@x
#define C(x) #x

//----------define several line

#define MACRO(arg1, arg2) do {\
/*declarations*/\
	stmt1; \
	stmt2; \
} while(0) /* (no trailing)*/

//-------------condition define---------
#ifdef X

/*```````````*/
#endif
#ifdef Y
/*******************/

#endif

//---------------cancel define
#define name 12
#undef name

//----------define cover headerfile(.h)
#ifndef __headerfileXXX__
#define __headerfileXXX__
/**********file content*************/

#endif

//---------------in case a headerfile(.h) be covered more than once
#ifndef COMDEF_H
#define COMDEF_H
//headerfile content
#endif

//_________-typedef----
typedef unsigned long int uint32;

//get the content of the designated address
	#define MEM_B(x) (*((byte*)(x)))
	#define MEM_W(x) (*((word*)(x)))

//get the max-number or min0number
	#define MAX(x,y) (((x)>(y))?(x):(y))

//get the pos of a field in the struct
	#define FPOS(type, field)\
		/*lint -e545 */ ( (dword) &(( type *) 0)-> field ) /*lint +e545 */

//get the size of a field in the struct
	#define FSIZ(type, field) sizeof(((type*)0)->field)

//change two bytes into word with lsb type
	#define FLIPW(ray)  ( (((word) (ray)[0]) * 256) + (ray)[1] )

//change a word into two bytes by lsb type
	#define FLOPW(ray, val) \
	(ray)[0] = ((val)/256); \
	(ray)[1] = ((val)&0xff)
//get the address(word type) of a var
	#define B_PTR(var) ((byte*)(void*)&(var))
	#define W_PTR(var) ((word*)(void*)&(var))
//get the high or low byte of a word
	#define  WORD_LO(xxx)  ((byte) ((word)(xxx) & 255)) 
	#define  WORD_HI(xxx)  ((byte) ((word)(xxx) >> 8))
//change a little_char into big_char ex 'a' -> 'A'
	#define  UPCASE( c ) ( ((c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) )
//judge  whether a char is a 16x number or not
	#define  HEXCHK( c ) ( ((c) >= '0' && (c) <= '9') || \
			((c) >= 'A' && (c) <= 'F') || \
			((c) >= 'a' && (c) <= 'f'))
//a way to prevent overflow
	#define INC_SAT(val)  (val = ((val)+1 > (val)) ? (val)+1 : (val))
//return num of the array
	#define ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )
//返回一个无符号数n尾的值MOD_BY_POWER_OF_TWO(X,n)=X%(2^n) 
	#define MOD_BY_POWER_OF_TWO( val, mod_by )\
		( (dword)(val) & (dword)((mod_by)-1) )
//对于IO空间映射在存储空间的结构，输入输出处理 
	#define inp(port)	(*((volatile byte *) (port)))   
	#define inpw(port)        (*((volatile word *) (port)))   
	#define inpdw(port)       (*((volatile dword *)(port))) 
	#define outp(port, val)   (*((volatile byte *) (port)) = ((byte) (val))) 
	#define outpw(port, val)  (*((volatile word *) (port)) = ((word) (val))
	#define outpdw(port, val) (*((volatile dword *) (port)) = ((dword) (val)))
//使用一些宏跟踪调试 
//ANSI标准说明了五个预定义的宏名。它们是： __LINE__ __FILE__ __DATE__ __TIME__ __STDC__ 
//C++中还定义了 __cplusplus 
//如果编译器不是标准的,则可能仅支持以上宏名中的几个,或根本不支持。记住编译程序也许还提供其它预定义的宏名。 
//__LINE__ 及 __FILE__ 宏指示，#line指令可以改变它的值，简单的讲，编译时，它们包含程序的当前行数和文件名。 
//__DATE__ 宏指令含有形式为月/日/年的串,表示源文件被翻译到代码时的日期。 __TIME__ 宏指令包含程序编译的时间。时间用字符串表示，其形式为：分：秒 
//__STDC__ 宏指令的意义是编译时定义的。一般来讲，如果__STDC__已经定义，编译器将仅接受不包含任何非标准扩展的标准C/C++代码。如果实现是标准的,则宏__STDC__含有十进制常量1。如果它含有任何其它数,则实现是非标准的。 
//__cplusplus 与标准c++一致的编译器把它定义为一个包含至少6为的数值。与标准c++不一致的编译器将使用具有5位或更少的数值。 可以定义宏,例如: 
//当定义了_DEBUG,输出数据信息和所在文件所在行 
	#ifdef _DEBUG 
	#define DEBUGMSG(msg,date) printf(msg);printf(“%d%d%d”,date,_LINE_,_FILE_) 
	#else 
	#define DEBUGMSG(msg,date)  
	#endif
//宏定义防止错误使用小括号包含。 
//例如： 
//有问题的定义：#define DUMP_WRITE(addr,nr) {memcpy(bufp,addr,nr); bufp += nr;} 应该使用的定义： #difne DO(a,b) do{a+b;a++;}while(0)
//gcc在碰到else前面的“；”时就认为if语句已经结束，因而后面的else不在if语句中。而采用do{} while(0)的定义，在任何情况下都没有问题。而改为 #difne DO(a,b) do{a+b;a++;}while(0) 的定义则在任何情况下都不会出错
//
//
//define中的特殊标识符 
	#define Conn(x,y) x##y
	#define ToChar(x) #@x
	#define ToString(x) #x  
//int a=Conn(12,34); char b=ToChar(a); char c[]=ToString(a); 
//结果是 a=1234,c='a',c='1234'; 
//可以看出 ## 是简单的连接符，#@用来给参数加单引号，#用来给参数加双引号即转成字符串 
// 
//
