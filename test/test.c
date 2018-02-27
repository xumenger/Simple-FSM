/********************************************************************************* 
 * Copyright(C), xumenger
 * FileName     : test.c
 * Author       : xumenger
 * Version      : V1.0.0 
 * Date         : 2018-01-15
 * Description  : 状态机框架测试程序
**********************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include "../src/fsm.h"

/*
 * 定义一个人一天的状态
 */
enum
{
  GET_UP,
  GO_TO_SCHOOL,
  HAVE_LUNCH,
  DO_HOMEWORK,
  SLEEP,
};

/*
 * 定义事件
 */
enum
{
  EVENT1 = 1,
  EVENT2,
  EVENT3
};


/*
 * 定义各种状态下发生事件的回调函数
 */
void GetUp(){
  printf("get up!\n");
}

void Go2School(){
  printf("go to school!\n");
}

void HaveLunch(){
  printf("have lunch!\n");
}

void DoHomework(){
  printf("do homework!\n");
}

void Go2Bed(){
  printf("go to bed!\n");
}


/*
 * 小明每天的状态表
 */
FSMTable XiaoMingTable[] =
{
//{到来的事件,   当前的状态,      将要要执行的函数,  下一个状态 }
	{ EVENT1,      SLEEP,           GetUp,             GET_UP },
	{ EVENT2,      GET_UP,          Go2School,         GO_TO_SCHOOL },
	{ EVENT3,      GO_TO_SCHOOL,    HaveLunch,         HAVE_LUNCH },
	{ EVENT1,      HAVE_LUNCH,      DoHomework,        DO_HOMEWORK },
	{ EVENT2,      DO_HOMEWORK,     Go2Bed,            SLEEP },

	//add your codes here

};


/*
 * 模拟事件发生和变化，用于测试
 */
void test(int *event)
{
  if(*event == 3){
    *event = 1;
  }
  else{
    (*event)++;
  }
}


int main()
{
  FSM fsm;
  int count = sizeof(XiaoMingTable) / sizeof(FSMTable);
  FSM_Regist(&fsm, XiaoMingTable, count, SLEEP);
  int event = EVENT1;

  //小明周而复始的一天又一天
  while(1){
    printf("event %d is coming...\n", event);
    FSM_EventHandle(&fsm, event);
    printf("fsm current state %d\n", fsm.curState);
    printf("state change, sleep(1)\n");
    test(&event);
    //休眠1s，让运行效果更明显
    sleep(1);
  }

  return 0;
}
