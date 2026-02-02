/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "rPCR_03_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation rPCR_03_performSimulation
#define prefixedName_updateContinuousSystem rPCR_03_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation rPCR_03_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int rPCR_03_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int rPCR_03_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int rPCR_03_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 341
type: SIMPLE_ASSIGN
$whenCondition1 = sample(1, cycle_time, cycle_time)
*/
void rPCR_03_eqFunction_341(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,341};
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];
  TRACE_POP
}
/*
equation index: 342
type: SIMPLE_ASSIGN
$DER.V = 0.0
*/
void rPCR_03_eqFunction_342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,342};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 343
type: SIMPLE_ASSIGN
FluoB = if signalB.c * sFluoB > lFluoB then bFluoB + signalB.c * sFluoB else bFluoB
*/
void rPCR_03_eqFunction_343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,343};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp1 = (1e-6) * (fabs((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)));
  tmp2 = fabs((data->simulationInfo->realParameter[234] /* lFluoB PARAM */));
  relationhysteresis(data, &tmp0, ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)), (data->simulationInfo->realParameter[234] /* lFluoB PARAM */), tmp1, tmp2, 1, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[141]] /* FluoB variable */) = (tmp0?(data->simulationInfo->realParameter[208] /* bFluoB PARAM */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)):(data->simulationInfo->realParameter[208] /* bFluoB PARAM */));
  TRACE_POP
}
/*
equation index: 344
type: SIMPLE_ASSIGN
FluoA = if signalA.c * sFluoA > lFluoA then bFluoA + signalA.c * sFluoA else bFluoA
*/
void rPCR_03_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,344};
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  tmp4 = (1e-6) * (fabs((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)));
  tmp5 = fabs((data->simulationInfo->realParameter[233] /* lFluoA PARAM */));
  relationhysteresis(data, &tmp3, ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)), (data->simulationInfo->realParameter[233] /* lFluoA PARAM */), tmp4, tmp5, 0, Greater, GreaterZC);
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[140]] /* FluoA variable */) = (tmp3?(data->simulationInfo->realParameter[207] /* bFluoA PARAM */) + ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)):(data->simulationInfo->realParameter[207] /* bFluoA PARAM */));
  TRACE_POP
}
/*
equation index: 345
type: SIMPLE_ASSIGN
dProbeB = PB.c + BsPB.c + BsPrsPB.c + BsPrsPBPoly.c + AaPB.c + AaPraPB.c + AaPraPBPoly.c
*/
void rPCR_03_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[281]] /* dProbeB variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 346
type: SIMPLE_ASSIGN
dProbeA = PA.c + AsPA.c + AsPrsPA.c + AsPrsPAPoly.c + BaPA.c + BaPraPA.c + BaPraPAPoly.c
*/
void rPCR_03_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[280]] /* dProbeA variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 347
type: SIMPLE_ASSIGN
totalPra = Pra.c + AaPra.c + BaPra.c + BaPraPoly.c + AaPraPoly.c + BaPraPA.c + BaPraPAPoly.c + AaPraPB.c + AaPraPBPoly.c
*/
void rPCR_03_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[327]] /* totalPra variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 348
type: SIMPLE_ASSIGN
totalPrs = Prs.c + AsPrs.c + BsPrs.c + AsPrsPA.c + BsPrsPB.c + BsPrsPoly.c + BsPrsPBPoly.c + AsPrsPoly.c + AsPrsPAPoly.c
*/
void rPCR_03_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,348};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[328]] /* totalPrs variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 349
type: SIMPLE_ASSIGN
totalBa = Ba.c + AsBa.c + AsBaPoly.c + BaBs.c + BaBsPoly.c + BaPra.c + BaPraPoly.c + BaPA.c + BaPraPA.c + BaPraPAPoly.c
*/
void rPCR_03_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[325]] /* totalBa variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 350
type: SIMPLE_ASSIGN
totalBs = Bs.c + AaBs.c + AaBsPoly.c + BaBs.c + BaBsPoly.c + BsPrs.c + BsPB.c + BsPrsPB.c + BsPrsPoly.c + BsPrsPBPoly.c
*/
void rPCR_03_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[326]] /* totalBs variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 351
type: SIMPLE_ASSIGN
totalAa = Aa.c + AaBs.c + AaBsPoly.c + AaAs.c + AaAsPoly.c + AaPra.c + AaPraPoly.c + AaPB.c + AaPraPB.c + AaPraPBPoly.c
*/
void rPCR_03_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[323]] /* totalAa variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 352
type: SIMPLE_ASSIGN
totalAs = As.c + AsBa.c + AsBaPoly.c + AaAs.c + AaAsPoly.c + AsPrs.c + AsPA.c + AsPrsPA.c + AsPrsPoly.c + AsPrsPAPoly.c
*/
void rPCR_03_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[324]] /* totalAs variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */);
  TRACE_POP
}
/*
equation index: 353
type: SIMPLE_ASSIGN
ratio = (totalAs + totalAa) / (totalAs + totalAa + totalBs + totalBa)
*/
void rPCR_03_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[318]] /* ratio variable */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[324]] /* totalAs variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[323]] /* totalAa variable */),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[324]] /* totalAs variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[323]] /* totalAa variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[326]] /* totalBs variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[325]] /* totalBa variable */),"totalAs + totalAa + totalBs + totalBa",equationIndexes);
  TRACE_POP
}
/*
equation index: 354
type: SIMPLE_ASSIGN
R_AaPra_PB_x_AaPraPB.rr = R_AaPra_PB_x_AaPraPB.k1 * AaPra.c ^ R_AaPra_PB_x_AaPraPB.nS1e * PB.c ^ R_AaPra_PB_x_AaPraPB.nS2e * V - R_AaPra_PB_x_AaPraPB.k2 * AaPraPB.c ^ R_AaPra_PB_x_AaPraPB.nP1e * V
*/
void rPCR_03_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  tmp6 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */);
  tmp7 = (data->simulationInfo->realParameter[60] /* R_AaPra_PB_x_AaPraPB.nS1e PARAM */);
  if(tmp6 < 0.0 && tmp7 != 0.0)
  {
    tmp9 = modf(tmp7, &tmp10);
    
    if(tmp9 > 0.5)
    {
      tmp9 -= 1.0;
      tmp10 += 1.0;
    }
    else if(tmp9 < -0.5)
    {
      tmp9 += 1.0;
      tmp10 -= 1.0;
    }
    
    if(fabs(tmp9) < 1e-10)
      tmp8 = pow(tmp6, tmp10);
    else
    {
      tmp12 = modf(1.0/tmp7, &tmp11);
      if(tmp12 > 0.5)
      {
        tmp12 -= 1.0;
        tmp11 += 1.0;
      }
      else if(tmp12 < -0.5)
      {
        tmp12 += 1.0;
        tmp11 -= 1.0;
      }
      if(fabs(tmp12) < 1e-10 && ((unsigned long)tmp11 & 1))
      {
        tmp8 = -pow(-tmp6, tmp9)*pow(tmp6, tmp10);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp6, tmp7);
      }
    }
  }
  else
  {
    tmp8 = pow(tmp6, tmp7);
  }
  if(isnan(tmp8) || isinf(tmp8))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp6, tmp7);
  }tmp13 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */);
  tmp14 = (data->simulationInfo->realParameter[61] /* R_AaPra_PB_x_AaPraPB.nS2e PARAM */);
  if(tmp13 < 0.0 && tmp14 != 0.0)
  {
    tmp16 = modf(tmp14, &tmp17);
    
    if(tmp16 > 0.5)
    {
      tmp16 -= 1.0;
      tmp17 += 1.0;
    }
    else if(tmp16 < -0.5)
    {
      tmp16 += 1.0;
      tmp17 -= 1.0;
    }
    
    if(fabs(tmp16) < 1e-10)
      tmp15 = pow(tmp13, tmp17);
    else
    {
      tmp19 = modf(1.0/tmp14, &tmp18);
      if(tmp19 > 0.5)
      {
        tmp19 -= 1.0;
        tmp18 += 1.0;
      }
      else if(tmp19 < -0.5)
      {
        tmp19 += 1.0;
        tmp18 -= 1.0;
      }
      if(fabs(tmp19) < 1e-10 && ((unsigned long)tmp18 & 1))
      {
        tmp15 = -pow(-tmp13, tmp16)*pow(tmp13, tmp17);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp13, tmp14);
      }
    }
  }
  else
  {
    tmp15 = pow(tmp13, tmp14);
  }
  if(isnan(tmp15) || isinf(tmp15))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp13, tmp14);
  }tmp20 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */);
  tmp21 = (data->simulationInfo->realParameter[59] /* R_AaPra_PB_x_AaPraPB.nP1e PARAM */);
  if(tmp20 < 0.0 && tmp21 != 0.0)
  {
    tmp23 = modf(tmp21, &tmp24);
    
    if(tmp23 > 0.5)
    {
      tmp23 -= 1.0;
      tmp24 += 1.0;
    }
    else if(tmp23 < -0.5)
    {
      tmp23 += 1.0;
      tmp24 -= 1.0;
    }
    
    if(fabs(tmp23) < 1e-10)
      tmp22 = pow(tmp20, tmp24);
    else
    {
      tmp26 = modf(1.0/tmp21, &tmp25);
      if(tmp26 > 0.5)
      {
        tmp26 -= 1.0;
        tmp25 += 1.0;
      }
      else if(tmp26 < -0.5)
      {
        tmp26 += 1.0;
        tmp25 -= 1.0;
      }
      if(fabs(tmp26) < 1e-10 && ((unsigned long)tmp25 & 1))
      {
        tmp22 = -pow(-tmp20, tmp23)*pow(tmp20, tmp24);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
      }
    }
  }
  else
  {
    tmp22 = pow(tmp20, tmp21);
  }
  if(isnan(tmp22) || isinf(tmp22))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* R_AaPra_PB_x_AaPraPB.rr variable */) = ((data->simulationInfo->realParameter[57] /* R_AaPra_PB_x_AaPraPB.k1 PARAM */)) * ((tmp8) * ((tmp15) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[58] /* R_AaPra_PB_x_AaPraPB.k2 PARAM */)) * ((tmp22) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 355
type: SIMPLE_ASSIGN
iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr = iR_AaPraPBPoly_x_AaAs_Poly_SignalB.k1 * AaPraPBPoly.c ^ iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nS1e * V
*/
void rPCR_03_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  tmp27 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */);
  tmp28 = (data->simulationInfo->realParameter[218] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nS1e PARAM */);
  if(tmp27 < 0.0 && tmp28 != 0.0)
  {
    tmp30 = modf(tmp28, &tmp31);
    
    if(tmp30 > 0.5)
    {
      tmp30 -= 1.0;
      tmp31 += 1.0;
    }
    else if(tmp30 < -0.5)
    {
      tmp30 += 1.0;
      tmp31 -= 1.0;
    }
    
    if(fabs(tmp30) < 1e-10)
      tmp29 = pow(tmp27, tmp31);
    else
    {
      tmp33 = modf(1.0/tmp28, &tmp32);
      if(tmp33 > 0.5)
      {
        tmp33 -= 1.0;
        tmp32 += 1.0;
      }
      else if(tmp33 < -0.5)
      {
        tmp33 += 1.0;
        tmp32 -= 1.0;
      }
      if(fabs(tmp33) < 1e-10 && ((unsigned long)tmp32 & 1))
      {
        tmp29 = -pow(-tmp27, tmp30)*pow(tmp27, tmp31);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp27, tmp28);
      }
    }
  }
  else
  {
    tmp29 = pow(tmp27, tmp28);
  }
  if(isnan(tmp29) || isinf(tmp29))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp27, tmp28);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[286]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr variable */) = ((data->simulationInfo->realParameter[217] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.k1 PARAM */)) * ((tmp29) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 356
type: SIMPLE_ASSIGN
AaPraPBPoly.n = AaPraPBPoly.c * V
*/
void rPCR_03_eqFunction_356(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,356};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* AaPraPBPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 357
type: SIMPLE_ASSIGN
R_AaPraPB_Poly_x_AaPraPBPoly.rr = R_AaPraPB_Poly_x_AaPraPBPoly.k1 * AaPraPB.c ^ R_AaPraPB_Poly_x_AaPraPBPoly.nS1e * Poly.c ^ R_AaPraPB_Poly_x_AaPraPBPoly.nS2e * V - R_AaPraPB_Poly_x_AaPraPBPoly.k2 * AaPraPBPoly.c ^ R_AaPraPB_Poly_x_AaPraPBPoly.nP1e * V
*/
void rPCR_03_eqFunction_357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,357};
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  modelica_real tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  modelica_real tmp45;
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_real tmp48;
  modelica_real tmp49;
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_real tmp52;
  modelica_real tmp53;
  modelica_real tmp54;
  tmp34 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */);
  tmp35 = (data->simulationInfo->realParameter[55] /* R_AaPraPB_Poly_x_AaPraPBPoly.nS1e PARAM */);
  if(tmp34 < 0.0 && tmp35 != 0.0)
  {
    tmp37 = modf(tmp35, &tmp38);
    
    if(tmp37 > 0.5)
    {
      tmp37 -= 1.0;
      tmp38 += 1.0;
    }
    else if(tmp37 < -0.5)
    {
      tmp37 += 1.0;
      tmp38 -= 1.0;
    }
    
    if(fabs(tmp37) < 1e-10)
      tmp36 = pow(tmp34, tmp38);
    else
    {
      tmp40 = modf(1.0/tmp35, &tmp39);
      if(tmp40 > 0.5)
      {
        tmp40 -= 1.0;
        tmp39 += 1.0;
      }
      else if(tmp40 < -0.5)
      {
        tmp40 += 1.0;
        tmp39 -= 1.0;
      }
      if(fabs(tmp40) < 1e-10 && ((unsigned long)tmp39 & 1))
      {
        tmp36 = -pow(-tmp34, tmp37)*pow(tmp34, tmp38);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp34, tmp35);
      }
    }
  }
  else
  {
    tmp36 = pow(tmp34, tmp35);
  }
  if(isnan(tmp36) || isinf(tmp36))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp34, tmp35);
  }tmp41 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp42 = (data->simulationInfo->realParameter[56] /* R_AaPraPB_Poly_x_AaPraPBPoly.nS2e PARAM */);
  if(tmp41 < 0.0 && tmp42 != 0.0)
  {
    tmp44 = modf(tmp42, &tmp45);
    
    if(tmp44 > 0.5)
    {
      tmp44 -= 1.0;
      tmp45 += 1.0;
    }
    else if(tmp44 < -0.5)
    {
      tmp44 += 1.0;
      tmp45 -= 1.0;
    }
    
    if(fabs(tmp44) < 1e-10)
      tmp43 = pow(tmp41, tmp45);
    else
    {
      tmp47 = modf(1.0/tmp42, &tmp46);
      if(tmp47 > 0.5)
      {
        tmp47 -= 1.0;
        tmp46 += 1.0;
      }
      else if(tmp47 < -0.5)
      {
        tmp47 += 1.0;
        tmp46 -= 1.0;
      }
      if(fabs(tmp47) < 1e-10 && ((unsigned long)tmp46 & 1))
      {
        tmp43 = -pow(-tmp41, tmp44)*pow(tmp41, tmp45);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp41, tmp42);
      }
    }
  }
  else
  {
    tmp43 = pow(tmp41, tmp42);
  }
  if(isnan(tmp43) || isinf(tmp43))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp41, tmp42);
  }tmp48 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */);
  tmp49 = (data->simulationInfo->realParameter[54] /* R_AaPraPB_Poly_x_AaPraPBPoly.nP1e PARAM */);
  if(tmp48 < 0.0 && tmp49 != 0.0)
  {
    tmp51 = modf(tmp49, &tmp52);
    
    if(tmp51 > 0.5)
    {
      tmp51 -= 1.0;
      tmp52 += 1.0;
    }
    else if(tmp51 < -0.5)
    {
      tmp51 += 1.0;
      tmp52 -= 1.0;
    }
    
    if(fabs(tmp51) < 1e-10)
      tmp50 = pow(tmp48, tmp52);
    else
    {
      tmp54 = modf(1.0/tmp49, &tmp53);
      if(tmp54 > 0.5)
      {
        tmp54 -= 1.0;
        tmp53 += 1.0;
      }
      else if(tmp54 < -0.5)
      {
        tmp54 += 1.0;
        tmp53 -= 1.0;
      }
      if(fabs(tmp54) < 1e-10 && ((unsigned long)tmp53 & 1))
      {
        tmp50 = -pow(-tmp48, tmp51)*pow(tmp48, tmp52);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp48, tmp49);
      }
    }
  }
  else
  {
    tmp50 = pow(tmp48, tmp49);
  }
  if(isnan(tmp50) || isinf(tmp50))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp48, tmp49);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* R_AaPraPB_Poly_x_AaPraPBPoly.rr variable */) = ((data->simulationInfo->realParameter[52] /* R_AaPraPB_Poly_x_AaPraPBPoly.k1 PARAM */)) * ((tmp36) * ((tmp43) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[53] /* R_AaPraPB_Poly_x_AaPraPBPoly.k2 PARAM */)) * ((tmp50) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 358
type: SIMPLE_ASSIGN
R_AaPB_Pra_x_AaPraPB.rr = R_AaPB_Pra_x_AaPraPB.k1 * AaPB.c ^ R_AaPB_Pra_x_AaPraPB.nS1e * Pra.c ^ R_AaPB_Pra_x_AaPraPB.nS2e * V - R_AaPB_Pra_x_AaPraPB.k2 * AaPraPB.c ^ R_AaPB_Pra_x_AaPraPB.nP1e * V
*/
void rPCR_03_eqFunction_358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,358};
  modelica_real tmp55;
  modelica_real tmp56;
  modelica_real tmp57;
  modelica_real tmp58;
  modelica_real tmp59;
  modelica_real tmp60;
  modelica_real tmp61;
  modelica_real tmp62;
  modelica_real tmp63;
  modelica_real tmp64;
  modelica_real tmp65;
  modelica_real tmp66;
  modelica_real tmp67;
  modelica_real tmp68;
  modelica_real tmp69;
  modelica_real tmp70;
  modelica_real tmp71;
  modelica_real tmp72;
  modelica_real tmp73;
  modelica_real tmp74;
  modelica_real tmp75;
  tmp55 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */);
  tmp56 = (data->simulationInfo->realParameter[50] /* R_AaPB_Pra_x_AaPraPB.nS1e PARAM */);
  if(tmp55 < 0.0 && tmp56 != 0.0)
  {
    tmp58 = modf(tmp56, &tmp59);
    
    if(tmp58 > 0.5)
    {
      tmp58 -= 1.0;
      tmp59 += 1.0;
    }
    else if(tmp58 < -0.5)
    {
      tmp58 += 1.0;
      tmp59 -= 1.0;
    }
    
    if(fabs(tmp58) < 1e-10)
      tmp57 = pow(tmp55, tmp59);
    else
    {
      tmp61 = modf(1.0/tmp56, &tmp60);
      if(tmp61 > 0.5)
      {
        tmp61 -= 1.0;
        tmp60 += 1.0;
      }
      else if(tmp61 < -0.5)
      {
        tmp61 += 1.0;
        tmp60 -= 1.0;
      }
      if(fabs(tmp61) < 1e-10 && ((unsigned long)tmp60 & 1))
      {
        tmp57 = -pow(-tmp55, tmp58)*pow(tmp55, tmp59);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp55, tmp56);
      }
    }
  }
  else
  {
    tmp57 = pow(tmp55, tmp56);
  }
  if(isnan(tmp57) || isinf(tmp57))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp55, tmp56);
  }tmp62 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */);
  tmp63 = (data->simulationInfo->realParameter[51] /* R_AaPB_Pra_x_AaPraPB.nS2e PARAM */);
  if(tmp62 < 0.0 && tmp63 != 0.0)
  {
    tmp65 = modf(tmp63, &tmp66);
    
    if(tmp65 > 0.5)
    {
      tmp65 -= 1.0;
      tmp66 += 1.0;
    }
    else if(tmp65 < -0.5)
    {
      tmp65 += 1.0;
      tmp66 -= 1.0;
    }
    
    if(fabs(tmp65) < 1e-10)
      tmp64 = pow(tmp62, tmp66);
    else
    {
      tmp68 = modf(1.0/tmp63, &tmp67);
      if(tmp68 > 0.5)
      {
        tmp68 -= 1.0;
        tmp67 += 1.0;
      }
      else if(tmp68 < -0.5)
      {
        tmp68 += 1.0;
        tmp67 -= 1.0;
      }
      if(fabs(tmp68) < 1e-10 && ((unsigned long)tmp67 & 1))
      {
        tmp64 = -pow(-tmp62, tmp65)*pow(tmp62, tmp66);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
      }
    }
  }
  else
  {
    tmp64 = pow(tmp62, tmp63);
  }
  if(isnan(tmp64) || isinf(tmp64))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
  }tmp69 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */);
  tmp70 = (data->simulationInfo->realParameter[49] /* R_AaPB_Pra_x_AaPraPB.nP1e PARAM */);
  if(tmp69 < 0.0 && tmp70 != 0.0)
  {
    tmp72 = modf(tmp70, &tmp73);
    
    if(tmp72 > 0.5)
    {
      tmp72 -= 1.0;
      tmp73 += 1.0;
    }
    else if(tmp72 < -0.5)
    {
      tmp72 += 1.0;
      tmp73 -= 1.0;
    }
    
    if(fabs(tmp72) < 1e-10)
      tmp71 = pow(tmp69, tmp73);
    else
    {
      tmp75 = modf(1.0/tmp70, &tmp74);
      if(tmp75 > 0.5)
      {
        tmp75 -= 1.0;
        tmp74 += 1.0;
      }
      else if(tmp75 < -0.5)
      {
        tmp75 += 1.0;
        tmp74 -= 1.0;
      }
      if(fabs(tmp75) < 1e-10 && ((unsigned long)tmp74 & 1))
      {
        tmp71 = -pow(-tmp69, tmp72)*pow(tmp69, tmp73);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp69, tmp70);
      }
    }
  }
  else
  {
    tmp71 = pow(tmp69, tmp70);
  }
  if(isnan(tmp71) || isinf(tmp71))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp69, tmp70);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* R_AaPB_Pra_x_AaPraPB.rr variable */) = ((data->simulationInfo->realParameter[47] /* R_AaPB_Pra_x_AaPraPB.k1 PARAM */)) * ((tmp57) * ((tmp64) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[48] /* R_AaPB_Pra_x_AaPraPB.k2 PARAM */)) * ((tmp71) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 359
type: SIMPLE_ASSIGN
R_Aa_PB_x_AaPB.rr = R_Aa_PB_x_AaPB.k1 * Aa.c ^ R_Aa_PB_x_AaPB.nS1e * PB.c ^ R_Aa_PB_x_AaPB.nS2e * V - R_Aa_PB_x_AaPB.k2 * AaPB.c ^ R_Aa_PB_x_AaPB.nP1e * V
*/
void rPCR_03_eqFunction_359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,359};
  modelica_real tmp76;
  modelica_real tmp77;
  modelica_real tmp78;
  modelica_real tmp79;
  modelica_real tmp80;
  modelica_real tmp81;
  modelica_real tmp82;
  modelica_real tmp83;
  modelica_real tmp84;
  modelica_real tmp85;
  modelica_real tmp86;
  modelica_real tmp87;
  modelica_real tmp88;
  modelica_real tmp89;
  modelica_real tmp90;
  modelica_real tmp91;
  modelica_real tmp92;
  modelica_real tmp93;
  modelica_real tmp94;
  modelica_real tmp95;
  modelica_real tmp96;
  tmp76 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */);
  tmp77 = (data->simulationInfo->realParameter[80] /* R_Aa_PB_x_AaPB.nS1e PARAM */);
  if(tmp76 < 0.0 && tmp77 != 0.0)
  {
    tmp79 = modf(tmp77, &tmp80);
    
    if(tmp79 > 0.5)
    {
      tmp79 -= 1.0;
      tmp80 += 1.0;
    }
    else if(tmp79 < -0.5)
    {
      tmp79 += 1.0;
      tmp80 -= 1.0;
    }
    
    if(fabs(tmp79) < 1e-10)
      tmp78 = pow(tmp76, tmp80);
    else
    {
      tmp82 = modf(1.0/tmp77, &tmp81);
      if(tmp82 > 0.5)
      {
        tmp82 -= 1.0;
        tmp81 += 1.0;
      }
      else if(tmp82 < -0.5)
      {
        tmp82 += 1.0;
        tmp81 -= 1.0;
      }
      if(fabs(tmp82) < 1e-10 && ((unsigned long)tmp81 & 1))
      {
        tmp78 = -pow(-tmp76, tmp79)*pow(tmp76, tmp80);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp76, tmp77);
      }
    }
  }
  else
  {
    tmp78 = pow(tmp76, tmp77);
  }
  if(isnan(tmp78) || isinf(tmp78))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp76, tmp77);
  }tmp83 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */);
  tmp84 = (data->simulationInfo->realParameter[81] /* R_Aa_PB_x_AaPB.nS2e PARAM */);
  if(tmp83 < 0.0 && tmp84 != 0.0)
  {
    tmp86 = modf(tmp84, &tmp87);
    
    if(tmp86 > 0.5)
    {
      tmp86 -= 1.0;
      tmp87 += 1.0;
    }
    else if(tmp86 < -0.5)
    {
      tmp86 += 1.0;
      tmp87 -= 1.0;
    }
    
    if(fabs(tmp86) < 1e-10)
      tmp85 = pow(tmp83, tmp87);
    else
    {
      tmp89 = modf(1.0/tmp84, &tmp88);
      if(tmp89 > 0.5)
      {
        tmp89 -= 1.0;
        tmp88 += 1.0;
      }
      else if(tmp89 < -0.5)
      {
        tmp89 += 1.0;
        tmp88 -= 1.0;
      }
      if(fabs(tmp89) < 1e-10 && ((unsigned long)tmp88 & 1))
      {
        tmp85 = -pow(-tmp83, tmp86)*pow(tmp83, tmp87);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp83, tmp84);
      }
    }
  }
  else
  {
    tmp85 = pow(tmp83, tmp84);
  }
  if(isnan(tmp85) || isinf(tmp85))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp83, tmp84);
  }tmp90 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */);
  tmp91 = (data->simulationInfo->realParameter[79] /* R_Aa_PB_x_AaPB.nP1e PARAM */);
  if(tmp90 < 0.0 && tmp91 != 0.0)
  {
    tmp93 = modf(tmp91, &tmp94);
    
    if(tmp93 > 0.5)
    {
      tmp93 -= 1.0;
      tmp94 += 1.0;
    }
    else if(tmp93 < -0.5)
    {
      tmp93 += 1.0;
      tmp94 -= 1.0;
    }
    
    if(fabs(tmp93) < 1e-10)
      tmp92 = pow(tmp90, tmp94);
    else
    {
      tmp96 = modf(1.0/tmp91, &tmp95);
      if(tmp96 > 0.5)
      {
        tmp96 -= 1.0;
        tmp95 += 1.0;
      }
      else if(tmp96 < -0.5)
      {
        tmp96 += 1.0;
        tmp95 -= 1.0;
      }
      if(fabs(tmp96) < 1e-10 && ((unsigned long)tmp95 & 1))
      {
        tmp92 = -pow(-tmp90, tmp93)*pow(tmp90, tmp94);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp90, tmp91);
      }
    }
  }
  else
  {
    tmp92 = pow(tmp90, tmp91);
  }
  if(isnan(tmp92) || isinf(tmp92))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp90, tmp91);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[187]] /* R_Aa_PB_x_AaPB.rr variable */) = ((data->simulationInfo->realParameter[77] /* R_Aa_PB_x_AaPB.k1 PARAM */)) * ((tmp78) * ((tmp85) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[78] /* R_Aa_PB_x_AaPB.k2 PARAM */)) * ((tmp92) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 360
type: SIMPLE_ASSIGN
AaPraPB.n = AaPraPB.c * V
*/
void rPCR_03_eqFunction_360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,360};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* AaPraPB.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 361
type: SIMPLE_ASSIGN
AaPB.n = AaPB.c * V
*/
void rPCR_03_eqFunction_361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,361};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* AaPB.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 362
type: SIMPLE_ASSIGN
R_BaPra_PA_x_BaPraPA.rr = R_BaPra_PA_x_BaPraPA.k1 * PA.c ^ R_BaPra_PA_x_BaPraPA.nS1e * BaPra.c ^ R_BaPra_PA_x_BaPraPA.nS2e * V - R_BaPra_PA_x_BaPraPA.k2 * BaPraPA.c ^ R_BaPra_PA_x_BaPraPA.nP1e * V
*/
void rPCR_03_eqFunction_362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,362};
  modelica_real tmp97;
  modelica_real tmp98;
  modelica_real tmp99;
  modelica_real tmp100;
  modelica_real tmp101;
  modelica_real tmp102;
  modelica_real tmp103;
  modelica_real tmp104;
  modelica_real tmp105;
  modelica_real tmp106;
  modelica_real tmp107;
  modelica_real tmp108;
  modelica_real tmp109;
  modelica_real tmp110;
  modelica_real tmp111;
  modelica_real tmp112;
  modelica_real tmp113;
  modelica_real tmp114;
  modelica_real tmp115;
  modelica_real tmp116;
  modelica_real tmp117;
  tmp97 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */);
  tmp98 = (data->simulationInfo->realParameter[145] /* R_BaPra_PA_x_BaPraPA.nS1e PARAM */);
  if(tmp97 < 0.0 && tmp98 != 0.0)
  {
    tmp100 = modf(tmp98, &tmp101);
    
    if(tmp100 > 0.5)
    {
      tmp100 -= 1.0;
      tmp101 += 1.0;
    }
    else if(tmp100 < -0.5)
    {
      tmp100 += 1.0;
      tmp101 -= 1.0;
    }
    
    if(fabs(tmp100) < 1e-10)
      tmp99 = pow(tmp97, tmp101);
    else
    {
      tmp103 = modf(1.0/tmp98, &tmp102);
      if(tmp103 > 0.5)
      {
        tmp103 -= 1.0;
        tmp102 += 1.0;
      }
      else if(tmp103 < -0.5)
      {
        tmp103 += 1.0;
        tmp102 -= 1.0;
      }
      if(fabs(tmp103) < 1e-10 && ((unsigned long)tmp102 & 1))
      {
        tmp99 = -pow(-tmp97, tmp100)*pow(tmp97, tmp101);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp97, tmp98);
      }
    }
  }
  else
  {
    tmp99 = pow(tmp97, tmp98);
  }
  if(isnan(tmp99) || isinf(tmp99))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp97, tmp98);
  }tmp104 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */);
  tmp105 = (data->simulationInfo->realParameter[146] /* R_BaPra_PA_x_BaPraPA.nS2e PARAM */);
  if(tmp104 < 0.0 && tmp105 != 0.0)
  {
    tmp107 = modf(tmp105, &tmp108);
    
    if(tmp107 > 0.5)
    {
      tmp107 -= 1.0;
      tmp108 += 1.0;
    }
    else if(tmp107 < -0.5)
    {
      tmp107 += 1.0;
      tmp108 -= 1.0;
    }
    
    if(fabs(tmp107) < 1e-10)
      tmp106 = pow(tmp104, tmp108);
    else
    {
      tmp110 = modf(1.0/tmp105, &tmp109);
      if(tmp110 > 0.5)
      {
        tmp110 -= 1.0;
        tmp109 += 1.0;
      }
      else if(tmp110 < -0.5)
      {
        tmp110 += 1.0;
        tmp109 -= 1.0;
      }
      if(fabs(tmp110) < 1e-10 && ((unsigned long)tmp109 & 1))
      {
        tmp106 = -pow(-tmp104, tmp107)*pow(tmp104, tmp108);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp104, tmp105);
      }
    }
  }
  else
  {
    tmp106 = pow(tmp104, tmp105);
  }
  if(isnan(tmp106) || isinf(tmp106))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp104, tmp105);
  }tmp111 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */);
  tmp112 = (data->simulationInfo->realParameter[144] /* R_BaPra_PA_x_BaPraPA.nP1e PARAM */);
  if(tmp111 < 0.0 && tmp112 != 0.0)
  {
    tmp114 = modf(tmp112, &tmp115);
    
    if(tmp114 > 0.5)
    {
      tmp114 -= 1.0;
      tmp115 += 1.0;
    }
    else if(tmp114 < -0.5)
    {
      tmp114 += 1.0;
      tmp115 -= 1.0;
    }
    
    if(fabs(tmp114) < 1e-10)
      tmp113 = pow(tmp111, tmp115);
    else
    {
      tmp117 = modf(1.0/tmp112, &tmp116);
      if(tmp117 > 0.5)
      {
        tmp117 -= 1.0;
        tmp116 += 1.0;
      }
      else if(tmp117 < -0.5)
      {
        tmp117 += 1.0;
        tmp116 -= 1.0;
      }
      if(fabs(tmp117) < 1e-10 && ((unsigned long)tmp116 & 1))
      {
        tmp113 = -pow(-tmp111, tmp114)*pow(tmp111, tmp115);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp111, tmp112);
      }
    }
  }
  else
  {
    tmp113 = pow(tmp111, tmp112);
  }
  if(isnan(tmp113) || isinf(tmp113))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp111, tmp112);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[239]] /* R_BaPra_PA_x_BaPraPA.rr variable */) = ((data->simulationInfo->realParameter[142] /* R_BaPra_PA_x_BaPraPA.k1 PARAM */)) * ((tmp99) * ((tmp106) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[143] /* R_BaPra_PA_x_BaPraPA.k2 PARAM */)) * ((tmp113) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 363
type: SIMPLE_ASSIGN
iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr = iR_BaPraPAPoly_x_BaBs_Poly_SignalA.k1 * BaPraPAPoly.c ^ iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nS1e * V
*/
void rPCR_03_eqFunction_363(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,363};
  modelica_real tmp118;
  modelica_real tmp119;
  modelica_real tmp120;
  modelica_real tmp121;
  modelica_real tmp122;
  modelica_real tmp123;
  modelica_real tmp124;
  tmp118 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */);
  tmp119 = (data->simulationInfo->realParameter[226] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nS1e PARAM */);
  if(tmp118 < 0.0 && tmp119 != 0.0)
  {
    tmp121 = modf(tmp119, &tmp122);
    
    if(tmp121 > 0.5)
    {
      tmp121 -= 1.0;
      tmp122 += 1.0;
    }
    else if(tmp121 < -0.5)
    {
      tmp121 += 1.0;
      tmp122 -= 1.0;
    }
    
    if(fabs(tmp121) < 1e-10)
      tmp120 = pow(tmp118, tmp122);
    else
    {
      tmp124 = modf(1.0/tmp119, &tmp123);
      if(tmp124 > 0.5)
      {
        tmp124 -= 1.0;
        tmp123 += 1.0;
      }
      else if(tmp124 < -0.5)
      {
        tmp124 += 1.0;
        tmp123 -= 1.0;
      }
      if(fabs(tmp124) < 1e-10 && ((unsigned long)tmp123 & 1))
      {
        tmp120 = -pow(-tmp118, tmp121)*pow(tmp118, tmp122);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp118, tmp119);
      }
    }
  }
  else
  {
    tmp120 = pow(tmp118, tmp119);
  }
  if(isnan(tmp120) || isinf(tmp120))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp118, tmp119);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[304]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr variable */) = ((data->simulationInfo->realParameter[225] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.k1 PARAM */)) * ((tmp120) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 364
type: SIMPLE_ASSIGN
BaPraPAPoly.n = BaPraPAPoly.c * V
*/
void rPCR_03_eqFunction_364(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,364};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[124]] /* BaPraPAPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 365
type: SIMPLE_ASSIGN
R_BaPraPA_Poly_x_BaPraPAPoly.rr = R_BaPraPA_Poly_x_BaPraPAPoly.k1 * BaPraPA.c ^ R_BaPraPA_Poly_x_BaPraPAPoly.nS1e * Poly.c ^ R_BaPraPA_Poly_x_BaPraPAPoly.nS2e * V - R_BaPraPA_Poly_x_BaPraPAPoly.k2 * BaPraPAPoly.c ^ R_BaPraPA_Poly_x_BaPraPAPoly.nP1e * V
*/
void rPCR_03_eqFunction_365(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,365};
  modelica_real tmp125;
  modelica_real tmp126;
  modelica_real tmp127;
  modelica_real tmp128;
  modelica_real tmp129;
  modelica_real tmp130;
  modelica_real tmp131;
  modelica_real tmp132;
  modelica_real tmp133;
  modelica_real tmp134;
  modelica_real tmp135;
  modelica_real tmp136;
  modelica_real tmp137;
  modelica_real tmp138;
  modelica_real tmp139;
  modelica_real tmp140;
  modelica_real tmp141;
  modelica_real tmp142;
  modelica_real tmp143;
  modelica_real tmp144;
  modelica_real tmp145;
  tmp125 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */);
  tmp126 = (data->simulationInfo->realParameter[140] /* R_BaPraPA_Poly_x_BaPraPAPoly.nS1e PARAM */);
  if(tmp125 < 0.0 && tmp126 != 0.0)
  {
    tmp128 = modf(tmp126, &tmp129);
    
    if(tmp128 > 0.5)
    {
      tmp128 -= 1.0;
      tmp129 += 1.0;
    }
    else if(tmp128 < -0.5)
    {
      tmp128 += 1.0;
      tmp129 -= 1.0;
    }
    
    if(fabs(tmp128) < 1e-10)
      tmp127 = pow(tmp125, tmp129);
    else
    {
      tmp131 = modf(1.0/tmp126, &tmp130);
      if(tmp131 > 0.5)
      {
        tmp131 -= 1.0;
        tmp130 += 1.0;
      }
      else if(tmp131 < -0.5)
      {
        tmp131 += 1.0;
        tmp130 -= 1.0;
      }
      if(fabs(tmp131) < 1e-10 && ((unsigned long)tmp130 & 1))
      {
        tmp127 = -pow(-tmp125, tmp128)*pow(tmp125, tmp129);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp125, tmp126);
      }
    }
  }
  else
  {
    tmp127 = pow(tmp125, tmp126);
  }
  if(isnan(tmp127) || isinf(tmp127))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp125, tmp126);
  }tmp132 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp133 = (data->simulationInfo->realParameter[141] /* R_BaPraPA_Poly_x_BaPraPAPoly.nS2e PARAM */);
  if(tmp132 < 0.0 && tmp133 != 0.0)
  {
    tmp135 = modf(tmp133, &tmp136);
    
    if(tmp135 > 0.5)
    {
      tmp135 -= 1.0;
      tmp136 += 1.0;
    }
    else if(tmp135 < -0.5)
    {
      tmp135 += 1.0;
      tmp136 -= 1.0;
    }
    
    if(fabs(tmp135) < 1e-10)
      tmp134 = pow(tmp132, tmp136);
    else
    {
      tmp138 = modf(1.0/tmp133, &tmp137);
      if(tmp138 > 0.5)
      {
        tmp138 -= 1.0;
        tmp137 += 1.0;
      }
      else if(tmp138 < -0.5)
      {
        tmp138 += 1.0;
        tmp137 -= 1.0;
      }
      if(fabs(tmp138) < 1e-10 && ((unsigned long)tmp137 & 1))
      {
        tmp134 = -pow(-tmp132, tmp135)*pow(tmp132, tmp136);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp132, tmp133);
      }
    }
  }
  else
  {
    tmp134 = pow(tmp132, tmp133);
  }
  if(isnan(tmp134) || isinf(tmp134))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp132, tmp133);
  }tmp139 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */);
  tmp140 = (data->simulationInfo->realParameter[139] /* R_BaPraPA_Poly_x_BaPraPAPoly.nP1e PARAM */);
  if(tmp139 < 0.0 && tmp140 != 0.0)
  {
    tmp142 = modf(tmp140, &tmp143);
    
    if(tmp142 > 0.5)
    {
      tmp142 -= 1.0;
      tmp143 += 1.0;
    }
    else if(tmp142 < -0.5)
    {
      tmp142 += 1.0;
      tmp143 -= 1.0;
    }
    
    if(fabs(tmp142) < 1e-10)
      tmp141 = pow(tmp139, tmp143);
    else
    {
      tmp145 = modf(1.0/tmp140, &tmp144);
      if(tmp145 > 0.5)
      {
        tmp145 -= 1.0;
        tmp144 += 1.0;
      }
      else if(tmp145 < -0.5)
      {
        tmp145 += 1.0;
        tmp144 -= 1.0;
      }
      if(fabs(tmp145) < 1e-10 && ((unsigned long)tmp144 & 1))
      {
        tmp141 = -pow(-tmp139, tmp142)*pow(tmp139, tmp143);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp139, tmp140);
      }
    }
  }
  else
  {
    tmp141 = pow(tmp139, tmp140);
  }
  if(isnan(tmp141) || isinf(tmp141))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp139, tmp140);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[235]] /* R_BaPraPA_Poly_x_BaPraPAPoly.rr variable */) = ((data->simulationInfo->realParameter[137] /* R_BaPraPA_Poly_x_BaPraPAPoly.k1 PARAM */)) * ((tmp127) * ((tmp134) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[138] /* R_BaPraPA_Poly_x_BaPraPAPoly.k2 PARAM */)) * ((tmp141) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 366
type: SIMPLE_ASSIGN
R_BaPA_Pra_x_BaPraPA.rr = R_BaPA_Pra_x_BaPraPA.k1 * BaPA.c ^ R_BaPA_Pra_x_BaPraPA.nS1e * Pra.c ^ R_BaPA_Pra_x_BaPraPA.nS2e * V - R_BaPA_Pra_x_BaPraPA.k2 * BaPraPA.c ^ R_BaPA_Pra_x_BaPraPA.nP1e * V
*/
void rPCR_03_eqFunction_366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,366};
  modelica_real tmp146;
  modelica_real tmp147;
  modelica_real tmp148;
  modelica_real tmp149;
  modelica_real tmp150;
  modelica_real tmp151;
  modelica_real tmp152;
  modelica_real tmp153;
  modelica_real tmp154;
  modelica_real tmp155;
  modelica_real tmp156;
  modelica_real tmp157;
  modelica_real tmp158;
  modelica_real tmp159;
  modelica_real tmp160;
  modelica_real tmp161;
  modelica_real tmp162;
  modelica_real tmp163;
  modelica_real tmp164;
  modelica_real tmp165;
  modelica_real tmp166;
  tmp146 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */);
  tmp147 = (data->simulationInfo->realParameter[135] /* R_BaPA_Pra_x_BaPraPA.nS1e PARAM */);
  if(tmp146 < 0.0 && tmp147 != 0.0)
  {
    tmp149 = modf(tmp147, &tmp150);
    
    if(tmp149 > 0.5)
    {
      tmp149 -= 1.0;
      tmp150 += 1.0;
    }
    else if(tmp149 < -0.5)
    {
      tmp149 += 1.0;
      tmp150 -= 1.0;
    }
    
    if(fabs(tmp149) < 1e-10)
      tmp148 = pow(tmp146, tmp150);
    else
    {
      tmp152 = modf(1.0/tmp147, &tmp151);
      if(tmp152 > 0.5)
      {
        tmp152 -= 1.0;
        tmp151 += 1.0;
      }
      else if(tmp152 < -0.5)
      {
        tmp152 += 1.0;
        tmp151 -= 1.0;
      }
      if(fabs(tmp152) < 1e-10 && ((unsigned long)tmp151 & 1))
      {
        tmp148 = -pow(-tmp146, tmp149)*pow(tmp146, tmp150);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp146, tmp147);
      }
    }
  }
  else
  {
    tmp148 = pow(tmp146, tmp147);
  }
  if(isnan(tmp148) || isinf(tmp148))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp146, tmp147);
  }tmp153 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */);
  tmp154 = (data->simulationInfo->realParameter[136] /* R_BaPA_Pra_x_BaPraPA.nS2e PARAM */);
  if(tmp153 < 0.0 && tmp154 != 0.0)
  {
    tmp156 = modf(tmp154, &tmp157);
    
    if(tmp156 > 0.5)
    {
      tmp156 -= 1.0;
      tmp157 += 1.0;
    }
    else if(tmp156 < -0.5)
    {
      tmp156 += 1.0;
      tmp157 -= 1.0;
    }
    
    if(fabs(tmp156) < 1e-10)
      tmp155 = pow(tmp153, tmp157);
    else
    {
      tmp159 = modf(1.0/tmp154, &tmp158);
      if(tmp159 > 0.5)
      {
        tmp159 -= 1.0;
        tmp158 += 1.0;
      }
      else if(tmp159 < -0.5)
      {
        tmp159 += 1.0;
        tmp158 -= 1.0;
      }
      if(fabs(tmp159) < 1e-10 && ((unsigned long)tmp158 & 1))
      {
        tmp155 = -pow(-tmp153, tmp156)*pow(tmp153, tmp157);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp153, tmp154);
      }
    }
  }
  else
  {
    tmp155 = pow(tmp153, tmp154);
  }
  if(isnan(tmp155) || isinf(tmp155))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp153, tmp154);
  }tmp160 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */);
  tmp161 = (data->simulationInfo->realParameter[134] /* R_BaPA_Pra_x_BaPraPA.nP1e PARAM */);
  if(tmp160 < 0.0 && tmp161 != 0.0)
  {
    tmp163 = modf(tmp161, &tmp164);
    
    if(tmp163 > 0.5)
    {
      tmp163 -= 1.0;
      tmp164 += 1.0;
    }
    else if(tmp163 < -0.5)
    {
      tmp163 += 1.0;
      tmp164 -= 1.0;
    }
    
    if(fabs(tmp163) < 1e-10)
      tmp162 = pow(tmp160, tmp164);
    else
    {
      tmp166 = modf(1.0/tmp161, &tmp165);
      if(tmp166 > 0.5)
      {
        tmp166 -= 1.0;
        tmp165 += 1.0;
      }
      else if(tmp166 < -0.5)
      {
        tmp166 += 1.0;
        tmp165 -= 1.0;
      }
      if(fabs(tmp166) < 1e-10 && ((unsigned long)tmp165 & 1))
      {
        tmp162 = -pow(-tmp160, tmp163)*pow(tmp160, tmp164);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp160, tmp161);
      }
    }
  }
  else
  {
    tmp162 = pow(tmp160, tmp161);
  }
  if(isnan(tmp162) || isinf(tmp162))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp160, tmp161);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* R_BaPA_Pra_x_BaPraPA.rr variable */) = ((data->simulationInfo->realParameter[132] /* R_BaPA_Pra_x_BaPraPA.k1 PARAM */)) * ((tmp148) * ((tmp155) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[133] /* R_BaPA_Pra_x_BaPraPA.k2 PARAM */)) * ((tmp162) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 367
type: SIMPLE_ASSIGN
R_Ba_PA_x_BaPA.rr = R_Ba_PA_x_BaPA.k1 * PA.c ^ R_Ba_PA_x_BaPA.nS1e * Ba.c ^ R_Ba_PA_x_BaPA.nS2e * V - R_Ba_PA_x_BaPA.k2 * BaPA.c ^ R_Ba_PA_x_BaPA.nP1e * V
*/
void rPCR_03_eqFunction_367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,367};
  modelica_real tmp167;
  modelica_real tmp168;
  modelica_real tmp169;
  modelica_real tmp170;
  modelica_real tmp171;
  modelica_real tmp172;
  modelica_real tmp173;
  modelica_real tmp174;
  modelica_real tmp175;
  modelica_real tmp176;
  modelica_real tmp177;
  modelica_real tmp178;
  modelica_real tmp179;
  modelica_real tmp180;
  modelica_real tmp181;
  modelica_real tmp182;
  modelica_real tmp183;
  modelica_real tmp184;
  modelica_real tmp185;
  modelica_real tmp186;
  modelica_real tmp187;
  tmp167 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */);
  tmp168 = (data->simulationInfo->realParameter[160] /* R_Ba_PA_x_BaPA.nS1e PARAM */);
  if(tmp167 < 0.0 && tmp168 != 0.0)
  {
    tmp170 = modf(tmp168, &tmp171);
    
    if(tmp170 > 0.5)
    {
      tmp170 -= 1.0;
      tmp171 += 1.0;
    }
    else if(tmp170 < -0.5)
    {
      tmp170 += 1.0;
      tmp171 -= 1.0;
    }
    
    if(fabs(tmp170) < 1e-10)
      tmp169 = pow(tmp167, tmp171);
    else
    {
      tmp173 = modf(1.0/tmp168, &tmp172);
      if(tmp173 > 0.5)
      {
        tmp173 -= 1.0;
        tmp172 += 1.0;
      }
      else if(tmp173 < -0.5)
      {
        tmp173 += 1.0;
        tmp172 -= 1.0;
      }
      if(fabs(tmp173) < 1e-10 && ((unsigned long)tmp172 & 1))
      {
        tmp169 = -pow(-tmp167, tmp170)*pow(tmp167, tmp171);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp167, tmp168);
      }
    }
  }
  else
  {
    tmp169 = pow(tmp167, tmp168);
  }
  if(isnan(tmp169) || isinf(tmp169))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp167, tmp168);
  }tmp174 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */);
  tmp175 = (data->simulationInfo->realParameter[161] /* R_Ba_PA_x_BaPA.nS2e PARAM */);
  if(tmp174 < 0.0 && tmp175 != 0.0)
  {
    tmp177 = modf(tmp175, &tmp178);
    
    if(tmp177 > 0.5)
    {
      tmp177 -= 1.0;
      tmp178 += 1.0;
    }
    else if(tmp177 < -0.5)
    {
      tmp177 += 1.0;
      tmp178 -= 1.0;
    }
    
    if(fabs(tmp177) < 1e-10)
      tmp176 = pow(tmp174, tmp178);
    else
    {
      tmp180 = modf(1.0/tmp175, &tmp179);
      if(tmp180 > 0.5)
      {
        tmp180 -= 1.0;
        tmp179 += 1.0;
      }
      else if(tmp180 < -0.5)
      {
        tmp180 += 1.0;
        tmp179 -= 1.0;
      }
      if(fabs(tmp180) < 1e-10 && ((unsigned long)tmp179 & 1))
      {
        tmp176 = -pow(-tmp174, tmp177)*pow(tmp174, tmp178);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp174, tmp175);
      }
    }
  }
  else
  {
    tmp176 = pow(tmp174, tmp175);
  }
  if(isnan(tmp176) || isinf(tmp176))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp174, tmp175);
  }tmp181 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */);
  tmp182 = (data->simulationInfo->realParameter[159] /* R_Ba_PA_x_BaPA.nP1e PARAM */);
  if(tmp181 < 0.0 && tmp182 != 0.0)
  {
    tmp184 = modf(tmp182, &tmp185);
    
    if(tmp184 > 0.5)
    {
      tmp184 -= 1.0;
      tmp185 += 1.0;
    }
    else if(tmp184 < -0.5)
    {
      tmp184 += 1.0;
      tmp185 -= 1.0;
    }
    
    if(fabs(tmp184) < 1e-10)
      tmp183 = pow(tmp181, tmp185);
    else
    {
      tmp187 = modf(1.0/tmp182, &tmp186);
      if(tmp187 > 0.5)
      {
        tmp187 -= 1.0;
        tmp186 += 1.0;
      }
      else if(tmp187 < -0.5)
      {
        tmp187 += 1.0;
        tmp186 -= 1.0;
      }
      if(fabs(tmp187) < 1e-10 && ((unsigned long)tmp186 & 1))
      {
        tmp183 = -pow(-tmp181, tmp184)*pow(tmp181, tmp185);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp181, tmp182);
      }
    }
  }
  else
  {
    tmp183 = pow(tmp181, tmp182);
  }
  if(isnan(tmp183) || isinf(tmp183))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp181, tmp182);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[251]] /* R_Ba_PA_x_BaPA.rr variable */) = ((data->simulationInfo->realParameter[157] /* R_Ba_PA_x_BaPA.k1 PARAM */)) * ((tmp169) * ((tmp176) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[158] /* R_Ba_PA_x_BaPA.k2 PARAM */)) * ((tmp183) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 368
type: SIMPLE_ASSIGN
BaPraPA.n = BaPraPA.c * V
*/
void rPCR_03_eqFunction_368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,368};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* BaPraPA.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 369
type: SIMPLE_ASSIGN
BaPA.n = BaPA.c * V
*/
void rPCR_03_eqFunction_369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,369};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* BaPA.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 370
type: SIMPLE_ASSIGN
iR_AaPraPoly_x_AaAs_Poly.rr = iR_AaPraPoly_x_AaAs_Poly.k1 * AaPraPoly.c ^ iR_AaPraPoly_x_AaAs_Poly.nS1e * V
*/
void rPCR_03_eqFunction_370(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,370};
  modelica_real tmp188;
  modelica_real tmp189;
  modelica_real tmp190;
  modelica_real tmp191;
  modelica_real tmp192;
  modelica_real tmp193;
  modelica_real tmp194;
  tmp188 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */);
  tmp189 = (data->simulationInfo->realParameter[220] /* iR_AaPraPoly_x_AaAs_Poly.nS1e PARAM */);
  if(tmp188 < 0.0 && tmp189 != 0.0)
  {
    tmp191 = modf(tmp189, &tmp192);
    
    if(tmp191 > 0.5)
    {
      tmp191 -= 1.0;
      tmp192 += 1.0;
    }
    else if(tmp191 < -0.5)
    {
      tmp191 += 1.0;
      tmp192 -= 1.0;
    }
    
    if(fabs(tmp191) < 1e-10)
      tmp190 = pow(tmp188, tmp192);
    else
    {
      tmp194 = modf(1.0/tmp189, &tmp193);
      if(tmp194 > 0.5)
      {
        tmp194 -= 1.0;
        tmp193 += 1.0;
      }
      else if(tmp194 < -0.5)
      {
        tmp194 += 1.0;
        tmp193 -= 1.0;
      }
      if(fabs(tmp194) < 1e-10 && ((unsigned long)tmp193 & 1))
      {
        tmp190 = -pow(-tmp188, tmp191)*pow(tmp188, tmp192);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp188, tmp189);
      }
    }
  }
  else
  {
    tmp190 = pow(tmp188, tmp189);
  }
  if(isnan(tmp190) || isinf(tmp190))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp188, tmp189);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[290]] /* iR_AaPraPoly_x_AaAs_Poly.rr variable */) = ((data->simulationInfo->realParameter[219] /* iR_AaPraPoly_x_AaAs_Poly.k1 PARAM */)) * ((tmp190) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 371
type: SIMPLE_ASSIGN
iR_BaPraPoly_x_BaBs_Poly.rr = iR_BaPraPoly_x_BaBs_Poly.k1 * BaPraPoly.c ^ iR_BaPraPoly_x_BaBs_Poly.nS1e * V
*/
void rPCR_03_eqFunction_371(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,371};
  modelica_real tmp195;
  modelica_real tmp196;
  modelica_real tmp197;
  modelica_real tmp198;
  modelica_real tmp199;
  modelica_real tmp200;
  modelica_real tmp201;
  tmp195 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */);
  tmp196 = (data->simulationInfo->realParameter[228] /* iR_BaPraPoly_x_BaBs_Poly.nS1e PARAM */);
  if(tmp195 < 0.0 && tmp196 != 0.0)
  {
    tmp198 = modf(tmp196, &tmp199);
    
    if(tmp198 > 0.5)
    {
      tmp198 -= 1.0;
      tmp199 += 1.0;
    }
    else if(tmp198 < -0.5)
    {
      tmp198 += 1.0;
      tmp199 -= 1.0;
    }
    
    if(fabs(tmp198) < 1e-10)
      tmp197 = pow(tmp195, tmp199);
    else
    {
      tmp201 = modf(1.0/tmp196, &tmp200);
      if(tmp201 > 0.5)
      {
        tmp201 -= 1.0;
        tmp200 += 1.0;
      }
      else if(tmp201 < -0.5)
      {
        tmp201 += 1.0;
        tmp200 -= 1.0;
      }
      if(fabs(tmp201) < 1e-10 && ((unsigned long)tmp200 & 1))
      {
        tmp197 = -pow(-tmp195, tmp198)*pow(tmp195, tmp199);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp195, tmp196);
      }
    }
  }
  else
  {
    tmp197 = pow(tmp195, tmp196);
  }
  if(isnan(tmp197) || isinf(tmp197))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp195, tmp196);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[308]] /* iR_BaPraPoly_x_BaBs_Poly.rr variable */) = ((data->simulationInfo->realParameter[227] /* iR_BaPraPoly_x_BaBs_Poly.k1 PARAM */)) * ((tmp197) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 372
type: SIMPLE_ASSIGN
iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr = iR_AsPrsPaPoly_x_AaAs_Poly_SigA.k1 * AsPrsPAPoly.c ^ iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nS1e * V
*/
void rPCR_03_eqFunction_372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,372};
  modelica_real tmp202;
  modelica_real tmp203;
  modelica_real tmp204;
  modelica_real tmp205;
  modelica_real tmp206;
  modelica_real tmp207;
  modelica_real tmp208;
  tmp202 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */);
  tmp203 = (data->simulationInfo->realParameter[222] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nS1e PARAM */);
  if(tmp202 < 0.0 && tmp203 != 0.0)
  {
    tmp205 = modf(tmp203, &tmp206);
    
    if(tmp205 > 0.5)
    {
      tmp205 -= 1.0;
      tmp206 += 1.0;
    }
    else if(tmp205 < -0.5)
    {
      tmp205 += 1.0;
      tmp206 -= 1.0;
    }
    
    if(fabs(tmp205) < 1e-10)
      tmp204 = pow(tmp202, tmp206);
    else
    {
      tmp208 = modf(1.0/tmp203, &tmp207);
      if(tmp208 > 0.5)
      {
        tmp208 -= 1.0;
        tmp207 += 1.0;
      }
      else if(tmp208 < -0.5)
      {
        tmp208 += 1.0;
        tmp207 -= 1.0;
      }
      if(fabs(tmp208) < 1e-10 && ((unsigned long)tmp207 & 1))
      {
        tmp204 = -pow(-tmp202, tmp205)*pow(tmp202, tmp206);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp202, tmp203);
      }
    }
  }
  else
  {
    tmp204 = pow(tmp202, tmp203);
  }
  if(isnan(tmp204) || isinf(tmp204))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp202, tmp203);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[295]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr variable */) = ((data->simulationInfo->realParameter[221] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.k1 PARAM */)) * ((tmp204) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 373
type: SIMPLE_ASSIGN
iR_AsPrsPoly_x_AaAs_Poly.rr = iR_AsPrsPoly_x_AaAs_Poly.k1 * AsPrsPoly.c ^ iR_AsPrsPoly_x_AaAs_Poly.nS1e * V
*/
void rPCR_03_eqFunction_373(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,373};
  modelica_real tmp209;
  modelica_real tmp210;
  modelica_real tmp211;
  modelica_real tmp212;
  modelica_real tmp213;
  modelica_real tmp214;
  modelica_real tmp215;
  tmp209 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */);
  tmp210 = (data->simulationInfo->realParameter[224] /* iR_AsPrsPoly_x_AaAs_Poly.nS1e PARAM */);
  if(tmp209 < 0.0 && tmp210 != 0.0)
  {
    tmp212 = modf(tmp210, &tmp213);
    
    if(tmp212 > 0.5)
    {
      tmp212 -= 1.0;
      tmp213 += 1.0;
    }
    else if(tmp212 < -0.5)
    {
      tmp212 += 1.0;
      tmp213 -= 1.0;
    }
    
    if(fabs(tmp212) < 1e-10)
      tmp211 = pow(tmp209, tmp213);
    else
    {
      tmp215 = modf(1.0/tmp210, &tmp214);
      if(tmp215 > 0.5)
      {
        tmp215 -= 1.0;
        tmp214 += 1.0;
      }
      else if(tmp215 < -0.5)
      {
        tmp215 += 1.0;
        tmp214 -= 1.0;
      }
      if(fabs(tmp215) < 1e-10 && ((unsigned long)tmp214 & 1))
      {
        tmp211 = -pow(-tmp209, tmp212)*pow(tmp209, tmp213);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp209, tmp210);
      }
    }
  }
  else
  {
    tmp211 = pow(tmp209, tmp210);
  }
  if(isnan(tmp211) || isinf(tmp211))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp209, tmp210);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[299]] /* iR_AsPrsPoly_x_AaAs_Poly.rr variable */) = ((data->simulationInfo->realParameter[223] /* iR_AsPrsPoly_x_AaAs_Poly.k1 PARAM */)) * ((tmp211) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 374
type: SIMPLE_ASSIGN
iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr = iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.k1 * BsPrsPBPoly.c ^ iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nS1e * V
*/
void rPCR_03_eqFunction_374(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,374};
  modelica_real tmp216;
  modelica_real tmp217;
  modelica_real tmp218;
  modelica_real tmp219;
  modelica_real tmp220;
  modelica_real tmp221;
  modelica_real tmp222;
  tmp216 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */);
  tmp217 = (data->simulationInfo->realParameter[230] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nS1e PARAM */);
  if(tmp216 < 0.0 && tmp217 != 0.0)
  {
    tmp219 = modf(tmp217, &tmp220);
    
    if(tmp219 > 0.5)
    {
      tmp219 -= 1.0;
      tmp220 += 1.0;
    }
    else if(tmp219 < -0.5)
    {
      tmp219 += 1.0;
      tmp220 -= 1.0;
    }
    
    if(fabs(tmp219) < 1e-10)
      tmp218 = pow(tmp216, tmp220);
    else
    {
      tmp222 = modf(1.0/tmp217, &tmp221);
      if(tmp222 > 0.5)
      {
        tmp222 -= 1.0;
        tmp221 += 1.0;
      }
      else if(tmp222 < -0.5)
      {
        tmp222 += 1.0;
        tmp221 -= 1.0;
      }
      if(fabs(tmp222) < 1e-10 && ((unsigned long)tmp221 & 1))
      {
        tmp218 = -pow(-tmp216, tmp219)*pow(tmp216, tmp220);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp216, tmp217);
      }
    }
  }
  else
  {
    tmp218 = pow(tmp216, tmp217);
  }
  if(isnan(tmp218) || isinf(tmp218))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp216, tmp217);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[313]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr variable */) = ((data->simulationInfo->realParameter[229] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.k1 PARAM */)) * ((tmp218) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 375
type: SIMPLE_ASSIGN
iR_BsPrsPoly_x_BaBs_Poly.rr = iR_BsPrsPoly_x_BaBs_Poly.k1 * BsPrsPoly.c ^ iR_BsPrsPoly_x_BaBs_Poly.nS1e * V
*/
void rPCR_03_eqFunction_375(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,375};
  modelica_real tmp223;
  modelica_real tmp224;
  modelica_real tmp225;
  modelica_real tmp226;
  modelica_real tmp227;
  modelica_real tmp228;
  modelica_real tmp229;
  tmp223 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */);
  tmp224 = (data->simulationInfo->realParameter[232] /* iR_BsPrsPoly_x_BaBs_Poly.nS1e PARAM */);
  if(tmp223 < 0.0 && tmp224 != 0.0)
  {
    tmp226 = modf(tmp224, &tmp227);
    
    if(tmp226 > 0.5)
    {
      tmp226 -= 1.0;
      tmp227 += 1.0;
    }
    else if(tmp226 < -0.5)
    {
      tmp226 += 1.0;
      tmp227 -= 1.0;
    }
    
    if(fabs(tmp226) < 1e-10)
      tmp225 = pow(tmp223, tmp227);
    else
    {
      tmp229 = modf(1.0/tmp224, &tmp228);
      if(tmp229 > 0.5)
      {
        tmp229 -= 1.0;
        tmp228 += 1.0;
      }
      else if(tmp229 < -0.5)
      {
        tmp229 += 1.0;
        tmp228 -= 1.0;
      }
      if(fabs(tmp229) < 1e-10 && ((unsigned long)tmp228 & 1))
      {
        tmp225 = -pow(-tmp223, tmp226)*pow(tmp223, tmp227);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp223, tmp224);
      }
    }
  }
  else
  {
    tmp225 = pow(tmp223, tmp224);
  }
  if(isnan(tmp225) || isinf(tmp225))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp223, tmp224);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[317]] /* iR_BsPrsPoly_x_BaBs_Poly.rr variable */) = ((data->simulationInfo->realParameter[231] /* iR_BsPrsPoly_x_BaBs_Poly.k1 PARAM */)) * ((tmp225) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)));
  TRACE_POP
}
/*
equation index: 376
type: SIMPLE_ASSIGN
R_BsPrsPB_Poly_x_BsPrsPBPoly.rr = R_BsPrsPB_Poly_x_BsPrsPBPoly.k1 * BsPrsPB.c ^ R_BsPrsPB_Poly_x_BsPrsPBPoly.nS1e * Poly.c ^ R_BsPrsPB_Poly_x_BsPrsPBPoly.nS2e * V - R_BsPrsPB_Poly_x_BsPrsPBPoly.k2 * BsPrsPBPoly.c ^ R_BsPrsPB_Poly_x_BsPrsPBPoly.nP1e * V
*/
void rPCR_03_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,376};
  modelica_real tmp230;
  modelica_real tmp231;
  modelica_real tmp232;
  modelica_real tmp233;
  modelica_real tmp234;
  modelica_real tmp235;
  modelica_real tmp236;
  modelica_real tmp237;
  modelica_real tmp238;
  modelica_real tmp239;
  modelica_real tmp240;
  modelica_real tmp241;
  modelica_real tmp242;
  modelica_real tmp243;
  modelica_real tmp244;
  modelica_real tmp245;
  modelica_real tmp246;
  modelica_real tmp247;
  modelica_real tmp248;
  modelica_real tmp249;
  modelica_real tmp250;
  tmp230 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */);
  tmp231 = (data->simulationInfo->realParameter[175] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nS1e PARAM */);
  if(tmp230 < 0.0 && tmp231 != 0.0)
  {
    tmp233 = modf(tmp231, &tmp234);
    
    if(tmp233 > 0.5)
    {
      tmp233 -= 1.0;
      tmp234 += 1.0;
    }
    else if(tmp233 < -0.5)
    {
      tmp233 += 1.0;
      tmp234 -= 1.0;
    }
    
    if(fabs(tmp233) < 1e-10)
      tmp232 = pow(tmp230, tmp234);
    else
    {
      tmp236 = modf(1.0/tmp231, &tmp235);
      if(tmp236 > 0.5)
      {
        tmp236 -= 1.0;
        tmp235 += 1.0;
      }
      else if(tmp236 < -0.5)
      {
        tmp236 += 1.0;
        tmp235 -= 1.0;
      }
      if(fabs(tmp236) < 1e-10 && ((unsigned long)tmp235 & 1))
      {
        tmp232 = -pow(-tmp230, tmp233)*pow(tmp230, tmp234);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp230, tmp231);
      }
    }
  }
  else
  {
    tmp232 = pow(tmp230, tmp231);
  }
  if(isnan(tmp232) || isinf(tmp232))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp230, tmp231);
  }tmp237 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp238 = (data->simulationInfo->realParameter[176] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nS2e PARAM */);
  if(tmp237 < 0.0 && tmp238 != 0.0)
  {
    tmp240 = modf(tmp238, &tmp241);
    
    if(tmp240 > 0.5)
    {
      tmp240 -= 1.0;
      tmp241 += 1.0;
    }
    else if(tmp240 < -0.5)
    {
      tmp240 += 1.0;
      tmp241 -= 1.0;
    }
    
    if(fabs(tmp240) < 1e-10)
      tmp239 = pow(tmp237, tmp241);
    else
    {
      tmp243 = modf(1.0/tmp238, &tmp242);
      if(tmp243 > 0.5)
      {
        tmp243 -= 1.0;
        tmp242 += 1.0;
      }
      else if(tmp243 < -0.5)
      {
        tmp243 += 1.0;
        tmp242 -= 1.0;
      }
      if(fabs(tmp243) < 1e-10 && ((unsigned long)tmp242 & 1))
      {
        tmp239 = -pow(-tmp237, tmp240)*pow(tmp237, tmp241);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp237, tmp238);
      }
    }
  }
  else
  {
    tmp239 = pow(tmp237, tmp238);
  }
  if(isnan(tmp239) || isinf(tmp239))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp237, tmp238);
  }tmp244 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */);
  tmp245 = (data->simulationInfo->realParameter[174] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nP1e PARAM */);
  if(tmp244 < 0.0 && tmp245 != 0.0)
  {
    tmp247 = modf(tmp245, &tmp248);
    
    if(tmp247 > 0.5)
    {
      tmp247 -= 1.0;
      tmp248 += 1.0;
    }
    else if(tmp247 < -0.5)
    {
      tmp247 += 1.0;
      tmp248 -= 1.0;
    }
    
    if(fabs(tmp247) < 1e-10)
      tmp246 = pow(tmp244, tmp248);
    else
    {
      tmp250 = modf(1.0/tmp245, &tmp249);
      if(tmp250 > 0.5)
      {
        tmp250 -= 1.0;
        tmp249 += 1.0;
      }
      else if(tmp250 < -0.5)
      {
        tmp250 += 1.0;
        tmp249 -= 1.0;
      }
      if(fabs(tmp250) < 1e-10 && ((unsigned long)tmp249 & 1))
      {
        tmp246 = -pow(-tmp244, tmp247)*pow(tmp244, tmp248);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp244, tmp245);
      }
    }
  }
  else
  {
    tmp246 = pow(tmp244, tmp245);
  }
  if(isnan(tmp246) || isinf(tmp246))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp244, tmp245);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[263]] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.rr variable */) = ((data->simulationInfo->realParameter[172] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.k1 PARAM */)) * ((tmp232) * ((tmp239) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[173] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.k2 PARAM */)) * ((tmp246) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 377
type: SIMPLE_ASSIGN
R_BsPrs_Poly_x_BsPrsPoly.rr = R_BsPrs_Poly_x_BsPrsPoly.k1 * BsPrs.c ^ R_BsPrs_Poly_x_BsPrsPoly.nS1e * Poly.c ^ R_BsPrs_Poly_x_BsPrsPoly.nS2e * V - R_BsPrs_Poly_x_BsPrsPoly.k2 * BsPrsPoly.c ^ R_BsPrs_Poly_x_BsPrsPoly.nP1e * V
*/
void rPCR_03_eqFunction_377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,377};
  modelica_real tmp251;
  modelica_real tmp252;
  modelica_real tmp253;
  modelica_real tmp254;
  modelica_real tmp255;
  modelica_real tmp256;
  modelica_real tmp257;
  modelica_real tmp258;
  modelica_real tmp259;
  modelica_real tmp260;
  modelica_real tmp261;
  modelica_real tmp262;
  modelica_real tmp263;
  modelica_real tmp264;
  modelica_real tmp265;
  modelica_real tmp266;
  modelica_real tmp267;
  modelica_real tmp268;
  modelica_real tmp269;
  modelica_real tmp270;
  modelica_real tmp271;
  tmp251 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */);
  tmp252 = (data->simulationInfo->realParameter[185] /* R_BsPrs_Poly_x_BsPrsPoly.nS1e PARAM */);
  if(tmp251 < 0.0 && tmp252 != 0.0)
  {
    tmp254 = modf(tmp252, &tmp255);
    
    if(tmp254 > 0.5)
    {
      tmp254 -= 1.0;
      tmp255 += 1.0;
    }
    else if(tmp254 < -0.5)
    {
      tmp254 += 1.0;
      tmp255 -= 1.0;
    }
    
    if(fabs(tmp254) < 1e-10)
      tmp253 = pow(tmp251, tmp255);
    else
    {
      tmp257 = modf(1.0/tmp252, &tmp256);
      if(tmp257 > 0.5)
      {
        tmp257 -= 1.0;
        tmp256 += 1.0;
      }
      else if(tmp257 < -0.5)
      {
        tmp257 += 1.0;
        tmp256 -= 1.0;
      }
      if(fabs(tmp257) < 1e-10 && ((unsigned long)tmp256 & 1))
      {
        tmp253 = -pow(-tmp251, tmp254)*pow(tmp251, tmp255);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp251, tmp252);
      }
    }
  }
  else
  {
    tmp253 = pow(tmp251, tmp252);
  }
  if(isnan(tmp253) || isinf(tmp253))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp251, tmp252);
  }tmp258 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp259 = (data->simulationInfo->realParameter[186] /* R_BsPrs_Poly_x_BsPrsPoly.nS2e PARAM */);
  if(tmp258 < 0.0 && tmp259 != 0.0)
  {
    tmp261 = modf(tmp259, &tmp262);
    
    if(tmp261 > 0.5)
    {
      tmp261 -= 1.0;
      tmp262 += 1.0;
    }
    else if(tmp261 < -0.5)
    {
      tmp261 += 1.0;
      tmp262 -= 1.0;
    }
    
    if(fabs(tmp261) < 1e-10)
      tmp260 = pow(tmp258, tmp262);
    else
    {
      tmp264 = modf(1.0/tmp259, &tmp263);
      if(tmp264 > 0.5)
      {
        tmp264 -= 1.0;
        tmp263 += 1.0;
      }
      else if(tmp264 < -0.5)
      {
        tmp264 += 1.0;
        tmp263 -= 1.0;
      }
      if(fabs(tmp264) < 1e-10 && ((unsigned long)tmp263 & 1))
      {
        tmp260 = -pow(-tmp258, tmp261)*pow(tmp258, tmp262);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp258, tmp259);
      }
    }
  }
  else
  {
    tmp260 = pow(tmp258, tmp259);
  }
  if(isnan(tmp260) || isinf(tmp260))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp258, tmp259);
  }tmp265 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */);
  tmp266 = (data->simulationInfo->realParameter[184] /* R_BsPrs_Poly_x_BsPrsPoly.nP1e PARAM */);
  if(tmp265 < 0.0 && tmp266 != 0.0)
  {
    tmp268 = modf(tmp266, &tmp269);
    
    if(tmp268 > 0.5)
    {
      tmp268 -= 1.0;
      tmp269 += 1.0;
    }
    else if(tmp268 < -0.5)
    {
      tmp268 += 1.0;
      tmp269 -= 1.0;
    }
    
    if(fabs(tmp268) < 1e-10)
      tmp267 = pow(tmp265, tmp269);
    else
    {
      tmp271 = modf(1.0/tmp266, &tmp270);
      if(tmp271 > 0.5)
      {
        tmp271 -= 1.0;
        tmp270 += 1.0;
      }
      else if(tmp271 < -0.5)
      {
        tmp271 += 1.0;
        tmp270 -= 1.0;
      }
      if(fabs(tmp271) < 1e-10 && ((unsigned long)tmp270 & 1))
      {
        tmp267 = -pow(-tmp265, tmp268)*pow(tmp265, tmp269);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp265, tmp266);
      }
    }
  }
  else
  {
    tmp267 = pow(tmp265, tmp266);
  }
  if(isnan(tmp267) || isinf(tmp267))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp265, tmp266);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[271]] /* R_BsPrs_Poly_x_BsPrsPoly.rr variable */) = ((data->simulationInfo->realParameter[182] /* R_BsPrs_Poly_x_BsPrsPoly.k1 PARAM */)) * ((tmp253) * ((tmp260) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[183] /* R_BsPrs_Poly_x_BsPrsPoly.k2 PARAM */)) * ((tmp267) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 378
type: SIMPLE_ASSIGN
R_BaPra_Poly_x_BaPraPoly.rr = R_BaPra_Poly_x_BaPraPoly.k1 * BaPra.c ^ R_BaPra_Poly_x_BaPraPoly.nS1e * Poly.c ^ R_BaPra_Poly_x_BaPraPoly.nS2e * V - R_BaPra_Poly_x_BaPraPoly.k2 * BaPraPoly.c ^ R_BaPra_Poly_x_BaPraPoly.nP1e * V
*/
void rPCR_03_eqFunction_378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,378};
  modelica_real tmp272;
  modelica_real tmp273;
  modelica_real tmp274;
  modelica_real tmp275;
  modelica_real tmp276;
  modelica_real tmp277;
  modelica_real tmp278;
  modelica_real tmp279;
  modelica_real tmp280;
  modelica_real tmp281;
  modelica_real tmp282;
  modelica_real tmp283;
  modelica_real tmp284;
  modelica_real tmp285;
  modelica_real tmp286;
  modelica_real tmp287;
  modelica_real tmp288;
  modelica_real tmp289;
  modelica_real tmp290;
  modelica_real tmp291;
  modelica_real tmp292;
  tmp272 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */);
  tmp273 = (data->simulationInfo->realParameter[150] /* R_BaPra_Poly_x_BaPraPoly.nS1e PARAM */);
  if(tmp272 < 0.0 && tmp273 != 0.0)
  {
    tmp275 = modf(tmp273, &tmp276);
    
    if(tmp275 > 0.5)
    {
      tmp275 -= 1.0;
      tmp276 += 1.0;
    }
    else if(tmp275 < -0.5)
    {
      tmp275 += 1.0;
      tmp276 -= 1.0;
    }
    
    if(fabs(tmp275) < 1e-10)
      tmp274 = pow(tmp272, tmp276);
    else
    {
      tmp278 = modf(1.0/tmp273, &tmp277);
      if(tmp278 > 0.5)
      {
        tmp278 -= 1.0;
        tmp277 += 1.0;
      }
      else if(tmp278 < -0.5)
      {
        tmp278 += 1.0;
        tmp277 -= 1.0;
      }
      if(fabs(tmp278) < 1e-10 && ((unsigned long)tmp277 & 1))
      {
        tmp274 = -pow(-tmp272, tmp275)*pow(tmp272, tmp276);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp272, tmp273);
      }
    }
  }
  else
  {
    tmp274 = pow(tmp272, tmp273);
  }
  if(isnan(tmp274) || isinf(tmp274))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp272, tmp273);
  }tmp279 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp280 = (data->simulationInfo->realParameter[151] /* R_BaPra_Poly_x_BaPraPoly.nS2e PARAM */);
  if(tmp279 < 0.0 && tmp280 != 0.0)
  {
    tmp282 = modf(tmp280, &tmp283);
    
    if(tmp282 > 0.5)
    {
      tmp282 -= 1.0;
      tmp283 += 1.0;
    }
    else if(tmp282 < -0.5)
    {
      tmp282 += 1.0;
      tmp283 -= 1.0;
    }
    
    if(fabs(tmp282) < 1e-10)
      tmp281 = pow(tmp279, tmp283);
    else
    {
      tmp285 = modf(1.0/tmp280, &tmp284);
      if(tmp285 > 0.5)
      {
        tmp285 -= 1.0;
        tmp284 += 1.0;
      }
      else if(tmp285 < -0.5)
      {
        tmp285 += 1.0;
        tmp284 -= 1.0;
      }
      if(fabs(tmp285) < 1e-10 && ((unsigned long)tmp284 & 1))
      {
        tmp281 = -pow(-tmp279, tmp282)*pow(tmp279, tmp283);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp279, tmp280);
      }
    }
  }
  else
  {
    tmp281 = pow(tmp279, tmp280);
  }
  if(isnan(tmp281) || isinf(tmp281))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp279, tmp280);
  }tmp286 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */);
  tmp287 = (data->simulationInfo->realParameter[149] /* R_BaPra_Poly_x_BaPraPoly.nP1e PARAM */);
  if(tmp286 < 0.0 && tmp287 != 0.0)
  {
    tmp289 = modf(tmp287, &tmp290);
    
    if(tmp289 > 0.5)
    {
      tmp289 -= 1.0;
      tmp290 += 1.0;
    }
    else if(tmp289 < -0.5)
    {
      tmp289 += 1.0;
      tmp290 -= 1.0;
    }
    
    if(fabs(tmp289) < 1e-10)
      tmp288 = pow(tmp286, tmp290);
    else
    {
      tmp292 = modf(1.0/tmp287, &tmp291);
      if(tmp292 > 0.5)
      {
        tmp292 -= 1.0;
        tmp291 += 1.0;
      }
      else if(tmp292 < -0.5)
      {
        tmp292 += 1.0;
        tmp291 -= 1.0;
      }
      if(fabs(tmp292) < 1e-10 && ((unsigned long)tmp291 & 1))
      {
        tmp288 = -pow(-tmp286, tmp289)*pow(tmp286, tmp290);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp286, tmp287);
      }
    }
  }
  else
  {
    tmp288 = pow(tmp286, tmp287);
  }
  if(isnan(tmp288) || isinf(tmp288))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp286, tmp287);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* R_BaPra_Poly_x_BaPraPoly.rr variable */) = ((data->simulationInfo->realParameter[147] /* R_BaPra_Poly_x_BaPraPoly.k1 PARAM */)) * ((tmp274) * ((tmp281) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[148] /* R_BaPra_Poly_x_BaPraPoly.k2 PARAM */)) * ((tmp288) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 379
type: SIMPLE_ASSIGN
R_AsPrsPA_Poly_AsPrsPAPoly.rr = R_AsPrsPA_Poly_AsPrsPAPoly.k1 * Poly.c ^ R_AsPrsPA_Poly_AsPrsPAPoly.nS1e * AsPrsPA.c ^ R_AsPrsPA_Poly_AsPrsPAPoly.nS2e * V - R_AsPrsPA_Poly_AsPrsPAPoly.k2 * AsPrsPAPoly.c ^ R_AsPrsPA_Poly_AsPrsPAPoly.nP1e * V
*/
void rPCR_03_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,379};
  modelica_real tmp293;
  modelica_real tmp294;
  modelica_real tmp295;
  modelica_real tmp296;
  modelica_real tmp297;
  modelica_real tmp298;
  modelica_real tmp299;
  modelica_real tmp300;
  modelica_real tmp301;
  modelica_real tmp302;
  modelica_real tmp303;
  modelica_real tmp304;
  modelica_real tmp305;
  modelica_real tmp306;
  modelica_real tmp307;
  modelica_real tmp308;
  modelica_real tmp309;
  modelica_real tmp310;
  modelica_real tmp311;
  modelica_real tmp312;
  modelica_real tmp313;
  tmp293 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp294 = (data->simulationInfo->realParameter[100] /* R_AsPrsPA_Poly_AsPrsPAPoly.nS1e PARAM */);
  if(tmp293 < 0.0 && tmp294 != 0.0)
  {
    tmp296 = modf(tmp294, &tmp297);
    
    if(tmp296 > 0.5)
    {
      tmp296 -= 1.0;
      tmp297 += 1.0;
    }
    else if(tmp296 < -0.5)
    {
      tmp296 += 1.0;
      tmp297 -= 1.0;
    }
    
    if(fabs(tmp296) < 1e-10)
      tmp295 = pow(tmp293, tmp297);
    else
    {
      tmp299 = modf(1.0/tmp294, &tmp298);
      if(tmp299 > 0.5)
      {
        tmp299 -= 1.0;
        tmp298 += 1.0;
      }
      else if(tmp299 < -0.5)
      {
        tmp299 += 1.0;
        tmp298 -= 1.0;
      }
      if(fabs(tmp299) < 1e-10 && ((unsigned long)tmp298 & 1))
      {
        tmp295 = -pow(-tmp293, tmp296)*pow(tmp293, tmp297);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp293, tmp294);
      }
    }
  }
  else
  {
    tmp295 = pow(tmp293, tmp294);
  }
  if(isnan(tmp295) || isinf(tmp295))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp293, tmp294);
  }tmp300 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */);
  tmp301 = (data->simulationInfo->realParameter[101] /* R_AsPrsPA_Poly_AsPrsPAPoly.nS2e PARAM */);
  if(tmp300 < 0.0 && tmp301 != 0.0)
  {
    tmp303 = modf(tmp301, &tmp304);
    
    if(tmp303 > 0.5)
    {
      tmp303 -= 1.0;
      tmp304 += 1.0;
    }
    else if(tmp303 < -0.5)
    {
      tmp303 += 1.0;
      tmp304 -= 1.0;
    }
    
    if(fabs(tmp303) < 1e-10)
      tmp302 = pow(tmp300, tmp304);
    else
    {
      tmp306 = modf(1.0/tmp301, &tmp305);
      if(tmp306 > 0.5)
      {
        tmp306 -= 1.0;
        tmp305 += 1.0;
      }
      else if(tmp306 < -0.5)
      {
        tmp306 += 1.0;
        tmp305 -= 1.0;
      }
      if(fabs(tmp306) < 1e-10 && ((unsigned long)tmp305 & 1))
      {
        tmp302 = -pow(-tmp300, tmp303)*pow(tmp300, tmp304);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp300, tmp301);
      }
    }
  }
  else
  {
    tmp302 = pow(tmp300, tmp301);
  }
  if(isnan(tmp302) || isinf(tmp302))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp300, tmp301);
  }tmp307 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */);
  tmp308 = (data->simulationInfo->realParameter[99] /* R_AsPrsPA_Poly_AsPrsPAPoly.nP1e PARAM */);
  if(tmp307 < 0.0 && tmp308 != 0.0)
  {
    tmp310 = modf(tmp308, &tmp311);
    
    if(tmp310 > 0.5)
    {
      tmp310 -= 1.0;
      tmp311 += 1.0;
    }
    else if(tmp310 < -0.5)
    {
      tmp310 += 1.0;
      tmp311 -= 1.0;
    }
    
    if(fabs(tmp310) < 1e-10)
      tmp309 = pow(tmp307, tmp311);
    else
    {
      tmp313 = modf(1.0/tmp308, &tmp312);
      if(tmp313 > 0.5)
      {
        tmp313 -= 1.0;
        tmp312 += 1.0;
      }
      else if(tmp313 < -0.5)
      {
        tmp313 += 1.0;
        tmp312 -= 1.0;
      }
      if(fabs(tmp313) < 1e-10 && ((unsigned long)tmp312 & 1))
      {
        tmp309 = -pow(-tmp307, tmp310)*pow(tmp307, tmp311);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp307, tmp308);
      }
    }
  }
  else
  {
    tmp309 = pow(tmp307, tmp308);
  }
  if(isnan(tmp309) || isinf(tmp309))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp307, tmp308);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[203]] /* R_AsPrsPA_Poly_AsPrsPAPoly.rr variable */) = ((data->simulationInfo->realParameter[97] /* R_AsPrsPA_Poly_AsPrsPAPoly.k1 PARAM */)) * ((tmp295) * ((tmp302) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[98] /* R_AsPrsPA_Poly_AsPrsPAPoly.k2 PARAM */)) * ((tmp309) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 380
type: SIMPLE_ASSIGN
R_AsPrs_Poly_x_AsPrsPoly.rr = R_AsPrs_Poly_x_AsPrsPoly.k1 * Poly.c ^ R_AsPrs_Poly_x_AsPrsPoly.nS1e * AsPrs.c ^ R_AsPrs_Poly_x_AsPrsPoly.nS2e * V - R_AsPrs_Poly_x_AsPrsPoly.k2 * AsPrsPoly.c ^ R_AsPrs_Poly_x_AsPrsPoly.nP1e * V
*/
void rPCR_03_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,380};
  modelica_real tmp314;
  modelica_real tmp315;
  modelica_real tmp316;
  modelica_real tmp317;
  modelica_real tmp318;
  modelica_real tmp319;
  modelica_real tmp320;
  modelica_real tmp321;
  modelica_real tmp322;
  modelica_real tmp323;
  modelica_real tmp324;
  modelica_real tmp325;
  modelica_real tmp326;
  modelica_real tmp327;
  modelica_real tmp328;
  modelica_real tmp329;
  modelica_real tmp330;
  modelica_real tmp331;
  modelica_real tmp332;
  modelica_real tmp333;
  modelica_real tmp334;
  tmp314 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp315 = (data->simulationInfo->realParameter[110] /* R_AsPrs_Poly_x_AsPrsPoly.nS1e PARAM */);
  if(tmp314 < 0.0 && tmp315 != 0.0)
  {
    tmp317 = modf(tmp315, &tmp318);
    
    if(tmp317 > 0.5)
    {
      tmp317 -= 1.0;
      tmp318 += 1.0;
    }
    else if(tmp317 < -0.5)
    {
      tmp317 += 1.0;
      tmp318 -= 1.0;
    }
    
    if(fabs(tmp317) < 1e-10)
      tmp316 = pow(tmp314, tmp318);
    else
    {
      tmp320 = modf(1.0/tmp315, &tmp319);
      if(tmp320 > 0.5)
      {
        tmp320 -= 1.0;
        tmp319 += 1.0;
      }
      else if(tmp320 < -0.5)
      {
        tmp320 += 1.0;
        tmp319 -= 1.0;
      }
      if(fabs(tmp320) < 1e-10 && ((unsigned long)tmp319 & 1))
      {
        tmp316 = -pow(-tmp314, tmp317)*pow(tmp314, tmp318);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp314, tmp315);
      }
    }
  }
  else
  {
    tmp316 = pow(tmp314, tmp315);
  }
  if(isnan(tmp316) || isinf(tmp316))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp314, tmp315);
  }tmp321 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */);
  tmp322 = (data->simulationInfo->realParameter[111] /* R_AsPrs_Poly_x_AsPrsPoly.nS2e PARAM */);
  if(tmp321 < 0.0 && tmp322 != 0.0)
  {
    tmp324 = modf(tmp322, &tmp325);
    
    if(tmp324 > 0.5)
    {
      tmp324 -= 1.0;
      tmp325 += 1.0;
    }
    else if(tmp324 < -0.5)
    {
      tmp324 += 1.0;
      tmp325 -= 1.0;
    }
    
    if(fabs(tmp324) < 1e-10)
      tmp323 = pow(tmp321, tmp325);
    else
    {
      tmp327 = modf(1.0/tmp322, &tmp326);
      if(tmp327 > 0.5)
      {
        tmp327 -= 1.0;
        tmp326 += 1.0;
      }
      else if(tmp327 < -0.5)
      {
        tmp327 += 1.0;
        tmp326 -= 1.0;
      }
      if(fabs(tmp327) < 1e-10 && ((unsigned long)tmp326 & 1))
      {
        tmp323 = -pow(-tmp321, tmp324)*pow(tmp321, tmp325);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp321, tmp322);
      }
    }
  }
  else
  {
    tmp323 = pow(tmp321, tmp322);
  }
  if(isnan(tmp323) || isinf(tmp323))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp321, tmp322);
  }tmp328 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */);
  tmp329 = (data->simulationInfo->realParameter[109] /* R_AsPrs_Poly_x_AsPrsPoly.nP1e PARAM */);
  if(tmp328 < 0.0 && tmp329 != 0.0)
  {
    tmp331 = modf(tmp329, &tmp332);
    
    if(tmp331 > 0.5)
    {
      tmp331 -= 1.0;
      tmp332 += 1.0;
    }
    else if(tmp331 < -0.5)
    {
      tmp331 += 1.0;
      tmp332 -= 1.0;
    }
    
    if(fabs(tmp331) < 1e-10)
      tmp330 = pow(tmp328, tmp332);
    else
    {
      tmp334 = modf(1.0/tmp329, &tmp333);
      if(tmp334 > 0.5)
      {
        tmp334 -= 1.0;
        tmp333 += 1.0;
      }
      else if(tmp334 < -0.5)
      {
        tmp334 += 1.0;
        tmp333 -= 1.0;
      }
      if(fabs(tmp334) < 1e-10 && ((unsigned long)tmp333 & 1))
      {
        tmp330 = -pow(-tmp328, tmp331)*pow(tmp328, tmp332);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp328, tmp329);
      }
    }
  }
  else
  {
    tmp330 = pow(tmp328, tmp329);
  }
  if(isnan(tmp330) || isinf(tmp330))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp328, tmp329);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* R_AsPrs_Poly_x_AsPrsPoly.rr variable */) = ((data->simulationInfo->realParameter[107] /* R_AsPrs_Poly_x_AsPrsPoly.k1 PARAM */)) * ((tmp316) * ((tmp323) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[108] /* R_AsPrs_Poly_x_AsPrsPoly.k2 PARAM */)) * ((tmp330) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 381
type: SIMPLE_ASSIGN
R_AaPra_Poly_x_AaPraPoly.rr = R_AaPra_Poly_x_AaPraPoly.k1 * Poly.c ^ R_AaPra_Poly_x_AaPraPoly.nS1e * AaPra.c ^ R_AaPra_Poly_x_AaPraPoly.nS2e * V - R_AaPra_Poly_x_AaPraPoly.k2 * AaPraPoly.c ^ R_AaPra_Poly_x_AaPraPoly.nP1e * V
*/
void rPCR_03_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
  modelica_real tmp335;
  modelica_real tmp336;
  modelica_real tmp337;
  modelica_real tmp338;
  modelica_real tmp339;
  modelica_real tmp340;
  modelica_real tmp341;
  modelica_real tmp342;
  modelica_real tmp343;
  modelica_real tmp344;
  modelica_real tmp345;
  modelica_real tmp346;
  modelica_real tmp347;
  modelica_real tmp348;
  modelica_real tmp349;
  modelica_real tmp350;
  modelica_real tmp351;
  modelica_real tmp352;
  modelica_real tmp353;
  modelica_real tmp354;
  modelica_real tmp355;
  tmp335 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp336 = (data->simulationInfo->realParameter[65] /* R_AaPra_Poly_x_AaPraPoly.nS1e PARAM */);
  if(tmp335 < 0.0 && tmp336 != 0.0)
  {
    tmp338 = modf(tmp336, &tmp339);
    
    if(tmp338 > 0.5)
    {
      tmp338 -= 1.0;
      tmp339 += 1.0;
    }
    else if(tmp338 < -0.5)
    {
      tmp338 += 1.0;
      tmp339 -= 1.0;
    }
    
    if(fabs(tmp338) < 1e-10)
      tmp337 = pow(tmp335, tmp339);
    else
    {
      tmp341 = modf(1.0/tmp336, &tmp340);
      if(tmp341 > 0.5)
      {
        tmp341 -= 1.0;
        tmp340 += 1.0;
      }
      else if(tmp341 < -0.5)
      {
        tmp341 += 1.0;
        tmp340 -= 1.0;
      }
      if(fabs(tmp341) < 1e-10 && ((unsigned long)tmp340 & 1))
      {
        tmp337 = -pow(-tmp335, tmp338)*pow(tmp335, tmp339);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp335, tmp336);
      }
    }
  }
  else
  {
    tmp337 = pow(tmp335, tmp336);
  }
  if(isnan(tmp337) || isinf(tmp337))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp335, tmp336);
  }tmp342 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */);
  tmp343 = (data->simulationInfo->realParameter[66] /* R_AaPra_Poly_x_AaPraPoly.nS2e PARAM */);
  if(tmp342 < 0.0 && tmp343 != 0.0)
  {
    tmp345 = modf(tmp343, &tmp346);
    
    if(tmp345 > 0.5)
    {
      tmp345 -= 1.0;
      tmp346 += 1.0;
    }
    else if(tmp345 < -0.5)
    {
      tmp345 += 1.0;
      tmp346 -= 1.0;
    }
    
    if(fabs(tmp345) < 1e-10)
      tmp344 = pow(tmp342, tmp346);
    else
    {
      tmp348 = modf(1.0/tmp343, &tmp347);
      if(tmp348 > 0.5)
      {
        tmp348 -= 1.0;
        tmp347 += 1.0;
      }
      else if(tmp348 < -0.5)
      {
        tmp348 += 1.0;
        tmp347 -= 1.0;
      }
      if(fabs(tmp348) < 1e-10 && ((unsigned long)tmp347 & 1))
      {
        tmp344 = -pow(-tmp342, tmp345)*pow(tmp342, tmp346);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp342, tmp343);
      }
    }
  }
  else
  {
    tmp344 = pow(tmp342, tmp343);
  }
  if(isnan(tmp344) || isinf(tmp344))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp342, tmp343);
  }tmp349 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */);
  tmp350 = (data->simulationInfo->realParameter[64] /* R_AaPra_Poly_x_AaPraPoly.nP1e PARAM */);
  if(tmp349 < 0.0 && tmp350 != 0.0)
  {
    tmp352 = modf(tmp350, &tmp353);
    
    if(tmp352 > 0.5)
    {
      tmp352 -= 1.0;
      tmp353 += 1.0;
    }
    else if(tmp352 < -0.5)
    {
      tmp352 += 1.0;
      tmp353 -= 1.0;
    }
    
    if(fabs(tmp352) < 1e-10)
      tmp351 = pow(tmp349, tmp353);
    else
    {
      tmp355 = modf(1.0/tmp350, &tmp354);
      if(tmp355 > 0.5)
      {
        tmp355 -= 1.0;
        tmp354 += 1.0;
      }
      else if(tmp355 < -0.5)
      {
        tmp355 += 1.0;
        tmp354 -= 1.0;
      }
      if(fabs(tmp355) < 1e-10 && ((unsigned long)tmp354 & 1))
      {
        tmp351 = -pow(-tmp349, tmp352)*pow(tmp349, tmp353);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp349, tmp350);
      }
    }
  }
  else
  {
    tmp351 = pow(tmp349, tmp350);
  }
  if(isnan(tmp351) || isinf(tmp351))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp349, tmp350);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[175]] /* R_AaPra_Poly_x_AaPraPoly.rr variable */) = ((data->simulationInfo->realParameter[62] /* R_AaPra_Poly_x_AaPraPoly.k1 PARAM */)) * ((tmp337) * ((tmp344) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[63] /* R_AaPra_Poly_x_AaPraPoly.k2 PARAM */)) * ((tmp351) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 382
type: SIMPLE_ASSIGN
R_AsBa_Poly_x_AsBaPoly.rr = R_AsBa_Poly_x_AsBaPoly.k1 * Poly.c ^ R_AsBa_Poly_x_AsBaPoly.nS1e * AsBa.c ^ R_AsBa_Poly_x_AsBaPoly.nS2e * V - R_AsBa_Poly_x_AsBaPoly.k2 * AsBaPoly.c ^ R_AsBa_Poly_x_AsBaPoly.nP1e * V
*/
void rPCR_03_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
  modelica_real tmp356;
  modelica_real tmp357;
  modelica_real tmp358;
  modelica_real tmp359;
  modelica_real tmp360;
  modelica_real tmp361;
  modelica_real tmp362;
  modelica_real tmp363;
  modelica_real tmp364;
  modelica_real tmp365;
  modelica_real tmp366;
  modelica_real tmp367;
  modelica_real tmp368;
  modelica_real tmp369;
  modelica_real tmp370;
  modelica_real tmp371;
  modelica_real tmp372;
  modelica_real tmp373;
  modelica_real tmp374;
  modelica_real tmp375;
  modelica_real tmp376;
  tmp356 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp357 = (data->simulationInfo->realParameter[90] /* R_AsBa_Poly_x_AsBaPoly.nS1e PARAM */);
  if(tmp356 < 0.0 && tmp357 != 0.0)
  {
    tmp359 = modf(tmp357, &tmp360);
    
    if(tmp359 > 0.5)
    {
      tmp359 -= 1.0;
      tmp360 += 1.0;
    }
    else if(tmp359 < -0.5)
    {
      tmp359 += 1.0;
      tmp360 -= 1.0;
    }
    
    if(fabs(tmp359) < 1e-10)
      tmp358 = pow(tmp356, tmp360);
    else
    {
      tmp362 = modf(1.0/tmp357, &tmp361);
      if(tmp362 > 0.5)
      {
        tmp362 -= 1.0;
        tmp361 += 1.0;
      }
      else if(tmp362 < -0.5)
      {
        tmp362 += 1.0;
        tmp361 -= 1.0;
      }
      if(fabs(tmp362) < 1e-10 && ((unsigned long)tmp361 & 1))
      {
        tmp358 = -pow(-tmp356, tmp359)*pow(tmp356, tmp360);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp356, tmp357);
      }
    }
  }
  else
  {
    tmp358 = pow(tmp356, tmp357);
  }
  if(isnan(tmp358) || isinf(tmp358))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp356, tmp357);
  }tmp363 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */);
  tmp364 = (data->simulationInfo->realParameter[91] /* R_AsBa_Poly_x_AsBaPoly.nS2e PARAM */);
  if(tmp363 < 0.0 && tmp364 != 0.0)
  {
    tmp366 = modf(tmp364, &tmp367);
    
    if(tmp366 > 0.5)
    {
      tmp366 -= 1.0;
      tmp367 += 1.0;
    }
    else if(tmp366 < -0.5)
    {
      tmp366 += 1.0;
      tmp367 -= 1.0;
    }
    
    if(fabs(tmp366) < 1e-10)
      tmp365 = pow(tmp363, tmp367);
    else
    {
      tmp369 = modf(1.0/tmp364, &tmp368);
      if(tmp369 > 0.5)
      {
        tmp369 -= 1.0;
        tmp368 += 1.0;
      }
      else if(tmp369 < -0.5)
      {
        tmp369 += 1.0;
        tmp368 -= 1.0;
      }
      if(fabs(tmp369) < 1e-10 && ((unsigned long)tmp368 & 1))
      {
        tmp365 = -pow(-tmp363, tmp366)*pow(tmp363, tmp367);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp363, tmp364);
      }
    }
  }
  else
  {
    tmp365 = pow(tmp363, tmp364);
  }
  if(isnan(tmp365) || isinf(tmp365))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp363, tmp364);
  }tmp370 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */);
  tmp371 = (data->simulationInfo->realParameter[89] /* R_AsBa_Poly_x_AsBaPoly.nP1e PARAM */);
  if(tmp370 < 0.0 && tmp371 != 0.0)
  {
    tmp373 = modf(tmp371, &tmp374);
    
    if(tmp373 > 0.5)
    {
      tmp373 -= 1.0;
      tmp374 += 1.0;
    }
    else if(tmp373 < -0.5)
    {
      tmp373 += 1.0;
      tmp374 -= 1.0;
    }
    
    if(fabs(tmp373) < 1e-10)
      tmp372 = pow(tmp370, tmp374);
    else
    {
      tmp376 = modf(1.0/tmp371, &tmp375);
      if(tmp376 > 0.5)
      {
        tmp376 -= 1.0;
        tmp375 += 1.0;
      }
      else if(tmp376 < -0.5)
      {
        tmp376 += 1.0;
        tmp375 -= 1.0;
      }
      if(fabs(tmp376) < 1e-10 && ((unsigned long)tmp375 & 1))
      {
        tmp372 = -pow(-tmp370, tmp373)*pow(tmp370, tmp374);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp370, tmp371);
      }
    }
  }
  else
  {
    tmp372 = pow(tmp370, tmp371);
  }
  if(isnan(tmp372) || isinf(tmp372))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp370, tmp371);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* R_AsBa_Poly_x_AsBaPoly.rr variable */) = ((data->simulationInfo->realParameter[87] /* R_AsBa_Poly_x_AsBaPoly.k1 PARAM */)) * ((tmp358) * ((tmp365) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[88] /* R_AsBa_Poly_x_AsBaPoly.k2 PARAM */)) * ((tmp372) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 383
type: SIMPLE_ASSIGN
R_AaBs_Poly_x_AaBsPoly.rr = R_AaBs_Poly_x_AaBsPoly.k1 * Poly.c ^ R_AaBs_Poly_x_AaBsPoly.nS1e * AaBs.c ^ R_AaBs_Poly_x_AaBsPoly.nS2e * V - R_AaBs_Poly_x_AaBsPoly.k2 * AaBsPoly.c ^ R_AaBs_Poly_x_AaBsPoly.nP1e * V
*/
void rPCR_03_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
  modelica_real tmp377;
  modelica_real tmp378;
  modelica_real tmp379;
  modelica_real tmp380;
  modelica_real tmp381;
  modelica_real tmp382;
  modelica_real tmp383;
  modelica_real tmp384;
  modelica_real tmp385;
  modelica_real tmp386;
  modelica_real tmp387;
  modelica_real tmp388;
  modelica_real tmp389;
  modelica_real tmp390;
  modelica_real tmp391;
  modelica_real tmp392;
  modelica_real tmp393;
  modelica_real tmp394;
  modelica_real tmp395;
  modelica_real tmp396;
  modelica_real tmp397;
  tmp377 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp378 = (data->simulationInfo->realParameter[45] /* R_AaBs_Poly_x_AaBsPoly.nS1e PARAM */);
  if(tmp377 < 0.0 && tmp378 != 0.0)
  {
    tmp380 = modf(tmp378, &tmp381);
    
    if(tmp380 > 0.5)
    {
      tmp380 -= 1.0;
      tmp381 += 1.0;
    }
    else if(tmp380 < -0.5)
    {
      tmp380 += 1.0;
      tmp381 -= 1.0;
    }
    
    if(fabs(tmp380) < 1e-10)
      tmp379 = pow(tmp377, tmp381);
    else
    {
      tmp383 = modf(1.0/tmp378, &tmp382);
      if(tmp383 > 0.5)
      {
        tmp383 -= 1.0;
        tmp382 += 1.0;
      }
      else if(tmp383 < -0.5)
      {
        tmp383 += 1.0;
        tmp382 -= 1.0;
      }
      if(fabs(tmp383) < 1e-10 && ((unsigned long)tmp382 & 1))
      {
        tmp379 = -pow(-tmp377, tmp380)*pow(tmp377, tmp381);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp377, tmp378);
      }
    }
  }
  else
  {
    tmp379 = pow(tmp377, tmp378);
  }
  if(isnan(tmp379) || isinf(tmp379))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp377, tmp378);
  }tmp384 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */);
  tmp385 = (data->simulationInfo->realParameter[46] /* R_AaBs_Poly_x_AaBsPoly.nS2e PARAM */);
  if(tmp384 < 0.0 && tmp385 != 0.0)
  {
    tmp387 = modf(tmp385, &tmp388);
    
    if(tmp387 > 0.5)
    {
      tmp387 -= 1.0;
      tmp388 += 1.0;
    }
    else if(tmp387 < -0.5)
    {
      tmp387 += 1.0;
      tmp388 -= 1.0;
    }
    
    if(fabs(tmp387) < 1e-10)
      tmp386 = pow(tmp384, tmp388);
    else
    {
      tmp390 = modf(1.0/tmp385, &tmp389);
      if(tmp390 > 0.5)
      {
        tmp390 -= 1.0;
        tmp389 += 1.0;
      }
      else if(tmp390 < -0.5)
      {
        tmp390 += 1.0;
        tmp389 -= 1.0;
      }
      if(fabs(tmp390) < 1e-10 && ((unsigned long)tmp389 & 1))
      {
        tmp386 = -pow(-tmp384, tmp387)*pow(tmp384, tmp388);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp384, tmp385);
      }
    }
  }
  else
  {
    tmp386 = pow(tmp384, tmp385);
  }
  if(isnan(tmp386) || isinf(tmp386))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp384, tmp385);
  }tmp391 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */);
  tmp392 = (data->simulationInfo->realParameter[44] /* R_AaBs_Poly_x_AaBsPoly.nP1e PARAM */);
  if(tmp391 < 0.0 && tmp392 != 0.0)
  {
    tmp394 = modf(tmp392, &tmp395);
    
    if(tmp394 > 0.5)
    {
      tmp394 -= 1.0;
      tmp395 += 1.0;
    }
    else if(tmp394 < -0.5)
    {
      tmp394 += 1.0;
      tmp395 -= 1.0;
    }
    
    if(fabs(tmp394) < 1e-10)
      tmp393 = pow(tmp391, tmp395);
    else
    {
      tmp397 = modf(1.0/tmp392, &tmp396);
      if(tmp397 > 0.5)
      {
        tmp397 -= 1.0;
        tmp396 += 1.0;
      }
      else if(tmp397 < -0.5)
      {
        tmp397 += 1.0;
        tmp396 -= 1.0;
      }
      if(fabs(tmp397) < 1e-10 && ((unsigned long)tmp396 & 1))
      {
        tmp393 = -pow(-tmp391, tmp394)*pow(tmp391, tmp395);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp391, tmp392);
      }
    }
  }
  else
  {
    tmp393 = pow(tmp391, tmp392);
  }
  if(isnan(tmp393) || isinf(tmp393))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp391, tmp392);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[159]] /* R_AaBs_Poly_x_AaBsPoly.rr variable */) = ((data->simulationInfo->realParameter[42] /* R_AaBs_Poly_x_AaBsPoly.k1 PARAM */)) * ((tmp379) * ((tmp386) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[43] /* R_AaBs_Poly_x_AaBsPoly.k2 PARAM */)) * ((tmp393) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 384
type: SIMPLE_ASSIGN
R_BaBs_Poly_x_BaBsPoly.rr = R_BaBs_Poly_x_BaBsPoly.k1 * BaBs.c ^ R_BaBs_Poly_x_BaBsPoly.nS1e * Poly.c ^ R_BaBs_Poly_x_BaBsPoly.nS2e * V - R_BaBs_Poly_x_BaBsPoly.k2 * BaBsPoly.c ^ R_BaBs_Poly_x_BaBsPoly.nP1e * V
*/
void rPCR_03_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
  modelica_real tmp398;
  modelica_real tmp399;
  modelica_real tmp400;
  modelica_real tmp401;
  modelica_real tmp402;
  modelica_real tmp403;
  modelica_real tmp404;
  modelica_real tmp405;
  modelica_real tmp406;
  modelica_real tmp407;
  modelica_real tmp408;
  modelica_real tmp409;
  modelica_real tmp410;
  modelica_real tmp411;
  modelica_real tmp412;
  modelica_real tmp413;
  modelica_real tmp414;
  modelica_real tmp415;
  modelica_real tmp416;
  modelica_real tmp417;
  modelica_real tmp418;
  tmp398 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */);
  tmp399 = (data->simulationInfo->realParameter[130] /* R_BaBs_Poly_x_BaBsPoly.nS1e PARAM */);
  if(tmp398 < 0.0 && tmp399 != 0.0)
  {
    tmp401 = modf(tmp399, &tmp402);
    
    if(tmp401 > 0.5)
    {
      tmp401 -= 1.0;
      tmp402 += 1.0;
    }
    else if(tmp401 < -0.5)
    {
      tmp401 += 1.0;
      tmp402 -= 1.0;
    }
    
    if(fabs(tmp401) < 1e-10)
      tmp400 = pow(tmp398, tmp402);
    else
    {
      tmp404 = modf(1.0/tmp399, &tmp403);
      if(tmp404 > 0.5)
      {
        tmp404 -= 1.0;
        tmp403 += 1.0;
      }
      else if(tmp404 < -0.5)
      {
        tmp404 += 1.0;
        tmp403 -= 1.0;
      }
      if(fabs(tmp404) < 1e-10 && ((unsigned long)tmp403 & 1))
      {
        tmp400 = -pow(-tmp398, tmp401)*pow(tmp398, tmp402);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp398, tmp399);
      }
    }
  }
  else
  {
    tmp400 = pow(tmp398, tmp399);
  }
  if(isnan(tmp400) || isinf(tmp400))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp398, tmp399);
  }tmp405 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp406 = (data->simulationInfo->realParameter[131] /* R_BaBs_Poly_x_BaBsPoly.nS2e PARAM */);
  if(tmp405 < 0.0 && tmp406 != 0.0)
  {
    tmp408 = modf(tmp406, &tmp409);
    
    if(tmp408 > 0.5)
    {
      tmp408 -= 1.0;
      tmp409 += 1.0;
    }
    else if(tmp408 < -0.5)
    {
      tmp408 += 1.0;
      tmp409 -= 1.0;
    }
    
    if(fabs(tmp408) < 1e-10)
      tmp407 = pow(tmp405, tmp409);
    else
    {
      tmp411 = modf(1.0/tmp406, &tmp410);
      if(tmp411 > 0.5)
      {
        tmp411 -= 1.0;
        tmp410 += 1.0;
      }
      else if(tmp411 < -0.5)
      {
        tmp411 += 1.0;
        tmp410 -= 1.0;
      }
      if(fabs(tmp411) < 1e-10 && ((unsigned long)tmp410 & 1))
      {
        tmp407 = -pow(-tmp405, tmp408)*pow(tmp405, tmp409);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp405, tmp406);
      }
    }
  }
  else
  {
    tmp407 = pow(tmp405, tmp406);
  }
  if(isnan(tmp407) || isinf(tmp407))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp405, tmp406);
  }tmp412 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */);
  tmp413 = (data->simulationInfo->realParameter[129] /* R_BaBs_Poly_x_BaBsPoly.nP1e PARAM */);
  if(tmp412 < 0.0 && tmp413 != 0.0)
  {
    tmp415 = modf(tmp413, &tmp416);
    
    if(tmp415 > 0.5)
    {
      tmp415 -= 1.0;
      tmp416 += 1.0;
    }
    else if(tmp415 < -0.5)
    {
      tmp415 += 1.0;
      tmp416 -= 1.0;
    }
    
    if(fabs(tmp415) < 1e-10)
      tmp414 = pow(tmp412, tmp416);
    else
    {
      tmp418 = modf(1.0/tmp413, &tmp417);
      if(tmp418 > 0.5)
      {
        tmp418 -= 1.0;
        tmp417 += 1.0;
      }
      else if(tmp418 < -0.5)
      {
        tmp418 += 1.0;
        tmp417 -= 1.0;
      }
      if(fabs(tmp418) < 1e-10 && ((unsigned long)tmp417 & 1))
      {
        tmp414 = -pow(-tmp412, tmp415)*pow(tmp412, tmp416);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp412, tmp413);
      }
    }
  }
  else
  {
    tmp414 = pow(tmp412, tmp413);
  }
  if(isnan(tmp414) || isinf(tmp414))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp412, tmp413);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* R_BaBs_Poly_x_BaBsPoly.rr variable */) = ((data->simulationInfo->realParameter[127] /* R_BaBs_Poly_x_BaBsPoly.k1 PARAM */)) * ((tmp400) * ((tmp407) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[128] /* R_BaBs_Poly_x_BaBsPoly.k2 PARAM */)) * ((tmp414) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 385
type: SIMPLE_ASSIGN
R_AaAs_Poly_x_AaAsPoly.rr = R_AaAs_Poly_x_AaAsPoly.k1 * Poly.c ^ R_AaAs_Poly_x_AaAsPoly.nS1e * AaAs.c ^ R_AaAs_Poly_x_AaAsPoly.nS2e * V - R_AaAs_Poly_x_AaAsPoly.k2 * AaAsPoly.c ^ R_AaAs_Poly_x_AaAsPoly.nP1e * V
*/
void rPCR_03_eqFunction_385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,385};
  modelica_real tmp419;
  modelica_real tmp420;
  modelica_real tmp421;
  modelica_real tmp422;
  modelica_real tmp423;
  modelica_real tmp424;
  modelica_real tmp425;
  modelica_real tmp426;
  modelica_real tmp427;
  modelica_real tmp428;
  modelica_real tmp429;
  modelica_real tmp430;
  modelica_real tmp431;
  modelica_real tmp432;
  modelica_real tmp433;
  modelica_real tmp434;
  modelica_real tmp435;
  modelica_real tmp436;
  modelica_real tmp437;
  modelica_real tmp438;
  modelica_real tmp439;
  tmp419 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */);
  tmp420 = (data->simulationInfo->realParameter[40] /* R_AaAs_Poly_x_AaAsPoly.nS1e PARAM */);
  if(tmp419 < 0.0 && tmp420 != 0.0)
  {
    tmp422 = modf(tmp420, &tmp423);
    
    if(tmp422 > 0.5)
    {
      tmp422 -= 1.0;
      tmp423 += 1.0;
    }
    else if(tmp422 < -0.5)
    {
      tmp422 += 1.0;
      tmp423 -= 1.0;
    }
    
    if(fabs(tmp422) < 1e-10)
      tmp421 = pow(tmp419, tmp423);
    else
    {
      tmp425 = modf(1.0/tmp420, &tmp424);
      if(tmp425 > 0.5)
      {
        tmp425 -= 1.0;
        tmp424 += 1.0;
      }
      else if(tmp425 < -0.5)
      {
        tmp425 += 1.0;
        tmp424 -= 1.0;
      }
      if(fabs(tmp425) < 1e-10 && ((unsigned long)tmp424 & 1))
      {
        tmp421 = -pow(-tmp419, tmp422)*pow(tmp419, tmp423);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp419, tmp420);
      }
    }
  }
  else
  {
    tmp421 = pow(tmp419, tmp420);
  }
  if(isnan(tmp421) || isinf(tmp421))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp419, tmp420);
  }tmp426 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */);
  tmp427 = (data->simulationInfo->realParameter[41] /* R_AaAs_Poly_x_AaAsPoly.nS2e PARAM */);
  if(tmp426 < 0.0 && tmp427 != 0.0)
  {
    tmp429 = modf(tmp427, &tmp430);
    
    if(tmp429 > 0.5)
    {
      tmp429 -= 1.0;
      tmp430 += 1.0;
    }
    else if(tmp429 < -0.5)
    {
      tmp429 += 1.0;
      tmp430 -= 1.0;
    }
    
    if(fabs(tmp429) < 1e-10)
      tmp428 = pow(tmp426, tmp430);
    else
    {
      tmp432 = modf(1.0/tmp427, &tmp431);
      if(tmp432 > 0.5)
      {
        tmp432 -= 1.0;
        tmp431 += 1.0;
      }
      else if(tmp432 < -0.5)
      {
        tmp432 += 1.0;
        tmp431 -= 1.0;
      }
      if(fabs(tmp432) < 1e-10 && ((unsigned long)tmp431 & 1))
      {
        tmp428 = -pow(-tmp426, tmp429)*pow(tmp426, tmp430);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp426, tmp427);
      }
    }
  }
  else
  {
    tmp428 = pow(tmp426, tmp427);
  }
  if(isnan(tmp428) || isinf(tmp428))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp426, tmp427);
  }tmp433 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */);
  tmp434 = (data->simulationInfo->realParameter[39] /* R_AaAs_Poly_x_AaAsPoly.nP1e PARAM */);
  if(tmp433 < 0.0 && tmp434 != 0.0)
  {
    tmp436 = modf(tmp434, &tmp437);
    
    if(tmp436 > 0.5)
    {
      tmp436 -= 1.0;
      tmp437 += 1.0;
    }
    else if(tmp436 < -0.5)
    {
      tmp436 += 1.0;
      tmp437 -= 1.0;
    }
    
    if(fabs(tmp436) < 1e-10)
      tmp435 = pow(tmp433, tmp437);
    else
    {
      tmp439 = modf(1.0/tmp434, &tmp438);
      if(tmp439 > 0.5)
      {
        tmp439 -= 1.0;
        tmp438 += 1.0;
      }
      else if(tmp439 < -0.5)
      {
        tmp439 += 1.0;
        tmp438 -= 1.0;
      }
      if(fabs(tmp439) < 1e-10 && ((unsigned long)tmp438 & 1))
      {
        tmp435 = -pow(-tmp433, tmp436)*pow(tmp433, tmp437);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp433, tmp434);
      }
    }
  }
  else
  {
    tmp435 = pow(tmp433, tmp434);
  }
  if(isnan(tmp435) || isinf(tmp435))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp433, tmp434);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[155]] /* R_AaAs_Poly_x_AaAsPoly.rr variable */) = ((data->simulationInfo->realParameter[37] /* R_AaAs_Poly_x_AaAsPoly.k1 PARAM */)) * ((tmp421) * ((tmp428) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[38] /* R_AaAs_Poly_x_AaAsPoly.k2 PARAM */)) * ((tmp435) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 386
type: SIMPLE_ASSIGN
R_BsPrs_PB_x_BsPrsPB.rr = R_BsPrs_PB_x_BsPrsPB.k1 * BsPrs.c ^ R_BsPrs_PB_x_BsPrsPB.nS1e * PB.c ^ R_BsPrs_PB_x_BsPrsPB.nS2e * V - R_BsPrs_PB_x_BsPrsPB.k2 * BsPrsPB.c ^ R_BsPrs_PB_x_BsPrsPB.nP1e * V
*/
void rPCR_03_eqFunction_386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,386};
  modelica_real tmp440;
  modelica_real tmp441;
  modelica_real tmp442;
  modelica_real tmp443;
  modelica_real tmp444;
  modelica_real tmp445;
  modelica_real tmp446;
  modelica_real tmp447;
  modelica_real tmp448;
  modelica_real tmp449;
  modelica_real tmp450;
  modelica_real tmp451;
  modelica_real tmp452;
  modelica_real tmp453;
  modelica_real tmp454;
  modelica_real tmp455;
  modelica_real tmp456;
  modelica_real tmp457;
  modelica_real tmp458;
  modelica_real tmp459;
  modelica_real tmp460;
  tmp440 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */);
  tmp441 = (data->simulationInfo->realParameter[180] /* R_BsPrs_PB_x_BsPrsPB.nS1e PARAM */);
  if(tmp440 < 0.0 && tmp441 != 0.0)
  {
    tmp443 = modf(tmp441, &tmp444);
    
    if(tmp443 > 0.5)
    {
      tmp443 -= 1.0;
      tmp444 += 1.0;
    }
    else if(tmp443 < -0.5)
    {
      tmp443 += 1.0;
      tmp444 -= 1.0;
    }
    
    if(fabs(tmp443) < 1e-10)
      tmp442 = pow(tmp440, tmp444);
    else
    {
      tmp446 = modf(1.0/tmp441, &tmp445);
      if(tmp446 > 0.5)
      {
        tmp446 -= 1.0;
        tmp445 += 1.0;
      }
      else if(tmp446 < -0.5)
      {
        tmp446 += 1.0;
        tmp445 -= 1.0;
      }
      if(fabs(tmp446) < 1e-10 && ((unsigned long)tmp445 & 1))
      {
        tmp442 = -pow(-tmp440, tmp443)*pow(tmp440, tmp444);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp440, tmp441);
      }
    }
  }
  else
  {
    tmp442 = pow(tmp440, tmp441);
  }
  if(isnan(tmp442) || isinf(tmp442))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp440, tmp441);
  }tmp447 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */);
  tmp448 = (data->simulationInfo->realParameter[181] /* R_BsPrs_PB_x_BsPrsPB.nS2e PARAM */);
  if(tmp447 < 0.0 && tmp448 != 0.0)
  {
    tmp450 = modf(tmp448, &tmp451);
    
    if(tmp450 > 0.5)
    {
      tmp450 -= 1.0;
      tmp451 += 1.0;
    }
    else if(tmp450 < -0.5)
    {
      tmp450 += 1.0;
      tmp451 -= 1.0;
    }
    
    if(fabs(tmp450) < 1e-10)
      tmp449 = pow(tmp447, tmp451);
    else
    {
      tmp453 = modf(1.0/tmp448, &tmp452);
      if(tmp453 > 0.5)
      {
        tmp453 -= 1.0;
        tmp452 += 1.0;
      }
      else if(tmp453 < -0.5)
      {
        tmp453 += 1.0;
        tmp452 -= 1.0;
      }
      if(fabs(tmp453) < 1e-10 && ((unsigned long)tmp452 & 1))
      {
        tmp449 = -pow(-tmp447, tmp450)*pow(tmp447, tmp451);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp447, tmp448);
      }
    }
  }
  else
  {
    tmp449 = pow(tmp447, tmp448);
  }
  if(isnan(tmp449) || isinf(tmp449))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp447, tmp448);
  }tmp454 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */);
  tmp455 = (data->simulationInfo->realParameter[179] /* R_BsPrs_PB_x_BsPrsPB.nP1e PARAM */);
  if(tmp454 < 0.0 && tmp455 != 0.0)
  {
    tmp457 = modf(tmp455, &tmp458);
    
    if(tmp457 > 0.5)
    {
      tmp457 -= 1.0;
      tmp458 += 1.0;
    }
    else if(tmp457 < -0.5)
    {
      tmp457 += 1.0;
      tmp458 -= 1.0;
    }
    
    if(fabs(tmp457) < 1e-10)
      tmp456 = pow(tmp454, tmp458);
    else
    {
      tmp460 = modf(1.0/tmp455, &tmp459);
      if(tmp460 > 0.5)
      {
        tmp460 -= 1.0;
        tmp459 += 1.0;
      }
      else if(tmp460 < -0.5)
      {
        tmp460 += 1.0;
        tmp459 -= 1.0;
      }
      if(fabs(tmp460) < 1e-10 && ((unsigned long)tmp459 & 1))
      {
        tmp456 = -pow(-tmp454, tmp457)*pow(tmp454, tmp458);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp454, tmp455);
      }
    }
  }
  else
  {
    tmp456 = pow(tmp454, tmp455);
  }
  if(isnan(tmp456) || isinf(tmp456))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp454, tmp455);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[267]] /* R_BsPrs_PB_x_BsPrsPB.rr variable */) = ((data->simulationInfo->realParameter[177] /* R_BsPrs_PB_x_BsPrsPB.k1 PARAM */)) * ((tmp442) * ((tmp449) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[178] /* R_BsPrs_PB_x_BsPrsPB.k2 PARAM */)) * ((tmp456) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 387
type: SIMPLE_ASSIGN
R_AsPrs_PA_x_AsPrsPA.rr = R_AsPrs_PA_x_AsPrsPA.k1 * PA.c ^ R_AsPrs_PA_x_AsPrsPA.nS1e * AsPrs.c ^ R_AsPrs_PA_x_AsPrsPA.nS2e * V - R_AsPrs_PA_x_AsPrsPA.k2 * AsPrsPA.c ^ R_AsPrs_PA_x_AsPrsPA.nP1e * V
*/
void rPCR_03_eqFunction_387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,387};
  modelica_real tmp461;
  modelica_real tmp462;
  modelica_real tmp463;
  modelica_real tmp464;
  modelica_real tmp465;
  modelica_real tmp466;
  modelica_real tmp467;
  modelica_real tmp468;
  modelica_real tmp469;
  modelica_real tmp470;
  modelica_real tmp471;
  modelica_real tmp472;
  modelica_real tmp473;
  modelica_real tmp474;
  modelica_real tmp475;
  modelica_real tmp476;
  modelica_real tmp477;
  modelica_real tmp478;
  modelica_real tmp479;
  modelica_real tmp480;
  modelica_real tmp481;
  tmp461 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */);
  tmp462 = (data->simulationInfo->realParameter[105] /* R_AsPrs_PA_x_AsPrsPA.nS1e PARAM */);
  if(tmp461 < 0.0 && tmp462 != 0.0)
  {
    tmp464 = modf(tmp462, &tmp465);
    
    if(tmp464 > 0.5)
    {
      tmp464 -= 1.0;
      tmp465 += 1.0;
    }
    else if(tmp464 < -0.5)
    {
      tmp464 += 1.0;
      tmp465 -= 1.0;
    }
    
    if(fabs(tmp464) < 1e-10)
      tmp463 = pow(tmp461, tmp465);
    else
    {
      tmp467 = modf(1.0/tmp462, &tmp466);
      if(tmp467 > 0.5)
      {
        tmp467 -= 1.0;
        tmp466 += 1.0;
      }
      else if(tmp467 < -0.5)
      {
        tmp467 += 1.0;
        tmp466 -= 1.0;
      }
      if(fabs(tmp467) < 1e-10 && ((unsigned long)tmp466 & 1))
      {
        tmp463 = -pow(-tmp461, tmp464)*pow(tmp461, tmp465);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp461, tmp462);
      }
    }
  }
  else
  {
    tmp463 = pow(tmp461, tmp462);
  }
  if(isnan(tmp463) || isinf(tmp463))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp461, tmp462);
  }tmp468 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */);
  tmp469 = (data->simulationInfo->realParameter[106] /* R_AsPrs_PA_x_AsPrsPA.nS2e PARAM */);
  if(tmp468 < 0.0 && tmp469 != 0.0)
  {
    tmp471 = modf(tmp469, &tmp472);
    
    if(tmp471 > 0.5)
    {
      tmp471 -= 1.0;
      tmp472 += 1.0;
    }
    else if(tmp471 < -0.5)
    {
      tmp471 += 1.0;
      tmp472 -= 1.0;
    }
    
    if(fabs(tmp471) < 1e-10)
      tmp470 = pow(tmp468, tmp472);
    else
    {
      tmp474 = modf(1.0/tmp469, &tmp473);
      if(tmp474 > 0.5)
      {
        tmp474 -= 1.0;
        tmp473 += 1.0;
      }
      else if(tmp474 < -0.5)
      {
        tmp474 += 1.0;
        tmp473 -= 1.0;
      }
      if(fabs(tmp474) < 1e-10 && ((unsigned long)tmp473 & 1))
      {
        tmp470 = -pow(-tmp468, tmp471)*pow(tmp468, tmp472);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp468, tmp469);
      }
    }
  }
  else
  {
    tmp470 = pow(tmp468, tmp469);
  }
  if(isnan(tmp470) || isinf(tmp470))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp468, tmp469);
  }tmp475 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */);
  tmp476 = (data->simulationInfo->realParameter[104] /* R_AsPrs_PA_x_AsPrsPA.nP1e PARAM */);
  if(tmp475 < 0.0 && tmp476 != 0.0)
  {
    tmp478 = modf(tmp476, &tmp479);
    
    if(tmp478 > 0.5)
    {
      tmp478 -= 1.0;
      tmp479 += 1.0;
    }
    else if(tmp478 < -0.5)
    {
      tmp478 += 1.0;
      tmp479 -= 1.0;
    }
    
    if(fabs(tmp478) < 1e-10)
      tmp477 = pow(tmp475, tmp479);
    else
    {
      tmp481 = modf(1.0/tmp476, &tmp480);
      if(tmp481 > 0.5)
      {
        tmp481 -= 1.0;
        tmp480 += 1.0;
      }
      else if(tmp481 < -0.5)
      {
        tmp481 += 1.0;
        tmp480 -= 1.0;
      }
      if(fabs(tmp481) < 1e-10 && ((unsigned long)tmp480 & 1))
      {
        tmp477 = -pow(-tmp475, tmp478)*pow(tmp475, tmp479);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp475, tmp476);
      }
    }
  }
  else
  {
    tmp477 = pow(tmp475, tmp476);
  }
  if(isnan(tmp477) || isinf(tmp477))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp475, tmp476);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[207]] /* R_AsPrs_PA_x_AsPrsPA.rr variable */) = ((data->simulationInfo->realParameter[102] /* R_AsPrs_PA_x_AsPrsPA.k1 PARAM */)) * ((tmp463) * ((tmp470) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[103] /* R_AsPrs_PA_x_AsPrsPA.k2 PARAM */)) * ((tmp477) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 388
type: SIMPLE_ASSIGN
R_Bs_PB_x_BsPB.rr = R_Bs_PB_x_BsPB.k1 * Bs.c ^ R_Bs_PB_x_BsPB.nS1e * PB.c ^ R_Bs_PB_x_BsPB.nS2e * V - R_Bs_PB_x_BsPB.k2 * BsPB.c ^ R_Bs_PB_x_BsPB.nP1e * V
*/
void rPCR_03_eqFunction_388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,388};
  modelica_real tmp482;
  modelica_real tmp483;
  modelica_real tmp484;
  modelica_real tmp485;
  modelica_real tmp486;
  modelica_real tmp487;
  modelica_real tmp488;
  modelica_real tmp489;
  modelica_real tmp490;
  modelica_real tmp491;
  modelica_real tmp492;
  modelica_real tmp493;
  modelica_real tmp494;
  modelica_real tmp495;
  modelica_real tmp496;
  modelica_real tmp497;
  modelica_real tmp498;
  modelica_real tmp499;
  modelica_real tmp500;
  modelica_real tmp501;
  modelica_real tmp502;
  tmp482 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */);
  tmp483 = (data->simulationInfo->realParameter[190] /* R_Bs_PB_x_BsPB.nS1e PARAM */);
  if(tmp482 < 0.0 && tmp483 != 0.0)
  {
    tmp485 = modf(tmp483, &tmp486);
    
    if(tmp485 > 0.5)
    {
      tmp485 -= 1.0;
      tmp486 += 1.0;
    }
    else if(tmp485 < -0.5)
    {
      tmp485 += 1.0;
      tmp486 -= 1.0;
    }
    
    if(fabs(tmp485) < 1e-10)
      tmp484 = pow(tmp482, tmp486);
    else
    {
      tmp488 = modf(1.0/tmp483, &tmp487);
      if(tmp488 > 0.5)
      {
        tmp488 -= 1.0;
        tmp487 += 1.0;
      }
      else if(tmp488 < -0.5)
      {
        tmp488 += 1.0;
        tmp487 -= 1.0;
      }
      if(fabs(tmp488) < 1e-10 && ((unsigned long)tmp487 & 1))
      {
        tmp484 = -pow(-tmp482, tmp485)*pow(tmp482, tmp486);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp482, tmp483);
      }
    }
  }
  else
  {
    tmp484 = pow(tmp482, tmp483);
  }
  if(isnan(tmp484) || isinf(tmp484))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp482, tmp483);
  }tmp489 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */);
  tmp490 = (data->simulationInfo->realParameter[191] /* R_Bs_PB_x_BsPB.nS2e PARAM */);
  if(tmp489 < 0.0 && tmp490 != 0.0)
  {
    tmp492 = modf(tmp490, &tmp493);
    
    if(tmp492 > 0.5)
    {
      tmp492 -= 1.0;
      tmp493 += 1.0;
    }
    else if(tmp492 < -0.5)
    {
      tmp492 += 1.0;
      tmp493 -= 1.0;
    }
    
    if(fabs(tmp492) < 1e-10)
      tmp491 = pow(tmp489, tmp493);
    else
    {
      tmp495 = modf(1.0/tmp490, &tmp494);
      if(tmp495 > 0.5)
      {
        tmp495 -= 1.0;
        tmp494 += 1.0;
      }
      else if(tmp495 < -0.5)
      {
        tmp495 += 1.0;
        tmp494 -= 1.0;
      }
      if(fabs(tmp495) < 1e-10 && ((unsigned long)tmp494 & 1))
      {
        tmp491 = -pow(-tmp489, tmp492)*pow(tmp489, tmp493);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp489, tmp490);
      }
    }
  }
  else
  {
    tmp491 = pow(tmp489, tmp490);
  }
  if(isnan(tmp491) || isinf(tmp491))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp489, tmp490);
  }tmp496 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */);
  tmp497 = (data->simulationInfo->realParameter[189] /* R_Bs_PB_x_BsPB.nP1e PARAM */);
  if(tmp496 < 0.0 && tmp497 != 0.0)
  {
    tmp499 = modf(tmp497, &tmp500);
    
    if(tmp499 > 0.5)
    {
      tmp499 -= 1.0;
      tmp500 += 1.0;
    }
    else if(tmp499 < -0.5)
    {
      tmp499 += 1.0;
      tmp500 -= 1.0;
    }
    
    if(fabs(tmp499) < 1e-10)
      tmp498 = pow(tmp496, tmp500);
    else
    {
      tmp502 = modf(1.0/tmp497, &tmp501);
      if(tmp502 > 0.5)
      {
        tmp502 -= 1.0;
        tmp501 += 1.0;
      }
      else if(tmp502 < -0.5)
      {
        tmp502 += 1.0;
        tmp501 -= 1.0;
      }
      if(fabs(tmp502) < 1e-10 && ((unsigned long)tmp501 & 1))
      {
        tmp498 = -pow(-tmp496, tmp499)*pow(tmp496, tmp500);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp496, tmp497);
      }
    }
  }
  else
  {
    tmp498 = pow(tmp496, tmp497);
  }
  if(isnan(tmp498) || isinf(tmp498))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp496, tmp497);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[275]] /* R_Bs_PB_x_BsPB.rr variable */) = ((data->simulationInfo->realParameter[187] /* R_Bs_PB_x_BsPB.k1 PARAM */)) * ((tmp484) * ((tmp491) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[188] /* R_Bs_PB_x_BsPB.k2 PARAM */)) * ((tmp498) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 389
type: SIMPLE_ASSIGN
R_As_PA_x_AsPA.rr = R_As_PA_x_AsPA.k1 * PA.c ^ R_As_PA_x_AsPA.nS1e * As.c ^ R_As_PA_x_AsPA.nS2e * V - R_As_PA_x_AsPA.k2 * AsPA.c ^ R_As_PA_x_AsPA.nP1e * V
*/
void rPCR_03_eqFunction_389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,389};
  modelica_real tmp503;
  modelica_real tmp504;
  modelica_real tmp505;
  modelica_real tmp506;
  modelica_real tmp507;
  modelica_real tmp508;
  modelica_real tmp509;
  modelica_real tmp510;
  modelica_real tmp511;
  modelica_real tmp512;
  modelica_real tmp513;
  modelica_real tmp514;
  modelica_real tmp515;
  modelica_real tmp516;
  modelica_real tmp517;
  modelica_real tmp518;
  modelica_real tmp519;
  modelica_real tmp520;
  modelica_real tmp521;
  modelica_real tmp522;
  modelica_real tmp523;
  tmp503 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */);
  tmp504 = (data->simulationInfo->realParameter[120] /* R_As_PA_x_AsPA.nS1e PARAM */);
  if(tmp503 < 0.0 && tmp504 != 0.0)
  {
    tmp506 = modf(tmp504, &tmp507);
    
    if(tmp506 > 0.5)
    {
      tmp506 -= 1.0;
      tmp507 += 1.0;
    }
    else if(tmp506 < -0.5)
    {
      tmp506 += 1.0;
      tmp507 -= 1.0;
    }
    
    if(fabs(tmp506) < 1e-10)
      tmp505 = pow(tmp503, tmp507);
    else
    {
      tmp509 = modf(1.0/tmp504, &tmp508);
      if(tmp509 > 0.5)
      {
        tmp509 -= 1.0;
        tmp508 += 1.0;
      }
      else if(tmp509 < -0.5)
      {
        tmp509 += 1.0;
        tmp508 -= 1.0;
      }
      if(fabs(tmp509) < 1e-10 && ((unsigned long)tmp508 & 1))
      {
        tmp505 = -pow(-tmp503, tmp506)*pow(tmp503, tmp507);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp503, tmp504);
      }
    }
  }
  else
  {
    tmp505 = pow(tmp503, tmp504);
  }
  if(isnan(tmp505) || isinf(tmp505))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp503, tmp504);
  }tmp510 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */);
  tmp511 = (data->simulationInfo->realParameter[121] /* R_As_PA_x_AsPA.nS2e PARAM */);
  if(tmp510 < 0.0 && tmp511 != 0.0)
  {
    tmp513 = modf(tmp511, &tmp514);
    
    if(tmp513 > 0.5)
    {
      tmp513 -= 1.0;
      tmp514 += 1.0;
    }
    else if(tmp513 < -0.5)
    {
      tmp513 += 1.0;
      tmp514 -= 1.0;
    }
    
    if(fabs(tmp513) < 1e-10)
      tmp512 = pow(tmp510, tmp514);
    else
    {
      tmp516 = modf(1.0/tmp511, &tmp515);
      if(tmp516 > 0.5)
      {
        tmp516 -= 1.0;
        tmp515 += 1.0;
      }
      else if(tmp516 < -0.5)
      {
        tmp516 += 1.0;
        tmp515 -= 1.0;
      }
      if(fabs(tmp516) < 1e-10 && ((unsigned long)tmp515 & 1))
      {
        tmp512 = -pow(-tmp510, tmp513)*pow(tmp510, tmp514);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp510, tmp511);
      }
    }
  }
  else
  {
    tmp512 = pow(tmp510, tmp511);
  }
  if(isnan(tmp512) || isinf(tmp512))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp510, tmp511);
  }tmp517 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */);
  tmp518 = (data->simulationInfo->realParameter[119] /* R_As_PA_x_AsPA.nP1e PARAM */);
  if(tmp517 < 0.0 && tmp518 != 0.0)
  {
    tmp520 = modf(tmp518, &tmp521);
    
    if(tmp520 > 0.5)
    {
      tmp520 -= 1.0;
      tmp521 += 1.0;
    }
    else if(tmp520 < -0.5)
    {
      tmp520 += 1.0;
      tmp521 -= 1.0;
    }
    
    if(fabs(tmp520) < 1e-10)
      tmp519 = pow(tmp517, tmp521);
    else
    {
      tmp523 = modf(1.0/tmp518, &tmp522);
      if(tmp523 > 0.5)
      {
        tmp523 -= 1.0;
        tmp522 += 1.0;
      }
      else if(tmp523 < -0.5)
      {
        tmp523 += 1.0;
        tmp522 -= 1.0;
      }
      if(fabs(tmp523) < 1e-10 && ((unsigned long)tmp522 & 1))
      {
        tmp519 = -pow(-tmp517, tmp520)*pow(tmp517, tmp521);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp517, tmp518);
      }
    }
  }
  else
  {
    tmp519 = pow(tmp517, tmp518);
  }
  if(isnan(tmp519) || isinf(tmp519))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp517, tmp518);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* R_As_PA_x_AsPA.rr variable */) = ((data->simulationInfo->realParameter[117] /* R_As_PA_x_AsPA.k1 PARAM */)) * ((tmp505) * ((tmp512) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[118] /* R_As_PA_x_AsPA.k2 PARAM */)) * ((tmp519) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 390
type: SIMPLE_ASSIGN
R_AsPA_Prs_x_AsPrsPA.rr = R_AsPA_Prs_x_AsPrsPA.k1 * AsPA.c ^ R_AsPA_Prs_x_AsPrsPA.nS1e * Prs.c ^ R_AsPA_Prs_x_AsPrsPA.nS2e * V - R_AsPA_Prs_x_AsPrsPA.k2 * AsPrsPA.c ^ R_AsPA_Prs_x_AsPrsPA.nP1e * V
*/
void rPCR_03_eqFunction_390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,390};
  modelica_real tmp524;
  modelica_real tmp525;
  modelica_real tmp526;
  modelica_real tmp527;
  modelica_real tmp528;
  modelica_real tmp529;
  modelica_real tmp530;
  modelica_real tmp531;
  modelica_real tmp532;
  modelica_real tmp533;
  modelica_real tmp534;
  modelica_real tmp535;
  modelica_real tmp536;
  modelica_real tmp537;
  modelica_real tmp538;
  modelica_real tmp539;
  modelica_real tmp540;
  modelica_real tmp541;
  modelica_real tmp542;
  modelica_real tmp543;
  modelica_real tmp544;
  tmp524 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */);
  tmp525 = (data->simulationInfo->realParameter[95] /* R_AsPA_Prs_x_AsPrsPA.nS1e PARAM */);
  if(tmp524 < 0.0 && tmp525 != 0.0)
  {
    tmp527 = modf(tmp525, &tmp528);
    
    if(tmp527 > 0.5)
    {
      tmp527 -= 1.0;
      tmp528 += 1.0;
    }
    else if(tmp527 < -0.5)
    {
      tmp527 += 1.0;
      tmp528 -= 1.0;
    }
    
    if(fabs(tmp527) < 1e-10)
      tmp526 = pow(tmp524, tmp528);
    else
    {
      tmp530 = modf(1.0/tmp525, &tmp529);
      if(tmp530 > 0.5)
      {
        tmp530 -= 1.0;
        tmp529 += 1.0;
      }
      else if(tmp530 < -0.5)
      {
        tmp530 += 1.0;
        tmp529 -= 1.0;
      }
      if(fabs(tmp530) < 1e-10 && ((unsigned long)tmp529 & 1))
      {
        tmp526 = -pow(-tmp524, tmp527)*pow(tmp524, tmp528);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp524, tmp525);
      }
    }
  }
  else
  {
    tmp526 = pow(tmp524, tmp525);
  }
  if(isnan(tmp526) || isinf(tmp526))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp524, tmp525);
  }tmp531 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */);
  tmp532 = (data->simulationInfo->realParameter[96] /* R_AsPA_Prs_x_AsPrsPA.nS2e PARAM */);
  if(tmp531 < 0.0 && tmp532 != 0.0)
  {
    tmp534 = modf(tmp532, &tmp535);
    
    if(tmp534 > 0.5)
    {
      tmp534 -= 1.0;
      tmp535 += 1.0;
    }
    else if(tmp534 < -0.5)
    {
      tmp534 += 1.0;
      tmp535 -= 1.0;
    }
    
    if(fabs(tmp534) < 1e-10)
      tmp533 = pow(tmp531, tmp535);
    else
    {
      tmp537 = modf(1.0/tmp532, &tmp536);
      if(tmp537 > 0.5)
      {
        tmp537 -= 1.0;
        tmp536 += 1.0;
      }
      else if(tmp537 < -0.5)
      {
        tmp537 += 1.0;
        tmp536 -= 1.0;
      }
      if(fabs(tmp537) < 1e-10 && ((unsigned long)tmp536 & 1))
      {
        tmp533 = -pow(-tmp531, tmp534)*pow(tmp531, tmp535);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp531, tmp532);
      }
    }
  }
  else
  {
    tmp533 = pow(tmp531, tmp532);
  }
  if(isnan(tmp533) || isinf(tmp533))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp531, tmp532);
  }tmp538 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */);
  tmp539 = (data->simulationInfo->realParameter[94] /* R_AsPA_Prs_x_AsPrsPA.nP1e PARAM */);
  if(tmp538 < 0.0 && tmp539 != 0.0)
  {
    tmp541 = modf(tmp539, &tmp542);
    
    if(tmp541 > 0.5)
    {
      tmp541 -= 1.0;
      tmp542 += 1.0;
    }
    else if(tmp541 < -0.5)
    {
      tmp541 += 1.0;
      tmp542 -= 1.0;
    }
    
    if(fabs(tmp541) < 1e-10)
      tmp540 = pow(tmp538, tmp542);
    else
    {
      tmp544 = modf(1.0/tmp539, &tmp543);
      if(tmp544 > 0.5)
      {
        tmp544 -= 1.0;
        tmp543 += 1.0;
      }
      else if(tmp544 < -0.5)
      {
        tmp544 += 1.0;
        tmp543 -= 1.0;
      }
      if(fabs(tmp544) < 1e-10 && ((unsigned long)tmp543 & 1))
      {
        tmp540 = -pow(-tmp538, tmp541)*pow(tmp538, tmp542);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp538, tmp539);
      }
    }
  }
  else
  {
    tmp540 = pow(tmp538, tmp539);
  }
  if(isnan(tmp540) || isinf(tmp540))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp538, tmp539);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[199]] /* R_AsPA_Prs_x_AsPrsPA.rr variable */) = ((data->simulationInfo->realParameter[92] /* R_AsPA_Prs_x_AsPrsPA.k1 PARAM */)) * ((tmp526) * ((tmp533) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[93] /* R_AsPA_Prs_x_AsPrsPA.k2 PARAM */)) * ((tmp540) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 391
type: SIMPLE_ASSIGN
R_BsPB_Prs_x_BsPrsPB.rr = R_BsPB_Prs_x_BsPrsPB.k1 * Prs.c ^ R_BsPB_Prs_x_BsPrsPB.nS1e * BsPB.c ^ R_BsPB_Prs_x_BsPrsPB.nS2e * V - R_BsPB_Prs_x_BsPrsPB.k2 * BsPrsPB.c ^ R_BsPB_Prs_x_BsPrsPB.nP1e * V
*/
void rPCR_03_eqFunction_391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,391};
  modelica_real tmp545;
  modelica_real tmp546;
  modelica_real tmp547;
  modelica_real tmp548;
  modelica_real tmp549;
  modelica_real tmp550;
  modelica_real tmp551;
  modelica_real tmp552;
  modelica_real tmp553;
  modelica_real tmp554;
  modelica_real tmp555;
  modelica_real tmp556;
  modelica_real tmp557;
  modelica_real tmp558;
  modelica_real tmp559;
  modelica_real tmp560;
  modelica_real tmp561;
  modelica_real tmp562;
  modelica_real tmp563;
  modelica_real tmp564;
  modelica_real tmp565;
  tmp545 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */);
  tmp546 = (data->simulationInfo->realParameter[170] /* R_BsPB_Prs_x_BsPrsPB.nS1e PARAM */);
  if(tmp545 < 0.0 && tmp546 != 0.0)
  {
    tmp548 = modf(tmp546, &tmp549);
    
    if(tmp548 > 0.5)
    {
      tmp548 -= 1.0;
      tmp549 += 1.0;
    }
    else if(tmp548 < -0.5)
    {
      tmp548 += 1.0;
      tmp549 -= 1.0;
    }
    
    if(fabs(tmp548) < 1e-10)
      tmp547 = pow(tmp545, tmp549);
    else
    {
      tmp551 = modf(1.0/tmp546, &tmp550);
      if(tmp551 > 0.5)
      {
        tmp551 -= 1.0;
        tmp550 += 1.0;
      }
      else if(tmp551 < -0.5)
      {
        tmp551 += 1.0;
        tmp550 -= 1.0;
      }
      if(fabs(tmp551) < 1e-10 && ((unsigned long)tmp550 & 1))
      {
        tmp547 = -pow(-tmp545, tmp548)*pow(tmp545, tmp549);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp545, tmp546);
      }
    }
  }
  else
  {
    tmp547 = pow(tmp545, tmp546);
  }
  if(isnan(tmp547) || isinf(tmp547))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp545, tmp546);
  }tmp552 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */);
  tmp553 = (data->simulationInfo->realParameter[171] /* R_BsPB_Prs_x_BsPrsPB.nS2e PARAM */);
  if(tmp552 < 0.0 && tmp553 != 0.0)
  {
    tmp555 = modf(tmp553, &tmp556);
    
    if(tmp555 > 0.5)
    {
      tmp555 -= 1.0;
      tmp556 += 1.0;
    }
    else if(tmp555 < -0.5)
    {
      tmp555 += 1.0;
      tmp556 -= 1.0;
    }
    
    if(fabs(tmp555) < 1e-10)
      tmp554 = pow(tmp552, tmp556);
    else
    {
      tmp558 = modf(1.0/tmp553, &tmp557);
      if(tmp558 > 0.5)
      {
        tmp558 -= 1.0;
        tmp557 += 1.0;
      }
      else if(tmp558 < -0.5)
      {
        tmp558 += 1.0;
        tmp557 -= 1.0;
      }
      if(fabs(tmp558) < 1e-10 && ((unsigned long)tmp557 & 1))
      {
        tmp554 = -pow(-tmp552, tmp555)*pow(tmp552, tmp556);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp552, tmp553);
      }
    }
  }
  else
  {
    tmp554 = pow(tmp552, tmp553);
  }
  if(isnan(tmp554) || isinf(tmp554))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp552, tmp553);
  }tmp559 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */);
  tmp560 = (data->simulationInfo->realParameter[169] /* R_BsPB_Prs_x_BsPrsPB.nP1e PARAM */);
  if(tmp559 < 0.0 && tmp560 != 0.0)
  {
    tmp562 = modf(tmp560, &tmp563);
    
    if(tmp562 > 0.5)
    {
      tmp562 -= 1.0;
      tmp563 += 1.0;
    }
    else if(tmp562 < -0.5)
    {
      tmp562 += 1.0;
      tmp563 -= 1.0;
    }
    
    if(fabs(tmp562) < 1e-10)
      tmp561 = pow(tmp559, tmp563);
    else
    {
      tmp565 = modf(1.0/tmp560, &tmp564);
      if(tmp565 > 0.5)
      {
        tmp565 -= 1.0;
        tmp564 += 1.0;
      }
      else if(tmp565 < -0.5)
      {
        tmp565 += 1.0;
        tmp564 -= 1.0;
      }
      if(fabs(tmp565) < 1e-10 && ((unsigned long)tmp564 & 1))
      {
        tmp561 = -pow(-tmp559, tmp562)*pow(tmp559, tmp563);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp559, tmp560);
      }
    }
  }
  else
  {
    tmp561 = pow(tmp559, tmp560);
  }
  if(isnan(tmp561) || isinf(tmp561))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp559, tmp560);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[259]] /* R_BsPB_Prs_x_BsPrsPB.rr variable */) = ((data->simulationInfo->realParameter[167] /* R_BsPB_Prs_x_BsPrsPB.k1 PARAM */)) * ((tmp547) * ((tmp554) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[168] /* R_BsPB_Prs_x_BsPrsPB.k2 PARAM */)) * ((tmp561) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 392
type: SIMPLE_ASSIGN
R_Bs_Prs_x_BsPrs.rr = R_Bs_Prs_x_BsPrs.k1 * Bs.c ^ R_Bs_Prs_x_BsPrs.nS1e * Prs.c ^ R_Bs_Prs_x_BsPrs.nS2e * V - R_Bs_Prs_x_BsPrs.k2 * BsPrs.c ^ R_Bs_Prs_x_BsPrs.nP1e * V
*/
void rPCR_03_eqFunction_392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,392};
  modelica_real tmp566;
  modelica_real tmp567;
  modelica_real tmp568;
  modelica_real tmp569;
  modelica_real tmp570;
  modelica_real tmp571;
  modelica_real tmp572;
  modelica_real tmp573;
  modelica_real tmp574;
  modelica_real tmp575;
  modelica_real tmp576;
  modelica_real tmp577;
  modelica_real tmp578;
  modelica_real tmp579;
  modelica_real tmp580;
  modelica_real tmp581;
  modelica_real tmp582;
  modelica_real tmp583;
  modelica_real tmp584;
  modelica_real tmp585;
  modelica_real tmp586;
  tmp566 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */);
  tmp567 = (data->simulationInfo->realParameter[195] /* R_Bs_Prs_x_BsPrs.nS1e PARAM */);
  if(tmp566 < 0.0 && tmp567 != 0.0)
  {
    tmp569 = modf(tmp567, &tmp570);
    
    if(tmp569 > 0.5)
    {
      tmp569 -= 1.0;
      tmp570 += 1.0;
    }
    else if(tmp569 < -0.5)
    {
      tmp569 += 1.0;
      tmp570 -= 1.0;
    }
    
    if(fabs(tmp569) < 1e-10)
      tmp568 = pow(tmp566, tmp570);
    else
    {
      tmp572 = modf(1.0/tmp567, &tmp571);
      if(tmp572 > 0.5)
      {
        tmp572 -= 1.0;
        tmp571 += 1.0;
      }
      else if(tmp572 < -0.5)
      {
        tmp572 += 1.0;
        tmp571 -= 1.0;
      }
      if(fabs(tmp572) < 1e-10 && ((unsigned long)tmp571 & 1))
      {
        tmp568 = -pow(-tmp566, tmp569)*pow(tmp566, tmp570);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp566, tmp567);
      }
    }
  }
  else
  {
    tmp568 = pow(tmp566, tmp567);
  }
  if(isnan(tmp568) || isinf(tmp568))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp566, tmp567);
  }tmp573 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */);
  tmp574 = (data->simulationInfo->realParameter[196] /* R_Bs_Prs_x_BsPrs.nS2e PARAM */);
  if(tmp573 < 0.0 && tmp574 != 0.0)
  {
    tmp576 = modf(tmp574, &tmp577);
    
    if(tmp576 > 0.5)
    {
      tmp576 -= 1.0;
      tmp577 += 1.0;
    }
    else if(tmp576 < -0.5)
    {
      tmp576 += 1.0;
      tmp577 -= 1.0;
    }
    
    if(fabs(tmp576) < 1e-10)
      tmp575 = pow(tmp573, tmp577);
    else
    {
      tmp579 = modf(1.0/tmp574, &tmp578);
      if(tmp579 > 0.5)
      {
        tmp579 -= 1.0;
        tmp578 += 1.0;
      }
      else if(tmp579 < -0.5)
      {
        tmp579 += 1.0;
        tmp578 -= 1.0;
      }
      if(fabs(tmp579) < 1e-10 && ((unsigned long)tmp578 & 1))
      {
        tmp575 = -pow(-tmp573, tmp576)*pow(tmp573, tmp577);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp573, tmp574);
      }
    }
  }
  else
  {
    tmp575 = pow(tmp573, tmp574);
  }
  if(isnan(tmp575) || isinf(tmp575))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp573, tmp574);
  }tmp580 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */);
  tmp581 = (data->simulationInfo->realParameter[194] /* R_Bs_Prs_x_BsPrs.nP1e PARAM */);
  if(tmp580 < 0.0 && tmp581 != 0.0)
  {
    tmp583 = modf(tmp581, &tmp584);
    
    if(tmp583 > 0.5)
    {
      tmp583 -= 1.0;
      tmp584 += 1.0;
    }
    else if(tmp583 < -0.5)
    {
      tmp583 += 1.0;
      tmp584 -= 1.0;
    }
    
    if(fabs(tmp583) < 1e-10)
      tmp582 = pow(tmp580, tmp584);
    else
    {
      tmp586 = modf(1.0/tmp581, &tmp585);
      if(tmp586 > 0.5)
      {
        tmp586 -= 1.0;
        tmp585 += 1.0;
      }
      else if(tmp586 < -0.5)
      {
        tmp586 += 1.0;
        tmp585 -= 1.0;
      }
      if(fabs(tmp586) < 1e-10 && ((unsigned long)tmp585 & 1))
      {
        tmp582 = -pow(-tmp580, tmp583)*pow(tmp580, tmp584);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp580, tmp581);
      }
    }
  }
  else
  {
    tmp582 = pow(tmp580, tmp581);
  }
  if(isnan(tmp582) || isinf(tmp582))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp580, tmp581);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[279]] /* R_Bs_Prs_x_BsPrs.rr variable */) = ((data->simulationInfo->realParameter[192] /* R_Bs_Prs_x_BsPrs.k1 PARAM */)) * ((tmp568) * ((tmp575) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[193] /* R_Bs_Prs_x_BsPrs.k2 PARAM */)) * ((tmp582) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 393
type: SIMPLE_ASSIGN
R_As_Prs_x_AsPrs.rr = R_As_Prs_x_AsPrs.k1 * Prs.c ^ R_As_Prs_x_AsPrs.nS1e * As.c ^ R_As_Prs_x_AsPrs.nS2e * V - R_As_Prs_x_AsPrs.k2 * AsPrs.c ^ R_As_Prs_x_AsPrs.nP1e * V
*/
void rPCR_03_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
  modelica_real tmp587;
  modelica_real tmp588;
  modelica_real tmp589;
  modelica_real tmp590;
  modelica_real tmp591;
  modelica_real tmp592;
  modelica_real tmp593;
  modelica_real tmp594;
  modelica_real tmp595;
  modelica_real tmp596;
  modelica_real tmp597;
  modelica_real tmp598;
  modelica_real tmp599;
  modelica_real tmp600;
  modelica_real tmp601;
  modelica_real tmp602;
  modelica_real tmp603;
  modelica_real tmp604;
  modelica_real tmp605;
  modelica_real tmp606;
  modelica_real tmp607;
  tmp587 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */);
  tmp588 = (data->simulationInfo->realParameter[125] /* R_As_Prs_x_AsPrs.nS1e PARAM */);
  if(tmp587 < 0.0 && tmp588 != 0.0)
  {
    tmp590 = modf(tmp588, &tmp591);
    
    if(tmp590 > 0.5)
    {
      tmp590 -= 1.0;
      tmp591 += 1.0;
    }
    else if(tmp590 < -0.5)
    {
      tmp590 += 1.0;
      tmp591 -= 1.0;
    }
    
    if(fabs(tmp590) < 1e-10)
      tmp589 = pow(tmp587, tmp591);
    else
    {
      tmp593 = modf(1.0/tmp588, &tmp592);
      if(tmp593 > 0.5)
      {
        tmp593 -= 1.0;
        tmp592 += 1.0;
      }
      else if(tmp593 < -0.5)
      {
        tmp593 += 1.0;
        tmp592 -= 1.0;
      }
      if(fabs(tmp593) < 1e-10 && ((unsigned long)tmp592 & 1))
      {
        tmp589 = -pow(-tmp587, tmp590)*pow(tmp587, tmp591);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp587, tmp588);
      }
    }
  }
  else
  {
    tmp589 = pow(tmp587, tmp588);
  }
  if(isnan(tmp589) || isinf(tmp589))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp587, tmp588);
  }tmp594 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */);
  tmp595 = (data->simulationInfo->realParameter[126] /* R_As_Prs_x_AsPrs.nS2e PARAM */);
  if(tmp594 < 0.0 && tmp595 != 0.0)
  {
    tmp597 = modf(tmp595, &tmp598);
    
    if(tmp597 > 0.5)
    {
      tmp597 -= 1.0;
      tmp598 += 1.0;
    }
    else if(tmp597 < -0.5)
    {
      tmp597 += 1.0;
      tmp598 -= 1.0;
    }
    
    if(fabs(tmp597) < 1e-10)
      tmp596 = pow(tmp594, tmp598);
    else
    {
      tmp600 = modf(1.0/tmp595, &tmp599);
      if(tmp600 > 0.5)
      {
        tmp600 -= 1.0;
        tmp599 += 1.0;
      }
      else if(tmp600 < -0.5)
      {
        tmp600 += 1.0;
        tmp599 -= 1.0;
      }
      if(fabs(tmp600) < 1e-10 && ((unsigned long)tmp599 & 1))
      {
        tmp596 = -pow(-tmp594, tmp597)*pow(tmp594, tmp598);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp594, tmp595);
      }
    }
  }
  else
  {
    tmp596 = pow(tmp594, tmp595);
  }
  if(isnan(tmp596) || isinf(tmp596))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp594, tmp595);
  }tmp601 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */);
  tmp602 = (data->simulationInfo->realParameter[124] /* R_As_Prs_x_AsPrs.nP1e PARAM */);
  if(tmp601 < 0.0 && tmp602 != 0.0)
  {
    tmp604 = modf(tmp602, &tmp605);
    
    if(tmp604 > 0.5)
    {
      tmp604 -= 1.0;
      tmp605 += 1.0;
    }
    else if(tmp604 < -0.5)
    {
      tmp604 += 1.0;
      tmp605 -= 1.0;
    }
    
    if(fabs(tmp604) < 1e-10)
      tmp603 = pow(tmp601, tmp605);
    else
    {
      tmp607 = modf(1.0/tmp602, &tmp606);
      if(tmp607 > 0.5)
      {
        tmp607 -= 1.0;
        tmp606 += 1.0;
      }
      else if(tmp607 < -0.5)
      {
        tmp607 += 1.0;
        tmp606 -= 1.0;
      }
      if(fabs(tmp607) < 1e-10 && ((unsigned long)tmp606 & 1))
      {
        tmp603 = -pow(-tmp601, tmp604)*pow(tmp601, tmp605);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp601, tmp602);
      }
    }
  }
  else
  {
    tmp603 = pow(tmp601, tmp602);
  }
  if(isnan(tmp603) || isinf(tmp603))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp601, tmp602);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* R_As_Prs_x_AsPrs.rr variable */) = ((data->simulationInfo->realParameter[122] /* R_As_Prs_x_AsPrs.k1 PARAM */)) * ((tmp589) * ((tmp596) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[123] /* R_As_Prs_x_AsPrs.k2 PARAM */)) * ((tmp603) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 394
type: SIMPLE_ASSIGN
R_Aa_Pra_x_AaPra.rr = R_Aa_Pra_x_AaPra.k1 * Pra.c ^ R_Aa_Pra_x_AaPra.nS1e * Aa.c ^ R_Aa_Pra_x_AaPra.nS2e * V - R_Aa_Pra_x_AaPra.k2 * AaPra.c ^ R_Aa_Pra_x_AaPra.nP1e * V
*/
void rPCR_03_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  modelica_real tmp608;
  modelica_real tmp609;
  modelica_real tmp610;
  modelica_real tmp611;
  modelica_real tmp612;
  modelica_real tmp613;
  modelica_real tmp614;
  modelica_real tmp615;
  modelica_real tmp616;
  modelica_real tmp617;
  modelica_real tmp618;
  modelica_real tmp619;
  modelica_real tmp620;
  modelica_real tmp621;
  modelica_real tmp622;
  modelica_real tmp623;
  modelica_real tmp624;
  modelica_real tmp625;
  modelica_real tmp626;
  modelica_real tmp627;
  modelica_real tmp628;
  tmp608 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */);
  tmp609 = (data->simulationInfo->realParameter[85] /* R_Aa_Pra_x_AaPra.nS1e PARAM */);
  if(tmp608 < 0.0 && tmp609 != 0.0)
  {
    tmp611 = modf(tmp609, &tmp612);
    
    if(tmp611 > 0.5)
    {
      tmp611 -= 1.0;
      tmp612 += 1.0;
    }
    else if(tmp611 < -0.5)
    {
      tmp611 += 1.0;
      tmp612 -= 1.0;
    }
    
    if(fabs(tmp611) < 1e-10)
      tmp610 = pow(tmp608, tmp612);
    else
    {
      tmp614 = modf(1.0/tmp609, &tmp613);
      if(tmp614 > 0.5)
      {
        tmp614 -= 1.0;
        tmp613 += 1.0;
      }
      else if(tmp614 < -0.5)
      {
        tmp614 += 1.0;
        tmp613 -= 1.0;
      }
      if(fabs(tmp614) < 1e-10 && ((unsigned long)tmp613 & 1))
      {
        tmp610 = -pow(-tmp608, tmp611)*pow(tmp608, tmp612);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp608, tmp609);
      }
    }
  }
  else
  {
    tmp610 = pow(tmp608, tmp609);
  }
  if(isnan(tmp610) || isinf(tmp610))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp608, tmp609);
  }tmp615 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */);
  tmp616 = (data->simulationInfo->realParameter[86] /* R_Aa_Pra_x_AaPra.nS2e PARAM */);
  if(tmp615 < 0.0 && tmp616 != 0.0)
  {
    tmp618 = modf(tmp616, &tmp619);
    
    if(tmp618 > 0.5)
    {
      tmp618 -= 1.0;
      tmp619 += 1.0;
    }
    else if(tmp618 < -0.5)
    {
      tmp618 += 1.0;
      tmp619 -= 1.0;
    }
    
    if(fabs(tmp618) < 1e-10)
      tmp617 = pow(tmp615, tmp619);
    else
    {
      tmp621 = modf(1.0/tmp616, &tmp620);
      if(tmp621 > 0.5)
      {
        tmp621 -= 1.0;
        tmp620 += 1.0;
      }
      else if(tmp621 < -0.5)
      {
        tmp621 += 1.0;
        tmp620 -= 1.0;
      }
      if(fabs(tmp621) < 1e-10 && ((unsigned long)tmp620 & 1))
      {
        tmp617 = -pow(-tmp615, tmp618)*pow(tmp615, tmp619);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp615, tmp616);
      }
    }
  }
  else
  {
    tmp617 = pow(tmp615, tmp616);
  }
  if(isnan(tmp617) || isinf(tmp617))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp615, tmp616);
  }tmp622 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */);
  tmp623 = (data->simulationInfo->realParameter[84] /* R_Aa_Pra_x_AaPra.nP1e PARAM */);
  if(tmp622 < 0.0 && tmp623 != 0.0)
  {
    tmp625 = modf(tmp623, &tmp626);
    
    if(tmp625 > 0.5)
    {
      tmp625 -= 1.0;
      tmp626 += 1.0;
    }
    else if(tmp625 < -0.5)
    {
      tmp625 += 1.0;
      tmp626 -= 1.0;
    }
    
    if(fabs(tmp625) < 1e-10)
      tmp624 = pow(tmp622, tmp626);
    else
    {
      tmp628 = modf(1.0/tmp623, &tmp627);
      if(tmp628 > 0.5)
      {
        tmp628 -= 1.0;
        tmp627 += 1.0;
      }
      else if(tmp628 < -0.5)
      {
        tmp628 += 1.0;
        tmp627 -= 1.0;
      }
      if(fabs(tmp628) < 1e-10 && ((unsigned long)tmp627 & 1))
      {
        tmp624 = -pow(-tmp622, tmp625)*pow(tmp622, tmp626);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp622, tmp623);
      }
    }
  }
  else
  {
    tmp624 = pow(tmp622, tmp623);
  }
  if(isnan(tmp624) || isinf(tmp624))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp622, tmp623);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* R_Aa_Pra_x_AaPra.rr variable */) = ((data->simulationInfo->realParameter[82] /* R_Aa_Pra_x_AaPra.k1 PARAM */)) * ((tmp610) * ((tmp617) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[83] /* R_Aa_Pra_x_AaPra.k2 PARAM */)) * ((tmp624) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 395
type: SIMPLE_ASSIGN
R_Ba_Pra_x_BaPra.rr = R_Ba_Pra_x_BaPra.k1 * Ba.c ^ R_Ba_Pra_x_BaPra.nS1e * Pra.c ^ R_Ba_Pra_x_BaPra.nS2e * V - R_Ba_Pra_x_BaPra.k2 * BaPra.c ^ R_Ba_Pra_x_BaPra.nP1e * V
*/
void rPCR_03_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  modelica_real tmp629;
  modelica_real tmp630;
  modelica_real tmp631;
  modelica_real tmp632;
  modelica_real tmp633;
  modelica_real tmp634;
  modelica_real tmp635;
  modelica_real tmp636;
  modelica_real tmp637;
  modelica_real tmp638;
  modelica_real tmp639;
  modelica_real tmp640;
  modelica_real tmp641;
  modelica_real tmp642;
  modelica_real tmp643;
  modelica_real tmp644;
  modelica_real tmp645;
  modelica_real tmp646;
  modelica_real tmp647;
  modelica_real tmp648;
  modelica_real tmp649;
  tmp629 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */);
  tmp630 = (data->simulationInfo->realParameter[165] /* R_Ba_Pra_x_BaPra.nS1e PARAM */);
  if(tmp629 < 0.0 && tmp630 != 0.0)
  {
    tmp632 = modf(tmp630, &tmp633);
    
    if(tmp632 > 0.5)
    {
      tmp632 -= 1.0;
      tmp633 += 1.0;
    }
    else if(tmp632 < -0.5)
    {
      tmp632 += 1.0;
      tmp633 -= 1.0;
    }
    
    if(fabs(tmp632) < 1e-10)
      tmp631 = pow(tmp629, tmp633);
    else
    {
      tmp635 = modf(1.0/tmp630, &tmp634);
      if(tmp635 > 0.5)
      {
        tmp635 -= 1.0;
        tmp634 += 1.0;
      }
      else if(tmp635 < -0.5)
      {
        tmp635 += 1.0;
        tmp634 -= 1.0;
      }
      if(fabs(tmp635) < 1e-10 && ((unsigned long)tmp634 & 1))
      {
        tmp631 = -pow(-tmp629, tmp632)*pow(tmp629, tmp633);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp629, tmp630);
      }
    }
  }
  else
  {
    tmp631 = pow(tmp629, tmp630);
  }
  if(isnan(tmp631) || isinf(tmp631))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp629, tmp630);
  }tmp636 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */);
  tmp637 = (data->simulationInfo->realParameter[166] /* R_Ba_Pra_x_BaPra.nS2e PARAM */);
  if(tmp636 < 0.0 && tmp637 != 0.0)
  {
    tmp639 = modf(tmp637, &tmp640);
    
    if(tmp639 > 0.5)
    {
      tmp639 -= 1.0;
      tmp640 += 1.0;
    }
    else if(tmp639 < -0.5)
    {
      tmp639 += 1.0;
      tmp640 -= 1.0;
    }
    
    if(fabs(tmp639) < 1e-10)
      tmp638 = pow(tmp636, tmp640);
    else
    {
      tmp642 = modf(1.0/tmp637, &tmp641);
      if(tmp642 > 0.5)
      {
        tmp642 -= 1.0;
        tmp641 += 1.0;
      }
      else if(tmp642 < -0.5)
      {
        tmp642 += 1.0;
        tmp641 -= 1.0;
      }
      if(fabs(tmp642) < 1e-10 && ((unsigned long)tmp641 & 1))
      {
        tmp638 = -pow(-tmp636, tmp639)*pow(tmp636, tmp640);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp636, tmp637);
      }
    }
  }
  else
  {
    tmp638 = pow(tmp636, tmp637);
  }
  if(isnan(tmp638) || isinf(tmp638))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp636, tmp637);
  }tmp643 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */);
  tmp644 = (data->simulationInfo->realParameter[164] /* R_Ba_Pra_x_BaPra.nP1e PARAM */);
  if(tmp643 < 0.0 && tmp644 != 0.0)
  {
    tmp646 = modf(tmp644, &tmp647);
    
    if(tmp646 > 0.5)
    {
      tmp646 -= 1.0;
      tmp647 += 1.0;
    }
    else if(tmp646 < -0.5)
    {
      tmp646 += 1.0;
      tmp647 -= 1.0;
    }
    
    if(fabs(tmp646) < 1e-10)
      tmp645 = pow(tmp643, tmp647);
    else
    {
      tmp649 = modf(1.0/tmp644, &tmp648);
      if(tmp649 > 0.5)
      {
        tmp649 -= 1.0;
        tmp648 += 1.0;
      }
      else if(tmp649 < -0.5)
      {
        tmp649 += 1.0;
        tmp648 -= 1.0;
      }
      if(fabs(tmp649) < 1e-10 && ((unsigned long)tmp648 & 1))
      {
        tmp645 = -pow(-tmp643, tmp646)*pow(tmp643, tmp647);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp643, tmp644);
      }
    }
  }
  else
  {
    tmp645 = pow(tmp643, tmp644);
  }
  if(isnan(tmp645) || isinf(tmp645))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp643, tmp644);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[255]] /* R_Ba_Pra_x_BaPra.rr variable */) = ((data->simulationInfo->realParameter[162] /* R_Ba_Pra_x_BaPra.k1 PARAM */)) * ((tmp631) * ((tmp638) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[163] /* R_Ba_Pra_x_BaPra.k2 PARAM */)) * ((tmp645) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 396
type: SIMPLE_ASSIGN
R_As_Ba_x_AsBa.rr = R_As_Ba_x_AsBa.k1 * As.c ^ R_As_Ba_x_AsBa.nS1e * Ba.c ^ R_As_Ba_x_AsBa.nS2e * V - R_As_Ba_x_AsBa.k2 * AsBa.c ^ R_As_Ba_x_AsBa.nP1e * V
*/
void rPCR_03_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
  modelica_real tmp650;
  modelica_real tmp651;
  modelica_real tmp652;
  modelica_real tmp653;
  modelica_real tmp654;
  modelica_real tmp655;
  modelica_real tmp656;
  modelica_real tmp657;
  modelica_real tmp658;
  modelica_real tmp659;
  modelica_real tmp660;
  modelica_real tmp661;
  modelica_real tmp662;
  modelica_real tmp663;
  modelica_real tmp664;
  modelica_real tmp665;
  modelica_real tmp666;
  modelica_real tmp667;
  modelica_real tmp668;
  modelica_real tmp669;
  modelica_real tmp670;
  tmp650 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */);
  tmp651 = (data->simulationInfo->realParameter[115] /* R_As_Ba_x_AsBa.nS1e PARAM */);
  if(tmp650 < 0.0 && tmp651 != 0.0)
  {
    tmp653 = modf(tmp651, &tmp654);
    
    if(tmp653 > 0.5)
    {
      tmp653 -= 1.0;
      tmp654 += 1.0;
    }
    else if(tmp653 < -0.5)
    {
      tmp653 += 1.0;
      tmp654 -= 1.0;
    }
    
    if(fabs(tmp653) < 1e-10)
      tmp652 = pow(tmp650, tmp654);
    else
    {
      tmp656 = modf(1.0/tmp651, &tmp655);
      if(tmp656 > 0.5)
      {
        tmp656 -= 1.0;
        tmp655 += 1.0;
      }
      else if(tmp656 < -0.5)
      {
        tmp656 += 1.0;
        tmp655 -= 1.0;
      }
      if(fabs(tmp656) < 1e-10 && ((unsigned long)tmp655 & 1))
      {
        tmp652 = -pow(-tmp650, tmp653)*pow(tmp650, tmp654);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp650, tmp651);
      }
    }
  }
  else
  {
    tmp652 = pow(tmp650, tmp651);
  }
  if(isnan(tmp652) || isinf(tmp652))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp650, tmp651);
  }tmp657 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */);
  tmp658 = (data->simulationInfo->realParameter[116] /* R_As_Ba_x_AsBa.nS2e PARAM */);
  if(tmp657 < 0.0 && tmp658 != 0.0)
  {
    tmp660 = modf(tmp658, &tmp661);
    
    if(tmp660 > 0.5)
    {
      tmp660 -= 1.0;
      tmp661 += 1.0;
    }
    else if(tmp660 < -0.5)
    {
      tmp660 += 1.0;
      tmp661 -= 1.0;
    }
    
    if(fabs(tmp660) < 1e-10)
      tmp659 = pow(tmp657, tmp661);
    else
    {
      tmp663 = modf(1.0/tmp658, &tmp662);
      if(tmp663 > 0.5)
      {
        tmp663 -= 1.0;
        tmp662 += 1.0;
      }
      else if(tmp663 < -0.5)
      {
        tmp663 += 1.0;
        tmp662 -= 1.0;
      }
      if(fabs(tmp663) < 1e-10 && ((unsigned long)tmp662 & 1))
      {
        tmp659 = -pow(-tmp657, tmp660)*pow(tmp657, tmp661);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp657, tmp658);
      }
    }
  }
  else
  {
    tmp659 = pow(tmp657, tmp658);
  }
  if(isnan(tmp659) || isinf(tmp659))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp657, tmp658);
  }tmp664 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */);
  tmp665 = (data->simulationInfo->realParameter[114] /* R_As_Ba_x_AsBa.nP1e PARAM */);
  if(tmp664 < 0.0 && tmp665 != 0.0)
  {
    tmp667 = modf(tmp665, &tmp668);
    
    if(tmp667 > 0.5)
    {
      tmp667 -= 1.0;
      tmp668 += 1.0;
    }
    else if(tmp667 < -0.5)
    {
      tmp667 += 1.0;
      tmp668 -= 1.0;
    }
    
    if(fabs(tmp667) < 1e-10)
      tmp666 = pow(tmp664, tmp668);
    else
    {
      tmp670 = modf(1.0/tmp665, &tmp669);
      if(tmp670 > 0.5)
      {
        tmp670 -= 1.0;
        tmp669 += 1.0;
      }
      else if(tmp670 < -0.5)
      {
        tmp670 += 1.0;
        tmp669 -= 1.0;
      }
      if(fabs(tmp670) < 1e-10 && ((unsigned long)tmp669 & 1))
      {
        tmp666 = -pow(-tmp664, tmp667)*pow(tmp664, tmp668);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp664, tmp665);
      }
    }
  }
  else
  {
    tmp666 = pow(tmp664, tmp665);
  }
  if(isnan(tmp666) || isinf(tmp666))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp664, tmp665);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* R_As_Ba_x_AsBa.rr variable */) = ((data->simulationInfo->realParameter[112] /* R_As_Ba_x_AsBa.k1 PARAM */)) * ((tmp652) * ((tmp659) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[113] /* R_As_Ba_x_AsBa.k2 PARAM */)) * ((tmp666) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 397
type: SIMPLE_ASSIGN
R_Aa_Bs_x_AaBs.rr = R_Aa_Bs_x_AaBs.k1 * Aa.c ^ R_Aa_Bs_x_AaBs.nS1e * Bs.c ^ R_Aa_Bs_x_AaBs.nS2e * V - R_Aa_Bs_x_AaBs.k2 * AaBs.c ^ R_Aa_Bs_x_AaBs.nP1e * V
*/
void rPCR_03_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
  modelica_real tmp671;
  modelica_real tmp672;
  modelica_real tmp673;
  modelica_real tmp674;
  modelica_real tmp675;
  modelica_real tmp676;
  modelica_real tmp677;
  modelica_real tmp678;
  modelica_real tmp679;
  modelica_real tmp680;
  modelica_real tmp681;
  modelica_real tmp682;
  modelica_real tmp683;
  modelica_real tmp684;
  modelica_real tmp685;
  modelica_real tmp686;
  modelica_real tmp687;
  modelica_real tmp688;
  modelica_real tmp689;
  modelica_real tmp690;
  modelica_real tmp691;
  tmp671 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */);
  tmp672 = (data->simulationInfo->realParameter[75] /* R_Aa_Bs_x_AaBs.nS1e PARAM */);
  if(tmp671 < 0.0 && tmp672 != 0.0)
  {
    tmp674 = modf(tmp672, &tmp675);
    
    if(tmp674 > 0.5)
    {
      tmp674 -= 1.0;
      tmp675 += 1.0;
    }
    else if(tmp674 < -0.5)
    {
      tmp674 += 1.0;
      tmp675 -= 1.0;
    }
    
    if(fabs(tmp674) < 1e-10)
      tmp673 = pow(tmp671, tmp675);
    else
    {
      tmp677 = modf(1.0/tmp672, &tmp676);
      if(tmp677 > 0.5)
      {
        tmp677 -= 1.0;
        tmp676 += 1.0;
      }
      else if(tmp677 < -0.5)
      {
        tmp677 += 1.0;
        tmp676 -= 1.0;
      }
      if(fabs(tmp677) < 1e-10 && ((unsigned long)tmp676 & 1))
      {
        tmp673 = -pow(-tmp671, tmp674)*pow(tmp671, tmp675);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp671, tmp672);
      }
    }
  }
  else
  {
    tmp673 = pow(tmp671, tmp672);
  }
  if(isnan(tmp673) || isinf(tmp673))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp671, tmp672);
  }tmp678 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */);
  tmp679 = (data->simulationInfo->realParameter[76] /* R_Aa_Bs_x_AaBs.nS2e PARAM */);
  if(tmp678 < 0.0 && tmp679 != 0.0)
  {
    tmp681 = modf(tmp679, &tmp682);
    
    if(tmp681 > 0.5)
    {
      tmp681 -= 1.0;
      tmp682 += 1.0;
    }
    else if(tmp681 < -0.5)
    {
      tmp681 += 1.0;
      tmp682 -= 1.0;
    }
    
    if(fabs(tmp681) < 1e-10)
      tmp680 = pow(tmp678, tmp682);
    else
    {
      tmp684 = modf(1.0/tmp679, &tmp683);
      if(tmp684 > 0.5)
      {
        tmp684 -= 1.0;
        tmp683 += 1.0;
      }
      else if(tmp684 < -0.5)
      {
        tmp684 += 1.0;
        tmp683 -= 1.0;
      }
      if(fabs(tmp684) < 1e-10 && ((unsigned long)tmp683 & 1))
      {
        tmp680 = -pow(-tmp678, tmp681)*pow(tmp678, tmp682);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp678, tmp679);
      }
    }
  }
  else
  {
    tmp680 = pow(tmp678, tmp679);
  }
  if(isnan(tmp680) || isinf(tmp680))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp678, tmp679);
  }tmp685 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */);
  tmp686 = (data->simulationInfo->realParameter[74] /* R_Aa_Bs_x_AaBs.nP1e PARAM */);
  if(tmp685 < 0.0 && tmp686 != 0.0)
  {
    tmp688 = modf(tmp686, &tmp689);
    
    if(tmp688 > 0.5)
    {
      tmp688 -= 1.0;
      tmp689 += 1.0;
    }
    else if(tmp688 < -0.5)
    {
      tmp688 += 1.0;
      tmp689 -= 1.0;
    }
    
    if(fabs(tmp688) < 1e-10)
      tmp687 = pow(tmp685, tmp689);
    else
    {
      tmp691 = modf(1.0/tmp686, &tmp690);
      if(tmp691 > 0.5)
      {
        tmp691 -= 1.0;
        tmp690 += 1.0;
      }
      else if(tmp691 < -0.5)
      {
        tmp691 += 1.0;
        tmp690 -= 1.0;
      }
      if(fabs(tmp691) < 1e-10 && ((unsigned long)tmp690 & 1))
      {
        tmp687 = -pow(-tmp685, tmp688)*pow(tmp685, tmp689);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp685, tmp686);
      }
    }
  }
  else
  {
    tmp687 = pow(tmp685, tmp686);
  }
  if(isnan(tmp687) || isinf(tmp687))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp685, tmp686);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* R_Aa_Bs_x_AaBs.rr variable */) = ((data->simulationInfo->realParameter[72] /* R_Aa_Bs_x_AaBs.k1 PARAM */)) * ((tmp673) * ((tmp680) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[73] /* R_Aa_Bs_x_AaBs.k2 PARAM */)) * ((tmp687) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 398
type: SIMPLE_ASSIGN
R_Aa_As_x_AaAs.rr = R_Aa_As_x_AaAs.k1 * As.c ^ R_Aa_As_x_AaAs.nS1e * Aa.c ^ R_Aa_As_x_AaAs.nS2e * V - R_Aa_As_x_AaAs.k2 * AaAs.c ^ R_Aa_As_x_AaAs.nP1e * V
*/
void rPCR_03_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
  modelica_real tmp692;
  modelica_real tmp693;
  modelica_real tmp694;
  modelica_real tmp695;
  modelica_real tmp696;
  modelica_real tmp697;
  modelica_real tmp698;
  modelica_real tmp699;
  modelica_real tmp700;
  modelica_real tmp701;
  modelica_real tmp702;
  modelica_real tmp703;
  modelica_real tmp704;
  modelica_real tmp705;
  modelica_real tmp706;
  modelica_real tmp707;
  modelica_real tmp708;
  modelica_real tmp709;
  modelica_real tmp710;
  modelica_real tmp711;
  modelica_real tmp712;
  tmp692 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */);
  tmp693 = (data->simulationInfo->realParameter[70] /* R_Aa_As_x_AaAs.nS1e PARAM */);
  if(tmp692 < 0.0 && tmp693 != 0.0)
  {
    tmp695 = modf(tmp693, &tmp696);
    
    if(tmp695 > 0.5)
    {
      tmp695 -= 1.0;
      tmp696 += 1.0;
    }
    else if(tmp695 < -0.5)
    {
      tmp695 += 1.0;
      tmp696 -= 1.0;
    }
    
    if(fabs(tmp695) < 1e-10)
      tmp694 = pow(tmp692, tmp696);
    else
    {
      tmp698 = modf(1.0/tmp693, &tmp697);
      if(tmp698 > 0.5)
      {
        tmp698 -= 1.0;
        tmp697 += 1.0;
      }
      else if(tmp698 < -0.5)
      {
        tmp698 += 1.0;
        tmp697 -= 1.0;
      }
      if(fabs(tmp698) < 1e-10 && ((unsigned long)tmp697 & 1))
      {
        tmp694 = -pow(-tmp692, tmp695)*pow(tmp692, tmp696);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp692, tmp693);
      }
    }
  }
  else
  {
    tmp694 = pow(tmp692, tmp693);
  }
  if(isnan(tmp694) || isinf(tmp694))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp692, tmp693);
  }tmp699 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */);
  tmp700 = (data->simulationInfo->realParameter[71] /* R_Aa_As_x_AaAs.nS2e PARAM */);
  if(tmp699 < 0.0 && tmp700 != 0.0)
  {
    tmp702 = modf(tmp700, &tmp703);
    
    if(tmp702 > 0.5)
    {
      tmp702 -= 1.0;
      tmp703 += 1.0;
    }
    else if(tmp702 < -0.5)
    {
      tmp702 += 1.0;
      tmp703 -= 1.0;
    }
    
    if(fabs(tmp702) < 1e-10)
      tmp701 = pow(tmp699, tmp703);
    else
    {
      tmp705 = modf(1.0/tmp700, &tmp704);
      if(tmp705 > 0.5)
      {
        tmp705 -= 1.0;
        tmp704 += 1.0;
      }
      else if(tmp705 < -0.5)
      {
        tmp705 += 1.0;
        tmp704 -= 1.0;
      }
      if(fabs(tmp705) < 1e-10 && ((unsigned long)tmp704 & 1))
      {
        tmp701 = -pow(-tmp699, tmp702)*pow(tmp699, tmp703);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp699, tmp700);
      }
    }
  }
  else
  {
    tmp701 = pow(tmp699, tmp700);
  }
  if(isnan(tmp701) || isinf(tmp701))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp699, tmp700);
  }tmp706 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */);
  tmp707 = (data->simulationInfo->realParameter[69] /* R_Aa_As_x_AaAs.nP1e PARAM */);
  if(tmp706 < 0.0 && tmp707 != 0.0)
  {
    tmp709 = modf(tmp707, &tmp710);
    
    if(tmp709 > 0.5)
    {
      tmp709 -= 1.0;
      tmp710 += 1.0;
    }
    else if(tmp709 < -0.5)
    {
      tmp709 += 1.0;
      tmp710 -= 1.0;
    }
    
    if(fabs(tmp709) < 1e-10)
      tmp708 = pow(tmp706, tmp710);
    else
    {
      tmp712 = modf(1.0/tmp707, &tmp711);
      if(tmp712 > 0.5)
      {
        tmp712 -= 1.0;
        tmp711 += 1.0;
      }
      else if(tmp712 < -0.5)
      {
        tmp712 += 1.0;
        tmp711 -= 1.0;
      }
      if(fabs(tmp712) < 1e-10 && ((unsigned long)tmp711 & 1))
      {
        tmp708 = -pow(-tmp706, tmp709)*pow(tmp706, tmp710);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp706, tmp707);
      }
    }
  }
  else
  {
    tmp708 = pow(tmp706, tmp707);
  }
  if(isnan(tmp708) || isinf(tmp708))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp706, tmp707);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* R_Aa_As_x_AaAs.rr variable */) = ((data->simulationInfo->realParameter[67] /* R_Aa_As_x_AaAs.k1 PARAM */)) * ((tmp694) * ((tmp701) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[68] /* R_Aa_As_x_AaAs.k2 PARAM */)) * ((tmp708) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 399
type: SIMPLE_ASSIGN
R_Ba_Bs_x_BaBs.rr = R_Ba_Bs_x_BaBs.k1 * Ba.c ^ R_Ba_Bs_x_BaBs.nS1e * Bs.c ^ R_Ba_Bs_x_BaBs.nS2e * V - R_Ba_Bs_x_BaBs.k2 * BaBs.c ^ R_Ba_Bs_x_BaBs.nP1e * V
*/
void rPCR_03_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
  modelica_real tmp713;
  modelica_real tmp714;
  modelica_real tmp715;
  modelica_real tmp716;
  modelica_real tmp717;
  modelica_real tmp718;
  modelica_real tmp719;
  modelica_real tmp720;
  modelica_real tmp721;
  modelica_real tmp722;
  modelica_real tmp723;
  modelica_real tmp724;
  modelica_real tmp725;
  modelica_real tmp726;
  modelica_real tmp727;
  modelica_real tmp728;
  modelica_real tmp729;
  modelica_real tmp730;
  modelica_real tmp731;
  modelica_real tmp732;
  modelica_real tmp733;
  tmp713 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */);
  tmp714 = (data->simulationInfo->realParameter[155] /* R_Ba_Bs_x_BaBs.nS1e PARAM */);
  if(tmp713 < 0.0 && tmp714 != 0.0)
  {
    tmp716 = modf(tmp714, &tmp717);
    
    if(tmp716 > 0.5)
    {
      tmp716 -= 1.0;
      tmp717 += 1.0;
    }
    else if(tmp716 < -0.5)
    {
      tmp716 += 1.0;
      tmp717 -= 1.0;
    }
    
    if(fabs(tmp716) < 1e-10)
      tmp715 = pow(tmp713, tmp717);
    else
    {
      tmp719 = modf(1.0/tmp714, &tmp718);
      if(tmp719 > 0.5)
      {
        tmp719 -= 1.0;
        tmp718 += 1.0;
      }
      else if(tmp719 < -0.5)
      {
        tmp719 += 1.0;
        tmp718 -= 1.0;
      }
      if(fabs(tmp719) < 1e-10 && ((unsigned long)tmp718 & 1))
      {
        tmp715 = -pow(-tmp713, tmp716)*pow(tmp713, tmp717);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp713, tmp714);
      }
    }
  }
  else
  {
    tmp715 = pow(tmp713, tmp714);
  }
  if(isnan(tmp715) || isinf(tmp715))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp713, tmp714);
  }tmp720 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */);
  tmp721 = (data->simulationInfo->realParameter[156] /* R_Ba_Bs_x_BaBs.nS2e PARAM */);
  if(tmp720 < 0.0 && tmp721 != 0.0)
  {
    tmp723 = modf(tmp721, &tmp724);
    
    if(tmp723 > 0.5)
    {
      tmp723 -= 1.0;
      tmp724 += 1.0;
    }
    else if(tmp723 < -0.5)
    {
      tmp723 += 1.0;
      tmp724 -= 1.0;
    }
    
    if(fabs(tmp723) < 1e-10)
      tmp722 = pow(tmp720, tmp724);
    else
    {
      tmp726 = modf(1.0/tmp721, &tmp725);
      if(tmp726 > 0.5)
      {
        tmp726 -= 1.0;
        tmp725 += 1.0;
      }
      else if(tmp726 < -0.5)
      {
        tmp726 += 1.0;
        tmp725 -= 1.0;
      }
      if(fabs(tmp726) < 1e-10 && ((unsigned long)tmp725 & 1))
      {
        tmp722 = -pow(-tmp720, tmp723)*pow(tmp720, tmp724);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp720, tmp721);
      }
    }
  }
  else
  {
    tmp722 = pow(tmp720, tmp721);
  }
  if(isnan(tmp722) || isinf(tmp722))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp720, tmp721);
  }tmp727 = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */);
  tmp728 = (data->simulationInfo->realParameter[154] /* R_Ba_Bs_x_BaBs.nP1e PARAM */);
  if(tmp727 < 0.0 && tmp728 != 0.0)
  {
    tmp730 = modf(tmp728, &tmp731);
    
    if(tmp730 > 0.5)
    {
      tmp730 -= 1.0;
      tmp731 += 1.0;
    }
    else if(tmp730 < -0.5)
    {
      tmp730 += 1.0;
      tmp731 -= 1.0;
    }
    
    if(fabs(tmp730) < 1e-10)
      tmp729 = pow(tmp727, tmp731);
    else
    {
      tmp733 = modf(1.0/tmp728, &tmp732);
      if(tmp733 > 0.5)
      {
        tmp733 -= 1.0;
        tmp732 += 1.0;
      }
      else if(tmp733 < -0.5)
      {
        tmp733 += 1.0;
        tmp732 -= 1.0;
      }
      if(fabs(tmp733) < 1e-10 && ((unsigned long)tmp732 & 1))
      {
        tmp729 = -pow(-tmp727, tmp730)*pow(tmp727, tmp731);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp727, tmp728);
      }
    }
  }
  else
  {
    tmp729 = pow(tmp727, tmp728);
  }
  if(isnan(tmp729) || isinf(tmp729))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp727, tmp728);
  }
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[247]] /* R_Ba_Bs_x_BaBs.rr variable */) = ((data->simulationInfo->realParameter[152] /* R_Ba_Bs_x_BaBs.k1 PARAM */)) * ((tmp715) * ((tmp722) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */)))) - (((data->simulationInfo->realParameter[153] /* R_Ba_Bs_x_BaBs.k2 PARAM */)) * ((tmp729) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */))));
  TRACE_POP
}
/*
equation index: 400
type: SIMPLE_ASSIGN
signalB.n = signalB.c * V
*/
void rPCR_03_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[321]] /* signalB.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 401
type: SIMPLE_ASSIGN
signalA.n = signalA.c * V
*/
void rPCR_03_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[319]] /* signalA.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 402
type: SIMPLE_ASSIGN
$DER.AaBsPoly.c = (R_AaBs_Poly_x_AaBsPoly.rr - AaBsPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[44]] /* der(AaBsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[159]] /* R_AaBs_Poly_x_AaBsPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 403
type: SIMPLE_ASSIGN
AaBsPoly.n = AaBsPoly.c * V
*/
void rPCR_03_eqFunction_403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,403};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* AaBsPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 404
type: SIMPLE_ASSIGN
$DER.AsBaPoly.c = (R_AsBa_Poly_x_AsBaPoly.rr - AsBaPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[52]] /* der(AsBaPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* R_AsBa_Poly_x_AsBaPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 405
type: SIMPLE_ASSIGN
AsBaPoly.n = AsBaPoly.c * V
*/
void rPCR_03_eqFunction_405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,405};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* AsBaPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 406
type: SIMPLE_ASSIGN
BsPrsPoly.n = BsPrsPoly.c * V
*/
void rPCR_03_eqFunction_406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,406};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[138]] /* BsPrsPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 407
type: SIMPLE_ASSIGN
BsPrsPBPoly.n = BsPrsPBPoly.c * V
*/
void rPCR_03_eqFunction_407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,407};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[136]] /* BsPrsPBPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 408
type: SIMPLE_ASSIGN
BaPraPoly.n = BaPraPoly.c * V
*/
void rPCR_03_eqFunction_408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,408};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[126]] /* BaPraPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 409
type: SIMPLE_ASSIGN
AsPrsPoly.n = AsPrsPoly.c * V
*/
void rPCR_03_eqFunction_409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,409};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* AsPrsPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 410
type: SIMPLE_ASSIGN
AsPrsPAPoly.n = AsPrsPAPoly.c * V
*/
void rPCR_03_eqFunction_410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,410};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* AsPrsPAPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 411
type: SIMPLE_ASSIGN
AaPraPoly.n = AaPraPoly.c * V
*/
void rPCR_03_eqFunction_411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,411};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* AaPraPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 412
type: SIMPLE_ASSIGN
BsPrsPB.n = BsPrsPB.c * V
*/
void rPCR_03_eqFunction_412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,412};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[134]] /* BsPrsPB.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 413
type: SIMPLE_ASSIGN
AsPrsPA.n = AsPrsPA.c * V
*/
void rPCR_03_eqFunction_413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,413};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* AsPrsPA.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 414
type: SIMPLE_ASSIGN
AsPA.n = AsPA.c * V
*/
void rPCR_03_eqFunction_414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,414};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* AsPA.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 415
type: SIMPLE_ASSIGN
BsPB.n = BsPB.c * V
*/
void rPCR_03_eqFunction_415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,415};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[130]] /* BsPB.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 416
type: SIMPLE_ASSIGN
BsPrs.n = BsPrs.c * V
*/
void rPCR_03_eqFunction_416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,416};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* BsPrs.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 417
type: SIMPLE_ASSIGN
AsPrs.n = AsPrs.c * V
*/
void rPCR_03_eqFunction_417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,417};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* AsPrs.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 418
type: SIMPLE_ASSIGN
AaPra.n = AaPra.c * V
*/
void rPCR_03_eqFunction_418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,418};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* AaPra.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 419
type: SIMPLE_ASSIGN
BaPra.n = BaPra.c * V
*/
void rPCR_03_eqFunction_419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,419};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* BaPra.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 420
type: SIMPLE_ASSIGN
$DER.BaBsPoly.c = (R_BaBs_Poly_x_BaBsPoly.rr - BaBsPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,420};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[60]] /* der(BaBsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* R_BaBs_Poly_x_BaBsPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 421
type: SIMPLE_ASSIGN
BaBsPoly.n = BaBsPoly.c * V
*/
void rPCR_03_eqFunction_421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,421};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* BaBsPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 422
type: SIMPLE_ASSIGN
$DER.AaAsPoly.c = (R_AaAs_Poly_x_AaAsPoly.rr - AaAsPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,422};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[42]] /* der(AaAsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[155]] /* R_AaAs_Poly_x_AaAsPoly.rr variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 423
type: SIMPLE_ASSIGN
AaAsPoly.n = AaAsPoly.c * V
*/
void rPCR_03_eqFunction_423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,423};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* AaAsPoly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 424
type: SIMPLE_ASSIGN
AaAs.n = AaAs.c * V
*/
void rPCR_03_eqFunction_424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,424};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* AaAs.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 425
type: SIMPLE_ASSIGN
BaBs.n = BaBs.c * V
*/
void rPCR_03_eqFunction_425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,425};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* BaBs.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 426
type: SIMPLE_ASSIGN
AaBs.n = AaBs.c * V
*/
void rPCR_03_eqFunction_426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,426};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* AaBs.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 427
type: SIMPLE_ASSIGN
AsBa.n = AsBa.c * V
*/
void rPCR_03_eqFunction_427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,427};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* AsBa.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 428
type: SIMPLE_ASSIGN
Poly.n = Poly.c * V
*/
void rPCR_03_eqFunction_428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,428};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[146]] /* Poly.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 429
type: SIMPLE_ASSIGN
PB.n = PB.c * V
*/
void rPCR_03_eqFunction_429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,429};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[144]] /* PB.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 430
type: SIMPLE_ASSIGN
PA.n = PA.c * V
*/
void rPCR_03_eqFunction_430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,430};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[142]] /* PA.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 431
type: SIMPLE_ASSIGN
Pra.n = Pra.c * V
*/
void rPCR_03_eqFunction_431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,431};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[148]] /* Pra.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 432
type: SIMPLE_ASSIGN
Prs.n = Prs.c * V
*/
void rPCR_03_eqFunction_432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,432};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[150]] /* Prs.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 433
type: SIMPLE_ASSIGN
Ba.n = Ba.c * V
*/
void rPCR_03_eqFunction_433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,433};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* Ba.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 434
type: SIMPLE_ASSIGN
Bs.n = Bs.c * V
*/
void rPCR_03_eqFunction_434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,434};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[128]] /* Bs.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 435
type: SIMPLE_ASSIGN
Aa.n = Aa.c * V
*/
void rPCR_03_eqFunction_435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,435};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* Aa.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 436
type: SIMPLE_ASSIGN
As.n = As.c * V
*/
void rPCR_03_eqFunction_436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,436};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* As.n variable */) = ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */));
  TRACE_POP
}
/*
equation index: 437
type: SIMPLE_ASSIGN
AaPraPBPoly.rNet = R_AaPraPB_Poly_x_AaPraPBPoly.rr - iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr
*/
void rPCR_03_eqFunction_437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,437};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* AaPraPBPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* R_AaPraPB_Poly_x_AaPraPBPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[286]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr variable */);
  TRACE_POP
}
/*
equation index: 438
type: SIMPLE_ASSIGN
$DER.AaPraPBPoly.c = (AaPraPBPoly.rNet - AaPraPBPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,438};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[48]] /* der(AaPraPBPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[95]] /* AaPraPBPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 439
type: SIMPLE_ASSIGN
AaPraPB.rNet = R_AaPra_PB_x_AaPraPB.rr - (R_AaPraPB_Poly_x_AaPraPBPoly.rr - R_AaPB_Pra_x_AaPraPB.rr)
*/
void rPCR_03_eqFunction_439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,439};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* AaPraPB.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* R_AaPra_PB_x_AaPraPB.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* R_AaPraPB_Poly_x_AaPraPBPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* R_AaPB_Pra_x_AaPraPB.rr variable */));
  TRACE_POP
}
/*
equation index: 440
type: SIMPLE_ASSIGN
$DER.AaPraPB.c = (AaPraPB.rNet - AaPraPB.c * der(V)) / V
*/
void rPCR_03_eqFunction_440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,440};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[47]] /* der(AaPraPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[93]] /* AaPraPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 441
type: SIMPLE_ASSIGN
AaPB.rNet = R_Aa_PB_x_AaPB.rr - R_AaPB_Pra_x_AaPraPB.rr
*/
void rPCR_03_eqFunction_441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,441};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* AaPB.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[187]] /* R_Aa_PB_x_AaPB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* R_AaPB_Pra_x_AaPraPB.rr variable */);
  TRACE_POP
}
/*
equation index: 442
type: SIMPLE_ASSIGN
$DER.AaPB.c = (AaPB.rNet - AaPB.c * der(V)) / V
*/
void rPCR_03_eqFunction_442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,442};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[45]] /* der(AaPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[89]] /* AaPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 443
type: SIMPLE_ASSIGN
BaPraPAPoly.rNet = R_BaPraPA_Poly_x_BaPraPAPoly.rr - iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr
*/
void rPCR_03_eqFunction_443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,443};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[125]] /* BaPraPAPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[235]] /* R_BaPraPA_Poly_x_BaPraPAPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[304]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr variable */);
  TRACE_POP
}
/*
equation index: 444
type: SIMPLE_ASSIGN
$DER.BaPraPAPoly.c = (BaPraPAPoly.rNet - BaPraPAPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,444};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[64]] /* der(BaPraPAPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[125]] /* BaPraPAPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 445
type: SIMPLE_ASSIGN
BaPraPA.rNet = R_BaPra_PA_x_BaPraPA.rr - (R_BaPraPA_Poly_x_BaPraPAPoly.rr - R_BaPA_Pra_x_BaPraPA.rr)
*/
void rPCR_03_eqFunction_445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,445};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[123]] /* BaPraPA.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[239]] /* R_BaPra_PA_x_BaPraPA.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[235]] /* R_BaPraPA_Poly_x_BaPraPAPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* R_BaPA_Pra_x_BaPraPA.rr variable */));
  TRACE_POP
}
/*
equation index: 446
type: SIMPLE_ASSIGN
$DER.BaPraPA.c = (BaPraPA.rNet - BaPraPA.c * der(V)) / V
*/
void rPCR_03_eqFunction_446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,446};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[63]] /* der(BaPraPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[123]] /* BaPraPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 447
type: SIMPLE_ASSIGN
BaPA.rNet = R_Ba_PA_x_BaPA.rr - R_BaPA_Pra_x_BaPraPA.rr
*/
void rPCR_03_eqFunction_447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,447};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* BaPA.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[251]] /* R_Ba_PA_x_BaPA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* R_BaPA_Pra_x_BaPraPA.rr variable */);
  TRACE_POP
}
/*
equation index: 448
type: SIMPLE_ASSIGN
$DER.BaPA.c = (BaPA.rNet - BaPA.c * der(V)) / V
*/
void rPCR_03_eqFunction_448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,448};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[61]] /* der(BaPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[119]] /* BaPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 449
type: SIMPLE_ASSIGN
signalA.rNet = iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr + iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr
*/
void rPCR_03_eqFunction_449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,449};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[320]] /* signalA.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[304]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[295]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr variable */);
  TRACE_POP
}
/*
equation index: 450
type: SIMPLE_ASSIGN
$DER.signalA.c = (signalA.rNet - signalA.c * der(V)) / V
*/
void rPCR_03_eqFunction_450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,450};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[78]] /* der(signalA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[320]] /* signalA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 451
type: SIMPLE_ASSIGN
signalB.rNet = iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr + iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr
*/
void rPCR_03_eqFunction_451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,451};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[322]] /* signalB.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[286]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[313]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr variable */);
  TRACE_POP
}
/*
equation index: 452
type: SIMPLE_ASSIGN
$DER.signalB.c = (signalB.rNet - signalB.c * der(V)) / V
*/
void rPCR_03_eqFunction_452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,452};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[79]] /* der(signalB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[322]] /* signalB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 453
type: SIMPLE_ASSIGN
BsPrsPBPoly.rNet = R_BsPrsPB_Poly_x_BsPrsPBPoly.rr - iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr
*/
void rPCR_03_eqFunction_453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,453};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[137]] /* BsPrsPBPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[263]] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[313]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr variable */);
  TRACE_POP
}
/*
equation index: 454
type: SIMPLE_ASSIGN
$DER.BsPrsPBPoly.c = (BsPrsPBPoly.rNet - BsPrsPBPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,454};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[70]] /* der(BsPrsPBPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[137]] /* BsPrsPBPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 455
type: SIMPLE_ASSIGN
BsPrsPoly.rNet = R_BsPrs_Poly_x_BsPrsPoly.rr - iR_BsPrsPoly_x_BaBs_Poly.rr
*/
void rPCR_03_eqFunction_455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,455};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[139]] /* BsPrsPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[271]] /* R_BsPrs_Poly_x_BsPrsPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[317]] /* iR_BsPrsPoly_x_BaBs_Poly.rr variable */);
  TRACE_POP
}
/*
equation index: 456
type: SIMPLE_ASSIGN
$DER.BsPrsPoly.c = (BsPrsPoly.rNet - BsPrsPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,456};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[71]] /* der(BsPrsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[139]] /* BsPrsPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 457
type: SIMPLE_ASSIGN
BaPraPoly.rNet = R_BaPra_Poly_x_BaPraPoly.rr - iR_BaPraPoly_x_BaBs_Poly.rr
*/
void rPCR_03_eqFunction_457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,457};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[127]] /* BaPraPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* R_BaPra_Poly_x_BaPraPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[308]] /* iR_BaPraPoly_x_BaBs_Poly.rr variable */);
  TRACE_POP
}
/*
equation index: 458
type: SIMPLE_ASSIGN
$DER.BaPraPoly.c = (BaPraPoly.rNet - BaPraPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,458};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[65]] /* der(BaPraPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[127]] /* BaPraPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 459
type: SIMPLE_ASSIGN
AsPrsPAPoly.rNet = R_AsPrsPA_Poly_AsPrsPAPoly.rr - iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr
*/
void rPCR_03_eqFunction_459(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,459};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* AsPrsPAPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[203]] /* R_AsPrsPA_Poly_AsPrsPAPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[295]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr variable */);
  TRACE_POP
}
/*
equation index: 460
type: SIMPLE_ASSIGN
$DER.AsPrsPAPoly.c = (AsPrsPAPoly.rNet - AsPrsPAPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_460(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,460};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[56]] /* der(AsPrsPAPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[110]] /* AsPrsPAPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 461
type: SIMPLE_ASSIGN
AsPrsPoly.rNet = R_AsPrs_Poly_x_AsPrsPoly.rr - iR_AsPrsPoly_x_AaAs_Poly.rr
*/
void rPCR_03_eqFunction_461(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,461};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* AsPrsPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* R_AsPrs_Poly_x_AsPrsPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[299]] /* iR_AsPrsPoly_x_AaAs_Poly.rr variable */);
  TRACE_POP
}
/*
equation index: 462
type: SIMPLE_ASSIGN
$DER.AsPrsPoly.c = (AsPrsPoly.rNet - AsPrsPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_462(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,462};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[57]] /* der(AsPrsPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[112]] /* AsPrsPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 463
type: SIMPLE_ASSIGN
AaPraPoly.rNet = R_AaPra_Poly_x_AaPraPoly.rr - iR_AaPraPoly_x_AaAs_Poly.rr
*/
void rPCR_03_eqFunction_463(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,463};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* AaPraPoly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[175]] /* R_AaPra_Poly_x_AaPraPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[290]] /* iR_AaPraPoly_x_AaAs_Poly.rr variable */);
  TRACE_POP
}
/*
equation index: 464
type: SIMPLE_ASSIGN
$DER.AaPraPoly.c = (AaPraPoly.rNet - AaPraPoly.c * der(V)) / V
*/
void rPCR_03_eqFunction_464(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,464};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[49]] /* der(AaPraPoly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[97]] /* AaPraPoly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 465
type: SIMPLE_ASSIGN
AaPra.rNet = R_Aa_Pra_x_AaPra.rr - (R_AaPra_PB_x_AaPraPB.rr + R_AaPra_Poly_x_AaPraPoly.rr)
*/
void rPCR_03_eqFunction_465(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,465};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* AaPra.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* R_Aa_Pra_x_AaPra.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* R_AaPra_PB_x_AaPraPB.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[175]] /* R_AaPra_Poly_x_AaPraPoly.rr variable */));
  TRACE_POP
}
/*
equation index: 466
type: SIMPLE_ASSIGN
$DER.AaPra.c = (AaPra.rNet - AaPra.c * der(V)) / V
*/
void rPCR_03_eqFunction_466(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,466};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[46]] /* der(AaPra.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[91]] /* AaPra.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 467
type: SIMPLE_ASSIGN
BaBs.rNet = R_Ba_Bs_x_BaBs.rr - (R_BaBs_Poly_x_BaBsPoly.rr - iR_BaPraPoly_x_BaBs_Poly.rr - iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr - iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr - iR_BsPrsPoly_x_BaBs_Poly.rr)
*/
void rPCR_03_eqFunction_467(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,467};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* BaBs.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[247]] /* R_Ba_Bs_x_BaBs.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* R_BaBs_Poly_x_BaBsPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[308]] /* iR_BaPraPoly_x_BaBs_Poly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[304]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[313]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[317]] /* iR_BsPrsPoly_x_BaBs_Poly.rr variable */));
  TRACE_POP
}
/*
equation index: 468
type: SIMPLE_ASSIGN
$DER.BaBs.c = (BaBs.rNet - BaBs.c * der(V)) / V
*/
void rPCR_03_eqFunction_468(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,468};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[59]] /* der(BaBs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[116]] /* BaBs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 469
type: SIMPLE_ASSIGN
AaAs.rNet = R_Aa_As_x_AaAs.rr - (R_AaAs_Poly_x_AaAsPoly.rr - iR_AaPraPoly_x_AaAs_Poly.rr - iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr - iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr - iR_AsPrsPoly_x_AaAs_Poly.rr)
*/
void rPCR_03_eqFunction_469(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,469};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* AaAs.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* R_Aa_As_x_AaAs.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[155]] /* R_AaAs_Poly_x_AaAsPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[290]] /* iR_AaPraPoly_x_AaAs_Poly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[286]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[295]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[299]] /* iR_AsPrsPoly_x_AaAs_Poly.rr variable */));
  TRACE_POP
}
/*
equation index: 470
type: SIMPLE_ASSIGN
$DER.AaAs.c = (AaAs.rNet - AaAs.c * der(V)) / V
*/
void rPCR_03_eqFunction_470(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,470};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[41]] /* der(AaAs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[83]] /* AaAs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 471
type: SIMPLE_ASSIGN
Poly.rNet = iR_BsPrsPoly_x_BaBs_Poly.rr - (R_AaPraPB_Poly_x_AaPraPBPoly.rr + R_BaPraPA_Poly_x_BaPraPAPoly.rr + R_BsPrsPB_Poly_x_BsPrsPBPoly.rr + R_BsPrs_Poly_x_BsPrsPoly.rr + R_BaPra_Poly_x_BaPraPoly.rr + R_AsPrsPA_Poly_AsPrsPAPoly.rr + R_AsPrs_Poly_x_AsPrsPoly.rr + R_AaPra_Poly_x_AaPraPoly.rr + R_AsBa_Poly_x_AsBaPoly.rr + R_AaBs_Poly_x_AaBsPoly.rr + R_BaBs_Poly_x_BaBsPoly.rr + R_AaAs_Poly_x_AaAsPoly.rr - iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr - iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr - iR_AaPraPoly_x_AaAs_Poly.rr - iR_BaPraPoly_x_BaBs_Poly.rr - iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr - iR_AsPrsPoly_x_AaAs_Poly.rr - iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr)
*/
void rPCR_03_eqFunction_471(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,471};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* Poly.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[317]] /* iR_BsPrsPoly_x_BaBs_Poly.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[167]] /* R_AaPraPB_Poly_x_AaPraPBPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[235]] /* R_BaPraPA_Poly_x_BaPraPAPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[263]] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[271]] /* R_BsPrs_Poly_x_BsPrsPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* R_BaPra_Poly_x_BaPraPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[203]] /* R_AsPrsPA_Poly_AsPrsPAPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* R_AsPrs_Poly_x_AsPrsPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[175]] /* R_AaPra_Poly_x_AaPraPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* R_AsBa_Poly_x_AsBaPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[159]] /* R_AaBs_Poly_x_AaBsPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[227]] /* R_BaBs_Poly_x_BaBsPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[155]] /* R_AaAs_Poly_x_AaAsPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[304]] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[286]] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[290]] /* iR_AaPraPoly_x_AaAs_Poly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[308]] /* iR_BaPraPoly_x_BaBs_Poly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[295]] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[299]] /* iR_AsPrsPoly_x_AaAs_Poly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[313]] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr variable */));
  TRACE_POP
}
/*
equation index: 472
type: SIMPLE_ASSIGN
$DER.Poly.c = (Poly.rNet - Poly.c * der(V)) / V
*/
void rPCR_03_eqFunction_472(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,472};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[74]] /* der(Poly.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[147]] /* Poly.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 473
type: SIMPLE_ASSIGN
BsPrsPB.rNet = R_BsPrs_PB_x_BsPrsPB.rr - (R_BsPrsPB_Poly_x_BsPrsPBPoly.rr - R_BsPB_Prs_x_BsPrsPB.rr)
*/
void rPCR_03_eqFunction_473(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,473};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[135]] /* BsPrsPB.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[267]] /* R_BsPrs_PB_x_BsPrsPB.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[263]] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[259]] /* R_BsPB_Prs_x_BsPrsPB.rr variable */));
  TRACE_POP
}
/*
equation index: 474
type: SIMPLE_ASSIGN
$DER.BsPrsPB.c = (BsPrsPB.rNet - BsPrsPB.c * der(V)) / V
*/
void rPCR_03_eqFunction_474(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,474};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[69]] /* der(BsPrsPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[135]] /* BsPrsPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 475
type: SIMPLE_ASSIGN
PB.rNet = (-R_AaPra_PB_x_AaPraPB.rr) - R_Aa_PB_x_AaPB.rr - R_BsPrs_PB_x_BsPrsPB.rr - R_Bs_PB_x_BsPB.rr
*/
void rPCR_03_eqFunction_475(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,475};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[145]] /* PB.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[171]] /* R_AaPra_PB_x_AaPraPB.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[187]] /* R_Aa_PB_x_AaPB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[267]] /* R_BsPrs_PB_x_BsPrsPB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[275]] /* R_Bs_PB_x_BsPB.rr variable */);
  TRACE_POP
}
/*
equation index: 476
type: SIMPLE_ASSIGN
$DER.PB.c = (PB.rNet - PB.c * der(V)) / V
*/
void rPCR_03_eqFunction_476(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,476};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[73]] /* der(PB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[145]] /* PB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 477
type: SIMPLE_ASSIGN
AsPrsPA.rNet = R_AsPrs_PA_x_AsPrsPA.rr - (R_AsPrsPA_Poly_AsPrsPAPoly.rr - R_AsPA_Prs_x_AsPrsPA.rr)
*/
void rPCR_03_eqFunction_477(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,477};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* AsPrsPA.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[207]] /* R_AsPrs_PA_x_AsPrsPA.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[203]] /* R_AsPrsPA_Poly_AsPrsPAPoly.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[199]] /* R_AsPA_Prs_x_AsPrsPA.rr variable */));
  TRACE_POP
}
/*
equation index: 478
type: SIMPLE_ASSIGN
$DER.AsPrsPA.c = (AsPrsPA.rNet - AsPrsPA.c * der(V)) / V
*/
void rPCR_03_eqFunction_478(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,478};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[55]] /* der(AsPrsPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[108]] /* AsPrsPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 479
type: SIMPLE_ASSIGN
AsPrs.rNet = R_As_Prs_x_AsPrs.rr - (R_AsPrs_Poly_x_AsPrsPoly.rr + R_AsPrs_PA_x_AsPrsPA.rr)
*/
void rPCR_03_eqFunction_479(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,479};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* AsPrs.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* R_As_Prs_x_AsPrs.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[211]] /* R_AsPrs_Poly_x_AsPrsPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[207]] /* R_AsPrs_PA_x_AsPrsPA.rr variable */));
  TRACE_POP
}
/*
equation index: 480
type: SIMPLE_ASSIGN
$DER.AsPrs.c = (AsPrs.rNet - AsPrs.c * der(V)) / V
*/
void rPCR_03_eqFunction_480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,480};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[54]] /* der(AsPrs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[106]] /* AsPrs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 481
type: SIMPLE_ASSIGN
PA.rNet = (-R_BaPra_PA_x_BaPraPA.rr) - R_Ba_PA_x_BaPA.rr - R_AsPrs_PA_x_AsPrsPA.rr - R_As_PA_x_AsPA.rr
*/
void rPCR_03_eqFunction_481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,481};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[143]] /* PA.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[239]] /* R_BaPra_PA_x_BaPraPA.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[251]] /* R_Ba_PA_x_BaPA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[207]] /* R_AsPrs_PA_x_AsPrsPA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* R_As_PA_x_AsPA.rr variable */);
  TRACE_POP
}
/*
equation index: 482
type: SIMPLE_ASSIGN
$DER.PA.c = (PA.rNet - PA.c * der(V)) / V
*/
void rPCR_03_eqFunction_482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,482};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[72]] /* der(PA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[143]] /* PA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 483
type: SIMPLE_ASSIGN
BsPB.rNet = R_Bs_PB_x_BsPB.rr - R_BsPB_Prs_x_BsPrsPB.rr
*/
void rPCR_03_eqFunction_483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,483};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[131]] /* BsPB.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[275]] /* R_Bs_PB_x_BsPB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[259]] /* R_BsPB_Prs_x_BsPrsPB.rr variable */);
  TRACE_POP
}
/*
equation index: 484
type: SIMPLE_ASSIGN
$DER.BsPB.c = (BsPB.rNet - BsPB.c * der(V)) / V
*/
void rPCR_03_eqFunction_484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,484};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[67]] /* der(BsPB.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[131]] /* BsPB.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 485
type: SIMPLE_ASSIGN
AsPA.rNet = R_As_PA_x_AsPA.rr - R_AsPA_Prs_x_AsPrsPA.rr
*/
void rPCR_03_eqFunction_485(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,485};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* AsPA.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* R_As_PA_x_AsPA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[199]] /* R_AsPA_Prs_x_AsPrsPA.rr variable */);
  TRACE_POP
}
/*
equation index: 486
type: SIMPLE_ASSIGN
$DER.AsPA.c = (AsPA.rNet - AsPA.c * der(V)) / V
*/
void rPCR_03_eqFunction_486(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,486};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[53]] /* der(AsPA.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[104]] /* AsPA.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 487
type: SIMPLE_ASSIGN
BsPrs.rNet = R_Bs_Prs_x_BsPrs.rr - (R_BsPrs_Poly_x_BsPrsPoly.rr + R_BsPrs_PB_x_BsPrsPB.rr)
*/
void rPCR_03_eqFunction_487(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,487};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[133]] /* BsPrs.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[279]] /* R_Bs_Prs_x_BsPrs.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[271]] /* R_BsPrs_Poly_x_BsPrsPoly.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[267]] /* R_BsPrs_PB_x_BsPrsPB.rr variable */));
  TRACE_POP
}
/*
equation index: 488
type: SIMPLE_ASSIGN
$DER.BsPrs.c = (BsPrs.rNet - BsPrs.c * der(V)) / V
*/
void rPCR_03_eqFunction_488(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,488};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[68]] /* der(BsPrs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[133]] /* BsPrs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 489
type: SIMPLE_ASSIGN
Prs.rNet = (-R_AsPA_Prs_x_AsPrsPA.rr) - R_BsPB_Prs_x_BsPrsPB.rr - R_Bs_Prs_x_BsPrs.rr - R_As_Prs_x_AsPrs.rr
*/
void rPCR_03_eqFunction_489(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,489};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[151]] /* Prs.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[199]] /* R_AsPA_Prs_x_AsPrsPA.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[259]] /* R_BsPB_Prs_x_BsPrsPB.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[279]] /* R_Bs_Prs_x_BsPrs.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* R_As_Prs_x_AsPrs.rr variable */);
  TRACE_POP
}
/*
equation index: 490
type: SIMPLE_ASSIGN
$DER.Prs.c = (Prs.rNet - Prs.c * der(V)) / V
*/
void rPCR_03_eqFunction_490(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,490};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[76]] /* der(Prs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[151]] /* Prs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 491
type: SIMPLE_ASSIGN
Bs.rNet = (-R_Bs_PB_x_BsPB.rr) - R_Bs_Prs_x_BsPrs.rr - R_Aa_Bs_x_AaBs.rr - R_Ba_Bs_x_BaBs.rr
*/
void rPCR_03_eqFunction_491(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,491};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[129]] /* Bs.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[275]] /* R_Bs_PB_x_BsPB.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[279]] /* R_Bs_Prs_x_BsPrs.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* R_Aa_Bs_x_AaBs.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[247]] /* R_Ba_Bs_x_BaBs.rr variable */);
  TRACE_POP
}
/*
equation index: 492
type: SIMPLE_ASSIGN
$DER.Bs.c = (Bs.rNet - Bs.c * der(V)) / V
*/
void rPCR_03_eqFunction_492(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,492};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[66]] /* der(Bs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[129]] /* Bs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 493
type: SIMPLE_ASSIGN
BaPra.rNet = R_Ba_Pra_x_BaPra.rr - (R_BaPra_PA_x_BaPraPA.rr + R_BaPra_Poly_x_BaPraPoly.rr)
*/
void rPCR_03_eqFunction_493(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,493};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* BaPra.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[255]] /* R_Ba_Pra_x_BaPra.rr variable */) - ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[239]] /* R_BaPra_PA_x_BaPraPA.rr variable */) + (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[243]] /* R_BaPra_Poly_x_BaPraPoly.rr variable */));
  TRACE_POP
}
/*
equation index: 494
type: SIMPLE_ASSIGN
$DER.BaPra.c = (BaPra.rNet - BaPra.c * der(V)) / V
*/
void rPCR_03_eqFunction_494(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,494};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[62]] /* der(BaPra.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[121]] /* BaPra.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 495
type: SIMPLE_ASSIGN
Pra.rNet = (-R_AaPB_Pra_x_AaPraPB.rr) - R_BaPA_Pra_x_BaPraPA.rr - R_Aa_Pra_x_AaPra.rr - R_Ba_Pra_x_BaPra.rr
*/
void rPCR_03_eqFunction_495(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,495};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[149]] /* Pra.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[163]] /* R_AaPB_Pra_x_AaPraPB.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[231]] /* R_BaPA_Pra_x_BaPraPA.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* R_Aa_Pra_x_AaPra.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[255]] /* R_Ba_Pra_x_BaPra.rr variable */);
  TRACE_POP
}
/*
equation index: 496
type: SIMPLE_ASSIGN
$DER.Pra.c = (Pra.rNet - Pra.c * der(V)) / V
*/
void rPCR_03_eqFunction_496(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,496};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[75]] /* der(Pra.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[149]] /* Pra.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 497
type: SIMPLE_ASSIGN
AsBa.rNet = R_As_Ba_x_AsBa.rr - R_AsBa_Poly_x_AsBaPoly.rr
*/
void rPCR_03_eqFunction_497(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,497};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* AsBa.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* R_As_Ba_x_AsBa.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[195]] /* R_AsBa_Poly_x_AsBaPoly.rr variable */);
  TRACE_POP
}
/*
equation index: 498
type: SIMPLE_ASSIGN
$DER.AsBa.c = (AsBa.rNet - AsBa.c * der(V)) / V
*/
void rPCR_03_eqFunction_498(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,498};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[51]] /* der(AsBa.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[101]] /* AsBa.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 499
type: SIMPLE_ASSIGN
Ba.rNet = (-R_Ba_PA_x_BaPA.rr) - R_Ba_Pra_x_BaPra.rr - R_As_Ba_x_AsBa.rr - R_Ba_Bs_x_BaBs.rr
*/
void rPCR_03_eqFunction_499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,499};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* Ba.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[251]] /* R_Ba_PA_x_BaPA.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[255]] /* R_Ba_Pra_x_BaPra.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* R_As_Ba_x_AsBa.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[247]] /* R_Ba_Bs_x_BaBs.rr variable */);
  TRACE_POP
}
/*
equation index: 500
type: SIMPLE_ASSIGN
$DER.Ba.c = (Ba.rNet - Ba.c * der(V)) / V
*/
void rPCR_03_eqFunction_500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,500};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[58]] /* der(Ba.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[114]] /* Ba.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 501
type: SIMPLE_ASSIGN
AaBs.rNet = R_Aa_Bs_x_AaBs.rr - R_AaBs_Poly_x_AaBsPoly.rr
*/
void rPCR_03_eqFunction_501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,501};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* AaBs.rNet variable */) = (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* R_Aa_Bs_x_AaBs.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[159]] /* R_AaBs_Poly_x_AaBsPoly.rr variable */);
  TRACE_POP
}
/*
equation index: 502
type: SIMPLE_ASSIGN
$DER.AaBs.c = (AaBs.rNet - AaBs.c * der(V)) / V
*/
void rPCR_03_eqFunction_502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,502};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[43]] /* der(AaBs.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[86]] /* AaBs.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 503
type: SIMPLE_ASSIGN
Aa.rNet = (-R_Aa_PB_x_AaPB.rr) - R_Aa_Pra_x_AaPra.rr - R_Aa_Bs_x_AaBs.rr - R_Aa_As_x_AaAs.rr
*/
void rPCR_03_eqFunction_503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,503};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* Aa.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[187]] /* R_Aa_PB_x_AaPB.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[191]] /* R_Aa_Pra_x_AaPra.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[183]] /* R_Aa_Bs_x_AaBs.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* R_Aa_As_x_AaAs.rr variable */);
  TRACE_POP
}
/*
equation index: 504
type: SIMPLE_ASSIGN
$DER.Aa.c = (Aa.rNet - Aa.c * der(V)) / V
*/
void rPCR_03_eqFunction_504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,504};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[40]] /* der(Aa.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[81]] /* Aa.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 505
type: SIMPLE_ASSIGN
As.rNet = (-R_As_PA_x_AsPA.rr) - R_As_Prs_x_AsPrs.rr - R_As_Ba_x_AsBa.rr - R_Aa_As_x_AaAs.rr
*/
void rPCR_03_eqFunction_505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,505};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* As.rNet variable */) = (-(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[219]] /* R_As_PA_x_AsPA.rr variable */)) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[223]] /* R_As_Prs_x_AsPrs.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[215]] /* R_As_Ba_x_AsBa.rr variable */) - (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[179]] /* R_Aa_As_x_AaAs.rr variable */);
  TRACE_POP
}
/*
equation index: 506
type: SIMPLE_ASSIGN
$DER.As.c = (As.rNet - As.c * der(V)) / V
*/
void rPCR_03_eqFunction_506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,506};
  (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[50]] /* der(As.c) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[99]] /* As.rNet variable */) - (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */)) * ((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[77]] /* der(V) STATE_DER */))),(data->localData[0]->realVars[data->simulationInfo->realVarsIndex[37]] /* V STATE(1) */),"V",equationIndexes);
  TRACE_POP
}
/*
equation index: 507
type: SIMPLE_ASSIGN
$whenCondition2 = time > cycle_time * cycle_max
*/
void rPCR_03_eqFunction_507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,507};
  modelica_boolean tmp734;
  modelica_real tmp735;
  modelica_real tmp736;
  tmp735 = 1.0;
  tmp736 = (fabs((data->simulationInfo->realParameter[210] /* cycle_time PARAM */))) * (fabs((data->simulationInfo->realParameter[209] /* cycle_max PARAM */)));
  relationhysteresis(data, &tmp734, data->localData[0]->timeValue, ((data->simulationInfo->realParameter[210] /* cycle_time PARAM */)) * ((data->simulationInfo->realParameter[209] /* cycle_max PARAM */)), tmp735, tmp736, 2, Greater, GreaterZC);
  (data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) = tmp734;
  TRACE_POP
}
/*
equation index: 546
type: WHEN

when {$whenCondition2} then
  terminate("PCR finished")%>);
end when;
*/
void rPCR_03_eqFunction_546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,546};
  static const MMC_DEFSTRINGLIT(tmp737,12,"PCR finished");
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[1]] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
  {
    FILE_INFO info = {"/scicore/home/sinnreic/kinter/openmodelica/rPCR_03.mo",278,5,278,30,0};
    omc_terminate(info, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp737)));
  }
  TRACE_POP
}
/*
equation index: 545
type: WHEN

when {$whenCondition1} then
  reinit(cycle,  cycle + 1);
end when;
*/
void rPCR_03_eqFunction_545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,545};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* cycle DISCRETE */) = (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* cycle DISCRETE */) + ((modelica_integer) 1);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit cycle = "OMC_INT_FORMAT"", (data->localData[0]->integerVars[data->simulationInfo->integerVarsIndex[0]] /* cycle DISCRETE */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 544
type: WHEN

