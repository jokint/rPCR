/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "rPCR_03_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 547
type: SIMPLE_ASSIGN
$START.signalB.c = Signal_B
*/
static void rPCR_03_eqFunction_547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,547};
  (data->modelData->realVarsData[39] /* signalB.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[203] /* Signal_B PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */) = (data->modelData->realVarsData[39] /* signalB.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[39].info /* signalB.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 548
type: SIMPLE_ASSIGN
$START.signalA.c = Signal_A
*/
static void rPCR_03_eqFunction_548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,548};
  (data->modelData->realVarsData[38] /* signalA.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[202] /* Signal_A PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */) = (data->modelData->realVarsData[38] /* signalA.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[38].info /* signalA.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 549
type: SIMPLE_ASSIGN
$START.Poly.c = Polymerase
*/
static void rPCR_03_eqFunction_549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  (data->modelData->realVarsData[34] /* Poly.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[24] /* Polymerase PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */) = (data->modelData->realVarsData[34] /* Poly.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[34].info /* Poly.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 550
type: SIMPLE_ASSIGN
$START.PB.c = ProbeB
*/
static void rPCR_03_eqFunction_550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  (data->modelData->realVarsData[33] /* PB.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[32] /* ProbeB PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */) = (data->modelData->realVarsData[33] /* PB.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[33].info /* PB.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 551
type: SIMPLE_ASSIGN
$START.PA.c = ProbeA
*/
static void rPCR_03_eqFunction_551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  (data->modelData->realVarsData[32] /* PA.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[29] /* ProbeA PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */) = (data->modelData->realVarsData[32] /* PA.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[32].info /* PA.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 552
type: SIMPLE_ASSIGN
$START.Pra.c = antiPrimer
*/
static void rPCR_03_eqFunction_552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  (data->modelData->realVarsData[35] /* Pra.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[206] /* antiPrimer PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */) = (data->modelData->realVarsData[35] /* Pra.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[35].info /* Pra.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 553
type: SIMPLE_ASSIGN
$START.Prs.c = sensePrimer
*/
static void rPCR_03_eqFunction_553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
  (data->modelData->realVarsData[36] /* Prs.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[243] /* sensePrimer PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */) = (data->modelData->realVarsData[36] /* Prs.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[36].info /* Prs.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 554
type: SIMPLE_ASSIGN
$START.Ba.c = antiB
*/
static void rPCR_03_eqFunction_554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  (data->modelData->realVarsData[18] /* Ba.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[205] /* antiB PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */) = (data->modelData->realVarsData[18] /* Ba.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[18].info /* Ba.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 555
type: SIMPLE_ASSIGN
$START.Bs.c = senseB
*/
static void rPCR_03_eqFunction_555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
  (data->modelData->realVarsData[26] /* Bs.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[242] /* senseB PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */) = (data->modelData->realVarsData[26] /* Bs.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[26].info /* Bs.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 556
type: SIMPLE_ASSIGN
$START.Aa.c = antiA
*/
static void rPCR_03_eqFunction_556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  (data->modelData->realVarsData[0] /* Aa.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[204] /* antiA PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */) = (data->modelData->realVarsData[0] /* Aa.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[0].info /* Aa.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */));
  TRACE_POP
}

/*
equation index: 557
type: SIMPLE_ASSIGN
$START.As.c = senseA
*/
static void rPCR_03_eqFunction_557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
  (data->modelData->realVarsData[10] /* As.c STATE(1) */).attribute .start = (data->simulationInfo->realParameter[241] /* senseA PARAM */);
    (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */) = (data->modelData->realVarsData[10] /* As.c STATE(1) */).attribute .start;
    infoStreamPrint(OMC_LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[10].info /* As.c */.name, (modelica_real) (data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
int rPCR_03_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating min-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* max ******************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating max-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* nominal **************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating nominal-values");
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(OMC_LOG_INIT, 1, "updating primary start-values");
  rPCR_03_eqFunction_547(data, threadData);

  rPCR_03_eqFunction_548(data, threadData);

  rPCR_03_eqFunction_549(data, threadData);

  rPCR_03_eqFunction_550(data, threadData);

  rPCR_03_eqFunction_551(data, threadData);

  rPCR_03_eqFunction_552(data, threadData);

  rPCR_03_eqFunction_553(data, threadData);

  rPCR_03_eqFunction_554(data, threadData);

  rPCR_03_eqFunction_555(data, threadData);

  rPCR_03_eqFunction_556(data, threadData);

  rPCR_03_eqFunction_557(data, threadData);
  if (OMC_ACTIVE_STREAM(OMC_LOG_INIT)) messageClose(OMC_LOG_INIT);
  
  TRACE_POP
  return 0;
}

void rPCR_03_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 558
type: SIMPLE_ASSIGN
R_AaPra_PB_x_AaPraPB.k2 = Aa_PB_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  (data->simulationInfo->realParameter[58] /* R_AaPra_PB_x_AaPraPB.k2 PARAM */) = (data->simulationInfo->realParameter[1] /* Aa_PB_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 559
type: SIMPLE_ASSIGN
R_AaPra_PB_x_AaPraPB.k1 = Aa_PB_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
  (data->simulationInfo->realParameter[57] /* R_AaPra_PB_x_AaPraPB.k1 PARAM */) = (data->simulationInfo->realParameter[0] /* Aa_PB_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 560
type: SIMPLE_ASSIGN
iR_AaPraPBPoly_x_AaAs_Poly_SignalB.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  (data->simulationInfo->realParameter[217] /* iR_AaPraPBPoly_x_AaAs_Poly_SignalB.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 562
type: SIMPLE_ASSIGN
R_AaPraPB_Poly_x_AaPraPBPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  (data->simulationInfo->realParameter[53] /* R_AaPraPB_Poly_x_AaPraPBPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 563
type: SIMPLE_ASSIGN
R_AaPraPB_Poly_x_AaPraPBPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
  (data->simulationInfo->realParameter[52] /* R_AaPraPB_Poly_x_AaPraPBPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 564
type: SIMPLE_ASSIGN
Pra_k2 = Primer_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  (data->simulationInfo->realParameter[26] /* Pra_k2 PARAM */) = (data->simulationInfo->realParameter[28] /* Primer_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 565
type: SIMPLE_ASSIGN
Aa_Pra_k2 = Pra_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
  (data->simulationInfo->realParameter[3] /* Aa_Pra_k2 PARAM */) = (data->simulationInfo->realParameter[26] /* Pra_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 566
type: SIMPLE_ASSIGN
R_AaPB_Pra_x_AaPraPB.k2 = Aa_Pra_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
  (data->simulationInfo->realParameter[48] /* R_AaPB_Pra_x_AaPraPB.k2 PARAM */) = (data->simulationInfo->realParameter[3] /* Aa_Pra_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 567
type: SIMPLE_ASSIGN
Pra_k1 = Primer_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,567};
  (data->simulationInfo->realParameter[25] /* Pra_k1 PARAM */) = (data->simulationInfo->realParameter[27] /* Primer_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 568
type: SIMPLE_ASSIGN
Aa_Pra_k1 = Pra_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_568(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,568};
  (data->simulationInfo->realParameter[2] /* Aa_Pra_k1 PARAM */) = (data->simulationInfo->realParameter[25] /* Pra_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 569
type: SIMPLE_ASSIGN
R_AaPB_Pra_x_AaPraPB.k1 = Aa_Pra_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_569(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,569};
  (data->simulationInfo->realParameter[47] /* R_AaPB_Pra_x_AaPraPB.k1 PARAM */) = (data->simulationInfo->realParameter[2] /* Aa_Pra_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 570
type: SIMPLE_ASSIGN
R_Aa_PB_x_AaPB.k2 = Aa_PB_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_570(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,570};
  (data->simulationInfo->realParameter[78] /* R_Aa_PB_x_AaPB.k2 PARAM */) = (data->simulationInfo->realParameter[1] /* Aa_PB_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 571
type: SIMPLE_ASSIGN
R_Aa_PB_x_AaPB.k1 = Aa_PB_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_571(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,571};
  (data->simulationInfo->realParameter[77] /* R_Aa_PB_x_AaPB.k1 PARAM */) = (data->simulationInfo->realParameter[0] /* Aa_PB_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 574
type: SIMPLE_ASSIGN
R_BaPra_PA_x_BaPraPA.k2 = Ba_PA_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,574};
  (data->simulationInfo->realParameter[143] /* R_BaPra_PA_x_BaPraPA.k2 PARAM */) = (data->simulationInfo->realParameter[13] /* Ba_PA_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 575
type: SIMPLE_ASSIGN
R_BaPra_PA_x_BaPraPA.k1 = Ba_PA_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,575};
  (data->simulationInfo->realParameter[142] /* R_BaPra_PA_x_BaPraPA.k1 PARAM */) = (data->simulationInfo->realParameter[12] /* Ba_PA_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 576
type: SIMPLE_ASSIGN
iR_BaPraPAPoly_x_BaBs_Poly_SignalA.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_576(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,576};
  (data->simulationInfo->realParameter[225] /* iR_BaPraPAPoly_x_BaBs_Poly_SignalA.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 578
type: SIMPLE_ASSIGN
R_BaPraPA_Poly_x_BaPraPAPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_578(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,578};
  (data->simulationInfo->realParameter[138] /* R_BaPraPA_Poly_x_BaPraPAPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 579
type: SIMPLE_ASSIGN
R_BaPraPA_Poly_x_BaPraPAPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_579(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,579};
  (data->simulationInfo->realParameter[137] /* R_BaPraPA_Poly_x_BaPraPAPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 580
type: SIMPLE_ASSIGN
Ba_Pra_k2 = Pra_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_580(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,580};
  (data->simulationInfo->realParameter[15] /* Ba_Pra_k2 PARAM */) = (data->simulationInfo->realParameter[26] /* Pra_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 581
type: SIMPLE_ASSIGN
R_BaPA_Pra_x_BaPraPA.k2 = Ba_Pra_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_581(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,581};
  (data->simulationInfo->realParameter[133] /* R_BaPA_Pra_x_BaPraPA.k2 PARAM */) = (data->simulationInfo->realParameter[15] /* Ba_Pra_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 582
type: SIMPLE_ASSIGN
Ba_Pra_k1 = Pra_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_582(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,582};
  (data->simulationInfo->realParameter[14] /* Ba_Pra_k1 PARAM */) = (data->simulationInfo->realParameter[25] /* Pra_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 583
type: SIMPLE_ASSIGN
R_BaPA_Pra_x_BaPraPA.k1 = Ba_Pra_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_583(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,583};
  (data->simulationInfo->realParameter[132] /* R_BaPA_Pra_x_BaPraPA.k1 PARAM */) = (data->simulationInfo->realParameter[14] /* Ba_Pra_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 584
type: SIMPLE_ASSIGN
R_Ba_PA_x_BaPA.k2 = Ba_PA_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,584};
  (data->simulationInfo->realParameter[158] /* R_Ba_PA_x_BaPA.k2 PARAM */) = (data->simulationInfo->realParameter[13] /* Ba_PA_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 585
type: SIMPLE_ASSIGN
R_Ba_PA_x_BaPA.k1 = Ba_PA_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,585};
  (data->simulationInfo->realParameter[157] /* R_Ba_PA_x_BaPA.k1 PARAM */) = (data->simulationInfo->realParameter[12] /* Ba_PA_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 588
type: SIMPLE_ASSIGN
Bs_Prs_PBxPB_k2 = ProbeB_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,588};
  (data->simulationInfo->realParameter[19] /* Bs_Prs_PBxPB_k2 PARAM */) = (data->simulationInfo->realParameter[34] /* ProbeB_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 589
type: SIMPLE_ASSIGN
Bs_Prs_PBxPB_k1 = ProbeB_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,589};
  (data->simulationInfo->realParameter[18] /* Bs_Prs_PBxPB_k1 PARAM */) = (data->simulationInfo->realParameter[33] /* ProbeB_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 590
type: SIMPLE_ASSIGN
As_Prs_PAxPA_k2 = ProbeA_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_590(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,590};
  (data->simulationInfo->realParameter[7] /* As_Prs_PAxPA_k2 PARAM */) = (data->simulationInfo->realParameter[31] /* ProbeA_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 591
type: SIMPLE_ASSIGN
As_Prs_PAxPA_k1 = ProbeA_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_591(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,591};
  (data->simulationInfo->realParameter[6] /* As_Prs_PAxPA_k1 PARAM */) = (data->simulationInfo->realParameter[30] /* ProbeA_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 592
type: SIMPLE_ASSIGN
Bs_PB_k2 = ProbeB_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_592(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,592};
  (data->simulationInfo->realParameter[17] /* Bs_PB_k2 PARAM */) = (data->simulationInfo->realParameter[34] /* ProbeB_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 593
type: SIMPLE_ASSIGN
Bs_PB_k1 = ProbeB_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_593(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,593};
  (data->simulationInfo->realParameter[16] /* Bs_PB_k1 PARAM */) = (data->simulationInfo->realParameter[33] /* ProbeB_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 594
type: SIMPLE_ASSIGN
As_PA_k2 = ProbeA_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_594(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,594};
  (data->simulationInfo->realParameter[5] /* As_PA_k2 PARAM */) = (data->simulationInfo->realParameter[31] /* ProbeA_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 595
type: SIMPLE_ASSIGN
As_PA_k1 = ProbeA_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_595(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,595};
  (data->simulationInfo->realParameter[4] /* As_PA_k1 PARAM */) = (data->simulationInfo->realParameter[30] /* ProbeA_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 596
type: SIMPLE_ASSIGN
heteroAsBa_k2 = hetero_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_596(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,596};
  (data->simulationInfo->realParameter[214] /* heteroAsBa_k2 PARAM */) = (data->simulationInfo->realParameter[216] /* hetero_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 597
type: SIMPLE_ASSIGN
heteroAsBa_k1 = hetero_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_597(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,597};
  (data->simulationInfo->realParameter[213] /* heteroAsBa_k1 PARAM */) = (data->simulationInfo->realParameter[215] /* hetero_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 598
type: SIMPLE_ASSIGN
heteroAaBs_k2 = hetero_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_598(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
  (data->simulationInfo->realParameter[212] /* heteroAaBs_k2 PARAM */) = (data->simulationInfo->realParameter[216] /* hetero_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 599
type: SIMPLE_ASSIGN
heteroAaBs_k1 = hetero_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_599(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
  (data->simulationInfo->realParameter[211] /* heteroAaBs_k1 PARAM */) = (data->simulationInfo->realParameter[215] /* hetero_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 600
type: SIMPLE_ASSIGN
Prs_k2 = Primer_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_600(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,600};
  (data->simulationInfo->realParameter[36] /* Prs_k2 PARAM */) = (data->simulationInfo->realParameter[28] /* Primer_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 601
type: SIMPLE_ASSIGN
As_Prs_PAxPrs_k2 = Prs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_601(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,601};
  (data->simulationInfo->realParameter[9] /* As_Prs_PAxPrs_k2 PARAM */) = (data->simulationInfo->realParameter[36] /* Prs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 602
type: SIMPLE_ASSIGN
Prs_k1 = Primer_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_602(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,602};
  (data->simulationInfo->realParameter[35] /* Prs_k1 PARAM */) = (data->simulationInfo->realParameter[27] /* Primer_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 603
type: SIMPLE_ASSIGN
As_Prs_PAxPrs_k1 = Prs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_603(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,603};
  (data->simulationInfo->realParameter[8] /* As_Prs_PAxPrs_k1 PARAM */) = (data->simulationInfo->realParameter[35] /* Prs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 604
type: SIMPLE_ASSIGN
Bs_Prs_PBxPrs_k2 = Prs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_604(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,604};
  (data->simulationInfo->realParameter[21] /* Bs_Prs_PBxPrs_k2 PARAM */) = (data->simulationInfo->realParameter[36] /* Prs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 605
type: SIMPLE_ASSIGN
Bs_Prs_PBxPrs_k1 = Prs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_605(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,605};
  (data->simulationInfo->realParameter[20] /* Bs_Prs_PBxPrs_k1 PARAM */) = (data->simulationInfo->realParameter[35] /* Prs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 606
type: SIMPLE_ASSIGN
Bs_Prs_k2 = Prs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_606(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,606};
  (data->simulationInfo->realParameter[23] /* Bs_Prs_k2 PARAM */) = (data->simulationInfo->realParameter[36] /* Prs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 607
type: SIMPLE_ASSIGN
Bs_Prs_k1 = Prs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_607(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,607};
  (data->simulationInfo->realParameter[22] /* Bs_Prs_k1 PARAM */) = (data->simulationInfo->realParameter[35] /* Prs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 608
type: SIMPLE_ASSIGN
As_Prs_k2 = Prs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_608(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,608};
  (data->simulationInfo->realParameter[11] /* As_Prs_k2 PARAM */) = (data->simulationInfo->realParameter[36] /* Prs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 609
type: SIMPLE_ASSIGN
As_Prs_k1 = Prs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_609(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,609};
  (data->simulationInfo->realParameter[10] /* As_Prs_k1 PARAM */) = (data->simulationInfo->realParameter[35] /* Prs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 610
type: SIMPLE_ASSIGN
senseB = (1.0 - startRatio) * startTemplate
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_610(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,610};
  (data->simulationInfo->realParameter[242] /* senseB PARAM */) = (1.0 - (data->simulationInfo->realParameter[245] /* startRatio PARAM */)) * ((data->simulationInfo->realParameter[246] /* startTemplate PARAM */));
  TRACE_POP
}

/*
equation index: 611
type: SIMPLE_ASSIGN
antiB = (1.0 - startRatio) * startTemplate
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_611(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,611};
  (data->simulationInfo->realParameter[205] /* antiB PARAM */) = (1.0 - (data->simulationInfo->realParameter[245] /* startRatio PARAM */)) * ((data->simulationInfo->realParameter[246] /* startTemplate PARAM */));
  TRACE_POP
}

/*
equation index: 612
type: SIMPLE_ASSIGN
senseA = startRatio * startTemplate
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_612(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,612};
  (data->simulationInfo->realParameter[241] /* senseA PARAM */) = ((data->simulationInfo->realParameter[245] /* startRatio PARAM */)) * ((data->simulationInfo->realParameter[246] /* startTemplate PARAM */));
  TRACE_POP
}

/*
equation index: 613
type: SIMPLE_ASSIGN
antiA = startRatio * startTemplate
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_613(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,613};
  (data->simulationInfo->realParameter[204] /* antiA PARAM */) = ((data->simulationInfo->realParameter[245] /* startRatio PARAM */)) * ((data->simulationInfo->realParameter[246] /* startTemplate PARAM */));
  TRACE_POP
}

