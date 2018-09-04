#include <stdio.h>  
int main()  
{  
    int sum=0;  
    for(int a=1; a<=9; a++)  
        for(int b=1; b<=9; b++)  
        {  
            if(a==b) continue;  
            for(int c=1; c<=9; c++)  
            {  
                if(c==a||c==b) continue;  
                for(int d=1; d<=9; d++)  
                {  
                    if(d==a||d==b||d==c)continue;  
                    for(int e=1; e<=9; e++)  
                    {  
                        if(e==a||e==b||e==c||e==d) continue;  
                        for(int f=1; f<=9; f++)  
                        {  
                            if(f==a||f==b||f==c||f==d||f==e) continue;  
                            for(int g=1; g<=9; g++)  
                            {  
                                if(g==a||g==b||g==c||g==d||g==e||g==f) continue;  
                                for(int h=1; h<=9; h++)  
                                {  
                                    if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;  
                                    for(int i=1; i<=9; i++)  
                                    {  
                                        if(i==a||i==b||i==c||i==d||i==e||i==f||i==g||i==h) continue;  
                                        int t1=a*c*(100*g+10*h+i);  
                                        int t2=b*(100*g+10*h+i);  
                                        int t3=c*(100*d+10*e+f);  
                                        int t4=10*c*(100*g+10*h+i);  
                                        if(t1+t2+t3==t4)  
                                            sum++;  
                                    }  
                                }  
                            }  
                        }  
                    }  
                }  
            }  
        }  
  
    printf("%d",sum);  
    return 0;  
}  