when {$whenCondition1} then
  reinit(Aa.c,  pre(totalAa));
end when;
*/
void rPCR_03_eqFunction_544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,544};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */) = (data->simulationInfo->realVarsPre[323] /* totalAa variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit Aa.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 543
type: WHEN

when {$whenCondition1} then
  reinit(As.c,  pre(totalAs));
end when;
*/
void rPCR_03_eqFunction_543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,543};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */) = (data->simulationInfo->realVarsPre[324] /* totalAs variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit As.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 542
type: WHEN

when {$whenCondition1} then
  reinit(Ba.c,  pre(totalBa));
end when;
*/
void rPCR_03_eqFunction_542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,542};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */) = (data->simulationInfo->realVarsPre[325] /* totalBa variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit Ba.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 541
type: WHEN

when {$whenCondition1} then
  reinit(Bs.c,  pre(totalBs));
end when;
*/
void rPCR_03_eqFunction_541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,541};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */) = (data->simulationInfo->realVarsPre[326] /* totalBs variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit Bs.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 540
type: WHEN

when {$whenCondition1} then
  reinit(Prs.c,  pre(totalPrs));
end when;
*/
void rPCR_03_eqFunction_540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,540};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */) = (data->simulationInfo->realVarsPre[328] /* totalPrs variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit Prs.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 539
type: WHEN

when {$whenCondition1} then
  reinit(Pra.c,  pre(totalPra));
end when;
*/
void rPCR_03_eqFunction_539(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,539};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */) = (data->simulationInfo->realVarsPre[327] /* totalPra variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit Pra.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 538
type: WHEN

when {$whenCondition1} then
  reinit(PA.c,  pre(dProbeA));
end when;
*/
void rPCR_03_eqFunction_538(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,538};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */) = (data->simulationInfo->realVarsPre[280] /* dProbeA variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit PA.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 537
type: WHEN

when {$whenCondition1} then
  reinit(PB.c,  pre(dProbeB));
end when;
*/
void rPCR_03_eqFunction_537(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,537};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */) = (data->simulationInfo->realVarsPre[281] /* dProbeB variable */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit PB.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 536
type: WHEN

when {$whenCondition1} then
  reinit(Poly.c,  Polymerase);
end when;
*/
void rPCR_03_eqFunction_536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,536};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */) = (data->simulationInfo->realParameter[24] /* Polymerase PARAM */);
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit Poly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 535
type: WHEN