/*
equation index: 614
type: SIMPLE_ASSIGN
antiPrimer = startPrimer
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_614(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,614};
  (data->simulationInfo->realParameter[206] /* antiPrimer PARAM */) = (data->simulationInfo->realParameter[244] /* startPrimer PARAM */);
  TRACE_POP
}

/*
equation index: 615
type: SIMPLE_ASSIGN
sensePrimer = startPrimer
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_615(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,615};
  (data->simulationInfo->realParameter[243] /* sensePrimer PARAM */) = (data->simulationInfo->realParameter[244] /* startPrimer PARAM */);
  TRACE_POP
}

/*
equation index: 616
type: SIMPLE_ASSIGN
iR_AaPraPoly_x_AaAs_Poly.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_616(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,616};
  (data->simulationInfo->realParameter[219] /* iR_AaPraPoly_x_AaAs_Poly.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 617
type: SIMPLE_ASSIGN
iR_BaPraPoly_x_BaBs_Poly.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_617(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,617};
  (data->simulationInfo->realParameter[227] /* iR_BaPraPoly_x_BaBs_Poly.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 618
type: SIMPLE_ASSIGN
iR_AsPrsPaPoly_x_AaAs_Poly_SigA.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_618(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,618};
  (data->simulationInfo->realParameter[221] /* iR_AsPrsPaPoly_x_AaAs_Poly_SigA.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 619
type: SIMPLE_ASSIGN
iR_AsPrsPoly_x_AaAs_Poly.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_619(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,619};
  (data->simulationInfo->realParameter[223] /* iR_AsPrsPoly_x_AaAs_Poly.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 620
type: SIMPLE_ASSIGN
iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_620(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,620};
  (data->simulationInfo->realParameter[229] /* iR_BsPrsPbPoly_x_BaBs_Poly_SignalB.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 621
type: SIMPLE_ASSIGN
iR_BsPrsPoly_x_BaBs_Poly.k1 = RextPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_621(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,621};
  (data->simulationInfo->realParameter[231] /* iR_BsPrsPoly_x_BaBs_Poly.k1 PARAM */) = (data->simulationInfo->realParameter[199] /* RextPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 622
type: SIMPLE_ASSIGN
R_BsPrsPB_Poly_x_BsPrsPBPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_622(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,622};
  (data->simulationInfo->realParameter[173] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 623
type: SIMPLE_ASSIGN
R_BsPrsPB_Poly_x_BsPrsPBPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_623(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,623};
  (data->simulationInfo->realParameter[172] /* R_BsPrsPB_Poly_x_BsPrsPBPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 624
type: SIMPLE_ASSIGN
R_BsPrs_Poly_x_BsPrsPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_624(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,624};
  (data->simulationInfo->realParameter[183] /* R_BsPrs_Poly_x_BsPrsPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 625
type: SIMPLE_ASSIGN
R_BsPrs_Poly_x_BsPrsPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_625(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,625};
  (data->simulationInfo->realParameter[182] /* R_BsPrs_Poly_x_BsPrsPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 626
type: SIMPLE_ASSIGN
R_BaPra_Poly_x_BaPraPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_626(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,626};
  (data->simulationInfo->realParameter[148] /* R_BaPra_Poly_x_BaPraPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 627
type: SIMPLE_ASSIGN
R_BaPra_Poly_x_BaPraPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_627(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,627};
  (data->simulationInfo->realParameter[147] /* R_BaPra_Poly_x_BaPraPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 628
type: SIMPLE_ASSIGN
R_AsPrsPA_Poly_AsPrsPAPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_628(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,628};
  (data->simulationInfo->realParameter[98] /* R_AsPrsPA_Poly_AsPrsPAPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 629
type: SIMPLE_ASSIGN
R_AsPrsPA_Poly_AsPrsPAPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_629(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,629};
  (data->simulationInfo->realParameter[97] /* R_AsPrsPA_Poly_AsPrsPAPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 630
type: SIMPLE_ASSIGN
R_AsPrs_Poly_x_AsPrsPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_630(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,630};
  (data->simulationInfo->realParameter[108] /* R_AsPrs_Poly_x_AsPrsPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 631
type: SIMPLE_ASSIGN
R_AsPrs_Poly_x_AsPrsPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_631(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,631};
  (data->simulationInfo->realParameter[107] /* R_AsPrs_Poly_x_AsPrsPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 632
type: SIMPLE_ASSIGN
R_AaPra_Poly_x_AaPraPoly.k2 = RiniPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_632(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,632};
  (data->simulationInfo->realParameter[63] /* R_AaPra_Poly_x_AaPraPoly.k2 PARAM */) = (data->simulationInfo->realParameter[201] /* RiniPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 633
type: SIMPLE_ASSIGN
R_AaPra_Poly_x_AaPraPoly.k1 = RiniPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_633(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,633};
  (data->simulationInfo->realParameter[62] /* R_AaPra_Poly_x_AaPraPoly.k1 PARAM */) = (data->simulationInfo->realParameter[200] /* RiniPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 634
type: SIMPLE_ASSIGN
R_AsBa_Poly_x_AsBaPoly.k2 = RdsPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_634(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,634};
  (data->simulationInfo->realParameter[88] /* R_AsBa_Poly_x_AsBaPoly.k2 PARAM */) = (data->simulationInfo->realParameter[198] /* RdsPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 635
type: SIMPLE_ASSIGN
R_AsBa_Poly_x_AsBaPoly.k1 = RdsPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_635(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,635};
  (data->simulationInfo->realParameter[87] /* R_AsBa_Poly_x_AsBaPoly.k1 PARAM */) = (data->simulationInfo->realParameter[197] /* RdsPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 636
type: SIMPLE_ASSIGN
R_AaBs_Poly_x_AaBsPoly.k2 = RdsPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_636(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,636};
  (data->simulationInfo->realParameter[43] /* R_AaBs_Poly_x_AaBsPoly.k2 PARAM */) = (data->simulationInfo->realParameter[198] /* RdsPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 637
type: SIMPLE_ASSIGN
R_AaBs_Poly_x_AaBsPoly.k1 = RdsPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_637(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,637};
  (data->simulationInfo->realParameter[42] /* R_AaBs_Poly_x_AaBsPoly.k1 PARAM */) = (data->simulationInfo->realParameter[197] /* RdsPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 638
type: SIMPLE_ASSIGN
R_BaBs_Poly_x_BaBsPoly.k2 = RdsPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_638(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,638};
  (data->simulationInfo->realParameter[128] /* R_BaBs_Poly_x_BaBsPoly.k2 PARAM */) = (data->simulationInfo->realParameter[198] /* RdsPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 639
type: SIMPLE_ASSIGN
R_BaBs_Poly_x_BaBsPoly.k1 = RdsPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_639(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,639};
  (data->simulationInfo->realParameter[127] /* R_BaBs_Poly_x_BaBsPoly.k1 PARAM */) = (data->simulationInfo->realParameter[197] /* RdsPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 640
type: SIMPLE_ASSIGN
R_AaAs_Poly_x_AaAsPoly.k2 = RdsPoly_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_640(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,640};
  (data->simulationInfo->realParameter[38] /* R_AaAs_Poly_x_AaAsPoly.k2 PARAM */) = (data->simulationInfo->realParameter[198] /* RdsPoly_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 641
type: SIMPLE_ASSIGN
R_AaAs_Poly_x_AaAsPoly.k1 = RdsPoly_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_641(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,641};
  (data->simulationInfo->realParameter[37] /* R_AaAs_Poly_x_AaAsPoly.k1 PARAM */) = (data->simulationInfo->realParameter[197] /* RdsPoly_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 642
type: SIMPLE_ASSIGN
R_BsPrs_PB_x_BsPrsPB.k2 = Bs_Prs_PBxPB_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_642(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,642};
  (data->simulationInfo->realParameter[178] /* R_BsPrs_PB_x_BsPrsPB.k2 PARAM */) = (data->simulationInfo->realParameter[19] /* Bs_Prs_PBxPB_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 643
type: SIMPLE_ASSIGN
R_BsPrs_PB_x_BsPrsPB.k1 = Bs_Prs_PBxPB_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_643(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,643};
  (data->simulationInfo->realParameter[177] /* R_BsPrs_PB_x_BsPrsPB.k1 PARAM */) = (data->simulationInfo->realParameter[18] /* Bs_Prs_PBxPB_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 644
type: SIMPLE_ASSIGN
R_AsPrs_PA_x_AsPrsPA.k2 = As_Prs_PAxPA_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_644(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,644};
  (data->simulationInfo->realParameter[103] /* R_AsPrs_PA_x_AsPrsPA.k2 PARAM */) = (data->simulationInfo->realParameter[7] /* As_Prs_PAxPA_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 645
type: SIMPLE_ASSIGN
R_AsPrs_PA_x_AsPrsPA.k1 = As_Prs_PAxPA_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_645(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,645};
  (data->simulationInfo->realParameter[102] /* R_AsPrs_PA_x_AsPrsPA.k1 PARAM */) = (data->simulationInfo->realParameter[6] /* As_Prs_PAxPA_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 646
type: SIMPLE_ASSIGN
R_Bs_PB_x_BsPB.k2 = Bs_PB_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_646(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,646};
  (data->simulationInfo->realParameter[188] /* R_Bs_PB_x_BsPB.k2 PARAM */) = (data->simulationInfo->realParameter[17] /* Bs_PB_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 647
type: SIMPLE_ASSIGN
R_Bs_PB_x_BsPB.k1 = Bs_PB_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_647(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,647};
  (data->simulationInfo->realParameter[187] /* R_Bs_PB_x_BsPB.k1 PARAM */) = (data->simulationInfo->realParameter[16] /* Bs_PB_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 648
type: SIMPLE_ASSIGN
R_As_PA_x_AsPA.k2 = As_PA_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_648(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,648};
  (data->simulationInfo->realParameter[118] /* R_As_PA_x_AsPA.k2 PARAM */) = (data->simulationInfo->realParameter[5] /* As_PA_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 649
type: SIMPLE_ASSIGN
R_As_PA_x_AsPA.k1 = As_PA_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_649(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,649};
  (data->simulationInfo->realParameter[117] /* R_As_PA_x_AsPA.k1 PARAM */) = (data->simulationInfo->realParameter[4] /* As_PA_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 650
type: SIMPLE_ASSIGN
R_AsPA_Prs_x_AsPrsPA.k2 = As_Prs_PAxPrs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_650(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,650};
  (data->simulationInfo->realParameter[93] /* R_AsPA_Prs_x_AsPrsPA.k2 PARAM */) = (data->simulationInfo->realParameter[9] /* As_Prs_PAxPrs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 651
type: SIMPLE_ASSIGN
R_AsPA_Prs_x_AsPrsPA.k1 = As_Prs_PAxPrs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_651(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,651};
  (data->simulationInfo->realParameter[92] /* R_AsPA_Prs_x_AsPrsPA.k1 PARAM */) = (data->simulationInfo->realParameter[8] /* As_Prs_PAxPrs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 652
type: SIMPLE_ASSIGN
R_BsPB_Prs_x_BsPrsPB.k2 = Bs_Prs_PBxPrs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_652(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,652};
  (data->simulationInfo->realParameter[168] /* R_BsPB_Prs_x_BsPrsPB.k2 PARAM */) = (data->simulationInfo->realParameter[21] /* Bs_Prs_PBxPrs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 653
type: SIMPLE_ASSIGN
R_BsPB_Prs_x_BsPrsPB.k1 = Bs_Prs_PBxPrs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_653(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,653};
  (data->simulationInfo->realParameter[167] /* R_BsPB_Prs_x_BsPrsPB.k1 PARAM */) = (data->simulationInfo->realParameter[20] /* Bs_Prs_PBxPrs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 654
type: SIMPLE_ASSIGN
R_Bs_Prs_x_BsPrs.k2 = Bs_Prs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_654(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,654};
  (data->simulationInfo->realParameter[193] /* R_Bs_Prs_x_BsPrs.k2 PARAM */) = (data->simulationInfo->realParameter[23] /* Bs_Prs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 655
type: SIMPLE_ASSIGN
R_Bs_Prs_x_BsPrs.k1 = Bs_Prs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_655(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,655};
  (data->simulationInfo->realParameter[192] /* R_Bs_Prs_x_BsPrs.k1 PARAM */) = (data->simulationInfo->realParameter[22] /* Bs_Prs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 656
type: SIMPLE_ASSIGN
R_As_Prs_x_AsPrs.k2 = As_Prs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_656(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,656};
  (data->simulationInfo->realParameter[123] /* R_As_Prs_x_AsPrs.k2 PARAM */) = (data->simulationInfo->realParameter[11] /* As_Prs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 657
type: SIMPLE_ASSIGN
R_As_Prs_x_AsPrs.k1 = As_Prs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_657(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,657};
  (data->simulationInfo->realParameter[122] /* R_As_Prs_x_AsPrs.k1 PARAM */) = (data->simulationInfo->realParameter[10] /* As_Prs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 658
type: SIMPLE_ASSIGN
R_Aa_Pra_x_AaPra.k2 = Aa_Pra_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_658(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,658};
  (data->simulationInfo->realParameter[83] /* R_Aa_Pra_x_AaPra.k2 PARAM */) = (data->simulationInfo->realParameter[3] /* Aa_Pra_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 659
type: SIMPLE_ASSIGN
R_Aa_Pra_x_AaPra.k1 = Aa_Pra_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_659(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,659};
  (data->simulationInfo->realParameter[82] /* R_Aa_Pra_x_AaPra.k1 PARAM */) = (data->simulationInfo->realParameter[2] /* Aa_Pra_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 660
type: SIMPLE_ASSIGN
R_Ba_Pra_x_BaPra.k2 = Ba_Pra_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_660(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,660};
  (data->simulationInfo->realParameter[163] /* R_Ba_Pra_x_BaPra.k2 PARAM */) = (data->simulationInfo->realParameter[15] /* Ba_Pra_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 661
type: SIMPLE_ASSIGN
R_Ba_Pra_x_BaPra.k1 = Ba_Pra_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_661(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,661};
  (data->simulationInfo->realParameter[162] /* R_Ba_Pra_x_BaPra.k1 PARAM */) = (data->simulationInfo->realParameter[14] /* Ba_Pra_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 662
type: SIMPLE_ASSIGN
R_As_Ba_x_AsBa.k2 = heteroAsBa_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_662(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,662};
  (data->simulationInfo->realParameter[113] /* R_As_Ba_x_AsBa.k2 PARAM */) = (data->simulationInfo->realParameter[214] /* heteroAsBa_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 663
type: SIMPLE_ASSIGN
R_As_Ba_x_AsBa.k1 = heteroAsBa_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_663(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,663};
  (data->simulationInfo->realParameter[112] /* R_As_Ba_x_AsBa.k1 PARAM */) = (data->simulationInfo->realParameter[213] /* heteroAsBa_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 664
type: SIMPLE_ASSIGN
R_Aa_Bs_x_AaBs.k2 = heteroAaBs_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_664(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,664};
  (data->simulationInfo->realParameter[73] /* R_Aa_Bs_x_AaBs.k2 PARAM */) = (data->simulationInfo->realParameter[212] /* heteroAaBs_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 665
type: SIMPLE_ASSIGN
R_Aa_Bs_x_AaBs.k1 = heteroAaBs_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_665(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,665};
  (data->simulationInfo->realParameter[72] /* R_Aa_Bs_x_AaBs.k1 PARAM */) = (data->simulationInfo->realParameter[211] /* heteroAaBs_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 666
type: SIMPLE_ASSIGN
R_Aa_As_x_AaAs.k2 = rehybA_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_666(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,666};
  (data->simulationInfo->realParameter[68] /* R_Aa_As_x_AaAs.k2 PARAM */) = (data->simulationInfo->realParameter[236] /* rehybA_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 667
type: SIMPLE_ASSIGN
R_Aa_As_x_AaAs.k1 = rehybA_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_667(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,667};
  (data->simulationInfo->realParameter[67] /* R_Aa_As_x_AaAs.k1 PARAM */) = (data->simulationInfo->realParameter[235] /* rehybA_k1 PARAM */);
  TRACE_POP
}

