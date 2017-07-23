
#include <windows.h>
#include "trace.h"


fstream trace::tracefile;
fstream trace::logfile;

bool trace::traceflag;
bool trace::trace_time_flag;
bool trace::trace_memory_flag;
bool trace::logflag;

long trace::trace_time::gettime()
{
	return GetTickCount();
}

int trace::trace_memory::newnumber;
int trace::trace_memory::delnumber;
int trace::trace_memory::memrecord[1000000];

void trace::trace_memory::setrecord(int index,bool value)
{
	int i=index>>5;
	int j=index&31;
	int mask=1<<j;
	if (value) memrecord[i]|=mask;
	else memrecord[i]&=~mask;
}

bool trace::trace_memory::getrecord(int index)
{
	int i=index>>5;
	int j=index&31;
	int mask=1<<j;
	return (memrecord[i]&mask)!=0;
}

void * trace::trace_memory::mynew(size_t n)
{
	/* debug --
	if (newnumber==57 || newnumber==431463 || newnumber==560401 || newnumber==560414 || 
		newnumber==1813143 || newnumber==1813145 || newnumber==1813150 || newnumber==1813154)
	{
		int x=0;
	}
	/*-- debug */
	void * p=malloc(n+4);
	if (p!=NULL)
	{
		*(int*)p=newnumber;
		setrecord(newnumber,true);
		newnumber++;
		return (char *)p+4;
	}
	else return NULL;
}

void trace::trace_memory::mydelete(void * p)
{
	if (p)
	{
		delnumber++;
		int number=*(int *)((char *)p-4);
		setrecord(number,false);
		::free((char *)p-4);
	}
}

void trace::trace_memory::mymemory()
{
	fstream trace_memory_file("trace_memory.txt",ios::app|ios::out);
	trace_memory_file << "newnumber = " << newnumber << endl;
	trace_memory_file << "delnumber = " << delnumber << endl;
	for (int i=0;i<newnumber;i++)
	{
		if (getrecord(i)==true)
			trace_memory_file << "Memory Leak: " << i << endl;
	}
	trace_memory_file.close();
}

/* --------------------------------------------------------- 
�������ڴ�й©�ķ�����
 1. �뽫��������ע��ȥ����
 2. �������������˳�ʱ����trace::trace_memory::mymemory()������
    ����ʱ�ͻ�����һ��trace.txt�ļ��������ڴ�й©��newnumberֵ��
 3. Ȼ����trace::trace_memory::mynew()������������Ӧ�ϵ㣬
    �Ϳ��Լ���Ĵ�������ڴ�û�б��ͷš�
-----------------------------------------------------------*/

/* debug
using namespace trace;
using namespace trace_memory;

void * operator new(size_t n) { return mynew(n); }
void operator delete(void * p) { mydelete(p); }
debug */

