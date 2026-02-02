/* Asserts */
#include "rPCR_03_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 867
type: ALGORITHM

  assert(As.c >= 0.0, "Variable violating min constraint: 0.0 <= As.c, has value: " + String(As.c, "g"));
*/
void rPCR_03_eqFunction_867(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,867};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,59,"Variable violating min constraint: 0.0 <= As.c, has value: ");
  modelica_string tmp2;
  modelica_metatype tmpMeta3;
  static int tmp4 = 0;
  if(!tmp4)
  {
    tmp0 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */),0.0);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[10]] /* As.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta3 = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        const char* assert_cond = "(As.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta3));
        }
      }
      tmp4 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 868
type: ALGORITHM

  assert(As.n >= 0.0, "Variable violating min constraint: 0.0 <= As.n, has value: " + String(As.n, "g"));
*/
void rPCR_03_eqFunction_868(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,868};
  modelica_boolean tmp5;
  static const MMC_DEFSTRINGLIT(tmp6,59,"Variable violating min constraint: 0.0 <= As.n, has value: ");
  modelica_string tmp7;
  modelica_metatype tmpMeta8;
  static int tmp9 = 0;
  if(!tmp9)
  {
    tmp5 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* As.n variable */),0.0);
    if(!tmp5)
    {
      tmp7 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[98]] /* As.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta8 = stringAppend(MMC_REFSTRINGLIT(tmp6),tmp7);
      {
        const char* assert_cond = "(As.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta8));
        }
      }
      tmp9 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 869
type: ALGORITHM

  assert(Aa.c >= 0.0, "Variable violating min constraint: 0.0 <= Aa.c, has value: " + String(Aa.c, "g"));
*/
void rPCR_03_eqFunction_869(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,869};
  modelica_boolean tmp10;
  static const MMC_DEFSTRINGLIT(tmp11,59,"Variable violating min constraint: 0.0 <= Aa.c, has value: ");
  modelica_string tmp12;
  modelica_metatype tmpMeta13;
  static int tmp14 = 0;
  if(!tmp14)
  {
    tmp10 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */),0.0);
    if(!tmp10)
    {
      tmp12 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[0]] /* Aa.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta13 = stringAppend(MMC_REFSTRINGLIT(tmp11),tmp12);
      {
        const char* assert_cond = "(Aa.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta13));
        }
      }
      tmp14 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 870
type: ALGORITHM

  assert(Aa.n >= 0.0, "Variable violating min constraint: 0.0 <= Aa.n, has value: " + String(Aa.n, "g"));
*/
void rPCR_03_eqFunction_870(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,870};
  modelica_boolean tmp15;
  static const MMC_DEFSTRINGLIT(tmp16,59,"Variable violating min constraint: 0.0 <= Aa.n, has value: ");
  modelica_string tmp17;
  modelica_metatype tmpMeta18;
  static int tmp19 = 0;
  if(!tmp19)
  {
    tmp15 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* Aa.n variable */),0.0);
    if(!tmp15)
    {
      tmp17 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[80]] /* Aa.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta18 = stringAppend(MMC_REFSTRINGLIT(tmp16),tmp17);
      {
        const char* assert_cond = "(Aa.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta18));
        }
      }
      tmp19 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 871
type: ALGORITHM

  assert(Bs.c >= 0.0, "Variable violating min constraint: 0.0 <= Bs.c, has value: " + String(Bs.c, "g"));
*/
void rPCR_03_eqFunction_871(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,871};
  modelica_boolean tmp20;
  static const MMC_DEFSTRINGLIT(tmp21,59,"Variable violating min constraint: 0.0 <= Bs.c, has value: ");
  modelica_string tmp22;
  modelica_metatype tmpMeta23;
  static int tmp24 = 0;
  if(!tmp24)
  {
    tmp20 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */),0.0);
    if(!tmp20)
    {
      tmp22 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[26]] /* Bs.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta23 = stringAppend(MMC_REFSTRINGLIT(tmp21),tmp22);
      {
        const char* assert_cond = "(Bs.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta23));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta23));
        }
      }
      tmp24 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 872
type: ALGORITHM

  assert(Bs.n >= 0.0, "Variable violating min constraint: 0.0 <= Bs.n, has value: " + String(Bs.n, "g"));
*/
void rPCR_03_eqFunction_872(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,872};
  modelica_boolean tmp25;
  static const MMC_DEFSTRINGLIT(tmp26,59,"Variable violating min constraint: 0.0 <= Bs.n, has value: ");
  modelica_string tmp27;
  modelica_metatype tmpMeta28;
  static int tmp29 = 0;
  if(!tmp29)
  {
    tmp25 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[128]] /* Bs.n variable */),0.0);
    if(!tmp25)
    {
      tmp27 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[128]] /* Bs.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta28 = stringAppend(MMC_REFSTRINGLIT(tmp26),tmp27);
      {
        const char* assert_cond = "(Bs.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta28));
        }
      }
      tmp29 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 873
type: ALGORITHM

  assert(Ba.c >= 0.0, "Variable violating min constraint: 0.0 <= Ba.c, has value: " + String(Ba.c, "g"));
*/
void rPCR_03_eqFunction_873(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,873};
  modelica_boolean tmp30;
  static const MMC_DEFSTRINGLIT(tmp31,59,"Variable violating min constraint: 0.0 <= Ba.c, has value: ");
  modelica_string tmp32;
  modelica_metatype tmpMeta33;
  static int tmp34 = 0;
  if(!tmp34)
  {
    tmp30 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */),0.0);
    if(!tmp30)
    {
      tmp32 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[18]] /* Ba.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta33 = stringAppend(MMC_REFSTRINGLIT(tmp31),tmp32);
      {
        const char* assert_cond = "(Ba.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta33));
        }
      }
      tmp34 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 874
type: ALGORITHM

  assert(Ba.n >= 0.0, "Variable violating min constraint: 0.0 <= Ba.n, has value: " + String(Ba.n, "g"));
*/
void rPCR_03_eqFunction_874(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,874};
  modelica_boolean tmp35;
  static const MMC_DEFSTRINGLIT(tmp36,59,"Variable violating min constraint: 0.0 <= Ba.n, has value: ");
  modelica_string tmp37;
  modelica_metatype tmpMeta38;
  static int tmp39 = 0;
  if(!tmp39)
  {
    tmp35 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* Ba.n variable */),0.0);
    if(!tmp35)
    {
      tmp37 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[113]] /* Ba.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta38 = stringAppend(MMC_REFSTRINGLIT(tmp36),tmp37);
      {
        const char* assert_cond = "(Ba.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta38));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta38));
        }
      }
      tmp39 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 875
type: ALGORITHM

  assert(Prs.c >= 0.0, "Variable violating min constraint: 0.0 <= Prs.c, has value: " + String(Prs.c, "g"));
*/
void rPCR_03_eqFunction_875(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,875};
  modelica_boolean tmp40;
  static const MMC_DEFSTRINGLIT(tmp41,60,"Variable violating min constraint: 0.0 <= Prs.c, has value: ");
  modelica_string tmp42;
  modelica_metatype tmpMeta43;
  static int tmp44 = 0;
  if(!tmp44)
  {
    tmp40 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */),0.0);
    if(!tmp40)
    {
      tmp42 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[36]] /* Prs.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta43 = stringAppend(MMC_REFSTRINGLIT(tmp41),tmp42);
      {
        const char* assert_cond = "(Prs.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta43));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta43));
        }
      }
      tmp44 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 876
type: ALGORITHM

  assert(Prs.n >= 0.0, "Variable violating min constraint: 0.0 <= Prs.n, has value: " + String(Prs.n, "g"));
*/
void rPCR_03_eqFunction_876(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,876};
  modelica_boolean tmp45;
  static const MMC_DEFSTRINGLIT(tmp46,60,"Variable violating min constraint: 0.0 <= Prs.n, has value: ");
  modelica_string tmp47;
  modelica_metatype tmpMeta48;
  static int tmp49 = 0;
  if(!tmp49)
  {
    tmp45 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[150]] /* Prs.n variable */),0.0);
    if(!tmp45)
    {
      tmp47 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[150]] /* Prs.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta48 = stringAppend(MMC_REFSTRINGLIT(tmp46),tmp47);
      {
        const char* assert_cond = "(Prs.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta48));
        }
      }
      tmp49 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 877
type: ALGORITHM

  assert(Pra.c >= 0.0, "Variable violating min constraint: 0.0 <= Pra.c, has value: " + String(Pra.c, "g"));
*/
void rPCR_03_eqFunction_877(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,877};
  modelica_boolean tmp50;
  static const MMC_DEFSTRINGLIT(tmp51,60,"Variable violating min constraint: 0.0 <= Pra.c, has value: ");
  modelica_string tmp52;
  modelica_metatype tmpMeta53;
  static int tmp54 = 0;
  if(!tmp54)
  {
    tmp50 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */),0.0);
    if(!tmp50)
    {
      tmp52 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[35]] /* Pra.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta53 = stringAppend(MMC_REFSTRINGLIT(tmp51),tmp52);
      {
        const char* assert_cond = "(Pra.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta53));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta53));
        }
      }
      tmp54 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 878
type: ALGORITHM

  assert(Pra.n >= 0.0, "Variable violating min constraint: 0.0 <= Pra.n, has value: " + String(Pra.n, "g"));
*/
void rPCR_03_eqFunction_878(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,878};
  modelica_boolean tmp55;
  static const MMC_DEFSTRINGLIT(tmp56,60,"Variable violating min constraint: 0.0 <= Pra.n, has value: ");
  modelica_string tmp57;
  modelica_metatype tmpMeta58;
  static int tmp59 = 0;
  if(!tmp59)
  {
    tmp55 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[148]] /* Pra.n variable */),0.0);
    if(!tmp55)
    {
      tmp57 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[148]] /* Pra.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta58 = stringAppend(MMC_REFSTRINGLIT(tmp56),tmp57);
      {
        const char* assert_cond = "(Pra.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta58));
        }
      }
      tmp59 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 879
type: ALGORITHM

  assert(PA.c >= 0.0, "Variable violating min constraint: 0.0 <= PA.c, has value: " + String(PA.c, "g"));
*/
void rPCR_03_eqFunction_879(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,879};
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,59,"Variable violating min constraint: 0.0 <= PA.c, has value: ");
  modelica_string tmp62;
  modelica_metatype tmpMeta63;
  static int tmp64 = 0;
  if(!tmp64)
  {
    tmp60 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */),0.0);
    if(!tmp60)
    {
      tmp62 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[32]] /* PA.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta63 = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
      {
        const char* assert_cond = "(PA.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta63));
        }
      }
      tmp64 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 880
type: ALGORITHM

  assert(PA.n >= 0.0, "Variable violating min constraint: 0.0 <= PA.n, has value: " + String(PA.n, "g"));
*/
void rPCR_03_eqFunction_880(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,880};
  modelica_boolean tmp65;
  static const MMC_DEFSTRINGLIT(tmp66,59,"Variable violating min constraint: 0.0 <= PA.n, has value: ");
  modelica_string tmp67;
  modelica_metatype tmpMeta68;
  static int tmp69 = 0;
  if(!tmp69)
  {
    tmp65 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[142]] /* PA.n variable */),0.0);
    if(!tmp65)
    {
      tmp67 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[142]] /* PA.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta68 = stringAppend(MMC_REFSTRINGLIT(tmp66),tmp67);
      {
        const char* assert_cond = "(PA.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta68));
        }
      }
      tmp69 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 881
type: ALGORITHM

  assert(PB.c >= 0.0, "Variable violating min constraint: 0.0 <= PB.c, has value: " + String(PB.c, "g"));
*/
void rPCR_03_eqFunction_881(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,881};
  modelica_boolean tmp70;
  static const MMC_DEFSTRINGLIT(tmp71,59,"Variable violating min constraint: 0.0 <= PB.c, has value: ");
  modelica_string tmp72;
  modelica_metatype tmpMeta73;
  static int tmp74 = 0;
  if(!tmp74)
  {
    tmp70 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */),0.0);
    if(!tmp70)
    {
      tmp72 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[33]] /* PB.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta73 = stringAppend(MMC_REFSTRINGLIT(tmp71),tmp72);
      {
        const char* assert_cond = "(PB.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta73));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta73));
        }
      }
      tmp74 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 882
type: ALGORITHM

  assert(PB.n >= 0.0, "Variable violating min constraint: 0.0 <= PB.n, has value: " + String(PB.n, "g"));
*/
void rPCR_03_eqFunction_882(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,882};
  modelica_boolean tmp75;
  static const MMC_DEFSTRINGLIT(tmp76,59,"Variable violating min constraint: 0.0 <= PB.n, has value: ");
  modelica_string tmp77;
  modelica_metatype tmpMeta78;
  static int tmp79 = 0;
  if(!tmp79)
  {
    tmp75 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[144]] /* PB.n variable */),0.0);
    if(!tmp75)
    {
      tmp77 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[144]] /* PB.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta78 = stringAppend(MMC_REFSTRINGLIT(tmp76),tmp77);
      {
        const char* assert_cond = "(PB.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta78));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta78));
        }
      }
      tmp79 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 883
type: ALGORITHM

  assert(Poly.c >= 0.0, "Variable violating min constraint: 0.0 <= Poly.c, has value: " + String(Poly.c, "g"));
*/
void rPCR_03_eqFunction_883(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,883};
  modelica_boolean tmp80;
  static const MMC_DEFSTRINGLIT(tmp81,61,"Variable violating min constraint: 0.0 <= Poly.c, has value: ");
  modelica_string tmp82;
  modelica_metatype tmpMeta83;
  static int tmp84 = 0;
  if(!tmp84)
  {
    tmp80 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */),0.0);
    if(!tmp80)
    {
      tmp82 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[34]] /* Poly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta83 = stringAppend(MMC_REFSTRINGLIT(tmp81),tmp82);
      {
        const char* assert_cond = "(Poly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta83));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta83));
        }
      }
      tmp84 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 884
type: ALGORITHM

  assert(Poly.n >= 0.0, "Variable violating min constraint: 0.0 <= Poly.n, has value: " + String(Poly.n, "g"));
*/
void rPCR_03_eqFunction_884(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,884};
  modelica_boolean tmp85;
  static const MMC_DEFSTRINGLIT(tmp86,61,"Variable violating min constraint: 0.0 <= Poly.n, has value: ");
  modelica_string tmp87;
  modelica_metatype tmpMeta88;
  static int tmp89 = 0;
  if(!tmp89)
  {
    tmp85 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[146]] /* Poly.n variable */),0.0);
    if(!tmp85)
    {
      tmp87 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[146]] /* Poly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta88 = stringAppend(MMC_REFSTRINGLIT(tmp86),tmp87);
      {
        const char* assert_cond = "(Poly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta88));
        }
      }
      tmp89 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 885
type: ALGORITHM

  assert(AsBa.c >= 0.0, "Variable violating min constraint: 0.0 <= AsBa.c, has value: " + String(AsBa.c, "g"));
*/
void rPCR_03_eqFunction_885(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,885};
  modelica_boolean tmp90;
  static const MMC_DEFSTRINGLIT(tmp91,61,"Variable violating min constraint: 0.0 <= AsBa.c, has value: ");
  modelica_string tmp92;
  modelica_metatype tmpMeta93;
  static int tmp94 = 0;
  if(!tmp94)
  {
    tmp90 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */),0.0);
    if(!tmp90)
    {
      tmp92 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[11]] /* AsBa.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta93 = stringAppend(MMC_REFSTRINGLIT(tmp91),tmp92);
      {
        const char* assert_cond = "(AsBa.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta93));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta93));
        }
      }
      tmp94 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 886
type: ALGORITHM

  assert(AsBa.n >= 0.0, "Variable violating min constraint: 0.0 <= AsBa.n, has value: " + String(AsBa.n, "g"));
*/
void rPCR_03_eqFunction_886(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,886};
  modelica_boolean tmp95;
  static const MMC_DEFSTRINGLIT(tmp96,61,"Variable violating min constraint: 0.0 <= AsBa.n, has value: ");
  modelica_string tmp97;
  modelica_metatype tmpMeta98;
  static int tmp99 = 0;
  if(!tmp99)
  {
    tmp95 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* AsBa.n variable */),0.0);
    if(!tmp95)
    {
      tmp97 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[100]] /* AsBa.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta98 = stringAppend(MMC_REFSTRINGLIT(tmp96),tmp97);
      {
        const char* assert_cond = "(AsBa.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta98));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta98));
        }
      }
      tmp99 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 887
type: ALGORITHM

  assert(AaBs.c >= 0.0, "Variable violating min constraint: 0.0 <= AaBs.c, has value: " + String(AaBs.c, "g"));
*/
void rPCR_03_eqFunction_887(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,887};
  modelica_boolean tmp100;
  static const MMC_DEFSTRINGLIT(tmp101,61,"Variable violating min constraint: 0.0 <= AaBs.c, has value: ");
  modelica_string tmp102;
  modelica_metatype tmpMeta103;
  static int tmp104 = 0;
  if(!tmp104)
  {
    tmp100 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */),0.0);
    if(!tmp100)
    {
      tmp102 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[3]] /* AaBs.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta103 = stringAppend(MMC_REFSTRINGLIT(tmp101),tmp102);
      {
        const char* assert_cond = "(AaBs.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta103));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta103));
        }
      }
      tmp104 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 888
type: ALGORITHM

  assert(AaBs.n >= 0.0, "Variable violating min constraint: 0.0 <= AaBs.n, has value: " + String(AaBs.n, "g"));
*/
void rPCR_03_eqFunction_888(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,888};
  modelica_boolean tmp105;
  static const MMC_DEFSTRINGLIT(tmp106,61,"Variable violating min constraint: 0.0 <= AaBs.n, has value: ");
  modelica_string tmp107;
  modelica_metatype tmpMeta108;
  static int tmp109 = 0;
  if(!tmp109)
  {
    tmp105 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* AaBs.n variable */),0.0);
    if(!tmp105)
    {
      tmp107 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[85]] /* AaBs.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta108 = stringAppend(MMC_REFSTRINGLIT(tmp106),tmp107);
      {
        const char* assert_cond = "(AaBs.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta108));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta108));
        }
      }
      tmp109 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 889
type: ALGORITHM

  assert(BaBs.c >= 0.0, "Variable violating min constraint: 0.0 <= BaBs.c, has value: " + String(BaBs.c, "g"));
*/
void rPCR_03_eqFunction_889(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,889};
  modelica_boolean tmp110;
  static const MMC_DEFSTRINGLIT(tmp111,61,"Variable violating min constraint: 0.0 <= BaBs.c, has value: ");
  modelica_string tmp112;
  modelica_metatype tmpMeta113;
  static int tmp114 = 0;
  if(!tmp114)
  {
    tmp110 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */),0.0);
    if(!tmp110)
    {
      tmp112 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[19]] /* BaBs.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta113 = stringAppend(MMC_REFSTRINGLIT(tmp111),tmp112);
      {
        const char* assert_cond = "(BaBs.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta113));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta113));
        }
      }
      tmp114 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 890
type: ALGORITHM

  assert(BaBs.n >= 0.0, "Variable violating min constraint: 0.0 <= BaBs.n, has value: " + String(BaBs.n, "g"));
*/
void rPCR_03_eqFunction_890(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,890};
  modelica_boolean tmp115;
  static const MMC_DEFSTRINGLIT(tmp116,61,"Variable violating min constraint: 0.0 <= BaBs.n, has value: ");
  modelica_string tmp117;
  modelica_metatype tmpMeta118;
  static int tmp119 = 0;
  if(!tmp119)
  {
    tmp115 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* BaBs.n variable */),0.0);
    if(!tmp115)
    {
      tmp117 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[115]] /* BaBs.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta118 = stringAppend(MMC_REFSTRINGLIT(tmp116),tmp117);
      {
        const char* assert_cond = "(BaBs.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta118));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta118));
        }
      }
      tmp119 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 891
type: ALGORITHM

  assert(AaAs.c >= 0.0, "Variable violating min constraint: 0.0 <= AaAs.c, has value: " + String(AaAs.c, "g"));
*/
void rPCR_03_eqFunction_891(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,891};
  modelica_boolean tmp120;
  static const MMC_DEFSTRINGLIT(tmp121,61,"Variable violating min constraint: 0.0 <= AaAs.c, has value: ");
  modelica_string tmp122;
  modelica_metatype tmpMeta123;
  static int tmp124 = 0;
  if(!tmp124)
  {
    tmp120 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */),0.0);
    if(!tmp120)
    {
      tmp122 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[1]] /* AaAs.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta123 = stringAppend(MMC_REFSTRINGLIT(tmp121),tmp122);
      {
        const char* assert_cond = "(AaAs.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta123));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta123));
        }
      }
      tmp124 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 892
type: ALGORITHM

  assert(AaAs.n >= 0.0, "Variable violating min constraint: 0.0 <= AaAs.n, has value: " + String(AaAs.n, "g"));
*/
void rPCR_03_eqFunction_892(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,892};
  modelica_boolean tmp125;
  static const MMC_DEFSTRINGLIT(tmp126,61,"Variable violating min constraint: 0.0 <= AaAs.n, has value: ");
  modelica_string tmp127;
  modelica_metatype tmpMeta128;
  static int tmp129 = 0;
  if(!tmp129)
  {
    tmp125 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* AaAs.n variable */),0.0);
    if(!tmp125)
    {
      tmp127 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[82]] /* AaAs.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta128 = stringAppend(MMC_REFSTRINGLIT(tmp126),tmp127);
      {
        const char* assert_cond = "(AaAs.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta128));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta128));
        }
      }
      tmp129 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 893
type: ALGORITHM

  assert(AaAsPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= AaAsPoly.c, has value: " + String(AaAsPoly.c, "g"));
*/
void rPCR_03_eqFunction_893(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,893};
  modelica_boolean tmp130;
  static const MMC_DEFSTRINGLIT(tmp131,65,"Variable violating min constraint: 0.0 <= AaAsPoly.c, has value: ");
  modelica_string tmp132;
  modelica_metatype tmpMeta133;
  static int tmp134 = 0;
  if(!tmp134)
  {
    tmp130 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */),0.0);
    if(!tmp130)
    {
      tmp132 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[2]] /* AaAsPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta133 = stringAppend(MMC_REFSTRINGLIT(tmp131),tmp132);
      {
        const char* assert_cond = "(AaAsPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta133));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta133));
        }
      }
      tmp134 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 894
type: ALGORITHM

  assert(AaAsPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= AaAsPoly.n, has value: " + String(AaAsPoly.n, "g"));
*/
void rPCR_03_eqFunction_894(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,894};
  modelica_boolean tmp135;
  static const MMC_DEFSTRINGLIT(tmp136,65,"Variable violating min constraint: 0.0 <= AaAsPoly.n, has value: ");
  modelica_string tmp137;
  modelica_metatype tmpMeta138;
  static int tmp139 = 0;
  if(!tmp139)
  {
    tmp135 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* AaAsPoly.n variable */),0.0);
    if(!tmp135)
    {
      tmp137 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[84]] /* AaAsPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta138 = stringAppend(MMC_REFSTRINGLIT(tmp136),tmp137);
      {
        const char* assert_cond = "(AaAsPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta138));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta138));
        }
      }
      tmp139 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 895
type: ALGORITHM

  assert(BaBsPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= BaBsPoly.c, has value: " + String(BaBsPoly.c, "g"));
*/
void rPCR_03_eqFunction_895(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,895};
  modelica_boolean tmp140;
  static const MMC_DEFSTRINGLIT(tmp141,65,"Variable violating min constraint: 0.0 <= BaBsPoly.c, has value: ");
  modelica_string tmp142;
  modelica_metatype tmpMeta143;
  static int tmp144 = 0;
  if(!tmp144)
  {
    tmp140 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */),0.0);
    if(!tmp140)
    {
      tmp142 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[20]] /* BaBsPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta143 = stringAppend(MMC_REFSTRINGLIT(tmp141),tmp142);
      {
        const char* assert_cond = "(BaBsPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta143));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta143));
        }
      }
      tmp144 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 896
type: ALGORITHM

  assert(BaBsPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= BaBsPoly.n, has value: " + String(BaBsPoly.n, "g"));
*/
void rPCR_03_eqFunction_896(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,896};
  modelica_boolean tmp145;
  static const MMC_DEFSTRINGLIT(tmp146,65,"Variable violating min constraint: 0.0 <= BaBsPoly.n, has value: ");
  modelica_string tmp147;
  modelica_metatype tmpMeta148;
  static int tmp149 = 0;
  if(!tmp149)
  {
    tmp145 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* BaBsPoly.n variable */),0.0);
    if(!tmp145)
    {
      tmp147 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[117]] /* BaBsPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta148 = stringAppend(MMC_REFSTRINGLIT(tmp146),tmp147);
      {
        const char* assert_cond = "(BaBsPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta148));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta148));
        }
      }
      tmp149 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 897
type: ALGORITHM

  assert(BaPra.c >= 0.0, "Variable violating min constraint: 0.0 <= BaPra.c, has value: " + String(BaPra.c, "g"));
*/
void rPCR_03_eqFunction_897(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,897};
  modelica_boolean tmp150;
  static const MMC_DEFSTRINGLIT(tmp151,62,"Variable violating min constraint: 0.0 <= BaPra.c, has value: ");
  modelica_string tmp152;
  modelica_metatype tmpMeta153;
  static int tmp154 = 0;
  if(!tmp154)
  {
    tmp150 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */),0.0);
    if(!tmp150)
    {
      tmp152 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[22]] /* BaPra.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta153 = stringAppend(MMC_REFSTRINGLIT(tmp151),tmp152);
      {
        const char* assert_cond = "(BaPra.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta153));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta153));
        }
      }
      tmp154 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 898
type: ALGORITHM

  assert(BaPra.n >= 0.0, "Variable violating min constraint: 0.0 <= BaPra.n, has value: " + String(BaPra.n, "g"));
*/
void rPCR_03_eqFunction_898(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,898};
  modelica_boolean tmp155;
  static const MMC_DEFSTRINGLIT(tmp156,62,"Variable violating min constraint: 0.0 <= BaPra.n, has value: ");
  modelica_string tmp157;
  modelica_metatype tmpMeta158;
  static int tmp159 = 0;
  if(!tmp159)
  {
    tmp155 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* BaPra.n variable */),0.0);
    if(!tmp155)
    {
      tmp157 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[120]] /* BaPra.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta158 = stringAppend(MMC_REFSTRINGLIT(tmp156),tmp157);
      {
        const char* assert_cond = "(BaPra.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta158));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta158));
        }
      }
      tmp159 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 899
type: ALGORITHM

  assert(AaPra.c >= 0.0, "Variable violating min constraint: 0.0 <= AaPra.c, has value: " + String(AaPra.c, "g"));
*/
void rPCR_03_eqFunction_899(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,899};
  modelica_boolean tmp160;
  static const MMC_DEFSTRINGLIT(tmp161,62,"Variable violating min constraint: 0.0 <= AaPra.c, has value: ");
  modelica_string tmp162;
  modelica_metatype tmpMeta163;
  static int tmp164 = 0;
  if(!tmp164)
  {
    tmp160 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */),0.0);
    if(!tmp160)
    {
      tmp162 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[6]] /* AaPra.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta163 = stringAppend(MMC_REFSTRINGLIT(tmp161),tmp162);
      {
        const char* assert_cond = "(AaPra.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta163));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta163));
        }
      }
      tmp164 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 900
type: ALGORITHM

  assert(AaPra.n >= 0.0, "Variable violating min constraint: 0.0 <= AaPra.n, has value: " + String(AaPra.n, "g"));
*/
void rPCR_03_eqFunction_900(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,900};
  modelica_boolean tmp165;
  static const MMC_DEFSTRINGLIT(tmp166,62,"Variable violating min constraint: 0.0 <= AaPra.n, has value: ");
  modelica_string tmp167;
  modelica_metatype tmpMeta168;
  static int tmp169 = 0;
  if(!tmp169)
  {
    tmp165 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* AaPra.n variable */),0.0);
    if(!tmp165)
    {
      tmp167 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[90]] /* AaPra.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta168 = stringAppend(MMC_REFSTRINGLIT(tmp166),tmp167);
      {
        const char* assert_cond = "(AaPra.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta168));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta168));
        }
      }
      tmp169 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 901
type: ALGORITHM

  assert(AsPrs.c >= 0.0, "Variable violating min constraint: 0.0 <= AsPrs.c, has value: " + String(AsPrs.c, "g"));
*/
void rPCR_03_eqFunction_901(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,901};
  modelica_boolean tmp170;
  static const MMC_DEFSTRINGLIT(tmp171,62,"Variable violating min constraint: 0.0 <= AsPrs.c, has value: ");
  modelica_string tmp172;
  modelica_metatype tmpMeta173;
  static int tmp174 = 0;
  if(!tmp174)
  {
    tmp170 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */),0.0);
    if(!tmp170)
    {
      tmp172 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[14]] /* AsPrs.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta173 = stringAppend(MMC_REFSTRINGLIT(tmp171),tmp172);
      {
        const char* assert_cond = "(AsPrs.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta173));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta173));
        }
      }
      tmp174 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 902
type: ALGORITHM

  assert(AsPrs.n >= 0.0, "Variable violating min constraint: 0.0 <= AsPrs.n, has value: " + String(AsPrs.n, "g"));
*/
void rPCR_03_eqFunction_902(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,902};
  modelica_boolean tmp175;
  static const MMC_DEFSTRINGLIT(tmp176,62,"Variable violating min constraint: 0.0 <= AsPrs.n, has value: ");
  modelica_string tmp177;
  modelica_metatype tmpMeta178;
  static int tmp179 = 0;
  if(!tmp179)
  {
    tmp175 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* AsPrs.n variable */),0.0);
    if(!tmp175)
    {
      tmp177 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[105]] /* AsPrs.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta178 = stringAppend(MMC_REFSTRINGLIT(tmp176),tmp177);
      {
        const char* assert_cond = "(AsPrs.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta178));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta178));
        }
      }
      tmp179 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 903
type: ALGORITHM

  assert(BsPrs.c >= 0.0, "Variable violating min constraint: 0.0 <= BsPrs.c, has value: " + String(BsPrs.c, "g"));
*/
void rPCR_03_eqFunction_903(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,903};
  modelica_boolean tmp180;
  static const MMC_DEFSTRINGLIT(tmp181,62,"Variable violating min constraint: 0.0 <= BsPrs.c, has value: ");
  modelica_string tmp182;
  modelica_metatype tmpMeta183;
  static int tmp184 = 0;
  if(!tmp184)
  {
    tmp180 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */),0.0);
    if(!tmp180)
    {
      tmp182 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[28]] /* BsPrs.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta183 = stringAppend(MMC_REFSTRINGLIT(tmp181),tmp182);
      {
        const char* assert_cond = "(BsPrs.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta183));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta183));
        }
      }
      tmp184 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 904
type: ALGORITHM

  assert(BsPrs.n >= 0.0, "Variable violating min constraint: 0.0 <= BsPrs.n, has value: " + String(BsPrs.n, "g"));
*/
void rPCR_03_eqFunction_904(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,904};
  modelica_boolean tmp185;
  static const MMC_DEFSTRINGLIT(tmp186,62,"Variable violating min constraint: 0.0 <= BsPrs.n, has value: ");
  modelica_string tmp187;
  modelica_metatype tmpMeta188;
  static int tmp189 = 0;
  if(!tmp189)
  {
    tmp185 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* BsPrs.n variable */),0.0);
    if(!tmp185)
    {
      tmp187 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[132]] /* BsPrs.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta188 = stringAppend(MMC_REFSTRINGLIT(tmp186),tmp187);
      {
        const char* assert_cond = "(BsPrs.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta188));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta188));
        }
      }
      tmp189 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 905
type: ALGORITHM

  assert(BsPB.c >= 0.0, "Variable violating min constraint: 0.0 <= BsPB.c, has value: " + String(BsPB.c, "g"));
*/
void rPCR_03_eqFunction_905(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,905};
  modelica_boolean tmp190;
  static const MMC_DEFSTRINGLIT(tmp191,61,"Variable violating min constraint: 0.0 <= BsPB.c, has value: ");
  modelica_string tmp192;
  modelica_metatype tmpMeta193;
  static int tmp194 = 0;
  if(!tmp194)
  {
    tmp190 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */),0.0);
    if(!tmp190)
    {
      tmp192 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[27]] /* BsPB.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta193 = stringAppend(MMC_REFSTRINGLIT(tmp191),tmp192);
      {
        const char* assert_cond = "(BsPB.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta193));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta193));
        }
      }
      tmp194 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 906
type: ALGORITHM

  assert(BsPB.n >= 0.0, "Variable violating min constraint: 0.0 <= BsPB.n, has value: " + String(BsPB.n, "g"));
*/
void rPCR_03_eqFunction_906(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,906};
  modelica_boolean tmp195;
  static const MMC_DEFSTRINGLIT(tmp196,61,"Variable violating min constraint: 0.0 <= BsPB.n, has value: ");
  modelica_string tmp197;
  modelica_metatype tmpMeta198;
  static int tmp199 = 0;
  if(!tmp199)
  {
    tmp195 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[130]] /* BsPB.n variable */),0.0);
    if(!tmp195)
    {
      tmp197 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[130]] /* BsPB.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta198 = stringAppend(MMC_REFSTRINGLIT(tmp196),tmp197);
      {
        const char* assert_cond = "(BsPB.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta198));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta198));
        }
      }
      tmp199 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 907
type: ALGORITHM

  assert(AsPA.c >= 0.0, "Variable violating min constraint: 0.0 <= AsPA.c, has value: " + String(AsPA.c, "g"));
*/
void rPCR_03_eqFunction_907(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,907};
  modelica_boolean tmp200;
  static const MMC_DEFSTRINGLIT(tmp201,61,"Variable violating min constraint: 0.0 <= AsPA.c, has value: ");
  modelica_string tmp202;
  modelica_metatype tmpMeta203;
  static int tmp204 = 0;
  if(!tmp204)
  {
    tmp200 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */),0.0);
    if(!tmp200)
    {
      tmp202 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[13]] /* AsPA.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta203 = stringAppend(MMC_REFSTRINGLIT(tmp201),tmp202);
      {
        const char* assert_cond = "(AsPA.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta203));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta203));
        }
      }
      tmp204 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 908
type: ALGORITHM

  assert(AsPA.n >= 0.0, "Variable violating min constraint: 0.0 <= AsPA.n, has value: " + String(AsPA.n, "g"));
*/
void rPCR_03_eqFunction_908(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,908};
  modelica_boolean tmp205;
  static const MMC_DEFSTRINGLIT(tmp206,61,"Variable violating min constraint: 0.0 <= AsPA.n, has value: ");
  modelica_string tmp207;
  modelica_metatype tmpMeta208;
  static int tmp209 = 0;
  if(!tmp209)
  {
    tmp205 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* AsPA.n variable */),0.0);
    if(!tmp205)
    {
      tmp207 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[103]] /* AsPA.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta208 = stringAppend(MMC_REFSTRINGLIT(tmp206),tmp207);
      {
        const char* assert_cond = "(AsPA.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta208));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta208));
        }
      }
      tmp209 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 909
type: ALGORITHM

  assert(AsPrsPA.c >= 0.0, "Variable violating min constraint: 0.0 <= AsPrsPA.c, has value: " + String(AsPrsPA.c, "g"));
*/
void rPCR_03_eqFunction_909(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,909};
  modelica_boolean tmp210;
  static const MMC_DEFSTRINGLIT(tmp211,64,"Variable violating min constraint: 0.0 <= AsPrsPA.c, has value: ");
  modelica_string tmp212;
  modelica_metatype tmpMeta213;
  static int tmp214 = 0;
  if(!tmp214)
  {
    tmp210 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */),0.0);
    if(!tmp210)
    {
      tmp212 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[15]] /* AsPrsPA.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta213 = stringAppend(MMC_REFSTRINGLIT(tmp211),tmp212);
      {
        const char* assert_cond = "(AsPrsPA.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta213));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta213));
        }
      }
      tmp214 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 910
type: ALGORITHM

  assert(AsPrsPA.n >= 0.0, "Variable violating min constraint: 0.0 <= AsPrsPA.n, has value: " + String(AsPrsPA.n, "g"));
*/
void rPCR_03_eqFunction_910(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,910};
  modelica_boolean tmp215;
  static const MMC_DEFSTRINGLIT(tmp216,64,"Variable violating min constraint: 0.0 <= AsPrsPA.n, has value: ");
  modelica_string tmp217;
  modelica_metatype tmpMeta218;
  static int tmp219 = 0;
  if(!tmp219)
  {
    tmp215 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* AsPrsPA.n variable */),0.0);
    if(!tmp215)
    {
      tmp217 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[107]] /* AsPrsPA.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta218 = stringAppend(MMC_REFSTRINGLIT(tmp216),tmp217);
      {
        const char* assert_cond = "(AsPrsPA.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta218));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta218));
        }
      }
      tmp219 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 911
type: ALGORITHM

  assert(BsPrsPB.c >= 0.0, "Variable violating min constraint: 0.0 <= BsPrsPB.c, has value: " + String(BsPrsPB.c, "g"));
*/
void rPCR_03_eqFunction_911(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,911};
  modelica_boolean tmp220;
  static const MMC_DEFSTRINGLIT(tmp221,64,"Variable violating min constraint: 0.0 <= BsPrsPB.c, has value: ");
  modelica_string tmp222;
  modelica_metatype tmpMeta223;
  static int tmp224 = 0;
  if(!tmp224)
  {
    tmp220 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */),0.0);
    if(!tmp220)
    {
      tmp222 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[29]] /* BsPrsPB.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta223 = stringAppend(MMC_REFSTRINGLIT(tmp221),tmp222);
      {
        const char* assert_cond = "(BsPrsPB.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta223));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta223));
        }
      }
      tmp224 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 912
type: ALGORITHM

  assert(BsPrsPB.n >= 0.0, "Variable violating min constraint: 0.0 <= BsPrsPB.n, has value: " + String(BsPrsPB.n, "g"));
*/
void rPCR_03_eqFunction_912(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,912};
  modelica_boolean tmp225;
  static const MMC_DEFSTRINGLIT(tmp226,64,"Variable violating min constraint: 0.0 <= BsPrsPB.n, has value: ");
  modelica_string tmp227;
  modelica_metatype tmpMeta228;
  static int tmp229 = 0;
  if(!tmp229)
  {
    tmp225 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[134]] /* BsPrsPB.n variable */),0.0);
    if(!tmp225)
    {
      tmp227 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[134]] /* BsPrsPB.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta228 = stringAppend(MMC_REFSTRINGLIT(tmp226),tmp227);
      {
        const char* assert_cond = "(BsPrsPB.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta228));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta228));
        }
      }
      tmp229 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 913
type: ALGORITHM

  assert(AaPraPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= AaPraPoly.c, has value: " + String(AaPraPoly.c, "g"));
*/
void rPCR_03_eqFunction_913(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,913};
  modelica_boolean tmp230;
  static const MMC_DEFSTRINGLIT(tmp231,66,"Variable violating min constraint: 0.0 <= AaPraPoly.c, has value: ");
  modelica_string tmp232;
  modelica_metatype tmpMeta233;
  static int tmp234 = 0;
  if(!tmp234)
  {
    tmp230 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */),0.0);
    if(!tmp230)
    {
      tmp232 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[9]] /* AaPraPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta233 = stringAppend(MMC_REFSTRINGLIT(tmp231),tmp232);
      {
        const char* assert_cond = "(AaPraPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta233));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta233));
        }
      }
      tmp234 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 914
type: ALGORITHM

  assert(AaPraPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= AaPraPoly.n, has value: " + String(AaPraPoly.n, "g"));
*/
void rPCR_03_eqFunction_914(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,914};
  modelica_boolean tmp235;
  static const MMC_DEFSTRINGLIT(tmp236,66,"Variable violating min constraint: 0.0 <= AaPraPoly.n, has value: ");
  modelica_string tmp237;
  modelica_metatype tmpMeta238;
  static int tmp239 = 0;
  if(!tmp239)
  {
    tmp235 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* AaPraPoly.n variable */),0.0);
    if(!tmp235)
    {
      tmp237 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[96]] /* AaPraPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta238 = stringAppend(MMC_REFSTRINGLIT(tmp236),tmp237);
      {
        const char* assert_cond = "(AaPraPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta238));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta238));
        }
      }
      tmp239 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 915
type: ALGORITHM

  assert(AsPrsPAPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= AsPrsPAPoly.c, has value: " + String(AsPrsPAPoly.c, "g"));
*/
void rPCR_03_eqFunction_915(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,915};
  modelica_boolean tmp240;
  static const MMC_DEFSTRINGLIT(tmp241,68,"Variable violating min constraint: 0.0 <= AsPrsPAPoly.c, has value: ");
  modelica_string tmp242;
  modelica_metatype tmpMeta243;
  static int tmp244 = 0;
  if(!tmp244)
  {
    tmp240 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */),0.0);
    if(!tmp240)
    {
      tmp242 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[16]] /* AsPrsPAPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta243 = stringAppend(MMC_REFSTRINGLIT(tmp241),tmp242);
      {
        const char* assert_cond = "(AsPrsPAPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta243));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta243));
        }
      }
      tmp244 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 916
type: ALGORITHM

  assert(AsPrsPAPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= AsPrsPAPoly.n, has value: " + String(AsPrsPAPoly.n, "g"));
*/
void rPCR_03_eqFunction_916(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,916};
  modelica_boolean tmp245;
  static const MMC_DEFSTRINGLIT(tmp246,68,"Variable violating min constraint: 0.0 <= AsPrsPAPoly.n, has value: ");
  modelica_string tmp247;
  modelica_metatype tmpMeta248;
  static int tmp249 = 0;
  if(!tmp249)
  {
    tmp245 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* AsPrsPAPoly.n variable */),0.0);
    if(!tmp245)
    {
      tmp247 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[109]] /* AsPrsPAPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta248 = stringAppend(MMC_REFSTRINGLIT(tmp246),tmp247);
      {
        const char* assert_cond = "(AsPrsPAPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta248));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta248));
        }
      }
      tmp249 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 917
type: ALGORITHM

  assert(AsPrsPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= AsPrsPoly.c, has value: " + String(AsPrsPoly.c, "g"));
*/
void rPCR_03_eqFunction_917(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,917};
  modelica_boolean tmp250;
  static const MMC_DEFSTRINGLIT(tmp251,66,"Variable violating min constraint: 0.0 <= AsPrsPoly.c, has value: ");
  modelica_string tmp252;
  modelica_metatype tmpMeta253;
  static int tmp254 = 0;
  if(!tmp254)
  {
    tmp250 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */),0.0);
    if(!tmp250)
    {
      tmp252 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[17]] /* AsPrsPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta253 = stringAppend(MMC_REFSTRINGLIT(tmp251),tmp252);
      {
        const char* assert_cond = "(AsPrsPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta253));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta253));
        }
      }
      tmp254 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 918
type: ALGORITHM

  assert(AsPrsPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= AsPrsPoly.n, has value: " + String(AsPrsPoly.n, "g"));
*/
void rPCR_03_eqFunction_918(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,918};
  modelica_boolean tmp255;
  static const MMC_DEFSTRINGLIT(tmp256,66,"Variable violating min constraint: 0.0 <= AsPrsPoly.n, has value: ");
  modelica_string tmp257;
  modelica_metatype tmpMeta258;
  static int tmp259 = 0;
  if(!tmp259)
  {
    tmp255 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* AsPrsPoly.n variable */),0.0);
    if(!tmp255)
    {
      tmp257 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[111]] /* AsPrsPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta258 = stringAppend(MMC_REFSTRINGLIT(tmp256),tmp257);
      {
        const char* assert_cond = "(AsPrsPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta258));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta258));
        }
      }
      tmp259 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 919
type: ALGORITHM

  assert(BaPraPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= BaPraPoly.c, has value: " + String(BaPraPoly.c, "g"));
*/
void rPCR_03_eqFunction_919(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,919};
  modelica_boolean tmp260;
  static const MMC_DEFSTRINGLIT(tmp261,66,"Variable violating min constraint: 0.0 <= BaPraPoly.c, has value: ");
  modelica_string tmp262;
  modelica_metatype tmpMeta263;
  static int tmp264 = 0;
  if(!tmp264)
  {
    tmp260 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */),0.0);
    if(!tmp260)
    {
      tmp262 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[25]] /* BaPraPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta263 = stringAppend(MMC_REFSTRINGLIT(tmp261),tmp262);
      {
        const char* assert_cond = "(BaPraPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta263));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta263));
        }
      }
      tmp264 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 920
type: ALGORITHM

  assert(BaPraPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= BaPraPoly.n, has value: " + String(BaPraPoly.n, "g"));
*/
void rPCR_03_eqFunction_920(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,920};
  modelica_boolean tmp265;
  static const MMC_DEFSTRINGLIT(tmp266,66,"Variable violating min constraint: 0.0 <= BaPraPoly.n, has value: ");
  modelica_string tmp267;
  modelica_metatype tmpMeta268;
  static int tmp269 = 0;
  if(!tmp269)
  {
    tmp265 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[126]] /* BaPraPoly.n variable */),0.0);
    if(!tmp265)
    {
      tmp267 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[126]] /* BaPraPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta268 = stringAppend(MMC_REFSTRINGLIT(tmp266),tmp267);
      {
        const char* assert_cond = "(BaPraPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta268));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta268));
        }
      }
      tmp269 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 921
type: ALGORITHM

  assert(BsPrsPBPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= BsPrsPBPoly.c, has value: " + String(BsPrsPBPoly.c, "g"));
*/
void rPCR_03_eqFunction_921(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,921};
  modelica_boolean tmp270;
  static const MMC_DEFSTRINGLIT(tmp271,68,"Variable violating min constraint: 0.0 <= BsPrsPBPoly.c, has value: ");
  modelica_string tmp272;
  modelica_metatype tmpMeta273;
  static int tmp274 = 0;
  if(!tmp274)
  {
    tmp270 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */),0.0);
    if(!tmp270)
    {
      tmp272 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[30]] /* BsPrsPBPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta273 = stringAppend(MMC_REFSTRINGLIT(tmp271),tmp272);
      {
        const char* assert_cond = "(BsPrsPBPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta273));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta273));
        }
      }
      tmp274 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 922
type: ALGORITHM

  assert(BsPrsPBPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= BsPrsPBPoly.n, has value: " + String(BsPrsPBPoly.n, "g"));
*/
void rPCR_03_eqFunction_922(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,922};
  modelica_boolean tmp275;
  static const MMC_DEFSTRINGLIT(tmp276,68,"Variable violating min constraint: 0.0 <= BsPrsPBPoly.n, has value: ");
  modelica_string tmp277;
  modelica_metatype tmpMeta278;
  static int tmp279 = 0;
  if(!tmp279)
  {
    tmp275 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[136]] /* BsPrsPBPoly.n variable */),0.0);
    if(!tmp275)
    {
      tmp277 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[136]] /* BsPrsPBPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta278 = stringAppend(MMC_REFSTRINGLIT(tmp276),tmp277);
      {
        const char* assert_cond = "(BsPrsPBPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta278));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta278));
        }
      }
      tmp279 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 923
type: ALGORITHM

  assert(BsPrsPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= BsPrsPoly.c, has value: " + String(BsPrsPoly.c, "g"));
*/
void rPCR_03_eqFunction_923(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,923};
  modelica_boolean tmp280;
  static const MMC_DEFSTRINGLIT(tmp281,66,"Variable violating min constraint: 0.0 <= BsPrsPoly.c, has value: ");
  modelica_string tmp282;
  modelica_metatype tmpMeta283;
  static int tmp284 = 0;
  if(!tmp284)
  {
    tmp280 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */),0.0);
    if(!tmp280)
    {
      tmp282 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[31]] /* BsPrsPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta283 = stringAppend(MMC_REFSTRINGLIT(tmp281),tmp282);
      {
        const char* assert_cond = "(BsPrsPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta283));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta283));
        }
      }
      tmp284 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 924
type: ALGORITHM

  assert(BsPrsPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= BsPrsPoly.n, has value: " + String(BsPrsPoly.n, "g"));
*/
void rPCR_03_eqFunction_924(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,924};
  modelica_boolean tmp285;
  static const MMC_DEFSTRINGLIT(tmp286,66,"Variable violating min constraint: 0.0 <= BsPrsPoly.n, has value: ");
  modelica_string tmp287;
  modelica_metatype tmpMeta288;
  static int tmp289 = 0;
  if(!tmp289)
  {
    tmp285 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[138]] /* BsPrsPoly.n variable */),0.0);
    if(!tmp285)
    {
      tmp287 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[138]] /* BsPrsPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta288 = stringAppend(MMC_REFSTRINGLIT(tmp286),tmp287);
      {
        const char* assert_cond = "(BsPrsPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta288));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta288));
        }
      }
      tmp289 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 925
type: ALGORITHM

  assert(AsBaPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= AsBaPoly.c, has value: " + String(AsBaPoly.c, "g"));
*/
void rPCR_03_eqFunction_925(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,925};
  modelica_boolean tmp290;
  static const MMC_DEFSTRINGLIT(tmp291,65,"Variable violating min constraint: 0.0 <= AsBaPoly.c, has value: ");
  modelica_string tmp292;
  modelica_metatype tmpMeta293;
  static int tmp294 = 0;
  if(!tmp294)
  {
    tmp290 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */),0.0);
    if(!tmp290)
    {
      tmp292 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[12]] /* AsBaPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta293 = stringAppend(MMC_REFSTRINGLIT(tmp291),tmp292);
      {
        const char* assert_cond = "(AsBaPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta293));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta293));
        }
      }
      tmp294 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 926
type: ALGORITHM

  assert(AsBaPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= AsBaPoly.n, has value: " + String(AsBaPoly.n, "g"));
*/
void rPCR_03_eqFunction_926(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,926};
  modelica_boolean tmp295;
  static const MMC_DEFSTRINGLIT(tmp296,65,"Variable violating min constraint: 0.0 <= AsBaPoly.n, has value: ");
  modelica_string tmp297;
  modelica_metatype tmpMeta298;
  static int tmp299 = 0;
  if(!tmp299)
  {
    tmp295 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* AsBaPoly.n variable */),0.0);
    if(!tmp295)
    {
      tmp297 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[102]] /* AsBaPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta298 = stringAppend(MMC_REFSTRINGLIT(tmp296),tmp297);
      {
        const char* assert_cond = "(AsBaPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta298));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta298));
        }
      }
      tmp299 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 927
type: ALGORITHM

  assert(AaBsPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= AaBsPoly.c, has value: " + String(AaBsPoly.c, "g"));
*/
void rPCR_03_eqFunction_927(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,927};
  modelica_boolean tmp300;
  static const MMC_DEFSTRINGLIT(tmp301,65,"Variable violating min constraint: 0.0 <= AaBsPoly.c, has value: ");
  modelica_string tmp302;
  modelica_metatype tmpMeta303;
  static int tmp304 = 0;
  if(!tmp304)
  {
    tmp300 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */),0.0);
    if(!tmp300)
    {
      tmp302 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[4]] /* AaBsPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta303 = stringAppend(MMC_REFSTRINGLIT(tmp301),tmp302);
      {
        const char* assert_cond = "(AaBsPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta303));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta303));
        }
      }
      tmp304 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 928
type: ALGORITHM

  assert(AaBsPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= AaBsPoly.n, has value: " + String(AaBsPoly.n, "g"));
*/
void rPCR_03_eqFunction_928(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,928};
  modelica_boolean tmp305;
  static const MMC_DEFSTRINGLIT(tmp306,65,"Variable violating min constraint: 0.0 <= AaBsPoly.n, has value: ");
  modelica_string tmp307;
  modelica_metatype tmpMeta308;
  static int tmp309 = 0;
  if(!tmp309)
  {
    tmp305 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* AaBsPoly.n variable */),0.0);
    if(!tmp305)
    {
      tmp307 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[87]] /* AaBsPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta308 = stringAppend(MMC_REFSTRINGLIT(tmp306),tmp307);
      {
        const char* assert_cond = "(AaBsPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta308));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta308));
        }
      }
      tmp309 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 929
type: ALGORITHM

  assert(signalA.c >= 0.0, "Variable violating min constraint: 0.0 <= signalA.c, has value: " + String(signalA.c, "g"));
*/
void rPCR_03_eqFunction_929(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,929};
  modelica_boolean tmp310;
  static const MMC_DEFSTRINGLIT(tmp311,64,"Variable violating min constraint: 0.0 <= signalA.c, has value: ");
  modelica_string tmp312;
  modelica_metatype tmpMeta313;
  static int tmp314 = 0;
  if(!tmp314)
  {
    tmp310 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */),0.0);
    if(!tmp310)
    {
      tmp312 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[38]] /* signalA.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta313 = stringAppend(MMC_REFSTRINGLIT(tmp311),tmp312);
      {
        const char* assert_cond = "(signalA.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta313));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta313));
        }
      }
      tmp314 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 930
type: ALGORITHM

  assert(signalA.n >= 0.0, "Variable violating min constraint: 0.0 <= signalA.n, has value: " + String(signalA.n, "g"));
*/
void rPCR_03_eqFunction_930(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,930};
  modelica_boolean tmp315;
  static const MMC_DEFSTRINGLIT(tmp316,64,"Variable violating min constraint: 0.0 <= signalA.n, has value: ");
  modelica_string tmp317;
  modelica_metatype tmpMeta318;
  static int tmp319 = 0;
  if(!tmp319)
  {
    tmp315 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[319]] /* signalA.n variable */),0.0);
    if(!tmp315)
    {
      tmp317 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[319]] /* signalA.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta318 = stringAppend(MMC_REFSTRINGLIT(tmp316),tmp317);
      {
        const char* assert_cond = "(signalA.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta318));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta318));
        }
      }
      tmp319 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 931
type: ALGORITHM

  assert(signalB.c >= 0.0, "Variable violating min constraint: 0.0 <= signalB.c, has value: " + String(signalB.c, "g"));
*/
void rPCR_03_eqFunction_931(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,931};
  modelica_boolean tmp320;
  static const MMC_DEFSTRINGLIT(tmp321,64,"Variable violating min constraint: 0.0 <= signalB.c, has value: ");
  modelica_string tmp322;
  modelica_metatype tmpMeta323;
  static int tmp324 = 0;
  if(!tmp324)
  {
    tmp320 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */),0.0);
    if(!tmp320)
    {
      tmp322 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[39]] /* signalB.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta323 = stringAppend(MMC_REFSTRINGLIT(tmp321),tmp322);
      {
        const char* assert_cond = "(signalB.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta323));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta323));
        }
      }
      tmp324 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 932
type: ALGORITHM

  assert(signalB.n >= 0.0, "Variable violating min constraint: 0.0 <= signalB.n, has value: " + String(signalB.n, "g"));
*/
void rPCR_03_eqFunction_932(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,932};
  modelica_boolean tmp325;
  static const MMC_DEFSTRINGLIT(tmp326,64,"Variable violating min constraint: 0.0 <= signalB.n, has value: ");
  modelica_string tmp327;
  modelica_metatype tmpMeta328;
  static int tmp329 = 0;
  if(!tmp329)
  {
    tmp325 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[321]] /* signalB.n variable */),0.0);
    if(!tmp325)
    {
      tmp327 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[321]] /* signalB.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta328 = stringAppend(MMC_REFSTRINGLIT(tmp326),tmp327);
      {
        const char* assert_cond = "(signalB.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta328));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta328));
        }
      }
      tmp329 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 933
type: ALGORITHM

  assert(BaPA.c >= 0.0, "Variable violating min constraint: 0.0 <= BaPA.c, has value: " + String(BaPA.c, "g"));
*/
void rPCR_03_eqFunction_933(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,933};
  modelica_boolean tmp330;
  static const MMC_DEFSTRINGLIT(tmp331,61,"Variable violating min constraint: 0.0 <= BaPA.c, has value: ");
  modelica_string tmp332;
  modelica_metatype tmpMeta333;
  static int tmp334 = 0;
  if(!tmp334)
  {
    tmp330 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */),0.0);
    if(!tmp330)
    {
      tmp332 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[21]] /* BaPA.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta333 = stringAppend(MMC_REFSTRINGLIT(tmp331),tmp332);
      {
        const char* assert_cond = "(BaPA.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta333));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta333));
        }
      }
      tmp334 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 934
type: ALGORITHM

  assert(BaPA.n >= 0.0, "Variable violating min constraint: 0.0 <= BaPA.n, has value: " + String(BaPA.n, "g"));
*/
void rPCR_03_eqFunction_934(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,934};
  modelica_boolean tmp335;
  static const MMC_DEFSTRINGLIT(tmp336,61,"Variable violating min constraint: 0.0 <= BaPA.n, has value: ");
  modelica_string tmp337;
  modelica_metatype tmpMeta338;
  static int tmp339 = 0;
  if(!tmp339)
  {
    tmp335 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* BaPA.n variable */),0.0);
    if(!tmp335)
    {
      tmp337 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[118]] /* BaPA.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta338 = stringAppend(MMC_REFSTRINGLIT(tmp336),tmp337);
      {
        const char* assert_cond = "(BaPA.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta338));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta338));
        }
      }
      tmp339 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 935
type: ALGORITHM

  assert(BaPraPA.c >= 0.0, "Variable violating min constraint: 0.0 <= BaPraPA.c, has value: " + String(BaPraPA.c, "g"));
*/
void rPCR_03_eqFunction_935(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,935};
  modelica_boolean tmp340;
  static const MMC_DEFSTRINGLIT(tmp341,64,"Variable violating min constraint: 0.0 <= BaPraPA.c, has value: ");
  modelica_string tmp342;
  modelica_metatype tmpMeta343;
  static int tmp344 = 0;
  if(!tmp344)
  {
    tmp340 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */),0.0);
    if(!tmp340)
    {
      tmp342 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[23]] /* BaPraPA.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta343 = stringAppend(MMC_REFSTRINGLIT(tmp341),tmp342);
      {
        const char* assert_cond = "(BaPraPA.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta343));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta343));
        }
      }
      tmp344 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 936
type: ALGORITHM

  assert(BaPraPA.n >= 0.0, "Variable violating min constraint: 0.0 <= BaPraPA.n, has value: " + String(BaPraPA.n, "g"));
*/
void rPCR_03_eqFunction_936(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,936};
  modelica_boolean tmp345;
  static const MMC_DEFSTRINGLIT(tmp346,64,"Variable violating min constraint: 0.0 <= BaPraPA.n, has value: ");
  modelica_string tmp347;
  modelica_metatype tmpMeta348;
  static int tmp349 = 0;
  if(!tmp349)
  {
    tmp345 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* BaPraPA.n variable */),0.0);
    if(!tmp345)
    {
      tmp347 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[122]] /* BaPraPA.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta348 = stringAppend(MMC_REFSTRINGLIT(tmp346),tmp347);
      {
        const char* assert_cond = "(BaPraPA.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta348));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta348));
        }
      }
      tmp349 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 937
type: ALGORITHM

  assert(BaPraPAPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= BaPraPAPoly.c, has value: " + String(BaPraPAPoly.c, "g"));
*/
void rPCR_03_eqFunction_937(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,937};
  modelica_boolean tmp350;
  static const MMC_DEFSTRINGLIT(tmp351,68,"Variable violating min constraint: 0.0 <= BaPraPAPoly.c, has value: ");
  modelica_string tmp352;
  modelica_metatype tmpMeta353;
  static int tmp354 = 0;
  if(!tmp354)
  {
    tmp350 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */),0.0);
    if(!tmp350)
    {
      tmp352 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[24]] /* BaPraPAPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta353 = stringAppend(MMC_REFSTRINGLIT(tmp351),tmp352);
      {
        const char* assert_cond = "(BaPraPAPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta353));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta353));
        }
      }
      tmp354 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 938
type: ALGORITHM

  assert(BaPraPAPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= BaPraPAPoly.n, has value: " + String(BaPraPAPoly.n, "g"));
*/
void rPCR_03_eqFunction_938(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,938};
  modelica_boolean tmp355;
  static const MMC_DEFSTRINGLIT(tmp356,68,"Variable violating min constraint: 0.0 <= BaPraPAPoly.n, has value: ");
  modelica_string tmp357;
  modelica_metatype tmpMeta358;
  static int tmp359 = 0;
  if(!tmp359)
  {
    tmp355 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[124]] /* BaPraPAPoly.n variable */),0.0);
    if(!tmp355)
    {
      tmp357 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[124]] /* BaPraPAPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta358 = stringAppend(MMC_REFSTRINGLIT(tmp356),tmp357);
      {
        const char* assert_cond = "(BaPraPAPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta358));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta358));
        }
      }
      tmp359 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 939
type: ALGORITHM

  assert(AaPB.c >= 0.0, "Variable violating min constraint: 0.0 <= AaPB.c, has value: " + String(AaPB.c, "g"));
*/
void rPCR_03_eqFunction_939(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,939};
  modelica_boolean tmp360;
  static const MMC_DEFSTRINGLIT(tmp361,61,"Variable violating min constraint: 0.0 <= AaPB.c, has value: ");
  modelica_string tmp362;
  modelica_metatype tmpMeta363;
  static int tmp364 = 0;
  if(!tmp364)
  {
    tmp360 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */),0.0);
    if(!tmp360)
    {
      tmp362 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[5]] /* AaPB.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta363 = stringAppend(MMC_REFSTRINGLIT(tmp361),tmp362);
      {
        const char* assert_cond = "(AaPB.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta363));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta363));
        }
      }
      tmp364 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 940
type: ALGORITHM

  assert(AaPB.n >= 0.0, "Variable violating min constraint: 0.0 <= AaPB.n, has value: " + String(AaPB.n, "g"));
*/
void rPCR_03_eqFunction_940(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,940};
  modelica_boolean tmp365;
  static const MMC_DEFSTRINGLIT(tmp366,61,"Variable violating min constraint: 0.0 <= AaPB.n, has value: ");
  modelica_string tmp367;
  modelica_metatype tmpMeta368;
  static int tmp369 = 0;
  if(!tmp369)
  {
    tmp365 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* AaPB.n variable */),0.0);
    if(!tmp365)
    {
      tmp367 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[88]] /* AaPB.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta368 = stringAppend(MMC_REFSTRINGLIT(tmp366),tmp367);
      {
        const char* assert_cond = "(AaPB.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta368));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta368));
        }
      }
      tmp369 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 941
type: ALGORITHM

  assert(AaPraPB.c >= 0.0, "Variable violating min constraint: 0.0 <= AaPraPB.c, has value: " + String(AaPraPB.c, "g"));
*/
void rPCR_03_eqFunction_941(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,941};
  modelica_boolean tmp370;
  static const MMC_DEFSTRINGLIT(tmp371,64,"Variable violating min constraint: 0.0 <= AaPraPB.c, has value: ");
  modelica_string tmp372;
  modelica_metatype tmpMeta373;
  static int tmp374 = 0;
  if(!tmp374)
  {
    tmp370 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */),0.0);
    if(!tmp370)
    {
      tmp372 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[7]] /* AaPraPB.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta373 = stringAppend(MMC_REFSTRINGLIT(tmp371),tmp372);
      {
        const char* assert_cond = "(AaPraPB.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta373));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta373));
        }
      }
      tmp374 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 942
type: ALGORITHM

  assert(AaPraPB.n >= 0.0, "Variable violating min constraint: 0.0 <= AaPraPB.n, has value: " + String(AaPraPB.n, "g"));
*/
void rPCR_03_eqFunction_942(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,942};
  modelica_boolean tmp375;
  static const MMC_DEFSTRINGLIT(tmp376,64,"Variable violating min constraint: 0.0 <= AaPraPB.n, has value: ");
  modelica_string tmp377;
  modelica_metatype tmpMeta378;
  static int tmp379 = 0;
  if(!tmp379)
  {
    tmp375 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* AaPraPB.n variable */),0.0);
    if(!tmp375)
    {
      tmp377 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[92]] /* AaPraPB.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta378 = stringAppend(MMC_REFSTRINGLIT(tmp376),tmp377);
      {
        const char* assert_cond = "(AaPraPB.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta378));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta378));
        }
      }
      tmp379 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 943
type: ALGORITHM

  assert(AaPraPBPoly.c >= 0.0, "Variable violating min constraint: 0.0 <= AaPraPBPoly.c, has value: " + String(AaPraPBPoly.c, "g"));
*/
void rPCR_03_eqFunction_943(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,943};
  modelica_boolean tmp380;
  static const MMC_DEFSTRINGLIT(tmp381,68,"Variable violating min constraint: 0.0 <= AaPraPBPoly.c, has value: ");
  modelica_string tmp382;
  modelica_metatype tmpMeta383;
  static int tmp384 = 0;
  if(!tmp384)
  {
    tmp380 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */),0.0);
    if(!tmp380)
    {
      tmp382 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[8]] /* AaPraPBPoly.c STATE(1) */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta383 = stringAppend(MMC_REFSTRINGLIT(tmp381),tmp382);
      {
        const char* assert_cond = "(AaPraPBPoly.c >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta383));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",5,3,5,251,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta383));
        }
      }
      tmp384 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 944
