#include "icon.h"
int ICON::SET_SIZE =12;  //һ����Ϸ���൱��96����,�޸ĳ�ǰ12Ϊ24
ICON::ICON(string names,int x,int y,int w,int h)  //���캯��
{
   name=names;
   itsX=x;
   itsY=y;
   width=w;
   height=h;
}
pair<string,ICON> pairArray[] =   //pair��һ��ģ�����ͣ����������ݺϳ�Ϊһ�����ݣ�map���������ֵ�ԣ����ﹹ����һ�����飬�����3�����������е�Ԫ��
{                                 //make����pair����pair<>����
    make_pair("CASTLE",ICON("CASTLE",0,0,8*2,8*2)),                  //����ICON���캯�����趨�����ƺͶ�Ӧ����
    make_pair("BACKGROUND",ICON("BACKGROUND",0,0,14*8,10*8)),
    make_pair("PATH",ICON("PATH",0,0,4*2,4*2)),
    make_pair("MONSTER1R",ICON("MONSTER1R",0,0,3*2,4*2)),
    make_pair("TOWER1",ICON("TOWER1",0,0,4*2,4*2)),
    make_pair("BASEBUTTON",ICON("BASEBUTTON",0,0,4*2,4*2)),
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));
//��̬��Ա��������г�ʼ����������������־����һ��Χ�ڵ����м�ֵ��
ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;           //map��ĵ�������ͨ�׵�˵�����൱�ڼ�������I
    kv = ICON::GAME_ICON_SET.find(type);  //.find�������ڲ��ң�����Ϊ�������ض�Ӧ�ĵ�����
    if (kv==ICON::GAME_ICON_SET.end()){    //end������ָ�Ҳ�����

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();                   //����һ��Ĭ��ֵ
    }
    else{
        return kv->second;        //���ض�Ӧ��ֵ�Ե��Ǹ�ֵ,Ҳ���Ƕ�ӦͼƬ
    }
}
