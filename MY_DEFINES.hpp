/*------------------------------------------------------------------------------------------*\
   This file is built by Hanss401:

   TO DO: c_plus_plus main include/define/typedef/useful functions/constants;

   Change Log:
   ---Version 0.10---
       ---Hanss401:
           Add some useful functons and so on;
           2019.11.1 22:30;
   ---Version 0.11---
       ---Hanss401:
           Add some useful #defines;
           2019.11.2 08:54;         
   ---Version 0.12---
       ---Hanss401:
           Add some useful #defines functions;
           2019.11.5 20:33;                 
   
\*------------------------------------------------------------------------------------------*/

// ================= includes ======================

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <functional>
#include <random>

// ================= defines ======================

#define MONOTONICALLY_INC_CYCLE_CLOSE(i,a,n) for(int i=a;i<=n;++i)
#define MONOTONICALLY_DEC_CYCLE_CLOSE(i,a,n) for(int i=a;i>=n;--i)

#define MONOTONICALLY_INC_CYCLE_OPEN(i,a,n) for(int i=a;i<n;++i)
#define MONOTONICALLY_DEC_CYCLE_OPEN(i,a,n) for(int i=a;i>n;--i)

#define LOOP_WHILE(x) while(x)

#define PRINT_10_SPACES putchar(10)

#define lc (o<<1)
#define rc (lc|1)

#define BIGGER(a,b) a>b?a:b
#define SMALLER(a,b) a<b?a:b

#define ASSIGNMENT_INTEGER(x) scanf("%d",&x);




// ================= typedef and constants ======================

typedef long long LLONG_INT;
typedef pair<int,int> INT_PAIR;
const int BIGPRIME_NUM = 1e9+7, INF_BIG_NUM = 0x3f3f3f3f;
const double INF_SMALL_NUM=1e-10;



// ================= functions ======================

LLONG_INT GCD_NUM(LLONG_INT a, LLONG_INT b)
{
    return b?gcd(b,a%b):a;
}

LLONG_INT POW_NUM(LLONG_INT a,LLONG_INT n) 
{
  LLONG_INT r=1%BIGPRIME_NUM;
  for (a%=BIGPRIME_NUM;n;a=a*a%BIGPRIME_NUM,n>>=1)if(n&1)r=r*a%BIGPRIME_NUM;
  return r;
}

LLONG_INT INV_NUM(LLONG_INT x)
{
  return x<=1?1:inv(BIGPRIME_NUM%x)*(BIGPRIME_NUM-BIGPRIME_NUM/x)%BIGPRIME_NUM;
}

// mod computation
LLONG_INT MOD(LLONG_INT x,LLONG_INT m){return x%m;}
LLONG_INT MOD_ADD(LLONG_INT x,LLONG_INT y,LLONG_INT m){return MOD(x+y,m);}
LLONG_INT MOD_MUL(LLONG_INT x,LLONG_INT y,LLONG_INT m){return MOD(x*y,m);}

// ================= structs ======================


// point
class POINT{
    public:
        double x,y;
        POINT(double x=0,double y=0):x(x),y(y){}
        POINT operator + (POINT p){return POINT(x+p.x,y+p.y);   }
        POINT operator - (POINT p){return POINT(x-p.x,y-p.y);   }
        double operator*(POINT p){return x*p.x+y*p.y;   }  //inner product a.b;
        double operator^(POINT p){return x*p.y-y*p.x;   }  //out   product aXb;
        double abs(){return sqrt(x*x+y*y);  }
        bool operator< (const POINT &q) const{return x!=q.x?x<q.x:y<q.y;}
        bool operator==(const POINT &q) const{return fabs(x-q.x)<EPS&&fabs(y-q.y)<EPS;}
};

double distance(POINT a,POINT b)
{
    return (double)sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
} // distance of two points;

// ================= classes =========================

