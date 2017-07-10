#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxlines=201;
const int maxignored=50;
const int maxkeys=15*maxlines;
const int maxc_o_w=100;
int KEYS[maxkeys][3];//KEY[][0] 关键词所在行号 KEY[][1]行内偏移 KEY[][2] 长度
int cnt=0;
string lines[maxlines];
string ignored[maxignored];

//void createKeys()//done
//{
//    for(int i=0;lines[i]!="";i++)
//    {//each line
//        char *w_ptr = (char*)lines[i].c_str();
//        for(;;)
//        {//each word
//
//            char ch[maxc_o_w]="\0";
//            sscanf(w_ptr,"%s",ch);if('\0'==w_ptr[-1])break;//if end break
//            w_ptr+=strlen(ch)+1;//next word
//
//            int _is_ignored=0;
//            for(int k=0; ignored[k]!="" ;k++)
//                if(0==strcmp(ignored[k].c_str(),ch)){_is_ignored=1;break;}
//
//            if(!_is_ignored)
//            {
//                KEYS[cnt][0]=i;
//                KEYS[cnt][1]=w_ptr-strlen(ch)-1-(char*)lines[i].c_str();
//                KEYS[cnt++][2]=strlen(ch);
//            }
//        }
//    }
//}
//void ctKeys()
//{
//    for(int i=0;lines[i]!="";i++)
//    {//each line
//        int f=lines[i].find_first_not_of(' ',0);
//        int r=lines[i].find_last_not_of(' ',lines[i].length());
//        int _is_lastword=0;
//        if(f-1==lines[i].find_last_of(' ',r)||
//           r+1==lines[i].find_first_of(' ',f)||
//           string::npos==lines[i].find_last_of(' ',r)||
//           string::npos==lines[i].find_first_of(' ',f))_is_lastword=1;
//        f=0,r=0;
//        for(;;)
//        {//each word
//            string word;
//            int _is_key=1;
//            f = lines[i].find_first_not_of(' ',r);
//            if(_is_lastword)r = lines[i].find_last_not_of(' ',lines[i].length());
//            else            r = lines[i].find_first_of(' ',f);
//            if( f-1==lines[i].find_last_of(' ',r)||
//                r+1==lines[i].find_first_of(' ',f)||
//                string::npos==lines[i].find_last_of(' ',r)||
//                string::npos==lines[i].find_first_of(' ',f))_is_lastword=1;
//
//            word = lines[i].substr(f,r-f);
//            for(int j=0; ignored[j]!="";j++)
//                if(ignored[j] == word){_is_key=0;break;}
//            if(_is_key)
//            {KEYS[cnt][0]=i; KEYS[cnt][1]=f; KEYS[cnt][2]=r-f;cnt++;}
//        }
//    }
//}
void newKeys()
{
    for(int i=0;lines[i]!="";i++)
    {//for each line
        char *f,*r,*h=(char*)lines[i].c_str();
        char word[maxc_o_w];
        for(f=r=h ; *f!='\0'; r>f?f=r:f++)
        {
            int _is_key=1;
            if(*f!=' ')
            {//here's a word
                for(r=f;*r!=' ' && *r!='\0';r++){word[r-f]=*r;word[r-f+1]='\0';}
                for(int j=0;ignored[j]!="";j++)
                    if(0==strcmp(ignored[j].c_str(),word))_is_key=0;
                if(_is_key){KEYS[cnt][0]=i; KEYS[cnt][1]=f-h; KEYS[cnt++][2]=r-f;}//add key?
            }
        }
    }
}

//...尝试了四种↑↑↑↑↑以后再写字符串的检索 绝壁用sccanf()正则 或者自己实现限状态自动机
void getData()//done
{
    int i=0,j=0;
    while(getline(cin,ignored[i++]))//gets()
    {
        transform(ignored[i-1].begin(), ignored[i-1].end(), ignored[i-1].begin(), ::tolower);
        if(0 == strcmp(ignored[i-1].c_str(),"::"))
            {ignored[i-1]="";break;}
    }
    while(getline(cin,lines[j++]))
        transform(lines[j-1].begin(), lines[j-1].end(), lines[j-1].begin(), ::tolower);
        //前导空格……也得处理……哦特么淦
    newKeys();
}

void putData()
{
    for(int i=0;i<cnt;i++)
    {//for each key
        string line=lines[KEYS[i][0]];
        transform(line.begin()+KEYS[i][1],
                  line.begin()+KEYS[i][1]+KEYS[i][2],
                  line.begin()+KEYS[i][1],
                  ::toupper);//为啥不直接找KEY的时候转 蠢呐

        cout<<line<<endl;
    }
}

int cmp_KEY(const void *_a,const void *_b)//done
{
    int *KEYa =(int *)_a; char worda[maxc_o_w];
    int *KEYb =(int *)_b; char wordb[maxc_o_w];
    sscanf(((char*)lines[KEYa[0]].c_str())+KEYa[1],"%s",worda);
    sscanf(((char*)lines[KEYb[0]].c_str())+KEYb[1],"%s",wordb);
    if(0==strcmp(worda,wordb) && KEYa[0]==KEYb[0]) return KEYa[1]-KEYb[1];
    if(0==strcmp(worda,wordb))return KEYa[0]-KEYb[0];
    return strcmp(worda,wordb);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    getData();
    qsort(KEYS,cnt,sizeof(KEYS[0]),cmp_KEY);
    putData();
    return 0;
}
