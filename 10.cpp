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
  switch(op){
  case 0:
    return param1+param2;
  case 1:
    return param1-param2;
  case 2:
    return param1*param2;
  case 3:
    return param1/param2;
  default:
    return 0;
  }
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

void ans(double w,double x,double y,double z){
  int i,j,k,s,t,u,a,b,c,tournament;
  double num1,num2,num3,num4;
  list<double> li={w,x,y,z};
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
              auto res1=Result();
              auto res2=Result();
              auto res3=Result();
              for(tournament=0;tournament<3;tournament++){
                switch(tournament){
                case 0:
                  if(s<2&&t<2&&u>1){
                    for(a=0;a<2;a++){
                      if(a==0){
                        res1.val=calculate(s,num1,num2);
                        res1.str="("+to_string((int)num1)+print_op(s)+to_string((int)num2)+")";
                      }else{
                        res1.val=calculate(s,num2,num1);
                        res1.str="("+to_string((int)num2)+print_op(s)+to_string((int)num1)+")";
                      }
                      for(b=0;b<2;b++){
                        if(b==0){
                          res2.val=calculate(t,num3,num4);
                          res2.str="("+to_string((int)num3)+print_op(t)+to_string((int)num4)+")";
                        }else{
                          res2.val=calculate(t,num4,num3);
                          res2.str="("+to_string((int)num4)+print_op(t)+to_string((int)num3)+")";
                        }
                        for(c=0;c<2;c++){
                          if(c==0){
                            res3.val=calculate(u,res1.val,res2.val);
                            res3.str=res1.str+print_op(u)+res2.str;
                          }else{
                            res3.val=calculate(u,res2.val,res1.val);
                            res3.str=res2.str+print_op(u)+res1.str;
                          }
                          if(res3.val-10==0){
                            cout<<res3.str<<"="<<res3.val<<endl;
                            return;
                          }
                        }
                      }
                    }
                  }else{
                    break;
                  }
                  break;
                case 1:
                  if(s>1&&t>1&&u<2){
                    for(a=0;a<2;a++){
                      if(a==0){
                        res1.val=calculate(s,num1,num2);
                        res1.str=to_string((int)num1)+print_op(s)+to_string((int)num2);
                      }else{
                        res1.val=calculate(s,num2,num1);
                        res1.str=to_string((int)num2)+print_op(s)+to_string((int)num1);
                      }
                      for(b=0;b<2;b++){
                        if(b==0){
                          res2.val=calculate(t,num3,num4);
                          res2.str=to_string((int)num3)+print_op(t)+to_string((int)num4);
                        }else{
                          res2.val=calculate(t,num4,num3);
                          res2.str=to_string((int)num4)+print_op(t)+to_string((int)num3);
                        }
                        for(c=0;c<2;c++){
                          if(c==0){
                            res3.val=calculate(u,res1.val,res2.val);
                            res3.str=res1.str+print_op(u)+res2.str;
                          }else{
                            res3.val=calculate(u,res2.val,res1.val);
                            res3.str=res2.str+print_op(u)+res1.str;
                          }
                          if(res3.val-10==0){
                            cout<<res3.str<<"="<<res3.val<<endl;
                            return;
                          }
                        }
                      }
                    }
                  }else{
                    break;
                  }
                  break;
                default:
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
                        res1.form=mono;
                      }
                      if(b==0){
                        res2.val=calculate(t,res1.val,num3);
                        res2.str=res1.str+print_op(t)+to_string((int)num3);
                      }else{
                        if((t==3&&s>1)||(t==1&&s<2)){
                          break;
                        }else{
                          res2.val=calculate(t,num3,res1.val);
                          res2.str=to_string((int)num3)+print_op(t)+res1.str;
                        }
                      }
                      for(c=0;c<2;c++){
                        if(u>1&&res2.form==poly){
                          res2.str="("+res2.str+")";
                          res2.form=mono;
                        }
                        if(c==0){
                          res3.val=calculate(u,res2.val,num4);
                          res3.str=res2.str+print_op(u)+to_string((int)num4);
                        }else{
                          if((u==3&&t>1)||(u==1&&t<2)){
                            break;
                          }else{
                            res3.val=calculate(u,num4,res2.val);
                            res3.str=to_string((int)num4)+print_op(u)+res2.str;
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
                          cout<<res3.str<<"="<<res3.val<<endl;
                          return;
                        }
                      }
                    }
                  }
                }
              }
            }
          } 
        }
      }
    } 
  }
  cout<<"not found."<<endl;
}

int main(int argc,char *argv[]){
  int w,x,y,z;
  //list<double> li={double(atoi(argv[1])),double(atoi(argv[2])),double(atoi(argv[3])),double(atoi(argv[4]))};
  if(argc==5){
    ans(double(atoi(argv[1])),double(atoi(argv[2])),double(atoi(argv[3])),double(atoi(argv[4])));
  }else{
    for(w=1;w<10;w++){
      for(x=w+1;x<10;x++){
        for(y=x+1;y<10;y++){
          for(z=y+1;z<10;z++){
            ans(w,x,y,z);
          }
        }
      }
    }
  }
  return 0;
}
