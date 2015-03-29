#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
bool is_leap_year(int y)
{
    if(y%4==0)
    {
        if(y%100==0)
        {
            if(y%400==0)
                return true;
            return false;
        }
        return true;
    }
    return false;
}
int the_month(string a)
{
    if(a=="January")
        return 1;
    if(a=="February")
        return 2;
    if(a=="March")
        return 3;
    if(a=="April")
        return 4;
    if(a=="May")
        return 5;
    if(a=="June")
        return 6;
    if(a=="July")
        return 7;
    if(a=="August")
        return 8;
    if(a=="September")
        return 9;
    if(a=="October")
        return 10;
    if(a=="November")
        return 11;
    if(a=="December")
        return 12;
    else
        return 0;
}
int main()
{
    int ii,t;
    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        string str1,str2;
        int date1,date2;
        int year1,year2;
        
        cin>>str1;
        cin>>date1;
        getchar();
        cin>>year1;
        
        cin>>str2;
        cin>>date2;
        getchar();
        cin>>year2;
        
        int month1=the_month(str1);
        int month2=the_month(str2);
        
        int ans=(year2-year1)/400*97;
        
        year1%=400;
        year2%=400;
        
        year1+=400;
        year2+=400;
        
        if(year1>year2)
            year2+=400;
        
        for(int i=year1;i<=year2;i++)
            if(is_leap_year(i))
                ans++;
        
        if(is_leap_year(year1)&&month1>=3)
            ans--;
        
        if(is_leap_year(year2))
        {
            if(month2==1)
                ans--;
            if(month2==2&&date2<=28)
                ans--;
        }
        
        cout<<"Case "<<ii<<": "<<ans<<endl;
    }
    return 0;
}