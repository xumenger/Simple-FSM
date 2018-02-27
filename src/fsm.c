/********************************************************************************* 
 * Copyright(C), xumenger
 * FileName     : fsm.c
 * Author       : xumenger
 * Version      : V1.0.0 
 * Date         : 2018-01-15
 * Description  : 状态机框架接口实现
**********************************************************************************/
#include <stdio.h>
#include "fsm.h"


/*******************************************************************************
* Function   : FSM_Regist
* Description: 为状态机注册状态表
* Input      :
    * pFsm, 状态机
    * pFsmTable, 状态表
    * count, 状态表中元素数量
    * curState, 当前状态  
* Output     :
* Return     : 
* Others     : 
*******************************************************************************/  
void FSM_Regist(FSM *pFsm, FSMTable *pFsmTable, int count, int curState)
{
  pFsm->fsmTable = pFsmTable;
  pFsm->count = count;
  pFsm->curState = curState;
}

/*******************************************************************************
* Function   : FSM_EventHandle
* Description: 事件处理
* Input      :
    * pFsm, 状态机
    * event, 当前发生的事件 
* Output     :
* Return     : 
* Others     : 
*******************************************************************************/  
void FSM_EventHandle(FSM *pFsm, int event)
{
  FSMTable *pActTable = pFsm->fsmTable;
  void (*eventActFun)() = NULL;
  int NextState;
  int CurState = pFsm->curState;
  
  //获取当前动作函数
  int i = 0;
  for(i=0; i<pFsm->count; i++){
    //当且仅当当前状态下来了指定的事件，才执行它
    if(event == pActTable[i].event && CurState == pActTable[i].curState){
      eventActFun = pActTable[i].eventActFun;
      NextState = pActTable[i].nextState;
      break;
    }
  }

  //判断条件是否满足
  if(NULL != eventActFun){
  	//回调执行动作
    eventActFun();
    //状态跳转
    pFsm->curState = NextState;
    eventActFun = NULL;
  }
}
