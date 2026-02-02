/* Initialization */
#include "rPCR_03_model.h"
#include "rPCR_03_11mix.h"
#include "rPCR_03_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void rPCR_03_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
cycle = 1
*/
void rPCR_03_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* cycle DISCRETE */) = ((modelica_integer) 1);
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
R_Ba_Bs_x_BaBs.nS1 = 1.0
*/
void rPCR_03_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[245]] /* R_Ba_Bs_x_BaBs.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
R_Ba_Bs_x_BaBs.nS2 = 1.0
*/
void rPCR_03_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[246]] /* R_Ba_Bs_x_BaBs.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
R_Ba_Bs_x_BaBs.nP1 = 1.0
*/
void rPCR_03_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[244]] /* R_Ba_Bs_x_BaBs.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
R_Aa_As_x_AaAs.nS1 = 1.0
*/
void rPCR_03_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[177]] /* R_Aa_As_x_AaAs.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
R_Aa_As_x_AaAs.nS2 = 1.0
*/
void rPCR_03_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[178]] /* R_Aa_As_x_AaAs.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
R_Aa_As_x_AaAs.nP1 = 1.0
*/
void rPCR_03_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[176]] /* R_Aa_As_x_AaAs.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
R_Aa_Bs_x_AaBs.nS1 = 1.0
*/
void rPCR_03_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[181]] /* R_Aa_Bs_x_AaBs.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
R_Aa_Bs_x_AaBs.nS2 = 1.0
*/
void rPCR_03_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[182]] /* R_Aa_Bs_x_AaBs.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
R_Aa_Bs_x_AaBs.nP1 = 1.0
*/
void rPCR_03_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[180]] /* R_Aa_Bs_x_AaBs.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
R_As_Ba_x_AsBa.nS1 = 1.0
*/
void rPCR_03_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[213]] /* R_As_Ba_x_AsBa.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
R_As_Ba_x_AsBa.nS2 = 1.0
*/
void rPCR_03_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[214]] /* R_As_Ba_x_AsBa.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
R_As_Ba_x_AsBa.nP1 = 1.0
*/
void rPCR_03_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[212]] /* R_As_Ba_x_AsBa.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
R_Ba_Pra_x_BaPra.nS1 = 1.0
*/
void rPCR_03_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[253]] /* R_Ba_Pra_x_BaPra.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 15
type: SIMPLE_ASSIGN
R_Ba_Pra_x_BaPra.nS2 = 1.0
*/
void rPCR_03_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[254]] /* R_Ba_Pra_x_BaPra.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 16
type: SIMPLE_ASSIGN
R_Ba_Pra_x_BaPra.nP1 = 1.0
*/
void rPCR_03_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[252]] /* R_Ba_Pra_x_BaPra.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 17
type: SIMPLE_ASSIGN
R_Aa_Pra_x_AaPra.nS1 = 1.0
*/
void rPCR_03_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[189]] /* R_Aa_Pra_x_AaPra.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 18
type: SIMPLE_ASSIGN
R_Aa_Pra_x_AaPra.nS2 = 1.0
*/
void rPCR_03_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[190]] /* R_Aa_Pra_x_AaPra.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 19
type: SIMPLE_ASSIGN
R_Aa_Pra_x_AaPra.nP1 = 1.0
*/
void rPCR_03_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[188]] /* R_Aa_Pra_x_AaPra.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 20
type: SIMPLE_ASSIGN
R_As_Prs_x_AsPrs.nS1 = 1.0
*/
void rPCR_03_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[221]] /* R_As_Prs_x_AsPrs.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 21
type: SIMPLE_ASSIGN
R_As_Prs_x_AsPrs.nS2 = 1.0
*/
void rPCR_03_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[222]] /* R_As_Prs_x_AsPrs.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 22
type: SIMPLE_ASSIGN
R_As_Prs_x_AsPrs.nP1 = 1.0
*/
void rPCR_03_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[220]] /* R_As_Prs_x_AsPrs.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 23
type: SIMPLE_ASSIGN
R_Bs_Prs_x_BsPrs.nS1 = 1.0
*/
void rPCR_03_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[277]] /* R_Bs_Prs_x_BsPrs.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 24
type: SIMPLE_ASSIGN
R_Bs_Prs_x_BsPrs.nS2 = 1.0
*/
void rPCR_03_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[278]] /* R_Bs_Prs_x_BsPrs.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 25
type: SIMPLE_ASSIGN
R_Bs_Prs_x_BsPrs.nP1 = 1.0
*/
void rPCR_03_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[276]] /* R_Bs_Prs_x_BsPrs.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 26
type: SIMPLE_ASSIGN
R_BsPB_Prs_x_BsPrsPB.nS1 = 1.0
*/
void rPCR_03_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[257]] /* R_BsPB_Prs_x_BsPrsPB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 27
type: SIMPLE_ASSIGN
R_BsPB_Prs_x_BsPrsPB.nS2 = 1.0
*/
void rPCR_03_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[258]] /* R_BsPB_Prs_x_BsPrsPB.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 28
type: SIMPLE_ASSIGN
R_BsPB_Prs_x_BsPrsPB.nP1 = 1.0
*/
void rPCR_03_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[256]] /* R_BsPB_Prs_x_BsPrsPB.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 29
type: SIMPLE_ASSIGN
R_AsPA_Prs_x_AsPrsPA.nS1 = 1.0
*/
void rPCR_03_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[197]] /* R_AsPA_Prs_x_AsPrsPA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 30
type: SIMPLE_ASSIGN
R_AsPA_Prs_x_AsPrsPA.nS2 = 1.0
*/
void rPCR_03_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[198]] /* R_AsPA_Prs_x_AsPrsPA.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 31
type: SIMPLE_ASSIGN
R_AsPA_Prs_x_AsPrsPA.nP1 = 1.0
*/
void rPCR_03_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[196]] /* R_AsPA_Prs_x_AsPrsPA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 32
type: SIMPLE_ASSIGN
R_As_PA_x_AsPA.nS1 = 1.0
*/
void rPCR_03_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[217]] /* R_As_PA_x_AsPA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 33
type: SIMPLE_ASSIGN
R_As_PA_x_AsPA.nS2 = 1.0
*/
void rPCR_03_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[218]] /* R_As_PA_x_AsPA.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 34
type: SIMPLE_ASSIGN
R_As_PA_x_AsPA.nP1 = 1.0
*/
void rPCR_03_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[216]] /* R_As_PA_x_AsPA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 35
type: SIMPLE_ASSIGN
R_Bs_PB_x_BsPB.nS1 = 1.0
*/
void rPCR_03_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[273]] /* R_Bs_PB_x_BsPB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 36
type: SIMPLE_ASSIGN
R_Bs_PB_x_BsPB.nS2 = 1.0
*/
void rPCR_03_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[274]] /* R_Bs_PB_x_BsPB.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 37
type: SIMPLE_ASSIGN
R_Bs_PB_x_BsPB.nP1 = 1.0
*/
void rPCR_03_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[272]] /* R_Bs_PB_x_BsPB.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 38
type: SIMPLE_ASSIGN
R_AsPrs_PA_x_AsPrsPA.nS1 = 1.0
*/
void rPCR_03_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[205]] /* R_AsPrs_PA_x_AsPrsPA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 39
type: SIMPLE_ASSIGN
R_AsPrs_PA_x_AsPrsPA.nS2 = 1.0
*/
void rPCR_03_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[206]] /* R_AsPrs_PA_x_AsPrsPA.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 40
type: SIMPLE_ASSIGN
R_AsPrs_PA_x_AsPrsPA.nP1 = 1.0
*/
void rPCR_03_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[204]] /* R_AsPrs_PA_x_AsPrsPA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 41
type: SIMPLE_ASSIGN
R_BsPrs_PB_x_BsPrsPB.nS1 = 1.0
*/
void rPCR_03_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[265]] /* R_BsPrs_PB_x_BsPrsPB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 42
type: SIMPLE_ASSIGN
R_BsPrs_PB_x_BsPrsPB.nS2 = 1.0
*/
void rPCR_03_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[266]] /* R_BsPrs_PB_x_BsPrsPB.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 43
type: SIMPLE_ASSIGN
R_BsPrs_PB_x_BsPrsPB.nP1 = 1.0
*/
void rPCR_03_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[264]] /* R_BsPrs_PB_x_BsPrsPB.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 44
type: SIMPLE_ASSIGN
R_AaAs_Poly_x_AaAsPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[153]] /* R_AaAs_Poly_x_AaAsPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 45
type: SIMPLE_ASSIGN
R_AaAs_Poly_x_AaAsPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[154]] /* R_AaAs_Poly_x_AaAsPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 46
type: SIMPLE_ASSIGN
R_AaAs_Poly_x_AaAsPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[152]] /* R_AaAs_Poly_x_AaAsPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 47
type: SIMPLE_ASSIGN
R_BaBs_Poly_x_BaBsPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[225]] /* R_BaBs_Poly_x_BaBsPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 48
type: SIMPLE_ASSIGN
R_BaBs_Poly_x_BaBsPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[226]] /* R_BaBs_Poly_x_BaBsPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 49
type: SIMPLE_ASSIGN
R_BaBs_Poly_x_BaBsPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[224]] /* R_BaBs_Poly_x_BaBsPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 50
type: SIMPLE_ASSIGN
R_AaBs_Poly_x_AaBsPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[157]] /* R_AaBs_Poly_x_AaBsPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 51
type: SIMPLE_ASSIGN
R_AaBs_Poly_x_AaBsPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[158]] /* R_AaBs_Poly_x_AaBsPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 52
type: SIMPLE_ASSIGN
R_AaBs_Poly_x_AaBsPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[156]] /* R_AaBs_Poly_x_AaBsPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 53
type: SIMPLE_ASSIGN
R_AsBa_Poly_x_AsBaPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[193]] /* R_AsBa_Poly_x_AsBaPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 54
type: SIMPLE_ASSIGN
R_AsBa_Poly_x_AsBaPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[194]] /* R_AsBa_Poly_x_AsBaPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 55
type: SIMPLE_ASSIGN
R_AsBa_Poly_x_AsBaPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[192]] /* R_AsBa_Poly_x_AsBaPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 56
type: SIMPLE_ASSIGN
R_AaPra_Poly_x_AaPraPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[173]] /* R_AaPra_Poly_x_AaPraPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 57
type: SIMPLE_ASSIGN
R_AaPra_Poly_x_AaPraPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[174]] /* R_AaPra_Poly_x_AaPraPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 58
type: SIMPLE_ASSIGN
R_AaPra_Poly_x_AaPraPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[172]] /* R_AaPra_Poly_x_AaPraPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 59
type: SIMPLE_ASSIGN
R_AsPrs_Poly_x_AsPrsPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[209]] /* R_AsPrs_Poly_x_AsPrsPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 60
type: SIMPLE_ASSIGN
R_AsPrs_Poly_x_AsPrsPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[210]] /* R_AsPrs_Poly_x_AsPrsPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 61
type: SIMPLE_ASSIGN
R_AsPrs_Poly_x_AsPrsPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[208]] /* R_AsPrs_Poly_x_AsPrsPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 62
type: SIMPLE_ASSIGN
R_AsPrsPA_Poly_AsPrsPAPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[201]] /* R_AsPrsPA_Poly_AsPrsPAPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 63
type: SIMPLE_ASSIGN
R_AsPrsPA_Poly_AsPrsPAPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[202]] /* R_AsPrsPA_Poly_AsPrsPAPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 64
type: SIMPLE_ASSIGN
R_AsPrsPA_Poly_AsPrsPAPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[200]] /* R_AsPrsPA_Poly_AsPrsPAPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 65
type: SIMPLE_ASSIGN
R_BaPra_Poly_x_BaPraPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[241]] /* R_BaPra_Poly_x_BaPraPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 66
type: SIMPLE_ASSIGN
R_BaPra_Poly_x_BaPraPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[242]] /* R_BaPra_Poly_x_BaPraPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 67
type: SIMPLE_ASSIGN
R_BaPra_Poly_x_BaPraPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[240]] /* R_BaPra_Poly_x_BaPraPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 68
type: SIMPLE_ASSIGN
R_BsPrs_Poly_x_BsPrsPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[269]] /* R_BsPrs_Poly_x_BsPrsPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 69
type: SIMPLE_ASSIGN
R_BsPrs_Poly_x_BsPrsPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[270]] /* R_BsPrs_Poly_x_BsPrsPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 70
type: SIMPLE_ASSIGN
R_BsPrs_Poly_x_BsPrsPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[268]] /* R_BsPrs_Poly_x_BsPrsPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 71
type: SIMPLE_ASSIGN
R_BsPrsPB_Poly_x_BsPrsPBPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[261]] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 72
type: SIMPLE_ASSIGN
R_BsPrsPB_Poly_x_BsPrsPBPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[262]] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 73
type: SIMPLE_ASSIGN
R_BsPrsPB_Poly_x_BsPrsPBPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[260]] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 74
type: SIMPLE_ASSIGN
iR_BsPrsPoly_x_BaBs_Poly.nS1 = 1.0
*/
void rPCR_03_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[316]] /* iR_BsPrsPoly_x_BaBs_Poly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 75
type: SIMPLE_ASSIGN
iR_BsPrsPoly_x_BaBs_Poly.nP1 = 1.0
*/
void rPCR_03_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[314]] /* iR_BsPrsPoly_x_BaBs_Poly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 76
type: SIMPLE_ASSIGN
iR_BsPrsPoly_x_BaBs_Poly.nP2 = 1.0
*/
void rPCR_03_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[315]] /* iR_BsPrsPoly_x_BaBs_Poly.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 77
type: SIMPLE_ASSIGN
iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nS1 = 1.0
*/
void rPCR_03_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[312]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 78
type: SIMPLE_ASSIGN
iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP1 = 1.0
*/
void rPCR_03_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[309]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 79
type: SIMPLE_ASSIGN
iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP2 = 1.0
*/
void rPCR_03_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[310]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 80
type: SIMPLE_ASSIGN
iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP3 = 1.0
*/
void rPCR_03_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[311]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP3 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
iR_AsPrsPoly_x_AaAs_Poly.nS1 = 1.0
*/
void rPCR_03_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[298]] /* iR_AsPrsPoly_x_AaAs_Poly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
iR_AsPrsPoly_x_AaAs_Poly.nP1 = 1.0
*/
void rPCR_03_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[296]] /* iR_AsPrsPoly_x_AaAs_Poly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
iR_AsPrsPoly_x_AaAs_Poly.nP2 = 1.0
*/
void rPCR_03_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[297]] /* iR_AsPrsPoly_x_AaAs_Poly.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 84
type: SIMPLE_ASSIGN
iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nS1 = 1.0
*/
void rPCR_03_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[294]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 85
type: SIMPLE_ASSIGN
iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP1 = 1.0
*/
void rPCR_03_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[291]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 86
type: SIMPLE_ASSIGN
iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP2 = 1.0
*/
void rPCR_03_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[292]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 87
type: SIMPLE_ASSIGN
iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP3 = 1.0
*/
void rPCR_03_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[293]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP3 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 88
type: SIMPLE_ASSIGN
iR_BaPraPoly_x_BaBs_Poly.nS1 = 1.0
*/
void rPCR_03_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[307]] /* iR_BaPraPoly_x_BaBs_Poly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
iR_BaPraPoly_x_BaBs_Poly.nP1 = 1.0
*/
void rPCR_03_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[305]] /* iR_BaPraPoly_x_BaBs_Poly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 90
type: SIMPLE_ASSIGN
iR_BaPraPoly_x_BaBs_Poly.nP2 = 1.0
*/
void rPCR_03_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[306]] /* iR_BaPraPoly_x_BaBs_Poly.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 91
type: SIMPLE_ASSIGN
iR_AaPraPoly_x_AaAs_Poly.nS1 = 1.0
*/
void rPCR_03_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[289]] /* iR_AaPraPoly_x_AaAs_Poly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 92
type: SIMPLE_ASSIGN
iR_AaPraPoly_x_AaAs_Poly.nP1 = 1.0
*/
void rPCR_03_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[287]] /* iR_AaPraPoly_x_AaAs_Poly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 93
type: SIMPLE_ASSIGN
iR_AaPraPoly_x_AaAs_Poly.nP2 = 1.0
*/
void rPCR_03_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[288]] /* iR_AaPraPoly_x_AaAs_Poly.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 94
type: SIMPLE_ASSIGN
R_Ba_PA_x_BaPA.nS1 = 1.0
*/
void rPCR_03_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[249]] /* R_Ba_PA_x_BaPA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 95
type: SIMPLE_ASSIGN
R_Ba_PA_x_BaPA.nS2 = 1.0
*/
void rPCR_03_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[250]] /* R_Ba_PA_x_BaPA.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 96
type: SIMPLE_ASSIGN
R_Ba_PA_x_BaPA.nP1 = 1.0
*/
void rPCR_03_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[248]] /* R_Ba_PA_x_BaPA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 97
type: SIMPLE_ASSIGN
R_BaPA_Pra_x_BaPraPA.nS1 = 1.0
*/
void rPCR_03_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[229]] /* R_BaPA_Pra_x_BaPraPA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 98
type: SIMPLE_ASSIGN
R_BaPA_Pra_x_BaPraPA.nS2 = 1.0
*/
void rPCR_03_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[230]] /* R_BaPA_Pra_x_BaPraPA.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 99
type: SIMPLE_ASSIGN
R_BaPA_Pra_x_BaPraPA.nP1 = 1.0
*/
void rPCR_03_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[228]] /* R_BaPA_Pra_x_BaPraPA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 100
type: SIMPLE_ASSIGN
R_BaPraPA_Poly_x_BaPraPAPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[233]] /* R_BaPraPA_Poly_x_BaPraPAPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 101
type: SIMPLE_ASSIGN
R_BaPraPA_Poly_x_BaPraPAPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[234]] /* R_BaPraPA_Poly_x_BaPraPAPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
R_BaPraPA_Poly_x_BaPraPAPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[232]] /* R_BaPraPA_Poly_x_BaPraPAPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 103
type: SIMPLE_ASSIGN
iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nS1 = 1.0
*/
void rPCR_03_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[303]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 104
type: SIMPLE_ASSIGN
iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP1 = 1.0
*/
void rPCR_03_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[300]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 105
type: SIMPLE_ASSIGN
iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP2 = 1.0
*/
void rPCR_03_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[301]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 106
type: SIMPLE_ASSIGN
iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP3 = 1.0
*/
void rPCR_03_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[302]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP3 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 107
type: SIMPLE_ASSIGN
R_BaPra_PA_x_BaPraPA.nS1 = 1.0
*/
void rPCR_03_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[237]] /* R_BaPra_PA_x_BaPraPA.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 108
type: SIMPLE_ASSIGN
R_BaPra_PA_x_BaPraPA.nS2 = 1.0
*/
void rPCR_03_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[238]] /* R_BaPra_PA_x_BaPraPA.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 109
type: SIMPLE_ASSIGN
R_BaPra_PA_x_BaPraPA.nP1 = 1.0
*/
void rPCR_03_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[236]] /* R_BaPra_PA_x_BaPraPA.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 110
type: SIMPLE_ASSIGN
R_Aa_PB_x_AaPB.nS1 = 1.0
*/
void rPCR_03_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[185]] /* R_Aa_PB_x_AaPB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 111
type: SIMPLE_ASSIGN
R_Aa_PB_x_AaPB.nS2 = 1.0
*/
void rPCR_03_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[186]] /* R_Aa_PB_x_AaPB.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 112
type: SIMPLE_ASSIGN
R_Aa_PB_x_AaPB.nP1 = 1.0
*/
void rPCR_03_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[184]] /* R_Aa_PB_x_AaPB.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 113
type: SIMPLE_ASSIGN
R_AaPB_Pra_x_AaPraPB.nS1 = 1.0
*/
void rPCR_03_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[161]] /* R_AaPB_Pra_x_AaPraPB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 114
type: SIMPLE_ASSIGN
R_AaPB_Pra_x_AaPraPB.nS2 = 1.0
*/
void rPCR_03_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[162]] /* R_AaPB_Pra_x_AaPraPB.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 115
type: SIMPLE_ASSIGN
R_AaPB_Pra_x_AaPraPB.nP1 = 1.0
*/
void rPCR_03_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[160]] /* R_AaPB_Pra_x_AaPraPB.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 116
type: SIMPLE_ASSIGN
R_AaPraPB_Poly_x_AaPraPBPoly.nS1 = 1.0
*/
void rPCR_03_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[165]] /* R_AaPraPB_Poly_x_AaPraPBPoly.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 117
type: SIMPLE_ASSIGN
R_AaPraPB_Poly_x_AaPraPBPoly.nS2 = 1.0
*/
void rPCR_03_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[166]] /* R_AaPraPB_Poly_x_AaPraPBPoly.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 118
type: SIMPLE_ASSIGN
R_AaPraPB_Poly_x_AaPraPBPoly.nP1 = 1.0
*/
void rPCR_03_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[164]] /* R_AaPraPB_Poly_x_AaPraPBPoly.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 119
type: SIMPLE_ASSIGN
iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nS1 = 1.0
*/
void rPCR_03_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[285]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 120
type: SIMPLE_ASSIGN
iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP1 = 1.0
*/
void rPCR_03_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[282]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 121
type: SIMPLE_ASSIGN
iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP2 = 1.0
*/
void rPCR_03_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[283]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 122
type: SIMPLE_ASSIGN
iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP3 = 1.0
*/
void rPCR_03_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[284]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP3 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 123
type: SIMPLE_ASSIGN
R_AaPra_PB_x_AaPraPB.nS1 = 1.0
*/
void rPCR_03_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[169]] /* R_AaPra_PB_x_AaPraPB.nS1 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 124
type: SIMPLE_ASSIGN
R_AaPra_PB_x_AaPraPB.nS2 = 1.0
*/
void rPCR_03_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[170]] /* R_AaPra_PB_x_AaPraPB.nS2 variable */) = 1.0;
  TRACE_POP
}

