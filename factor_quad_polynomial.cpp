#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool is_value_integer(float value);

// If the square root symbol is not printing correctly then try commenting out 11 and removing the line comment in 10.

//char sqrt_symbol = 251;
string sqrt_symbol = "\u221a";

int main(){
    int a=0,b=0,c=0;
    cout<<"Enter the coefficients of the polynomial : \n";
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<"c = ";
    cin>>c;
    float f = pow(b,2)-4*a*c;
    int d = pow(b,2)-4*a*c;
    
    //cout<<f<<endl;
    float D = sqrt(d);
    float x_1 = (-b + D)/(2*a);
    float x_2 = (-b - D)/(2*a);

    int int_x_1=static_cast<int>(round(x_1));
    int int_x_2=static_cast<int>(round(x_2));
 
    //check whether the values of x are integer or not;
    bool is_int=true;
    if(x_1!=(float)int_x_1 || x_2!=(float)int_x_2){
        //cout<<"Not Integer!!";
        is_int=false;
    }
    
    //else cout<<"Interger!!!!\n";
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
    // cout<<x_1<<endl;
    // cout<<x_2<<endl;

    if(d<0)cout<<"No real factors exist.";
    else if(is_int==true){
        if(x_1<0)cout<<"The factors are (x + "<< -x_1 <<")";
        else cout<<"The factors are (x - "<< x_1 <<")";
        if(x_2<0)cout<<" and (x + "<< -x_2 <<")";
        else cout<<" and (x - "<< x_2 <<")";
    }
    else if(is_int==false && is_value_integer(D)==true){
        if(b - D>0)cout<<"The factors are (x - "<< (b - D);
        else cout<<"The factors are (x + "<< -(b - D);
        if(b + D>0)cout<<")/"<< 2*a <<") and (x - "<< (b + D)<<")/"<< 2*a <<")";
        else cout<<")/"<< 2*a <<") and (x + "<< -(b + D)<<")/"<< 2*a <<")";
    }
    else if(is_int==false && is_value_integer(D)==false){
        if(b>0)cout<<"The factors are [x - ("<< b <<" - "<<sqrt_symbol<< f <<")/"<< 2*a <<"] and [x - ("<< b <<" + "<<sqrt_symbol<< f <<")/"<< 2*a <<"]";
        else cout<<"The factors are [x + ("<< -b <<" + "<<sqrt_symbol<< f <<")/"<< 2*a <<"] and [x + ("<< -b <<" - "<<sqrt_symbol<< f <<")/"<< 2*a <<"]";
    }
    return 0;
}

bool is_value_integer(float value){
    return (value == static_cast<int>(value));
}