when {$whenCondition1} then
  reinit(AaAs.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,535};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaAs.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 534
type: WHEN

when {$whenCondition1} then
  reinit(AaAsPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,534};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaAsPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 533
type: WHEN

when {$whenCondition1} then
  reinit(AsPrs.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,533};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AsPrs.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 532
type: WHEN

when {$whenCondition1} then
  reinit(AsPA.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,532};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AsPA.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 531
type: WHEN

when {$whenCondition1} then
  reinit(AsPrsPA.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,531};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AsPrsPA.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 530
type: WHEN

when {$whenCondition1} then
  reinit(AaPra.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,530};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaPra.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 529
type: WHEN

when {$whenCondition1} then
  reinit(AsPrsPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,529};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AsPrsPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 528
type: WHEN

when {$whenCondition1} then
  reinit(AsPrsPAPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,528};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AsPrsPAPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 527
type: WHEN

when {$whenCondition1} then
  reinit(AaPraPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,527};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaPraPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 526
type: WHEN

when {$whenCondition1} then
  reinit(BaBs.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,526};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BaBs.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 525
type: WHEN

when {$whenCondition1} then
  reinit(BaBsPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,525};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BaBsPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 524
type: WHEN

when {$whenCondition1} then
  reinit(BsPrs.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,524};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BsPrs.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 523
