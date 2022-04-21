/*
 * 源代码构建方式：
 * 使用VS2022编译并生成安装包。
 */

#include<stdio.h>
#include<stdlib.h>
#pragma comment (lib,"Winmm.lib")
#include<Windows.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#define width (125)
#define length (175)
#define gapx (70)
#define gapy (25)
#define numx (4)
#define numy (3)
#define time1 (20)
#define width2 (75)
#define length2 (100)
#define gapx2 (70)
#define gapy2 (25)
#define numx2 (5)
#define numy2 (4)
#define time2 (50)
#define time3 (60)
#define numx3 (6)
#define numy3 (5)
#define width3 (75)
#define length3 (100)
#define gapx3 (60)
#define gapy3 (20)
#define width4 (70)
#define length4 (90)
#define gapx4 (70)
#define gapy4 (15)
#define time4 (90)
#define numx4 (6)
#define numy4 (6)
int score = 0;
int rank = 0;
int i, j, flag;
int sum = 0;
IMAGE card0, card02, card[12], card2[20], card03, card3[30], card4[36], card04, over, sm;
IMAGE* pai[12], * pai2[20], * pai3[30], * pai4[36];
SYSTEMTIME shi;
time_t cur, begin;
struct card {
	int x;
	int y;
	int now;
}
c[12] = {
			{(1250 - numx * (width + gapx) + gapx) / 2,(740 - numy * (length + gapy) + gapy) / 2 + 100,-1},
			{c[0].x + 1 * (width + gapx),c[0].y + 0 * (length + gapy),-1},
			{c[0].x + 2 * (width + gapx),c[0].y + 0 * (length + gapy),-1},
			{c[0].x + 3 * (width + gapx),c[0].y + 0 * (length + gapy),-1},
			{c[0].x + 0 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
			{c[0].x + 1 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
			{c[0].x + 2 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
			{c[0].x + 3 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
			{c[0].x + 0 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
			{c[0].x + 1 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
			{c[0].x + 2 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
			{c[0].x + 3 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
},
d[12] = {
	{(1250 - numx * (width + gapx) + gapx) / 2,(740 - numy * (length + gapy) + gapy) / 2 + 100,-1},
	{d[0].x + 1 * (width + gapx),c[0].y + 0 * (length + gapy),-1},
	{d[0].x + 2 * (width + gapx),c[0].y + 0 * (length + gapy),-1},
	{d[0].x + 3 * (width + gapx),c[0].y + 0 * (length + gapy),-1},
	{d[0].x + 0 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
	{d[0].x + 1 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
	{d[0].x + 2 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
	{d[0].x + 3 * (width + gapx),c[0].y + 1 * (length + gapy),-1},
	{d[0].x + 0 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
	{d[0].x + 1 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
	{d[0].x + 2 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
	{d[0].x + 3 * (width + gapx),c[0].y + 2 * (length + gapy),-1},
},
c2[20] = {
	{(1250 - numx2 * (width2 + gapx2) + gapx2) / 2,(740 - numy2 * (length2 + gapy2) + gapy2) / 2 + 100,-1},
	{c2[0].x + 1 * (width2 + gapx2),c2[0].y + 0 * (length2 + gapy2),-1},
	{c2[0].x + 2 * (width2 + gapx2),c2[0].y + 0 * (length2 + gapy2),-1},
	{c2[0].x + 3 * (width2 + gapx2), c2[0].y + 0 * (length2 + gapy2), -1},
	{ c2[0].x + 4 * (width2 + gapx2),c2[0].y + 0 * (length2 + gapy2),-1 },
	{ c2[0].x + 0 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1 },
	{ c2[0].x + 1 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1 },
	{ c2[0].x + 2 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1 },
	{ c2[0].x + 3 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1 },
	{ c2[0].x + 4 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1 },
	{ c2[0].x + 0 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1 },
	{ c2[0].x + 1 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1 },
	{ c2[0].x + 2 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1 },
	{ c2[0].x + 3 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1 },
	{ c2[0].x + 4 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1 },
	{ c2[0].x + 0 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1 },
	{ c2[0].x + 1 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1 },
	{ c2[0].x + 2 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1 },
	{ c2[0].x + 3 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1 },
	{ c2[0].x + 4 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1 }
},
d2[20] = {
	{(1250 - numx2 * (width2 + gapx2) + gapx2) / 2,(740 - numy2 * (length2 + gapy2) + gapy2) / 2 + 100,-1},
	{c2[0].x + 1 * (width2 + gapx2),c2[0].y + 0 * (length2 + gapy2),-1},
	{c2[0].x + 2 * (width2 + gapx2),c2[0].y + 0 * (length2 + gapy2),-1},
	{c2[0].x + 3 * (width2 + gapx2),c2[0].y + 0 * (length2 + gapy2),-1},
	{c2[0].x + 4 * (width2 + gapx2),c2[0].y + 0 * (length2 + gapy2),-1},
	{c2[0].x + 0 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1},
	{c2[0].x + 1 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1},
	{c2[0].x + 2 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1},
	{c2[0].x + 3 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1},
	{c2[0].x + 4 * (width2 + gapx2),c2[0].y + 1 * (length2 + gapy2),-1},
	{c2[0].x + 0 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1},
	{c2[0].x + 1 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1},
	{c2[0].x + 2 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1},
	{c2[0].x + 3 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1},
	{c2[0].x + 4 * (width2 + gapx2),c2[0].y + 2 * (length2 + gapy2),-1},
	{c2[0].x + 0 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1},
	{c2[0].x + 1 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1},
	{c2[0].x + 2 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1},
	{c2[0].x + 3 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1},
	{c2[0].x + 4 * (width2 + gapx2),c2[0].y + 3 * (length2 + gapy2),-1}
},
c3[30] = {
			{(1250 - numx3 * (width3 + gapx3) + gapx3) / 2,(740 - numy3 * (length3 + gapy3) + gapy3) / 2 + 100,-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
},
d3[30] = {
			{(1250 - numx3 * (width3 + gapx3) + gapx3) / 2,(740 - numy3 * (length3 + gapy3) + gapy3) / 2 + 100,-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 0 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 1 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 2 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 3 * (length3 + gapy3),-1},
			{c3[0].x + 0 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 1 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 2 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 3 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 4 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
			{c3[0].x + 5 * (width3 + gapx3),c3[0].y + 4 * (length3 + gapy3),-1},
},
c4[36] = {
				{(1250 - numx4 * (width4 + gapx4) + gapx4) / 2,(740 - numy4 * (length4 + gapy4) + gapy4) / 2 + 100,-1},
				{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
				{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
				{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
				{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
				{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
				{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
				{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
				{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
				{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
				{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
				{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
				{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
				{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
				{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
				{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
				{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
				{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
				{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
				{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
				{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
				{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
				{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
				{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
				{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
				{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
				{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
				{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
				{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
				{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
				{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
				{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
				{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
				{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
				{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
				{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
	},
	d4[36] = {
					{(1250 - numx4 * (width4 + gapx4) + gapx4) / 2,(740 - numy4 * (length4 + gapy4) + gapy4) / 2 + 100,-1},
					{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
					{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
					{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
					{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
					{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 0 * (length4 + gapy4),-1},
					{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
					{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
					{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
					{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
					{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
					{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 1 * (length4 + gapy4),-1},
					{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
					{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
					{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
					{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
					{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
					{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 2 * (length4 + gapy4),-1},
					{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
					{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
					{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
					{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
					{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
					{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 3 * (length4 + gapy4),-1},
					{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
					{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
					{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
					{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
					{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
					{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 4 * (length4 + gapy4),-1},
					{c4[0].x + 0 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
					{c4[0].x + 1 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
					{c4[0].x + 2 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
					{c4[0].x + 3 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
					{c4[0].x + 4 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
					{c4[0].x + 5 * (width4 + gapx4),c4[0].y + 5 * (length4 + gapy4),-1},
	};

MOUSEMSG m;
void connect()
{
	int i = 0, j[6] = { 0 }, k, l;
	for (l = 0; l < 12; l++)
		c[l] = d[l];
	while (i < 12)
	{
		GetLocalTime(&shi);
		srand(shi.wMilliseconds); Sleep(7);
		k = rand() % 6 + 2;
		if (j[k - 2] < 2)
		{
			j[k - 2]++;
			pai[i] = &card[k - 2];
			i++;
		}

	}

}
void connect2()
{
	int i = 0, j[10] = { 0 }, k, l;
	for (l = 0; l < 20; l++)
		c2[l] = d2[l];
	while (i < 20)
	{
		GetLocalTime(&shi);
		srand(shi.wMilliseconds); Sleep(7);
		k = rand() % 10 + 2;
		if (j[k - 2] < 2)
		{
			j[k - 2]++;
			pai2[i] = &card2[k - 2];
			i++;
		}

	}

}
void connect3()
{
	int i = 0, j[15] = { 0 }, k, l;
	for (l = 0; l < 30; l++)
		c3[l] = d3[l];
	while (i < 30)
	{
		GetLocalTime(&shi);
		srand(shi.wMilliseconds); Sleep(7);
		k = rand() % 15 + 2;
		if (j[k - 2] < 2)
		{
			j[k - 2]++;
			pai3[i] = &card3[k - 2];
			i++;
		}

	}
}
void connect4()
{
	int i = 0, j[18] = { 0 }, k, l;
	for (l = 0; l < 36; l++)
		c4[l] = d4[l];
	while (i < 36)
	{
		GetLocalTime(&shi);
		srand(shi.wMilliseconds); Sleep(7);
		k = rand() % 18 + 2;
		if (j[k - 2] < 2)
		{
			j[k - 2]++;
			pai4[i] = &card4[k - 2];
			i++;
		}
	}
}

void change(int i)
{
	clearrectangle(c[i].x, c[i].y, c[i].x + width, c[j].y + length);
	if (c[i].now == 1)
		putimage(c[i].x, c[i].y, pai[i]);
	else if (c[i].now == -1)
		putimage(c[i].x, c[i].y, &card0);
	else if (c[i].now == 0);
}

void change2(int i)
{
	clearrectangle(c2[i].x, c2[i].y, c2[i].x + width2, c2[j].y + length2);
	if (c2[i].now == 1)
		putimage(c2[i].x, c2[i].y, pai2[i]);
	else if (c2[i].now == -1)
		putimage(c2[i].x, c2[i].y, &card02);
	else if (c2[i].now == 0);
}
void change3(int i)
{
	clearrectangle(c3[i].x, c3[i].y, c3[i].x + width3, c3[j].y + length3);
	if (c3[i].now == 1)
		putimage(c3[i].x, c3[i].y, pai3[i]);
	else if (c3[i].now == -1)
		putimage(c3[i].x, c3[i].y, &card03);
	else if (c3[i].now == 0);
}
void change4(int i)
{
	clearrectangle(c4[i].x, c4[i].y, c4[i].x + width4, c4[j].y + length4);
	if (c4[i].now == 1)
		putimage(c4[i].x, c4[i].y, pai4[i]);
	else if (c4[i].now == -1)
		putimage(c4[i].x, c4[i].y, &card04);
	else if (c4[i].now == 0);
}

void daotime()
{
	cur = time(NULL);
	char str[32];
	setcolor(WHITE);
	sprintf_s(str, 32, "%03d", time1 - (int)difftime(cur, begin));
	if (time1 - (int)difftime(cur, begin) > 0)
		outtextxy(670, 100, str);
}

void daotime2()
{
	cur = time(NULL);
	char str[32];
	setcolor(WHITE);
	sprintf_s(str, 32, "%03d", time2 - (int)difftime(cur, begin));
	if (time2 - (int)difftime(cur, begin) > 0)
		outtextxy(670, 100, str);
}
void daotime3()
{
	cur = time(NULL);
	char str[32];
	setcolor(WHITE);
	sprintf_s(str, 32, "%03d", time3 - (int)difftime(cur, begin));
	if (time3 - (int)difftime(cur, begin) > 0)
		outtextxy(670, 100, str);
}
void daotime4()
{
	cur = time(NULL);
	char str[32];
	setcolor(WHITE);
	sprintf_s(str, 32, "%03d", time4 - (int)difftime(cur, begin));
	if (time4 - (int)difftime(cur, begin) > 0)
		outtextxy(670, 100, str);
}

void welcome()

{
	initgraph(1250, 900);


	setfont(40, 0, _T("微软雅黑"));  //设置文本的字体样式(高，宽（0表示自适应），字体）
	setcolor(WHITE); // 设置颜色
	outtextxy(550, 400, _T("记忆大师"));
	Sleep(2000);
	cleardevice();
	loadimage(&sm, "记忆图片\\sm.jpg", 1250, 900);
	loadimage(&over, "记忆图片\\over.png", 550, 130);
	putimage(0, 0, &sm);
	while (1)
	{

		m = GetMouseMsg();//获取当前鼠标信息
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 497 && m.x < 654 && m.y>693 && m.y < 744)
			{
				cleardevice(); return;
			}
		}
	}

}

void initGameScreen()
{
	loadimage(&card0, "记忆图片\\1.jpg", width, length);
	loadimage(&card[0], "记忆图片\\2.jpg", width, length);
	loadimage(&card[1], "记忆图片\\3.jpg", width, length);
	loadimage(&card[2], "记忆图片\\4.jpg", width, length);
	loadimage(&card[3], "记忆图片\\5.jpg", width, length);
	loadimage(&card[4], "记忆图片\\6.jpg", width, length);
	loadimage(&card[5], "记忆图片\\7.jpg", width, length);
	connect();		begin = time(NULL);
	rectangle(0, 0, 1250, 160);
	setfont(25, 0, _T("微软雅黑"));
	setcolor(WHITE);
	outtextxy(470, 20, _T("关卡："));
	outtextxy(660, 20, _T("第一关"));
	outtextxy(470, 100, _T("时间剩余："));
}
void initGameScreen2()
{
	loadimage(&card02, "记忆图片\\1.jpg", width2, length2);
	loadimage(&card2[0], "记忆图片\\2.jpg", width2, length2);
	loadimage(&card2[1], "记忆图片\\3.jpg", width2, length2);
	loadimage(&card2[2], "记忆图片\\4.jpg", width2, length2);
	loadimage(&card2[3], "记忆图片\\5.jpg", width2, length2);
	loadimage(&card2[4], "记忆图片\\6.jpg", width2, length2);
	loadimage(&card2[5], "记忆图片\\7.jpg", width2, length2);
	loadimage(&card2[6], "记忆图片\\8.jpg", width2, length2);
	loadimage(&card2[7], "记忆图片\\9.jpg", width2, length2);
	loadimage(&card2[8], "记忆图片\\10.jpg", width2, length2);
	loadimage(&card2[9], "记忆图片\\11.jpg", width2, length2);
	connect2();		begin = time(NULL);
	rectangle(0, 0, 1250, 160);
	setfont(25, 0, _T("微软雅黑"));
	setcolor(WHITE);
	outtextxy(470, 20, _T("关卡："));
	outtextxy(660, 20, _T("第二关"));
	outtextxy(470, 100, _T("时间剩余："));
}
void initGameScreen3()
{
	loadimage(&card03, "记忆图片\\1.jpg", width3, length3);
	loadimage(&card3[0], "记忆图片\\2.jpg", width3, length3);
	loadimage(&card3[1], "记忆图片\\3.jpg", width3, length3);
	loadimage(&card3[2], "记忆图片\\4.jpg", width3, length3);
	loadimage(&card3[3], "记忆图片\\5.jpg", width3, length3);
	loadimage(&card3[4], "记忆图片\\6.jpg", width3, length3);
	loadimage(&card3[5], "记忆图片\\7.jpg", width3, length3);
	loadimage(&card3[6], "记忆图片\\8.jpg", width3, length3);
	loadimage(&card3[7], "记忆图片\\9.jpg", width3, length3);
	loadimage(&card3[8], "记忆图片\\10.jpg", width3, length3);
	loadimage(&card3[9], "记忆图片\\11.jpg", width3, length3);
	loadimage(&card3[10], "记忆图片\\12.jpg", width3, length3);
	loadimage(&card3[11], "记忆图片\\13.jpg", width3, length3);
	loadimage(&card3[12], "记忆图片\\14.jpg", width3, length3);
	loadimage(&card3[13], "记忆图片\\clock.jpg", width3, length3);
	loadimage(&card3[14], "记忆图片\\pao.jpg", width3, length3);
	connect3();		begin = time(NULL);
	rectangle(0, 0, 1250, 160);
	setfont(25, 0, _T("微软雅黑"));
	setcolor(WHITE);
	outtextxy(470, 20, _T("关卡："));
	outtextxy(660, 20, _T("第三关"));
	outtextxy(470, 100, _T("时间剩余："));
}
void initGameScreen4()
{
	loadimage(&card04, "记忆图片\\1.jpg", width4, length4);
	loadimage(&card4[0], "记忆图片\\2.jpg", width4, length4);
	loadimage(&card4[1], "记忆图片\\3.jpg", width4, length4);
	loadimage(&card4[2], "记忆图片\\4.jpg", width4, length4);
	loadimage(&card4[3], "记忆图片\\5.jpg", width4, length4);
	loadimage(&card4[4], "记忆图片\\6.jpg", width4, length4);
	loadimage(&card4[5], "记忆图片\\7.jpg", width4, length4);
	loadimage(&card4[6], "记忆图片\\8.jpg", width4, length4);
	loadimage(&card4[7], "记忆图片\\9.jpg", width4, length4);
	loadimage(&card4[8], "记忆图片\\10.jpg", width4, length4);
	loadimage(&card4[9], "记忆图片\\11.jpg", width4, length4);
	loadimage(&card4[10], "记忆图片\\12.jpg", width4, length4);
	loadimage(&card4[11], "记忆图片\\13.jpg", width4, length4);
	loadimage(&card4[12], "记忆图片\\14.jpg", width4, length4);
	loadimage(&card4[13], "记忆图片\\clock.jpg", width4, length4);
	loadimage(&card4[14], "记忆图片\\15.png", width4, length4);
	loadimage(&card4[15], "记忆图片\\16.png", width4, length4);
	loadimage(&card4[16], "记忆图片\\17.png", width4, length4);
	loadimage(&card4[17], "记忆图片\\18.png", width4, length4);
	connect4();		begin = time(NULL);
	rectangle(0, 0, 1250, 160);
	setfont(25, 0, _T("微软雅黑"));
	setcolor(WHITE);
	outtextxy(470, 20, _T("关卡："));
	outtextxy(660, 20, _T("第四关"));
	outtextxy(470, 100, _T("时间剩余："));
}

void pao(IMAGE* p)
{
	if (p == &card3[14])
	{
		mciSendString("open 记忆图片\\提示前后.wav alias bingo", NULL, 0, NULL);
		mciSendString("play bingo", NULL, 0, NULL);
		for (i = 0; i < 30; i++)
		{
			if (c3[i].now == -1)
			{
				c3[i].now = 1;
			}
		}
		for (j = 0; j < 30; j++)
			change3(j);

		Sleep(3000);
		for (i = 0; i < 30; i++)
		{
			if (c3[i].now == 1)
			{
				c3[i].now = -1;
			}
		}
		for (j = 0; j < 30; j++)
			change3(j);
		mciSendString("close bingo", NULL, 0, NULL);
		mciSendString("open 记忆图片\\提示前后.wav alias bingo", NULL, 0, NULL);
		mciSendString("play bingo", NULL, 0, NULL);
	}
}
void boom(IMAGE* p)
{
	if (p == &card4[17])
	{
		mciSendString("open 记忆图片\\炸弹后.wav alias boom", NULL, 0, NULL);
		mciSendString("play boom", NULL, 0, NULL);
		Sleep(800);
		mciSendString("close boom", NULL, 0, NULL);
		for (i = 0; i < 36; i++)
			c4[i].now = -1;
		for (j = 0; j < 36; j++)
			change4(j);
	}
}
void addtime3(IMAGE* p)
{
	if (p == &card3[13])
		begin = begin + 10;
}
void addtime4(IMAGE* p)
{
	if (p == &card4[13])
		begin = begin + 10;
}
void guan4()
{
	cleardevice();
	initGameScreen4();
	for (i = 0; i < 36; i++)
		putimage(c4[i].x, c4[i].y, &card04);
	mciSendString("open 记忆图片\\加长心跳.wav alias heart", NULL, 0, NULL);
	mciSendString("play heart", NULL, 0, NULL);
	while (1)
	{
		if (MouseHit())
		{
			m = GetMouseMsg();//获取当前鼠标信息
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				for (j = 0; j < 36; j++) {
					if (m.x >= c4[j].x && m.x <= c4[j].x + width4 && m.y >= c4[j].y && m.y <= c4[j].y + length4 && c4[j].now == -1) {
						for (i = 0, sum = 0; i < 36; i++)
						{
							if (c4[i].now > 0)
							{
								sum += c4[i].now; flag = i;
							}
						}
						if (sum == 0) { c4[j].now = 1; change4(j); }
						else if (sum == 1)
						{
							c4[j].now = 1; change4(j);
							if (pai4[flag] == pai4[j])
							{
								mciSendString("close xiao", NULL, 0, NULL);
								mciSendString("open 记忆图片\\消除.mp3 alias xiao", NULL, 0, NULL);
								mciSendString("play xiao", NULL, 0, NULL);
								Sleep(500); c4[j].now = 0; c4[flag].now = 0; for (j = 0; j < 36; j++) change4(j);
								addtime4(pai4[flag]);
								if (c4[0].now == 0 && c4[1].now == 0 && c4[2].now == 0 && c4[3].now == 0 && c4[4].now == 0
									&& c4[5].now == 0 && c4[6].now == 0 && c4[7].now == 0 && c4[8].now == 0 &&
									c4[9].now == 0 && c4[10].now == 0 && c4[11].now == 0 && c4[12].now == 0 &&
									c4[13].now == 0 && c4[14].now == 0 && c4[15].now == 0 && c4[16].now == 0 &&
									c4[17].now == 0 && c4[18].now == 0 && c4[19].now == 0 && c4[20].now == 0
									&& c4[21].now == 0 && c4[22].now == 0 && c4[23].now == 0 && c4[24].now == 0 && c4[25].now == 0
									&& c4[26].now == 0 && c4[27].now == 0 && c4[28].now == 0 && c4[29].now == 0 && c4[30].now == 0
									&& c4[31].now == 0 && c4[32].now == 0 && c4[33].now == 0 && c4[34].now == 0 && c4[35].now == 0)
								{
									mciSendString("close heart", NULL, 0, NULL);
									mciSendString("close guo", NULL, 0, NULL);
									mciSendString("open 记忆图片\\过关.mp3 alias guo", NULL, 0, NULL);
									mciSendString("play guo", NULL, 0, NULL);
									outtextxy(550, 400, _T("恭喜过关！")); Sleep(1000); return;
								}
								boom(pai4[flag]);
							}
						}
					}

					else if (m.x >= c4[j].x && m.x <= c4[j].x + width4 && m.y >= c4[j].y && m.y <= c4[j].y + length4 && c4[j].now == 1) {
						c4[j].now = -1; change4(j);

					}
				}
			}


		}
		daotime4();
		if (time4 - (int)difftime(cur, begin) == 0)
		{
			cleardevice();
			putimage(375, 220, &over);
			mciSendString("close heart", NULL, 0, NULL);
			mciSendString("open 记忆图片\\失败.wav alias shu", NULL, 0, NULL);
			mciSendString("play shu", NULL, 0, NULL);
			setfont(50, 0, _T("微软雅黑"));
			outtextxy(560, 400, _T("再来一次"));
			while (1)
			{

				m = GetMouseMsg();//获取当前鼠标信息
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (m.x > 560 && m.x < 760 && m.y>400 && m.y < 450)
					{
						mciSendString("close shu", NULL, 0, NULL); guan4();
					}
				}
			}
		}
	}
}

void guan3()
{
	cleardevice();
	initGameScreen3();
	for (i = 0; i < 30; i++)
		putimage(c3[i].x, c3[i].y, &card03);
	mciSendString("open 记忆图片\\加长心跳.wav alias heart", NULL, 0, NULL);
	mciSendString("play heart", NULL, 0, NULL);
	while (1)
	{
		if (MouseHit())
		{
			m = GetMouseMsg();//获取当前鼠标信息
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				for (j = 0; j < 30; j++) {
					if (m.x >= c3[j].x && m.x <= c3[j].x + width3 && m.y >= c3[j].y && m.y <= c3[j].y + length3 && c3[j].now == -1) {
						for (i = 0, sum = 0; i < 30; i++)
						{
							if (c3[i].now > 0)
							{
								sum += c3[i].now; flag = i;
							}
						}
						if (sum == 0) { c3[j].now = 1; change3(j); }
						else if (sum == 1)
						{
							c3[j].now = 1; change3(j);
							if (pai3[flag] == pai3[j])
							{
								mciSendString("close xiao", NULL, 0, NULL);
								mciSendString("open 记忆图片\\消除.mp3 alias xiao", NULL, 0, NULL);
								mciSendString("play xiao", NULL, 0, NULL);
								Sleep(500); c3[j].now = 0; c3[flag].now = 0; for (j = 0; j < 30; j++) change3(j);
								pao(pai3[flag]);
								addtime3(pai3[flag]);
								if (c3[0].now == 0 && c3[1].now == 0 && c3[2].now == 0 && c3[3].now == 0 && c3[4].now == 0
									&& c3[5].now == 0 && c3[6].now == 0 && c3[7].now == 0 && c3[8].now == 0 &&
									c3[9].now == 0 && c3[10].now == 0 && c3[11].now == 0 && c3[12].now == 0 &&
									c3[13].now == 0 && c3[14].now == 0 && c3[15].now == 0 && c3[16].now == 0 &&
									c3[17].now == 0 && c3[18].now == 0 && c3[19].now == 0 && c3[20].now == 0
									&& c3[21].now == 0 && c3[22].now == 0 && c3[23].now == 0 && c3[24].now == 0 && c3[25].now == 0
									&& c3[26].now == 0 && c3[27].now == 0 && c3[28].now == 0 && c3[29].now == 0)
								{
									mciSendString("close heart", NULL, 0, NULL);
									mciSendString("close guo", NULL, 0, NULL);
									mciSendString("open 记忆图片\\过关.mp3 alias guo", NULL, 0, NULL);
									mciSendString("play guo", NULL, 0, NULL);
									outtextxy(550, 400, _T("恭喜过关！"));
									outtextxy(560, 440, _T("下一关"));
									Sleep(1000);
									while (1)
									{

										m = GetMouseMsg();//获取当前鼠标信息
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											if (m.x > 560 && m.x < 710 && m.y>440 && m.y < 490)
												guan4();
										}
									}return;
								}
							}
						}
					}

					else if (m.x >= c3[j].x && m.x <= c3[j].x + width3 && m.y >= c3[j].y && m.y <= c3[j].y + length3 && c3[j].now == 1) {
						c3[j].now = -1; change3(j);

					}
				}
			}


		}
		daotime3();
		if (time3 - (int)difftime(cur, begin) == 0)
		{
			cleardevice();
			mciSendString("close heart", NULL, 0, NULL);
			mciSendString("open 记忆图片\\失败.wav alias shu", NULL, 0, NULL);
			mciSendString("play shu", NULL, 0, NULL);
			putimage(375, 220, &over);
			setfont(50, 0, _T("微软雅黑"));
			outtextxy(560, 400, _T("再来一次"));
			while (1)
			{

				m = GetMouseMsg();//获取当前鼠标信息
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (m.x > 560 && m.x < 760 && m.y>400 && m.y < 450)
					{
						mciSendString("close shu", NULL, 0, NULL);
						guan3();
					}
				}
			}
		}
	}
}
void guan2()
{
	cleardevice();
	initGameScreen2();
	for (i = 0; i < 20; i++)
		putimage(c2[i].x, c2[i].y, &card02);
	mciSendString("open 记忆图片\\加长心跳.wav alias heart", NULL, 0, NULL);
	mciSendString("play heart", NULL, 0, NULL);
	while (1)
	{
		if (MouseHit()) {
			m = GetMouseMsg();//获取当前鼠标信息
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				for (j = 0; j < 20; j++) {
					if (m.x >= c2[j].x && m.x <= c2[j].x + width2 && m.y >= c2[j].y && m.y <= c2[j].y + length2 && c2[j].now == -1) {
						for (i = 0, sum = 0; i < 20; i++)
						{
							if (c2[i].now > 0)
							{
								sum += c2[i].now; flag = i;
							}
						}
						if (sum == 0) { c2[j].now = 1; change2(j); }
						else if (sum == 1)
						{
							c2[j].now = 1; change2(j);
							if (pai2[flag] == pai2[j])
							{
								mciSendString("close xiao", NULL, 0, NULL);
								mciSendString("open 记忆图片\\消除.mp3 alias xiao", NULL, 0, NULL);
								mciSendString("play xiao", NULL, 0, NULL);
								Sleep(500); c2[j].now = 0; c2[flag].now = 0; for (j = 0; j < 20; j++) change2(j);
								if (c2[0].now == 0 && c2[1].now == 0 && c2[2].now == 0 && c2[3].now == 0 && c2[4].now == 0
									&& c2[5].now == 0 && c2[6].now == 0 && c2[7].now == 0 && c2[8].now == 0 &&
									c2[9].now == 0 && c2[10].now == 0 && c2[11].now == 0 && c2[12].now == 0 &&
									c2[13].now == 0 && c2[14].now == 0 && c2[15].now == 0 && c2[16].now == 0 &&
									c2[17].now == 0 && c2[18].now == 0 && c2[19].now == 0)
								{
									mciSendString("close heart", NULL, 0, NULL);
									mciSendString("close guo", NULL, 0, NULL);
									mciSendString("open 记忆图片\\过关.mp3 alias guo", NULL, 0, NULL);
									mciSendString("play guo", NULL, 0, NULL);
									outtextxy(550, 400, _T("恭喜过关！"));
									outtextxy(560, 440, _T("下一关"));
									Sleep(1000);
									while (1)
									{

										m = GetMouseMsg();//获取当前鼠标信息
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											if (m.x > 560 && m.x < 710 && m.y>440 && m.y < 490)
												guan3();
										}
									}return;
								}
							}
						}
					}

					else if (m.x >= c2[j].x && m.x <= c2[j].x + width2 && m.y >= c2[j].y && m.y <= c2[j].y + length2 && c2[j].now == 1) {
						c2[j].now = -1; change2(j);

					}
				}
			}


		}
		daotime2();
		if (time2 - (int)difftime(cur, begin) == 0)
		{
			cleardevice();
			mciSendString("close heart", NULL, 0, NULL);
			mciSendString("open 记忆图片\\失败.wav alias shu", NULL, 0, NULL);
			mciSendString("play shu", NULL, 0, NULL);
			putimage(375, 220, &over);
			setfont(50, 0, _T("微软雅黑"));
			outtextxy(560, 400, _T("再来一次"));
			while (1)
			{

				m = GetMouseMsg();//获取当前鼠标信息
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (m.x > 560 && m.x < 760 && m.y>400 && m.y < 450)
					{
						mciSendString("close shu", NULL, 0, NULL);
						guan2();
					}
				}
			}
		}
	}
}

void guan1()
{
	cleardevice();
	initGameScreen();
	for (i = 0; i < 12; i++)
		putimage(c[i].x, c[i].y, &card0);
	mciSendString("open 记忆图片\\加长心跳.wav alias heart", NULL, 0, NULL);
	mciSendString("open 记忆图片\\消除.mp3 alias xiao", NULL, 0, NULL);
	mciSendString("play heart", NULL, 0, NULL);
	while (1)
	{
		if (MouseHit()) {
			m = GetMouseMsg();//获取当前鼠标信息
			switch (m.uMsg)
			{
			case WM_LBUTTONDOWN:
				for (j = 0; j < 12; j++)
				{
					if (m.x >= c[j].x && m.x <= c[j].x + width && m.y >= c[j].y && m.y <= c[j].y + length && c[j].now == -1)
					{
						for (i = 0, sum = 0; i < 12; i++)
						{
							if (c[i].now > 0)
							{
								sum += c[i].now; flag = i;
							}
						}
						if (sum == 0) { c[j].now = 1; change(j); }
						else if (sum == 1)
						{
							c[j].now = 1; change(j);
							if (pai[flag] == pai[j])
							{
								mciSendString("close xiao", NULL, 0, NULL);
								mciSendString("open 记忆图片\\消除.mp3 alias xiao", NULL, 0, NULL);
								mciSendString("play xiao", NULL, 0, NULL);
								Sleep(500); c[j].now = 0; c[flag].now = 0; for (j = 0; j < 12; j++) change(j);
								if (c[0].now == 0 && c[1].now == 0 && c[2].now == 0 && c[3].now == 0 && c[4].now == 0 &&
									c[5].now == 0 && c[6].now == 0 &&
									c[7].now == 0 && c[8].now == 0 && c[9].now == 0 && c[10].now == 0 && c[11].now == 0)
								{
									mciSendString("close heart", NULL, 0, NULL);
									mciSendString("open 记忆图片\\过关.mp3 alias guo", NULL, 0, NULL);
									mciSendString("play guo", NULL, 0, NULL);
									outtextxy(550, 400, _T("恭喜过关！"));
									outtextxy(560, 440, _T("下一关"));
									Sleep(1000);
									while (1)
									{

										m = GetMouseMsg();//获取当前鼠标信息
										if (m.uMsg == WM_LBUTTONDOWN)
										{
											if (m.x > 560 && m.x < 710 && m.y>440 && m.y < 490)
												guan2();
										}
									}return;
								}
							}
						}
					}

					else if (m.x >= c[j].x && m.x <= c[j].x + width && m.y >= c[j].y && m.y <= c[j].y + length && c[j].now == 1) {
						c[j].now = -1; change(j);

					}
				}
			}


		}
		daotime();
		if (time1 - (int)difftime(cur, begin) == 0)
		{						
			mciSendString("close heart", NULL, 0, NULL);
			mciSendString("open 记忆图片\\失败.wav alias shu", NULL, 0, NULL);
			mciSendString("play shu", NULL, 0, NULL);
			cleardevice();
			putimage(375, 220, &over);
			setfont(50, 0, _T("微软雅黑"));
			outtextxy(560, 400, _T("再来一次"));
			while (1)
			{

				m = GetMouseMsg();//获取当前鼠标信息
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (m.x > 560 && m.x < 760 && m.y>400 && m.y < 450)
					{
						mciSendString("close shu", NULL, 0, NULL); guan1(); return;
					}
				}
			}
		}
	}
}

int main()
{
	welcome();
	guan1();
	system("pause");

}