/*
equation index: 668
type: SIMPLE_ASSIGN
R_Ba_Bs_x_BaBs.k2 = rehybB_k2
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_668(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,668};
  (data->simulationInfo->realParameter[153] /* R_Ba_Bs_x_BaBs.k2 PARAM */) = (data->simulationInfo->realParameter[238] /* rehybB_k2 PARAM */);
  TRACE_POP
}

/*
equation index: 669
type: SIMPLE_ASSIGN
R_Ba_Bs_x_BaBs.k1 = rehybB_k1
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_669(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,669};
  (data->simulationInfo->realParameter[152] /* R_Ba_Bs_x_BaBs.k1 PARAM */) = (data->simulationInfo->realParameter[237] /* rehybB_k1 PARAM */);
  TRACE_POP
}
extern void rPCR_03_eqFunction_125(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_124(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_123(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_122(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_121(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_120(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_119(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_118(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_117(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_116(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_115(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_114(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_113(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_112(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_111(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_110(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_109(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_108(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_107(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_106(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_105(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_104(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_103(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_102(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_101(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_100(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_99(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_98(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_97(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_96(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_95(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_94(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_93(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_92(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_91(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_90(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_89(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_88(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_87(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_86(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_85(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_84(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_83(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_82(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_81(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_80(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_79(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_78(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_77(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_76(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_75(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_74(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_73(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_72(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_71(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_70(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_69(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_68(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_67(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_66(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_65(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_64(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_63(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_62(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_61(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_60(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_59(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_58(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_57(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_56(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_55(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_54(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_53(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_52(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_51(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_50(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_49(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_48(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_47(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_46(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_45(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_44(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_43(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_42(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_41(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_40(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_39(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_38(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_37(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_36(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_35(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_34(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_33(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_32(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_31(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_30(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_29(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_28(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_27(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_26(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_25(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_24(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_23(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_22(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_21(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_20(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_19(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_18(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_17(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_16(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_15(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_14(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_13(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_12(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_11(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_10(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_9(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_8(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_7(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_6(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_5(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_4(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_3(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_2(DATA *data, threadData_t *threadData);

extern void rPCR_03_eqFunction_1(DATA *data, threadData_t *threadData);


/*
equation index: 828
type: ALGORITHM

  assert(AaPraPBPoly.use >= BioChem.Types.StateVariable.c and AaPraPBPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPraPBPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(AaPraPBPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_828(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,828};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,133,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPraPBPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp3;
  modelica_metatype tmpMeta4;
  static int tmp5 = 0;
  if(!tmp5)
  {
    tmp0 = GreaterEq((data->simulationInfo->integerParameter[8] /* AaPraPBPoly.use PARAM */),1);
    tmp1 = LessEq((data->simulationInfo->integerParameter[8] /* AaPraPBPoly.use PARAM */),2);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[8] /* AaPraPBPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta4 = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        const char* assert_cond = "(AaPraPBPoly.use >= BioChem.Types.StateVariable.c and AaPraPBPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta4));
        }
      }
      tmp5 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 829
type: ALGORITHM

  assert(AaPraPB.use >= BioChem.Types.StateVariable.c and AaPraPB.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPraPB.use <= BioChem.Types.StateVariable.n, has value: " + String(AaPraPB.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_829(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,829};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  static const MMC_DEFSTRINGLIT(tmp8,129,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPraPB.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp9;
  modelica_metatype tmpMeta10;
  static int tmp11 = 0;
  if(!tmp11)
  {
    tmp6 = GreaterEq((data->simulationInfo->integerParameter[7] /* AaPraPB.use PARAM */),1);
    tmp7 = LessEq((data->simulationInfo->integerParameter[7] /* AaPraPB.use PARAM */),2);
    if(!(tmp6 && tmp7))
    {
      tmp9 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[7] /* AaPraPB.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta10 = stringAppend(MMC_REFSTRINGLIT(tmp8),tmp9);
      {
        const char* assert_cond = "(AaPraPB.use >= BioChem.Types.StateVariable.c and AaPraPB.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta10));
        }
      }
      tmp11 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 830
type: ALGORITHM

  assert(AaPB.use >= BioChem.Types.StateVariable.c and AaPB.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPB.use <= BioChem.Types.StateVariable.n, has value: " + String(AaPB.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_830(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,830};
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  static const MMC_DEFSTRINGLIT(tmp14,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPB.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp15;
  modelica_metatype tmpMeta16;
  static int tmp17 = 0;
  if(!tmp17)
  {
    tmp12 = GreaterEq((data->simulationInfo->integerParameter[5] /* AaPB.use PARAM */),1);
    tmp13 = LessEq((data->simulationInfo->integerParameter[5] /* AaPB.use PARAM */),2);
    if(!(tmp12 && tmp13))
    {
      tmp15 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[5] /* AaPB.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta16 = stringAppend(MMC_REFSTRINGLIT(tmp14),tmp15);
      {
        const char* assert_cond = "(AaPB.use >= BioChem.Types.StateVariable.c and AaPB.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta16));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta16));
        }
      }
      tmp17 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 831
type: ALGORITHM

  assert(BaPraPAPoly.use >= BioChem.Types.StateVariable.c and BaPraPAPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPraPAPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(BaPraPAPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_831(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,831};
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  static const MMC_DEFSTRINGLIT(tmp20,133,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPraPAPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp21;
  modelica_metatype tmpMeta22;
  static int tmp23 = 0;
  if(!tmp23)
  {
    tmp18 = GreaterEq((data->simulationInfo->integerParameter[24] /* BaPraPAPoly.use PARAM */),1);
    tmp19 = LessEq((data->simulationInfo->integerParameter[24] /* BaPraPAPoly.use PARAM */),2);
    if(!(tmp18 && tmp19))
    {
      tmp21 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[24] /* BaPraPAPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta22 = stringAppend(MMC_REFSTRINGLIT(tmp20),tmp21);
      {
        const char* assert_cond = "(BaPraPAPoly.use >= BioChem.Types.StateVariable.c and BaPraPAPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta22));
        }
      }
      tmp23 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 832
type: ALGORITHM

  assert(BaPraPA.use >= BioChem.Types.StateVariable.c and BaPraPA.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPraPA.use <= BioChem.Types.StateVariable.n, has value: " + String(BaPraPA.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_832(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,832};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  static const MMC_DEFSTRINGLIT(tmp26,129,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPraPA.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp27;
  modelica_metatype tmpMeta28;
  static int tmp29 = 0;
  if(!tmp29)
  {
    tmp24 = GreaterEq((data->simulationInfo->integerParameter[23] /* BaPraPA.use PARAM */),1);
    tmp25 = LessEq((data->simulationInfo->integerParameter[23] /* BaPraPA.use PARAM */),2);
    if(!(tmp24 && tmp25))
    {
      tmp27 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[23] /* BaPraPA.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta28 = stringAppend(MMC_REFSTRINGLIT(tmp26),tmp27);
      {
        const char* assert_cond = "(BaPraPA.use >= BioChem.Types.StateVariable.c and BaPraPA.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
        }
      }
      tmp29 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 833
type: ALGORITHM

  assert(BaPA.use >= BioChem.Types.StateVariable.c and BaPA.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPA.use <= BioChem.Types.StateVariable.n, has value: " + String(BaPA.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_833(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,833};
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPA.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp33;
  modelica_metatype tmpMeta34;
  static int tmp35 = 0;
  if(!tmp35)
  {
    tmp30 = GreaterEq((data->simulationInfo->integerParameter[21] /* BaPA.use PARAM */),1);
    tmp31 = LessEq((data->simulationInfo->integerParameter[21] /* BaPA.use PARAM */),2);
    if(!(tmp30 && tmp31))
    {
      tmp33 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[21] /* BaPA.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta34 = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
      {
        const char* assert_cond = "(BaPA.use >= BioChem.Types.StateVariable.c and BaPA.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
        }
      }
      tmp35 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 834
type: ALGORITHM

  assert(signalB.use >= BioChem.Types.StateVariable.c and signalB.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= signalB.use <= BioChem.Types.StateVariable.n, has value: " + String(signalB.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_834(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,834};
  modelica_boolean tmp36;
  modelica_boolean tmp37;
  static const MMC_DEFSTRINGLIT(tmp38,129,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= signalB.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp39;
  modelica_metatype tmpMeta40;
  static int tmp41 = 0;
  if(!tmp41)
  {
    tmp36 = GreaterEq((data->simulationInfo->integerParameter[38] /* signalB.use PARAM */),1);
    tmp37 = LessEq((data->simulationInfo->integerParameter[38] /* signalB.use PARAM */),2);
    if(!(tmp36 && tmp37))
    {
      tmp39 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[38] /* signalB.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta40 = stringAppend(MMC_REFSTRINGLIT(tmp38),tmp39);
      {
        const char* assert_cond = "(signalB.use >= BioChem.Types.StateVariable.c and signalB.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
        }
      }
      tmp41 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 835
type: ALGORITHM

  assert(signalA.use >= BioChem.Types.StateVariable.c and signalA.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= signalA.use <= BioChem.Types.StateVariable.n, has value: " + String(signalA.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_835(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,835};
  modelica_boolean tmp42;
  modelica_boolean tmp43;
  static const MMC_DEFSTRINGLIT(tmp44,129,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= signalA.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp45;
  modelica_metatype tmpMeta46;
  static int tmp47 = 0;
  if(!tmp47)
  {
    tmp42 = GreaterEq((data->simulationInfo->integerParameter[37] /* signalA.use PARAM */),1);
    tmp43 = LessEq((data->simulationInfo->integerParameter[37] /* signalA.use PARAM */),2);
    if(!(tmp42 && tmp43))
    {
      tmp45 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[37] /* signalA.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta46 = stringAppend(MMC_REFSTRINGLIT(tmp44),tmp45);
      {
        const char* assert_cond = "(signalA.use >= BioChem.Types.StateVariable.c and signalA.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta46));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta46));
        }
      }
      tmp47 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 836
type: ALGORITHM

  assert(AaBsPoly.use >= BioChem.Types.StateVariable.c and AaBsPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaBsPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(AaBsPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_836(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,836};
  modelica_boolean tmp48;
  modelica_boolean tmp49;
  static const MMC_DEFSTRINGLIT(tmp50,130,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaBsPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp51;
  modelica_metatype tmpMeta52;
  static int tmp53 = 0;
  if(!tmp53)
  {
    tmp48 = GreaterEq((data->simulationInfo->integerParameter[4] /* AaBsPoly.use PARAM */),1);
    tmp49 = LessEq((data->simulationInfo->integerParameter[4] /* AaBsPoly.use PARAM */),2);
    if(!(tmp48 && tmp49))
    {
      tmp51 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[4] /* AaBsPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta52 = stringAppend(MMC_REFSTRINGLIT(tmp50),tmp51);
      {
        const char* assert_cond = "(AaBsPoly.use >= BioChem.Types.StateVariable.c and AaBsPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta52));
        }
      }
      tmp53 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 837
type: ALGORITHM

  assert(AsBaPoly.use >= BioChem.Types.StateVariable.c and AsBaPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsBaPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(AsBaPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_837(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,837};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  static const MMC_DEFSTRINGLIT(tmp56,130,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsBaPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp57;
  modelica_metatype tmpMeta58;
  static int tmp59 = 0;
  if(!tmp59)
  {
    tmp54 = GreaterEq((data->simulationInfo->integerParameter[12] /* AsBaPoly.use PARAM */),1);
    tmp55 = LessEq((data->simulationInfo->integerParameter[12] /* AsBaPoly.use PARAM */),2);
    if(!(tmp54 && tmp55))
    {
      tmp57 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[12] /* AsBaPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta58 = stringAppend(MMC_REFSTRINGLIT(tmp56),tmp57);
      {
        const char* assert_cond = "(AsBaPoly.use >= BioChem.Types.StateVariable.c and AsBaPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
        }
      }
      tmp59 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 838
type: ALGORITHM

  assert(BsPrsPoly.use >= BioChem.Types.StateVariable.c and BsPrsPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrsPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(BsPrsPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_838(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,838};
  modelica_boolean tmp60;
  modelica_boolean tmp61;
  static const MMC_DEFSTRINGLIT(tmp62,131,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrsPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp63;
  modelica_metatype tmpMeta64;
  static int tmp65 = 0;
  if(!tmp65)
  {
    tmp60 = GreaterEq((data->simulationInfo->integerParameter[31] /* BsPrsPoly.use PARAM */),1);
    tmp61 = LessEq((data->simulationInfo->integerParameter[31] /* BsPrsPoly.use PARAM */),2);
    if(!(tmp60 && tmp61))
    {
      tmp63 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[31] /* BsPrsPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta64 = stringAppend(MMC_REFSTRINGLIT(tmp62),tmp63);
      {
        const char* assert_cond = "(BsPrsPoly.use >= BioChem.Types.StateVariable.c and BsPrsPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta64));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta64));
        }
      }
      tmp65 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 839
type: ALGORITHM

  assert(BsPrsPBPoly.use >= BioChem.Types.StateVariable.c and BsPrsPBPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrsPBPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(BsPrsPBPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_839(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,839};
  modelica_boolean tmp66;
  modelica_boolean tmp67;
  static const MMC_DEFSTRINGLIT(tmp68,133,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrsPBPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp69;
  modelica_metatype tmpMeta70;
  static int tmp71 = 0;
  if(!tmp71)
  {
    tmp66 = GreaterEq((data->simulationInfo->integerParameter[30] /* BsPrsPBPoly.use PARAM */),1);
    tmp67 = LessEq((data->simulationInfo->integerParameter[30] /* BsPrsPBPoly.use PARAM */),2);
    if(!(tmp66 && tmp67))
    {
      tmp69 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[30] /* BsPrsPBPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta70 = stringAppend(MMC_REFSTRINGLIT(tmp68),tmp69);
      {
        const char* assert_cond = "(BsPrsPBPoly.use >= BioChem.Types.StateVariable.c and BsPrsPBPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta70));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta70));
        }
      }
      tmp71 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 840
type: ALGORITHM

  assert(BaPraPoly.use >= BioChem.Types.StateVariable.c and BaPraPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPraPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(BaPraPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_840(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,840};
  modelica_boolean tmp72;
  modelica_boolean tmp73;
  static const MMC_DEFSTRINGLIT(tmp74,131,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPraPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp75;
  modelica_metatype tmpMeta76;
  static int tmp77 = 0;
  if(!tmp77)
  {
    tmp72 = GreaterEq((data->simulationInfo->integerParameter[25] /* BaPraPoly.use PARAM */),1);
    tmp73 = LessEq((data->simulationInfo->integerParameter[25] /* BaPraPoly.use PARAM */),2);
    if(!(tmp72 && tmp73))
    {
      tmp75 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[25] /* BaPraPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta76 = stringAppend(MMC_REFSTRINGLIT(tmp74),tmp75);
      {
        const char* assert_cond = "(BaPraPoly.use >= BioChem.Types.StateVariable.c and BaPraPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta76));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta76));
        }
      }
      tmp77 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 841
type: ALGORITHM

  assert(AsPrsPoly.use >= BioChem.Types.StateVariable.c and AsPrsPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrsPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(AsPrsPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_841(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,841};
  modelica_boolean tmp78;
  modelica_boolean tmp79;
  static const MMC_DEFSTRINGLIT(tmp80,131,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrsPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp81;
  modelica_metatype tmpMeta82;
  static int tmp83 = 0;
  if(!tmp83)
  {
    tmp78 = GreaterEq((data->simulationInfo->integerParameter[17] /* AsPrsPoly.use PARAM */),1);
    tmp79 = LessEq((data->simulationInfo->integerParameter[17] /* AsPrsPoly.use PARAM */),2);
    if(!(tmp78 && tmp79))
    {
      tmp81 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[17] /* AsPrsPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta82 = stringAppend(MMC_REFSTRINGLIT(tmp80),tmp81);
      {
        const char* assert_cond = "(AsPrsPoly.use >= BioChem.Types.StateVariable.c and AsPrsPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta82));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta82));
        }
      }
      tmp83 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 842
type: ALGORITHM

  assert(AsPrsPAPoly.use >= BioChem.Types.StateVariable.c and AsPrsPAPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrsPAPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(AsPrsPAPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_842(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,842};
  modelica_boolean tmp84;
  modelica_boolean tmp85;
  static const MMC_DEFSTRINGLIT(tmp86,133,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrsPAPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp87;
  modelica_metatype tmpMeta88;
  static int tmp89 = 0;
  if(!tmp89)
  {
    tmp84 = GreaterEq((data->simulationInfo->integerParameter[16] /* AsPrsPAPoly.use PARAM */),1);
    tmp85 = LessEq((data->simulationInfo->integerParameter[16] /* AsPrsPAPoly.use PARAM */),2);
    if(!(tmp84 && tmp85))
    {
      tmp87 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[16] /* AsPrsPAPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta88 = stringAppend(MMC_REFSTRINGLIT(tmp86),tmp87);
      {
        const char* assert_cond = "(AsPrsPAPoly.use >= BioChem.Types.StateVariable.c and AsPrsPAPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
        }
      }
      tmp89 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 843
type: ALGORITHM

  assert(AaPraPoly.use >= BioChem.Types.StateVariable.c and AaPraPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPraPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(AaPraPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_843(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,843};
  modelica_boolean tmp90;
  modelica_boolean tmp91;
  static const MMC_DEFSTRINGLIT(tmp92,131,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPraPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp93;
  modelica_metatype tmpMeta94;
  static int tmp95 = 0;
  if(!tmp95)
  {
    tmp90 = GreaterEq((data->simulationInfo->integerParameter[9] /* AaPraPoly.use PARAM */),1);
    tmp91 = LessEq((data->simulationInfo->integerParameter[9] /* AaPraPoly.use PARAM */),2);
    if(!(tmp90 && tmp91))
    {
      tmp93 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[9] /* AaPraPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta94 = stringAppend(MMC_REFSTRINGLIT(tmp92),tmp93);
      {
        const char* assert_cond = "(AaPraPoly.use >= BioChem.Types.StateVariable.c and AaPraPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta94));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta94));
        }
      }
      tmp95 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 844
type: ALGORITHM

  assert(BsPrsPB.use >= BioChem.Types.StateVariable.c and BsPrsPB.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrsPB.use <= BioChem.Types.StateVariable.n, has value: " + String(BsPrsPB.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_844(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,844};
  modelica_boolean tmp96;
  modelica_boolean tmp97;
  static const MMC_DEFSTRINGLIT(tmp98,129,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrsPB.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp99;
  modelica_metatype tmpMeta100;
  static int tmp101 = 0;
  if(!tmp101)
  {
    tmp96 = GreaterEq((data->simulationInfo->integerParameter[29] /* BsPrsPB.use PARAM */),1);
    tmp97 = LessEq((data->simulationInfo->integerParameter[29] /* BsPrsPB.use PARAM */),2);
    if(!(tmp96 && tmp97))
    {
      tmp99 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[29] /* BsPrsPB.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta100 = stringAppend(MMC_REFSTRINGLIT(tmp98),tmp99);
      {
        const char* assert_cond = "(BsPrsPB.use >= BioChem.Types.StateVariable.c and BsPrsPB.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta100));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta100));
        }
      }
      tmp101 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 845
type: ALGORITHM

  assert(AsPrsPA.use >= BioChem.Types.StateVariable.c and AsPrsPA.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrsPA.use <= BioChem.Types.StateVariable.n, has value: " + String(AsPrsPA.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_845(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,845};
  modelica_boolean tmp102;
  modelica_boolean tmp103;
  static const MMC_DEFSTRINGLIT(tmp104,129,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrsPA.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp105;
  modelica_metatype tmpMeta106;
  static int tmp107 = 0;
  if(!tmp107)
  {
    tmp102 = GreaterEq((data->simulationInfo->integerParameter[15] /* AsPrsPA.use PARAM */),1);
    tmp103 = LessEq((data->simulationInfo->integerParameter[15] /* AsPrsPA.use PARAM */),2);
    if(!(tmp102 && tmp103))
    {
      tmp105 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[15] /* AsPrsPA.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta106 = stringAppend(MMC_REFSTRINGLIT(tmp104),tmp105);
      {
        const char* assert_cond = "(AsPrsPA.use >= BioChem.Types.StateVariable.c and AsPrsPA.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta106));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta106));
        }
      }
      tmp107 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 846
type: ALGORITHM

  assert(AsPA.use >= BioChem.Types.StateVariable.c and AsPA.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPA.use <= BioChem.Types.StateVariable.n, has value: " + String(AsPA.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_846(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,846};
  modelica_boolean tmp108;
  modelica_boolean tmp109;
  static const MMC_DEFSTRINGLIT(tmp110,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPA.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp111;
  modelica_metatype tmpMeta112;
  static int tmp113 = 0;
  if(!tmp113)
  {
    tmp108 = GreaterEq((data->simulationInfo->integerParameter[13] /* AsPA.use PARAM */),1);
    tmp109 = LessEq((data->simulationInfo->integerParameter[13] /* AsPA.use PARAM */),2);
    if(!(tmp108 && tmp109))
    {
      tmp111 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[13] /* AsPA.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta112 = stringAppend(MMC_REFSTRINGLIT(tmp110),tmp111);
      {
        const char* assert_cond = "(AsPA.use >= BioChem.Types.StateVariable.c and AsPA.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta112));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta112));
        }
      }
      tmp113 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 847
type: ALGORITHM

  assert(BsPB.use >= BioChem.Types.StateVariable.c and BsPB.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPB.use <= BioChem.Types.StateVariable.n, has value: " + String(BsPB.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_847(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,847};
  modelica_boolean tmp114;
  modelica_boolean tmp115;
  static const MMC_DEFSTRINGLIT(tmp116,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPB.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp117;
  modelica_metatype tmpMeta118;
  static int tmp119 = 0;
  if(!tmp119)
  {
    tmp114 = GreaterEq((data->simulationInfo->integerParameter[27] /* BsPB.use PARAM */),1);
    tmp115 = LessEq((data->simulationInfo->integerParameter[27] /* BsPB.use PARAM */),2);
    if(!(tmp114 && tmp115))
    {
      tmp117 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[27] /* BsPB.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta118 = stringAppend(MMC_REFSTRINGLIT(tmp116),tmp117);
      {
        const char* assert_cond = "(BsPB.use >= BioChem.Types.StateVariable.c and BsPB.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta118));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta118));
        }
      }
      tmp119 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 848
type: ALGORITHM

  assert(BsPrs.use >= BioChem.Types.StateVariable.c and BsPrs.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrs.use <= BioChem.Types.StateVariable.n, has value: " + String(BsPrs.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_848(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,848};
  modelica_boolean tmp120;
  modelica_boolean tmp121;
  static const MMC_DEFSTRINGLIT(tmp122,127,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BsPrs.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp123;
  modelica_metatype tmpMeta124;
  static int tmp125 = 0;
  if(!tmp125)
  {
    tmp120 = GreaterEq((data->simulationInfo->integerParameter[28] /* BsPrs.use PARAM */),1);
    tmp121 = LessEq((data->simulationInfo->integerParameter[28] /* BsPrs.use PARAM */),2);
    if(!(tmp120 && tmp121))
    {
      tmp123 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[28] /* BsPrs.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta124 = stringAppend(MMC_REFSTRINGLIT(tmp122),tmp123);
      {
        const char* assert_cond = "(BsPrs.use >= BioChem.Types.StateVariable.c and BsPrs.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta124));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta124));
        }
      }
      tmp125 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 849
type: ALGORITHM

  assert(AsPrs.use >= BioChem.Types.StateVariable.c and AsPrs.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrs.use <= BioChem.Types.StateVariable.n, has value: " + String(AsPrs.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_849(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,849};
  modelica_boolean tmp126;
  modelica_boolean tmp127;
  static const MMC_DEFSTRINGLIT(tmp128,127,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsPrs.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp129;
  modelica_metatype tmpMeta130;
  static int tmp131 = 0;
  if(!tmp131)
  {
    tmp126 = GreaterEq((data->simulationInfo->integerParameter[14] /* AsPrs.use PARAM */),1);
    tmp127 = LessEq((data->simulationInfo->integerParameter[14] /* AsPrs.use PARAM */),2);
    if(!(tmp126 && tmp127))
    {
      tmp129 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[14] /* AsPrs.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta130 = stringAppend(MMC_REFSTRINGLIT(tmp128),tmp129);
      {
        const char* assert_cond = "(AsPrs.use >= BioChem.Types.StateVariable.c and AsPrs.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta130));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta130));
        }
      }
      tmp131 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 850
type: ALGORITHM

  assert(AaPra.use >= BioChem.Types.StateVariable.c and AaPra.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPra.use <= BioChem.Types.StateVariable.n, has value: " + String(AaPra.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_850(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,850};
  modelica_boolean tmp132;
  modelica_boolean tmp133;
  static const MMC_DEFSTRINGLIT(tmp134,127,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaPra.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp135;
  modelica_metatype tmpMeta136;
  static int tmp137 = 0;
  if(!tmp137)
  {
    tmp132 = GreaterEq((data->simulationInfo->integerParameter[6] /* AaPra.use PARAM */),1);
    tmp133 = LessEq((data->simulationInfo->integerParameter[6] /* AaPra.use PARAM */),2);
    if(!(tmp132 && tmp133))
    {
      tmp135 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[6] /* AaPra.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta136 = stringAppend(MMC_REFSTRINGLIT(tmp134),tmp135);
      {
        const char* assert_cond = "(AaPra.use >= BioChem.Types.StateVariable.c and AaPra.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta136));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta136));
        }
      }
      tmp137 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 851
type: ALGORITHM

  assert(BaPra.use >= BioChem.Types.StateVariable.c and BaPra.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPra.use <= BioChem.Types.StateVariable.n, has value: " + String(BaPra.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_851(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,851};
  modelica_boolean tmp138;
  modelica_boolean tmp139;
  static const MMC_DEFSTRINGLIT(tmp140,127,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaPra.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp141;
  modelica_metatype tmpMeta142;
  static int tmp143 = 0;
  if(!tmp143)
  {
    tmp138 = GreaterEq((data->simulationInfo->integerParameter[22] /* BaPra.use PARAM */),1);
    tmp139 = LessEq((data->simulationInfo->integerParameter[22] /* BaPra.use PARAM */),2);
    if(!(tmp138 && tmp139))
    {
      tmp141 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[22] /* BaPra.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta142 = stringAppend(MMC_REFSTRINGLIT(tmp140),tmp141);
      {
        const char* assert_cond = "(BaPra.use >= BioChem.Types.StateVariable.c and BaPra.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta142));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta142));
        }
      }
      tmp143 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 852
type: ALGORITHM

  assert(BaBsPoly.use >= BioChem.Types.StateVariable.c and BaBsPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaBsPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(BaBsPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_852(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,852};
  modelica_boolean tmp144;
  modelica_boolean tmp145;
  static const MMC_DEFSTRINGLIT(tmp146,130,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaBsPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp147;
  modelica_metatype tmpMeta148;
  static int tmp149 = 0;
  if(!tmp149)
  {
    tmp144 = GreaterEq((data->simulationInfo->integerParameter[20] /* BaBsPoly.use PARAM */),1);
    tmp145 = LessEq((data->simulationInfo->integerParameter[20] /* BaBsPoly.use PARAM */),2);
    if(!(tmp144 && tmp145))
    {
      tmp147 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[20] /* BaBsPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta148 = stringAppend(MMC_REFSTRINGLIT(tmp146),tmp147);
      {
        const char* assert_cond = "(BaBsPoly.use >= BioChem.Types.StateVariable.c and BaBsPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta148));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta148));
        }
      }
      tmp149 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 853
type: ALGORITHM

  assert(AaAsPoly.use >= BioChem.Types.StateVariable.c and AaAsPoly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaAsPoly.use <= BioChem.Types.StateVariable.n, has value: " + String(AaAsPoly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_853(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,853};
  modelica_boolean tmp150;
  modelica_boolean tmp151;
  static const MMC_DEFSTRINGLIT(tmp152,130,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaAsPoly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp153;
  modelica_metatype tmpMeta154;
  static int tmp155 = 0;
  if(!tmp155)
  {
    tmp150 = GreaterEq((data->simulationInfo->integerParameter[2] /* AaAsPoly.use PARAM */),1);
    tmp151 = LessEq((data->simulationInfo->integerParameter[2] /* AaAsPoly.use PARAM */),2);
    if(!(tmp150 && tmp151))
    {
      tmp153 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[2] /* AaAsPoly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta154 = stringAppend(MMC_REFSTRINGLIT(tmp152),tmp153);
      {
        const char* assert_cond = "(AaAsPoly.use >= BioChem.Types.StateVariable.c and AaAsPoly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta154));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta154));
        }
      }
      tmp155 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 854
type: ALGORITHM

  assert(AaAs.use >= BioChem.Types.StateVariable.c and AaAs.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaAs.use <= BioChem.Types.StateVariable.n, has value: " + String(AaAs.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_854(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,854};
  modelica_boolean tmp156;
  modelica_boolean tmp157;
  static const MMC_DEFSTRINGLIT(tmp158,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaAs.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp159;
  modelica_metatype tmpMeta160;
  static int tmp161 = 0;
  if(!tmp161)
  {
    tmp156 = GreaterEq((data->simulationInfo->integerParameter[1] /* AaAs.use PARAM */),1);
    tmp157 = LessEq((data->simulationInfo->integerParameter[1] /* AaAs.use PARAM */),2);
    if(!(tmp156 && tmp157))
    {
      tmp159 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[1] /* AaAs.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta160 = stringAppend(MMC_REFSTRINGLIT(tmp158),tmp159);
      {
        const char* assert_cond = "(AaAs.use >= BioChem.Types.StateVariable.c and AaAs.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta160));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta160));
        }
      }
      tmp161 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 855
type: ALGORITHM

  assert(BaBs.use >= BioChem.Types.StateVariable.c and BaBs.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaBs.use <= BioChem.Types.StateVariable.n, has value: " + String(BaBs.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_855(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,855};
  modelica_boolean tmp162;
  modelica_boolean tmp163;
  static const MMC_DEFSTRINGLIT(tmp164,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= BaBs.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp165;
  modelica_metatype tmpMeta166;
  static int tmp167 = 0;
  if(!tmp167)
  {
    tmp162 = GreaterEq((data->simulationInfo->integerParameter[19] /* BaBs.use PARAM */),1);
    tmp163 = LessEq((data->simulationInfo->integerParameter[19] /* BaBs.use PARAM */),2);
    if(!(tmp162 && tmp163))
    {
      tmp165 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[19] /* BaBs.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta166 = stringAppend(MMC_REFSTRINGLIT(tmp164),tmp165);
      {
        const char* assert_cond = "(BaBs.use >= BioChem.Types.StateVariable.c and BaBs.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta166));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta166));
        }
      }
      tmp167 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 856
type: ALGORITHM

  assert(AaBs.use >= BioChem.Types.StateVariable.c and AaBs.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaBs.use <= BioChem.Types.StateVariable.n, has value: " + String(AaBs.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_856(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,856};
  modelica_boolean tmp168;
  modelica_boolean tmp169;
  static const MMC_DEFSTRINGLIT(tmp170,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AaBs.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp171;
  modelica_metatype tmpMeta172;
  static int tmp173 = 0;
  if(!tmp173)
  {
    tmp168 = GreaterEq((data->simulationInfo->integerParameter[3] /* AaBs.use PARAM */),1);
    tmp169 = LessEq((data->simulationInfo->integerParameter[3] /* AaBs.use PARAM */),2);
    if(!(tmp168 && tmp169))
    {
      tmp171 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[3] /* AaBs.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta172 = stringAppend(MMC_REFSTRINGLIT(tmp170),tmp171);
      {
        const char* assert_cond = "(AaBs.use >= BioChem.Types.StateVariable.c and AaBs.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta172));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta172));
        }
      }
      tmp173 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 857
type: ALGORITHM

  assert(AsBa.use >= BioChem.Types.StateVariable.c and AsBa.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsBa.use <= BioChem.Types.StateVariable.n, has value: " + String(AsBa.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_857(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,857};
  modelica_boolean tmp174;
  modelica_boolean tmp175;
  static const MMC_DEFSTRINGLIT(tmp176,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= AsBa.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp177;
  modelica_metatype tmpMeta178;
  static int tmp179 = 0;
  if(!tmp179)
  {
    tmp174 = GreaterEq((data->simulationInfo->integerParameter[11] /* AsBa.use PARAM */),1);
    tmp175 = LessEq((data->simulationInfo->integerParameter[11] /* AsBa.use PARAM */),2);
    if(!(tmp174 && tmp175))
    {
      tmp177 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[11] /* AsBa.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta178 = stringAppend(MMC_REFSTRINGLIT(tmp176),tmp177);
      {
        const char* assert_cond = "(AsBa.use >= BioChem.Types.StateVariable.c and AsBa.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta178));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta178));
        }
      }
      tmp179 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 858
type: ALGORITHM

  assert(Poly.use >= BioChem.Types.StateVariable.c and Poly.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Poly.use <= BioChem.Types.StateVariable.n, has value: " + String(Poly.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_858(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,858};
  modelica_boolean tmp180;
  modelica_boolean tmp181;
  static const MMC_DEFSTRINGLIT(tmp182,126,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Poly.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp183;
  modelica_metatype tmpMeta184;
  static int tmp185 = 0;
  if(!tmp185)
  {
    tmp180 = GreaterEq((data->simulationInfo->integerParameter[34] /* Poly.use PARAM */),1);
    tmp181 = LessEq((data->simulationInfo->integerParameter[34] /* Poly.use PARAM */),2);
    if(!(tmp180 && tmp181))
    {
      tmp183 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[34] /* Poly.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta184 = stringAppend(MMC_REFSTRINGLIT(tmp182),tmp183);
      {
        const char* assert_cond = "(Poly.use >= BioChem.Types.StateVariable.c and Poly.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta184));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta184));
        }
      }
      tmp185 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 859
type: ALGORITHM

  assert(PB.use >= BioChem.Types.StateVariable.c and PB.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= PB.use <= BioChem.Types.StateVariable.n, has value: " + String(PB.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_859(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,859};
  modelica_boolean tmp186;
  modelica_boolean tmp187;
  static const MMC_DEFSTRINGLIT(tmp188,124,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= PB.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp189;
  modelica_metatype tmpMeta190;
  static int tmp191 = 0;
  if(!tmp191)
  {
    tmp186 = GreaterEq((data->simulationInfo->integerParameter[33] /* PB.use PARAM */),1);
    tmp187 = LessEq((data->simulationInfo->integerParameter[33] /* PB.use PARAM */),2);
    if(!(tmp186 && tmp187))
    {
      tmp189 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[33] /* PB.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta190 = stringAppend(MMC_REFSTRINGLIT(tmp188),tmp189);
      {
        const char* assert_cond = "(PB.use >= BioChem.Types.StateVariable.c and PB.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta190));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta190));
        }
      }
      tmp191 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 860
type: ALGORITHM

  assert(PA.use >= BioChem.Types.StateVariable.c and PA.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= PA.use <= BioChem.Types.StateVariable.n, has value: " + String(PA.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_860(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,860};
  modelica_boolean tmp192;
  modelica_boolean tmp193;
  static const MMC_DEFSTRINGLIT(tmp194,124,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= PA.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp195;
  modelica_metatype tmpMeta196;
  static int tmp197 = 0;
  if(!tmp197)
  {
    tmp192 = GreaterEq((data->simulationInfo->integerParameter[32] /* PA.use PARAM */),1);
    tmp193 = LessEq((data->simulationInfo->integerParameter[32] /* PA.use PARAM */),2);
    if(!(tmp192 && tmp193))
    {
      tmp195 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[32] /* PA.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta196 = stringAppend(MMC_REFSTRINGLIT(tmp194),tmp195);
      {
        const char* assert_cond = "(PA.use >= BioChem.Types.StateVariable.c and PA.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta196));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta196));
        }
      }
      tmp197 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 861
type: ALGORITHM

  assert(Pra.use >= BioChem.Types.StateVariable.c and Pra.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Pra.use <= BioChem.Types.StateVariable.n, has value: " + String(Pra.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_861(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,861};
  modelica_boolean tmp198;
  modelica_boolean tmp199;
  static const MMC_DEFSTRINGLIT(tmp200,125,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Pra.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp201;
  modelica_metatype tmpMeta202;
  static int tmp203 = 0;
  if(!tmp203)
  {
    tmp198 = GreaterEq((data->simulationInfo->integerParameter[35] /* Pra.use PARAM */),1);
    tmp199 = LessEq((data->simulationInfo->integerParameter[35] /* Pra.use PARAM */),2);
    if(!(tmp198 && tmp199))
    {
      tmp201 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[35] /* Pra.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta202 = stringAppend(MMC_REFSTRINGLIT(tmp200),tmp201);
      {
        const char* assert_cond = "(Pra.use >= BioChem.Types.StateVariable.c and Pra.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta202));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta202));
        }
      }
      tmp203 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 862
type: ALGORITHM

  assert(Prs.use >= BioChem.Types.StateVariable.c and Prs.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Prs.use <= BioChem.Types.StateVariable.n, has value: " + String(Prs.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_862(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,862};
  modelica_boolean tmp204;
  modelica_boolean tmp205;
  static const MMC_DEFSTRINGLIT(tmp206,125,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Prs.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp207;
  modelica_metatype tmpMeta208;
  static int tmp209 = 0;
  if(!tmp209)
  {
    tmp204 = GreaterEq((data->simulationInfo->integerParameter[36] /* Prs.use PARAM */),1);
    tmp205 = LessEq((data->simulationInfo->integerParameter[36] /* Prs.use PARAM */),2);
    if(!(tmp204 && tmp205))
    {
      tmp207 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[36] /* Prs.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta208 = stringAppend(MMC_REFSTRINGLIT(tmp206),tmp207);
      {
        const char* assert_cond = "(Prs.use >= BioChem.Types.StateVariable.c and Prs.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta208));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta208));
        }
      }
      tmp209 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 863
type: ALGORITHM

  assert(Ba.use >= BioChem.Types.StateVariable.c and Ba.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Ba.use <= BioChem.Types.StateVariable.n, has value: " + String(Ba.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_863(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,863};
  modelica_boolean tmp210;
  modelica_boolean tmp211;
  static const MMC_DEFSTRINGLIT(tmp212,124,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Ba.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp213;
  modelica_metatype tmpMeta214;
  static int tmp215 = 0;
  if(!tmp215)
  {
    tmp210 = GreaterEq((data->simulationInfo->integerParameter[18] /* Ba.use PARAM */),1);
    tmp211 = LessEq((data->simulationInfo->integerParameter[18] /* Ba.use PARAM */),2);
    if(!(tmp210 && tmp211))
    {
      tmp213 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[18] /* Ba.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta214 = stringAppend(MMC_REFSTRINGLIT(tmp212),tmp213);
      {
        const char* assert_cond = "(Ba.use >= BioChem.Types.StateVariable.c and Ba.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta214));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta214));
        }
      }
      tmp215 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 864
type: ALGORITHM

  assert(Bs.use >= BioChem.Types.StateVariable.c and Bs.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Bs.use <= BioChem.Types.StateVariable.n, has value: " + String(Bs.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_864(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,864};
  modelica_boolean tmp216;
  modelica_boolean tmp217;
  static const MMC_DEFSTRINGLIT(tmp218,124,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Bs.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp219;
  modelica_metatype tmpMeta220;
  static int tmp221 = 0;
  if(!tmp221)
  {
    tmp216 = GreaterEq((data->simulationInfo->integerParameter[26] /* Bs.use PARAM */),1);
    tmp217 = LessEq((data->simulationInfo->integerParameter[26] /* Bs.use PARAM */),2);
    if(!(tmp216 && tmp217))
    {
      tmp219 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[26] /* Bs.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta220 = stringAppend(MMC_REFSTRINGLIT(tmp218),tmp219);
      {
        const char* assert_cond = "(Bs.use >= BioChem.Types.StateVariable.c and Bs.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta220));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta220));
        }
      }
      tmp221 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 865
type: ALGORITHM

  assert(Aa.use >= BioChem.Types.StateVariable.c and Aa.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Aa.use <= BioChem.Types.StateVariable.n, has value: " + String(Aa.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_865(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,865};
  modelica_boolean tmp222;
  modelica_boolean tmp223;
  static const MMC_DEFSTRINGLIT(tmp224,124,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= Aa.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp225;
  modelica_metatype tmpMeta226;
  static int tmp227 = 0;
  if(!tmp227)
  {
    tmp222 = GreaterEq((data->simulationInfo->integerParameter[0] /* Aa.use PARAM */),1);
    tmp223 = LessEq((data->simulationInfo->integerParameter[0] /* Aa.use PARAM */),2);
    if(!(tmp222 && tmp223))
    {
      tmp225 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[0] /* Aa.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta226 = stringAppend(MMC_REFSTRINGLIT(tmp224),tmp225);
      {
        const char* assert_cond = "(Aa.use >= BioChem.Types.StateVariable.c and Aa.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta226));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta226));
        }
      }
      tmp227 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 866
type: ALGORITHM

  assert(As.use >= BioChem.Types.StateVariable.c and As.use <= BioChem.Types.StateVariable.n, "Variable violating min/max constraint: BioChem.Types.StateVariable.c <= As.use <= BioChem.Types.StateVariable.n, has value: " + String(As.use, "d"));
*/
OMC_DISABLE_OPT
static void rPCR_03_eqFunction_866(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,866};
  modelica_boolean tmp228;
  modelica_boolean tmp229;
  static const MMC_DEFSTRINGLIT(tmp230,124,"Variable violating min/max constraint: BioChem.Types.StateVariable.c <= As.use <= BioChem.Types.StateVariable.n, has value: ");
  modelica_string tmp231;
  modelica_metatype tmpMeta232;
  static int tmp233 = 0;
  if(!tmp233)
  {
    tmp228 = GreaterEq((data->simulationInfo->integerParameter[10] /* As.use PARAM */),1);
    tmp229 = LessEq((data->simulationInfo->integerParameter[10] /* As.use PARAM */),2);
    if(!(tmp228 && tmp229))
    {
      tmp231 = modelica_integer_to_modelica_string_format((data->simulationInfo->integerParameter[10] /* As.use PARAM */), (modelica_string) mmc_strings_len1[100]);
      tmpMeta232 = stringAppend(MMC_REFSTRINGLIT(tmp230),tmp231);
      {
        const char* assert_cond = "(As.use >= BioChem.Types.StateVariable.c and As.use <= BioChem.Types.StateVariable.n)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta232));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",9,3,9,205,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta232));
        }
      }
      tmp233 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void rPCR_03_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  rPCR_03_eqFunction_558(data, threadData);
  rPCR_03_eqFunction_559(data, threadData);
  rPCR_03_eqFunction_560(data, threadData);
  rPCR_03_eqFunction_562(data, threadData);
  rPCR_03_eqFunction_563(data, threadData);
  rPCR_03_eqFunction_564(data, threadData);
  rPCR_03_eqFunction_565(data, threadData);
  rPCR_03_eqFunction_566(data, threadData);
  rPCR_03_eqFunction_567(data, threadData);
  rPCR_03_eqFunction_568(data, threadData);
  rPCR_03_eqFunction_569(data, threadData);
  rPCR_03_eqFunction_570(data, threadData);
  rPCR_03_eqFunction_571(data, threadData);
  rPCR_03_eqFunction_574(data, threadData);
  rPCR_03_eqFunction_575(data, threadData);
  rPCR_03_eqFunction_576(data, threadData);
  rPCR_03_eqFunction_578(data, threadData);
  rPCR_03_eqFunction_579(data, threadData);
  rPCR_03_eqFunction_580(data, threadData);
  rPCR_03_eqFunction_581(data, threadData);
  rPCR_03_eqFunction_582(data, threadData);
  rPCR_03_eqFunction_583(data, threadData);
  rPCR_03_eqFunction_584(data, threadData);
  rPCR_03_eqFunction_585(data, threadData);
  rPCR_03_eqFunction_588(data, threadData);
  rPCR_03_eqFunction_589(data, threadData);
  rPCR_03_eqFunction_590(data, threadData);
  rPCR_03_eqFunction_591(data, threadData);
  rPCR_03_eqFunction_592(data, threadData);
  rPCR_03_eqFunction_593(data, threadData);
  rPCR_03_eqFunction_594(data, threadData);
  rPCR_03_eqFunction_595(data, threadData);
  rPCR_03_eqFunction_596(data, threadData);
  rPCR_03_eqFunction_597(data, threadData);
  rPCR_03_eqFunction_598(data, threadData);
  rPCR_03_eqFunction_599(data, threadData);
  rPCR_03_eqFunction_600(data, threadData);
  rPCR_03_eqFunction_601(data, threadData);
  rPCR_03_eqFunction_602(data, threadData);
  rPCR_03_eqFunction_603(data, threadData);
  rPCR_03_eqFunction_604(data, threadData);
  rPCR_03_eqFunction_605(data, threadData);
  rPCR_03_eqFunction_606(data, threadData);
  rPCR_03_eqFunction_607(data, threadData);
  rPCR_03_eqFunction_608(data, threadData);
  rPCR_03_eqFunction_609(data, threadData);
  rPCR_03_eqFunction_610(data, threadData);
  rPCR_03_eqFunction_611(data, threadData);
  rPCR_03_eqFunction_612(data, threadData);
  rPCR_03_eqFunction_613(data, threadData);
  rPCR_03_eqFunction_614(data, threadData);
  rPCR_03_eqFunction_615(data, threadData);
  rPCR_03_eqFunction_616(data, threadData);
  rPCR_03_eqFunction_617(data, threadData);
  rPCR_03_eqFunction_618(data, threadData);
  rPCR_03_eqFunction_619(data, threadData);
  rPCR_03_eqFunction_620(data, threadData);
  rPCR_03_eqFunction_621(data, threadData);
  rPCR_03_eqFunction_622(data, threadData);
  rPCR_03_eqFunction_623(data, threadData);
  rPCR_03_eqFunction_624(data, threadData);
  rPCR_03_eqFunction_625(data, threadData);
  rPCR_03_eqFunction_626(data, threadData);
  rPCR_03_eqFunction_627(data, threadData);
  rPCR_03_eqFunction_628(data, threadData);
  rPCR_03_eqFunction_629(data, threadData);
  rPCR_03_eqFunction_630(data, threadData);
  rPCR_03_eqFunction_631(data, threadData);
  rPCR_03_eqFunction_632(data, threadData);
  rPCR_03_eqFunction_633(data, threadData);
  rPCR_03_eqFunction_634(data, threadData);
  rPCR_03_eqFunction_635(data, threadData);
  rPCR_03_eqFunction_636(data, threadData);
  rPCR_03_eqFunction_637(data, threadData);
  rPCR_03_eqFunction_638(data, threadData);
  rPCR_03_eqFunction_639(data, threadData);
  rPCR_03_eqFunction_640(data, threadData);
  rPCR_03_eqFunction_641(data, threadData);
  rPCR_03_eqFunction_642(data, threadData);
  rPCR_03_eqFunction_643(data, threadData);
  rPCR_03_eqFunction_644(data, threadData);
  rPCR_03_eqFunction_645(data, threadData);
  rPCR_03_eqFunction_646(data, threadData);
  rPCR_03_eqFunction_647(data, threadData);
  rPCR_03_eqFunction_648(data, threadData);
  rPCR_03_eqFunction_649(data, threadData);
  rPCR_03_eqFunction_650(data, threadData);
  rPCR_03_eqFunction_651(data, threadData);
  rPCR_03_eqFunction_652(data, threadData);
  rPCR_03_eqFunction_653(data, threadData);
  rPCR_03_eqFunction_654(data, threadData);
  rPCR_03_eqFunction_655(data, threadData);
  rPCR_03_eqFunction_656(data, threadData);
  rPCR_03_eqFunction_657(data, threadData);
  rPCR_03_eqFunction_658(data, threadData);
  rPCR_03_eqFunction_659(data, threadData);
  rPCR_03_eqFunction_660(data, threadData);
  rPCR_03_eqFunction_661(data, threadData);
  rPCR_03_eqFunction_662(data, threadData);
  rPCR_03_eqFunction_663(data, threadData);
  rPCR_03_eqFunction_664(data, threadData);
  rPCR_03_eqFunction_665(data, threadData);
  rPCR_03_eqFunction_666(data, threadData);
  rPCR_03_eqFunction_667(data, threadData);
  rPCR_03_eqFunction_668(data, threadData);
  rPCR_03_eqFunction_669(data, threadData);
  rPCR_03_eqFunction_125(data, threadData);
  rPCR_03_eqFunction_124(data, threadData);
  rPCR_03_eqFunction_123(data, threadData);
  rPCR_03_eqFunction_122(data, threadData);
  rPCR_03_eqFunction_121(data, threadData);
  rPCR_03_eqFunction_120(data, threadData);
  rPCR_03_eqFunction_119(data, threadData);
  rPCR_03_eqFunction_118(data, threadData);
  rPCR_03_eqFunction_117(data, threadData);
  rPCR_03_eqFunction_116(data, threadData);
  rPCR_03_eqFunction_115(data, threadData);
  rPCR_03_eqFunction_114(data, threadData);
  rPCR_03_eqFunction_113(data, threadData);
  rPCR_03_eqFunction_112(data, threadData);
  rPCR_03_eqFunction_111(data, threadData);
  rPCR_03_eqFunction_110(data, threadData);
  rPCR_03_eqFunction_109(data, threadData);
  rPCR_03_eqFunction_108(data, threadData);
  rPCR_03_eqFunction_107(data, threadData);
  rPCR_03_eqFunction_106(data, threadData);
  rPCR_03_eqFunction_105(data, threadData);
  rPCR_03_eqFunction_104(data, threadData);
  rPCR_03_eqFunction_103(data, threadData);
  rPCR_03_eqFunction_102(data, threadData);
  rPCR_03_eqFunction_101(data, threadData);
  rPCR_03_eqFunction_100(data, threadData);
  rPCR_03_eqFunction_99(data, threadData);
  rPCR_03_eqFunction_98(data, threadData);
  rPCR_03_eqFunction_97(data, threadData);
  rPCR_03_eqFunction_96(data, threadData);
  rPCR_03_eqFunction_95(data, threadData);
  rPCR_03_eqFunction_94(data, threadData);
  rPCR_03_eqFunction_93(data, threadData);
  rPCR_03_eqFunction_92(data, threadData);
  rPCR_03_eqFunction_91(data, threadData);
  rPCR_03_eqFunction_90(data, threadData);
  rPCR_03_eqFunction_89(data, threadData);
  rPCR_03_eqFunction_88(data, threadData);
  rPCR_03_eqFunction_87(data, threadData);
  rPCR_03_eqFunction_86(data, threadData);
  rPCR_03_eqFunction_85(data, threadData);
  rPCR_03_eqFunction_84(data, threadData);
  rPCR_03_eqFunction_83(data, threadData);
  rPCR_03_eqFunction_82(data, threadData);
  rPCR_03_eqFunction_81(data, threadData);
  rPCR_03_eqFunction_80(data, threadData);
  rPCR_03_eqFunction_79(data, threadData);
  rPCR_03_eqFunction_78(data, threadData);
  rPCR_03_eqFunction_77(data, threadData);
  rPCR_03_eqFunction_76(data, threadData);
  rPCR_03_eqFunction_75(data, threadData);
  rPCR_03_eqFunction_74(data, threadData);
  rPCR_03_eqFunction_73(data, threadData);
  rPCR_03_eqFunction_72(data, threadData);
  rPCR_03_eqFunction_71(data, threadData);
  rPCR_03_eqFunction_70(data, threadData);
  rPCR_03_eqFunction_69(data, threadData);
  rPCR_03_eqFunction_68(data, threadData);
  rPCR_03_eqFunction_67(data, threadData);
  rPCR_03_eqFunction_66(data, threadData);
  rPCR_03_eqFunction_65(data, threadData);
  rPCR_03_eqFunction_64(data, threadData);
  rPCR_03_eqFunction_63(data, threadData);
  rPCR_03_eqFunction_62(data, threadData);
  rPCR_03_eqFunction_61(data, threadData);
  rPCR_03_eqFunction_60(data, threadData);
  rPCR_03_eqFunction_59(data, threadData);
  rPCR_03_eqFunction_58(data, threadData);
  rPCR_03_eqFunction_57(data, threadData);
  rPCR_03_eqFunction_56(data, threadData);
  rPCR_03_eqFunction_55(data, threadData);
  rPCR_03_eqFunction_54(data, threadData);
  rPCR_03_eqFunction_53(data, threadData);
  rPCR_03_eqFunction_52(data, threadData);
  rPCR_03_eqFunction_51(data, threadData);
  rPCR_03_eqFunction_50(data, threadData);
  rPCR_03_eqFunction_49(data, threadData);
  rPCR_03_eqFunction_48(data, threadData);
  rPCR_03_eqFunction_47(data, threadData);
  rPCR_03_eqFunction_46(data, threadData);
  rPCR_03_eqFunction_45(data, threadData);
  rPCR_03_eqFunction_44(data, threadData);
  rPCR_03_eqFunction_43(data, threadData);
  rPCR_03_eqFunction_42(data, threadData);
  rPCR_03_eqFunction_41(data, threadData);
  rPCR_03_eqFunction_40(data, threadData);
  rPCR_03_eqFunction_39(data, threadData);
  rPCR_03_eqFunction_38(data, threadData);
  rPCR_03_eqFunction_37(data, threadData);
  rPCR_03_eqFunction_36(data, threadData);
  rPCR_03_eqFunction_35(data, threadData);
  rPCR_03_eqFunction_34(data, threadData);
  rPCR_03_eqFunction_33(data, threadData);
  rPCR_03_eqFunction_32(data, threadData);
  rPCR_03_eqFunction_31(data, threadData);
  rPCR_03_eqFunction_30(data, threadData);
  rPCR_03_eqFunction_29(data, threadData);
  rPCR_03_eqFunction_28(data, threadData);
  rPCR_03_eqFunction_27(data, threadData);
  rPCR_03_eqFunction_26(data, threadData);
  rPCR_03_eqFunction_25(data, threadData);
  rPCR_03_eqFunction_24(data, threadData);
  rPCR_03_eqFunction_23(data, threadData);
  rPCR_03_eqFunction_22(data, threadData);
  rPCR_03_eqFunction_21(data, threadData);
  rPCR_03_eqFunction_20(data, threadData);
  rPCR_03_eqFunction_19(data, threadData);
  rPCR_03_eqFunction_18(data, threadData);
  rPCR_03_eqFunction_17(data, threadData);
  rPCR_03_eqFunction_16(data, threadData);
  rPCR_03_eqFunction_15(data, threadData);
  rPCR_03_eqFunction_14(data, threadData);
  rPCR_03_eqFunction_13(data, threadData);
  rPCR_03_eqFunction_12(data, threadData);
  rPCR_03_eqFunction_11(data, threadData);
  rPCR_03_eqFunction_10(data, threadData);
  rPCR_03_eqFunction_9(data, threadData);
  rPCR_03_eqFunction_8(data, threadData);
  rPCR_03_eqFunction_7(data, threadData);
  rPCR_03_eqFunction_6(data, threadData);
  rPCR_03_eqFunction_5(data, threadData);
  rPCR_03_eqFunction_4(data, threadData);
  rPCR_03_eqFunction_3(data, threadData);
  rPCR_03_eqFunction_2(data, threadData);
  rPCR_03_eqFunction_1(data, threadData);
  rPCR_03_eqFunction_828(data, threadData);
  rPCR_03_eqFunction_829(data, threadData);
  rPCR_03_eqFunction_830(data, threadData);
  rPCR_03_eqFunction_831(data, threadData);
  rPCR_03_eqFunction_832(data, threadData);
  rPCR_03_eqFunction_833(data, threadData);
  rPCR_03_eqFunction_834(data, threadData);
  rPCR_03_eqFunction_835(data, threadData);
  rPCR_03_eqFunction_836(data, threadData);
  rPCR_03_eqFunction_837(data, threadData);
  rPCR_03_eqFunction_838(data, threadData);
  rPCR_03_eqFunction_839(data, threadData);
  rPCR_03_eqFunction_840(data, threadData);
  rPCR_03_eqFunction_841(data, threadData);
  rPCR_03_eqFunction_842(data, threadData);
  rPCR_03_eqFunction_843(data, threadData);
  rPCR_03_eqFunction_844(data, threadData);
  rPCR_03_eqFunction_845(data, threadData);
  rPCR_03_eqFunction_846(data, threadData);
  rPCR_03_eqFunction_847(data, threadData);
  rPCR_03_eqFunction_848(data, threadData);
  rPCR_03_eqFunction_849(data, threadData);
  rPCR_03_eqFunction_850(data, threadData);
  rPCR_03_eqFunction_851(data, threadData);
  rPCR_03_eqFunction_852(data, threadData);
  rPCR_03_eqFunction_853(data, threadData);
  rPCR_03_eqFunction_854(data, threadData);
  rPCR_03_eqFunction_855(data, threadData);
  rPCR_03_eqFunction_856(data, threadData);
  rPCR_03_eqFunction_857(data, threadData);
  rPCR_03_eqFunction_858(data, threadData);
  rPCR_03_eqFunction_859(data, threadData);
  rPCR_03_eqFunction_860(data, threadData);
  rPCR_03_eqFunction_861(data, threadData);
  rPCR_03_eqFunction_862(data, threadData);
  rPCR_03_eqFunction_863(data, threadData);
  rPCR_03_eqFunction_864(data, threadData);
  rPCR_03_eqFunction_865(data, threadData);
  rPCR_03_eqFunction_866(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int rPCR_03_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  (data->simulationInfo->integerParameter[0]/* Aa.use PARAM */) = 1;
  data->modelData->integerParameterData[0].time_unvarying = 1;
  (data->simulationInfo->integerParameter[1]/* AaAs.use PARAM */) = 1;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  (data->simulationInfo->integerParameter[2]/* AaAsPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[2].time_unvarying = 1;
  (data->simulationInfo->integerParameter[3]/* AaBs.use PARAM */) = 1;
  data->modelData->integerParameterData[3].time_unvarying = 1;
  (data->simulationInfo->integerParameter[4]/* AaBsPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[4].time_unvarying = 1;
  (data->simulationInfo->integerParameter[5]/* AaPB.use PARAM */) = 1;
  data->modelData->integerParameterData[5].time_unvarying = 1;
  (data->simulationInfo->integerParameter[6]/* AaPra.use PARAM */) = 1;
  data->modelData->integerParameterData[6].time_unvarying = 1;
  (data->simulationInfo->integerParameter[7]/* AaPraPB.use PARAM */) = 1;
  data->modelData->integerParameterData[7].time_unvarying = 1;
  (data->simulationInfo->integerParameter[8]/* AaPraPBPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[8].time_unvarying = 1;
  (data->simulationInfo->integerParameter[9]/* AaPraPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[9].time_unvarying = 1;
  (data->simulationInfo->integerParameter[10]/* As.use PARAM */) = 1;
  data->modelData->integerParameterData[10].time_unvarying = 1;
  (data->simulationInfo->integerParameter[11]/* AsBa.use PARAM */) = 1;
  data->modelData->integerParameterData[11].time_unvarying = 1;
  (data->simulationInfo->integerParameter[12]/* AsBaPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[12].time_unvarying = 1;
  (data->simulationInfo->integerParameter[13]/* AsPA.use PARAM */) = 1;
  data->modelData->integerParameterData[13].time_unvarying = 1;
  (data->simulationInfo->integerParameter[14]/* AsPrs.use PARAM */) = 1;
  data->modelData->integerParameterData[14].time_unvarying = 1;
  (data->simulationInfo->integerParameter[15]/* AsPrsPA.use PARAM */) = 1;
  data->modelData->integerParameterData[15].time_unvarying = 1;
  (data->simulationInfo->integerParameter[16]/* AsPrsPAPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[16].time_unvarying = 1;
  (data->simulationInfo->integerParameter[17]/* AsPrsPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[17].time_unvarying = 1;
  (data->simulationInfo->integerParameter[18]/* Ba.use PARAM */) = 1;
  data->modelData->integerParameterData[18].time_unvarying = 1;
  (data->simulationInfo->integerParameter[19]/* BaBs.use PARAM */) = 1;
  data->modelData->integerParameterData[19].time_unvarying = 1;
  (data->simulationInfo->integerParameter[20]/* BaBsPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[20].time_unvarying = 1;
  (data->simulationInfo->integerParameter[21]/* BaPA.use PARAM */) = 1;
  data->modelData->integerParameterData[21].time_unvarying = 1;
  (data->simulationInfo->integerParameter[22]/* BaPra.use PARAM */) = 1;
  data->modelData->integerParameterData[22].time_unvarying = 1;
  (data->simulationInfo->integerParameter[23]/* BaPraPA.use PARAM */) = 1;
  data->modelData->integerParameterData[23].time_unvarying = 1;
  (data->simulationInfo->integerParameter[24]/* BaPraPAPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[24].time_unvarying = 1;
  (data->simulationInfo->integerParameter[25]/* BaPraPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[25].time_unvarying = 1;
  (data->simulationInfo->integerParameter[26]/* Bs.use PARAM */) = 1;
  data->modelData->integerParameterData[26].time_unvarying = 1;
  (data->simulationInfo->integerParameter[27]/* BsPB.use PARAM */) = 1;
  data->modelData->integerParameterData[27].time_unvarying = 1;
  (data->simulationInfo->integerParameter[28]/* BsPrs.use PARAM */) = 1;
  data->modelData->integerParameterData[28].time_unvarying = 1;
  (data->simulationInfo->integerParameter[29]/* BsPrsPB.use PARAM */) = 1;
  data->modelData->integerParameterData[29].time_unvarying = 1;
  (data->simulationInfo->integerParameter[30]/* BsPrsPBPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[30].time_unvarying = 1;
  (data->simulationInfo->integerParameter[31]/* BsPrsPoly.use PARAM */) = 1;
  data->modelData->integerParameterData[31].time_unvarying = 1;
  (data->simulationInfo->integerParameter[32]/* PA.use PARAM */) = 1;
  data->modelData->integerParameterData[32].time_unvarying = 1;
  (data->simulationInfo->integerParameter[33]/* PB.use PARAM */) = 1;
  data->modelData->integerParameterData[33].time_unvarying = 1;
  (data->simulationInfo->integerParameter[34]/* Poly.use PARAM */) = 1;
  data->modelData->integerParameterData[34].time_unvarying = 1;
  (data->simulationInfo->integerParameter[35]/* Pra.use PARAM */) = 1;
  data->modelData->integerParameterData[35].time_unvarying = 1;
  (data->simulationInfo->integerParameter[36]/* Prs.use PARAM */) = 1;
  data->modelData->integerParameterData[36].time_unvarying = 1;
  (data->simulationInfo->integerParameter[37]/* signalA.use PARAM */) = 1;
  data->modelData->integerParameterData[37].time_unvarying = 1;
  (data->simulationInfo->integerParameter[38]/* signalB.use PARAM */) = 1;
  data->modelData->integerParameterData[38].time_unvarying = 1;
  rPCR_03_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

