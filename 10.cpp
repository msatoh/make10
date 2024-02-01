#include<float.h>
#include<stdlib.h>
#include<list>
#include<iostream>
using namespace std;
enum style {mono,poly};

class Result{
public:
  double val;
  enum style form=mono;
  string str;
};

double calculate(int op,double param1, double param2){
  if(op==0)
    return param1+param2;
  else if(op==1)
    return param1-param2;
  else if(op==2)
    return param1*param2;
  else if(op==3)
    return param1/param2;
  else
    return 0;
}

string print_op(int op){
  switch (op){
  case 0:
    return "+";
  case 1:
    return "-";
  case 2:
    return "*";
  case 3:
    return "/";
  default:
    return "";
  }
}

double ref(list<double> lst,int i){
  list<double>::iterator itr=lst.begin();
  int j;
  for(j=0;j<i;j++){
    itr++;
  }
  return *itr;
}

list<double> pick(list<double> lst,int i){
  list<double>::iterator itr=lst.begin();
  int j;
  for(j=0;j<i;j++){
    itr++;
  }
  lst.erase(itr);
  return lst;
}

int main(int argc,char *argv[]){
  double num1,num2,num3,num4;
  auto res1=Result();
  auto res2=Result();
  auto res3=Result();
  int i,j,k,s,t,u,a,b,c;
  list<double> li={double(atoi(argv[1])),double(atoi(argv[2])),double(atoi(argv[3])),double(atoi(argv[4]))};
  list<double> li1,li2;
  for(i=0;i<4;i++){
    num1=ref(li,i);
    li1=pick(li,i);
    for(j=0;j<3;j++){
      num2=ref(li1,j);
      li2=pick(li1,j);
      for(k=0;k<2;k++){
        num3=ref(li2,k);
        num4=ref(li2,(k+1)%2);
        for(s=0;s<4;s++){
          for(t=0;t<4;t++){
            for(u=0;u<4;u++){
              for(a=0;a<2;a++){
                if(s<2){
                  res1.form=poly;
                }
                if(a==0){
                  res1.val=calculate(s,num1,num2);
                  res1.str=to_string((int)num1)+print_op(s)+to_string((int)num2);
                }else{
                  res1.val=calculate(s,num2,num1);
                  res1.str=to_string((int)num2)+print_op(s)+to_string((int)num1);
                }
                for(b=0;b<2;b++){
                  if(t<2){
                    res2.form=poly;
                  }else if(res1.form==poly){
                    res1.str="("+res1.str+")";
                  }
                  if(b==0){
                    res2.val=calculate(t,res1.val,num3);
                    res2.str=res1.str+print_op(t)+to_string((int)num3);
                  }else{
                    res2.val=calculate(t,num3,res1.val);
                    res2.str=to_string((int)num3)+print_op(t)+res1.str;
                  }
                  for(c=0;c<2;c++){
                    if(u>1&&res2.form==poly){
                      res2.str="("+res2.str+")";
                    }
                    if(c==0){
                      res3.val=calculate(u,res2.val,num4);
                      res3.str=res2.str+print_op(t)+to_string((int)num4);
                    }else{
                      res3.val=calculate(u,num4,res2.val);
                      res2.str=to_string((int)num4)+print_op(t)+res2.str;
                    }
                  }
                }
              }
              if(res3.val-10==0){
                /*if(a==0){
                  cout<<num1<<print_op(s)<<num2<<"="<<res1.val<<", ";
                }
                else{
                  cout<<num2<<print_op(s)<<num1<<"="<<res1.val<<", ";
                }
                if(b==0){
                  cout<<res1.val<<print_op(t)<<num3<<"="<<res2.val<<", ";
                }
                else{
                  cout<<num3<<print_op(t)<<res1.val<<"="<<res2.val<<", ";
                }
                if(c==0){
                  cout<<res2.val<<print_op(u)<<num4<<"="<<res3.val<<endl;
                }
                else{
                  cout<<num4<<print_op(u)<<res2.val<<"="<<res3.val<<endl;
                }*/
                cout<<res3.str<<"=10"<<endl;
                return 1;
              }
            }
          } 
        }
      }
    } 
  }
  cout<<"not found."<<endl;
  return 0;
}