type: ALGORITHM

  assert(AaPraPBPoly.n >= 0.0, "Variable violating min constraint: 0.0 <= AaPraPBPoly.n, has value: " + String(AaPraPBPoly.n, "g"));
*/
void rPCR_03_eqFunction_944(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,944};
  modelica_boolean tmp385;
  static const MMC_DEFSTRINGLIT(tmp386,68,"Variable violating min constraint: 0.0 <= AaPraPBPoly.n, has value: ");
  modelica_string tmp387;
  modelica_metatype tmpMeta388;
  static int tmp389 = 0;
  if(!tmp389)
  {
    tmp385 = GreaterEq((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* AaPraPBPoly.n variable */),0.0);
    if(!tmp385)
    {
      tmp387 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[data->simulationInfo->realVarsIndex[94]] /* AaPraPBPoly.n variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta388 = stringAppend(MMC_REFSTRINGLIT(tmp386),tmp387);
      {
        const char* assert_cond = "(AaPraPBPoly.n >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          infoStreamPrintWithEquationIndexes(OMC_LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta388));
        } else {
          FILE_INFO info = {"/scicore/home/sinnreic/kinter/.openmodelica/libraries/BioChem 2.0/Substances/Substance.mo",7,3,7,255,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta388));
        }
      }
      tmp389 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int rPCR_03_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  rPCR_03_eqFunction_867(data, threadData);

  rPCR_03_eqFunction_868(data, threadData);

  rPCR_03_eqFunction_869(data, threadData);

  rPCR_03_eqFunction_870(data, threadData);

  rPCR_03_eqFunction_871(data, threadData);

  rPCR_03_eqFunction_872(data, threadData);

  rPCR_03_eqFunction_873(data, threadData);

  rPCR_03_eqFunction_874(data, threadData);

  rPCR_03_eqFunction_875(data, threadData);

  rPCR_03_eqFunction_876(data, threadData);

  rPCR_03_eqFunction_877(data, threadData);

  rPCR_03_eqFunction_878(data, threadData);

  rPCR_03_eqFunction_879(data, threadData);

  rPCR_03_eqFunction_880(data, threadData);

  rPCR_03_eqFunction_881(data, threadData);

  rPCR_03_eqFunction_882(data, threadData);

  rPCR_03_eqFunction_883(data, threadData);

  rPCR_03_eqFunction_884(data, threadData);

  rPCR_03_eqFunction_885(data, threadData);

  rPCR_03_eqFunction_886(data, threadData);

  rPCR_03_eqFunction_887(data, threadData);

  rPCR_03_eqFunction_888(data, threadData);

  rPCR_03_eqFunction_889(data, threadData);

  rPCR_03_eqFunction_890(data, threadData);

  rPCR_03_eqFunction_891(data, threadData);

  rPCR_03_eqFunction_892(data, threadData);

  rPCR_03_eqFunction_893(data, threadData);

  rPCR_03_eqFunction_894(data, threadData);

  rPCR_03_eqFunction_895(data, threadData);

  rPCR_03_eqFunction_896(data, threadData);

  rPCR_03_eqFunction_897(data, threadData);

  rPCR_03_eqFunction_898(data, threadData);

  rPCR_03_eqFunction_899(data, threadData);

  rPCR_03_eqFunction_900(data, threadData);

  rPCR_03_eqFunction_901(data, threadData);

  rPCR_03_eqFunction_902(data, threadData);

  rPCR_03_eqFunction_903(data, threadData);

  rPCR_03_eqFunction_904(data, threadData);

  rPCR_03_eqFunction_905(data, threadData);

  rPCR_03_eqFunction_906(data, threadData);

  rPCR_03_eqFunction_907(data, threadData);

  rPCR_03_eqFunction_908(data, threadData);

  rPCR_03_eqFunction_909(data, threadData);

  rPCR_03_eqFunction_910(data, threadData);

  rPCR_03_eqFunction_911(data, threadData);

  rPCR_03_eqFunction_912(data, threadData);

  rPCR_03_eqFunction_913(data, threadData);

  rPCR_03_eqFunction_914(data, threadData);

  rPCR_03_eqFunction_915(data, threadData);

  rPCR_03_eqFunction_916(data, threadData);

  rPCR_03_eqFunction_917(data, threadData);

  rPCR_03_eqFunction_918(data, threadData);

  rPCR_03_eqFunction_919(data, threadData);

  rPCR_03_eqFunction_920(data, threadData);

  rPCR_03_eqFunction_921(data, threadData);

  rPCR_03_eqFunction_922(data, threadData);

  rPCR_03_eqFunction_923(data, threadData);

  rPCR_03_eqFunction_924(data, threadData);

  rPCR_03_eqFunction_925(data, threadData);

  rPCR_03_eqFunction_926(data, threadData);

  rPCR_03_eqFunction_927(data, threadData);

  rPCR_03_eqFunction_928(data, threadData);

  rPCR_03_eqFunction_929(data, threadData);

  rPCR_03_eqFunction_930(data, threadData);

  rPCR_03_eqFunction_931(data, threadData);

  rPCR_03_eqFunction_932(data, threadData);

  rPCR_03_eqFunction_933(data, threadData);

  rPCR_03_eqFunction_934(data, threadData);

  rPCR_03_eqFunction_935(data, threadData);

  rPCR_03_eqFunction_936(data, threadData);

  rPCR_03_eqFunction_937(data, threadData);

  rPCR_03_eqFunction_938(data, threadData);

  rPCR_03_eqFunction_939(data, threadData);

  rPCR_03_eqFunction_940(data, threadData);

  rPCR_03_eqFunction_941(data, threadData);

  rPCR_03_eqFunction_942(data, threadData);

  rPCR_03_eqFunction_943(data, threadData);

  rPCR_03_eqFunction_944(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

