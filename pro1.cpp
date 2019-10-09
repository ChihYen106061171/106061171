#include<iostream>
#include<fstream>
using namespace std;

//drop
void drop(bool**myarr,int posi,int shapeindex,int m)
{

    int step = 0;
    int i,j;

    if((shapeindex==1)||(shapeindex==3)||(shapeindex==6)||(shapeindex==8)||(shapeindex==10)
       ||(shapeindex==12)||(shapeindex==13)||(shapeindex==15)){//3
    int b[4] = {-1,-1,-1,-1};//record last block

    for(j=1;j<=3;j++){
         for(i=4;i>=1;i--){
            if(myarr[i][posi+j-1]==1) {
                    b[j] = i; // rewrite
                    break;//find last bottom 1
            }
       }
    }

    while((b[1]<m+4)&&(b[2]<m+4)&&(b[3]<m+4)&&(myarr[(b[1]+1)][posi]==0)
          &&(myarr[(b[2]+1)][posi+1]==0)&&(myarr[(b[3]+1)][posi+2]==0))
    {
        step++;
        b[1]++;
        b[2]++;
        b[3]++;
    } //<=?


    for(i=1;i<5;i++){    //bring all to dest
        for(j=0;j<3;j++){
            if(myarr[i][posi+j]==1){//move
                myarr[i+step][posi+j] = 1;
                myarr[i][posi+j]=0;
            }
        }
    }



    }//first if for 3

    //case 2 from here
    else if((shapeindex==2)||(shapeindex==4)||(shapeindex==5)||(shapeindex==7)||
            (shapeindex==9)||(shapeindex==11)||(shapeindex==14)||(shapeindex==16)||(shapeindex==19)){//2
    int b[3] = {-1,-1,-1};//record last block

    for(j=1;j<=2;j++){
         for(i=4;i>=1;i--){
            if(myarr[i][posi+j-1]==1) {
                    b[j] = i;
                    break;//find last bottom 1
            }
       }
    }

    while((b[1]<m+4)&&(b[2]<m+4)&&(myarr[(b[1]+1)][posi]==0)
          &&(myarr[(b[2]+1)][posi+1]==0))
    {
        step++;
        b[1]++;
        b[2]++;
    }

    for(i=1;i<5;i++){//bring all to dest
        for(j=0;j<2;j++){
            if(myarr[i][posi+j]==1){
                myarr[i+step][posi+j] = 1;
                myarr[i][posi+j]=0;
            }
        }
    }

    } //if for 2

    else if(shapeindex==17){
    int b[2] = {-1,-1};//record last block
    for(j=1;j<=1;j++){
         for(i=4;i>=1;i--){
            if(myarr[i][posi+j-1]==1) {
                    b[j] = i;
                    break;//find last bottom 1
            }
       }
    }

    while((b[1]<m+4)&&(myarr[(b[1]+1)][posi]==0))
    {
        step++;
        b[1]++;
    }

    for(i=1;i<5;i++){//bring all to dest
        for(j=0;j<1;j++){
            if(myarr[i][posi+j]==1){
                myarr[i+step][posi+j] = 1;
                myarr[i][posi+j]=0;
            }
        }
    }

    }//for I1
    else if(shapeindex==18){
        int b[5] = {-1,-1,-1,-1,-1};//record last block
    for(j=1;j<=4;j++){
         for(i=4;i>=1;i--){
            if(myarr[i][posi+j-1]==1) {
                    b[j] = i;
                    break;//find last bottom 1
            }
       }
    }

    while((b[1]<m+4)&&(b[2]<m+4)&&(b[3]<m+4)&&(b[4]<m+4)&&(myarr[(b[1]+1)][posi]==0)
          &&(myarr[(b[2]+1)][posi+1]==0)&&(myarr[(b[3]+1)][posi+2]==0)&&(myarr[(b[4]+1)][posi+3]==0))
    {
        step++;
        b[1]++;
        b[2]++;
        b[3]++;
        b[4]++;
    }

    for(i=1;i<5;i++){//bring all to dest
        for(j=0;j<4;j++){
            if(myarr[i][posi+j]==1){
                myarr[i+step][posi+j] = 1;
                myarr[i][posi+j]=0;
            }
        }
    }
    }
}

