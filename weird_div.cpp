#include <iostream>
#include <stdlib.h>
#include <iomanip>

//NOTE: BUG jika dua digit,tidak bisa dibagi 0

using namespace std;

const int Nmax = 100000;

int tabPem[Nmax];
int tabPen[Nmax];
int N,tab1pem,tab2pen;
float cek,cek2;


bool isPrima(int angka){
    int i=1;
    int countMod = 0;
    while (i<=angka){
        if (angka%i==0){
            countMod++;
        }
        i++;
    }
    if (countMod==2){
        return true;
    }else{
        return false;
    }

}


void sortArrayPen(int tabPen[]){
    int temp = 0;
    for(int i=0;i<=4;i++){
        for(int j=0;j<=4-i;j++){
            if(tabPen[j]>tabPen[j+1]){
                temp=tabPen[j];
                tabPen[j]=tabPen[j+1];
                tabPen[j+1]=temp;
            }
        }
    }

}



int main()
{
    cout<<"Input N: ";
    cin>>N;
    int i = 1;
    while (i<N){
        if (isPrima(i)){
            int NumPem = i;
            for (int ArrPem = 2;ArrPem >=0 ;ArrPem--){
                tabPem[ArrPem] = NumPem%10;
                NumPem/=10;
            }
            //main process
            int j = 1;
            while (j<N){
            cek = (float)i/(float)j;
            int NumPen = j;
            for (int ArrPen = 2;ArrPen >=0 ;ArrPen--){
                tabPen[ArrPen] = NumPen%10;
                NumPen/=10;
            }
            sortArrayPen(tabPen);
            if (tabPem[0]==0 && tabPen[0]==0){ //array pertama dua digit
                if (tabPem[1]==0 && tabPen[1]==0 && tabPem[0]==0 && tabPen[0]==0){ //cek satu digit
                   break;
                }else if (tabPem[2]==tabPen[2] && tabPem[1]!=tabPen[1]){ //menghitung tengah jika kanan kiri sama
                    if (tabPem[2]==0 && tabPen[2]==0){
                        break;
                    }else if(tabPem[2]==tabPen[2]){
                        tab1pem = tabPem[1];
                        tab2pen = tabPen[1];
                        if (tab2pen==0){
                            tab2pen = -1;
                        }
                    }

                }else if (tabPem[1]==tabPen[2] && tabPem[2]!=tabPen[1]){
                    tab1pem = tabPem[2];
                    tab2pen = tabPen[1];
                    if (tab2pen==0){
                        tab2pen = -1;
                    }
                }else if (tabPem[2]==tabPen[1] && tabPem[1]!=tabPen[2]){
                    tab1pem = tabPem[1];
                    tab2pen = tabPen[2];
                    if (tab2pen==0){
                        tab2pen = -1;
                    }
                }else if (tabPem[2]!=tabPen[2] && tabPem[1]!=tabPen[1] && tabPem[1]!=tabPen[2] && tabPem[2]!=tabPen[1]){
                    tab1pem = 0;
                    tab2pen = -1;
                }else if (tabPem[1]==tabPen[2]&&tabPem[2]==tabPen[1]){
                    tab1pem = 0;
                    tab2pen = -1;
                }
            }else{
                if (tabPem[0]!=tabPen[0] && tabPem[1]==tabPen[1] && tabPem[2]==tabPen[2]){ //23 sama
                    tab1pem = tabPem[0];
                    tab2pen = tabPen[0];
                }else if (tabPem[0]==tabPen[0] && tabPem[1]!=tabPen[1] && tabPem[2]==tabPen[2]){ //13 sama
                    tab1pem = tabPem[1];
                    tab2pen = tabPen[1];
                }else if (tabPem[0]==tabPen[0] && tabPem[1]==tabPen[1] && tabPem[2]!=tabPen[2]){ //12 sama
                    tab1pem = tabPem[2];
                    tab2pen = tabPen[2];
                }else if (tabPem[0]!=tabPen[0] && tabPem[1]!=tabPen[1] && tabPem[2]==tabPen[2]){ // cek 3digit. digit 1 dan 2 beda
                    int tab1pem1 = tabPem[0]*10 + tabPem[1];
                    int tab2pen2 = tabPen[0]*10 + tabPen[1];
                    tab1pem = tab1pem1;
                    tab2pen = tab2pen2;

                }else if (tabPem[0]!=tabPen[0] && tabPem[1]==tabPen[1] && tabPem[2]!=tabPen[2]){ // cek 3digit. digit 1 dan 3 beda
                    int tab1pem1 = tabPem[0]*10 + tabPem[2];
                    int tab2pen2 = tabPen[0]*10 + tabPen[2];
                    tab1pem = tab1pem1;
                    tab2pen = tab2pen2;
                }else if (tabPem[0]==tabPen[0] && tabPem[1]!=tabPen[1] && tabPem[2]!=tabPen[2]){ // cek 3digit. digit 2 dan 3 beda
                    int tab1pem1 = tabPem[1]*10 + tabPem[2];
                    int tab2pen2 = tabPen[1]*10 + tabPen[2];
                    tab1pem = tab1pem1;
                    tab2pen = tab2pen2;
                }else if (tabPem[0]!=tabPen[0] && tabPem[1]!=tabPen[1] && tabPem[2]!=tabPen[2]){
                    if (tabPem[1]==tabPen[2] && tabPem[2]==tabPen[1] &&tabPem[0]!=tabPen[0]){
                        tab1pem = tabPem[0];
                        tab2pen = tabPen[0];
                    }else if (tabPem[0]==tabPen[1] && tabPem[1]==tabPen[0] &&tabPem[2]!=tabPen[2]){
                        tab1pem = tabPem[2];
                        tab2pen = tabPen[2];
                    }else if (tabPem[0]==tabPen[2] && tabPem[2]==tabPen[0] &&tabPem[1]!=tabPen[1]){
                        tab1pem = tabPem[1];
                        tab2pen = tabPen[1];
                    }else if (tabPem[0]!=tabPen[2] && tabPem[2]!=tabPen[0] &&tabPem[1]!=tabPen[1]){
                        tab1pem = 0;
                        tab2pen = -1;
                    }
                }else if(tabPem[0]==tabPen[0] && tabPem[1]==tabPen[1] && tabPem[2]==tabPen[2]){
                    tab1pem = 0;
                    tab2pen = -1;
                }
            }
            cek2 = (float)tab1pem/(float)tab2pen;

            if (cek2==cek){
                cout<<i<<"/"<<j<<endl;
            }
            j++;
            }
        }
        i++;
    }
}
