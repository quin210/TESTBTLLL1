#include <bits/stdc++.h>
using namespace std; 
//okiee
#define ll long long 
#define ll long long
#define info1 (e1/4.0 +19)
#define info2 (e1/9.0 + 21)
#define info3 (e1/16.0 + 17)

void checkExp(int & n){
    if (n > 600) n = 600;
    else if ( n < 0) n = 0;
    //if ((n - 1ll*n)  != 0) n = ceil(n);
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ( e1 < 4){
        if (e1 == 0){
        exp2 += 29;
    }
        else if (e1 == 1){
        exp2 += 45;
    }
        else if (e1 == 2){
        exp2 += 75;
    }
        else if (e1 == 3){
        exp2 += (29 + 45 + 75);
    }
    ll D = e1*3 + exp1*7;
     
    if (D%2 == 0){
        exp1 = ceil(static_cast<double>(exp1 + ((double)D/200)));
    }
    else {
       exp1 = ceil(static_cast<double>(exp1 - ((double)D/100)));
    }
    checkExp(exp1);
    }
    else 
    {
        if ( e1 >= 4 && e1 <= 19){
            exp2 = ceil(static_cast<double>(exp2 + (info1)));
            checkExp(exp2);
        } 
        else if ( e1 >=10 && e1 <=49){
            exp2 = ceil(static_cast<double>(exp2 + (info2)));
            checkExp(exp2);
        }
        else if ( e1 >= 50 && e1 <= 65){
            exp2 = ceil(static_cast<double>(exp2 + (info3)));
            checkExp(exp2);
        }
        else if ( e1 >= 66 && e1 <= 79){
            exp2 = ceil(static_cast<double>(exp2 + (info1))); checkExp(exp2);
            if (exp2 > 200) exp2 = ceil(static_cast<double>(exp2 + (info2)));
            checkExp(exp2);
        }
        else if ( e1 >= 80 && e1 <= 99){
            exp2 = ceil(static_cast<double>(exp2 + (info1))); checkExp(exp2); 
            exp2 = ceil(static_cast<double>(exp2 + (info2))); checkExp(exp2);
            if ( exp2 > 400) {
               exp2 = ceil(static_cast<double>(exp2 + (info3))); checkExp(exp2);
                exp2 = static_cast<double> (1.15*exp2); checkExp(exp2);
            }
             
        }
        exp1 = exp1 - e1;
        checkExp(exp1); checkExp(exp2);
    }
    cout <<exp1 <<" "<< exp2<<endl;
   return exp1 + exp2;
}

int main(){
    int exp1 = 295; 
    int exp2 = 64; 
    int e1= 3;
    cout << firstMeet(exp1, exp2, e1);
}