//delete
void Delete (bool**myarr,int m,int n)
{
    int i,j,k,a,b;
    i = m+4;

    while(i>=5){//from last row delete and drop
        for(j=1;j<=n;j++){
            if(myarr[i][j]!=1)
              { i--;//look up
                break;}
        }
        //a row to be delete
        if(j==(n+1)){//from "that  row!!"
            for(k=1;k<=n;k++) myarr[i][k] = 0; //delete
            for(a=i;a>0;a--){//no need for zero
                for(b=1;b<=n;b++){
                    myarr[a][b] = myarr[a-1][b];
                }
            }
        }
    }
}

//OK
int main()
{
    int shapeindex;
    int m,n,i,j;
    string obj;
    int posi;

    ifstream test;
    test.open("C:\\Users\\user\\Desktop\\project\\tetris.data.txt",ios::in);
    test>>m>>n; //data in for m n

    //bool myarr[m+1+4][n+1] = {0};//size notify
    bool **myarr = new bool*[m+5];
    for(i=0;i<m+5;i++){
          myarr[i] = new bool[n+1];
    }

    for(i=0;i<m+5;i++){
        for(j=0;j<n+1;j++){
            myarr[i][j] = 0;
        }
    }


    while (!test.eof())
    {//test star

        test>>obj>>posi;
        if(obj=="End") break;

        if(obj=="T1")
        {
            myarr[3][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[3][posi+2] = 1;
            myarr[4][posi+1] = 1;
            shapeindex = 1;
        }

        else if(obj=="T2")
        {
            myarr[3][posi] = 1;
            myarr[2][posi+1] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+1] = 1;
            shapeindex = 2;
        }


        else if(obj=="T3")
        {
            myarr[4][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+1] = 1;
            myarr[4][posi+2] = 1;
            shapeindex = 3;
        }

        else if(obj=="T4")
        {
            myarr[2][posi] = 1;
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            myarr[3][posi+1] = 1;
            shapeindex = 4;
        }

        else if(obj=="L1")
        {
            myarr[2][posi] = 1;
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            myarr[4][posi+1] = 1;
            shapeindex = 5;
        }

        else if(obj=="L2")
        {
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[3][posi+2] = 1;
            shapeindex = 6;
        }

        else if(obj=="L3"){
            myarr[2][posi] = 1;
            myarr[2][posi+1] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+1] = 1;
            shapeindex = 7;
        }
        else if(obj=="L4"){
            myarr[4][posi] = 1;
            myarr[4][posi+1] = 1;
            myarr[4][posi+2] = 1;
            myarr[3][posi+2] = 1;
            shapeindex = 8;
        }
        else if(obj=="J1"){
            myarr[4][posi] = 1;
            myarr[2][posi+1] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+1] = 1;
            shapeindex = 9;
        }
        else if(obj=="J2"){
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            myarr[4][posi+1] = 1;
            myarr[4][posi+2] = 1;
            shapeindex = 10;
        }
        else if(obj=="J3"){
            myarr[2][posi] = 1;
            myarr[2][posi+1] = 1;
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            shapeindex = 11;
        }
        else if(obj=="J4"){
            myarr[3][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+2] = 1;
            myarr[3][posi+2] = 1;
            shapeindex = 12;
        }
        else if(obj=="S1"){
            myarr[4][posi] = 1;
            myarr[4][posi+1] = 1;
            myarr[3][posi+1] = 1;
            myarr[3][posi+2] = 1;
            shapeindex = 13;
        }
        else if(obj=="S2"){
            myarr[2][posi] = 1;
            myarr[3][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+1] = 1;
            shapeindex = 14;
        }
        else if(obj=="Z1"){
            myarr[3][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+1] = 1;
            myarr[4][posi+2] = 1;
            shapeindex = 15;

        }
        else if(obj=="Z2"){
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[2][posi+1] = 1;
            shapeindex = 16;
        }
        else if(obj=="I1"){
            myarr[1][posi] = 1;
            myarr[2][posi] = 1;
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            shapeindex = 17;
        }
        else if(obj=="I2"){
            myarr[4][posi] = 1;
            myarr[4][posi+1] = 1;
            myarr[4][posi+2] = 1;
            myarr[4][posi+3] = 1;
            shapeindex = 18;
        }
        else if(obj=="O"){
            myarr[3][posi] = 1;
            myarr[4][posi] = 1;
            myarr[3][posi+1] = 1;
            myarr[4][posi+1] = 1;
            shapeindex  = 19;
        }

        drop(myarr,posi,shapeindex,m);//to be write
        Delete (myarr,m,n);
    }

    //remember use file
    for(i=5;i<=m+4;i++){
            for(j=1;j<=n;j++){
                cout<<myarr[i][j];
            }
            cout<<endl;
        }

    //end while
    return 0;
}
