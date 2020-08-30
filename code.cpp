#include<bits/stdc++.h>
using namespace std;   
bool custom_sort(double a, double b)
{
    double  a1=abs(a-0);
    double  b1=abs(b-0);
    return a1<b1;
}
int main()
{
/*Intialization Phase*/
double x1[] = {2.5, 1.5, 3.5, 1, 3, 7.5 , 5 , 7 , 8.5 , 6};                          
double x2[] = {2.5 , 2.3 , 4.4 ,1.9 , 3 , 2.7 , 2 , 1.7 , 0 , 3.508563011};
double y[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
 
vector<double>error; 
double err;
double b0 = 0;
double b1 = 0;
double b2=  0; 
double alpha = 0.01;
double  e = 2.71828;
  
/*Training Phase*/
for (int i = 0; i < 40; i ++) { 
    int idx = i % 10;
    double p = -(b0 + b1 * x1[idx]+ b2* x2[idx]);
    double pred  = 1/(1+ pow(e,p));
    err = y[idx]-pred;
    b0 = b0 - alpha * err*pred *(1-pred)* 1.0;
    b1 = b1 + alpha * err * pred*(1-pred) *x1[idx];
    b2 = b2 + alpha * err * pred*(1-pred) * x2[idx];
    cout<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"B2="<<b2<<" error="<<err<<endl;
    error.push_back(err);
    }
sort(error.begin(),error.end(),custom_sort);
cout<<"Final Values are: "<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"B2="<<b2<<" error="<<error[0];
  
/*Testing Phase*/
double test1,test2;
cin>>test1>>test2;
double pred=b0+b1*test1+b2*test2;
cout<<"The value predicted by the model= "<<pred<<endl;
if(pred>0.5)
pred=1;
else
pred=0;
cout<<"The class predicted by the model= "<<pred;
}