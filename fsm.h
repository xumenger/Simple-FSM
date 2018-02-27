/********************************************************************************* 
 * Copyright(C), xumenger
 * FileName     : fsm.h
 * Author       : xumenger
 * Version      : V1.0.0 
 * Date         : 2018-01-15
 * Description  : 状态机框架接口定义
**********************************************************************************/
#ifndef FSM_H
#define FSM_H

/*
 * 状态表
 */
typedef struct _FSMTable
{
  int event;             //事件
  int curState;          //当前状态
  void (*eventActFun)(); //当前状态下发生事件的回调函数
  int nextState;         //下一个状态
}FSMTable;

/*
 * 状态机
 */
typedef struct _FSM
{
  FSMTable *fsmTable;     //指向的状态表
  int count;              //状态表中元素个数
  int curState;           //FSM当前所处的状态
}FSM;


/*
 * 为状态机注册状态表
 */
void FSM_Regist(FSM *pFsm, FSMTable *pFsmTable, int count, int curState);
/*
 * 事件处理
 */
void FSM_EventHandle(FSM *pFsm, int event);

#endif
