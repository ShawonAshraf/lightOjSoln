#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

#define PI (2*acos(0.0))

using namespace std;

struct point
{
    double x,y;
};


double Distance(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}


int main()
{
    int t;
    
    scanf("%d",&t);
    
    for (int i = 1; i <= t; i++) {
    
        point A,B,O;
        double a,b,c;
        
        scanf("%lf%lf%lf%lf%lf%lf",&O.x,&O.y,&A.x,&A.y,&B.x,&B.y);
        
        a = Distance(O,A);
        b = Distance(O,B);
        c = Distance(A,B);
        
        double ans = (a + b - c) / (2 * sqrt(a*b));
        
        ans = acos(ans);
        
        double r = ans * sqrt(a);
        
        printf("Case %d: %lf\n", i, r);
    }
    return 0;
}