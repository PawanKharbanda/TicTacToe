//
//  main.cpp
//  Tic-Tac-Toe with Artificial-Intelligence
//
//  Created by Pawan on 7/12/18.
//  Copyright © 2018 Pawan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int computer;
struct node
{
    int r,c;
};
bool checkmoves(char a[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!='x' && a[i][j]!='0')
            {
                return true;
            }
        }
    }
    return false;
}
int evaluate(char a[][3])
{
    for(int row=0;row<3;row++)
    {
        if(a[row][0]==a[row][1] && a[row][1]==a[row][2])
        {
            if(a[row][0]=='x')
            {
            return 10;
            }
            else
            {
                return -10;
            }
        }
    }
    for(int col=0;col<3;col++)
    {
        if(a[0][col]==a[1][col] && a[1][col]==a[2][col] )
        {
            if(a[0][col]=='x')
            {
                return 10;
            }
            else
            {
                return -10;
            }
        }
    }
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
    {
        if(a[0][0]=='x')
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    else if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
    {
        if(a[0][2]=='x')
        {
            return 10;
        }
        else
        {
            return -10;
        }
    }
    return 0;
    
    
}
int minimax(char a[][3],bool ismax)
{
    int val=evaluate(a);
    if(val==10)
    {
        return val;
    }
    if(val==-10)
    {
        return val;
    }
    if(checkmoves(a)==false)
    {
        return 0;
    }
    
    if(ismax)
    {
        int best=-9999;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(a[i][j]!='x' && a[i][j]!='0')
                {
                    char k=a[i][j];
                    a[i][j]='x';
                    best=max(minimax(a,!ismax),best);
                    a[i][j]=k;
                }
            }
        }
        return best;
        
    }
    else
    {
        int best=9999;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(a[i][j]!='x' && a[i][j]!='0')
                {
                    char k=a[i][j];
                    a[i][j]='0';
                    best=min(minimax(a,!ismax),best);
                    a[i][j]=k;
                }
            }
        }
        return best;
        
    }
   
    
}
node bestmove(char a[][3],char mark)
{
    node move;
    int mval=-9999;
    move.r=-1;
    move.c=-1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!='x' && a[i][j]!='0')
            {
                char k=a[i][j];
                a[i][j]=mark;
                int val=minimax(a,false);
                a[i][j]=k;
                
                if(val>mval)
                {
                    mval=val;
                    move.r=i;
                    move.c=j;
                }
                
            }
            
        }
    }
    
    return move;
    
}




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
    for(int row=0;row<3;row++)
    {
        if(a[row][0]==a[row][1] && a[row][1]==a[row][2])
        {
            return 1;
        }
    }
    for(int col=0;col<3;col++)
    {
        if(a[0][col]==a[1][col] && a[1][col]==a[2][col] )
        {
            return 1;
        }
    }
    if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
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
    int computer;
    cout<<"If you want to play with COMPUTER Press 1"<<endl;
    cout<<"Else Press 0"<<endl;
    
    cin>>computer;
    char a[3][3]={
        {'1','2','3'},{'4','5','6'},{'7','8','9'}
    };
    
    int w=0;
    print(a);
    int c=9;
    
    char mark='0';
    while(c--)
    {
        int flag=0;
        if(computer==1 && mark=='x')
        {
            node move=bestmove(a,mark);
            a[move.r][move.c]=mark;
          
        }
        else
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
                flag=1;
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
                 flag=1;
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
                 flag=1;
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
                 flag=1;
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
                 flag=1;
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
                 flag=1;
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
                 flag=1;
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
                 flag=1;
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
                 flag=1;
                c=c+1;
            }
            
        }
        }
        print(a);
        w=check_win(a);
        if(w==1)
        {
            cout<<mark<<"  *WINNED THE GAME* "<<endl;
            break;
        }
      if(flag==0)
      { if(mark=='0')
        {
            mark='x';
        }
        else
        {
            mark='0';
        }
      }
    }
    if(w==0)
    {
        cout<<endl<<"DRAW Play Again"<<endl;
    }
}


