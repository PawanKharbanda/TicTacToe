//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Pawan on 7/12/18.
//  Copyright © 2018 Pawan. All rights reserved.
//

// Example program
#include <iostream>
#include <string>
using namespace std;
void print(char a[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" | ";
        }
        if(i<2)
            cout<<endl<<"____________"<<endl;
    }
    cout<<endl<<endl;
}
int check_win(char a[][3])
{
    if(a[0][0]==a[0][1] && a[0][1]==a[0][2])
    {
        return 1;
    }
    else if(a[1][0]==a[1][1] && a[1][1]==a[1][2])
    {
        return 1;
    }
    else if(a[2][0]==a[2][1] && a[2][1]==a[2][2])
    {
        return 1;
    }
    else if(a[0][0]==a[1][0] && a[1][0]==a[2][0])
    {
        return 1;
    }
    else if(a[0][1]==a[1][1] && a[1][1]==a[2][1])
    {
        return 1;
    }
    else if(a[0][2]==a[1][2] && a[1][2]==a[2][2])
    {
        return 1;
    }
    else if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
    {
        return 1;
    }
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
    {
        return 1;
    }
    return 0;
    
}
int main()
{
    char a[3][3]={
        {'1','2','3'},{'4','5','6'},{'7','8','9'}
    };
         int w=0;
    print(a);
    int c=9;
    char mark='0';
    while(c--)
    {
        int pos;
        cin>>pos;
        
        if(pos==1)
        {
            if(a[0][0]=='1')
            {
                a[0][0]=mark;
            }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
        }
        if(pos==2)
        {
            if(a[0][1]=='2')
            {  a[0][1]=mark; }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
            
        }
        if(pos==3)
        {
            if (a[0][2]=='3')
            { a[0][2]=mark; }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
            
        }
        if(pos==4 )
        {
            if(a[1][0]=='4')
            { a[1][0]=mark;}
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
        }
        if(pos==5)
        {
            if( a[1][1]=='5')
            {a[1][1]=mark; }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
        }
        if(pos==6 )
        {
            if(a[1][2]=='6')
            { a[1][2]=mark; }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
        }
        if(pos==7)
        {
            if ( a[2][0]=='7')
            { a[2][0]=mark; }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
        }
        if(pos==8)
        {
            if(a[2][1]=='8')
            { a[2][1]=mark; }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
        }
        if(pos==9 )
        {
            if(a[2][2]=='9')
            { a[2][2]=mark; }
            else
            {
                cout<<"Already marked ENTER VALID POSITION"<<endl;
                c=c+1;
            }
            
        }
        print(a);
   
        w=check_win(a);
        if(w==1)
        {
            cout<<mark<<"  *WINNED THE GAME* "<<endl;
            break;
        }
        
        if(mark=='0')
        {
            mark='x';
        }
        else
        {
            mark='0';
        }
        
    }
    if(w==0)
    {
        cout<<endl<<"DRAW Play Again";
    }
}