/*
equation index: 125
type: SIMPLE_ASSIGN
R_AaPra_PB_x_AaPraPB.nP1 = 1.0
*/
void rPCR_03_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[168]] /* R_AaPra_PB_x_AaPraPB.nP1 variable */) = 1.0;
  TRACE_POP
}
extern void rPCR_03_eqFunction_342(DATA *data, threadData_t *threadData);


/*
equation index: 127
type: SIMPLE_ASSIGN
V = $START.V
*/
void rPCR_03_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */) = (data->modelData->realVarsData[37] /* V STATE(1) */).attribute .start;
  TRACE_POP
}

/*
equation index: 128
type: SIMPLE_ASSIGN
As.c = senseA
*/
void rPCR_03_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */) = (data->simulationInfo->realParameter[241] /* senseA PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_436(DATA *data, threadData_t *threadData);


/*
equation index: 130
type: SIMPLE_ASSIGN
Aa.c = antiA
*/
void rPCR_03_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */) = (data->simulationInfo->realParameter[204] /* antiA PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_435(DATA *data, threadData_t *threadData);


/*
equation index: 132
type: SIMPLE_ASSIGN
Bs.c = senseB
*/
void rPCR_03_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */) = (data->simulationInfo->realParameter[242] /* senseB PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_434(DATA *data, threadData_t *threadData);


/*
equation index: 134
type: SIMPLE_ASSIGN
Ba.c = antiB
*/
void rPCR_03_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */) = (data->simulationInfo->realParameter[205] /* antiB PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_433(DATA *data, threadData_t *threadData);


/*
equation index: 136
type: SIMPLE_ASSIGN
Prs.c = sensePrimer
*/
void rPCR_03_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */) = (data->simulationInfo->realParameter[243] /* sensePrimer PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_432(DATA *data, threadData_t *threadData);


/*
equation index: 138
type: SIMPLE_ASSIGN
Pra.c = antiPrimer
*/
void rPCR_03_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */) = (data->simulationInfo->realParameter[206] /* antiPrimer PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_431(DATA *data, threadData_t *threadData);


/*
equation index: 140
type: SIMPLE_ASSIGN
PA.c = ProbeA
*/
void rPCR_03_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */) = (data->simulationInfo->realParameter[29] /* ProbeA PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_430(DATA *data, threadData_t *threadData);


/*
equation index: 142
type: SIMPLE_ASSIGN
PB.c = ProbeB
*/
void rPCR_03_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */) = (data->simulationInfo->realParameter[32] /* ProbeB PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_429(DATA *data, threadData_t *threadData);


/*
equation index: 144
type: SIMPLE_ASSIGN
Poly.c = Polymerase
*/
void rPCR_03_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */) = (data->simulationInfo->realParameter[24] /* Polymerase PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_428(DATA *data, threadData_t *threadData);


/*
equation index: 146
type: SIMPLE_ASSIGN
AsBa.c = $START.AsBa.c
*/
void rPCR_03_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */) = (data->modelData->realVarsData[11] /* AsBa.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_396(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_427(DATA *data, threadData_t *threadData);


/*
equation index: 149
type: SIMPLE_ASSIGN
AaBs.c = $START.AaBs.c
*/
void rPCR_03_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */) = (data->modelData->realVarsData[3] /* AaBs.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_397(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_426(DATA *data, threadData_t *threadData);


/*
equation index: 152
type: SIMPLE_ASSIGN
BaBs.c = $START.BaBs.c
*/
void rPCR_03_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */) = (data->modelData->realVarsData[19] /* BaBs.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_399(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_425(DATA *data, threadData_t *threadData);


/*
equation index: 155
type: SIMPLE_ASSIGN
AaAs.c = $START.AaAs.c
*/
void rPCR_03_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */) = (data->modelData->realVarsData[1] /* AaAs.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_398(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_424(DATA *data, threadData_t *threadData);


/*
equation index: 158
type: SIMPLE_ASSIGN
AaAsPoly.c = $START.AaAsPoly.c
*/
void rPCR_03_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */) = (data->modelData->realVarsData[2] /* AaAsPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_385(DATA *data, threadData_t *threadData);


/*
equation index: 160
type: SIMPLE_ASSIGN
$DER.AaAsPoly.c = (R_AaAs_Poly_x_AaAsPoly.rr - AaAsPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* der(AaAsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[155]] /* R_AaAs_Poly_x_AaAsPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_423(DATA *data, threadData_t *threadData);


/*
equation index: 162
type: SIMPLE_ASSIGN
BaBsPoly.c = $START.BaBsPoly.c
*/
void rPCR_03_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */) = (data->modelData->realVarsData[20] /* BaBsPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_384(DATA *data, threadData_t *threadData);


/*
equation index: 164
type: SIMPLE_ASSIGN
$DER.BaBsPoly.c = (R_BaBs_Poly_x_BaBsPoly.rr - BaBsPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* der(BaBsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* R_BaBs_Poly_x_BaBsPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_421(DATA *data, threadData_t *threadData);


/*
equation index: 166
type: SIMPLE_ASSIGN
BaPra.c = $START.BaPra.c
*/
void rPCR_03_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */) = (data->modelData->realVarsData[22] /* BaPra.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_395(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_419(DATA *data, threadData_t *threadData);


/*
equation index: 169
type: SIMPLE_ASSIGN
AaPra.c = $START.AaPra.c
*/
void rPCR_03_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */) = (data->modelData->realVarsData[6] /* AaPra.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_394(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_418(DATA *data, threadData_t *threadData);


/*
equation index: 172
type: SIMPLE_ASSIGN
AsPrs.c = $START.AsPrs.c
*/
void rPCR_03_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */) = (data->modelData->realVarsData[14] /* AsPrs.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_393(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_417(DATA *data, threadData_t *threadData);


/*
equation index: 175
type: SIMPLE_ASSIGN
BsPrs.c = $START.BsPrs.c
*/
void rPCR_03_eqFunction_175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,175};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */) = (data->modelData->realVarsData[28] /* BsPrs.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_392(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_416(DATA *data, threadData_t *threadData);


/*
equation index: 178
type: SIMPLE_ASSIGN
BsPB.c = $START.BsPB.c
*/
void rPCR_03_eqFunction_178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,178};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */) = (data->modelData->realVarsData[27] /* BsPB.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_388(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_491(DATA *data, threadData_t *threadData);


/*
equation index: 181
type: SIMPLE_ASSIGN
$DER.Bs.c = (Bs.rNet - Bs.c * $DER.V) / V
*/
void rPCR_03_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* der(Bs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[129]] /* Bs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_415(DATA *data, threadData_t *threadData);


/*
equation index: 183
type: SIMPLE_ASSIGN
AsPA.c = $START.AsPA.c
*/
void rPCR_03_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */) = (data->modelData->realVarsData[13] /* AsPA.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_389(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_505(DATA *data, threadData_t *threadData);


/*
equation index: 186
type: SIMPLE_ASSIGN
$DER.As.c = (As.rNet - As.c * $DER.V) / V
*/
void rPCR_03_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* der(As.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* As.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_414(DATA *data, threadData_t *threadData);


/*
equation index: 188
type: SIMPLE_ASSIGN
AsPrsPA.c = $START.AsPrsPA.c
*/
void rPCR_03_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */) = (data->modelData->realVarsData[15] /* AsPrsPA.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_387(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_390(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_485(DATA *data, threadData_t *threadData);


/*
equation index: 192
type: SIMPLE_ASSIGN
$DER.AsPA.c = (AsPA.rNet - AsPA.c * $DER.V) / V
*/
void rPCR_03_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* der(AsPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* AsPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_413(DATA *data, threadData_t *threadData);


/*
equation index: 194
type: SIMPLE_ASSIGN
BsPrsPB.c = $START.BsPrsPB.c
*/
void rPCR_03_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */) = (data->modelData->realVarsData[29] /* BsPrsPB.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_386(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_391(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_483(DATA *data, threadData_t *threadData);


/*
equation index: 198
type: SIMPLE_ASSIGN
$DER.BsPB.c = (BsPB.rNet - BsPB.c * $DER.V) / V
*/
void rPCR_03_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* der(BsPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[131]] /* BsPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_489(DATA *data, threadData_t *threadData);


/*
equation index: 200
type: SIMPLE_ASSIGN
$DER.Prs.c = (Prs.rNet - Prs.c * $DER.V) / V
*/
void rPCR_03_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* der(Prs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[151]] /* Prs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_412(DATA *data, threadData_t *threadData);


/*
equation index: 202
type: SIMPLE_ASSIGN
AaPraPoly.c = $START.AaPraPoly.c
*/
void rPCR_03_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */) = (data->modelData->realVarsData[9] /* AaPraPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_370(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_381(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_463(DATA *data, threadData_t *threadData);


/*
equation index: 206
type: SIMPLE_ASSIGN
$DER.AaPraPoly.c = (AaPraPoly.rNet - AaPraPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* der(AaPraPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* AaPraPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_411(DATA *data, threadData_t *threadData);


/*
equation index: 208
type: SIMPLE_ASSIGN
AsPrsPAPoly.c = $START.AsPrsPAPoly.c
*/
void rPCR_03_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */) = (data->modelData->realVarsData[16] /* AsPrsPAPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_372(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_379(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_459(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_477(DATA *data, threadData_t *threadData);


/*
equation index: 213
type: SIMPLE_ASSIGN
$DER.AsPrsPA.c = (AsPrsPA.rNet - AsPrsPA.c * $DER.V) / V
*/
void rPCR_03_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* der(AsPrsPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* AsPrsPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 214
type: SIMPLE_ASSIGN
$DER.AsPrsPAPoly.c = (AsPrsPAPoly.rNet - AsPrsPAPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* der(AsPrsPAPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* AsPrsPAPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_410(DATA *data, threadData_t *threadData);


/*
equation index: 216
type: SIMPLE_ASSIGN
AsPrsPoly.c = $START.AsPrsPoly.c
*/
void rPCR_03_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */) = (data->modelData->realVarsData[17] /* AsPrsPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_373(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_380(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_461(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_479(DATA *data, threadData_t *threadData);


/*
equation index: 221
type: SIMPLE_ASSIGN
$DER.AsPrs.c = (AsPrs.rNet - AsPrs.c * $DER.V) / V
*/
void rPCR_03_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* der(AsPrs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* AsPrs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 222
type: SIMPLE_ASSIGN
$DER.AsPrsPoly.c = (AsPrsPoly.rNet - AsPrsPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* der(AsPrsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* AsPrsPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_409(DATA *data, threadData_t *threadData);


/*
equation index: 224
type: SIMPLE_ASSIGN
BaPraPoly.c = $START.BaPraPoly.c
*/
void rPCR_03_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */) = (data->modelData->realVarsData[25] /* BaPraPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_371(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_378(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_457(DATA *data, threadData_t *threadData);


/*
equation index: 228
type: SIMPLE_ASSIGN
$DER.BaPraPoly.c = (BaPraPoly.rNet - BaPraPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* der(BaPraPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[127]] /* BaPraPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_408(DATA *data, threadData_t *threadData);


/*
equation index: 230
type: SIMPLE_ASSIGN
BsPrsPBPoly.c = $START.BsPrsPBPoly.c
*/
void rPCR_03_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */) = (data->modelData->realVarsData[30] /* BsPrsPBPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_374(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_376(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_453(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_473(DATA *data, threadData_t *threadData);


/*
equation index: 235
type: SIMPLE_ASSIGN
$DER.BsPrsPB.c = (BsPrsPB.rNet - BsPrsPB.c * $DER.V) / V
*/
void rPCR_03_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* der(BsPrsPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[135]] /* BsPrsPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 236
type: SIMPLE_ASSIGN
$DER.BsPrsPBPoly.c = (BsPrsPBPoly.rNet - BsPrsPBPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* der(BsPrsPBPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[137]] /* BsPrsPBPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_407(DATA *data, threadData_t *threadData);


/*
equation index: 238
type: SIMPLE_ASSIGN
BsPrsPoly.c = $START.BsPrsPoly.c
*/
void rPCR_03_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */) = (data->modelData->realVarsData[31] /* BsPrsPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_348(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_375(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_377(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_455(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_487(DATA *data, threadData_t *threadData);


/*
equation index: 244
type: SIMPLE_ASSIGN
$DER.BsPrs.c = (BsPrs.rNet - BsPrs.c * $DER.V) / V
*/
void rPCR_03_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* der(BsPrs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[133]] /* BsPrs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 245
type: SIMPLE_ASSIGN
$DER.BsPrsPoly.c = (BsPrsPoly.rNet - BsPrsPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* der(BsPrsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[139]] /* BsPrsPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_406(DATA *data, threadData_t *threadData);


/*
equation index: 247
type: SIMPLE_ASSIGN
AsBaPoly.c = $START.AsBaPoly.c
*/
void rPCR_03_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */) = (data->modelData->realVarsData[12] /* AsBaPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_352(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_382(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_497(DATA *data, threadData_t *threadData);


/*
equation index: 251
type: SIMPLE_ASSIGN
$DER.AsBa.c = (AsBa.rNet - AsBa.c * $DER.V) / V
*/
void rPCR_03_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* der(AsBa.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* AsBa.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 252
type: SIMPLE_ASSIGN
$DER.AsBaPoly.c = (R_AsBa_Poly_x_AsBaPoly.rr - AsBaPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* der(AsBaPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* R_AsBa_Poly_x_AsBaPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_405(DATA *data, threadData_t *threadData);


/*
equation index: 254
type: SIMPLE_ASSIGN
AaBsPoly.c = $START.AaBsPoly.c
*/
void rPCR_03_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */) = (data->modelData->realVarsData[4] /* AaBsPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_350(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_383(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_501(DATA *data, threadData_t *threadData);


/*
equation index: 258
type: SIMPLE_ASSIGN
$DER.AaBs.c = (AaBs.rNet - AaBs.c * $DER.V) / V
*/
void rPCR_03_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* der(AaBs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* AaBs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 259
type: SIMPLE_ASSIGN
$DER.AaBsPoly.c = (R_AaBs_Poly_x_AaBsPoly.rr - AaBsPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* der(AaBsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[159]] /* R_AaBs_Poly_x_AaBsPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_403(DATA *data, threadData_t *threadData);


/*
equation index: 261
type: SIMPLE_ASSIGN
signalA.c = Signal_A
*/
void rPCR_03_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */) = (data->simulationInfo->realParameter[202] /* Signal_A PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_344(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_401(DATA *data, threadData_t *threadData);


/*
equation index: 264
type: SIMPLE_ASSIGN
signalB.c = Signal_B
*/
void rPCR_03_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */) = (data->simulationInfo->realParameter[203] /* Signal_B PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_343(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_400(DATA *data, threadData_t *threadData);


/*
equation index: 267
type: SIMPLE_ASSIGN
$PRE.totalAs = totalAs
*/
void rPCR_03_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  (data->simulationInfo->realVarsPre[324] /* totalAs variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[324]] /* totalAs variable */);
  TRACE_POP
}

/*
equation index: 268
type: SIMPLE_ASSIGN
$PRE.totalBs = totalBs
*/
void rPCR_03_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  (data->simulationInfo->realVarsPre[326] /* totalBs variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[326]] /* totalBs variable */);
  TRACE_POP
}

/*
equation index: 269
type: SIMPLE_ASSIGN
$PRE.totalPrs = totalPrs
*/
void rPCR_03_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  (data->simulationInfo->realVarsPre[328] /* totalPrs variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[328]] /* totalPrs variable */);
  TRACE_POP
}

/*
equation index: 270
type: SIMPLE_ASSIGN
BaPA.c = $START.BaPA.c
*/
void rPCR_03_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */) = (data->modelData->realVarsData[21] /* BaPA.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_367(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_499(DATA *data, threadData_t *threadData);


/*
equation index: 273
type: SIMPLE_ASSIGN
$DER.Ba.c = (Ba.rNet - Ba.c * $DER.V) / V
*/
void rPCR_03_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* der(Ba.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* Ba.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_369(DATA *data, threadData_t *threadData);


/*
equation index: 275
type: SIMPLE_ASSIGN
BaPraPA.c = $START.BaPraPA.c
*/
void rPCR_03_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */) = (data->modelData->realVarsData[23] /* BaPraPA.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_362(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_481(DATA *data, threadData_t *threadData);


/*
equation index: 278
type: SIMPLE_ASSIGN
$DER.PA.c = (PA.rNet - PA.c * $DER.V) / V
*/
void rPCR_03_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* der(PA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[143]] /* PA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_493(DATA *data, threadData_t *threadData);


/*
equation index: 280
type: SIMPLE_ASSIGN
$DER.BaPra.c = (BaPra.rNet - BaPra.c * $DER.V) / V
*/
void rPCR_03_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* der(BaPra.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* BaPra.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_366(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_447(DATA *data, threadData_t *threadData);


/*
equation index: 283
type: SIMPLE_ASSIGN
$DER.BaPA.c = (BaPA.rNet - BaPA.c * $DER.V) / V
*/
void rPCR_03_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* der(BaPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* BaPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_368(DATA *data, threadData_t *threadData);


/*
equation index: 285
type: SIMPLE_ASSIGN
BaPraPAPoly.c = $START.BaPraPAPoly.c
*/
void rPCR_03_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */) = (data->modelData->realVarsData[24] /* BaPraPAPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_346(DATA *data, threadData_t *threadData);


/*
equation index: 287
type: SIMPLE_ASSIGN
$PRE.dProbeA = dProbeA
*/
void rPCR_03_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  (data->simulationInfo->realVarsPre[280] /* dProbeA variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[280]] /* dProbeA variable */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_349(DATA *data, threadData_t *threadData);


/*
equation index: 289
type: SIMPLE_ASSIGN
$PRE.totalBa = totalBa
*/
void rPCR_03_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  (data->simulationInfo->realVarsPre[325] /* totalBa variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[325]] /* totalBa variable */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_363(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_449(DATA *data, threadData_t *threadData);


/*
equation index: 292
type: SIMPLE_ASSIGN
$DER.signalA.c = (signalA.rNet - signalA.c * $DER.V) / V
*/
void rPCR_03_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* der(signalA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[320]] /* signalA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_467(DATA *data, threadData_t *threadData);


/*
equation index: 294
type: SIMPLE_ASSIGN
$DER.BaBs.c = (BaBs.rNet - BaBs.c * $DER.V) / V
*/
void rPCR_03_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* der(BaBs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* BaBs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_364(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_365(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_443(DATA *data, threadData_t *threadData);


/*
equation index: 298
type: SIMPLE_ASSIGN
$DER.BaPraPAPoly.c = (BaPraPAPoly.rNet - BaPraPAPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* der(BaPraPAPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[125]] /* BaPraPAPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_445(DATA *data, threadData_t *threadData);


/*
equation index: 300
type: SIMPLE_ASSIGN
$DER.BaPraPA.c = (BaPraPA.rNet - BaPraPA.c * $DER.V) / V
*/
void rPCR_03_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* der(BaPraPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[123]] /* BaPraPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 301
type: SIMPLE_ASSIGN
AaPB.c = $START.AaPB.c
*/
void rPCR_03_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */) = (data->modelData->realVarsData[5] /* AaPB.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_359(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_503(DATA *data, threadData_t *threadData);


/*
equation index: 304
type: SIMPLE_ASSIGN
$DER.Aa.c = (Aa.rNet - Aa.c * $DER.V) / V
*/
void rPCR_03_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* der(Aa.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* Aa.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_361(DATA *data, threadData_t *threadData);


/*
equation index: 306
type: SIMPLE_ASSIGN
AaPraPB.c = $START.AaPraPB.c
*/
void rPCR_03_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */) = (data->modelData->realVarsData[7] /* AaPraPB.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_354(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_465(DATA *data, threadData_t *threadData);


/*
equation index: 309
type: SIMPLE_ASSIGN
$DER.AaPra.c = (AaPra.rNet - AaPra.c * $DER.V) / V
*/
void rPCR_03_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* der(AaPra.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* AaPra.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_475(DATA *data, threadData_t *threadData);


/*
equation index: 311
type: SIMPLE_ASSIGN
$DER.PB.c = (PB.rNet - PB.c * $DER.V) / V
*/
void rPCR_03_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* der(PB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[145]] /* PB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_358(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_441(DATA *data, threadData_t *threadData);


/*
equation index: 314
type: SIMPLE_ASSIGN
$DER.AaPB.c = (AaPB.rNet - AaPB.c * $DER.V) / V
*/
void rPCR_03_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* der(AaPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* AaPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_495(DATA *data, threadData_t *threadData);


/*
equation index: 316
type: SIMPLE_ASSIGN
$DER.Pra.c = (Pra.rNet - Pra.c * $DER.V) / V
*/
void rPCR_03_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* der(Pra.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[149]] /* Pra.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_360(DATA *data, threadData_t *threadData);


/*
equation index: 318
type: SIMPLE_ASSIGN
AaPraPBPoly.c = $START.AaPraPBPoly.c
*/
void rPCR_03_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */) = (data->modelData->realVarsData[8] /* AaPraPBPoly.c STATE(1) */).attribute .start;
  TRACE_POP
}
extern void rPCR_03_eqFunction_345(DATA *data, threadData_t *threadData);


/*
equation index: 320
type: SIMPLE_ASSIGN
$PRE.dProbeB = dProbeB
*/
void rPCR_03_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  (data->simulationInfo->realVarsPre[281] /* dProbeB variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[281]] /* dProbeB variable */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_347(DATA *data, threadData_t *threadData);


/*
equation index: 322
type: SIMPLE_ASSIGN
$PRE.totalPra = totalPra
*/
void rPCR_03_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  (data->simulationInfo->realVarsPre[327] /* totalPra variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[327]] /* totalPra variable */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_351(DATA *data, threadData_t *threadData);


/*
equation index: 324
type: SIMPLE_ASSIGN
$PRE.totalAa = totalAa
*/
void rPCR_03_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,324};
  (data->simulationInfo->realVarsPre[323] /* totalAa variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[323]] /* totalAa variable */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_353(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_355(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_451(DATA *data, threadData_t *threadData);


/*
equation index: 328
type: SIMPLE_ASSIGN
$DER.signalB.c = (signalB.rNet - signalB.c * $DER.V) / V
*/
void rPCR_03_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* der(signalB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[322]] /* signalB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_469(DATA *data, threadData_t *threadData);


/*
equation index: 330
type: SIMPLE_ASSIGN
$DER.AaAs.c = (AaAs.rNet - AaAs.c * $DER.V) / V
*/
void rPCR_03_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* der(AaAs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* AaAs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_356(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_357(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_437(DATA *data, threadData_t *threadData);


/*
equation index: 334
type: SIMPLE_ASSIGN
$DER.AaPraPBPoly.c = (AaPraPBPoly.rNet - AaPraPBPoly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* der(AaPraPBPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* AaPraPBPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_439(DATA *data, threadData_t *threadData);


/*
equation index: 336
type: SIMPLE_ASSIGN
$DER.AaPraPB.c = (AaPraPB.rNet - AaPraPB.c * $DER.V) / V
*/
void rPCR_03_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* der(AaPraPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* AaPraPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
extern void rPCR_03_eqFunction_471(DATA *data, threadData_t *threadData);


/*
equation index: 338
type: SIMPLE_ASSIGN
$DER.Poly.c = (Poly.rNet - Poly.c * $DER.V) / V
*/
void rPCR_03_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* der(Poly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* Poly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}

/*
equation index: 339
type: SIMPLE_ASSIGN
$whenCondition1 = false
*/
void rPCR_03_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = 0 /* false */;
  TRACE_POP
}
extern void rPCR_03_eqFunction_507(DATA *data, threadData_t *threadData);

OMC_DISABLE_OPT
void rPCR_03_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  rPCR_03_eqFunction_1(data, threadData);
  rPCR_03_eqFunction_2(data, threadData);
  rPCR_03_eqFunction_3(data, threadData);
  rPCR_03_eqFunction_4(data, threadData);
  rPCR_03_eqFunction_5(data, threadData);
  rPCR_03_eqFunction_6(data, threadData);
  rPCR_03_eqFunction_7(data, threadData);
  rPCR_03_eqFunction_8(data, threadData);
  rPCR_03_eqFunction_9(data, threadData);
  rPCR_03_eqFunction_10(data, threadData);
  rPCR_03_eqFunction_11(data, threadData);
  rPCR_03_eqFunction_12(data, threadData);
  rPCR_03_eqFunction_13(data, threadData);
  rPCR_03_eqFunction_14(data, threadData);
  rPCR_03_eqFunction_15(data, threadData);
  rPCR_03_eqFunction_16(data, threadData);
  rPCR_03_eqFunction_17(data, threadData);
  rPCR_03_eqFunction_18(data, threadData);
  rPCR_03_eqFunction_19(data, threadData);
  rPCR_03_eqFunction_20(data, threadData);
  rPCR_03_eqFunction_21(data, threadData);
  rPCR_03_eqFunction_22(data, threadData);
  rPCR_03_eqFunction_23(data, threadData);
  rPCR_03_eqFunction_24(data, threadData);
  rPCR_03_eqFunction_25(data, threadData);
  rPCR_03_eqFunction_26(data, threadData);
  rPCR_03_eqFunction_27(data, threadData);
  rPCR_03_eqFunction_28(data, threadData);
  rPCR_03_eqFunction_29(data, threadData);
  rPCR_03_eqFunction_30(data, threadData);
  rPCR_03_eqFunction_31(data, threadData);
  rPCR_03_eqFunction_32(data, threadData);
  rPCR_03_eqFunction_33(data, threadData);
  rPCR_03_eqFunction_34(data, threadData);
  rPCR_03_eqFunction_35(data, threadData);
  rPCR_03_eqFunction_36(data, threadData);
  rPCR_03_eqFunction_37(data, threadData);
  rPCR_03_eqFunction_38(data, threadData);
  rPCR_03_eqFunction_39(data, threadData);
  rPCR_03_eqFunction_40(data, threadData);
  rPCR_03_eqFunction_41(data, threadData);
  rPCR_03_eqFunction_42(data, threadData);
  rPCR_03_eqFunction_43(data, threadData);
  rPCR_03_eqFunction_44(data, threadData);
  rPCR_03_eqFunction_45(data, threadData);
  rPCR_03_eqFunction_46(data, threadData);
  rPCR_03_eqFunction_47(data, threadData);
  rPCR_03_eqFunction_48(data, threadData);
  rPCR_03_eqFunction_49(data, threadData);
  rPCR_03_eqFunction_50(data, threadData);
  rPCR_03_eqFunction_51(data, threadData);
  rPCR_03_eqFunction_52(data, threadData);
  rPCR_03_eqFunction_53(data, threadData);
  rPCR_03_eqFunction_54(data, threadData);
  rPCR_03_eqFunction_55(data, threadData);
  rPCR_03_eqFunction_56(data, threadData);
  rPCR_03_eqFunction_57(data, threadData);
  rPCR_03_eqFunction_58(data, threadData);
  rPCR_03_eqFunction_59(data, threadData);
  rPCR_03_eqFunction_60(data, threadData);
  rPCR_03_eqFunction_61(data, threadData);
  rPCR_03_eqFunction_62(data, threadData);
  rPCR_03_eqFunction_63(data, threadData);
  rPCR_03_eqFunction_64(data, threadData);
  rPCR_03_eqFunction_65(data, threadData);
  rPCR_03_eqFunction_66(data, threadData);
  rPCR_03_eqFunction_67(data, threadData);
  rPCR_03_eqFunction_68(data, threadData);
  rPCR_03_eqFunction_69(data, threadData);
  rPCR_03_eqFunction_70(data, threadData);
  rPCR_03_eqFunction_71(data, threadData);
  rPCR_03_eqFunction_72(data, threadData);
  rPCR_03_eqFunction_73(data, threadData);
  rPCR_03_eqFunction_74(data, threadData);
  rPCR_03_eqFunction_75(data, threadData);
  rPCR_03_eqFunction_76(data, threadData);
  rPCR_03_eqFunction_77(data, threadData);
  rPCR_03_eqFunction_78(data, threadData);
  rPCR_03_eqFunction_79(data, threadData);
  rPCR_03_eqFunction_80(data, threadData);
  rPCR_03_eqFunction_81(data, threadData);
  rPCR_03_eqFunction_82(data, threadData);
  rPCR_03_eqFunction_83(data, threadData);
  rPCR_03_eqFunction_84(data, threadData);
  rPCR_03_eqFunction_85(data, threadData);
  rPCR_03_eqFunction_86(data, threadData);
  rPCR_03_eqFunction_87(data, threadData);
  rPCR_03_eqFunction_88(data, threadData);
  rPCR_03_eqFunction_89(data, threadData);
  rPCR_03_eqFunction_90(data, threadData);
  rPCR_03_eqFunction_91(data, threadData);
  rPCR_03_eqFunction_92(data, threadData);
  rPCR_03_eqFunction_93(data, threadData);
  rPCR_03_eqFunction_94(data, threadData);
  rPCR_03_eqFunction_95(data, threadData);
  rPCR_03_eqFunction_96(data, threadData);
  rPCR_03_eqFunction_97(data, threadData);
  rPCR_03_eqFunction_98(data, threadData);
  rPCR_03_eqFunction_99(data, threadData);
  rPCR_03_eqFunction_100(data, threadData);
  rPCR_03_eqFunction_101(data, threadData);
  rPCR_03_eqFunction_102(data, threadData);
  rPCR_03_eqFunction_103(data, threadData);
  rPCR_03_eqFunction_104(data, threadData);
  rPCR_03_eqFunction_105(data, threadData);
  rPCR_03_eqFunction_106(data, threadData);
  rPCR_03_eqFunction_107(data, threadData);
  rPCR_03_eqFunction_108(data, threadData);
  rPCR_03_eqFunction_109(data, threadData);
  rPCR_03_eqFunction_110(data, threadData);
  rPCR_03_eqFunction_111(data, threadData);
  rPCR_03_eqFunction_112(data, threadData);
  rPCR_03_eqFunction_113(data, threadData);
  rPCR_03_eqFunction_114(data, threadData);
  rPCR_03_eqFunction_115(data, threadData);
  rPCR_03_eqFunction_116(data, threadData);
  rPCR_03_eqFunction_117(data, threadData);
  rPCR_03_eqFunction_118(data, threadData);
  rPCR_03_eqFunction_119(data, threadData);
  rPCR_03_eqFunction_120(data, threadData);
  rPCR_03_eqFunction_121(data, threadData);
  rPCR_03_eqFunction_122(data, threadData);
  rPCR_03_eqFunction_123(data, threadData);
  rPCR_03_eqFunction_124(data, threadData);
  rPCR_03_eqFunction_125(data, threadData);
  rPCR_03_eqFunction_342(data, threadData);
  rPCR_03_eqFunction_127(data, threadData);
  rPCR_03_eqFunction_128(data, threadData);
  rPCR_03_eqFunction_436(data, threadData);
  rPCR_03_eqFunction_130(data, threadData);
  rPCR_03_eqFunction_435(data, threadData);
  rPCR_03_eqFunction_132(data, threadData);
  rPCR_03_eqFunction_434(data, threadData);
  rPCR_03_eqFunction_134(data, threadData);
  rPCR_03_eqFunction_433(data, threadData);
  rPCR_03_eqFunction_136(data, threadData);
  rPCR_03_eqFunction_432(data, threadData);
  rPCR_03_eqFunction_138(data, threadData);
  rPCR_03_eqFunction_431(data, threadData);
  rPCR_03_eqFunction_140(data, threadData);
  rPCR_03_eqFunction_430(data, threadData);
  rPCR_03_eqFunction_142(data, threadData);
  rPCR_03_eqFunction_429(data, threadData);
  rPCR_03_eqFunction_144(data, threadData);
  rPCR_03_eqFunction_428(data, threadData);
  rPCR_03_eqFunction_146(data, threadData);
  rPCR_03_eqFunction_396(data, threadData);
  rPCR_03_eqFunction_427(data, threadData);
  rPCR_03_eqFunction_149(data, threadData);
  rPCR_03_eqFunction_397(data, threadData);
  rPCR_03_eqFunction_426(data, threadData);
  rPCR_03_eqFunction_152(data, threadData);
  rPCR_03_eqFunction_399(data, threadData);
  rPCR_03_eqFunction_425(data, threadData);
  rPCR_03_eqFunction_155(data, threadData);
  rPCR_03_eqFunction_398(data, threadData);
  rPCR_03_eqFunction_424(data, threadData);
  rPCR_03_eqFunction_158(data, threadData);
  rPCR_03_eqFunction_385(data, threadData);
  rPCR_03_eqFunction_160(data, threadData);
  rPCR_03_eqFunction_423(data, threadData);
  rPCR_03_eqFunction_162(data, threadData);
  rPCR_03_eqFunction_384(data, threadData);
  rPCR_03_eqFunction_164(data, threadData);
  rPCR_03_eqFunction_421(data, threadData);
  rPCR_03_eqFunction_166(data, threadData);
  rPCR_03_eqFunction_395(data, threadData);
  rPCR_03_eqFunction_419(data, threadData);
  rPCR_03_eqFunction_169(data, threadData);
  rPCR_03_eqFunction_394(data, threadData);
  rPCR_03_eqFunction_418(data, threadData);
  rPCR_03_eqFunction_172(data, threadData);
  rPCR_03_eqFunction_393(data, threadData);
  rPCR_03_eqFunction_417(data, threadData);
  rPCR_03_eqFunction_175(data, threadData);
  rPCR_03_eqFunction_392(data, threadData);
  rPCR_03_eqFunction_416(data, threadData);
  rPCR_03_eqFunction_178(data, threadData);
  rPCR_03_eqFunction_388(data, threadData);
  rPCR_03_eqFunction_491(data, threadData);
  rPCR_03_eqFunction_181(data, threadData);
  rPCR_03_eqFunction_415(data, threadData);
  rPCR_03_eqFunction_183(data, threadData);
  rPCR_03_eqFunction_389(data, threadData);
  rPCR_03_eqFunction_505(data, threadData);
  rPCR_03_eqFunction_186(data, threadData);
  rPCR_03_eqFunction_414(data, threadData);
  rPCR_03_eqFunction_188(data, threadData);
  rPCR_03_eqFunction_387(data, threadData);
  rPCR_03_eqFunction_390(data, threadData);
  rPCR_03_eqFunction_485(data, threadData);
  rPCR_03_eqFunction_192(data, threadData);
  rPCR_03_eqFunction_413(data, threadData);
  rPCR_03_eqFunction_194(data, threadData);
  rPCR_03_eqFunction_386(data, threadData);
  rPCR_03_eqFunction_391(data, threadData);
  rPCR_03_eqFunction_483(data, threadData);
  rPCR_03_eqFunction_198(data, threadData);
  rPCR_03_eqFunction_489(data, threadData);
  rPCR_03_eqFunction_200(data, threadData);
  rPCR_03_eqFunction_412(data, threadData);
  rPCR_03_eqFunction_202(data, threadData);
  rPCR_03_eqFunction_370(data, threadData);
  rPCR_03_eqFunction_381(data, threadData);
  rPCR_03_eqFunction_463(data, threadData);
  rPCR_03_eqFunction_206(data, threadData);
  rPCR_03_eqFunction_411(data, threadData);
  rPCR_03_eqFunction_208(data, threadData);
  rPCR_03_eqFunction_372(data, threadData);
  rPCR_03_eqFunction_379(data, threadData);
  rPCR_03_eqFunction_459(data, threadData);
  rPCR_03_eqFunction_477(data, threadData);
  rPCR_03_eqFunction_213(data, threadData);
  rPCR_03_eqFunction_214(data, threadData);
  rPCR_03_eqFunction_410(data, threadData);
  rPCR_03_eqFunction_216(data, threadData);
  rPCR_03_eqFunction_373(data, threadData);
  rPCR_03_eqFunction_380(data, threadData);
  rPCR_03_eqFunction_461(data, threadData);
  rPCR_03_eqFunction_479(data, threadData);
  rPCR_03_eqFunction_221(data, threadData);
  rPCR_03_eqFunction_222(data, threadData);
  rPCR_03_eqFunction_409(data, threadData);
  rPCR_03_eqFunction_224(data, threadData);
  rPCR_03_eqFunction_371(data, threadData);
  rPCR_03_eqFunction_378(data, threadData);
  rPCR_03_eqFunction_457(data, threadData);
  rPCR_03_eqFunction_228(data, threadData);
  rPCR_03_eqFunction_408(data, threadData);
  rPCR_03_eqFunction_230(data, threadData);
  rPCR_03_eqFunction_374(data, threadData);
  rPCR_03_eqFunction_376(data, threadData);
  rPCR_03_eqFunction_453(data, threadData);
  rPCR_03_eqFunction_473(data, threadData);
  rPCR_03_eqFunction_235(data, threadData);
  rPCR_03_eqFunction_236(data, threadData);
  rPCR_03_eqFunction_407(data, threadData);
  rPCR_03_eqFunction_238(data, threadData);
  rPCR_03_eqFunction_348(data, threadData);
  rPCR_03_eqFunction_375(data, threadData);
  rPCR_03_eqFunction_377(data, threadData);
  rPCR_03_eqFunction_455(data, threadData);
  rPCR_03_eqFunction_487(data, threadData);
  rPCR_03_eqFunction_244(data, threadData);
  rPCR_03_eqFunction_245(data, threadData);
  rPCR_03_eqFunction_406(data, threadData);
  rPCR_03_eqFunction_247(data, threadData);
  rPCR_03_eqFunction_352(data, threadData);
  rPCR_03_eqFunction_382(data, threadData);
  rPCR_03_eqFunction_497(data, threadData);
  rPCR_03_eqFunction_251(data, threadData);
  rPCR_03_eqFunction_252(data, threadData);
  rPCR_03_eqFunction_405(data, threadData);
  rPCR_03_eqFunction_254(data, threadData);
  rPCR_03_eqFunction_350(data, threadData);
  rPCR_03_eqFunction_383(data, threadData);
  rPCR_03_eqFunction_501(data, threadData);
  rPCR_03_eqFunction_258(data, threadData);
  rPCR_03_eqFunction_259(data, threadData);
  rPCR_03_eqFunction_403(data, threadData);
  rPCR_03_eqFunction_261(data, threadData);
  rPCR_03_eqFunction_344(data, threadData);
  rPCR_03_eqFunction_401(data, threadData);
  rPCR_03_eqFunction_264(data, threadData);
  rPCR_03_eqFunction_343(data, threadData);
  rPCR_03_eqFunction_400(data, threadData);
  rPCR_03_eqFunction_267(data, threadData);
  rPCR_03_eqFunction_268(data, threadData);
  rPCR_03_eqFunction_269(data, threadData);
  rPCR_03_eqFunction_270(data, threadData);
  rPCR_03_eqFunction_367(data, threadData);
  rPCR_03_eqFunction_499(data, threadData);
  rPCR_03_eqFunction_273(data, threadData);
  rPCR_03_eqFunction_369(data, threadData);
  rPCR_03_eqFunction_275(data, threadData);
  rPCR_03_eqFunction_362(data, threadData);
  rPCR_03_eqFunction_481(data, threadData);
  rPCR_03_eqFunction_278(data, threadData);
  rPCR_03_eqFunction_493(data, threadData);
  rPCR_03_eqFunction_280(data, threadData);
  rPCR_03_eqFunction_366(data, threadData);
  rPCR_03_eqFunction_447(data, threadData);
  rPCR_03_eqFunction_283(data, threadData);
  rPCR_03_eqFunction_368(data, threadData);
  rPCR_03_eqFunction_285(data, threadData);
  rPCR_03_eqFunction_346(data, threadData);
  rPCR_03_eqFunction_287(data, threadData);
  rPCR_03_eqFunction_349(data, threadData);
  rPCR_03_eqFunction_289(data, threadData);
  rPCR_03_eqFunction_363(data, threadData);
  rPCR_03_eqFunction_449(data, threadData);
  rPCR_03_eqFunction_292(data, threadData);
  rPCR_03_eqFunction_467(data, threadData);
  rPCR_03_eqFunction_294(data, threadData);
  rPCR_03_eqFunction_364(data, threadData);
  rPCR_03_eqFunction_365(data, threadData);
  rPCR_03_eqFunction_443(data, threadData);
  rPCR_03_eqFunction_298(data, threadData);
  rPCR_03_eqFunction_445(data, threadData);
  rPCR_03_eqFunction_300(data, threadData);
  rPCR_03_eqFunction_301(data, threadData);
  rPCR_03_eqFunction_359(data, threadData);
  rPCR_03_eqFunction_503(data, threadData);
  rPCR_03_eqFunction_304(data, threadData);
  rPCR_03_eqFunction_361(data, threadData);
  rPCR_03_eqFunction_306(data, threadData);
  rPCR_03_eqFunction_354(data, threadData);
  rPCR_03_eqFunction_465(data, threadData);
  rPCR_03_eqFunction_309(data, threadData);
  rPCR_03_eqFunction_475(data, threadData);
  rPCR_03_eqFunction_311(data, threadData);
  rPCR_03_eqFunction_358(data, threadData);
  rPCR_03_eqFunction_441(data, threadData);
  rPCR_03_eqFunction_314(data, threadData);
  rPCR_03_eqFunction_495(data, threadData);
  rPCR_03_eqFunction_316(data, threadData);
  rPCR_03_eqFunction_360(data, threadData);
  rPCR_03_eqFunction_318(data, threadData);
  rPCR_03_eqFunction_345(data, threadData);
  rPCR_03_eqFunction_320(data, threadData);
  rPCR_03_eqFunction_347(data, threadData);
  rPCR_03_eqFunction_322(data, threadData);
  rPCR_03_eqFunction_351(data, threadData);
  rPCR_03_eqFunction_324(data, threadData);
  rPCR_03_eqFunction_353(data, threadData);
  rPCR_03_eqFunction_355(data, threadData);
  rPCR_03_eqFunction_451(data, threadData);
  rPCR_03_eqFunction_328(data, threadData);
  rPCR_03_eqFunction_469(data, threadData);
  rPCR_03_eqFunction_330(data, threadData);
  rPCR_03_eqFunction_356(data, threadData);
  rPCR_03_eqFunction_357(data, threadData);
  rPCR_03_eqFunction_437(data, threadData);
  rPCR_03_eqFunction_334(data, threadData);
  rPCR_03_eqFunction_439(data, threadData);
  rPCR_03_eqFunction_336(data, threadData);
  rPCR_03_eqFunction_471(data, threadData);
  rPCR_03_eqFunction_338(data, threadData);
  rPCR_03_eqFunction_339(data, threadData);
  rPCR_03_eqFunction_507(data, threadData);
  TRACE_POP
}

int rPCR_03_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  rPCR_03_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No rPCR_03_functionInitialEquations_lambda0 function */

int rPCR_03_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

