/* Problem
   AB
  -CD
  ---
   EF
  +GH
  ---
  PPP
Each letter is unique and E+H must has a carry out, so P = 1 -> F+H = 11, E+G = 10


Used backtracking. I chained up each operation on a digit, so lots of copy and pasting similar codes.
May be able to factor them out.

Alternative: There may be a concise recursion way of expressing the same thing.

*/

#include <iostream>
#include <cstdio>
#include <list>

bool bt_c(std::list<int> list, int e, int a){
  int c;
  bool flag = false;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    c = (*it);
    if( a-c == e){
      printf("a:  %d, c:  %d\n", a, c); 
      flag = true;
    }
  }
  return flag;
}

bool bt_a(std::list<int> list, int e){
  int a;
  bool flag = false;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    a = (*it);
    it = list.erase(it);
    if( bt_c(list, e,a) )
      flag = true;
    it = list.insert(it, a);
  }
  return flag;
}

bool bt_d(std::list<int> list, int e, int f, int b){
  int d;
  bool flag = false;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    d = (*it);
    if( b - d == f){
      it = list.erase(it);
      if(bt_a(list, e)){
        printf("b:  %d, d:  %d\n", b, d);
        flag = true;
      }
      it = list.insert(it, d); 
    }
  }
  return flag;
}

bool bt_b(std::list<int> list, int e, int f){
  int b;
  bool flag = false;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    b = (*it);       
    if( b >= f){
      it = list.erase(it);
      if( bt_d(list, e,f, b)){
        flag = true;
      }
      it = list.insert(it,b);
    }
  }
  return flag;
}

bool bt_g(std::list<int> list, int e, int f){
  int g;
  bool flag = false;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    g = (*it);
    if( e + g == 10 ){
      it = list.erase(it);
      if( bt_b(list, e, f ) ) {
        printf("e:  %d, g:  %d\n", e, g);
        flag = true;
      }
      it = list.insert(it, g);
    }
  }
  return flag;
}

bool bt_e(std::list<int> list, int f){
  int e;
  bool flag = false;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    e = (*it);
    it = list.erase(it); // remove the currently in use digit
    if(bt_g(list, e, f))
      flag = true;
    it = list.insert(it,e); // put it back   
  }
  return flag;
}

bool bt_h(std::list<int> list, int f){
  int h;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    h = (*it);
    if( f + h == 11 ){
      it = list.erase(it);
      if(bt_e(list,f))    
        printf("------\nf:  %d, h:  %d\n\n", f, h);
      it = list.insert(it, h);
    }
  }
}

bool bt(std::list<int> list){
  int f;
  for(std::list<int>::iterator it = list.begin(); it != list.end(); it++){
    f = (*it);
    it = list.erase(it); // remove the currently in use digit
    bt_h(list, f);
    it = list.insert(it,f); // put it back   
  }
}

int main(){
  std::list<int> list;
  for(int i = 0 ; i < 10; i ++){
    if( i != 1) // skip 1 , since P = 1
      list.push_back(i);
  }
  
  bt(list);

  return 0;
}
