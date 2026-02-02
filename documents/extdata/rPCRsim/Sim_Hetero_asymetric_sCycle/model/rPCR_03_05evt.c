/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "rPCR_03_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void rPCR_03_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
  /* sample 1 */
  data->modelData->samplesInfo[i].index = 1;
  data->modelData->samplesInfo[i].start = (data->simulationInfo->realParameter[210] /* cycle_time PARAM */);
  data->modelData->samplesInfo[i].interval = (data->simulationInfo->realParameter[210] /* cycle_time PARAM */) /* (max real for single time events) */;
  i++;
}

const char *rPCR_03_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"signalA.c * sFluoA > lFluoA",
  "signalB.c * sFluoB > lFluoB",
  "time > cycle_time * cycle_max"};
  static const int occurEqs0[] = {1,344};
  static const int occurEqs1[] = {1,343};
  static const int occurEqs2[] = {1,505};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
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

int rPCR_03_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  rPCR_03_eqFunction_342(data, threadData);

  rPCR_03_eqFunction_354(data, threadData);

  rPCR_03_eqFunction_355(data, threadData);

  rPCR_03_eqFunction_357(data, threadData);

  rPCR_03_eqFunction_358(data, threadData);

  rPCR_03_eqFunction_359(data, threadData);

  rPCR_03_eqFunction_362(data, threadData);

  rPCR_03_eqFunction_363(data, threadData);

  rPCR_03_eqFunction_365(data, threadData);

  rPCR_03_eqFunction_366(data, threadData);

  rPCR_03_eqFunction_367(data, threadData);

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

  rPCR_03_eqFunction_402(data, threadData);

  rPCR_03_eqFunction_404(data, threadData);

  rPCR_03_eqFunction_420(data, threadData);

  rPCR_03_eqFunction_422(data, threadData);

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
  
  TRACE_POP
  return 0;
}

int rPCR_03_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  start_index = current_index;
  tmp1 = (1e-6) * (fabs((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)));
  tmp2 = fabs((data->simulationInfo->realParameter[233] /* lFluoA PARAM */));
  tmp0 = GreaterZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)), (data->simulationInfo->realParameter[233] /* lFluoA PARAM */), tmp1, tmp2, data->simulationInfo->storedRelations[0]);
  gout[start_index] = (tmp0) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp4 = (1e-6) * (fabs((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)));
  tmp5 = fabs((data->simulationInfo->realParameter[234] /* lFluoB PARAM */));
  tmp3 = GreaterZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)), (data->simulationInfo->realParameter[234] /* lFluoB PARAM */), tmp4, tmp5, data->simulationInfo->storedRelations[1]);
  gout[start_index] = (tmp3) ? 1 : -1;
  current_index++;

  start_index = current_index;
  tmp7 = 1.0;
  tmp8 = (fabs((data->simulationInfo->realParameter[210] /* cycle_time PARAM */))) * (fabs((data->simulationInfo->realParameter[209] /* cycle_max PARAM */)));
  tmp6 = GreaterZC(data->localData[0]->timeValue, ((data->simulationInfo->realParameter[210] /* cycle_time PARAM */)) * ((data->simulationInfo->realParameter[209] /* cycle_max PARAM */)), tmp7, tmp8, data->simulationInfo->storedRelations[2]);
  gout[start_index] = (tmp6) ? 1 : -1;
  current_index++;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *rPCR_03_relationDescription(int i)
{
  const char *res[] = {"signalA.c * sFluoA > lFluoA",
  "signalB.c * sFluoB > lFluoB",
  "time > cycle_time * cycle_max"};
  return res[i];
}

int rPCR_03_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_boolean tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_integer current_index = 0;
  modelica_integer start_index;
  
  if(evalforZeroCross) {
    start_index = current_index;
    tmp10 = (1e-6) * (fabs((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)));
    tmp11 = fabs((data->simulationInfo->realParameter[233] /* lFluoA PARAM */));
    tmp9 = GreaterZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)), (data->simulationInfo->realParameter[233] /* lFluoA PARAM */), tmp10, tmp11, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[start_index] = tmp9;
    current_index++;

    start_index = current_index;
    tmp13 = (1e-6) * (fabs((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)));
    tmp14 = fabs((data->simulationInfo->realParameter[234] /* lFluoB PARAM */));
    tmp12 = GreaterZC(((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)), (data->simulationInfo->realParameter[234] /* lFluoB PARAM */), tmp13, tmp14, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[start_index] = tmp12;
    current_index++;

    start_index = current_index;
    tmp16 = 1.0;
    tmp17 = (fabs((data->simulationInfo->realParameter[210] /* cycle_time PARAM */))) * (fabs((data->simulationInfo->realParameter[209] /* cycle_max PARAM */)));
    tmp15 = GreaterZC(data->localData[0]->timeValue, ((data->simulationInfo->realParameter[210] /* cycle_time PARAM */)) * ((data->simulationInfo->realParameter[209] /* cycle_max PARAM */)), tmp16, tmp17, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[start_index] = tmp15;
    current_index++;
  } else {
    start_index = current_index;
    data->simulationInfo->relations[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */)) * ((data->simulationInfo->realParameter[239] /* sFluoA PARAM */)) > (data->simulationInfo->realParameter[233] /* lFluoA PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */)) * ((data->simulationInfo->realParameter[240] /* sFluoB PARAM */)) > (data->simulationInfo->realParameter[234] /* lFluoB PARAM */));
    current_index++;

    start_index = current_index;
    data->simulationInfo->relations[start_index] = (data->localData[0]->timeValue > ((data->simulationInfo->realParameter[210] /* cycle_time PARAM */)) * ((data->simulationInfo->realParameter[209] /* cycle_max PARAM */)));
    current_index++;
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

