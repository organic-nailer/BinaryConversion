#include <bits/stdc++.h>
using namespace std;

string TOTWO_DECIMAL(double A);

int ctoi(char i){
    return i - '0';
}
bool isInt(double A){
  return A - (int)A == 0.0;
}
string REVERSE_BIT_PLUS_ONE(string A){
    for(char &c:A){
        if(c == '0') c = '1';
        else c = '0';
    }

    for(int i = A.size() - 1; i >= 0; i--){
        if(A.at(i) == '0'){
            A.at(i) = '1';
            break;
        }
        else{
            A.at(i) = '0';
        }
    }

    return A;
}
//10->2,unsigned,����
string TOTWO(int A, int BIT = 0){
    if(BIT == 0){
        string R = "";
      while(1){
          if(A <= 1){
              R.push_back(A?'1':'0');
              break;
          }
          else{
              int rem = A%2;
              A /= 2;
              R.push_back((rem?'1':'0'));
          }
      }
      reverse(R.begin(),R.end());
      return R;
    }
    else{
      string R(BIT, '0');

      for(int i = 0; i < BIT; i++){
        if(A <= 1){
          R[i] = A?'1':'0';
          break;
        }
        else{
          int rem = A % 2;
          A /= 2;
          R[i] = rem?'1':'0';
        }
      }
      reverse(R.begin(),R.end());
      return R;
    }
}

string TOSIXTEEN(string TWO){
    vector<char> ST = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string RES;

    reverse(TWO.begin(), TWO.end());
    int rem = 4 - TWO.size()%4;
    if(rem == 4) rem = 0;
    for(int i = 0; i < rem; i++){
        TWO.push_back('0');
    }

    for(int i = 0;i < TWO.size(); i += 4){
        RES.push_back(
            ST[(ctoi(TWO[i]) * 1)
            +(ctoi(TWO[i+1]) * 2)
            +(ctoi(TWO[i+2]) * 4)
            +(ctoi(TWO[i+3]) * 8)]
        );
    }

    reverse(RES.begin(), RES.end());
    return RES;
}
//10->2,signed,����
string TOTWO_WITH_SIGN(int A,int BIT = 0, bool comp = 0){
    if(A < 0){
      if(!comp){
        return "-" + TOTWO(abs(A), BIT);
      }
      else{
        return REVERSE_BIT_PLUS_ONE(TOTWO(abs(A), BIT));
      }
    }
    else{
        return TOTWO(A, BIT);
    }
}

string TOSIXTEEN_WITH_SIGN(string TWO, bool comp = 0){
  if(TWO[0] == '-'){
    TWO.erase(TWO.begin());
    return "-" + TOSIXTEEN(TWO);
  }
  else{
    return TOSIXTEEN(TWO);
  }
}

string TOTWO_DECIMAL(double A){
    string R;
    map<double,int> M;
    M[A]++;
    int index = 0;

    while(1){
        A*= 2;

        R.push_back(((int)A)?'1':'0');

        if(A - (int)A == 0.0){
            break;
        }
        else{
            A = A - (int)A;
            if(M[A]==1){
                break;
            }
            M[A]++;
        }
    }

    return R;
}
//10->,signed,����
string TOTWO_WITH_DOT_SIGN(double A,int BIT = 0, bool comp = 0){
    if(!isInt(A)){
        return TOTWO_WITH_SIGN((int)A, BIT, comp) + "." + TOTWO_DECIMAL(A - (int)A);
    }
    else{
        return TOTWO_WITH_SIGN((int)A, BIT, comp);
    }
}

string TOSIXTEEN_DECIMAL(string TWO){
    vector<char> ST = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string RES;

    int rem = 4 - TWO.size()%4;
    if(rem == 4) rem = 0;
    for(int i = 0; i < rem; i++){
        TWO.push_back('0');
    }

    for(int i = 0;i < TWO.size(); i += 4){
        RES.push_back(
            ST[(ctoi(TWO[i]) * 8)
            +(ctoi(TWO[i+1]) * 4)
            +(ctoi(TWO[i+2]) * 2)
            +(ctoi(TWO[i+3]) * 1)]
        );
    }

    return RES;
}

string TOSIXTEEN_WITH_DOT_SIGN(string TWO){
    if(find(TWO.begin(),TWO.end(),'.') != TWO.end()){
        auto dot = find(TWO.begin(), TWO.end(), '.');

        string INT_PART = TWO.substr(0,dot - TWO.begin());
        string DEC_PART = TWO.substr(dot - TWO.begin() + 1,TWO.end() - dot + 1);

        return TOSIXTEEN_WITH_SIGN(INT_PART) + "." + TOSIXTEEN_DECIMAL(DEC_PART);
    }
    else{
        return TOSIXTEEN_WITH_SIGN(TWO);
    }
}

int TWOTOTEN(string TWO){
  int R = 0;
  reverse(TWO.begin(), TWO.end());
  for(int i = 0; i < TWO.size(); i++){
    if(TWO[i] == '1')
      R += pow(2,i);
  }
  return R;
}

int TWOTOTEN_COMP(string TWO,bool comp = 0){
  if(comp && *(TWO.begin()) == '1'){
    return -TWOTOTEN(REVERSE_BIT_PLUS_ONE(TWO));
  }
  else{
    return TWOTOTEN(TWO);
  }
}

double TWOTOTEN_DECIMAL(string DEC){
  double R = 0;
  for(int i = 1; i <= DEC.size(); i++){
    if(DEC[i-1] == '1'){
      R += pow(0.5,i);
    }
  }
  return R;
}

double TWOTOTEN_DOT(string TWO, bool comp = 0){
  if(find(TWO.begin(),TWO.end(), '.') != TWO.end()){
        auto dot = find(TWO.begin(), TWO.end(), '.');

        string INT_PART = TWO.substr(0,dot - TWO.begin());
        string DEC_PART = TWO.substr(dot - TWO.begin() + 1,TWO.end() - dot + 1);

        return TWOTOTEN_COMP(INT_PART,comp) + TWOTOTEN_DECIMAL(DEC_PART);
  }
  else{
    return TWOTOTEN_COMP(TWO,comp);
  }
}

void SHOW(double A, int BIT = 0){
    string t = TOTWO_WITH_DOT_SIGN(A, BIT, 1);
    cout << A << "(10) = " << t << "(2)" << endl;
    cout << A << "(10) = " << TOSIXTEEN_WITH_DOT_SIGN(t) << "(16)" << endl;
}

void SHOW_TOTEN(string A, bool comp = 0){
  cout << A << "(2) = " << TWOTOTEN_DOT(A,comp) << "(10)" << endl;
}

int main(){
    while(1){
        string A;
        bool c;
        cin >> A >> c;
        SHOW_TOTEN(A,c);
    }
}