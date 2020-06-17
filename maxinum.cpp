#include<bits/stdc++.h>
#define salto "\n"
#define ll long long
using namespace std;


int main(){
    ifstream cin("maxinum.in");
  ofstream cout("maxinum.out");
ll n;
cin>>n;
vector<ll> v(n+6,0);
vector<ll> a(n+6,0);
vector<bool> b(n+6);



for(int i=6;i<n+6;++i){
    cin>>v[i];
//cout<<v[i]<<salto;
}





ll d,mayor =-1 ;
//impares
for(int i=6;i<n+6;i+=2){    // primer indice  = 6
    a[i] = v[i]*v[i-2];
    mayor = max(a[i-4],a[i-6]);
    a[i] += mayor;
    d = i;
}

ll sum = 0;

//regreso

if(a[d-2]>a[d]) d-=2;

sum+=a[d];

//b[d] = true;

for(int i = d;i>7;i-=4){
         b[i-2] = true;
        b[i] = true;
    if( v[i]*v[i-2] + a[i-6] == a[i]  ){
          //  cout<<"6    "<<i-5<<salto;
      b[i-6] = true;

      i--;
      i--;
    }
    else{
      //  cout<<"4    "<<i-5<<salto;
        b[i-4] = true;
    }
}



//pares


for(int i=7;i<n+6;i+=2){     // primer indice  = 7
    a[i] = v[i]*v[i-2];
    mayor = max(a[i-4],a[i-6]);
    a[i] += mayor;
     d = i;
}

if(a[d-2]>a[d]) d-=2;

sum+=a[d];

//b[d] = true;

for(int i = d;i>8;i-=4){
        b[i] = true;
      b[i-2] = true;
    if( v[i]*v[i-2] + a[i-6] == a[i]  ){

      b[i-6] = true;


      i--;
      i--;
    }
    else{

        b[i-4] = true;

    }
}




ll cont = 0;

cout<<sum;

for(int i=6;i<n+6;++i){
    if(b[i]==false){
            //cout<<v[i]<<salto;
        cont+=v[i];
    }
}



cout<<salto<<cont;




return 0;
}