type: WHEN

when {$whenCondition1} then
  reinit(BsPB.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,523};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BsPB.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 522
type: WHEN

when {$whenCondition1} then
  reinit(BsPrsPB.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,522};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BsPrsPB.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 521
type: WHEN

when {$whenCondition1} then
  reinit(BaPra.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,521};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BaPra.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 520
type: WHEN

when {$whenCondition1} then
  reinit(BsPrsPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,520};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BsPrsPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 519
type: WHEN

when {$whenCondition1} then
  reinit(BsPrsPBPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,519};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BsPrsPBPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 518
type: WHEN

when {$whenCondition1} then
  reinit(BaPraPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,518};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BaPraPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 517
type: WHEN

when {$whenCondition1} then
  reinit(AsBa.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,517};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AsBa.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 516
type: WHEN

when {$whenCondition1} then
  reinit(AsBaPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,516};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AsBaPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 515
type: WHEN

when {$whenCondition1} then
  reinit(AaBs.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,515};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaBs.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 514
type: WHEN

when {$whenCondition1} then
  reinit(AaBsPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_514(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,514};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaBsPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 513
type: WHEN

when {$whenCondition1} then
  reinit(BaPA.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_513(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,513};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BaPA.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 512
type: WHEN

when {$whenCondition1} then
  reinit(BaPraPA.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_512(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,512};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BaPraPA.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 511
type: WHEN

when {$whenCondition1} then
  reinit(BaPraPAPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_511(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,511};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit BaPraPAPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 510
type: WHEN

when {$whenCondition1} then
  reinit(AaPB.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,510};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaPB.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 509
type: WHEN

when {$whenCondition1} then
  reinit(AaPraPB.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,509};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaPraPB.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 508
type: WHEN

when {$whenCondition1} then
  reinit(AaPraPBPoly.c,  0.0);
end when;
*/
void rPCR_03_eqFunction_508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,508};
  if(((data->localData[0]->booleanVars[data->simulationInfo->booleanVarsIndex[0]] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */) = 0.0;
    infoStreamPrint(OMC_LOG_EVENTS, 0, "reinit AaPraPBPoly.c = %g", (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */));
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int rPCR_03_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  rPCR_03_functionLocalKnownVars(data, threadData);
  rPCR_03_eqFunction_341(data, threadData);

  rPCR_03_eqFunction_342(data, threadData);

  rPCR_03_eqFunction_343(data, threadData);

  rPCR_03_eqFunction_344(data, threadData);

  rPCR_03_eqFunction_345(data, threadData);

  rPCR_03_eqFunction_346(data, threadData);

  rPCR_03_eqFunction_347(data, threadData);

  rPCR_03_eqFunction_348(data, threadData);

  rPCR_03_eqFunction_349(data, threadData);

  rPCR_03_eqFunction_350(data, threadData);

  rPCR_03_eqFunction_351(data, threadData);

  rPCR_03_eqFunction_352(data, threadData);

  rPCR_03_eqFunction_353(data, threadData);

  rPCR_03_eqFunction_354(data, threadData);

  rPCR_03_eqFunction_355(data, threadData);

  rPCR_03_eqFunction_356(data, threadData);

  rPCR_03_eqFunction_357(data, threadData);

  rPCR_03_eqFunction_358(data, threadData);

  rPCR_03_eqFunction_359(data, threadData);

  rPCR_03_eqFunction_360(data, threadData);

  rPCR_03_eqFunction_361(data, threadData);

  rPCR_03_eqFunction_362(data, threadData);

  rPCR_03_eqFunction_363(data, threadData);

  rPCR_03_eqFunction_364(data, threadData);

  rPCR_03_eqFunction_365(data, threadData);

  rPCR_03_eqFunction_366(data, threadData);

  rPCR_03_eqFunction_367(data, threadData);

  rPCR_03_eqFunction_368(data, threadData);

  rPCR_03_eqFunction_369(data, threadData);

  rPCR_03_eqFunction_370(data, threadData);

  rPCR_03_eqFunction_371(data, threadData);

  rPCR_03_eqFunction_372(data, threadData);

  rPCR_03_eqFunction_373(data, threadData);

  rPCR_03_eqFunction_374(data, threadData);

  rPCR_03_eqFunction_375(data, threadData);

  rPCR_03_eqFunction_376(data, threadData);

  rPCR_03_eqFunction_377(data, threadData);

  rPCR_03_eqFunction_378(data, threadData);

  rPCR_03_eqFunction_379(data, threadData);

  rPCR_03_eqFunction_380(data, threadData);

  rPCR_03_eqFunction_381(data, threadData);

  rPCR_03_eqFunction_382(data, threadData);

  rPCR_03_eqFunction_383(data, threadData);

  rPCR_03_eqFunction_384(data, threadData);

  rPCR_03_eqFunction_385(data, threadData);

  rPCR_03_eqFunction_386(data, threadData);

  rPCR_03_eqFunction_387(data, threadData);

  rPCR_03_eqFunction_388(data, threadData);

  rPCR_03_eqFunction_389(data, threadData);

  rPCR_03_eqFunction_390(data, threadData);

  rPCR_03_eqFunction_391(data, threadData);

  rPCR_03_eqFunction_392(data, threadData);

  rPCR_03_eqFunction_393(data, threadData);

  rPCR_03_eqFunction_394(data, threadData);

  rPCR_03_eqFunction_395(data, threadData);

  rPCR_03_eqFunction_396(data, threadData);

  rPCR_03_eqFunction_397(data, threadData);

  rPCR_03_eqFunction_398(data, threadData);

  rPCR_03_eqFunction_399(data, threadData);

  rPCR_03_eqFunction_400(data, threadData);

  rPCR_03_eqFunction_401(data, threadData);

  rPCR_03_eqFunction_402(data, threadData);

  rPCR_03_eqFunction_403(data, threadData);

  rPCR_03_eqFunction_404(data, threadData);

  rPCR_03_eqFunction_405(data, threadData);

  rPCR_03_eqFunction_406(data, threadData);

  rPCR_03_eqFunction_407(data, threadData);

  rPCR_03_eqFunction_408(data, threadData);

  rPCR_03_eqFunction_409(data, threadData);

  rPCR_03_eqFunction_410(data, threadData);

  rPCR_03_eqFunction_411(data, threadData);

  rPCR_03_eqFunction_412(data, threadData);

  rPCR_03_eqFunction_413(data, threadData);

  rPCR_03_eqFunction_414(data, threadData);

  rPCR_03_eqFunction_415(data, threadData);

  rPCR_03_eqFunction_416(data, threadData);

  rPCR_03_eqFunction_417(data, threadData);

  rPCR_03_eqFunction_418(data, threadData);

  rPCR_03_eqFunction_419(data, threadData);

  rPCR_03_eqFunction_420(data, threadData);

  rPCR_03_eqFunction_421(data, threadData);

  rPCR_03_eqFunction_422(data, threadData);

  rPCR_03_eqFunction_423(data, threadData);

  rPCR_03_eqFunction_424(data, threadData);

  rPCR_03_eqFunction_425(data, threadData);

  rPCR_03_eqFunction_426(data, threadData);

  rPCR_03_eqFunction_427(data, threadData);

  rPCR_03_eqFunction_428(data, threadData);

  rPCR_03_eqFunction_429(data, threadData);

  rPCR_03_eqFunction_430(data, threadData);

  rPCR_03_eqFunction_431(data, threadData);

  rPCR_03_eqFunction_432(data, threadData);

  rPCR_03_eqFunction_433(data, threadData);

  rPCR_03_eqFunction_434(data, threadData);

  rPCR_03_eqFunction_435(data, threadData);

  rPCR_03_eqFunction_436(data, threadData);

  rPCR_03_eqFunction_437(data, threadData);

  rPCR_03_eqFunction_438(data, threadData);

  rPCR_03_eqFunction_439(data, threadData);

  rPCR_03_eqFunction_440(data, threadData);

  rPCR_03_eqFunction_441(data, threadData);

  rPCR_03_eqFunction_442(data, threadData);

  rPCR_03_eqFunction_443(data, threadData);

  rPCR_03_eqFunction_444(data, threadData);

  rPCR_03_eqFunction_445(data, threadData);

  rPCR_03_eqFunction_446(data, threadData);

  rPCR_03_eqFunction_447(data, threadData);

  rPCR_03_eqFunction_448(data, threadData);

  rPCR_03_eqFunction_449(data, threadData);

  rPCR_03_eqFunction_450(data, threadData);

  rPCR_03_eqFunction_451(data, threadData);

  rPCR_03_eqFunction_452(data, threadData);

  rPCR_03_eqFunction_453(data, threadData);

  rPCR_03_eqFunction_454(data, threadData);

  rPCR_03_eqFunction_455(data, threadData);

  rPCR_03_eqFunction_456(data, threadData);

  rPCR_03_eqFunction_457(data, threadData);

  rPCR_03_eqFunction_458(data, threadData);

  rPCR_03_eqFunction_459(data, threadData);

  rPCR_03_eqFunction_460(data, threadData);

  rPCR_03_eqFunction_461(data, threadData);

  rPCR_03_eqFunction_462(data, threadData);

  rPCR_03_eqFunction_463(data, threadData);

  rPCR_03_eqFunction_464(data, threadData);

  rPCR_03_eqFunction_465(data, threadData);

  rPCR_03_eqFunction_466(data, threadData);

  rPCR_03_eqFunction_467(data, threadData);

  rPCR_03_eqFunction_468(data, threadData);

  rPCR_03_eqFunction_469(data, threadData);

  rPCR_03_eqFunction_470(data, threadData);

  rPCR_03_eqFunction_471(data, threadData);

  rPCR_03_eqFunction_472(data, threadData);

  rPCR_03_eqFunction_473(data, threadData);

  rPCR_03_eqFunction_474(data, threadData);

  rPCR_03_eqFunction_475(data, threadData);

  rPCR_03_eqFunction_476(data, threadData);

  rPCR_03_eqFunction_477(data, threadData);

  rPCR_03_eqFunction_478(data, threadData);

  rPCR_03_eqFunction_479(data, threadData);

  rPCR_03_eqFunction_480(data, threadData);

  rPCR_03_eqFunction_481(data, threadData);

  rPCR_03_eqFunction_482(data, threadData);

  rPCR_03_eqFunction_483(data, threadData);

  rPCR_03_eqFunction_484(data, threadData);

  rPCR_03_eqFunction_485(data, threadData);

  rPCR_03_eqFunction_486(data, threadData);

  rPCR_03_eqFunction_487(data, threadData);

  rPCR_03_eqFunction_488(data, threadData);

  rPCR_03_eqFunction_489(data, threadData);

  rPCR_03_eqFunction_490(data, threadData);

  rPCR_03_eqFunction_491(data, threadData);

  rPCR_03_eqFunction_492(data, threadData);

  rPCR_03_eqFunction_493(data, threadData);

  rPCR_03_eqFunction_494(data, threadData);

  rPCR_03_eqFunction_495(data, threadData);

  rPCR_03_eqFunction_496(data, threadData);

  rPCR_03_eqFunction_497(data, threadData);

  rPCR_03_eqFunction_498(data, threadData);

  rPCR_03_eqFunction_499(data, threadData);

  rPCR_03_eqFunction_500(data, threadData);

  rPCR_03_eqFunction_501(data, threadData);

  rPCR_03_eqFunction_502(data, threadData);

  rPCR_03_eqFunction_503(data, threadData);

  rPCR_03_eqFunction_504(data, threadData);

  rPCR_03_eqFunction_505(data, threadData);

  rPCR_03_eqFunction_506(data, threadData);

  rPCR_03_eqFunction_507(data, threadData);

  rPCR_03_eqFunction_546(data, threadData);

  rPCR_03_eqFunction_545(data, threadData);

  rPCR_03_eqFunction_544(data, threadData);

  rPCR_03_eqFunction_543(data, threadData);

  rPCR_03_eqFunction_542(data, threadData);

  rPCR_03_eqFunction_541(data, threadData);

  rPCR_03_eqFunction_540(data, threadData);

  rPCR_03_eqFunction_539(data, threadData);

  rPCR_03_eqFunction_538(data, threadData);

  rPCR_03_eqFunction_537(data, threadData);

  rPCR_03_eqFunction_536(data, threadData);

  rPCR_03_eqFunction_535(data, threadData);

  rPCR_03_eqFunction_534(data, threadData);

  rPCR_03_eqFunction_533(data, threadData);

  rPCR_03_eqFunction_532(data, threadData);

  rPCR_03_eqFunction_531(data, threadData);

  rPCR_03_eqFunction_530(data, threadData);

  rPCR_03_eqFunction_529(data, threadData);

  rPCR_03_eqFunction_528(data, threadData);

  rPCR_03_eqFunction_527(data, threadData);

  rPCR_03_eqFunction_526(data, threadData);

  rPCR_03_eqFunction_525(data, threadData);

  rPCR_03_eqFunction_524(data, threadData);

  rPCR_03_eqFunction_523(data, threadData);

  rPCR_03_eqFunction_522(data, threadData);

  rPCR_03_eqFunction_521(data, threadData);

  rPCR_03_eqFunction_520(data, threadData);

  rPCR_03_eqFunction_519(data, threadData);

  rPCR_03_eqFunction_518(data, threadData);

  rPCR_03_eqFunction_517(data, threadData);

  rPCR_03_eqFunction_516(data, threadData);

  rPCR_03_eqFunction_515(data, threadData);

  rPCR_03_eqFunction_514(data, threadData);

  rPCR_03_eqFunction_513(data, threadData);

  rPCR_03_eqFunction_512(data, threadData);

  rPCR_03_eqFunction_511(data, threadData);

  rPCR_03_eqFunction_510(data, threadData);

  rPCR_03_eqFunction_509(data, threadData);

  rPCR_03_eqFunction_508(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int rPCR_03_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

/* forwarded equations */
extern void rPCR_03_eqFunction_342(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_354(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_355(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_357(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_358(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_359(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_362(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_363(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_365(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_366(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_367(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_370(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_371(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_372(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_373(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_374(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_375(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_376(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_377(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_378(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_379(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_380(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_381(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_382(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_383(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_384(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_385(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_386(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_387(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_388(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_389(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_390(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_391(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_392(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_393(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_394(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_395(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_396(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_397(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_398(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_399(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_402(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_404(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_420(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_422(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_437(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_438(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_439(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_440(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_441(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_442(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_443(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_444(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_445(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_446(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_447(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_448(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_449(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_450(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_451(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_452(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_453(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_454(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_455(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_456(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_457(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_458(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_459(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_460(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_461(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_462(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_463(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_464(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_465(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_466(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_467(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_468(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_469(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_470(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_471(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_472(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_473(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_474(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_475(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_476(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_477(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_478(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_479(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_480(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_481(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_482(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_483(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_484(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_485(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_486(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_487(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_488(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_489(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_490(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_491(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_492(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_493(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_494(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_495(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_496(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_497(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_498(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_499(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_500(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_501(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_502(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_503(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_504(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_505(DATA* data, threadData_t *threadData);
extern void rPCR_03_eqFunction_506(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  int id;

  static void (*const eqFunctions[115])(DATA*, threadData_t*) = {
    rPCR_03_eqFunction_342,
    rPCR_03_eqFunction_354,
    rPCR_03_eqFunction_355,
    rPCR_03_eqFunction_357,
    rPCR_03_eqFunction_358,
    rPCR_03_eqFunction_359,
    rPCR_03_eqFunction_362,
    rPCR_03_eqFunction_363,
    rPCR_03_eqFunction_365,
    rPCR_03_eqFunction_366,
    rPCR_03_eqFunction_367,
    rPCR_03_eqFunction_370,
    rPCR_03_eqFunction_371,
    rPCR_03_eqFunction_372,
    rPCR_03_eqFunction_373,
    rPCR_03_eqFunction_374,
    rPCR_03_eqFunction_375,
    rPCR_03_eqFunction_376,
    rPCR_03_eqFunction_377,
    rPCR_03_eqFunction_378,
    rPCR_03_eqFunction_379,
    rPCR_03_eqFunction_380,
    rPCR_03_eqFunction_381,
    rPCR_03_eqFunction_382,
    rPCR_03_eqFunction_383,
    rPCR_03_eqFunction_384,
    rPCR_03_eqFunction_385,
    rPCR_03_eqFunction_386,
    rPCR_03_eqFunction_387,
    rPCR_03_eqFunction_388,
    rPCR_03_eqFunction_389,
    rPCR_03_eqFunction_390,
    rPCR_03_eqFunction_391,
    rPCR_03_eqFunction_392,
    rPCR_03_eqFunction_393,
    rPCR_03_eqFunction_394,
    rPCR_03_eqFunction_395,
    rPCR_03_eqFunction_396,
    rPCR_03_eqFunction_397,
    rPCR_03_eqFunction_398,
    rPCR_03_eqFunction_399,
    rPCR_03_eqFunction_402,
    rPCR_03_eqFunction_404,
    rPCR_03_eqFunction_420,
    rPCR_03_eqFunction_422,
    rPCR_03_eqFunction_437,
    rPCR_03_eqFunction_438,
    rPCR_03_eqFunction_439,
    rPCR_03_eqFunction_440,
    rPCR_03_eqFunction_441,
    rPCR_03_eqFunction_442,
    rPCR_03_eqFunction_443,
    rPCR_03_eqFunction_444,
    rPCR_03_eqFunction_445,
    rPCR_03_eqFunction_446,
    rPCR_03_eqFunction_447,
    rPCR_03_eqFunction_448,
    rPCR_03_eqFunction_449,
    rPCR_03_eqFunction_450,
    rPCR_03_eqFunction_451,
    rPCR_03_eqFunction_452,
    rPCR_03_eqFunction_453,
    rPCR_03_eqFunction_454,
    rPCR_03_eqFunction_455,
    rPCR_03_eqFunction_456,
    rPCR_03_eqFunction_457,
    rPCR_03_eqFunction_458,
    rPCR_03_eqFunction_459,
    rPCR_03_eqFunction_460,
    rPCR_03_eqFunction_461,
    rPCR_03_eqFunction_462,
    rPCR_03_eqFunction_463,
    rPCR_03_eqFunction_464,
    rPCR_03_eqFunction_465,
    rPCR_03_eqFunction_466,
    rPCR_03_eqFunction_467,
    rPCR_03_eqFunction_468,
    rPCR_03_eqFunction_469,
    rPCR_03_eqFunction_470,
    rPCR_03_eqFunction_471,
    rPCR_03_eqFunction_472,
    rPCR_03_eqFunction_473,
    rPCR_03_eqFunction_474,
    rPCR_03_eqFunction_475,
    rPCR_03_eqFunction_476,
    rPCR_03_eqFunction_477,
    rPCR_03_eqFunction_478,
    rPCR_03_eqFunction_479,
    rPCR_03_eqFunction_480,
    rPCR_03_eqFunction_481,
    rPCR_03_eqFunction_482,
    rPCR_03_eqFunction_483,
    rPCR_03_eqFunction_484,
    rPCR_03_eqFunction_485,
    rPCR_03_eqFunction_486,
    rPCR_03_eqFunction_487,
    rPCR_03_eqFunction_488,
    rPCR_03_eqFunction_489,
    rPCR_03_eqFunction_490,
    rPCR_03_eqFunction_491,
    rPCR_03_eqFunction_492,
    rPCR_03_eqFunction_493,
    rPCR_03_eqFunction_494,
    rPCR_03_eqFunction_495,
    rPCR_03_eqFunction_496,
    rPCR_03_eqFunction_497,
    rPCR_03_eqFunction_498,
    rPCR_03_eqFunction_499,
    rPCR_03_eqFunction_500,
    rPCR_03_eqFunction_501,
    rPCR_03_eqFunction_502,
    rPCR_03_eqFunction_503,
    rPCR_03_eqFunction_504,
    rPCR_03_eqFunction_505,
    rPCR_03_eqFunction_506
  };
  
  static const int eqIndices[115] = {
    342,
    354,
    355,
    357,
    358,
    359,
    362,
    363,
    365,
    366,
    367,
    370,
    371,
    372,
    373,
    374,
    375,
    376,
    377,
    378,
    379,
    380,
    381,
    382,
    383,
    384,
    385,
    386,
    387,
    388,
    389,
    390,
    391,
    392,
    393,
    394,
    395,
    396,
    397,
    398,
    399,
    402,
    404,
    420,
    422,
    437,
    438,
    439,
    440,
    441,
    442,
    443,
    444,
    445,
    446,
    447,
    448,
    449,
    450,
    451,
    452,
    453,
    454,
    455,
    456,
    457,
    458,
    459,
    460,
    461,
    462,
    463,
    464,
    465,
    466,
    467,
    468,
    469,
    470,
    471,
    472,
    473,
    474,
    475,
    476,
    477,
    478,
    479,
    480,
    481,
    482,
    483,
    484,
    485,
    486,
    487,
    488,
    489,
    490,
    491,
    492,
    493,
    494,
    495,
    496,
    497,
    498,
    499,
    500,
    501,
    502,
    503,
    504,
    505,
    506
  };
  
  for (id = 0; id < 115; id++) {
    eqFunctions[id](data, threadData);
    threadData->lastEquationSolved = eqIndices[id];
  }
}

int rPCR_03_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  rPCR_03_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

void rPCR_03_computeVarIndices(size_t* realIndex, size_t* integerIndex, size_t* booleanIndex, size_t* stringIndex)
{
  TRACE_PUSH

  size_t i_real = 0;
  size_t i_integer = 0;
  size_t i_boolean = 0;
  size_t i_string = 0;

  realIndex[0] = 0;
  integerIndex[0] = 0;
  booleanIndex[0] = 0;
  stringIndex[0] = 0;

  /* stateVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Aa.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaAs.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaAsPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaBs.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaBsPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPB.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPra.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPB.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPBPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* As.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsBa.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsBaPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPA.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrs.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPA.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPAPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Ba.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaBs.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaBsPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPA.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPra.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPA.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPAPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Bs.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPB.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrs.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPB.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPBPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPoly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* PA.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* PB.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Poly.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Pra.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Prs.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* V STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* signalA.c STATE(1) */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* signalB.c STATE(1) */
  
  /* derivativeVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Aa.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaAs.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaAsPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaBs.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaBsPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaPB.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaPra.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaPraPB.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaPraPBPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AaPraPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(As.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AsBa.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AsBaPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AsPA.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AsPrs.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AsPrsPA.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AsPrsPAPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(AsPrsPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Ba.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BaBs.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BaBsPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BaPA.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BaPra.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BaPraPA.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BaPraPAPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BaPraPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Bs.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BsPB.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BsPrs.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BsPrsPB.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BsPrsPBPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(BsPrsPoly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(PA.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(PB.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Poly.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Pra.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(Prs.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(V) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(signalA.c) STATE_DER */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* der(signalB.c) STATE_DER */
  
  /* algVars */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Aa.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Aa.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaAs.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaAs.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaAsPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaBs.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaBs.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaBsPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPB.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPB.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPra.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPra.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPB.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPB.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPBPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPBPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AaPraPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* As.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* As.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsBa.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsBa.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsBaPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPA.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPA.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrs.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrs.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPA.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPA.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPAPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPAPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* AsPrsPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Ba.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Ba.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaBs.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaBs.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaBsPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPA.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPA.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPra.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPra.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPA.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPA.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPAPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPAPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BaPraPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Bs.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Bs.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPB.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPB.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrs.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrs.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPB.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPB.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPBPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPBPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPoly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* BsPrsPoly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* FluoA variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* FluoB variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* PA.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* PA.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* PB.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* PB.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Poly.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Poly.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Pra.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Pra.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Prs.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* Prs.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaAs_Poly_x_AaAsPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaAs_Poly_x_AaAsPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaAs_Poly_x_AaAsPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaAs_Poly_x_AaAsPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaBs_Poly_x_AaBsPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaBs_Poly_x_AaBsPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaBs_Poly_x_AaBsPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaBs_Poly_x_AaBsPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPB_Pra_x_AaPraPB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPB_Pra_x_AaPraPB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPB_Pra_x_AaPraPB.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPB_Pra_x_AaPraPB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPraPB_Poly_x_AaPraPBPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPraPB_Poly_x_AaPraPBPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPraPB_Poly_x_AaPraPBPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPraPB_Poly_x_AaPraPBPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_PB_x_AaPraPB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_PB_x_AaPraPB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_PB_x_AaPraPB.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_PB_x_AaPraPB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_Poly_x_AaPraPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_Poly_x_AaPraPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_Poly_x_AaPraPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AaPra_Poly_x_AaPraPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_As_x_AaAs.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_As_x_AaAs.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_As_x_AaAs.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_As_x_AaAs.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Bs_x_AaBs.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Bs_x_AaBs.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Bs_x_AaBs.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Bs_x_AaBs.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_PB_x_AaPB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_PB_x_AaPB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_PB_x_AaPB.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_PB_x_AaPB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Pra_x_AaPra.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Pra_x_AaPra.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Pra_x_AaPra.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Aa_Pra_x_AaPra.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsBa_Poly_x_AsBaPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsBa_Poly_x_AsBaPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsBa_Poly_x_AsBaPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsBa_Poly_x_AsBaPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPA_Prs_x_AsPrsPA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPA_Prs_x_AsPrsPA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPA_Prs_x_AsPrsPA.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPA_Prs_x_AsPrsPA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrsPA_Poly_AsPrsPAPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrsPA_Poly_AsPrsPAPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrsPA_Poly_AsPrsPAPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrsPA_Poly_AsPrsPAPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_PA_x_AsPrsPA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_PA_x_AsPrsPA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_PA_x_AsPrsPA.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_PA_x_AsPrsPA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_Poly_x_AsPrsPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_Poly_x_AsPrsPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_Poly_x_AsPrsPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_AsPrs_Poly_x_AsPrsPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Ba_x_AsBa.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Ba_x_AsBa.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Ba_x_AsBa.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Ba_x_AsBa.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_PA_x_AsPA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_PA_x_AsPA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_PA_x_AsPA.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_PA_x_AsPA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Prs_x_AsPrs.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Prs_x_AsPrs.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Prs_x_AsPrs.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_As_Prs_x_AsPrs.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaBs_Poly_x_BaBsPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaBs_Poly_x_BaBsPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaBs_Poly_x_BaBsPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaBs_Poly_x_BaBsPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPA_Pra_x_BaPraPA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPA_Pra_x_BaPraPA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPA_Pra_x_BaPraPA.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPA_Pra_x_BaPraPA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPraPA_Poly_x_BaPraPAPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPraPA_Poly_x_BaPraPAPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPraPA_Poly_x_BaPraPAPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPraPA_Poly_x_BaPraPAPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_PA_x_BaPraPA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_PA_x_BaPraPA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_PA_x_BaPraPA.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_PA_x_BaPraPA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_Poly_x_BaPraPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_Poly_x_BaPraPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_Poly_x_BaPraPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BaPra_Poly_x_BaPraPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Bs_x_BaBs.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Bs_x_BaBs.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Bs_x_BaBs.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Bs_x_BaBs.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_PA_x_BaPA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_PA_x_BaPA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_PA_x_BaPA.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_PA_x_BaPA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Pra_x_BaPra.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Pra_x_BaPra.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Pra_x_BaPra.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Ba_Pra_x_BaPra.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPB_Prs_x_BsPrsPB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPB_Prs_x_BsPrsPB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPB_Prs_x_BsPrsPB.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPB_Prs_x_BsPrsPB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrsPB_Poly_x_BsPrsPBPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrsPB_Poly_x_BsPrsPBPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_PB_x_BsPrsPB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_PB_x_BsPrsPB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_PB_x_BsPrsPB.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_PB_x_BsPrsPB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_Poly_x_BsPrsPoly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_Poly_x_BsPrsPoly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_Poly_x_BsPrsPoly.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_BsPrs_Poly_x_BsPrsPoly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_PB_x_BsPB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_PB_x_BsPB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_PB_x_BsPB.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_PB_x_BsPB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_Prs_x_BsPrs.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_Prs_x_BsPrs.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_Prs_x_BsPrs.nS2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* R_Bs_Prs_x_BsPrs.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* dProbeA variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* dProbeB variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nP3 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPoly_x_AaAs_Poly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPoly_x_AaAs_Poly.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPoly_x_AaAs_Poly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AaPraPoly_x_AaAs_Poly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nP3 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPoly_x_AaAs_Poly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPoly_x_AaAs_Poly.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPoly_x_AaAs_Poly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_AsPrsPoly_x_AaAs_Poly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nP3 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPoly_x_BaBs_Poly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPoly_x_BaBs_Poly.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPoly_x_BaBs_Poly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BaPraPoly_x_BaBs_Poly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nP3 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPoly_x_BaBs_Poly.nP1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPoly_x_BaBs_Poly.nP2 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPoly_x_BaBs_Poly.nS1 variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* iR_BsPrsPoly_x_BaBs_Poly.rr variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* ratio variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* signalA.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* signalA.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* signalB.n variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* signalB.rNet variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* totalAa variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* totalAs variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* totalBa variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* totalBs variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* totalPra variable */
  realIndex[i_real+1] = realIndex[i_real] + ((modelica_integer) 1); i_real++; /* totalPrs variable */
  
  /* discreteAlgVars */
  
  /* realOptimizeConstraintsVars */
  
  /* realOptimizeFinalConstraintsVars */
  
  
  /* intAlgVars */
  integerIndex[i_integer+1] = integerIndex[i_integer] + ((modelica_integer) 1); i_integer++; /* cycle DISCRETE */
  
  /* boolAlgVars */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition1 DISCRETE */
  booleanIndex[i_boolean+1] = booleanIndex[i_boolean] + ((modelica_integer) 1); i_boolean++; /* $whenCondition2 DISCRETE */
  
  /* stringAlgVars */
  
  TRACE_POP
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "rPCR_03_12jac.h"
#include "rPCR_03_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks rPCR_03_callback = {
   (int (*)(DATA *, threadData_t *, void *)) rPCR_03_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) rPCR_03_performQSSSimulation,    /* performQSSSimulation */
   rPCR_03_updateContinuousSystem,    /* updateContinuousSystem */
   rPCR_03_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   rPCR_03_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   rPCR_03_initializeDAEmodeData,
   rPCR_03_computeVarIndices,
   rPCR_03_functionODE,
   rPCR_03_functionAlgebraics,
   rPCR_03_functionDAE,
   rPCR_03_functionLocalKnownVars,
   rPCR_03_input_function,
   rPCR_03_input_function_init,
   rPCR_03_input_function_updateStartValues,
   rPCR_03_data_function,
   rPCR_03_output_function,
   rPCR_03_setc_function,
   rPCR_03_setb_function,
   rPCR_03_function_storeDelayed,
   rPCR_03_function_storeSpatialDistribution,
   rPCR_03_function_initSpatialDistribution,
   rPCR_03_updateBoundVariableAttributes,
   rPCR_03_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   rPCR_03_functionRemovedInitialEquations,
   rPCR_03_updateBoundParameters,
   rPCR_03_checkForAsserts,
   rPCR_03_function_ZeroCrossingsEquations,
   rPCR_03_function_ZeroCrossings,
   rPCR_03_function_updateRelations,
   rPCR_03_zeroCrossingDescription,
   rPCR_03_relationDescription,
   rPCR_03_function_initSample,
   rPCR_03_INDEX_JAC_A,
   rPCR_03_INDEX_JAC_B,
   rPCR_03_INDEX_JAC_C,
   rPCR_03_INDEX_JAC_D,
   rPCR_03_INDEX_JAC_F,
   rPCR_03_INDEX_JAC_H,
   rPCR_03_initialAnalyticJacobianA,
   rPCR_03_initialAnalyticJacobianB,
   rPCR_03_initialAnalyticJacobianC,
   rPCR_03_initialAnalyticJacobianD,
   rPCR_03_initialAnalyticJacobianF,
   rPCR_03_initialAnalyticJacobianH,
   rPCR_03_functionJacA_column,
   rPCR_03_functionJacB_column,
   rPCR_03_functionJacC_column,
   rPCR_03_functionJacD_column,
   rPCR_03_functionJacF_column,
   rPCR_03_functionJacH_column,
   rPCR_03_linear_model_frame,
   rPCR_03_linear_model_datarecovery_frame,
   rPCR_03_mayer,
   rPCR_03_lagrange,
   rPCR_03_pickUpBoundsForInputsInOptimization,
   rPCR_03_setInputData,
   rPCR_03_getTimeGrid,
   rPCR_03_symbolicInlineSystem,
   rPCR_03_function_initSynchronous,
   rPCR_03_function_updateSynchronous,
   rPCR_03_function_equationsSynchronous,
   rPCR_03_inputNames,
   rPCR_03_dataReconciliationInputNames,
   rPCR_03_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "BioChem"
#define _OMC_LIT_RESOURCE_0_dir_data "/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,65,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Complex"
#define _OMC_LIT_RESOURCE_1_dir_data "/scicore/home/sinnreic/kinter/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,7,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,76,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "/scicore/home/sinnreic/kinter/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,77,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "/scicore/home/sinnreic/kinter/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,85,_OMC_LIT_RESOURCE_3_dir_data);

#define _OMC_LIT_RESOURCE_4_name_data "rPCR_03"
#define _OMC_LIT_RESOURCE_4_dir_data "/scicore/home/sinnreic/kinter/openmodelica"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_name,7,_OMC_LIT_RESOURCE_4_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir,42,_OMC_LIT_RESOURCE_4_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,10,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir)}};
void rPCR_03_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &rPCR_03_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "rPCR_03";
  data->modelData->modelFilePrefix = "rPCR_03";
  data->modelData->modelFileName = "rPCR_03.mo";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/scicore/home/sinnreic/kinter/openmodelica";
  data->modelData->modelGUID = "{1bda34a7-2c56-40f7-8ed3-7e0a1c14bb37}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "rPCR_03_init.c"
    ;
  static const char contents_info[] =
    #include "rPCR_03_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "rPCR_03_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "rPCR_03_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "rPCR_03_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 40;
  data->modelData->nVariablesRealArray = 329;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesIntegerArray = 1;
  data->modelData->nVariablesBooleanArray = 2;
  data->modelData->nVariablesStringArray = 0;
  data->modelData->nParametersReal = 247;
  data->modelData->nParametersInteger = 39;
  data->modelData->nParametersBoolean = 1;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 493;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 3;
  data->modelData->nSamples = 1;
  data->modelData->nRelations = 3;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 945;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 6;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}


#if defined(__MINGW32__) || defined(_MSC_VER)

#if !defined(_UNICODE)
#define _UNICODE
#endif
#if !defined(UNICODE)
#define UNICODE
#endif

#include <windows.h>
char** omc_fixWindowsArgv(int argc, wchar_t **wargv)
{
  char** newargv;
  /* Support for non-ASCII characters
  * Read the unicode command line arguments and translate it to char*
  */
  newargv = (char**)malloc(argc*sizeof(char*));
  for (int i = 0; i < argc; i++) {
    newargv[i] = omc_wchar_to_multibyte_str(wargv[i]);
  }
  return newargv;
}

#define OMC_MAIN wmain
#define OMC_CHAR wchar_t
#define OMC_EXPORT __declspec(dllexport) extern

#else
#define omc_fixWindowsArgv(N, A) (A)
#define OMC_MAIN main
#define OMC_CHAR char
#define OMC_EXPORT extern
#endif

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
#if defined(OMC_DLL_MAIN_DEFINE)
OMC_EXPORT int omcDllMain(int argc, OMC_CHAR **argv)
#else
int OMC_MAIN(int argc, OMC_CHAR** argv)
#endif
{
  char** newargv = omc_fixWindowsArgv(argc, argv);
  /*
    Set the error functions to be used for simulation.
    The default value for them is 'functions' version. Change it here to 'simulation' versions
  */
  omc_assert = omc_assert_simulation;
  omc_assert_withEquationIndexes = omc_assert_simulation_withEquationIndexes;

  omc_assert_warning_withEquationIndexes = omc_assert_warning_simulation_withEquationIndexes;
  omc_assert_warning = omc_assert_warning_simulation;
  omc_terminate = omc_terminate_simulation;
  omc_throw = omc_throw_simulation;

  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    rPCR_03_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, newargv, &data, threadData);
    if(res == 0) {
      res = _main_SimulationRuntime(argc, newargv, &data, threadData);
    }
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  return res;
}

#ifdef __cplusplus
}
#endif


